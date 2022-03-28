#include "loginhandler.h"

LoginHandler::LoginHandler()
{

}

string LoginHandler::encrypt(const string& str) {
    return "";
}

LoginStatus LoginHandler::login(const string& username, const string& password) const{

    CredentialsReader cReader;

    Customer* customer = cReader.searchByUsername(username);

    if (customer == NULL) {                 // Unable to find username.

        return NOT_AUTHENTICATED;
    }

    string retrievedUsername = customer->getUsername();
    string retrievedPassword = customer->getPassword();
    // Compare the 2 passwords

    if (password == retrievedPassword) {    // Correct password! Authenticate.
        free(customer);
        return AUTHENTICATED;
    }

    return NOT_AUTHENTICATED;               // Wrong password! No Authenticate.
}








