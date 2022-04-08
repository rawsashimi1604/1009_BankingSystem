#include "utils.h"

/**
 * Sets printing precision to 2 decimal places.
 *
 * @param None
 * @return std::streamsize object
 */
std::streamsize UtilityFunctions::setPrintingPrecision() {
    std::streamsize ss = std::cout.precision();
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    return ss;
}

/**
 * Removes printing precision.
 *
 * @param std::streamsize object
 * @return None
 */
void UtilityFunctions::removePrintingPrecision(std::streamsize ss) {
    std::cout << std::setprecision(ss);
}

/**
 * Gets today's date according to system time.
 *
 * @param None
 * @return Today's Date in a Date object
 */
Date UtilityFunctions::getTodaysDate() {
    u_int year = QDate::currentDate().year();
    u_int month = QDate::currentDate().month();
    u_int day = QDate::currentDate().day();

    return Date(year, month, day);
}

/**
 * Check for numeric string for Qstring
 *
 * @param s -> QString object to check whether it is a digit
 * @return Returns 1 if numeric, 0 if not numeric
 */
int UtilityFunctions::checkNumeric(QString s){
    if (s.size()> 0){
        for (int i =0;i<s.size();i++)
        {
            if(!s[i].isDigit()) // to check if it is alphabet !!
                return 1;
        }
    }
    return 0;
}

/**
 * Converts string -> TransactionType
 *
 * @param str -> string to be converted
 * @return Returns converted string as TransactionType
 */
Enums::TransactionType Enums::convertTransactionType(std::string& str) {
    if (str == "DEPOSIT") return Enums::TransactionType::DEPOSIT;
    else if (str == "WITHDRAWAL") return Enums::TransactionType::WITHDRAWAL;
    else if (str == "TRANSFER") return Enums::TransactionType::TRANSFER;

    return Enums::TransactionType::NONE;
}

/**
 * Converts TransactionType -> string
 *
 * @param TransactionType -> TransactionType to be converted
 * @return Returns converted TransactionType as string
 */
std::string Enums::convertString(Enums::TransactionType transType) {

    switch(transType) {
        case Enums::TransactionType::DEPOSIT:
            return "DEPOSIT";
        case Enums::TransactionType::WITHDRAWAL:
            return "WITHDRAWAL";
        case Enums::TransactionType::TRANSFER:
            return "TRANSFER";
        case Enums::TransactionType::NONE:
            return "NONE";
    }
    return "NONE";
}

/**
 * Prints all information about TransactionType object to specified ostream.
 *
 * @param COUT -> ostream object to overload (std::cout)
 * @param t -> TransactionType to output.
 * @return Returns ostream object
 */
std::ostream& Enums::operator<<(std::ostream& COUT, Enums::TransactionType t) {
    int enumVal = static_cast<int>(t);
    std::string str;
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






