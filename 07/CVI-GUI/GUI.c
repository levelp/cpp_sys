//==============================================================================
//
// Title:   GUI
// Purpose:   GUI example.
//
//==============================================================================

//==============================================================================
// Include files

#include <ansi_c.h>
#include <cvirte.h>
#include <userint.h>
#include "GUI.h"
#include "toolbox.h"
#include <stdio.h>
#include <FileBrowser.h>

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

static int panelHandle = 0;

//==============================================================================
// Static functions

//==============================================================================
// Global variables

//==============================================================================
// Global functions
char hex2ascii(char* hex) {
  int code;
  sscanf(hex, "%X", &code);
  return (char)code;
}

int check(char c) {
  c = tolower(c);
  return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f');
}

/// HIFN The main entry-point function.
int main (int argc, char* argv[]) {
  int error = 0;
  freopen("log.txt", "w", stdout);

  printf ("Initialize and load resources\n");
  nullChk (InitCVIRTE (0, argv, 0));
  errChk (panelHandle = LoadPanel (0, "GUI.uir", PANEL));

  // Custom initialization
  // int FileBrowser_Create (int panel, int control, char *startPath);
  FileBrowser_Create(PANEL, PANEL_FILEBROWSER, "D:\\");

  /* display the panel and run the user interface */
  errChk (DisplayPanel (panelHandle));
  errChk (RunUserInterface ());

Error:
  /* clean up */
  printf("clean up\n");
  if (panelHandle > 0)
    DiscardPanel (panelHandle);
  return 0;
}

//==============================================================================
// UI callback function prototypes

#define EVENT(x) case x: printf(#x"\n"); break;

/// HIFN Exit when the user dismisses the panel.
// panelCB - panel CallBack
int CVICALLBACK panelCB (int panel, int event, void* callbackData,
                         int eventData1, int eventData2) {
  switch(event) {
      EVENT(EVENT_CLOSE);
      EVENT(EVENT_MOUSE_POINTER_MOVE);
      EVENT(EVENT_GOT_FOCUS);
      EVENT(EVENT_PANEL_RESTORE);
      EVENT(EVENT_DISCARD);
    default:
      printf("event = %d\n", event);
  }
  if (event == EVENT_CLOSE)
    QuitUserInterface (0);
  return 0;
}

int CVICALLBACK sumCB (int panel, int control, int event,
                       void* callbackData, int eventData1, int eventData2) {
  double A, B, Sum;
  int code;

  switch (event) {
    case EVENT_COMMIT:
      code = GetCtrlVal (PANEL, PANEL_NUMERIC_A, &A);
      printf("A = %f\n", A);
      code = GetCtrlVal (PANEL, PANEL_NUMERIC_B, &B);
      printf("B = %f\n", B);
      Sum = A + B;
      printf("Sum = %f\n", Sum);
      SetCtrlVal(PANEL, PANEL_NUMERIC_SUM, Sum);

      break;
  }
  return 0;
}

int CVICALLBACK Sum2 (int panel, int control, int event,
                      void* callbackData, int eventData1, int eventData2) {
  double A, B, Sum;
  int code;

  switch (event) {
    case EVENT_COMMIT:
      code = GetCtrlVal (PANEL, PANEL_SLIDE_A, &A);
      printf("A = %f\n", A);
      code = GetCtrlVal (PANEL, PANEL_SLIDE_B, &B);
      printf("B = %f\n", B);
      Sum = A + B;
      printf("Sum = %f\n", Sum);
      SetCtrlVal(PANEL, PANEL_THERM, Sum);

      break;
  }
  return 0;
}

int CVICALLBACK cbHex2ascii (int panel, int control, int event,
                             void* callbackData, int eventData1, int eventData2) {
  char hex[3];
  char symbol;
  char output[20];
  int code;
  int i;


  switch (event) {
    case EVENT_COMMIT:
      code = GetCtrlVal (PANEL, PANEL_STRING_HEX, hex);
      // Verification
      for(i = 0; i < strlen(hex); i++) {
        if(!check(hex[i])) {
          sprintf(output, "Error in %d: %c", (i + 1), hex[i]);
          SetCtrlVal(PANEL, PANEL_STRING_ASCII, output);
          return 0;
        }
      }

      symbol = hex2ascii(hex);
      sprintf(output, "Symbol: %c", symbol);
      SetCtrlVal(PANEL, PANEL_STRING_ASCII, output);

      break;
  }
  return 0;
}

int CVICALLBACK cbTimerTick (int panel, int control, int event,
                             void* callbackData, int eventData1, int eventData2) {
  static int count = 0;
  char str[100];

  count++;

  switch (event) {
    case EVENT_TIMER_TICK:
      sprintf(str, "Tick: %d", count);

      InsertListItem (PANEL, PANEL_LISTBOX, 0, str, count);

      break;
  }
  return 0;
}

int CVICALLBACK powerOfTwoCb (int panel, int control, int event,
                              void* callbackData, int eventData1, int eventData2) {
  switch (event) {
    case EVENT_COMMIT:

      break;
  }
  return 0;
}
