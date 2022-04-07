#ifndef LEADERBOARDHANDLER_H
#define LEADERBOARDHANDLER_H

#include "model/customer.h"
#include "controller/credentialsreader.h"
#include "view/leaderboard.h" // added a constructor there

class LeaderboardHandler
{
private:
    CredentialsReader cReader;

public:
    LeaderboardHandler();
    std::vector<Customer> getTopThreeSpenders();                        // Get a vector of the top three spenders
    std::vector<Customer> getTopThreeSavers();                          // Get a vector of the top three savers
    double calculatePrcSpend(Customer customer);                        // Calculate Customer's percentile (spending)
    double calculatePrcSave(Customer customer);                         // Calculate Customer's percentile (spending)
};

#endif // LEADERBOARDHANDLER_H
