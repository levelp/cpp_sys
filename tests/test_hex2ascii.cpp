#include <gtest/gtest.h>
#include <cstring>
#include "hex2ascii.h"

class Hex2AsciiTest : public ::testing::Test {
protected:
    void TearDown() override {
        // Clean up any allocated memory if needed
    }
};

// Test 1: Basic conversion "41 42" -> "AB"
TEST_F(Hex2AsciiTest, BasicConversion) {
    char* result = hex2ascii("4142");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "AB");
    free(result);
}

// Test 2: Single character
TEST_F(Hex2AsciiTest, SingleCharacter) {
    char* result = hex2ascii("41");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "A");
    free(result);
}

// Test 3: Lowercase hex
TEST_F(Hex2AsciiTest, LowercaseHex) {
    char* result = hex2ascii("61");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "a");
    free(result);
}

// Test 4: Numbers
TEST_F(Hex2AsciiTest, Numbers) {
    char* result = hex2ascii("313233");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "123");
    free(result);
}

// Test 5: Empty string
TEST_F(Hex2AsciiTest, EmptyString) {
    char* result = hex2ascii("");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "");
    free(result);
}

// Test 6: Space character (0x20)
TEST_F(Hex2AsciiTest, SpaceCharacter) {
    char* result = hex2ascii("20");
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result[0], ' ');
    EXPECT_EQ(result[1], '\0');
    free(result);
}

// Test 7: Full alphabet uppercase
TEST_F(Hex2AsciiTest, FullAlphabetUppercase) {
    char* result = hex2ascii("4142434445464748494A4B4C4D4E4F505152535455565758595A");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    free(result);
}

// Test 8: Full alphabet lowercase
TEST_F(Hex2AsciiTest, FullAlphabetLowercase) {
    char* result = hex2ascii("6162636465666768696A6B6C6D6E6F707172737475767778797A");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "abcdefghijklmnopqrstuvwxyz");
    free(result);
}

// Test 9: Digits 0-9
TEST_F(Hex2AsciiTest, Digits) {
    char* result = hex2ascii("30313233343536373839");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "0123456789");
    free(result);
}

// Test 10: Special characters
TEST_F(Hex2AsciiTest, SpecialCharacters) {
    char* result = hex2ascii("21402324255E262A");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "!@#$%^&*");
    free(result);
}

// Test 11: Null character (0x00)
TEST_F(Hex2AsciiTest, NullCharacter) {
    char* result = hex2ascii("00");
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result[0], '\0');
    free(result);
}

// Test 12: Multiple null characters
TEST_F(Hex2AsciiTest, MultipleNullCharacters) {
    char* result = hex2ascii("000000");
    ASSERT_NE(result, nullptr);
    // First character should be null terminator
    EXPECT_EQ(result[0], '\0');
    free(result);
}

// Test 13: Tab and newline
TEST_F(Hex2AsciiTest, TabAndNewline) {
    char* result = hex2ascii("090A");
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result[0], '\t');
    EXPECT_EQ(result[1], '\n');
    EXPECT_EQ(result[2], '\0');
    free(result);
}

// Test 14: High ASCII values
TEST_F(Hex2AsciiTest, HighAsciiValues) {
    char* result = hex2ascii("FFFEFD");
    ASSERT_NE(result, nullptr);
    EXPECT_EQ((unsigned char)result[0], 0xFF);
    EXPECT_EQ((unsigned char)result[1], 0xFE);
    EXPECT_EQ((unsigned char)result[2], 0xFD);
    EXPECT_EQ(result[3], '\0');
    free(result);
}

// Test 15: Long string
TEST_F(Hex2AsciiTest, LongString) {
    // "Hello World" repeated
    char* result = hex2ascii("48656C6C6F20576F726C6448656C6C6F20576F726C64");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "Hello WorldHello World");
    free(result);
}

