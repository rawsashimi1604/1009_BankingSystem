#ifndef LOGINHANDLER_H
#define LOGINHANDLER_H

#define AUTHENTICATED 1
#define NOT_AUTHENTICATED 0

#include <iostream>
#include <string>

using namespace std;

class LoginHandler
{

private:
    string decrypt(const string& str);
public:
    LoginHandler();

    int login(const string& username, const string& password);

};

#endif // LOGINHANDLER_H
