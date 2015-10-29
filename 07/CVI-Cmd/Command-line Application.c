//==============================================================================
//
// Title:   Command-line Application
// Purpose:   A short description of the command-line tool.
//
// Created on:  25.11.2015 at 20:06:46 by Denis Stepulenok.
//
//==============================================================================

//==============================================================================
// Include files

#include <ansi_c.h>
#include <stdio.h>
//#include <iostream>

//#define S(x) cout << #x << " = " << x << endl;

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Static functions

/// HIFN  Explain how to use this command-line tool.
/// HIPAR name/The name of the command-line tool.
static void usage (char* name) {
  fprintf (stderr, "usage: %s <hexCode>\n", name);
  fprintf (stderr, "Convert hex-code to ASCII char.\n");
  fprintf (stderr, "    <hexCode>  - hex code of char, for example: 41\n");
  exit (1);
}

//==============================================================================
// Global variables

//==============================================================================
// Global functions

// На выходе - ASCII символ
// На входе 2
char hex2ascii(char* hex) {
  int code;
  sscanf(hex, "%X", &code);
  return (char)code;
}

/*string ascii2hex(char c) {
  char str[3]; // <-- сюда будем печатать
  sprintf(str, "%02X", (int)c);
  return string(str);
} */

/// HIFN  The main entry-point function.
/// HIPAR argc/The number of command-line arguments.
/// HIPAR argc/This number includes the name of the command-line tool.
/// HIPAR argv/An array of command-line arguments.
/// HIPAR argv/Element 0 contains the name of the command-line tool.
/// HIRET Returns 0 if successful.
int main (int argc, char* argv[]) {
  char* hex = "41";

  FILE* out = fopen("log.txt", "w");
  fprintf(out, "%c\n", hex2ascii(hex));
  fclose(out);

  // system("cmd /c pause");

  // Пишем по-русски
  if (argc < 2 || argc > 3)
    usage (argv[0]);

  // Work:
  //  argv[1] - first command line arg
  // ExeName.exe 41 -> Char: A
  printf("Char: %c\n", hex2ascii(argv[1]));

  return 0;
}

