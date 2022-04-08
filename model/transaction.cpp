#include "transaction.h"

/**
 * Construct Transaction Object with Date object
 *
 * @param id -> Customer ID
 * @param receiverID -> Customer who receives $ (id)
 * @param senderID -> Customer who sends $ (id)
 * @param amountReceived -> Total amount received
 * @param amountSent -> Total amount sent
 * @param date -> Date object representing date of transaction
 * @param transactionType -> Defines which transaction type
 *
 */
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

/**
 * Construct Transaction Object with Date object
 *
 * @param id -> Customer ID
 * @param receiverID -> Customer who receives $ (id)
 * @param senderID -> Customer who sends $ (id)
 * @param amountReceived -> Total amount received
 * @param amountSent -> Total amount sent
 * @param year -> year of transaction
 * @param month -> month of transaction
 * @param day -> day of transaction
 * @param transactionType -> Defines which transaction type
 *
 */
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

/**
 * Gets Transaction data from database as a vector of strings.
 *
 * @param None
 * @return Vector of Transaction object csv model in string format
 */
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

/**
 * Returns Transaction date
 *
 * @param None
 * @return Returns Transaction date
 */
Date Transaction::getTransactionDate() const
{
    return transactionDate;
}

/**
 * Returns Customer who receives $ (id)
 *
 * @param None
 * @return Returns Customer who receives $ (id)
 */
int Transaction::getReceiverID() const
{
    return receiverID;
}

/**
 * Returns Customer who sends $ (id)
 *
 * @param None
 * @return Returns Customer who sends $ (id)
 */
int Transaction::getSenderID() const
{
    return senderID;
}

/**
 * Returns total amount received
 *
 * @param None
 * @return Returns total amount received
 */
float Transaction::getAmountReceived() const
{
    return amountReceived;
}

/**
 * Returns total amount sent
 *
 * @param None
 * @return Returns total amount sent
 */
float Transaction::getAmountSent() const
{
    return amountSent;
}

/**
 * Returns Transaction Type (based on TransationType Enum)
 *
 * @param None
 * @return Returns Transaction Type (based on TransationType Enum)
 */
Enums::TransactionType Transaction::getTransactionType() const{
    return transType;
}

/**
 * Prints all information about transaction object to specified ostream.
 *
 * @param COUT -> ostream object to overload (std::cout)
 * @param transactionObj -> date to output.
 * @return Returns ostream object
 */
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
