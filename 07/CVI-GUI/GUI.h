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
#define  PANEL_NUMERIC_SUM                2       /* control type: numeric, callback function: (none) */
#define  PANEL_NUMERIC_B                  3       /* control type: numeric, callback function: (none) */
#define  PANEL_NUMERIC_A                  4       /* control type: numeric, callback function: (none) */
#define  PANEL_COMMANDBUTTON              5       /* control type: command, callback function: sumCB */
#define  PANEL_SLIDE_B                    6       /* control type: scale, callback function: Sum2 */
#define  PANEL_SLIDE_A                    7       /* control type: scale, callback function: Sum2 */
#define  PANEL_THERM                      8       /* control type: scale, callback function: (none) */
#define  PANEL_STRING_ASCII               9       /* control type: string, callback function: (none) */
#define  PANEL_STRING_HEX                 10      /* control type: string, callback function: cbHex2ascii */
#define  PANEL_RADIOBUTTON_3              11      /* control type: radioButton, callback function: (none) */
#define  PANEL_RADIOBUTTON_2              12      /* control type: radioButton, callback function: (none) */
#define  PANEL_RADIOBUTTON                13      /* control type: radioButton, callback function: (none) */
#define  PANEL_RADIOGROUP                 14      /* control type: tree, callback function: (none) */
#define  PANEL_RING                       15      /* control type: ring, callback function: powerOfTwoCb */
#define  PANEL_LISTBOX                    16      /* control type: listBox, callback function: (none) */
#define  PANEL_CANVAS                     17      /* control type: canvas, callback function: (none) */
#define  PANEL_FILEBROWSER                18      /* control type: tree, callback function: (none) */
#define  PANEL_TIMER                      19      /* control type: timer, callback function: cbTimerTick */


/* Control Arrays: */

#define  CTRLARRAY                        1

/* Menu Bars, Menus, and Menu Items: */

/* (no menu bars in the resource file) */


/* Callback Prototypes: */

int  CVICALLBACK cbHex2ascii(int panel, int control, int event, void* callbackData, int eventData1, int eventData2);
int  CVICALLBACK cbTimerTick(int panel, int control, int event, void* callbackData, int eventData1, int eventData2);
int  CVICALLBACK panelCB(int panel, int event, void* callbackData, int eventData1, int eventData2);
int  CVICALLBACK powerOfTwoCb(int panel, int control, int event, void* callbackData, int eventData1, int eventData2);
int  CVICALLBACK Sum2(int panel, int control, int event, void* callbackData, int eventData1, int eventData2);
int  CVICALLBACK sumCB(int panel, int control, int event, void* callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
}
#endif
