#include "deposit.h"
#include "ui_deposit.h"

Deposit::Deposit(BankingApp* bankApp, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Deposit)
{

    this->bankApp = bankApp;
    std::cout << bankApp << std::endl;
    ui->setupUi(this);
}

Deposit::~Deposit()
{
    delete ui;
}

void Deposit::on_back_clicked()
{
    emit menuClicked();
}

void Deposit::updateScreenBalance(){
    //When deposit button is clicked, it will update its balance
    QString balance = QString::number(bankApp->getCurrentCustomer()->getBalance());
    ui->balance->display(balance);
}

void Deposit::on_confirmDeposit_clicked()
{
    QString errorMsg = "";
    bool flag = true;
    QString depositAmt = ui->depositAmnt->text();

    // check for empty field
    if (depositAmt.size() == 0){
        flag = false;
        errorMsg = "Please insert a value to Deposit.";
    }

    // check for null or input 0
    if (depositAmt.toFloat() == 0 && flag == true){
        flag = false;
        ui->depositAmnt->clear();
        errorMsg = "Please deposit a value more than \"0\".";
    }

    //check if there is a negative input
    if(UtilityFunctions::checkNumeric(depositAmt) && flag == true){
        flag = false;
        ui->depositAmnt->clear();
        errorMsg = "Invalid input! Please input numbers only.";
    }

    if (flag == true){
        int result = transactHandler.deposit(*bankApp->getCurrentCustomer(),depositAmt.toFloat());
        if (result ==1){
            msgBox.setText("You have successfully deposited $"+ui->depositAmnt->text() + "\nMoving back to main menu...");
            msgBox.exec();
            CredentialsReader cReader;
            std::optional<Customer> updateCustomer = cReader.searchByUsername(bankApp->getCurrentCustomer()->getUsername());
            bankApp->setCurrentCustomer(updateCustomer);
            std::cout << bankApp->getCurrentCustomer()->getBalance() << std::endl;
            ui->depositAmnt->clear();
            emit menuClicked();
            return;
        }
        if(result == -1){
            errorMsg = "Transaction Log Failure, Please try again later.";
        }
        if (result == 0){
            errorMsg = "Deposit Failed, Please try again.";
        }


    }
    msgBox.setText(errorMsg);
    msgBox.exec();
    return;
}

