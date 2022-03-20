#include "customer.h"

// Private functions

streamsize Customer::setPrintingPrecision() {
    streamsize ss = cout.precision();
    cout << fixed;
    cout << setprecision(2);
    return ss;
}

void Customer::removePrintingPrecision(streamsize ss) {
    cout << setprecision(ss);
}


// Constructors

Customer::Customer(string firstName, string lastName, int age, string username, string password, u_int year, u_int month, u_int day)
    : dateRegistered(year, month, day), balance(0)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->age = age;
    this->username = username;
    this->password = password;
}

// Public functions

void Customer::printInfo() {
    // Set printing precision to 2 decimal places.
    streamsize ss = setPrintingPrecision();

    cout << firstName + " " + lastName + ": $" << balance << endl;
    cout << "Date registered: "; dateRegistered.print(); cout << endl;
    cout << "Age: " << age << endl;

    cout << "--Credentials--" << endl;
    cout << "username: " << username << endl;
    cout << "password: " << password << endl;

    // Reset printing precision.
    removePrintingPrecision(ss);
}
