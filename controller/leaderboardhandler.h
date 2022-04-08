#ifndef LEADERBOARDHANDLER_H
#define LEADERBOARDHANDLER_H

#include "model/customer.h"
#include "controller/credentialsreader.h"

/**
 * LeaderboardHandler contains a set of functions that interface with the Leaderboard View page.
 *
 */
class LeaderboardHandler
{
private:
    CredentialsReader cReader;                                          // Object used to access customers database

public:
    LeaderboardHandler();                                               // Constructs the LeaderboardHandler object.
    std::vector<Customer> getTopThreeSpenders();                        // Get a vector of the top three spenders
    std::vector<Customer> getTopThreeSavers();                          // Get a vector of the top three savers
    double calculatePrcSpend(Customer customer);                        // Calculate Customer's percentile (spending)
    double calculatePrcSave(Customer customer);                         // Calculate Customer's percentile (spending)
};

#endif // LEADERBOARDHANDLER_H
