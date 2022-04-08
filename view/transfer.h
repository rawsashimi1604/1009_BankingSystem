#ifndef TRANSFER_H
#define TRANSFER_H

#include <QtWidgets>
#include "bankingapp.h"
#include "controller/transactionreader.h"
#include "controller/transactionhandler.h"
#include "utils.h"



namespace Ui {
class Transfer;
}

/**
 * Transfer contains functionality and attributes of the Transfer UI
 *
 * It consist of various function to update the Transfer UI and logics of user interaction
 *
 * It is a class that inherits from QWidget
 */
class Transfer : public QWidget
{
    Q_OBJECT

private:
    Ui::Transfer *ui;                                                   // Pointer to UI object
    BankingApp* bankApp;                                                // Pointer to a shared Data object
    QMessageBox  msgBox;                                                // Initialises the QMessageBox object
    CredentialsReader cReader;                                          //Initialises the CredentialReader Object
    TransactionHandler transactHandler;                                 //Initialises the TransactionHandler Object

public:
    explicit Transfer(BankingApp* bankApp, QWidget *parent = nullptr);  // Constructor for the Transfer object
    ~Transfer();                                                        // Destructor for the Transfer object
    void updateScreenBalance();                                         // Updates the balance on the screen of current Customer


signals:
    void menuClicked();                                                 // Signal to track if the back button is clicked

private slots:
    void on_back_clicked();                                             // Allow user to move back to the previous screen (Menu)
    void on_cfmTransfer_clicked();                                      // Allows user to transfer the money to another user via username
};

#endif                                                                  // TRANSFER_H
