//==============================================================================
//
// Title:   IniUtils.h
// Purpose:   Util functions for Ini-file.
//
//==============================================================================

#ifndef __IniUtils_H__
#define __IniUtils_H__

#ifdef __cplusplus
extern "C" {
#endif

//==============================================================================
// Include files

#include "cvidef.h"

//==============================================================================
// Variables

IniText iniText;
int iniHasChanges = 0;
char pathName[MAX_PATHNAME_LEN];

//==============================================================================
// Global functions

void Ini_Begin(const char fileName[]) {
  char dirName[MAX_PATHNAME_LEN];

  /* set up the pathName for the .ini file */
  GetProjectDir(dirName);
  MakePathname(dirName, fileName, pathName);

  /* create object for holding the value/tag pairs */
  iniText = Ini_New(TRUE); /* TRUE for automatic sorting */

  Ini_SetAddQuotesToStrings(iniText, 0);
  // "Test" -> Test

  /* read in the tag/value pairs */
  Ini_ReadFromFile(iniText, pathName);

  iniHasChanges = 0;
}

void Ini_End() {
  // Ini has changes only if we have key that doesn't exits in *.ini
  if(iniHasChanges) {
    /* write out the tag/value pairs */
    Ini_WriteToFile(iniText, pathName);
    iniHasChanges = 0;
  }

  /* dispose of the in–memory tag/value pairs */
  Ini_Dispose(iniText);
}

// char*
void Ini_String(const char* section, const char* itemName, char** value) {
  if(Ini_ItemExists(iniText, section, itemName))
    Ini_GetStringCopy(iniText, section, itemName, value);
  else {
    Ini_PutString(iniText, section, itemName, *value);
    iniHasChanges = 1;
  }
}

// int
void Ini_Int(const char* section, const char* itemName, int* value) {
  if(Ini_ItemExists(iniText, section, itemName))
    Ini_GetInt(iniText, section, itemName, value);
  else {
    Ini_PutInt(iniText, section, itemName, *value);
    iniHasChanges = 1;
  }
}

// double
void Ini_Double(const char* section, const char* itemName, double* value) {
  if(Ini_ItemExists(iniText, section, itemName))
    Ini_GetDouble(iniText, section, itemName, value);
  else {
    Ini_PutDouble(iniText, section, itemName, *value);
    iniHasChanges = 1;
  }
}

// int: TRUE - 1 / FALSE - 0
void Ini_Boolean(const char* section, const char* itemName, int* value) {
  if(Ini_ItemExists(iniText, section, itemName))
    Ini_GetBoolean(iniText, section, itemName, value);
  else {
    Ini_PutBoolean(iniText, section, itemName, *value);
    iniHasChanges = 1;
  }
}


#ifdef __cplusplus
}
#endif

#endif  /* ndef __IniUtils_H__ */
