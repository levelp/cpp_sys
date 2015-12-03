/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/* Copyright (c) National Instruments 2015. All Rights Reserved.          */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Panels and Controls: */

#define  PANEL                            1       /* callback function: panelCB */
#define  PANEL_COM_PORT                   2       /* control type: ring, callback function: (none) */
#define  PANEL_SERIAL_NUMBER              3       /* control type: string, callback function: enterSerialNumber */
#define  PANEL_COMMANDBUTTON              4       /* control type: command, callback function: checkWriteRead */
#define  PANEL_SN_RESULT                  5       /* control type: string, callback function: (none) */
#define  PANEL_SN_LED                     6       /* control type: LED, callback function: (none) */
#define  PANEL_STRIPCHART                 7       /* control type: strip, callback function: (none) */
#define  PANEL_TIMER                      8       /* control type: timer, callback function: cbTimerTick */


/* Control Arrays: */

/* (no control arrays in the resource file) */


/* Menu Bars, Menus, and Menu Items: */

/* (no menu bars in the resource file) */


/* Callback Prototypes: */

int  CVICALLBACK cbTimerTick(int panel, int control, int event, void* callbackData, int eventData1, int eventData2);
int  CVICALLBACK checkWriteRead(int panel, int control, int event, void* callbackData, int eventData1, int eventData2);
int  CVICALLBACK enterSerialNumber(int panel, int control, int event, void* callbackData, int eventData1, int eventData2);
int  CVICALLBACK panelCB(int panel, int event, void* callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
}
#endif
