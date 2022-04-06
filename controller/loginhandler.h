#ifndef LOGINHANDLER_H
#define LOGINHANDLER_H

#include <iostream>
#include <string>

#include "controller/credentialsreader.h"
#include "controller/encrypter.h"

#define AUTHENTICATED 1
#define NOT_AUTHENTICATED 0

typedef int LoginStatus;

class LoginHandler
{

private:

public:
    LoginHandler();
    LoginStatus login(const std::string& username, const std::string& password) const;

};

#endif // LOGINHANDLER_H
