#include "deposit.h"
#include "ui_deposit.h"

/**
 * Constructs Deposit object which sets up the UI with parent and bankApp pointer
 *
 * @param parent ->  pointer that points to the Qwidget object
 * @param bankApp -> pointer that points BankingApp object 
 *
 */

Deposit::Deposit(BankingApp* bankApp, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Deposit)
{

    this->bankApp = bankApp;
    ui->setupUi(this);
    setWindowTitle(QString::fromStdString(bankApp->APPLICATION_NAME));
    QCoreApplication::setApplicationName(QString::fromStdString(bankApp->APPLICATION_NAME));
}

/**
 * Destructor for Deposit object
 *
 * @param None
 *
 */
Deposit::~Deposit()
{
    delete ui;
}

/**
 * Detect click on the back button
 *
 * @param None
 *
 */
void Deposit::on_back_clicked()
{
    emit menuClicked();
}

/**
 * Detect click for the back button
 *
 * @param None
 * @return None
 *
 */
void Deposit::updateScreenBalance(){
    //When deposit button is clicked, it will update its balance
    QString balance = QString::number(bankApp->getCurrentCustomer()->getBalance());
    ui->balance->display(balance);
}

/**
 * Function that detect click for the Confirm Deposit button that includes logic to check user input
 * It will show a dialog box if it detects error in the user input
 *
 * @param None
 *
 */
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

