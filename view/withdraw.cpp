#include "withdraw.h"
#include "ui_withdraw.h"

Withdraw::Withdraw(BankingApp* bankApp, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Withdraw)
{
    this->bankApp = bankApp;
    ui->setupUi(this);
    setWindowTitle(QString::fromStdString(bankApp->APPLICATION_NAME));
    QCoreApplication::setApplicationName(QString::fromStdString(bankApp->APPLICATION_NAME));
}

Withdraw::~Withdraw()
{
    delete ui;
}

void Withdraw::on_back_clicked()
{
    emit menuClicked();
}

void Withdraw::updateScreenBalance(){
    //When deposit button is clicked, it will update its balance
    QString balance = QString::number(bankApp->getCurrentCustomer()->getBalance());
    ui->balance->display(balance);
}




void Withdraw::on_cfmWithdraw_clicked()
{
    QString errorMsg = "";
    bool flag = true;
    QString withdrawAmt = ui->withdrawAmnt->text();

    // check for empty field
    if (withdrawAmt.size() == 0){
        flag = false;
        errorMsg = "Please insert a value to Withdraw.";
    }

    // check for null or input 0
    if (withdrawAmt.toFloat() == 0 && flag == true){
        flag = false;
        ui->withdrawAmnt->clear();
        errorMsg = "Please withdraw a value more than \"0\".";
    }

    //check if there is a negative input
    if(UtilityFunctions::checkNumeric(withdrawAmt) && flag == true){
        flag = false;
        ui->withdrawAmnt->clear();
        errorMsg = "Invalid input! Please input numbers only.";
    }

    //check if amount withdrawn is more than current balance
    if ((withdrawAmt.toFloat() > bankApp->getCurrentCustomer()->getBalance()) && flag == true){
        flag = false;
        ui->withdrawAmnt->clear();
        errorMsg = "Amount withdrawn has exceeded your limit!\nPlease try again.";
    }

    if (flag == true){
        int result = transactHandler.withdraw(*bankApp->getCurrentCustomer(),withdrawAmt.toFloat());
        if (result ==1){
            msgBox.setText("You have successfully withdrawn $"+ui->withdrawAmnt->text() + "\nMoving back to main menu...");
            msgBox.exec();
            CredentialsReader cReader;
            std::optional<Customer> updateCustomer = cReader.searchByUsername(bankApp->getCurrentCustomer()->getUsername());
            bankApp->setCurrentCustomer(updateCustomer);
            ui->withdrawAmnt->clear();
            emit menuClicked();
            return;
        }
        if(result == -1){
            errorMsg = "Transaction Log Failure, Please try again later.";
        }
        if (result == 0){
            errorMsg = "Withdraw Failed, Please try again.";
        }
    }
    msgBox.setText(errorMsg);
    msgBox.exec();
    return;



}

