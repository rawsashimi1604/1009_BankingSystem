#include "leaderboardhandler.h"

LeaderboardHandler::LeaderboardHandler()
{

}

std::vector<Customer> LeaderboardHandler::getTopThreeSpenders() {
    std::vector<Customer> customers = cReader.getAllCustomers();
    std::vector<Customer> res;


    // Add your logic to get top three spenders here

    // Accessing customers vector
    for (size_t i = 0; i < customers.size(); i++) {
        customers[i].getFullName();
    }

    return res;
}

std::vector<Customer> LeaderboardHandler::getTopThreeSavers() {
    std::vector<Customer> customers = cReader.getAllCustomers();
    std::vector<Customer> res;

    // Add your logic to get top three savers here

    // Accessing customers vector
    for (size_t i = 0; i < customers.size(); i++) {
        customers[i].getFullName();
    }

    return res;
}

double LeaderboardHandler::calculatePrcSpend(Customer customer) {

    if (!cReader.searchByID(customer.getID())) {
        std::cout << "Customer does not exist." << std::endl;
        return -1;
    }

    // Add your logic to get percentile for prc spent for inputted customer here

    return 0;
}

double LeaderboardHandler::calculatePrcSave(Customer customer) {

    if (!cReader.searchByID(customer.getID())) {
        std::cout << "Customer does not exist." << std::endl;
        return -1;
    }

    // Add your logic to get percentile for prc saved for inputted customer here

    return 0;
}
