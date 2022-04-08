#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QtWidgets>


#include "bankingapp.h"
#include "controller/transactionhandler.h"
#include "controller/credentialsreader.h"
#include "utils.h"

namespace Ui {
class Deposit;
}

/**
 * Deposit contains functionality and attributes of the deposit UI
 *
 * It consist of various function to update the Deposit UI and logics of user interaction
 *
 * It is a class that inherits from QWidget
 */
class Deposit : public QWidget
{
    Q_OBJECT

private:
    BankingApp* bankApp;                                                // Pointer to a shared Data object
    Ui::Deposit *ui;                                                    // Pointer to UI object
    TransactionHandler transactHandler;                                 // Initialise the TransactionHandler object
    QMessageBox msgBox;                                                 // Initialise the QMessageBox object

public:
    explicit Deposit(BankingApp* bankApp, QWidget *parent = nullptr);   // Deposit constructor
    ~Deposit();                                                         // Deposit Destructor
    void updateScreenBalance();                                         // Updates the balance on the screen of current customer

private slots:
    void on_back_clicked();                                             // Allows user to move back to previous screen (Menu)
    void on_confirmDeposit_clicked();                                   // Updates the deposited amount to the CSVfile

signals:
    void menuClicked();                                                 //Signal to track if the back button is clicked


};

#endif                                                                  // DEPOSIT_H
