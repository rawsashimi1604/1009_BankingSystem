#ifndef REGISTERACC_H
#define REGISTERACC_H

#include <QtWidgets>

#include "bankingapp.h"
#include "controller/registerhandler.h"
#include "utils.h"


namespace Ui {
class RegisterAcc;
}

/**
 * RegisterAcc contains functionality and attributes of the RegisterAcc UI
 *
 * It consist of various function to update the RegisterAcc UI and logics of user interaction
 *
 * It is a class that inherits from QWidget
 */
class RegisterAcc : public QWidget
{
    Q_OBJECT

private:
    BankingApp* bankApp;                                                    // Pointer to a shared Data object
    Ui::RegisterAcc *ui;                                                    // Pointer to Ui Object
    bool checkFlag ;                                                        // flag to check if users input is correct

public:
    explicit RegisterAcc(BankingApp* bankApp, QWidget *parent = nullptr);   // Constructor for RegisterAcc object
    ~RegisterAcc();                                                         // Destructor for RegisterAcc object

private slots:
    void on_back_clicked();                                                 // Allows user to move back to previous screen (TItle)
    void on_pushButton_3_clicked();                                         // Contains logic to check user input if succrssful creates a new account

signals:
    void menuClicked();                                                     // Signal to track if the back button is clicked
};

#endif                                                                      // REGISTERACC_H
