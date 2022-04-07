#include "date.h"

// 01/01/2000

Date::Date(std::string dateString) {

    std::string dateStore[3];

    std::string s = dateString;
    std::string delimiter = "/";

    size_t pos = 0;
    std::string token;

    int count = 0;

    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        s.erase(0, pos + delimiter.length());
        dateStore[count] = token;
        count++;
    }

    dateStore[count] = s;

    this->day = stoi(dateStore[0]);
    this->month = stoi(dateStore[1]);
    this->year = stoi(dateStore[2]);
}

Date::Date(u_int year, u_int month, u_int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}

std::string Date::getDateString() {
    std::string s = "";

    s += std::to_string(day);
    s += "/";
    s += std::to_string(month);
    s += "/";
    s += std::to_string(year);

    return s;
}

// Friend functions
std::ostream& operator<<(std::ostream& COUT, const Date& dateObj) {
    COUT << dateObj.day << "/" << dateObj.month << "/" << dateObj.year;
    return COUT;
}
