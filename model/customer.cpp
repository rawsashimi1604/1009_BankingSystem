#include "customer.h"

// Constant Variables
const float Customer::INITIAL_STARTING_BALANCE = 1000.00;


/**
 * Constructs Customer object using date values
 *
 * @param id -> Customer ID
 * @param firstName -> Customer first name
 * @param lastName -> Customer last name
 * @param age -> Customer age
 * @param username -> Customer username
 * @param password -> Customer password
 * @param year -> Today's Year
 * @param month -> Today's Month
 * @param day -> Today's Day
 *
 */
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

/**
 * Constructs customer object using Date object
 *
 * @param id -> Customer ID
 * @param firstName -> Customer first name
 * @param lastName -> Customer last name
 * @param age -> Customer age
 * @param username -> Customer username
 * @param password -> Customer password
 * @param Date -> Date object containing today's date.
 *
 */
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

/**
 * Constructs customer object using date string and customized balanced, amountSpent and amountSaved.
 *
 * @param id -> Customer ID
 * @param firstName -> Customer first name
 * @param lastName -> Customer last name
 * @param age -> Customer age
 * @param username -> Customer username
 * @param password -> Customer password
 * @param dateString -> date representing as a string (dd/mm/yyyy)
 * @param balance -> How much money to initialize Customer with
 * @param amountSpent -> How much money to initialize Customer with (spendings)
 * @param amountSaved -> How much money to initialize Customer with (savings)
 *
 */
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

/**
 * Desconstructs Customer object
 *
 * @param None
 *
 */
Customer::~Customer() {

}


/**
 * Gets Customer data from database as a vector of strings.
 *
 * @param None
 * @return Vector of customer object csv model in string format
 */
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


/**
 * Returns Customer's username
 *
 * @param None
 * @return Returns Customer's username
 */
std::string Customer::getUsername() const{
    return username;
}

/**
 * Returns Customer's password
 *
 * @param None
 * @return Returns Customer's password
 */
std::string Customer::getPassword() const{
    return password;
}

/**
 * Returns Customer's age
 *
 * @param None
 * @return Returns Customer's age
 */
int Customer::getAge() const {
    return age;
}

/**
 * Returns Customer's first name
 *
 * @param None
 * @return Returns Customer's first name
 */
std::string Customer::getFirstName() const {
    return firstName;
}

/**
 * Returns Customer's last name
 *
 * @param None
 * @return Returns Customer's last name
 */
std::string Customer::getLastName() const {
    return lastName;
}

/**
 * Returns Customer's full name
 *
 * @param None
 * @return Returns Customer's full name
 */
std::string Customer::getFullName() const {
    return firstName + " " + lastName;
}


/**
 * Returns Customer's date registered
 *
 * @param None
 * @return Returns Customer's date registered
 */
Date Customer::getDateRegistered() const {
    return dateRegistered;
}

/**
 * Returns Customer's current balance
 *
 * @param None
 * @return Returns Customer's current balance
 */
float Customer::getBalance() const {
    return balance;
}

/**
 * Returns Customer's total amount spent
 *
 * @param None
 * @return Returns Customer's total amount spent
 */
float Customer::getAmountSpent() const {
    return amountSpent;
}

/**
 * Returns Customer's total amount saved
 *
 * @param None
 * @return Returns Customer's total amount saved
 */
float Customer::getAmountSaved() const {
    return amountSaved;
}

/**
 * Sets Customer's balance
 *
 * @param newBalance -> balance to set Customer with
 * @return None
 */
void Customer::setBalance(float newBalance)
{
    balance = newBalance;
}

/**
 * Sets Customer's Amount saved
 *
 * @param newBalance -> Amount saved to set Customer with
 * @return None
 */
void Customer::setAmountSaved(float newAmountSaved)
{
    amountSaved = newAmountSaved;
}

/**
 * Sets Customer's Amount spent
 *
 * @param newBalance -> Amount spent to set Customer with
 * @return None
 */
void Customer::setAmountSpent(float newAmountSpent)
{
    amountSpent = newAmountSpent;
}


/**
 * Prints all information about Customer object to specified ostream.
 *
 * @param COUT -> ostream object to overload (std::cout)
 * @param customerObj -> customer to output.
 * @return ostream object
 */
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


