#include "registerhandler.h"

/**
 * Constructs RegisterHandler object
 *
 * @param None
 *
 */
RegisterHandler::RegisterHandler()
{

}

/**
 * Attempts to register a Customer with specified parameters. If successful, adds to the customer database.
 *
 * @param firstName -> first name to register with
 * @param lastName -> last name to register with
 * @param age -> age to register with
 * @param username -> username to register with
 * @param password -> password to register with
 * @return Returns REGISTER_SUCCESS if successful,
 * REGISTER_FAILURE_NAME_EXISTS if failure, name already exists,
 * REGISTER_FAILURE_FILE_ERROR if failure unable to access database.
 */
RegisterStatus RegisterHandler::registerAcc(const std::string& firstName, const std::string& lastName, const int age, const std::string& username, const std::string& password) const {

    // check if username exists,
    // if exists, return failure
    // else, write to customers.csv.
    // return SUCCESS

    CredentialsReader cReader;
    if (cReader.searchByUsername(username)) {       // Username already exists, can't use username.
        std::cout << "REGISTER_FAILURE_NAME_EXISTS" << std::endl;
        return REGISTER_FAILURE_NAME_EXISTS;
    }

    // Write to customer.csv
    Date currDate = UtilityFunctions::getTodaysDate();
    Customer customer(cReader.getNextID(), firstName, lastName, age, username, password, currDate);

    if (cReader.write(customer)) {
        std::cout << "REGISTER_SUCCESS" << std::endl;
        return REGISTER_SUCCESS;                    // Successfully added to customers.csv!
    }

    std::cout << "REGISTER_FAILURE_FILE_ERROR" << std::endl;
    return REGISTER_FAILURE_FILE_ERROR;             // something went wrong with file opening...
}

