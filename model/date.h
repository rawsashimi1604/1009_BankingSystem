#ifndef DATE_H
#define DATE_H

#include <iostream>

#include "csvmodel.h"
#include "model.h"

typedef unsigned u_int;

class Date : public Model
{
private:
    u_int year;
    u_int month;
    u_int day;

public:
    Date(std::string dateString);
    Date(u_int year, u_int month, u_int day);

    void printInfo() const;
    std::string getDateString();
};

#endif // DATE_H
