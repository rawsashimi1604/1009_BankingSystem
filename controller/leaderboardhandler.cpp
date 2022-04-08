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

 double LeaderboardHandler::calculatePrcSpend(Customer customer) {

     if (!cReader.searchByID(customer.getID())) {
         std::cout << "Customer does not exist." << std::endl;
         return -1;
     }
     float customerIndex = 0;
     float totalNumSpenders = 0;

     //get the sorted spenders list
     std::vector<Customer> customers = cReader.getAllCustomers();
     std::vector<Customer> res;

     std::sort(customers.begin(), customers.end(), [](const Customer& c1, const Customer& c2) {
         return c1.getAmountSpent() > c2.getAmountSpent();
     });

     for (size_t i = 0; i < customers.size(); i++) {

         res.push_back(customers[i]);
     }

     //After sort
     for (size_t i = 0; i < res.size(); i++) {
         if (res[i].getUsername() == customer.getUsername()){
             customerIndex = i+1;

         }
         totalNumSpenders++;
     }



     double prcSpend = (customerIndex/totalNumSpenders)*100;
//     std::cout << customerIndex << std::endl;
//     std::cout << totalNumSpenders << std::endl;
//     std::cout << prcSpend << std::endl;

     return prcSpend;
 }


 double LeaderboardHandler::calculatePrcSave(Customer customer) {
     if (!cReader.searchByID(customer.getID())) {
         std::cout << "Customer does not exist." << std::endl;
         return -1;
     }
     float customerIndex = 0;
     float totalNumSavers = 0;

     //get the sorted spenders list
     std::vector<Customer> customers = cReader.getAllCustomers();
     std::vector<Customer> res;

     std::sort(customers.begin(), customers.end(), [](const Customer& c1, const Customer& c2) {
         return c1.getAmountSaved() > c2.getAmountSaved();
     });

     for (size_t i = 0; i < customers.size(); i++) {

         res.push_back(customers[i]);
     }

     //After sort
     for (size_t i = 0; i < res.size(); i++) {
         if (res[i].getUsername() == customer.getUsername()){
             customerIndex = i+1;

         }
         totalNumSavers++;
     }



     double prcSave = (customerIndex/totalNumSavers)*100;
//     std::cout << customerIndex << std::endl;
//     std::cout << totalNumSpenders << std::endl;
//     std::cout << prcSave << std::endl;




     return prcSave;
}
