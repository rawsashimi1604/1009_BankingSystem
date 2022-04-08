#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <QWidget>

#include "bankingapp.h"
#include "controller/leaderboardhandler.h"

namespace Ui {
class Leaderboard;
}

/**
 * Leaderboard contains functionality and attributes of the Leaderboard UI
 *
 * It consist of various function to update the Leaderboard UI and logics of user interaction
 *
 * It is a class that inherits from QWidget
 */
class Leaderboard : public QWidget
{
    Q_OBJECT

private:
    BankingApp* bankApp;                                                    // Pointer to a shared Data object
    Ui::Leaderboard *ui;                                                    // Pointer to UI object
    QString percentSpend;                                                   // Qstring variable for percent spend
    QString percentSave;                                                    // Qstring variable for percent save
    LeaderboardHandler lHandler;                                            // Initialise the LeaderboardHandler

public:
    explicit Leaderboard(BankingApp* bankApp, QWidget *parent = nullptr);   // Leaderboard constructor
    ~Leaderboard();                                                         // Destructor for Leaderboard
    void updateScreenBalance();                                             // Updates the balance on the screen of current customer
    void getCustomerAmountsave();                                           // gets the amount saved by the customer
    void getCustomerAmountspend();                                          // gets the amound spend by the customer
    void getSavePercentage();                                               // gets the percentile index of the customer savings
    void getSpendPercentage();                                              // gets the percentile index of the customer spendings
    void displayTables();                                                   // initialises the 2 tables to display the top 3 spenders and savers

private slots:
    void on_back_clicked();                                                 // Allows user to move back to previous screen (Menu)



signals:
    void menuClicked();                                                     //Signal to track if the back button is clicked
};



#endif                                                                      // LEADERBOARD_H
