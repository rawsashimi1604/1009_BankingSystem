#include "transfer.h"
#include "ui_transfer.h"

Transfer::Transfer(BankingApp* bankApp, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Transfer)
{
    this->bankApp = bankApp;
    ui->setupUi(this);
    setWindowTitle(QString::fromStdString(bankApp->APPLICATION_NAME));
    QCoreApplication::setApplicationName(QString::fromStdString(bankApp->APPLICATION_NAME));
}

Transfer::~Transfer()
{
    delete ui;
}

void Transfer::on_back_clicked()
{
     emit menuClicked();
}

void Transfer::updateScreenBalance(){
    //When deposit button is clicked, it will update its balance
    QString balance = QString::number(bankApp->getCurrentCustomer()->getBalance());
    ui->balance->display(balance);
}


void Transfer::on_cfmTransfer_clicked()
{
    QString tAmt = ui->transferAmnt->text();
    QString tName = ui->transferName->text();
    QString errorMsg = "";
    std::string username = bankApp->getCurrentCustomer()->getUsername();
    bool flag = true;

    if (tAmt.size() == 0 || tName.size() == 0){
        flag = false;
        errorMsg = "Please ensure that your Amount to Transfer or Sender Username is not empty.";
    }
    if (tName.toStdString() == username){
        flag = false;
        errorMsg = "Please ensure that your Recipent is not the same as your Username.";
    }
    if ((UtilityFunctions::checkNumeric(tAmt) || (tAmt.toFloat() < 1)) && flag == true){
         flag =false;
        errorMsg = "Please enter a valid amount to transfer.";
    }
    if ((tAmt.toFloat() > bankApp->getCurrentCustomer()->getBalance()) && flag == true){
        flag = false;
        errorMsg = "Transfer amount exceeded your current balance!\nPlease re-enter a valid amount to transfer.";
    }

    if (flag == true){
        std::optional<Customer> recipent = cReader.searchByUsername(tName.toStdString());
        if (recipent){
            int result = transactHandler.transfer(*bankApp->getCurrentCustomer(),*recipent,tAmt.toFloat());
            if (result == TRANSACTION_FAILURE){
                errorMsg = "Transaction Failed, Please try again.";
            }
            if (result == TRANSACTION_LOG_FAILURE){
                errorMsg = "Transaction Failed, Please try again later.";
            }
            if (result == TRANSACTION_SUCCESS){
                msgBox.setText("You have successfully send <"+ tName +"> <$"+ tAmt + ">\nMoving back to main menu...");
                msgBox.exec();

                std::optional<Customer> updateCustomer = cReader.searchByUsername(bankApp->getCurrentCustomer()->getUsername());
                bankApp->setCurrentCustomer(updateCustomer);

                ui->transferAmnt->clear();
                ui->transferName->clear();
                emit menuClicked();
                return;
            }

        }
        errorMsg = "Recipent does not exist, please try again.";

    }

    msgBox.setText(errorMsg);
    msgBox.exec();
    return;

}

