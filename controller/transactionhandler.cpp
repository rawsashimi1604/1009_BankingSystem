#include "transactionhandler.h"

TransactionHandler::TransactionHandler()
{
}

bool TransactionHandler::logTransaction(int recieverId, int senderId, float amount_recieved, float amount_sent, Enums::TransactionType type) {
    // Use this function as a helper function to help with the other 3 functions
    TransactionReader TR;

    switch(type){
        case(Enums::TransactionType::WITHDRAWAL): {
            Transaction T(TR.getNextID(), recieverId, senderId, amount_recieved, amount_sent, UtilityFunctions::getTodaysDate(), Enums::TransactionType::WITHDRAWAL);
            return TR.write(T);
        }
        case(Enums::TransactionType::DEPOSIT): {
            Transaction T(TR.getNextID(), recieverId, senderId, amount_recieved, amount_sent, UtilityFunctions::getTodaysDate(), Enums::TransactionType::DEPOSIT);
            return TR.write(T);
        }
        case(Enums::TransactionType::TRANSFER): {
            Transaction T(TR.getNextID(), recieverId, senderId, amount_recieved, amount_sent, UtilityFunctions::getTodaysDate(), Enums::TransactionType::TRANSFER);
            return TR.write(T);
        }
        default:
            return false;
    }
}

TransactionStatus TransactionHandler::withdraw(Customer customer, float amt) {
    // If customer has less than amt, can't withdraw, return TRANSACTION_FAILURE
    if (customer.getBalance() < amt){
        return TRANSACTION_FAILURE;
    }
    // Else, minus amount from Customer, update .csv file with new values
    else{
        customer.setBalance(customer.getBalance() - amt);
        customer.setAmountSpent(customer.getAmountSpent() + amt);

        CredentialsReader CR;

        if (CR.update(customer)){
            // If no transfer log happened, return TRANSACTION_LOG_FAILURE, add back amount to bank balance
            if (!logTransaction(-1, customer.getID(), 0, amt, Enums::TransactionType::WITHDRAWAL)){
                customer.setBalance(customer.getBalance() + amt);
                customer.setAmountSpent(customer.getAmountSpent() - amt);
                return TRANSACTION_LOG_FAILURE;
            }
            // Else, update transactions.csv with new transaction
            customer = *CR.searchByID(customer.getID());
            return TRANSACTION_SUCCESS;
        }
        else{
            return TRANSACTION_FAILURE;
        }
    }
}

TransactionStatus TransactionHandler::deposit(Customer customer, float amt) {

    std::cout << customer;

    // Add amount to Customer, update .csv file with new values
    customer.setBalance(customer.getBalance() + amt);
    customer.setAmountSaved(customer.getAmountSaved() + amt);

    CredentialsReader CR;

    if (CR.update(customer)){
        // If no transfer log happened, return TRANSACTION_LOG_FAILURE, remove back amount to bank balance
        if (!logTransaction(customer.getID(), -1, amt, 0, Enums::TransactionType::DEPOSIT)){
            customer.setBalance(customer.getBalance() - amt);
            customer.setAmountSaved(customer.getAmountSaved() - amt);
            return TRANSACTION_LOG_FAILURE;
        }
        // Else, update transactions.csv with new transaction
        customer = *CR.searchByID(customer.getID());
        std::cout << customer;
        return TRANSACTION_SUCCESS;
    }
    else{
        return TRANSACTION_FAILURE;
    }
}

TransactionStatus TransactionHandler::transfer(Customer fromCustomer, Customer toCustomer, float amt) {
    // If customerOut has less than amt, can't transfer, return TRANSACTION_FAILURE
    if (fromCustomer.getBalance() < amt){
        return TRANSACTION_FAILURE;
    }
    // Else, minus amount from customerOut, add amount to customerIn, update .csv file with new values
    else{

        fromCustomer.setBalance(fromCustomer.getBalance() - amt);
        fromCustomer.setAmountSpent(fromCustomer.getAmountSpent() + amt);

        toCustomer.setBalance(toCustomer.getBalance() + amt);
        toCustomer.setAmountSaved(toCustomer.getAmountSaved() + amt);

        CredentialsReader CR;

        if (CR.update(fromCustomer) && CR.update(toCustomer)) {

            // If no transfer log happened, return TRANSACTION_LOG_FAILURE, remove and add back amount to bank balance
            if(!logTransaction(toCustomer.getID(), fromCustomer.getID(), amt, amt, Enums::TransactionType::TRANSFER)){
                fromCustomer.setBalance(fromCustomer.getBalance() + amt);
                fromCustomer.setAmountSpent(fromCustomer.getAmountSpent() - amt);
                toCustomer.setBalance(toCustomer.getBalance() - amt);
                toCustomer.setAmountSaved(toCustomer.getAmountSaved() - amt);
                return TRANSACTION_LOG_FAILURE;
            }

            // Else, update transactions.csv with new transaction
            else{
                fromCustomer = *CR.searchByID(fromCustomer.getID());        // Update customer pointers to point to updated values.
                toCustomer = *CR.searchByID(toCustomer.getID());
                return TRANSACTION_SUCCESS;
            }
        }
    }

    return TRANSACTION_FAILURE;
}
