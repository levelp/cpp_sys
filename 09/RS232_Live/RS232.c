//==============================================================================
// Include files

#include "inifile.h"
#include <ansi_c.h>
#include <cvirte.h>
#include <userint.h>
#include <RS232.h>
#include "RS232.h"
#include "toolbox.h"

//==============================================================================
// Instruments:
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
int baudRate = 115200;

// Date/time format for logging
char* logTimeFormat = "%I:%M:%S"; // %d.%m.%Y %I:%M:%S

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
  char buffer[256];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer, 80, logTimeFormat, timeinfo);
  printf("%s ", buffer);

  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);

  printf("\n");

  fflush(stdout);
}

// Show error from RS232
void showError(int errorNumber) {
  if(errorNumber >= 0)
    return;
  char* msg = GetRS232ErrorString(errorNumber);
  T("RS232 Error: %d %s", errorNumber, msg);
}

char* ascii2hex(unsigned char* s, int len) {
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

// Calc Control Sum
//   dbuf - command
//   wLen - number of bytes
unsigned char calcCRC8(unsigned char* buf, int len) {
  unsigned char nCRC = 0;
  nCRC = buf[0];
  for(int i = 1; i < len; i++)
    nCRC ^= buf[i];
  T("calcCRC8([%s], %d) -> %02X", ascii2hex(buf, len), len, nCRC);
  return nCRC;
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

void sendCommand(char* cmd) {
  sendCommandX(cmd, strlen(cmd));
}

void sendCommandCRC(char* cmd, int cmdLen) {
  static char buf[256];
  unsigned char CRC = calcCRC8(cmd, cmdLen);
  memcpy(buf, cmd, cmdLen);
  buf[cmdLen] = CRC;
  T("sendCommandCRC(\"%s\") cmdLen = %d CRC = %02X", ascii2hex(cmd, cmdLen), cmdLen,
    (int)CRC);
  sendCommandX(buf, cmdLen + 1); // +1 because we added CRC
}

void readAnswer() {
  static char buf[256];
  int readed = ComRd(COM_PORT, buf, sizeof(buf));
  if(readed < 0)
    showError(readed);
  else
    T("--- Readed: %d bytes ---\n%s", readed, ascii2hex(buf, readed));
}

void sendCommandHex(int* cmd, int len) {
  char s[len];
  for(int i = 0; i < len; i++)
    s[i] = (char)cmd[i];
  sendCommandCRC(s, len);
}

#define HEADER_SIZE 3

// do command and read answer
void doCmd(char* name, int len, ...) {
  T("--- %s ---", name);

  unsigned char header[HEADER_SIZE] = {
    0x6E, 0x51,  // command head
    0x86,        // length
  };

  int c[HEADER_SIZE + len];
  for(int i = 0; i < HEADER_SIZE; i++)
    c[i] = header[i];

  va_list args;
  va_start(args, len);
  for(int i = 0; i < len; i++)
    c[i + 3] = va_arg(args, int);
  va_end(args);

  sendCommandHex(c, len + 3);

  readAnswer();
}

// Call this function before sending any commands
void enterFactory() {
  //command [0] = 0x0D; "\r" - CR - Carriage Return
  //command [1] = 0x0A; "\n" - LF - Line Feed
  T("--- Head ---");
  sendCommand("\r\nTPV/Novatek\r\n");

  //T("--- Stop output ---");
  //sendCommand("\r0.ft\r");
  readAnswer();

  // Enter to factory
  doCmd("Enter to factory", 6,
        0x03, 0xFE,  // fix header 2
        0xE1,        // Fcode1 - factory mode
        0xA0,        // byte 4
        0x00,        // byte 5
        0x01
       );
}

// ==============
//    Commands
// ==============
void readModel() {
  doCmd("Read Model", 6, 0x01, 0xFE, 0xF0, 0x18, 0x04, 0x00);
}

void readSoftware() {
  doCmd("Read Software", 6, 0x01, 0xFE, 0xE4, 0x13, 0x00, 0x00);
}

// ===============
//    RS232.ini
// ===============
const char* INI_FILENAME = "RS232.ini";

IniText iniText;
int iniHasChanges = 0;

void Ini_String(const char* section, const char* itemName, char** value) {
  if(Ini_ItemExists(iniText, section, itemName))
    Ini_GetStringCopy(iniText, section, itemName, value);
  else {
    Ini_PutString(iniText, section, itemName, *value);
    iniHasChanges = 1;
  }
}

void Ini_Int(const char* section, const char* itemName, int* value) {
  if(Ini_ItemExists(iniText, section, itemName))
    Ini_GetInt(iniText, section, itemName, value);
  else {
    Ini_PutInt(iniText, section, itemName, *value);
    iniHasChanges = 1;
  }
}

void Ini_Booolean(const char* section, const char* itemName, int* value) {
  if(Ini_ItemExists(iniText, section, itemName))
    Ini_GetBoolean(iniText, section, itemName, value);
  else {
    Ini_PutBoolean(iniText, section, itemName, *value);
    iniHasChanges = 1;
  }
}

void readIni() {
  char pathName[MAX_PATHNAME_LEN];
  char dirName[MAX_PATHNAME_LEN];

  /* set up the pathName for the .ini file */
  GetProjectDir(dirName);
  MakePathname(dirName, INI_FILENAME, pathName);

  /* create object for holding the value/tag pairs */
  iniText = Ini_New(TRUE); /* TRUE for automatic sorting */

  Ini_SetAddQuotesToStrings(iniText, 0);

  /* read in the tag/value pairs */
  Ini_ReadFromFile(iniText, pathName);

  iniHasChanges = 0;

  /* create the in–memory tag/value pairs */
  Ini_Int("COM", "COM_PORT", &COM_PORT);
  Ini_Int("COM", "Baud rate", &baudRate);
  Ini_String("LOG", "logTimeFormat", &logTimeFormat);

  if(iniHasChanges) {
    /* write out the tag/value pairs */
    Ini_WriteToFile(iniText, pathName);
    iniHasChanges = 0;
  }

  /* dispose of the in–memory tag/value pairs */
  Ini_Dispose(iniText);
}

/// HIFN The main entry-point function.
int main (int argc, char* argv[]) {
  int error = 0;

  /* initialize and load resources */
  nullChk (InitCVIRTE (0, argv, 0));
  errChk (panelHandle = LoadPanel (0, "RS232.uir", PANEL));

  // Settings
  SetCtrlAttribute (panelHandle, PANEL_STRIPCHART, ATTR_SCROLL_MODE, VAL_CONTINUOUS);

  readIni();
  SetCtrlVal(PANEL, PANEL_COM_SEND_TO, COM_PORT);

  GetCtrlVal(PANEL, PANEL_COM_SEND_TO, &COM_PORT);

  T("--- Open COM%d port ---", COM_PORT);
  OpenComConfig(COM_PORT, "", baudRate, 0, 7, 1, 512, 512);

  enterFactory();

  readModel();

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
