#include "date.h"


/**
 * Construct Date object with date String "dd/mm/yyyy"
 *
 * @param dateString -> string in the format "dd/mm/yyyy"
 *
 */
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

/**
 * Construct Date object with integer values.
 *
 * @param year -> current Year
 * @param month -> current Month
 * @param day -> current Day
 *
 */
Date::Date(u_int year, u_int month, u_int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}

/**
 * Get the String representation of the date.
 *
 * @param None
 * @return Returns the String representation of the date.
 */
std::string Date::getDateString() {
    std::string s = "";

    s += std::to_string(day);
    s += "/";
    s += std::to_string(month);
    s += "/";
    s += std::to_string(year);

    return s;
}

/**
 * Prints all information about date object to specified ostream.
 *
 * @param COUT -> ostream object to overload (std::cout)
 * @param dateObj -> date to output.
 * @return Returns ostream object
 */
std::ostream& operator<<(std::ostream& COUT, const Date& dateObj) {
    COUT << dateObj.day << "/" << dateObj.month << "/" << dateObj.year;
    return COUT;
}
