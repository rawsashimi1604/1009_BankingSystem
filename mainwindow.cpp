#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controller/loginhandler.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Gets the pointer to the UI.
Ui::MainWindow* MainWindow::getUI() {
    return this->ui;
}

string login = "temp123";
string pass = "temp123456";

void MainWindow::on_loginButton_clicked()
{
    cout << "loginButtonCheck" << endl;

    QString uName =  ui->usernameField->toPlainText();
    QString uPass = ui->passwordField->toPlainText();

    //cout  << uName.toStdString() << ", " << uPass.toStdString() << endl;
    LoginHandler test;
    if(test.LoginHandler::login(uName.toStdString(),uPass.toStdString())){
         cout << "success" << endl;
    }
}

