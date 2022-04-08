#include "leaderboardhandler.h"

/**
 * Constructs LeaderboardHandler object
 *
 * @param None
 *
 */
LeaderboardHandler::LeaderboardHandler()
{

}

/**
 * Get a vector of the top three spenders
 *
 * @param None
 * @return Returns a vector of Customers (the top three spenders)
 */
std::vector<Customer> LeaderboardHandler::getTopThreeSpenders() {
    std::vector<Customer> customers = cReader.getAllCustomers();
    std::vector<Customer> res;

    std::sort(customers.begin(), customers.end(), [](const Customer& c1, const Customer& c2) {
        return c1.getAmountSpent() > c2.getAmountSpent();
    });

    for (size_t i = 0; i < customers.size(); i++) {
        if (i == 3) {
            break;
        }

        res.push_back(customers[i]);
    }

    return res;
}

/**
 * Get a vector of the top three savers
 *
 * @param None
 * @return Returns a vector of Customers (the top three savers)
 */
std::vector<Customer> LeaderboardHandler::getTopThreeSavers() {
    std::vector<Customer> customers = cReader.getAllCustomers();
    std::vector<Customer> res;

    std::sort(customers.begin(), customers.end(), [](const Customer& c1, const Customer& c2) {
        return c1.getAmountSaved() > c2.getAmountSaved();
    });

    for (size_t i = 0; i < customers.size(); i++) {
        if (i == 3) {
            break;
        }

        res.push_back(customers[i]);
    }

    return res;

}

/**
 * Calculate Customer's percentile (spending)
 *
 * @param Customer to check percentile spending
 * @return Returns the Customer's spending percentile.
 */
double LeaderboardHandler::calculatePrcSpend(Customer customer) {

    if (!cReader.searchByID(customer.getID())) {
        std::cout << "Customer does not exist." << std::endl;
        return -1;
    }

    // Add your logic to get percentile for prc spent for inputted customer here

    return 0;
}

/**
 * Calculate Customer's percentile (saving)
 *
 * @param Customer to check percentile saving
 * @return Returns the Customer's saving percentile.
 */
double LeaderboardHandler::calculatePrcSave(Customer customer) {

    if (!cReader.searchByID(customer.getID())) {
        std::cout << "Customer does not exist." << std::endl;
        return -1;
    }

    // Add your logic to get percentile for prc saved for inputted customer here

    return 0;
}
