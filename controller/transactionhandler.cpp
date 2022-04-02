#include "transactionhandler.h"

TransactionHandler::TransactionHandler()
{
}

bool TransactionHandler::logTransaction(int recieverId, int senderId, float amount_recieved, float amount_sent, Enums::TransactionType type) {
    // Use this function as a helper function to help with the other 3 functions
    TransactionReader TR;

    switch(type){
        case(Enums::TransactionType::WITHDRAWAL):{
            Transaction T(TR.getNextID(), recieverId, senderId, amount_recieved, amount_sent, UtilityFunctions::getTodaysDate(), Enums::TransactionType::WITHDRAWAL);
            return TR.write(T);
        }
        case(Enums::TransactionType::DEPOSIT):{
            Transaction T(TR.getNextID(), recieverId, senderId, amount_recieved, amount_sent, UtilityFunctions::getTodaysDate(), Enums::TransactionType::DEPOSIT);
            return TR.write(T);
        }
        case(Enums::TransactionType::TRANSFER):{
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
        CredentialsReader CR;

        if (CR.update(customer)){
            // If no transfer log happened, return TRANSACTION_LOG_FAILURE
            if (!logTransaction(-1, customer.getID(), 0, amt, Enums::TransactionType::WITHDRAWAL)){
                return TRANSACTION_LOG_FAILURE;
            }
            // Else, update transactions.csv with new transaction
            return TRANSACTION_SUCCESS;
        }
        else{
            return TRANSACTION_FAILURE;
        }
    }
}

TransactionStatus TransactionHandler::deposit(Customer customer, float amt) {
    // Add amount to Customer, update .csv file with new values
    customer.setBalance(customer.getBalance() + amt);
    CredentialsReader CR;

    if (CR.update(customer)){
        // If no transfer log happened, return TRANSACTION_LOG_FAILURE
        if (!logTransaction(customer.getID(), -1, amt, 0, Enums::TransactionType::DEPOSIT)){
            return TRANSACTION_LOG_FAILURE;
        }
        // Else, update transactions.csv with new transaction
        return TRANSACTION_SUCCESS;
    }
    else{
        return TRANSACTION_FAILURE;
    }
}

TransactionStatus TransactionHandler::transfer(Customer customerIn, Customer customerOut, float amt) {
    // If customerOut has less than amt, can't transfer, return TRANSACTION_FAILURE
    if (customerOut.getBalance() < amt){
        return TRANSACTION_FAILURE;
    }
    // Else, minus amount from customerOut, add amount to customerIn, update .csv file with new values
    else{
        customerOut.setBalance(customerOut.getBalance() - amt);
        customerIn.setBalance(customerIn.getBalance() + amt);

        CredentialsReader CR;

        if (CR.update(customerIn)){
            if (CR.update(customerOut)){
                // If no transfer log happened, return TRANSACTION_LOG_FAILURE
                if(!logTransaction(customerIn.getID(), customerOut.getID(), amt, amt, Enums::TransactionType::TRANSFER)){
                    return TRANSACTION_LOG_FAILURE;
                }
                // Else, update transactions.csv with new transaction
                else{
                    return TRANSACTION_SUCCESS;
                }
            }
            // If error updating, return TRANSACTION_FAILURE
            else{
                return TRANSACTION_FAILURE;
            }
        }
        // If error updating, return TRANSACTION_FAILURE
        else{
            return TRANSACTION_FAILURE;
        }
    }
}
