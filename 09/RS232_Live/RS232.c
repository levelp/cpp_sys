//==============================================================================
// Include files

#include "inifile.h"
#include <ansi_c.h>
#include <cvirte.h>
#include <userint.h>
#include <stdio.h>
#include <RS232.h>
#include "RS232.h"
#include "toolbox.h"
#include <assert.h>
#include <utility.h>
#include "IniUtils.h"

//==============================================================================
// Requred instruments:
// * toolslib\toolbox\inifile.fp

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

static int panelHandle = 0;

// COM-port for communication with SSB device
int COM_PORT = 4;
int MAX_COM_PORT = 10;
int baudRate = 115200;
int parity = 0;
int dataBits = 8;
int stopBits = 1;
int iqSize = 512; // Input queue size
int oqSize = 512; // Output queue size
double timeoutSeconds = 3.0;
int sleepAfterCommand = 1000;

// Date/time format for logging
char* logTimeFormat = "%I:%M:%S"; // %d.%m.%Y %I:%M:%S

char* activeModel = "24PHT4000_60";

int tryCount = 5;

// MODEL
char* modelName = "24PHT4000/60";
char* softwareVersion = "_002.200.000.000";
char* serialNumber = "12345678901234";

//==============================================================================
// Static functions

//==============================================================================
// Global variables

//==============================================================================
// Global functions

