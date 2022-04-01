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

using namespace std;

class RegisterHandler
{
private:

public:
    RegisterHandler();
    string encrypt(const string& str);
    RegisterStatus registerAcc(const string& firstName, const string& lastName, const int age, const string& username, const string& password) const;
};

#endif // REGISTERHANDLER_H
