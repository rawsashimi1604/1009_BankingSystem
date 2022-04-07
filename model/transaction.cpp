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
std::vector<std::string> Transaction::getCsvFormat() const{
    std::vector<std::string> csvRow;

    // convert float to string, round 2 dec
    std::string amtOut = std::to_string(getAmountSent());
    std::string amtOutRounded = amtOut.substr(0, amtOut.find(".") + 3);

    std::string amtIn = std::to_string(getAmountReceived());
    std::string amtInRounded = amtIn.substr(0, amtIn.find(".") + 3);


    csvRow.push_back(std::to_string(getID()));
    csvRow.push_back(getTransactionDate().getDateString());
    csvRow.push_back(std::to_string(getSenderID()));
    csvRow.push_back(std::to_string(getReceiverID()));
    csvRow.push_back(amtOutRounded);
    csvRow.push_back(amtInRounded);
    csvRow.push_back(Enums::convertString(getTransactionType()));

    return csvRow;
}

void Transaction::printInfo() const{

    // Set printing precision to 2 decimal places.
    std::streamsize ss = UtilityFunctions::setPrintingPrecision();

    if (transType == Enums::TransactionType::DEPOSIT){
        std::cout << "DEPOSIT, ";
        std::cout << transactionDate;
        std::cout << ", " << "nil, " << receiverID << ", $" << amountReceived << ", $" << amountSent << std::endl;
    }
    else if (transType == Enums::TransactionType::WITHDRAWAL) {
        std::cout << "WITHDRAWAL, ";
        std::cout << transactionDate;
        std::cout << ", " << senderID << " nil, " << ", $" << amountReceived << ", $" << amountSent << std::endl;
    }
    else if (transType == Enums::TransactionType::TRANSFER) {
        std::cout << "TRANSFER, ";
        std::cout << transactionDate;
        std::cout << ", " << senderID << ", " << receiverID << ", $" << amountReceived << ", $" << amountSent << std::endl;
    }
    else {
        std::cout << "ERROR GETTING TRANSFER." << std::endl;
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

std::ostream& operator<<(std::ostream& COUT, Transaction transactionObj) {
    // Set printing precision to 2 decimal places.
    std::streamsize ss = UtilityFunctions::setPrintingPrecision();

    if (transactionObj.transType == Enums::TransactionType::DEPOSIT){
        COUT << "DEPOSIT, " <<
        transactionObj.transactionDate <<
        ", " << "nil, " <<
        transactionObj.receiverID <<
        ", $" << transactionObj.amountReceived <<
        ", $" << transactionObj.amountSent << std::endl;
    }

    else if (transactionObj.transType == Enums::TransactionType::WITHDRAWAL) {
        COUT << "WITHDRAWAL, " <<
        transactionObj.transactionDate <<
        ", " << transactionObj.senderID <<
        " nil, " <<
        ", $" << transactionObj.amountReceived <<
        ", $" << transactionObj.amountSent << std::endl;
    }
    else if (transactionObj.transType == Enums::TransactionType::TRANSFER) {
        COUT << "TRANSFER, " <<
        transactionObj.transactionDate <<
        ", " << transactionObj.senderID <<
        ", " << transactionObj.receiverID <<
        ", $" << transactionObj.amountReceived <<
        ", $" << transactionObj.amountSent << std::endl;
    }
    else {
        COUT << "ERROR GETTING TRANSFER." << std::endl;
    }

    // Reset printing precision.
    UtilityFunctions::removePrintingPrecision(ss);

    return COUT;
}
