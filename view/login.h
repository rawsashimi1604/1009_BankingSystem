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

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(BankingApp* bankApp, QWidget *parent = nullptr);
    ~Login();

    Ui::Login* getUI();

private slots:
    void on_loginButton_clicked();


    void on_back_clicked();

private:
    Ui::Login *ui;
    //initialise the menu class
    Menu menu;
    Encrypter encrypt;

    BankingApp* bankApp;

signals:
    void menuClicked();
};
#endif // LOGIN_H
