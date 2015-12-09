//==============================================================================
// Title:   GUI_App
//==============================================================================

//==============================================================================
// Include files

#include <ansi_c.h>
#include <cvirte.h>
#include <userint.h>
#include "GUI_App.h"
#include "toolbox.h"
#include "../DLL/DLL.h"

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

/// HIFN The main entry-point function.
int main (int argc, char* argv[]) {
  int error = 0;

  /* initialize and load resources */
  nullChk (InitCVIRTE (0, argv, 0));
  errChk (panelHandle = LoadPanel (0, "GUI_App.uir", PANEL));

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

int CVICALLBACK convert (int panel, int control, int event,
                         void* callbackData, int eventData1, int eventData2) {
  switch (event) {
    case EVENT_COMMIT:
      char str[1024];
      GetCtrlVal(PANEL, PANEL_HEX_STRING, str);
      char* res = hex2ascii(str);
      SetCtrlVal(PANEL, PANEL_RES_STRING, res);
      free(res);

      break;
  }
  return 0;
}
