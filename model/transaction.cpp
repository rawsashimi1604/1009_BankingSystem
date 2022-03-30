#include "transaction.h"

Transaction::Transaction(int id, int receiverID, int senderID, float amountReceived, float amountSent, Date date, Enums::TransactionType transactionType)
    : transactionDate(date.getDateString())
{
    this->transactionID = id;
    this->receiverID = receiverID;
    this->senderID = senderID;
    this->amountReceived = amountReceived;
    this->amountSent = amountSent;
    this->transType = transactionType;
}

Transaction::Transaction(int id, int receiverID, int senderID, float amountReceived, float amountSent, u_int year, u_int month, u_int day, Enums::TransactionType transactionType)
    : transactionDate(year, month, day)
{
    this->transactionID = id;
    this->receiverID = receiverID;
    this->senderID = senderID;
    this->amountReceived = amountReceived;
    this->amountSent = amountSent;
    this->transType = transactionType;
}

// Public Functions
void Transaction::printInfo() const{

    // Set printing precision to 2 decimal places.
    streamsize ss = UtilityFunctions::setPrintingPrecision();

//    cout << "====================================TRANSACTION HISTORY====================================" << endl;
//    cout << "||   Type  ||    Date    ||    From    ||    To    ||    Amount In    ||    Amount Out   ||" << endl;
    if (transType == Enums::TransactionType::DEPOSIT){
        cout << "DEPOSIT, "; transactionDate.printInfo(); cout << ", " << "nil, " << receiverID << ", $" << amountReceived << ", $" << amountSent << endl;
    }
    else if (transType == Enums::TransactionType::WITHDRAWAL) {
        cout << "WITHDRAWAL, "; transactionDate.printInfo(); cout << ", " << senderID << " nil, " << ", $" << amountReceived << ", $" << amountSent << endl;
    }
    else if (transType == Enums::TransactionType::TRANSFER) {
        cout << "TRANSFER, "; transactionDate.printInfo(); cout << ", " << senderID << ", " << receiverID << ", $" << amountReceived << ", $" << amountSent << endl;
    }
    else {
        cout << "ERROR GETTING TRANSFER." << endl;
    }

    // Reset printing precision.
    UtilityFunctions::removePrintingPrecision(ss);
}

Enums::TransactionType Transaction::getTransactionType() {
    return transType;
}
