#include "utils.h"

// UtilityFunctions namespace
std::streamsize UtilityFunctions::setPrintingPrecision() {
    std::streamsize ss = std::cout.precision();
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    return ss;
}

void UtilityFunctions::removePrintingPrecision(std::streamsize ss) {
    std::cout << std::setprecision(ss);
}

Date UtilityFunctions::getTodaysDate() {
    u_int year = QDate::currentDate().year();
    u_int month = QDate::currentDate().month();
    u_int day = QDate::currentDate().day();

    return Date(year, month, day);
}

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

// Enums namespace
Enums::TransactionType Enums::convertTransactionType(std::string& str) {
    if (str == "DEPOSIT") return Enums::TransactionType::DEPOSIT;
    else if (str == "WITHDRAWAL") return Enums::TransactionType::WITHDRAWAL;
    else if (str == "TRANSFER") return Enums::TransactionType::TRANSFER;

    return Enums::TransactionType::NONE;
}

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




