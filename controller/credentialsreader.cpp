#include "credentialsreader.h"

const std::string CredentialsReader::DEFAULT_FILE_LOCATION = "../1009_BankingSystem/data/customers.csv";

/**
 * Constructs CredentialsReader with the DEFAULT_FILE_LOCATION
 *
 * @param None
 *
 */
CredentialsReader::CredentialsReader()
{
    this->fileLocation = DEFAULT_FILE_LOCATION;
}

/**
 * Constructs CredentialsReader with specified file location.
 *
 * @param fileLocation -> PATH of customers.csv file.
 *
 */
CredentialsReader::CredentialsReader(std::string fileLocation)
{
    this->fileLocation = fileLocation;
}

/**
 * Test function.
 *
 * @param None
 * @return None
 */
void CredentialsReader::printHello() {
    std::cout << "hello world from credentials reader!" << std::endl;
}


/**
 * Gets the next ID available for use in the database.
 *
 * @param None
 * @return The next ID available for use in the database.
 */
int CredentialsReader::getNextID() {

    std::fstream cFile(fileLocation);

    if(!cFile.is_open()) {
        std::cout << "Error opening " << fileLocation << ", returning NULL." << std::endl;
        return 0;
    }

    std::string idStr;
    int id = 0;

    std::string column;
    getline(cFile, column);             // Skip column headers

    while(cFile.good()) {
        getline(cFile, idStr, ',');
        getline(cFile, column);

        if (cFile.eof()) {
            break;
        }

        id = stoi(idStr);
    }

    cFile.close();

    return id + 1;                      // Next ID is last ID + 1
}


/**
 * Returns Customer object pointer with the given ID, NULL if not found.
 *
 * @param id -> customer ID to search for.
 * @return Returns Customer object pointer with the given ID, NULL if not found.
 */
std::optional<Customer> CredentialsReader::searchByID(int id) {
    bool existFlag = false;

    std::fstream cFile(fileLocation);

    // If file open failed, return nothing and show error.
    if(!cFile.is_open()) {
        std::cout << "Error opening " << fileLocation << ", returning NULL." << std::endl;
        return {};
    }

    // Skip first line (row columns)
    std::string column;
    getline(cFile, column);

    // Variables to store csv column data
    std::string customerID;
    std::string fName;
    std::string lName;
    std::string age;
    std::string uName;
    std::string pNo;
    std::string dateRegistered;
    std::string Bal;
    std::string aSpent;
    std::string aSaved;


    // Load info from .csv file into Customer object
    while(cFile.good()) {
        getline(cFile, customerID,',');
        getline(cFile, fName,',');
        getline(cFile, lName,',');
        getline(cFile, age,',');
        getline(cFile, uName,',');
        getline(cFile, pNo,',');
        getline(cFile, dateRegistered,',');
        getline(cFile, Bal,',');
        getline(cFile, aSpent,',');
        getline(cFile, aSaved,'\n');

        if (stoi(customerID) == id) {
            existFlag = true;
            break;
        }
    }

    cFile.close();

    // If customer exists,
    if (existFlag) {
        // Convert all floats and ints from strings
        int convertedAge = stoi(age);

        float convertedBalance = stof(Bal);
        float convertedAmountSpent = stof(aSpent);
        float convertedAmountSaved = stof(aSaved);

        // Construct Customer Object, decrypt
        Customer customer(id, fName, lName, convertedAge, uName, pNo, dateRegistered, convertedBalance, convertedAmountSpent, convertedAmountSaved);
        customer = e.decryptCustomer(customer);
        return customer;
    }

    return {};    // Customer dosent exist
}


/**
 * Returns Customer object pointer with the given username, NULL if not found.
 *
 * @param username -> customer username to search for.
 * @return Returns Customer object pointer with the given username, NULL if not found.
 */
std::optional<Customer> CredentialsReader::searchByUsername(std::string username) {

    bool existFlag = false;

    std::fstream cFile(fileLocation);
    int row = 1;                        // track current row.

    // Skip first line (row columns)
    std::string column;
    getline(cFile, column);

    std::string customerID;
    std::string fName;
    std::string lName;
    std::string age;

    std::string uName;
    std::string pNo;

    std::string dateRegistered;

    std::string Bal;
    std::string aSpent;
    std::string aSaved;


    // If file open failed, return NULL and show error.
    if(!cFile.is_open()) {
        std::cout << "Error opening " << fileLocation << ", returning NULL." << std::endl;
        return {};
    }


    // Load info from .csv file into Customer object
    while(cFile.good()) {
        getline(cFile, customerID,',');
        getline(cFile, fName,',');
        getline(cFile, lName,',');
        getline(cFile, age,',');
        getline(cFile, uName,',');
        getline(cFile, pNo,',');
        getline(cFile, dateRegistered,',');
        getline(cFile, Bal,',');
        getline(cFile, aSpent,',');
        getline(cFile, aSaved,'\n');

        // If reached EOF, stop searching
        if (cFile.eof()) {
            break;
        }

        if (e.encryptASCII(username) == uName) {
            existFlag = true;
            break;
        }

        row++;  // Update row number
    }

    cFile.close();

    // If customer exists,
    if (existFlag) {
        // Convert all floats and ints from strings
        int id = stoi(customerID);
        int convertedAge = stoi(age);

        float convertedBalance = stof(Bal);
        float convertedAmountSpent = stof(aSpent);
        float convertedAmountSaved = stof(aSaved);

        // Construct Customer Object, Decrypt
        Customer customer(id, fName, lName, convertedAge, uName, pNo, dateRegistered, convertedBalance, convertedAmountSpent, convertedAmountSaved);
        customer = e.decryptCustomer(customer);



        return customer;
    }

    return {};    // Customer dosent exist
}

