# 1009_BankingSystem

![Title Screen](https://github.com/rawsashimi1604/1009_BankingSystem/blob/master/images/TitleScreen.png?raw=true)

Our application is based around a banking simulation application. 
We have created this application to apply the skills learnt on **Object Oriented Programming (OOP).** 
It features common banking use cases and a Graphical User Interface (GUI) built using Qt6 Creator.

## Teammates
**P4 - TEAM 41:**
- [GAVIN LOO WEI REN](https://github.com/rawsashimi1604)
- [CASTRO JERIEL PEDROCHE](https://github.com/JerielCastro)
- [LEONG SHU MIN](https://github.com/minXnub)
- [MATHUKUMILLI GEETHIKA](https://github.com/geethika-m)
- [LEONG WAI KIAT](https://github.com/Wai-Kiat)
- [NYAN LIN HTOO](https://github.com/LynxYufloria)

## MVC Software Design Pattern
The application was designed using the MVC software design pattern (Model, View, Controller). 
We split all objects/classes into one of the 3 main categories. 
The Model category contains all objects related to storing data,
the View category contains all objects that interact with the GUI. 
Finally, the Controller category contains all objects that perform all business logic, update Model objects, and 
interact with View objects to produce the final output.
<br> <br>
Below is a diagram representing a Withdrawal Transaction
  <br> <br>
![Withdrawal Transaction](https://github.com/rawsashimi1604/1009_BankingSystem/blob/master/images/Withdrawal_Diagram.png?raw=true)


The Classes involved in the withdrawal transfer request include:
- Withdraw (View), an UI representation of the Withdraw page in the GUI (Qt)
- Customer (Model), an object that stores data that a customer should have. (username, PIN, balance, etc.)
- Transaction (Model), an object that stores data behind each transaction (date of transaction, who made the transaction, amount transferred, etc.)
- TransactionHandler (Controller), handles the logic behind each transaction request (withdraw, deposit, transfer), checks if transaction is valid (enough money to withdraw).
- CrendentialsReader (Controller), handles the logic behind updating the customers database.
- TransactionReader (Controller), handles the logic behind updating the transaction database.
- Encrypter (Controller), encrypts/decrypts customer sensitive data before writing data into the database or retrieving data from database.

## Application Layout
The application consists of the following pages:
- Title Page: The start of the application. It is where the user either logs in into their account or creates a new one.
- Register and Login Page: These pages are where the users can create a new account or log in to their existing account. 
- Main Menu Page:  This page is where most of the functions of the bank application are located. It also shows the current balance of the user.
- Withdraw and Deposit Page: This page is where the users can withdraw from and deposit to their account. 
- Transfer Page: This page is where the users can transfer money from their account to another account. 
- Transaction History Page: This page shows the previous transactions that happened to the users’ account.  
- Leaderboard Page: This page allows the users to compare the amount of money they have saved or spent with other users. 

![Transaction History](https://github.com/rawsashimi1604/1009_BankingSystem/blob/master/images/TransactionScreen.png?raw=true)

## File Handling

![CSV](https://github.com/rawsashimi1604/1009_BankingSystem/blob/master/images/Encryption.png?raw=true)

The data required for this application is stored in the customers.csv and transactions.csv. 
The above figure shows the data in the customers.csv. 
Each column is separated by a comma as standard for a csv file. The management of this set of data is handled by the CredentialsReader which opens a file stream for customers.csv and searches the customers.csv for a matching username or id as well as fetching everything and storing the information into an object of the Customer class. The CredentialsReader also can write new entries and update existing ones by interacting with the filestream.

There is a similar variant of TransactionReader managing the transactions.csv which contains the history of transactions performed on this system.

### Hashing / Encryption
Looking at the data continued in customers.csv one might notice that the Personal Identifiable Information is not readable. This is because the first name, last name and user name are encrypted with a caesar cipher. After reading through transaction.csv, the CredentialsHandler calls the Encrypter class to decrypt the relevant rows. The Encrypter class uses the encryptASCII function which goes through each character of every string and applies the cipher key to it by adding the key to the ASCII value of each character. The process is the same for decryptASCII except the cipher key is deducted from the ASCII value.

The password is also protected in a similar fashion. However, it is not encrypted but hashed. Hashing irreversibly converts the password into another string which is then stored. This means even if there is unauthorised access to the transactions.csv file and the intruder is able to decrypt the data, the password remains safe and the users’ login information is not compromised. Upon log in, the user's input for the password is hashed using the same algorithm and checked against the stored value to authorise the user.

The hashing algorithm XOR each byte of the input with a variable and multiples it by a large number. The result is then converted into hexadecimal format and made into uppercase.
