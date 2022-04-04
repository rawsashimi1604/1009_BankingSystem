#include "login.h"
#include "ui_login.h"


Login::Login(BankingApp* bankApp, QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::Login),
      menu(bankApp)
{
    this->bankApp = bankApp;
    std::cout << bankApp << std::endl;
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
    std::cout << "loginButtonCheck" << std::endl;

    QString uName =  ui->usernameField->text();
    QString uPass = ui->passwordField->text();

    LoginHandler loginHandler;                      // Login logic class
    QMessageBox msgBox;                             // Pop up message.

    if(loginHandler.login(uName.toStdString(),uPass.toStdString()) == AUTHENTICATED) {
        std::cout << "success" << std::endl;

        msgBox.setText("Login successful.");
        msgBox.exec();

        // Set BankingApp to logged in customer
        CredentialsReader cReader;
        std::optional<Customer> loggedInCustomer = cReader.searchByUsername(uName.toStdString());
        bankApp->setCurrentCustomer(loggedInCustomer);
        menu.updateScreenBalance();
        ui->stackedWidget->setCurrentWidget(&menu);

    } else {
        std::cout << "failure" << std::endl;

        msgBox.setText("Login unsuccessful. Please try again.");
        msgBox.exec();
    }
}


void Login::on_back_clicked()
{
    emit menuClicked();
}

