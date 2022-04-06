#include "history.h"
#include "ui_history.h"

History::History(BankingApp* bankApp, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::History)
{

    this->bankApp = bankApp;
    ui->setupUi(this);
}

History::~History()
{
    delete ui;
}

void History::on_back_clicked()
{
    ui->tableWidget->clear();
    emit menuClicked();
}

void History::updateScreenBalance(){
    //When deposit button is clicked, it will update its balance
    QString balance = QString::number(bankApp->getCurrentCustomer()->getBalance());
    ui->balance->display(balance);
}


void History::tableWidgetDisplay(){
    std::cout << "test" << std::endl;
    std::vector<Transaction> transaction = cReader.searchAllTransactions(bankApp->getCurrentCustomer()->getID());
    int rowCount = 0;

//    for (Transaction tract: transaction){
//        tract.printInfo();
//    }

    for (size_t i=0; i< transaction.size(); i++){
        //std::cout << transaction[79].getAmountReceived()  << std::endl;
        rowCount++;
    }


    QStringList headerLabels;
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setRowCount(rowCount);
    headerLabels  << "transactionDate" << "customerOut" << "customerIn" << "amountOut" << "amountIn" << "transType";
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);

    int reverseList = rowCount-1;
    for (size_t i=0; i< transaction.size(); i++){
        std::cout<< reverseList << std::endl;
        for (int j = 0; j < 6; j++){
            if (j == 0){
                Date tDate = transaction[reverseList].getTransactionDate();
                QString s = QString::fromStdString(tDate.getDateString());
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(s));
            }
            if (j ==1){
                int id1 = transaction[reverseList].getSenderID();
                if (id1 != -1){
                    QString s = QString::number(id1);
                    ui->tableWidget->setItem(i,j,new QTableWidgetItem(s));
                }
            }
            if (j == 2){
               int id2 = transaction[reverseList].getReceiverID();
               if (id2 != -1){
                   QString s = QString::number(id2);
                   ui->tableWidget->setItem(i,j,new QTableWidgetItem(s));
               }
            }
            if (j == 3){
                QString s = QString::number(transaction[reverseList].getAmountSent());
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(s));
            }
            if (j == 4){
                QString s = QString::number(transaction[reverseList].getAmountReceived());
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(s));
            }
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

