#include "credentialsreader.h"

const std::string CredentialsReader::DEFAULT_FILE_LOCATION = "../1009_BankingSystem/data/customers.csv";

CredentialsReader::CredentialsReader()
{
    this->fileLocation = DEFAULT_FILE_LOCATION;
}

CredentialsReader::CredentialsReader(std::string fileLocation)
{
    this->fileLocation = fileLocation;
}

void CredentialsReader::printHello() {
    std::cout << "hello world from credentials reader!" << std::endl;
}

// Get the next ID to add.
int CredentialsReader::getNextID() {

    std::fstream cFile(fileLocation);

    if(!cFile.is_open()) {
        std::cout << "Error opening " << fileLocation << ", returning NULL." << std::endl;
        return 0;
    }

    std::string idStr;
    int id;

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

// Search for customer by ID
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
        Encrypter e;
        customer = e.decryptCustomer(customer);
        return customer;
    }

    return {};    // Customer dosent exist
}

// Search for customer by Username
std::optional<Customer> CredentialsReader::searchByUsername(std::string username) {

    Encrypter e;                        // Encrypts ASCII (security)
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

        cFile.close();

        return customer;
    }

    return {};    // Customer dosent exist
}

// This function writes Customer information (encrypted) into ./data/customers.csv
// returns true if success, false if failed
bool CredentialsReader::write(Customer customer) {

    std::ofstream cFile(fileLocation, std::ios_base::app);
    Encrypter e;                            // Used to encrypt ASCII characters for security (customers.csv)
    e.encryptCustomer(customer);            // Encrypt customer data.

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


// Update customer.csv based on inputted customer's ID.
bool CredentialsReader::update(Customer customer) {
    // Create 1 additional file (diff name)
    // Copy data until reach row to change
    // Update record
    // Delete old file, rename file

    // Encrypt customer data
    Encrypter e;
    e.encryptCustomer(customer);


    std::string newFileLocation = "../1009_BankingSystem/data/customers_tmp.csv";    // to be updated, make more dynamic
    std::fstream fin, fout;

    fin.open(fileLocation, std::ios::in);            // Existing file.
    fout.open(newFileLocation, std::ios::out);       // New file to copy updated data to.

    bool found = false;                         // Denotes whether the Customer exists in the .csv file.
    std::vector<std::string> row;
    std::string line, word;
    int id = customer.getID();                  // ID of customer to update.

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

















