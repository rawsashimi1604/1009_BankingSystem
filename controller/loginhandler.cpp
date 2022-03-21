#include "loginhandler.h"

LoginHandler::LoginHandler()
{

}

string LoginHandler::decrypt(const string& str) {
    return "";
}

int LoginHandler::login(const string& username, const string& password) {

    // Look up username and query password from file..
    string fileUsername = "temp123";
    string filePassword = "temp123456";

 // If unable to find username,
//    if (notFound) {
//        return NOT_AUTHENTICATED;
//    }
    // Compare the 2 passwords
    if (password == filePassword) {
        return AUTHENTICATED;
    }
    return NOT_AUTHENTICATED;
}








