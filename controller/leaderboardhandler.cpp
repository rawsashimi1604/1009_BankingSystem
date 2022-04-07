//#include "leaderboardhandler.h"

//LeaderboardHandler::LeaderboardHandler()
//{

//}

//std::vector<Customer> LeaderboardHandler::getTopThreeSpenders() {
//    std::vector<Customer> customers = cReader.getAllCustomers();
//    //std::vector<Customer> res;
//    std::vector<Customer> res;

//    // Add your logic to get top three spenders here
//    int topspend = 0, secondspend=0, thirdspend=0;
//    std::string topspender,secondspender,thirdspender;

//    // Accessing customers vector
//    for (size_t i = 0; i < customers.size(); i++) {
//        customers[i].getAmountSpent();
//        if (customers[i].getAmountSpent() > topspend){
//            topspend = customers[i].getAmountSpent();
//            topspender = customers[i].getUsername();
//        }
//    }
//    for (size_t i = 0; i < customers.size(); i++) {
//        customers[i].getAmountSpent();
//        if (customers[i].getAmountSpent() > secondspend && customers[i].getAmountSpent() < topspend){
//            secondspend = customers[i].getAmountSpent();
//            secondspender = customers[i].getUsername();
//        }
//    }
//    for (size_t i = 0; i < customers.size(); i++) {
//        customers[i].getAmountSpent();
//        if (customers[i].getAmountSpent() > thirdspend && customers[i].getAmountSpent() < secondspend){
//            thirdspend = customers[i].getAmountSpent();
//            thirdspender = customers[i].getUsername();
//        }
//    }

//    std::string topspending = std::to_string(topspend);
//    std::string secondspending = std::to_string(secondspend);
//    std::string thirdspending = std::to_string(thirdspend);
//    Leaderboard Leaderboard(topspending, secondspending, thirdspending, topspender, secondspender, thirdspender);
////    res.push_back(topspend);
////    res.push_back(secondspend);
////    res.push_back(thirdspend);
////    res.push_back(topspender);
////    res.push_back(secondspender);
//    res.push_back(Leaderboard);
//    return res;
//}

//std::vector<Customer> LeaderboardHandler::getTopThreeSavers() {
//    std::vector<Customer> customers = cReader.getAllCustomers();
//    std::vector<Customer> res;

//    // Add your logic to get top three spenders here
//    int topsave = 0, secondsave=0, thirdsave=0;
//    std::string topsaver, secondsaver, thirdsaver;

//    // Accessing customers vector
//    for (size_t i = 0; i < customers.size(); i++) {
//        customers[i].getAmountSpent();
//        if (customers[i].getAmountSpent() > topsave){
//            topsave = customers[i].getAmountSpent();
//            topsaver = customers[i].getUsername();
//        }
//    }
//    for (size_t i = 0; i < customers.size(); i++) {
//        customers[i].getAmountSpent();
//        if (customers[i].getAmountSpent() > secondsave && customers[i].getAmountSpent() < topsave){
//            secondsave = customers[i].getAmountSpent();
//            secondsaver = customers[i].getUsername();
//        }
//    }
//    for (size_t i = 0; i < customers.size(); i++) {
//        customers[i].getAmountSpent();
//        if (customers[i].getAmountSpent() > thirdsave && customers[i].getAmountSpent() < secondsave){
//            thirdsave = customers[i].getAmountSpent();
//            thirdsaver = customers[i].getUsername();
//        }
//    }

//    std::string topsaving = std::to_string(topsave);
//    std::string secondsaving = std::to_string(secondsave);
//    std::string thirdsaving = std::to_string(thirdsave);
//    Leaderboard Leaderboard(topsaving, secondsaving, thirdsaving, topsaver, secondsaver, thirdsaver);
////    res.push_back(topspend);
////    res.push_back(secondspend);
////    res.push_back(thirdspend);
////    res.push_back(topspender);
////    res.push_back(secondspender);
//    res.push_back(Leaderboard);
//    return res;

//}

//double LeaderboardHandler::calculatePrcSpend(Customer customer) {

//    if (!cReader.searchByID(customer.getID())) {
//        std::cout << "Customer does not exist." << std::endl;
//        return -1;
//    }

//    // Add your logic to get percentile for prc spent for inputted customer here

//    return 0;
//}

//double LeaderboardHandler::calculatePrcSave(Customer customer) {

//    if (!cReader.searchByID(customer.getID())) {
//        std::cout << "Customer does not exist." << std::endl;
//        return -1;
//    }

//    // Add your logic to get percentile for prc saved for inputted customer here

//    return 0;
//}
