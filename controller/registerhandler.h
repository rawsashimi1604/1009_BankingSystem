#ifndef REGISTERHANDLER_H
#define REGISTERHANDLER_H

#include <iostream>
#include <string>

#include "credentialsreader.h"
#include "utils.h"

#define REGISTER_SUCCESS 1
#define REGISTER_FAILURE_NAME_EXISTS 0
#define REGISTER_FAILURE_FILE_ERROR -1

typedef int RegisterStatus;

class RegisterHandler
{
private:

public:
    RegisterHandler();
    RegisterStatus registerAcc(const std::string &firstName, const std::string &lastName, const int age, const std::string &username, const std::string &password) const;
};

#endif // REGISTERHANDLER_H
