#include "customer.h"

// Constant Variables
const float Customer::INITIAL_STARTING_BALANCE = 1000.00;

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
    this->balance = INITIAL_STARTING_BALANCE;
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


// Deconstructors
Customer::~Customer() {

}

// Public functions
void Customer::printInfo() const{
    // Set printing precision to 2 decimal places.
    streamsize ss = UtilityFunctions::setPrintingPrecision();

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
    UtilityFunctions::removePrintingPrecision(ss);
}

// Getters
int Customer::getID() const {
    return id;
}

string Customer::getUsername() const{
    return username;
}

string Customer::getPassword() const{
    return password;
}

int Customer::getAge() const {
    return age;
}

string Customer::getFirstName() const {
    return firstName;
}

string Customer::getLastName() const {
    return lastName;
}

string Customer::getFullName() const {
    return firstName + " " + lastName;
}

Date Customer::getDateRegistered() const {
    return dateRegistered;
}

float Customer::getBalance() const {
    return balance;
}

float Customer::getAmountSpent() const {
    return amountSpent;
}

float Customer::getAmountSaved() const {
    return amountSaved;
}
