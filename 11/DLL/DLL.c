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
char* hex2ascii(char* hex) {
  int offset;
  char* data = hex; // Data points to next hex code
  int i = 0; // Index for current symbol in result string
  char* res = malloc((strlen(hex) + 1) / 2 + 1); // Result string
  int code; // Symbol code
  while(sscanf(data, "%X%n", &code, &offset) == 1) {
    res[i] = (char) code; // Save current char to result string
    data += offset; // Move on to next hex code
    i++; // Move to next char in result string
  }
  res[i] = 0; // Symbol with code 0 - string terminator
  return res;
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
