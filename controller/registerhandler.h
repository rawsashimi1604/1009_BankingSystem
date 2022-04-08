#ifndef REGISTERHANDLER_H
#define REGISTERHANDLER_H

#include <iostream>
#include <string>

#include "credentialsreader.h"
#include "utils.h"

/**
 * RegisterHandler contains a set of functions that interface with the Register View page.
 *
 */
#define REGISTER_SUCCESS 1                      // Registration SUCCESS
#define REGISTER_FAILURE_NAME_EXISTS 0          // Registration FAILED, a user with the same name already exists.
#define REGISTER_FAILURE_FILE_ERROR -1          // Registration FAILED, unable to access database.

typedef int RegisterStatus;                     // Defines RegisterStatus type (int)

class RegisterHandler
{
private:

public:
    RegisterHandler();                          // Constructs the RegisterHandler Object
    RegisterStatus registerAcc(const std::string &firstName, const std::string &lastName, const int age, const std::string &username, const std::string &password) const;                   // Attempts to register a Customer with specified parameters.
};

#endif // REGISTERHANDLER_H
