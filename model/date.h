#ifndef DATE_H
#define DATE_H

#include <iostream>

#include "model.h"


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
    void printInfo();
    string getDateString();
};

#endif // DATE_H
