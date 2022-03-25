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
Customer::Customer(int id, string firstName, string lastName, int age, string username, string password, u_int year, u_int month, u_int day)
    : dateRegistered(year, month, day),
      balance(0),
      amountSpent(0),
      amountSaved(0)
{
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
    this->age = age;
    this->username = username;
    this->password = password;
}

Customer::Customer(int id, string firstName, string lastName, int age, string username, string password, string dateString, float balance, float amountSpent, float amountSaved)
    : dateRegistered(dateString)
{
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
    this->age = age;
    this->username = username;
    this->password = password;

    this->balance = balance;
    this->amountSpent = amountSpent;
    this->amountSaved = amountSaved;
}



// Public functions
void Customer::printInfo() {
    // Set printing precision to 2 decimal places.
    streamsize ss = setPrintingPrecision();

    cout << firstName + " " + lastName + ": $" << balance << endl;
    cout << "Date registered: "; dateRegistered.printInfo(); cout << endl;
    cout << "Age: " << age << endl;

    cout << "--Credentials--" << endl;
    cout << "username: " << username << endl;
    cout << "password: " << password << endl;

    cout << "--Statistics--" << endl;
    cout << "Amount saved: $" << amountSaved << endl;
    cout << "Amount spent: $" << amountSpent << endl;

    // Reset printing precision.
    removePrintingPrecision(ss);
}

string Customer::getUsername() {
    return username;
}

string Customer::getPassword() {
    return password;
}
