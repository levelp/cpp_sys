//==============================================================================
//
// Title:   NI_DLL
// Purpose:   A short description of the library.
//
//==============================================================================

//==============================================================================
// Include files

#include <utility.h>
#include "NI_DLL.h"

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

int sqr(int x) {
  return x * x;
}


/// HIFN  What does your function do?
/// HIPAR x/What inputs does your function expect?
/// HIRET What does your function return?
int Your_Functions_Here (int x) {
  return x;
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
