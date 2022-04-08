#include "leaderboardhandler.h"

LeaderboardHandler::LeaderboardHandler()
{

}

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

    // After sort
//    for (size_t i = 0; i < res.size(); i++) {
//        std::cout << "Customer name: " << res[i].getFullName() << std::endl;
//        std::cout << "Customer spend: $" << res[i].getAmountSpent() << std::endl << std::endl;
//    }

    return res;
}

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

    // After sort
//    for (size_t i = 0; i < res.size(); i++) {
//        std::cout << "Customer name: " << res[i].getFullName() << std::endl;
//        std::cout << "Customer spend: $" << res[i].getAmountSaved() << std::endl << std::endl;
//    }

    return res;

}
// percentage spend and save function is moved to Leaderboard.h and Leaderboard.cpp

// double LeaderboardHandler::calculatePrcSpend(Customer customer) {

//     if (!cReader.searchByID(customer.getID())) {
//         std::cout << "Customer does not exist." << std::endl;
//         return -1;
//     }

//     float spending = customer.getAmountSpent();
//     float saving = customer.getBalance();
//     double percentspend = spending/(spending+saving) *100;

//     // Add your logic to get percentile for prc spent for inputted customer here

//     return percentspend;
// }

// double LeaderboardHandler::calculatePrcSave(Customer customer) {

//     if (!cReader.searchByID(customer.getID())) {
//         std::cout << "Customer does not exist." << std::endl;
//         return -1;
//     }
//     float spending = customer.getAmountSpent();
//     float saving = customer.getBalance();
//     double percentsave = saving/(spending+saving) *100;

//     // Add your logic to get percentile for prc saved for inputted customer here

//     return percentsave;

