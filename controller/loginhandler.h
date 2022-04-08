#ifndef LOGINHANDLER_H
#define LOGINHANDLER_H

#include <iostream>
#include <string>

#include "controller/credentialsreader.h"
#include "controller/encrypter.h"

/**
 * LoginHandler contains a set of functions that interface with the Login View page.
 *
 */
#define AUTHENTICATED 1                     // Customer AUTHENTICATION successful
#define NOT_AUTHENTICATED 0                 // Customer AUTHENTICATION faillure

typedef int LoginStatus;                    // Defines LoginStatus type (int)

class LoginHandler
{

private:

public:
    LoginHandler();                         // Constructs LoginHandler object
    LoginStatus login(const std::string& username, const std::string& password) const;  // Attempts to login using username and password

};

#endif // LOGINHANDLER_H
