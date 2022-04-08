#include "history.h"
#include "ui_history.h"

/**
 * Constructs History object which sets up the UI with parent and bankApp pointer
 *
 * @param parent ->  pointer that points to the Qwidget object
 * @param bankApp -> pointer that points BankingApp object
 *
 */
History::History(BankingApp* bankApp, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::History)
{

    this->bankApp = bankApp;
    ui->setupUi(this);
    setWindowTitle(QString::fromStdString(bankApp->APPLICATION_NAME));
    QCoreApplication::setApplicationName(QString::fromStdString(bankApp->APPLICATION_NAME));

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

/**
 * Destructor for History object
 *
 * @param None
 *
 */
History::~History()
{
    delete ui;
}

/**
 * Detect click on the back button
 *
 * @param None
 * @return None
 *
 */
void History::on_back_clicked()
{
    ui->tableWidget->clear();
    emit menuClicked();
}

/**
 * Detect click for the back button
 *
 * @param None
 * @return None
 *
 */
void History::updateScreenBalance(){
    //When deposit button is clicked, it will update its balance
    QString balance = QString::number(bankApp->getCurrentCustomer()->getBalance());
    ui->balance->display(balance);
}

/**
 * Displays all the transactions related to the customer on the table 
 *
 * @param None
 * @return None
 *
 */
void History::tableWidgetDisplay(){
    std::vector<Transaction> transaction = tReader.searchAllTransactions(bankApp->getCurrentCustomer()->getID());
    int rowCount = 0;

//    for (Transaction tract: transaction){
//        tract.printInfo();
//    }

    for (size_t i=0; i< transaction.size(); i++){
        //std::cout << transaction[79].getAmountReceived()  << std::endl;
        rowCount++;
    }


    QStringList headerLabels;
    //Sets headers for the table
    headerLabels  << "transactionDate" << "customerOut" << "customerIn" << "amountOut" << "amountIn" << "transType";
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
    
    //Sets the number of column to 6 and Rows which match the number of transactions the users made
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setRowCount(rowCount);

    //Reverses the transactions list to show the most recent transactions first 
    int reverseList = rowCount-1;
    for (size_t i=0; i< transaction.size(); i++){
        std::cout<< reverseList << std::endl;
        for (int j = 0; j < 6; j++){
            //Inserts Dates for Date column
            if (j == 0){
                Date tDate = transaction[reverseList].getTransactionDate();
                QString s = QString::fromStdString(tDate.getDateString());
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(s));
            } 
            //Inserts Sender Name for CustomerOut column
            if (j ==1){
                int id1 = transaction[reverseList].getSenderID();
                if (id1 != -1){
                    std::optional<Customer> cust =  cReader.searchByID(id1);
                    QString s = QString::fromStdString(cust->getUsername());
                    ui->tableWidget->setItem(i,j,new QTableWidgetItem(s));
                }
            }
            //Inserts Reciever Name for CustomerOut column
            if (j == 2){
               int id2 = transaction[reverseList].getReceiverID();
               if (id2 != -1){
                   std::optional<Customer> cust =  cReader.searchByID(id2);
                   QString s = QString::fromStdString(cust->getUsername());
                   ui->tableWidget->setItem(i,j,new QTableWidgetItem(s));
               }
            }
            //Inserts the Amount that is deducted from the user account for AmountOut column
            if (j == 3){
                QString s = QString::number(transaction[reverseList].getAmountSent());
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(s));
            }
            //Inserts the Amount that is deducted from the user account for AmountOut column
            if (j == 4){
                QString s = QString::number(transaction[reverseList].getAmountReceived());
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(s));
            }
            //Inserts the Transaction type for Transactions column
            if (j == 5){
                std::string tType = Enums::convertString(transaction[reverseList].getTransactionType());
                QString s = QString::fromStdString(tType);
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(s));
            }
        }
        reverseList--;
    }

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);     //Disable edit for the table
}

