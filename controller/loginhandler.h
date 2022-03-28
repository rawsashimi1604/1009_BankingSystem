#ifndef LOGINHANDLER_H
#define LOGINHANDLER_H

#include <iostream>
#include <string>

#include "credentialsreader.h"

#define AUTHENTICATED 1
#define NOT_AUTHENTICATED 0

typedef int LoginStatus;

using namespace std;

class LoginHandler
{

private:

public:
    LoginHandler();
    string encrypt(const string& str);
    LoginStatus login(const string& username, const string& password) const;

};

#endif // LOGINHANDLER_H
