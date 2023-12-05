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
    // ACT
    // ASSERT
}