#include "customer.h"

// Constant Variables
const float Customer::INITIAL_STARTING_BALANCE = 1000.00;

// Constructors


Customer::Customer(int id, std::string firstName, std::string lastName, int age, std::string username, std::string password, u_int year, u_int month, u_int day)
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

Customer::Customer(int id, std::string firstName, std::string lastName, int age, std::string username, std::string password, Date date)
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

Customer::Customer(int id, std::string firstName, std::string lastName, int age, std::string username, std::string password, std::string dateString, float balance, float amountSpent, float amountSaved)
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
std::vector<std::string> Customer::getCsvFormat() const{
    std::vector<std::string> csvRow;

    // convert float to string, round 2 dec
    std::string balance = std::to_string(getBalance());
    std::string balanceRounded = balance.substr(0, balance.find(".") + 3);

    std::string amtSaved = std::to_string(getAmountSaved());
    std::string amtSavedRounded = amtSaved.substr(0, amtSaved.find(".") + 3);

    std::string amtSpent = std::to_string(getAmountSpent());
    std::string amtSpentRounded = amtSpent.substr(0, amtSpent.find(".") + 3);

    csvRow.push_back(std::to_string(getID()));
    csvRow.push_back(getFirstName());
    csvRow.push_back(getLastName());
    csvRow.push_back(std::to_string(getAge()));
    csvRow.push_back(getUsername());
    csvRow.push_back(getPassword());
    csvRow.push_back(getDateRegistered().getDateString());
    csvRow.push_back(balanceRounded);
    csvRow.push_back(amtSpentRounded);
    csvRow.push_back(amtSavedRounded);

    return csvRow;
}

// Getters
std::string Customer::getUsername() const{
    return username;
}

std::string Customer::getPassword() const{
    return password;
}

int Customer::getAge() const {
    return age;
}

std::string Customer::getFirstName() const {
    return firstName;
}

std::string Customer::getLastName() const {
    return lastName;
}

std::string Customer::getFullName() const {
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

// Operator overloading
std::ostream& operator<<(std::ostream& COUT, Customer& customerObj) {
    // Set printing precision to 2 decimal places.
    std::streamsize ss = UtilityFunctions::setPrintingPrecision();

    COUT    <<"---Customer Information---" << std::endl
            << customerObj.firstName + " " + customerObj.lastName + ": $" << customerObj.balance << std::endl
            << "Date registered: " << customerObj.dateRegistered << std::endl
            << "Age: " << customerObj.age << std::endl

            << "--Credentials--" << std::endl
            << "username: " << customerObj.username << std::endl
            << "password: " << customerObj.password << std::endl

            << "--Statistics--" << std::endl
            << "Amount saved: $" << customerObj.amountSaved << std::endl
            << "Amount spent: $" << customerObj.amountSpent << std::endl;

    // Reset printing precision.
    UtilityFunctions::removePrintingPrecision(ss);

    return COUT;
}


