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
Customer* CredentialsReader::searchByID(int id) {
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
        return NULL;
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

        if (row == id) {
            existFlag = true;
            break;
        }

        row++;  // Update row number
    }

    // If customer exists,
    if (existFlag) {
        // Convert all floats and ints from strings
        int convertedAge = stoi(age);

        float convertedBalance = stof(Bal);
        float convertedAmountSpent = stof(aSpent);
        float convertedAmountSaved = stof(aSaved);

        // Construct Customer Object (pointer)
        Customer* customer = new Customer(id, fName, lName, convertedAge, uName, pNo, dateRegistered, convertedBalance, convertedAmountSpent, convertedAmountSaved);
        cFile.close();

        return customer;
    }

    return NULL;    // Customer dosent exist
}

// Search for customer by Username
Customer* CredentialsReader::searchByUsername(string username) {

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
        return NULL;
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

        // Construct Customer Object (pointer)
        Customer* customer = new Customer(id, fName, lName, convertedAge, uName, pNo, dateRegistered, convertedBalance, convertedAmountSpent, convertedAmountSaved);
        cFile.close();

        return customer;
    }

    return NULL;    // Customer dosent exist
}


void CredentialsReader::write(Customer* customer) {

}
