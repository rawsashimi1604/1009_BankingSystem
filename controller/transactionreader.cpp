#include "transactionreader.h"

const string TransactionReader::DEFAULT_FILE_LOCATION = "../1009_BankingSystem/data/transactions.csv";

TransactionReader::TransactionReader()
{
    this->fileLocation = DEFAULT_FILE_LOCATION;
}

TransactionReader::TransactionReader(string fileLocation)
{
    this->fileLocation = fileLocation;
}


void TransactionReader::printHello() {
    cout << "hello world from transaction reader!" << endl;
}

Transaction* TransactionReader::searchByID(int id) {
    bool existFlag = false;

    fstream tFile(fileLocation);

    // If file open failed, return NULL and show error.
    if(!tFile.is_open()) {
        std::cout << "Error opening " << fileLocation << ", returning NULL." << endl;
        return NULL;
    }

    // Skip first line
    string column;
    getline(tFile, column);

    // Variables to store csv column data
    string transactionID;
    string transactionDate;
    string customerOut;
    string customerIn;
    string amountOut;
    string amountIn;
    string transType;

    // Load info from .csv file into Transaction object
    while(tFile.good()) {
        getline(tFile, transactionID, ',');
        getline(tFile, transactionDate, ',');
        getline(tFile, customerOut, ',');
        getline(tFile, customerIn, ',');
        getline(tFile, amountOut, ',');
        getline(tFile, amountIn, ',');
        getline(tFile, transType, '\n');

        if (stoi(transactionID) == id) {
            existFlag = true;
            break;
        }
    }

    tFile.close();
    cout << "File closed" << endl;

    // If transaction exists,
    if (existFlag) {

        // Convert all floats and ints from strings
        int convertedCustomerOut = stoi(customerOut);
        int convertedCustomerIn = stoi(customerIn);

        float convertedAmountOut = stof(amountOut);
        float convertedAmountIn = stof(amountIn);

        // Get Date
        Date date(transactionDate);

        // Convert Transaction Type
        Enums::TransactionType transactionType = Enums::convertTransactionType(transType);

        // Construct Transaction Object (pointer)
        Transaction* transaction = new Transaction(id, convertedCustomerIn, convertedCustomerOut, convertedAmountIn, convertedAmountOut, date, transactionType);

        return transaction;
    }

    return NULL;
}

vector<Transaction*> TransactionReader::searchAllTransactions(int customerID) {
    vector<Transaction*> res;

    fstream tFile(fileLocation);

    // If file open failed, return empty vector and show error.
    if(!tFile.is_open()) {
        std::cout << "Error opening " << fileLocation << ", returning NULL." << endl;
        return res;
    }

    // Skip first line
    string column;
    getline(tFile, column);

    // Variables to store csv column data
    string transactionID;
    string transactionDate;
    string customerOut;
    string customerIn;
    string amountOut;
    string amountIn;
    string transType;

    // Load info from .csv file into Transaction object
    while(tFile.good()) {
        getline(tFile, transactionID, ',');
        getline(tFile, transactionDate, ',');
        getline(tFile, customerOut, ',');
        getline(tFile, customerIn, ',');
        getline(tFile, amountOut, ',');
        getline(tFile, amountIn, ',');
        getline(tFile, transType, '\n');

        // If reached EOF, stop searching
        if (tFile.eof()) {
            break;
        }

        // If transaction matches, add Transaction pointer to vector.
        if (stoi(customerIn) == customerID || stoi(customerOut) == customerID) {

            // Convert all floats and ints from strings
            int id = stoi(transactionID);
            int convertedCustomerOut = stoi(customerOut);
            int convertedCustomerIn = stoi(customerIn);

            float convertedAmountOut = stof(amountOut);
            float convertedAmountIn = stof(amountIn);

            // Get Date
            Date date(transactionDate);

            // Convert transaction type to enum
            Enums::TransactionType transactionType = Enums::convertTransactionType(transType);

            // Construct Transaction Object (pointer)
            Transaction* transaction = new Transaction(id, convertedCustomerIn, convertedCustomerOut, convertedAmountIn, convertedAmountOut, date, transactionType);

            res.push_back(transaction);
        }
    }

    return res;
}

// This function writes the userCredential struct to the given fileName's csv file
// returns true if success, false if failed
bool TransactionReader::write(Transaction* transaction) {

    ofstream tFile(fileLocation, ios_base::app);

    if (!tFile.is_open()) {
        return false;
    }

    // Add transaction parameters to .csv file
    tFile   << transaction->getTransactionID() << ","
            << transaction->getTransactionDate().getDateString() << ","
            << transaction->getSenderID() << ","
            << transaction->getReceiverID() << ","
            << transaction->getAmountSent() << ","
            << transaction->getAmountReceived() << ","
            << Enums::convertString(transaction->getTransactionType()) << endl;

    tFile.close();
    return true;
}



