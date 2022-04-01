#include "customer.h"

// Constant Variables
const float Customer::INITIAL_STARTING_BALANCE = 1000.00;

// Constructors


Customer::Customer(int id, string firstName, string lastName, int age, string username, string password, u_int year, u_int month, u_int day)
    : CsvModel(id),
      dateRegistered(year, month, day),
      amountSpent(0),
      amountSaved(0)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->age = age;
    this->username = username;
    this->password = password;
    this->balance = INITIAL_STARTING_BALANCE;
}

Customer::Customer(int id, string firstName, string lastName, int age, string username, string password, Date date)
    : CsvModel(id),
      dateRegistered(date.getDateString()),
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
    : CsvModel(id),
      dateRegistered(dateString)
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
vector<string> Customer::getCsvFormat() const{
    vector<string> csvRow;

    // convert float to string, round 2 dec
    string balance = to_string(getBalance());
    string balanceRounded = balance.substr(0, balance.find(".") + 3);

    string amtSaved = to_string(getAmountSaved());
    string amtSavedRounded = amtSaved.substr(0, amtSaved.find(".") + 3);

    string amtSpent = to_string(getAmountSpent());
    string amtSpentRounded = amtSpent.substr(0, amtSpent.find(".") + 3);

    csvRow.push_back(to_string(getID()));
    csvRow.push_back(getFirstName());
    csvRow.push_back(getLastName());
    csvRow.push_back(to_string(getAge()));
    csvRow.push_back(getUsername());
    csvRow.push_back(getPassword());
    csvRow.push_back(getDateRegistered().getDateString());
    csvRow.push_back(balanceRounded);
    csvRow.push_back(amtSpentRounded);
    csvRow.push_back(amtSavedRounded);

    return csvRow;
}

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

// Setters
void Customer::setBalance(float newBalance)
{
    balance = newBalance;
}

void Customer::setAmountSaved(float newAmountSaved)
{
    amountSaved = newAmountSaved;
}

void Customer::setAmountSpent(float newAmountSpent)
{
    amountSpent = newAmountSpent;
}


