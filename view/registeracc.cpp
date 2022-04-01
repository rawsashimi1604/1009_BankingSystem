#include "registeracc.h"
#include "ui_registeracc.h"
#include <iostream>

RegisterAcc::RegisterAcc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterAcc)
{
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
    checkFlag = true;

    QString errorString = "";
    QMessageBox msgBox;
    int result;
    RegisterHandler rHandler;

    QString fname =  ui->fnameField->text();
    QString lname =  ui->lnameField->text();
    QString uName =  ui->usernameField->text();
    QString passCode =  ui->passField->text();
    QString age =  ui->ageField->text();



    if (fname.size() == 0){
        checkFlag = false;
         errorString += "-please enter your first name\n";
        //combinedMsg + errorString;

    }
    if (lname.size() == 0){
        checkFlag = false;
         errorString += "-please enter your last name\n";
        //combinedMsg + errorString;

    }
    if (uName.size() == 0){
        checkFlag = false;
         errorString += "-please enter a username\n";
        //combinedMsg + errorString;

    }
    if (passCode.size() == 0){
        checkFlag = false;
         errorString += "-please enter a pin number\n";

    }else{
        if(UtilityFunctions::checkNumeric(passCode)){
            checkFlag = false;
            errorString += "-Please only use numerics for your password\n";

        }
        if (passCode.size() < 6){
            checkFlag = false;
            errorString += "-Please ensure your pin number is 6 digit or more\n";
        }
   }

    if (age.size() == 0){
        checkFlag = false;
         errorString += "-please enter your age\n";
    }
    else{
         if(UtilityFunctions::checkNumeric(age)){
             checkFlag = false;
             errorString += "-Please only use numerics for your age\n";
         }
    }


    if (checkFlag == true){
       result = rHandler.registerAcc(fname.toStdString(), lname.toStdString(), age.toInt(), uName.toStdString(), passCode.toStdString());
       if (result == 1){
           msgBox.setText("Registration successful!");
           msgBox.exec();
           emit menuClicked();
       }if (result == 0){
           msgBox.setText("Current username is used, Please choose a new one.");
           msgBox.exec();
       }
    }
    if (checkFlag == false){
            msgBox.setText(errorString);
            msgBox.exec();
    }
}

