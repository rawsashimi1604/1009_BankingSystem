#include "date.h"

// 01/01/2000

Date::Date(string dateString) {

    string dateStore[3];

    string s = dateString;
    string delimiter = "/";

    size_t pos = 0;
    string token;

    int count = 0;

    while ((pos = s.find(delimiter)) != string::npos) {
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

void Date::printInfo() {
    cout << day << "/" << month << "/" << year;
}

string Date::getDateString() {
    string s = "";

    s += to_string(day);
    s += "/";
    s += to_string(month);
    s += "/";
    s += year;

    return s;
}
