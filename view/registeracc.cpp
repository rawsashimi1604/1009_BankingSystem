#include "registeracc.h"
#include "ui_registeracc.h"

RegisterAcc::RegisterAcc(BankingApp* bankApp, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterAcc)
{
    this->bankApp = bankApp;
    std::cout << bankApp << std::endl;
    ui->setupUi(this);
}

RegisterAcc::~RegisterAcc()
{
    delete ui;
}

void RegisterAcc::on_back_clicked()
{
    emit menuClicked();
}


void RegisterAcc::on_pushButton_3_clicked()
{

    QString fname =  ui->fnameField->text();
    QString lname =  ui->lnameField->text();
    QString uName =  ui->usernameField->text();
    QString passCode =  ui->passField->text();
    QString age =  ui->ageField->text();

    QMessageBox msgBox;
    RegisterHandler rHandler;

    if (fname.isNull()){
        msgBox.setText("Please input a valid username.");
        msgBox.exec();
    }



    rHandler.registerAcc(fname.toStdString(), lname.toStdString(), age.toInt(), uName.toStdString(), passCode.toStdString());
    msgBox.setText("Account Successfully Created.");
    msgBox.exec();
    emit menuClicked();
}

