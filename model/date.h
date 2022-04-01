#ifndef DATE_H
#define DATE_H

#include <iostream>

#include "csvmodel.h"


using namespace std;

typedef unsigned u_int;

class Date
{
private:
    u_int year;
    u_int month;
    u_int day;

public:
    Date(string dateString);
    Date(u_int year, u_int month, u_int day);

    void printInfo() const;
    string getDateString();
};

#endif // DATE_H
