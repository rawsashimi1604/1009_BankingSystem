#ifndef MENU_H
#define MENU_H

#include <QWidget>

#include "bankingapp.h"
#include "view/withdraw.h"
#include "view/deposit.h"
#include "view/transfer.h"
#include "view/history.h"
#include "view/leaderboard.h"



namespace Ui {
class Menu;
}

/**
 * Menu contains functionality and attributes of the Menu UI
 *
 * It consist of various function to update the Menu UI and logics of user interaction
 *
 * It is a class that inherits from QWidget
 */
class Menu : public QWidget
{
    Q_OBJECT

private:
    Ui::Menu *ui;                                                           // Pointer to the UI object
    BankingApp* bankApp;                                                    // Pointer to a shared Data object

    //initialise all the menu ui classes
    Withdraw withdraw;
    Deposit deposit;
    Transfer transfer;
    History history;
    Leaderboard leaderBoard;

public:
    explicit Menu(BankingApp* bankApp, QWidget *parent = nullptr);          // Constructor for the Menu object
    ~Menu();                                                                // Destructor for Menu object
    void updateScreenBalance();                                             // updates the balance on the screen of the current customer

private slots:
    void on_withdraw_clicked();                                             // Change the Menu Ui to withdraw UI
    void on_deposit_clicked();                                              // Change the Menu Ui to depotis UI
    void on_transfer_clicked();                                             // Change the Menu Ui to transfer UI
    void on_transactions_clicked();                                         // Change the Menu Ui to transactions UI
    void moveMenu();                                                        // sets the UI to Menu Ui and update the current balance on the screen
    void on_leaderboard_clicked();                                          // Change the Menu Ui to leaderboard UI

};

#endif // MENU_H
