#include "credentialsreader.h"

const string CredentialsReader::DEFAULT_FILE_LOCATION = "../1009_BankingSystem/data/customers.csv";

CredentialsReader::CredentialsReader()
{
    this->fileLocation = DEFAULT_FILE_LOCATION;
}

CredentialsReader::CredentialsReader(string fileLocation)
{
    this->fileLocation = fileLocation;
}

void CredentialsReader::printHello() {
    cout << "hello world from credentials reader!" << endl;
}

// Search for customer by ID
optional<Customer> CredentialsReader::searchByID(int id) {
    bool existFlag = false;

    fstream cFile(fileLocation);

    // If file open failed, return nothing and show error.
    if(!cFile.is_open()) {
        std::cout << "Error opening " << fileLocation << ", returning NULL." << endl;
        return {};
    }

    // Skip first line (row columns)
    string column;
    getline(cFile, column);

    // Variables to store csv column data
    string customerID;
    string fName;
    string lName;
    string age;
    string uName;
    string pNo;
    string dateRegistered;
    string Bal;
    string aSpent;
    string aSaved;


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

        // Construct Customer Object
        Customer customer(id, fName, lName, convertedAge, uName, pNo, dateRegistered, convertedBalance, convertedAmountSpent, convertedAmountSaved);
        return customer;
    }

    return {};    // Customer dosent exist
}

// Search for customer by Username
optional<Customer> CredentialsReader::searchByUsername(string username) {

    bool existFlag = false;

    fstream cFile(fileLocation);
    int row = 1;                        // track current row.

    // Skip first line (row columns)
    string column;
    getline(cFile, column);

    string customerID;
    string fName;
    string lName;
    string age;

    string uName;
    string pNo;

    string dateRegistered;

    string Bal;
    string aSpent;
    string aSaved;


    // If file open failed, return NULL and show error.
    if(!cFile.is_open()) {
        std::cout << "Error opening " << fileLocation << ", returning NULL." << endl;
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

        if (username == uName) {
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

        // Construct Customer Object
        Customer customer(id, fName, lName, convertedAge, uName, pNo, dateRegistered, convertedBalance, convertedAmountSpent, convertedAmountSaved);
        cFile.close();

        return customer;
    }

    return {};    // Customer dosent exist
}

// This function writes the userCredential struct to the given fileName's csv file
// returns true if success, false if failed
bool CredentialsReader::write(Customer customer) {

    ofstream cFile(fileLocation, ios_base::app);

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
            << customer.getAmountSaved() << endl;

    cFile.close();
    return true;
}


// Update customer.csv based on inputted customer's ID.
bool CredentialsReader::update(Customer customer) {
    // Create 1 additional file (diff name)
    // Copy data until reach row to change
    // Update record
    // Delete old file, rename file

    string newFileLocation = "../1009_BankingSystem/data/customers_tmp.csv";    // to be updated, make more dynamic
    fstream fin, fout;

    fin.open(fileLocation, ios::in);            // Existing file.
    fout.open(newFileLocation, ios::out);       // New file to copy updated data to.

    bool found = false;                         // Denotes whether the Customer exists in the .csv file.
    vector<string> row;
    string line, word;
    int id = customer.getID();                  // ID of customer to update.

    // Get new customer data as a vector
    vector<string> updatedCustomerData = customer.getCsvFormat();

//    // Check data is correct
//    for (size_t i = 0; i < updatedCustomerData.size(); i++) {
//        cout << updatedCustomerData[i] << " ";
//    }
//    cout << endl;

    // Copy column names
    getline(fin, line, '\n');
    fout << line << "\n";

    while(!fin.eof()) {
        row.clear();

        getline(fin, line);
        stringstream s(line);

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
    filesystem::remove(fileLocation);
    filesystem::rename(newFileLocation, fileLocation);

    // Return true if found and updated, false otherwise
    return found;
}

















