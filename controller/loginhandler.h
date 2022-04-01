#ifndef LOGINHANDLER_H
#define LOGINHANDLER_H

#include <iostream>
#include <string>

#include "credentialsreader.h"

#define AUTHENTICATED 1
#define NOT_AUTHENTICATED 0

typedef int LoginStatus;

class LoginHandler
{

private:

public:
    LoginHandler();
    std::string encrypt(const std::string& str);
    LoginStatus login(const std::string& username, const std::string& password) const;

};

#endif // LOGINHANDLER_H
