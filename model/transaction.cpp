#include "transaction.h"



Transaction::Transaction(int id, int receiverID, int senderID, float amountReceived, float amountSent, Date date, Enums::TransactionType transactionType)
    : CsvModel(id),
      transactionDate(date.getDateString())
{
    this->receiverID = receiverID;
    this->senderID = senderID;
    this->amountReceived = amountReceived;
    this->amountSent = amountSent;
    this->transType = transactionType;
}

Transaction::Transaction(int id, int receiverID, int senderID, float amountReceived, float amountSent, u_int year, u_int month, u_int day, Enums::TransactionType transactionType)
    : CsvModel(id),
      transactionDate(year, month, day)
{
    this->receiverID = receiverID;
    this->senderID = senderID;
    this->amountReceived = amountReceived;
    this->amountSent = amountSent;
    this->transType = transactionType;
}

// Public Functions
vector<string> Transaction::getCsvFormat() const{
    vector<string> csvRow;

    // convert float to string, round 2 dec
    string amtOut = to_string(getAmountSent());
    string amtOutRounded = amtOut.substr(0, amtOut.find(".") + 3);

    string amtIn = to_string(getAmountReceived());
    string amtInRounded = amtIn.substr(0, amtIn.find(".") + 3);


    csvRow.push_back(to_string(getID()));
    csvRow.push_back(getTransactionDate().getDateString());
    csvRow.push_back(to_string(getSenderID()));
    csvRow.push_back(to_string(getReceiverID()));
    csvRow.push_back(amtOutRounded);
    csvRow.push_back(amtInRounded);
    csvRow.push_back(Enums::convertString(getTransactionType()));

    return csvRow;
}

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

Date Transaction::getTransactionDate() const
{
    return transactionDate;
}

int Transaction::getReceiverID() const
{
    return receiverID;
}

int Transaction::getSenderID() const
{
    return senderID;
}

float Transaction::getAmountReceived() const
{
    return amountReceived;
}

float Transaction::getAmountSent() const
{
    return amountSent;
}

Enums::TransactionType Transaction::getTransactionType() const{
    return transType;
}
