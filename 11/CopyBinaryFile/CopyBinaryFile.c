//==============================================================================
// Include files

#include <ansi_c.h>

/// HIFN  The main entry-point function.
/// HIPAR argc/The number of command-line arguments.
/// HIPAR argc/This number includes the name of the command-line tool.
/// HIPAR argv/An array of command-line arguments.
/// HIPAR argv/Element 0 contains the name of the command-line tool.
/// HIRET Returns 0 if successful.
int main (int argc, char* argv[]) {
  // Open input file
  // rb - read + binary
  FILE* in = fopen("TEST.BIN", "rb");
  // while(!feof(in)){

  //  char c = fgetc(in);

  // Open output file
  // wb - write + binary
  FILE* out = fopen("sample.bin", "wb");

  char value = 0;
  for (int i = 0; i <= 17; i++) {
    value = fgetc(in); // fs1 >> value;
    fputc(value, out); // fs2 << value;
  }

  return 0;
}

