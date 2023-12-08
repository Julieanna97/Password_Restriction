#include <gtest/gtest.h>

extern "C++" {
    #include "password.h"
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
    const char *password = "tT1237";
    // ACT
    PASSWORD_ERROR error = checkPassword(password);
    // ASSERT
    ASSERT_EQ(error, PASSWORD_ERROR_TOO_SHORT);
}

TEST_F(PasswordTest, WhenUpperCaseShouldReturnErrorNoUpperCase)
{
    // ARRANGE
    const char *password = "test12345";
    // ACT
    PASSWORD_ERROR error = checkPassword(password);
    // ASSERT
    ASSERT_EQ(error, PASSWORD_ERROR_NO_UPPERCASE_LETTER);
}

TEST_F(PasswordTest,WhenNoLowerCaseShouldReturnErrorNoLowerCase){
    // ARRANGE
    const char *password = "TEST12345";
    // ACT 
    PASSWORD_ERROR error = checkPassword(password);
    //ASSERT
    ASSERT_EQ(error, PASSWORD_ERROR_NO_LOWERCASE_LETTER);
}


TEST_F(PasswordTest,WhenBadWordsShouldReturnErrorNoCertainWords){
    // ARRANGE
    const char *password = "Test123password45";
    // ACT 
    PASSWORD_ERROR error = checkPassword(password);
    //ASSERT
    ASSERT_EQ(error, PASSWORD_ERROR_CANT_CONTAIN_CERTAIN_WORDS);
}

