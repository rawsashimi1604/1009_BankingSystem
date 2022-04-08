#include "leaderboardhandler.h"

LeaderboardHandler::LeaderboardHandler()
{

}

std::vector<Customer> LeaderboardHandler::getTopThreeSpenders() {
    std::vector<Customer> customers = cReader.getAllCustomers();
    //std::vector<Customer> res;
    std::vector<Customer> res;

    // Sort customers by top 3 spenders ( Insertion Sort )
    for (size_t i = 1; i < customers.size(); i++) {

        float currSpend = customers[i].getAmountSpent();
        int position = i;

        while (position > 0 && customers[position-1].getAmountSpent() > currSpend) {
            customers[position] = customers[position-1];
            position--;
        }

        customers[position] = customers[i];
    }

    for (size_t i = 0; i < customers.size(); i++) {
        std::cout << "Customer name: " << customers[i].getFullName() << std::endl;
        std::cout << "Customer spend: $" << customers[i].getAmountSpent() << std::endl << std::endl;
    }

    return res;
}


double LeaderboardHandler::calculatePrcSpend(Customer customer) {

    if (!cReader.searchByID(customer.getID())) {
        std::cout << "Customer does not exist." << std::endl;
        return -1;
    }

    float spending = customer.getAmountSpent();
    float saving = customer.getBalance();
    double percentspend = spending/(spending+saving) *100;

    // Add your logic to get percentile for prc spent for inputted customer here

    return percentspend;
}

double LeaderboardHandler::calculatePrcSave(Customer customer) {

    if (!cReader.searchByID(customer.getID())) {
        std::cout << "Customer does not exist." << std::endl;
        return -1;
    }
    float spending = customer.getAmountSpent();
    float saving = customer.getBalance();
    double percentsave = saving/(spending+saving) *100;

    // Add your logic to get percentile for prc saved for inputted customer here

    return percentsave;
}
