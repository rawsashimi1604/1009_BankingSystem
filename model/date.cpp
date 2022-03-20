#include "date.h"

Date::Date(u_int year, u_int month, u_int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}

void Date::print() {
    cout << day << "/" << month << "/" << year;
}
