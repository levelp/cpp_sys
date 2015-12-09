//==============================================================================
//
// Title:   DLL
//
//==============================================================================

//==============================================================================
// Include files

#include <ansi_c.h>
#include <utility.h>
#include "DLL.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Static functions

//==============================================================================
// Global variables

//==============================================================================
// Global functions

/// HIFN  Convert from hex string to bytes: 41 42 -> AB
/// HIPAR hex hex string, example: E8 10 23
/// HIRET string
char hex2ascii(char* hex) {
  int code;
  sscanf(hex, "%X", &code);
  return (char)code;
}

//==============================================================================
// DLL main entry-point functions

int __stdcall DllMain (HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
  switch (fdwReason) {
    case DLL_PROCESS_ATTACH:
      if (InitCVIRTE (hinstDLL, 0, 0) == 0)
        return 0;   /* out of memory */
      break;
    case DLL_PROCESS_DETACH:
      CloseCVIRTE ();
      break;
  }

  return 1;
}

int __stdcall DllEntryPoint (HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
  /* Included for compatibility with Borland */

  return DllMain (hinstDLL, fdwReason, lpvReserved);
}
