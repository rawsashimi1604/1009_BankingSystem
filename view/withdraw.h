#ifndef WITHDRAW_H
#define WITHDRAW_H

#include <QtWidgets>

#include "bankingapp.h"
#include "controller/transactionhandler.h"
#include "utils.h"

namespace Ui {
class Withdraw;
}

/**
 * Withdraw contains functionality and attributes of the Withdraw UI
 *
 * It consist of various function to update the Withdraw UI and logics of user interaction
 *
 * It is a class that inherits from QWidget
 */
class Withdraw : public QWidget
{
    Q_OBJECT

private:
    Ui::Withdraw *ui;                                                   // Pointer to UI object
    BankingApp* bankApp;                                                // Pointer to a shared Data Object
    TransactionHandler transactHandler;                                 // Initialise the TransactionHandler object
    QMessageBox msgBox;                                                 // Initialise the QMessageBox object

public:
    explicit Withdraw(BankingApp* bankApp, QWidget *parent = nullptr); // Constructor for the Withdraw object
    ~Withdraw();                                                       // Destructor for the Withdraw object
    void updateScreenBalance();                                        // updates the balance on the screen of the current customer

private slots:
    void on_back_clicked();                                            // Allows the user to move back to previous screen (Menu)
    void on_cfmWithdraw_clicked();                                     // Deducts the value from the user balance when interacted

signals:
    void menuClicked();                                                // Signal to track if the back button is clicked

};

#endif                                                                 // WITHDRAW_H
