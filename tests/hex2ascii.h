#ifndef HEX2ASCII_H
#define HEX2ASCII_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Standalone version of hex2ascii for testing (without Windows dependencies)
// Original from 11/DLL/DLL.c
inline char* hex2ascii(const char* hex) {
    int offset;
    const char* data = hex; // Data points to next hex code
    int i = 0; // Index for current symbol in result string
    char* res = (char*)malloc((strlen(hex) + 1) / 2 + 1); // Result string
    int code; // Symbol code

    if (res == NULL) {
        return NULL;
    }

    while(sscanf(data, "%02X%n", &code, &offset) == 1) {
        res[i] = (char) code; // Save current char to result string
        data += offset; // Move on to next hex code
        i++; // Move to next char in result string
    }
    res[i] = 0; // Symbol with code 0 - string terminator

    return res;
}

#endif // HEX2ASCII_H
