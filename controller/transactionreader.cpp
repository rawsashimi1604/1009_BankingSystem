#include "transactionreader.h"

const std::string TransactionReader::DEFAULT_FILE_LOCATION = "../1009_BankingSystem/data/transactions.csv";

TransactionReader::TransactionReader()
{
    this->fileLocation = DEFAULT_FILE_LOCATION;
}

TransactionReader::TransactionReader(std::string fileLocation)
{
    this->fileLocation = fileLocation;
}


void TransactionReader::printHello() {
    std::cout << "hello world from transaction reader!" << std::endl;
}

// Get the next ID to add.
int TransactionReader::getNextID() {

    std::fstream tFile(fileLocation);

    if(!tFile.is_open()) {
        std::cout << "Error opening " << fileLocation << ", returning NULL." << std::endl;
        return 0;
    }

    std::string idStr;
    int id;

    std::string column;
    getline(tFile, column);             // Skip column headers

    while(tFile.good()) {
        getline(tFile, idStr, ',');
        getline(tFile, column);

        if (tFile.eof()) {
            break;
        }

        id = stoi(idStr);
    }

    tFile.close();

    return id + 1;                      // Next ID is last ID + 1
}

std::optional<Transaction> TransactionReader::searchByID(int id) {
    bool existFlag = false;

    std::fstream tFile(fileLocation);

    // If file open failed, return NULL and show error.
    if(!tFile.is_open()) {
        std::cout << "Error opening " << fileLocation << ", returning NULL." << std::endl;
        return {};
    }

    // Skip first line
    std::string column;
    getline(tFile, column);

    // Variables to store csv column data
    std::string transactionID;
    std::string transactionDate;
    std::string customerOut;
    std::string customerIn;
    std::string amountOut;
    std::string amountIn;
    std::string transType;

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
    std::cout << "File closed" << std::endl;

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

std::vector<Transaction> TransactionReader::searchAllTransactions(int customerID) {
    std::vector<Transaction> res;

    std::fstream tFile(fileLocation);

    // If file open failed, return empty vector and show error.
    if(!tFile.is_open()) {
        std::cout << "Error opening " << fileLocation << ", returning NULL." << std::endl;
        return res;
    }

    // Skip first line
    std::string column;
    getline(tFile, column);

    // Variables to store csv column data
    std::string transactionID;
    std::string transactionDate;
    std::string customerOut;
    std::string customerIn;
    std::string amountOut;
    std::string amountIn;
    std::string transType;

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

    std::ofstream tFile(fileLocation, std::ios_base::app);

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
            << Enums::convertString(transaction.getTransactionType()) << std::endl;

    tFile.close();
    return true;
}

bool TransactionReader::update(Transaction transaction) {

    // Create 1 additional file (diff name)
    // Copy data until reach row to change
    // Update record
    // Delete old file, rename file

    std::string newFileLocation = "../1009_BankingSystem/data/transactions_tmp.csv";    // to be updated, make more dynamic
    std::fstream fin, fout;

    fin.open(fileLocation, std::ios::in);            // Existing file.
    fout.open(newFileLocation, std::ios::out);       // New file to copy updated data to.

    bool found = false;                         // Denotes whether the Transaction exists in the .csv file.
    std::vector<std::string> row;
    std::string line, word;
    int id = transaction.getID();    // ID of transaction to update.

    // Get new transaction data as a vector
    std::vector<std::string> updatedCustomerData = transaction.getCsvFormat();

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



