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

void MainWindow::on_loginButton_clicked()
{
    cout << "loginButtonCheck" << endl;

    QString uName =  ui->usernameField->toPlainText();
    QString uPass = ui->passwordField->toPlainText();

    LoginHandler loginHandler;

    if(loginHandler.login(uName.toStdString(),uPass.toStdString()) == AUTHENTICATED) {
        cout << "success" << endl;
    } else {
        cout << "failure" << endl;
    }
}