// T - trace
void T(const char* format, ...) {
  time_t rawtime;
  struct tm* timeinfo;
  char timeStr[80];

  FILE* logFile = fopen("log.txt", "a+");

  // Get current date/time
  time (&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(timeStr, sizeof(timeStr), logTimeFormat, timeinfo);

  // Write current date/time to stdout & log file
  printf("%s ", timeStr);
  fprintf(logFile, "%s ", timeStr);

  // Write format string + args to stdout & log file
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  vfprintf(logFile, format, args);
  va_end(args);

  printf("\n");
  fprintf(logFile, "\n");

  fflush(stdout);
  fflush(logFile);
  fclose(logFile);
}

// Show error from RS232
void showError(int errorNumber) {
  if(errorNumber >= 0)
    return;
  char* msg = GetRS232ErrorString(errorNumber);
  T("RS232 Error: %d %s", errorNumber, msg);
}

char* dumpAscii(unsigned char* s) {
  int len = strlen(s);
  static char str[256];
  strcpy(str, "");
  char mode = '#'; // # - start
  for(int i = 0; i < len; i++) {
    unsigned char c = s[i];
    if(c >= ' ' && c <= 126) {
      if(mode == 'H')
        sprintf(str, "%s ", str);
      sprintf(str, "%s%c", str, c);
      mode = 'N'; // Normal char
    } else {
      if(mode == 'N' || mode == 'H')
        sprintf(str, "%s ", str);
      sprintf(str, "%s0x%02X", str, c);
      mode = 'H'; // Hex
    }
  }
  return str;
}

char* ascii2hex(unsigned char* s, int len) {
  static char str[10240];
  strcpy(str, "");
  for(int i = 0; i < len; i++) {
    unsigned char c = s[i];
    if(i != 0) strcat(str, " ");
    sprintf(str, "%s0x%02X", str, c);
  }
  return str;
}

// Header for all commands
#define HEADER_SIZE 3

const unsigned char CMD_HEADER[HEADER_SIZE] = {
  0x6E, 0x51,  // command head
  0x86,        // length
};

// Calc Control Sum
//   dbuf - command
//   wLen - number of bytes
unsigned char calcCRC8(unsigned char* buf, int len) {
  unsigned char nCRC = 0;
  nCRC = buf[0];
  for(int i = 1; i < len; i++)
    nCRC ^= buf[i];
  // T("calcCRC8([%s], %d) -> %02X", ascii2hex(buf, len), len, nCRC);
  return nCRC;
}

void testCRC8() {
  unsigned char buf[9] = {
    0x6E, 0x51,  // command head
    0x86,        // length
    0x03, 0xFE,  // fix header 2
    0xE1,        // Fcode1 - factory mode
    0xA0,        // byte 4
    0x00,        // byte 5
    0x01
  };
  assert( calcCRC8(buf, 9) == 0x04 );
}

// Send command without checksum
void sendCommandX(unsigned char* cmd, int len) {
  // Write to COM port
  int res = ComWrt(COM_PORT, cmd, len);
  T("ComWrt(\"%s\") -> %d", ascii2hex(cmd, len), res);
  if(len != res && res > 0)
    T("len = %d  res = %d", len, res);
  showError(res);
}

void sendCommand(unsigned char* cmd) {
  T("sendCommand(\"%s\")", dumpAscii(cmd));
  sendCommandX(cmd, strlen(cmd));
}

void sendCommandCRC(unsigned char* cmd, int cmdLen) {
  unsigned char buf[cmdLen + 1];
  memcpy(buf, cmd, cmdLen);
  unsigned char CRC = calcCRC8(cmd, cmdLen);
  buf[cmdLen] = CRC;
  //T("sendCommandCRC(\"%s\") cmdLen = %d CRC = %02X", ascii2hex(cmd, cmdLen), cmdLen,
  //  (int)CRC);
  sendCommandX(buf, cmdLen + 1); // +1 because we added CRC
}

typedef struct {
  int len; // Number of bytes
  unsigned char* data; // Data ("len" bytes)
} Answer;

Answer readAnswer() {
  static char buf[256];
  int readed = ComRd(COM_PORT, buf, sizeof(buf));
  Answer answer = {0, NULL};
  if(readed < 0)
    showError(readed);
  else {
    T("\n--- Readed: %d bytes --- \"%s\"",
      readed, ascii2hex(buf, 3));

    if(readed > 3) {
      // 3 bytes - answer header
      answer.len = readed - 3;
      answer.data = malloc(answer.len + 1);
      memcpy(answer.data, buf + 3, answer.len);
      answer.data[answer.len] = 0x00;
      T(">>>>> \"%s\"\n\"%s\"",
        answer.data,
        ascii2hex(answer.data, answer.len));
    }
  }
  FlushInQ(COM_PORT);
  FlushOutQ(COM_PORT);
  return answer;
}

void sendCommandHex(int* cmd, int len) {
  char s[len];
  for(int i = 0; i < len; i++)
    s[i] = (char)cmd[i];
  sendCommandCRC(s, len);
}

// do command and read answer
Answer doCmd(char* name, int len, ...) {
  T("\n===== %s =====", name);

  int c[HEADER_SIZE + len];
  for(int i = 0; i < HEADER_SIZE; i++)
    c[i] = CMD_HEADER[i];
  c[2] = 0x80 + len;

  va_list args;
  va_start(args, len);
  for(int i = 0; i < len; i++)
    c[i + 3] = va_arg(args, int);
  va_end(args);

  sendCommandHex(c, len + 3);

  Answer ans = readAnswer();

  //T("Sleep(%d)", sleepAfterCommand);
  Delay(sleepAfterCommand / 1000.0);

  return ans;
}

Answer doCmdArray(char* name, int len, int* bytes) {
  T("\n===== %s =====", name);

  int c[HEADER_SIZE + len];
  for(int i = 0; i < HEADER_SIZE; i++)
    c[i] = CMD_HEADER[i];
  c[2] = 0x80 + len;

  for(int i = 0; i < len; i++)
    c[i + 3] = bytes[i];

  sendCommandHex(c, len + 3);

  Answer ans = readAnswer();

  //T("Sleep(%d)", sleepAfterCommand);
  Delay(sleepAfterCommand / 1000.0);

  return ans;
}

// Call this function before sending any commands
void enterFactory() {
  //command [0] = 0x0D; "\r" - CR - Carriage Return
  //command [1] = 0x0A; "\n" - LF - Line Feed
  T("\n===== Head =====");
  sendCommand("\r\nTPV/Novatek\r\n");

  T("\n===== Stop output =====");
  sendCommand("\r0.ft\r");

  // Enter to factory
  doCmd("Enter to factory", 6,
        0x03, 0xFE,  // fix header 2
        0xE1,        // Fcode1 - factory mode
        0xA0,        // byte 4
        0x00,        // byte 5
        0x01
       );
}

// Check result - compare with right answer
int check(char* checkName, char* expected, Answer ans) {
  if(ans.data == NULL) {
    T("CHECK %s: expected \"%s\", actual NULL", checkName, expected);
    return FALSE;
  }
  if(strcmp(expected, ans.data)) {
    T("CHECK %s: expected \"%s\", actual \"%s\"", checkName, expected, ans.data);
    return FALSE;
  }
  return TRUE;
}

// ==============
//    Commands
// ==============
void readModel() {
  check("model name", modelName,
        doCmd("Read Model", 6, 0x01, 0xFE, 0xF0, 0x18, 0x04, 0x00));
}

Answer readSoftware() {
  return doCmd("Read Software", 6, 0x01, 0xFE, 0xE4, 0x13, 0x00, 0x00);
}

// ==========
//   Tests
// ==========
int checkIfInFactoryMode() {
  Answer ans = readSoftware();
  if(ans.len > 6 && ans.data[0] == '_' && ans.data[1] == '0')
    return TRUE;
  return FALSE;
}

void testReadSoftware() {
  for(int i = 1; i <= tryCount; i++) {
    T("Try #%d", i);
    if(check("software version", softwareVersion, readSoftware()))
      break;
  }
}

void writeSerialNumber(char* serialNumber) {
  // Store Product Code
  int cmd[4 + 14] = {0x03, 0xFE, 0xE8, 0x00};
  int len = strlen(serialNumber);
  for(int i = 0; i < len; i++)
    cmd[4 + i] = serialNumber[i];
  doCmdArray("Store Product Code", 4 + len, cmd);
}

char* checkSerialNumber(char* serialNumber) {
  Answer ans = doCmd("Read Product Code", 6, 0x01, 0xFE, 0xE8, 0x00, 0x00, 0x00);
  check("Serial number", serialNumber, ans);
  return ans.data;
}

char* testSerialNumber(char* serialNumber) {
  assert( strlen(serialNumber) == 14 );
  assert( serialNumber[0] == 'U' );
  assert( serialNumber[1] == 'Z' );
  writeSerialNumber(serialNumber);
  return checkSerialNumber(serialNumber);
}

// ===============
//    RS232.ini
// ===============
const char* INI_FILENAME = "RS232.ini";

void readIni() {
  Ini_Begin(INI_FILENAME);

  Ini_Int("COM", "COM_PORT", &COM_PORT);
  Ini_Int("COM", "MAX_COM_PORT", &MAX_COM_PORT);
  Ini_Int("COM", "Baud rate", &baudRate);
  Ini_Int("COM", "parity", &parity);
  Ini_Int("COM", "dataBits", &dataBits);
  Ini_Int("COM", "stopBits", &stopBits);
  Ini_Int("COM", "Input queue size", &iqSize);
  Ini_Int("COM", "Output queue size", &oqSize);
  Ini_Double("COM", "timeoutSeconds", &timeoutSeconds);
  Ini_Int("COM", "sleepAfterCommand", &sleepAfterCommand);

  Ini_String("LOG", "logTimeFormat", &logTimeFormat);

  Ini_String("MODEL", "activeModel", &activeModel);

  Ini_Int("TEST", "tryCount", &tryCount);

  Ini_End();
}

void readModelIni() {
  char fileName[MAX_PATHNAME_LEN];
  sprintf(fileName, "%s.ini", activeModel);

  Ini_Begin(fileName);

  Ini_String("MODEL", "modelName", &modelName);
  Ini_String("MODEL", "Serial number", &serialNumber);
  Ini_String("SOFTWARE", "Software version", &softwareVersion);

  Ini_End();
}

void fillComPortsList() {
  // Clear lits of COM-ports
  ClearListCtrl(PANEL, PANEL_COM_PORT);
  for(int i = 0; i < MAX_COM_PORT; i++) {
    int n = i + 1; // COM port number
    char name[6];
    sprintf(name, "COM%d", n);
    InsertListItem(PANEL, PANEL_COM_PORT, i, name, n);
  }
  SetCtrlVal(PANEL, PANEL_COM_PORT, COM_PORT);
}

/// HIFN The main entry-point function.
int main (int argc, char* argv[]) {
  int error = 0;

  /* initialize and load resources */
  nullChk (InitCVIRTE (0, argv, 0));
  errChk (panelHandle = LoadPanel (0, "RS232.uir", PANEL));

  // Settings
  SetCtrlAttribute (panelHandle, PANEL_STRIPCHART, ATTR_SCROLL_MODE, VAL_CONTINUOUS);

  testCRC8();

  readIni();
  readModelIni();

  fillComPortsList();

  //GetCtrlVal(PANEL, PANEL_COM_SEND_TO, &COM_PORT);

  char comPortName[5];
  sprintf(comPortName, "COM%d", COM_PORT);
  T("--- Open COM%d %s port ---", COM_PORT, comPortName);
  OpenComConfig(COM_PORT, comPortName, baudRate, parity,
                dataBits, stopBits, iqSize, oqSize);
  SetComTime(COM_PORT, timeoutSeconds);

  if(!checkIfInFactoryMode())
    enterFactory();

  readModel();
  testReadSoftware();

  testSerialNumber("UZ1A1234567890");

  //getchar();  // Pause
  //system("PAUSE"); // Pause

  /* display the panel and run the user interface */
  errChk (DisplayPanel (panelHandle));
  errChk (RunUserInterface ());

Error:
  /* clean up */
  if (panelHandle > 0)
    DiscardPanel (panelHandle);
  return 0;
}

//==============================================================================
// UI callback function prototypes

/// HIFN Exit when the user dismisses the panel.
int CVICALLBACK panelCB (int panel, int event, void* callbackData,
                         int eventData1, int eventData2) {
  if (event == EVENT_CLOSE)
    QuitUserInterface (0);
  return 0;
}

int CVICALLBACK cbTimerTick (int panel, int control, int event,
                             void* callbackData, int eventData1, int eventData2) {
  const int numberOfPoints = 1;
  double y[numberOfPoints];
  double y2[numberOfPoints];
  int startingIndex = 0;
  int skipCount = 0;

  switch (event) {
    case EVENT_TIMER_TICK:
      for(int x = 0; x < numberOfPoints; x++)
        y[x] = Random(0, 100);


      // VAL_CHAR     - A single byte character.
      // VAL_DOUBLE   - An 8 byte floating point value.
      // VAL_FLOAT    - A 4 byte floating point value.
      // VAL_INTEGER  - A 4 byte integer.
      // VAL_SHORT_INTEGER     - A 2 byte integer.
      // VAL_64BIT_INTEGER     - An 8 byte integer.
      // VAL_UNSIGNED_CHAR     - An unsigned single byte character.
      // VAL_UNSIGNED_INTEGER  - An unsigned 4 byte integer.
      // VAL_UNSIGNED_SHORT_INTEGER  - An unsigned 2 byte integer.
      // VAL_UNSIGNED_64BIT_INTEGER  - An unsigned 8 byte integer.
      //PlotStripChart(panelHandle, PANEL_STRIPCHART, y2, numberOfPoints, startingIndex, skipCount, VAL_DOUBLE);

      break;
  }
  return 0;
}

void checkWriteReadSerialNumber() {
  char serial[20];
  GetCtrlVal(PANEL, PANEL_SERIAL_NUMBER, serial);
  if(strlen(serial) != 14) {
    MessagePopup("Check Serial Number", "Length != 14");
    SetActiveCtrl(PANEL, PANEL_SERIAL_NUMBER);
    return;
  }
  if(serial[0] != 'U' || serial[1] != 'Z') {
    MessagePopup("Check Serial Number", "Serial number must starts with UZ");
    SetActiveCtrl(PANEL, PANEL_SERIAL_NUMBER);
    return;
  }
  char* result = testSerialNumber(serial);
  if(result != NULL) {
    SetCtrlVal(PANEL, PANEL_SN_RESULT, result);
    SetCtrlVal(PANEL, PANEL_SN_LED, !strcmp(result, serial));
  }
}

int CVICALLBACK checkWriteRead (int panel, int control, int event,
                                void* callbackData, int eventData1, int eventData2) {
  switch (event) {
    case EVENT_COMMIT:
      checkWriteReadSerialNumber();
      break;
  }
  return 0;
}

#define SHOW_KEY(x) case x: T("KeyPressed: "#x); break;

int CVICALLBACK enterSerialNumber (int panel, int control, int event,
                                   void* callbackData, int eventData1, int eventData2) {
  switch (event) {
    case EVENT_COMMIT:
      T("enterSerialNumber -> COMMIT");
      break;
    case EVENT_KEYPRESS:
      switch(eventData1) {
        case VAL_ENTER_VKEY:
          T("EVENT: enterSerialNumber -> ENTER pressed");
          checkWriteReadSerialNumber();
          break;
          SHOW_KEY(VAL_FWD_DELETE_VKEY);
          SHOW_KEY(VAL_BACKSPACE_VKEY);
          SHOW_KEY(VAL_ESC_VKEY);
          SHOW_KEY(VAL_TAB_VKEY);
          SHOW_KEY(VAL_UP_ARROW_VKEY);
          SHOW_KEY(VAL_DOWN_ARROW_VKEY);
          SHOW_KEY(VAL_LEFT_ARROW_VKEY);
          SHOW_KEY(VAL_RIGHT_ARROW_VKEY);
          SHOW_KEY(VAL_INSERT_VKEY);
          SHOW_KEY(VAL_HOME_VKEY);
          SHOW_KEY(VAL_END_VKEY);
          SHOW_KEY(VAL_PAGE_UP_VKEY);
          SHOW_KEY(VAL_PAGE_DOWN_VKEY);
          SHOW_KEY(VAL_F1_VKEY);
          SHOW_KEY(VAL_F2_VKEY);
          SHOW_KEY(VAL_F3_VKEY);
          SHOW_KEY(VAL_F4_VKEY);
          SHOW_KEY(VAL_F5_VKEY);
          SHOW_KEY(VAL_F6_VKEY);
          SHOW_KEY(VAL_F7_VKEY);
          SHOW_KEY(VAL_F8_VKEY);
          SHOW_KEY(VAL_F9_VKEY);
          SHOW_KEY(VAL_F10_VKEY);
          SHOW_KEY(VAL_F11_VKEY);
          SHOW_KEY(VAL_F12_VKEY);
      }
      break;
  }
  return 0;
}
