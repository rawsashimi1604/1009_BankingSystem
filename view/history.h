#ifndef HISTORY_H
#define HISTORY_H

#include <QWidget>

#include "bankingapp.h"
#include "controller/transactionreader.h"
#include "controller/credentialsreader.h"

#include "utils.h"

#include "model/customer.h"

namespace Ui {
class History;
}

/**
 * History contains functionality and attributes of History UI
 *
 * It consist of various function to update the History UI and logics user interaction
 *
 * It is a class that inherits from QWidget
 */

class History : public QWidget
{
    Q_OBJECT

private:
    BankingApp* bankApp;                                                        // Pointer to a shared Data object
    Ui::History *ui;                                                            // Pointer to UI object
    TransactionReader tReader;                                                  // Initialises TransactionReader object as tReader
    CredentialsReader cReader;                                                  // Initialises CredentialReader object as cReader

public:
    explicit History(BankingApp* bankApp, QWidget *parent = nullptr);           // History constructor
    ~History();                                                                 // History Destructor
    void updateScreenBalance();                                                 // Updates the balance on the screen of current customer
    void tableWidgetDisplay();                                                  // Updates the top 3 Spenders and Savers to the Spenders and Savers Table


private slots:
    void on_back_clicked();                                                     // Allows user to move back to previous screen (Menu)

signals:
    void menuClicked();                                                         //Signal to track if the back button is clicked

};

#endif                                                                          // HISTORY_H
