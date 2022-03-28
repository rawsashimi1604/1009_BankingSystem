#include "login.h"
#include "ui_login.h"


Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    //insert a menu object
    ui->stackedWidget->addWidget(&menu);

    //Insert place holder
    ui->usernameField->setPlaceholderText("Enter your Username");
    ui->passwordField->setPlaceholderText("Enter your Password");

    //Enable a clear button
    ui->usernameField->setClearButtonEnabled(true);
    ui->passwordField->setClearButtonEnabled(true);

    //Enable the dot for password field instead of plaintext
    ui->passwordField->setEchoMode(QLineEdit::Password);



}

Login::~Login()
{
    delete ui;
}

// Gets the pointer to the UI.
Ui::Login* Login::getUI() {
    return this->ui;

}

void Login::on_loginButton_clicked()
{
    cout << "loginButtonCheck" << endl;

    QString uName =  ui->usernameField->text();
    QString uPass = ui->passwordField->text();

    LoginHandler loginHandler;

    if(loginHandler.login(uName.toStdString(),uPass.toStdString()) == AUTHENTICATED) {
        cout << "success" << endl;
        ui->stackedWidget->setCurrentWidget(&menu);

    } else {
        cout << "failure" << endl;
    }
}

