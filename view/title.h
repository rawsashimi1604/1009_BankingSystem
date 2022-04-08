#ifndef TITLE_H
#define TITLE_H

#include <QWidget>

#include "bankingapp.h"
#include "view/registeracc.h"
#include "view/login.h"

namespace Ui {
class Title;
}

/**
 * Title contains functionality and attributes of the Title UI
 *
 * It consist of various function to update the Title UI and logics of user interaction
 *
 * It is a class that inherits from QWidget
 */
class Title : public QWidget
{
    Q_OBJECT


private:
    BankingApp* bankApp;                                            // Pointer to a shared Data object
    Ui::Title *ui;                                                  // Pointer to UI object
    RegisterAcc reg;                                                // Initialises the RegisterAcc object
    Login login;                                                    // Initialises the Login object

public:
    explicit Title(BankingApp* bankApp, QWidget *parent = nullptr); // Title Constructor
    ~Title();                                                       // Title Destructor

private slots:
    void on_createAcc_clicked();                                    // Move the Title UI to RegisterAcc UI
    void on_login_clicked();                                        // Move the Title UI to Login UI
    void moveMenu();                                                // Move the Current UI back to Title

};

#endif                                                              // TITLE_H
