#include "loginhandler.h"

LoginHandler::LoginHandler()
{

}

std::string LoginHandler::encrypt(const std::string& str) {
    return "";
}

LoginStatus LoginHandler::login(const std::string& username, const std::string& password) const{

    CredentialsReader cReader;

    std::optional<Customer> customer = cReader.searchByUsername(username);

    if (!customer) {                 // Unable to find username.

        return NOT_AUTHENTICATED;
    }

    std::string retrievedUsername = customer->getUsername();
    std::string retrievedPassword = customer->getPassword();

    // Compare the 2 passwords
    if (password == retrievedPassword) {    // Correct password! Authenticate.
        return AUTHENTICATED;
    }

    return NOT_AUTHENTICATED;               // Wrong password! No Authenticate.
}