/**
 * Returns a vector of all Customers in the database.
 *
 * @param None
 * @return Returns a vector of all Customers in the database.
 */
std::vector<Customer> CredentialsReader::getAllCustomers() {

    std::vector<Customer> result;


    std::fstream cFile(fileLocation);
    int row = 1;                        // track current row.

    // Skip first line (row columns)
    std::string column;
    getline(cFile, column);

    std::string customerID;
    std::string fName;
    std::string lName;
    std::string age;
    std::string uName;
    std::string pNo;
    std::string dateRegistered;
    std::string Bal;
    std::string aSpent;
    std::string aSaved;


    // If file open failed, return NULL and show error.
    if(!cFile.is_open()) {
        std::cout << "Error opening " << fileLocation << ", returning NULL." << std::endl;
        return result;
    }


    // Load info from .csv file into Customer object
    while(cFile.good()) {
        getline(cFile, customerID,',');
        getline(cFile, fName,',');
        getline(cFile, lName,',');
        getline(cFile, age,',');
        getline(cFile, uName,',');
        getline(cFile, pNo,',');
        getline(cFile, dateRegistered,',');
        getline(cFile, Bal,',');
        getline(cFile, aSpent,',');
        getline(cFile, aSaved,'\n');

        // If reached EOF, stop searching
        if (cFile.eof()) {
            break;
        }

        // Convert all floats and ints from strings
        int id = stoi(customerID);
        int convertedAge = stoi(age);

        float convertedBalance = stof(Bal);
        float convertedAmountSpent = stof(aSpent);
        float convertedAmountSaved = stof(aSaved);

        // Construct Customer Object, Decrypt
        Customer customer(id, fName, lName, convertedAge, uName, pNo, dateRegistered, convertedBalance, convertedAmountSpent, convertedAmountSaved);
        customer = e.decryptCustomer(customer);
        result.push_back(customer);

        row++;  // Update row number
    }

    cFile.close();
    return result;
}

/**
 * Appends a Customer to the database.
 *
 * @param customer -> Customer object to append to database.
 * @return Returns true if append was successful, false otherwise.
 */
bool CredentialsReader::write(Customer customer) {

    std::ofstream cFile(fileLocation, std::ios_base::app);
    e.encryptCustomer(customer);                            // Encrypt customer data.

    if (!cFile.is_open()) {
        return false;
    }

    // Add customer parameters to .csv file.
    cFile   << customer.getID() << ","
            << customer.getFirstName() << ","
            << customer.getLastName() << ","
            << customer.getAge() << ","
            << customer.getUsername() << ","
            << customer.getPassword() << ","
            << customer.getDateRegistered().getDateString() << ","
            << customer.getBalance() << ","
            << customer.getAmountSpent() << ","
            << customer.getAmountSaved() << std::endl;

    cFile.close();
    return true;
}


/**
 * Updates a Customer to the database.
 *
 * @param customer -> Customer object to update in database.
 * @return Returns true if update was successful, false otherwise.
 */
bool CredentialsReader::update(Customer customer) {
    // Create 1 additional file (diff name)
    // Copy data until reach row to change
    // Update record
    // Delete old file, rename file

    // Encrypt customer data
    e.encryptCustomerWithoutPassword(customer);


    std::string newFileLocation = "../1009_BankingSystem/data/customers_tmp.csv";    // to be updated, make more dynamic
    std::fstream fin, fout;

    fin.open(fileLocation, std::ios::in);           // Existing file.
    fout.open(newFileLocation, std::ios::out);      // New file to copy updated data to.

    bool found = false;                             // Denotes whether the Customer exists in the .csv file.
    std::vector<std::string> row;
    std::string line, word;
    int id = customer.getID();                      // ID of customer to update.

    // Get new customer data as a vector
    std::vector<std::string> updatedCustomerData = customer.getCsvFormat();

    // Copy column names
    getline(fin, line, '\n');
    fout << line << "\n";

    while(!fin.eof()) {
        row.clear();

        getline(fin, line);
        std::stringstream s(line);

        while(getline(s, word, ',')) {
            row.push_back(word);
        }

        int currID = stoi(row[0]);

        // If found the correct row to replace
        if (currID == id) {
            found = true;

            // Write new data to updated file.
            if (!fin.eof()) {
                size_t i;
                for (i = 0; i < updatedCustomerData.size() - 1; i++) {
                    fout << updatedCustomerData[i] << ",";
                }
                fout << updatedCustomerData[i] << "\n";
            }
        }

        // Else, write existing records to new file
        else {
            if(!fin.eof()) {
                // Write up till before last column
                for (size_t i = 0; i < row.size() - 1; i++) {
                    fout << row[i] << ",";
                }
                fout << row[row.size() - 1] << "\n";
            }

            // Reached EOF, stop adding records
            else {
                break;
            }
        }
    }

    // Close both files
    fin.close();
    fout.close();

    // Remove the old file, and update the tmp file to the old file's file name.
    std::filesystem::remove(fileLocation);
    std::filesystem::rename(newFileLocation, fileLocation);

    // Return true if found and updated, false otherwise
    return found;
}

