// Test 16: Hex with spaces (from original example comment)
TEST_F(Hex2AsciiTest, HexWithSpaces) {
    char* result = hex2ascii("E8 10 23");
    ASSERT_NE(result, nullptr);
    // Should parse E8, then stop at space and ignore rest
    EXPECT_EQ((unsigned char)result[0], 0xE8);
    free(result);
}

// Test 17: Mixed case hex digits
TEST_F(Hex2AsciiTest, MixedCaseHex) {
    char* result = hex2ascii("4142");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "AB");
    free(result);
}

// Test 18: Sentence
TEST_F(Hex2AsciiTest, Sentence) {
    char* result = hex2ascii("48656C6C6F2C20576F726C6421");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "Hello, World!");
    free(result);
}

// Test 19: All printable ASCII
TEST_F(Hex2AsciiTest, PrintableAscii) {
    char* result = hex2ascii("20212223");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, " !\"#");
    free(result);
}

// Test 20: Parentheses and brackets
TEST_F(Hex2AsciiTest, ParenthesesAndBrackets) {
    char* result = hex2ascii("28295B5D7B7D");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "()[]{}");
    free(result);
}

// Test 21: Backslash and forward slash
TEST_F(Hex2AsciiTest, Slashes) {
    char* result = hex2ascii("5C2F");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "\\/");
    free(result);
}

// Test 22: Equals and plus
TEST_F(Hex2AsciiTest, EqualsAndPlus) {
    char* result = hex2ascii("3D2B");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "=+");
    free(result);
}

// Test 23: Underscore and hyphen
TEST_F(Hex2AsciiTest, UnderscoreAndHyphen) {
    char* result = hex2ascii("5F2D");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "_-");
    free(result);
}

// Test 24: Comma and period
TEST_F(Hex2AsciiTest, CommaAndPeriod) {
    char* result = hex2ascii("2C2E");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, ",.");
    free(result);
}

// Test 25: Semicolon and colon
TEST_F(Hex2AsciiTest, SemicolonAndColon) {
    char* result = hex2ascii("3B3A");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, ";:");
    free(result);
}

// Test 26: Question mark and exclamation
TEST_F(Hex2AsciiTest, QuestionAndExclamation) {
    char* result = hex2ascii("3F21");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "?!");
    free(result);
}

// Test 27: Less than and greater than
TEST_F(Hex2AsciiTest, LessThanAndGreaterThan) {
    char* result = hex2ascii("3C3E");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "<>");
    free(result);
}

// Test 28: Pipe and ampersand
TEST_F(Hex2AsciiTest, PipeAndAmpersand) {
    char* result = hex2ascii("7C26");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "|&");
    free(result);
}

// Test 29: Tilde
TEST_F(Hex2AsciiTest, Tilde) {
    char* result = hex2ascii("7E");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "~");
    free(result);
}

// Test 30: Backtick
TEST_F(Hex2AsciiTest, Backtick) {
    char* result = hex2ascii("60");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "`");
    free(result);
}

// Test 31: Carriage return
TEST_F(Hex2AsciiTest, CarriageReturn) {
    char* result = hex2ascii("0D");
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result[0], '\r');
    EXPECT_EQ(result[1], '\0');
    free(result);
}

// Test 32: Form feed
TEST_F(Hex2AsciiTest, FormFeed) {
    char* result = hex2ascii("0C");
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result[0], '\f');
    EXPECT_EQ(result[1], '\0');
    free(result);
}

// Test 33: Vertical tab
TEST_F(Hex2AsciiTest, VerticalTab) {
    char* result = hex2ascii("0B");
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result[0], '\v');
    EXPECT_EQ(result[1], '\0');
    free(result);
}

// Test 34: Bell character
TEST_F(Hex2AsciiTest, BellCharacter) {
    char* result = hex2ascii("07");
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result[0], '\a');
    EXPECT_EQ(result[1], '\0');
    free(result);
}

// Test 35: Backspace
TEST_F(Hex2AsciiTest, Backspace) {
    char* result = hex2ascii("08");
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result[0], '\b');
    EXPECT_EQ(result[1], '\0');
    free(result);
}
