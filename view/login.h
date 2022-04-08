#ifndef LOGIN_H
#define LOGIN_H

#include <QtWidgets>
#include <QMainWindow>

#include "bankingapp.h"
#include "view/menu.h"
#include "controller/loginhandler.h"
#include "controller/encrypter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

/**
 * Login contains functionality and attributes of the Login UI
 *
 * It consist of various function to update the Login UI and logics of user interaction
 *
 * It is a class that inherits from QWidget
 */
class Login : public QMainWindow
{
    Q_OBJECT

private:
    Ui::Login *ui;                                                  // Pointer to UI object
    Menu menu;                                                      // initialise the menu class
    Encrypter encrypt;                                              // initialise the encrypt object
    BankingApp* bankApp;                                            // Pointer to a shared data object

public:
    Login(BankingApp* bankApp, QWidget *parent = nullptr);          // Login Constructor
    ~Login();                                                       // Login Destructor
    Ui::Login* getUI();                                             // Pointer to get UI function

private slots:
    void on_loginButton_clicked();                                  // Allows the user to login when they interact with the button

    void on_back_clicked();                                         // Allows the user to move back to previous screen (Title)



signals:
    void menuClicked();                                             // Signal to track if the back button is clicked
};
#endif // LOGIN_H
