#include "login.h"
#include "ui_login.h"


Login::Login(BankingApp* bankApp, QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::Login),
      menu(bankApp)
{
    this->bankApp = bankApp;
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
    std::cout << "Username:" + uName.toStdString() + "Password:" + uPass.toStdString() << std::endl;


    LoginHandler loginHandler;                      // Login logic class
    QMessageBox msgBox;                             // Pop up message.
    bool flag = true;
    QString errorMsg = "";

    if (uName.size() == 0 || uName.size() == 0){
        flag = false;
        errorMsg = "Please Enter a username or password.";
    }

    if (flag == true){
        if(loginHandler.login(uName.toStdString(),uPass.toStdString()) == AUTHENTICATED) {
            std::cout << "success" << std::endl;

            msgBox.setText("Login successful.");
            msgBox.exec();

            // Set BankingApp to logged in customer
            CredentialsReader cReader;
            std::optional<Customer> loggedInCustomer = cReader.searchByUsername(uName.toStdString());
            bankApp->setCurrentCustomer(loggedInCustomer);
            std::cout <<"logged in as: " << bankApp->getCurrentCustomer()->getUsername() << std::endl;
            menu.updateScreenBalance();
            ui->stackedWidget->setCurrentWidget(&menu);
            return;

        } else {
            std::cout << "failure" << std::endl;

            msgBox.setText("Login unsuccessful. Please try again.");
            msgBox.exec();
            return;
        }
    }
    msgBox.setText(errorMsg);
    msgBox.exec();
    return;

}


void Login::on_back_clicked()
{
    emit menuClicked();
}

