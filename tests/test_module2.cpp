#include <gtest/gtest.h>
#include <string>
#include <cstdio>

// Functions from 07/MultipleCpp/module2.cpp
char hex2ascii_module2(char* hex) {
    int code;
    sscanf(hex, "%X", &code);
    return (char)code;
}

std::string ascii2hex(char c) {
    char str[3];
    sprintf(str, "%02X", (int)c);
    return std::string(str);
}

// Tests
class Module2Test : public ::testing::Test {};

// Test 1: hex2ascii basic
TEST_F(Module2Test, Hex2AsciiBasic) {
    char hex[] = "41";
    EXPECT_EQ(hex2ascii_module2(hex), 'A');
}

// Test 2: hex2ascii lowercase
TEST_F(Module2Test, Hex2AsciiLowercase) {
    char hex[] = "61";
    EXPECT_EQ(hex2ascii_module2(hex), 'a');
}

// Test 3: hex2ascii digit
TEST_F(Module2Test, Hex2AsciiDigit) {
    char hex[] = "30";
    EXPECT_EQ(hex2ascii_module2(hex), '0');
}

// Test 4: hex2ascii space
TEST_F(Module2Test, Hex2AsciiSpace) {
    char hex[] = "20";
    EXPECT_EQ(hex2ascii_module2(hex), ' ');
}

// Test 5: ascii2hex uppercase
TEST_F(Module2Test, Ascii2HexUppercase) {
    EXPECT_EQ(ascii2hex('A'), "41");
}

// Test 6: ascii2hex lowercase
TEST_F(Module2Test, Ascii2HexLowercase) {
    EXPECT_EQ(ascii2hex('a'), "61");
}

// Test 7: ascii2hex digit
TEST_F(Module2Test, Ascii2HexDigit) {
    EXPECT_EQ(ascii2hex('0'), "30");
}

// Test 8: ascii2hex space
TEST_F(Module2Test, Ascii2HexSpace) {
    EXPECT_EQ(ascii2hex(' '), "20");
}

// Test 9: Round trip A
TEST_F(Module2Test, RoundTripA) {
    char hex[] = "41";
    char result = hex2ascii_module2(hex);
    std::string back = ascii2hex(result);
    EXPECT_EQ(back, "41");
}

// Test 10: Round trip lowercase
TEST_F(Module2Test, RoundTripLowercase) {
    char hex[] = "61";
    char result = hex2ascii_module2(hex);
    std::string back = ascii2hex(result);
    EXPECT_EQ(back, "61");
}

// Test 11: All uppercase letters
TEST_F(Module2Test, AllUppercaseLetters) {
    const char* letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i = 0; letters[i]; i++) {
        std::string hex = ascii2hex(letters[i]);
        char hexCopy[3];
        strcpy(hexCopy, hex.c_str());
        char result = hex2ascii_module2(hexCopy);
        EXPECT_EQ(result, letters[i]);
    }
}

// Test 12: All lowercase letters
TEST_F(Module2Test, AllLowercaseLetters) {
    const char* letters = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; letters[i]; i++) {
        std::string hex = ascii2hex(letters[i]);
        char hexCopy[3];
        strcpy(hexCopy, hex.c_str());
        char result = hex2ascii_module2(hexCopy);
        EXPECT_EQ(result, letters[i]);
    }
}

// Test 13: All digits
TEST_F(Module2Test, AllDigits) {
    const char* digits = "0123456789";
    for(int i = 0; digits[i]; i++) {
        std::string hex = ascii2hex(digits[i]);
        char hexCopy[3];
        strcpy(hexCopy, hex.c_str());
        char result = hex2ascii_module2(hexCopy);
        EXPECT_EQ(result, digits[i]);
    }
}

// Test 14: Special characters
TEST_F(Module2Test, SpecialCharacters) {
    const char* special = "!@#$%^&*()";
    for(int i = 0; special[i]; i++) {
        std::string hex = ascii2hex(special[i]);
        char hexCopy[3];
        strcpy(hexCopy, hex.c_str());
        char result = hex2ascii_module2(hexCopy);
        EXPECT_EQ(result, special[i]);
    }
}

// Test 15: Newline and tab
TEST_F(Module2Test, NewlineAndTab) {
    EXPECT_EQ(ascii2hex('\n'), "0A");
    EXPECT_EQ(ascii2hex('\t'), "09");
}

// Test 16: Null character
TEST_F(Module2Test, NullCharacter) {
    EXPECT_EQ(ascii2hex('\0'), "00");
}

// Test 17: High ASCII
TEST_F(Module2Test, HighASCII) {
    char hex[] = "FF";
    char result = hex2ascii_module2(hex);
    EXPECT_EQ((unsigned char)result, 0xFF);
}

// Test 18: Brackets
TEST_F(Module2Test, Brackets) {
    EXPECT_EQ(ascii2hex('('), "28");
    EXPECT_EQ(ascii2hex(')'), "29");
    EXPECT_EQ(ascii2hex('['), "5B");
    EXPECT_EQ(ascii2hex(']'), "5D");
}

// Test 19: Slash characters
TEST_F(Module2Test, Slashes) {
    EXPECT_EQ(ascii2hex('/'), "2F");
    EXPECT_EQ(ascii2hex('\\'), "5C");
}

// Test 20: Equals and plus
TEST_F(Module2Test, EqualsAndPlus) {
    EXPECT_EQ(ascii2hex('='), "3D");
    EXPECT_EQ(ascii2hex('+'), "2B");
}
