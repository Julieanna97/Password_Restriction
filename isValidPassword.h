#ifndef __ISVALIDPASSWORD_H
#define __ISVALIDPASSWORD_H
#include <string>

typedef enum
{
    PASSWORD_ERROR_OK,
    PASSWORD_ERROR_TOO_SHORT,   // Minimum 8 characters
    PASSWORD_ERROR_NO_UPPERCASE_LETTER, // Minimum 1 upper case 'A'
    PASSWORD_ERROR_NO_LOWERCASE_LETTER, // Minimum 1 lower case 'a'
    PASSWORD_ERROR_NO_NUMBER,    // At least 1 number '1'
    PASSWORD_ERROR_CANT_CONTAIN_CERTAIN_WORDS   // Can't contain words like
                                                // password, secret, summer, winter
} PASSWORD_ERROR;

PASSWORD_ERROR checkPassword(const std::string& password);

#endif