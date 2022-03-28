#ifndef LOGINHANDLER_H
#define LOGINHANDLER_H

#define AUTHENTICATED 1
#define NOT_AUTHENTICATED 0

#include <iostream>
#include <string>

#include "credentialsreader.h"

using namespace std;

class LoginHandler
{

private:

public:
    LoginHandler();
    string encrypt(const string& str);
    int login(const string& username, const string& password) const;

};

#endif // LOGINHANDLER_H
