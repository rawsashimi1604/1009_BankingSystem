#include "loginhandler.h"

/**
 * Constructs LoginHandler object
 *
 * @param None
 *
 */
LoginHandler::LoginHandler()
{

}

/**
 * Attempts to login using username and password
 *
 * @param username -> Decrypted username
 * @param password -> Decrypted password
 * @return AUTHENTICATED if success, NOT_AUTHENTICATED if failure.
 */
LoginStatus LoginHandler::login(const std::string& username, const std::string& password) const{

    CredentialsReader cReader;
    Encrypter e;

    std::optional<Customer> customer = cReader.searchByUsername(username);

    if (!customer) {                 // Unable to find username.
        return NOT_AUTHENTICATED;
    }

    std::string retrievedUsername = customer->getUsername();
    std::string retrievedPassword = customer->getPassword();

    std::cout << e.hash(password) << std::endl;
    std::cout << retrievedPassword << std::endl;

    // Compare the 2 passwords
    if (e.hash(password) == retrievedPassword) {    // Correct password! Authenticate.
        return AUTHENTICATED;
    }

    return NOT_AUTHENTICATED;               // Wrong password! No Authenticate.
}








