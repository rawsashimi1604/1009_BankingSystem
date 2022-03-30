#include "transaction.h"

// Enum functions
TransactionType convertTransactionType(string& str) {
    if (str == "DEPOSIT") return TransactionType::DEPOSIT;
    else if (str == "WITHDRAWAL") return TransactionType::WITHDRAWAL;
    else if (str == "TRANSFER") return TransactionType::TRANSFER;

    return TransactionType::NONE;
}

// help to std::cout TransactionType enum.
ostream& operator<<(ostream& COUT, TransactionType t) {
    int enumVal = static_cast<int>(t);
    string str;
    switch(enumVal) {
        case 0:
            str = "DEPOSIT";
            break;
        case 1:
            str = "WITHDRAWAL";
            break;
        case 2:
            str = "TRANSFER";
            break;
        case 3:
            str = "NONE";
            break;
    }

    COUT << str;
    return COUT;
}

Transaction::Transaction(int id, int receiverID, int senderID, float incoming, float outgoing, Date date, TransactionType transactionType)
    : transactionDate(date.getDateString())
{

    this->transactionID = id;
    this->transType = transactionType;
    setTransactionAttributes(receiverID, senderID);     // Helper function help set Customer* and Transaction Types attributes

    this->amountIn = incoming;
    this->amountOut = outgoing;
    this->transType = transactionType;
}

Transaction::Transaction(int id, int receiverID, int senderID, float incoming, float outgoing, u_int year, u_int month, u_int day, TransactionType transactionType)
    : transactionDate(year, month, day)
{
    this->transactionID = id;
    this->transType = transactionType;

    setTransactionAttributes(receiverID, senderID);     // Helper function help set Customer* and Transaction Types attributes attributes

    this->amountIn = incoming;
    this->amountOut = outgoing;
    this->transType = transactionType;
}

Transaction::~Transaction() {
    delete customerReceived;
    delete customerWithdrawn;
}

// Private Functions
void Transaction::setTransactionAttributes(int receiverID, int senderID){

    // If transaction type is DEPOSIT
    if (transType == TransactionType::DEPOSIT) {
        this->customerReceived = cReader.searchByID(receiverID);
        this->customerWithdrawn = NULL;

    }
    // If transaction type is WITHDRAWAL
    else if (transType == TransactionType::WITHDRAWAL) {
        this->customerWithdrawn = cReader.searchByID(senderID);
        this->customerReceived = NULL;
        this->transType = TransactionType::WITHDRAWAL;
    }
    // If transaction type is TRANSFER
    else if (transType == TransactionType::TRANSFER) {
        this->customerReceived = cReader.searchByID(receiverID);
        this->customerWithdrawn = cReader.searchByID(senderID);
        this->transType = TransactionType::TRANSFER;
    }
}


// Public Functions
void Transaction::printInfo() const{



    // Set printing precision to 2 decimal places.
    streamsize ss = UtilityFunctions::setPrintingPrecision();

//    cout << "====================================TRANSACTION HISTORY====================================" << endl;
//    cout << "||   Type  ||    Date    ||    From    ||    To    ||    Amount In    ||    Amount Out   ||" << endl;
    if (transType == TransactionType::DEPOSIT){
        cout << "DEPOSIT, "; transactionDate.printInfo(); cout << ", " << "nil, " << customerReceived->getID() << ", $" << amountIn << ", $" << amountOut << endl;
    }
    else if (transType == TransactionType::WITHDRAWAL) {
        cout << "WITHDRAWAL, "; transactionDate.printInfo(); cout << ", " << customerWithdrawn->getID() << " nil, " << ", $" << amountIn << ", $" << amountOut << endl;
    }
    else if (transType == TransactionType::TRANSFER) {
        cout << "TRANSFER, "; transactionDate.printInfo(); cout << ", " << customerWithdrawn->getID() << ", " <<customerReceived->getID() << ", $" << amountIn << ", $" << amountOut << endl;
    }
    else {
        cout << "ERROR GETTING TRANSFER." << endl;
    }

    // Reset printing precision.
    UtilityFunctions::removePrintingPrecision(ss);
}

TransactionType Transaction::getTransactionType() {
    return transType;
}
