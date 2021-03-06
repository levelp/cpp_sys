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
#define  PANEL_HEX_STRING                 2       /* control type: string, callback function: (none) */
#define  PANEL_RES_STRING                 3       /* control type: string, callback function: (none) */
#define  PANEL_COMMANDBUTTON              4       /* control type: command, callback function: convert */


/* Control Arrays: */

/* (no control arrays in the resource file) */


/* Menu Bars, Menus, and Menu Items: */

/* (no menu bars in the resource file) */


/* Callback Prototypes: */

int  CVICALLBACK convert(int panel, int control, int event, void* callbackData, int eventData1, int eventData2);
int  CVICALLBACK panelCB(int panel, int event, void* callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
}
#endif
