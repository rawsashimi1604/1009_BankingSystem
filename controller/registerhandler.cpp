#include "registerhandler.h"

RegisterHandler::RegisterHandler()
{

}

string RegisterHandler::encrypt(const string& str) {
    return "";
}

RegisterStatus RegisterHandler::registerAcc(const string& firstName, const string& lastName, const int age, const string& username, const string& password) const {

    // check if username exists,
    // if exists, return failure
    // else, write to customers.csv.
    // return SUCCESS

    CredentialsReader cReader;
    if (cReader.searchByUsername(username)) {       // Username already exists, can't use username.
        return REGISTER_FAILURE_NAME_EXISTS;
    }

    // Write to customer.csv
    Date currDate = UtilityFunctions::getTodaysDate();
    Customer customer(cReader.getNextID(), firstName, lastName, age, username, password, currDate);

    if (cReader.write(customer)) {
        return REGISTER_SUCCESS;                    // Successfully added to customers.csv!
    }

    return REGISTER_FAILURE_FILE_ERROR;             // something went wrong with file opening...
}

