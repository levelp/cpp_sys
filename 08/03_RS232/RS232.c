//==============================================================================
//
// Title:   RS232
// Purpose:   RS232 Demo.
//
//==============================================================================

//==============================================================================
// Include files

#include <ansi_c.h>
#include <cvirte.h>
#include <userint.h>
#include <RS232.h>
#include "RS232.h"
#include "toolbox.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

static int panelHandle = 0;

int comWrite, comRead;

#define READ_FROM_COM

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
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer, 80, "%d.%m.%Y %I:%M:%S ", timeinfo);
  printf(buffer);

  va_list args;
  va_start (args, format);
  vprintf (format, args);
  va_end (args);

  printf("\n");

  fflush(stdout);
}


/// HIFN The main entry-point function.
int main (int argc, char* argv[]) {
  int error = 0;

  /* initialize and load resources */
  nullChk (InitCVIRTE (0, argv, 0));
  errChk (panelHandle = LoadPanel (0, "RS232.uir", PANEL));

  // Settings
  SetCtrlAttribute (panelHandle, PANEL_STRIPCHART, ATTR_SCROLL_MODE, VAL_CONTINUOUS);

  // Open COM ports
  GetCtrlVal (PANEL, PANEL_COM_SEND_TO, &comWrite);
  GetCtrlVal (PANEL, PANEL_COM_READ_FROM, &comRead);

  OpenComConfig (comWrite, "", 115200, 0, 7, 1, 512, 512);
#ifdef READ_FROM_COM
  OpenComConfig (comRead, "", 115200, 0, 7, 1, 512, 512);
#endif

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

      char b1[10] = "1234";
      // Write to COM port
      int xx = ComWrt(comWrite, (char*)y, sizeof(y));

      //char b2[10];
#ifdef READ_FROM_COM
      int readed = ComRd(comRead, (char*)y2, sizeof(y2));
#endif
      //printf("%s\n", b2);

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
      PlotStripChart(panelHandle, PANEL_STRIPCHART, y2, numberOfPoints, startingIndex, skipCount, VAL_DOUBLE);

      break;
  }
  return 0;
}
