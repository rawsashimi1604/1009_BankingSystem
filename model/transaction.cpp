#include "transaction.h"

Transaction::Transaction(int id, int receiverID, int senderID, float incoming, float outgoing, Date date)
    : transactionDate(date.getDateString())
{
    this->transactionID = id;

    setTransactionAttributes(receiverID, senderID);     // Helper function help set Customer* and Transaction Types attributes

    this->amountIn = incoming;
    this->amountOut = outgoing;
}

Transaction::Transaction(int id, int receiverID, int senderID, float incoming, float outgoing, u_int year, u_int month, u_int day)
    : transactionDate(year, month, day)
{
    this->transactionID = id;

    setTransactionAttributes(receiverID, senderID);     // Helper function help set Customer* and Transaction Types attributes attributes

    this->amountIn = incoming;
    this->amountOut = outgoing;
}

Transaction::~Transaction() {
    delete customerReceived;
    delete customerWithdrawn;
}

// Private Functions
void Transaction::setTransactionAttributes(int receiverID, int senderID){

    // If transaction type is DEPOSIT
    if (receiverID != -1) {
        this->customerReceived = cReader.searchByID(receiverID);
        this->customerWithdrawn = NULL;
        this->transType = DEPOSIT;
    }
    // If transaction type is WITHDRAWAL
    else if (senderID != -1) {
        this->customerWithdrawn = cReader.searchByID(senderID);
        this->customerReceived = NULL;
        this->transType = WITHDRAWAL;
    }
    // If transaction type is TRANSFER
    else {
        this->customerReceived = cReader.searchByID(receiverID);
        this->customerWithdrawn = cReader.searchByID(senderID);
        this->transType = TRANSFER;
    }
}


// Public Functions
void Transaction::printInfo() const{

    // Set printing precision to 2 decimal places.
    streamsize ss = UtilityFunctions::setPrintingPrecision();

    cout << "====================================TRANSACTION HISTORY====================================" << endl;
    cout << "||   Type  ||    Date    ||    From    ||    To    ||    Amount In    ||    Amount Out   ||" << endl;
    if (transType == DEPOSIT){
        cout << "DEPOSIT, "; transactionDate.printInfo(); cout << ", " << "nil, " << customerReceived->getID() << ", $" << amountIn << ", $" << amountOut << endl;
    }
    else if (transType == WITHDRAWAL) {
        cout << "WITHDRAWAL, "; transactionDate.printInfo(); cout << ", " << customerWithdrawn->getID() << " nil, " << ", $" << amountIn << ", $" << amountOut << endl;
    }
    else if (transType == TRANSFER) {
        cout << "TRANSFER, "; transactionDate.printInfo(); cout << ", " << customerWithdrawn->getID() << customerReceived->getID() << ", $" << amountIn << ", $" << amountOut << endl;
        cout << "TRANSFER, "; transactionDate.printInfo(); cout << ", " << customerReceived->getID() << customerWithdrawn->getID() << ", $" << amountOut << ", $" << amountIn << endl;
    }

    // Reset printing precision.
    UtilityFunctions::removePrintingPrecision(ss);
}
