#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

typedef unsigned int u_int;

class Date
{
private:
    u_int year;
    u_int month;
    u_int day;

public:
    Date(u_int year, u_int month, u_int day);
    void print();
};

#endif // DATE_H
