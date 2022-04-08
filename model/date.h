#ifndef DATE_H
#define DATE_H

#include <iostream>

#include "csvmodel.h"

/**
 * A Date object contains data information about a Date.
 * It contains methods and attributes to ease converting between strings and integers for dates.
 * And generalizes how we represent dates in the code base.
 */

typedef unsigned u_int;                                                     // Define unsigned int as u_int;

class Date
{

    // Friend classes / functions
    friend std::ostream& operator<<(std::ostream&, const Date& dateObj);

private:
    u_int year;                                                             // Year
    u_int month;                                                            // Month
    u_int day;                                                              // Day

public:
    Date(std::string dateString);                                           // Construct Date object with date String "dd/mm/yyyy"
    Date(u_int year, u_int month, u_int day);                               // Construct Date object with integer values.

    std::string getDateString();                                            // Get the String representation of the date.
};

std::ostream& operator<<(std::ostream&, const Date& dateObj);               // Overloads insertion operator for Date object

#endif // DATE_H
