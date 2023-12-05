#include <gtest/gtest.h>

extern "C" {
#include "isValidPassword.h"
}

class PasswordTest : public testing::Test
{
    protected:
        void SetUp() override
        {
            /* WIthout this the Tests could break */
        }
};

// A A A
// ARRANGE
// ACT
// ASSERT
TEST_F(PasswordTest, WhenLessThanEightCharsShouldReturnErrorTooShort)
{
    // ARRANGE
    const char *password = "1234567";
    // ACT
    PASSWORD_ERROR result = checkPassword(password);
    // ASSERT
    ASSERT_EQ(result, PASSWORD_ERROR_TOO_SHORT);
}

TEST_F(PasswordTest, WhenUpperCaseShouldReturnErrorNoUpperCase)
{
    // ARRANGE
    const char *password = "test12345";
    // ACT
    PASSWORD_ERROR result = checkPassword(password);
    // ASSERT
    ASSERT_EQ(result, PASSWORD_ERROR_NO_UPPERCASE_LETTER);
}