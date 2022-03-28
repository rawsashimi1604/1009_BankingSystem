#ifndef REGISTERHANDLER_H
#define REGISTERHANDLER_H

#include <iostream>
#include <string>

#include "credentialsreader.h"

#define REGISTER_SUCCESS 1
#define REGISTER_FAILURE 0

typedef int RegisterStatus;

using namespace std;

class RegisterHandler
{
private:

public:
    RegisterHandler();
    string encrypt(const string& str);
    RegisterStatus registerAcc(const string& username, const string& password) const;
};

#endif // REGISTERHANDLER_H
