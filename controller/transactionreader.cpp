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

optional<Transaction> TransactionReader::searchByID(int id) {
    bool existFlag = false;

    fstream tFile(fileLocation);

    // If file open failed, return NULL and show error.
    if(!tFile.is_open()) {
        std::cout << "Error opening " << fileLocation << ", returning NULL." << endl;
        return {};
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

        // Construct Transaction Object
        Transaction transaction(id, convertedCustomerIn, convertedCustomerOut, convertedAmountIn, convertedAmountOut, date, transactionType);

        return transaction;
    }

    return {};
}

vector<Transaction> TransactionReader::searchAllTransactions(int customerID) {
    vector<Transaction> res;

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
            Transaction transaction(id, convertedCustomerIn, convertedCustomerOut, convertedAmountIn, convertedAmountOut, date, transactionType);

            res.push_back(transaction);
        }
    }

    return res;
}

// This function writes the userCredential struct to the given fileName's csv file
// returns true if success, false if failed
bool TransactionReader::write(Transaction transaction) {

    ofstream tFile(fileLocation, ios_base::app);

    if (!tFile.is_open()) {
        return false;
    }

    // Add transaction parameters to .csv file
    tFile   << transaction.getID() << ","
            << transaction.getTransactionDate().getDateString() << ","
            << transaction.getSenderID() << ","
            << transaction.getReceiverID() << ","
            << transaction.getAmountSent() << ","
            << transaction.getAmountReceived() << ","
            << Enums::convertString(transaction.getTransactionType()) << endl;

    tFile.close();
    return true;
}

bool TransactionReader::update(Transaction transaction) {

    // Create 1 additional file (diff name)
    // Copy data until reach row to change
    // Update record
    // Delete old file, rename file

    string newFileLocation = "../1009_BankingSystem/data/transactions_tmp.csv";    // to be updated, make more dynamic
    fstream fin, fout;

    fin.open(fileLocation, ios::in);            // Existing file.
    fout.open(newFileLocation, ios::out);       // New file to copy updated data to.

    bool found = false;                         // Denotes whether the Transaction exists in the .csv file.
    vector<string> row;
    string line, word;
    int id = transaction.getID();    // ID of transaction to update.

    // Get new transaction data as a vector
    vector<string> updatedCustomerData = transaction.getCsvFormat();

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



