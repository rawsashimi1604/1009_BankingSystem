#ifndef DATE_H
#define DATE_H

#include <iostream>

#include "csvmodel.h"

typedef unsigned u_int;

class Date
{

    // Friend classes / functions
    friend std::ostream& operator<<(std::ostream&, const Date& dateObj);

private:
    u_int year;
    u_int month;
    u_int day;

public:
    Date(std::string dateString);
    Date(u_int year, u_int month, u_int day);

    std::string getDateString();
};

std::ostream& operator<<(std::ostream&, const Date& dateObj);

#endif // DATE_H
