#include "title.h"
#include "ui_title.h"

Title::Title(BankingApp* bankApp, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Title),
    login(bankApp),
    reg(bankApp)
{
    this->bankApp = bankApp;
    ui->setupUi(this);
    setWindowTitle(QString::fromStdString(bankApp->APPLICATION_NAME));
    QCoreApplication::setApplicationName(QString::fromStdString(bankApp->APPLICATION_NAME));
    ui->stackedWidget->insertWidget(1,&reg);
    ui->stackedWidget->insertWidget(2,&login);
    connect(&reg,SIGNAL(menuClicked()),this,SLOT(moveMenu()));
    connect(&login,SIGNAL(menuClicked()),this,SLOT(moveMenu()));

}

Title::~Title()
{
    delete ui;
}

void Title::on_createAcc_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void Title::on_login_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Title::moveMenu(){
     ui->stackedWidget->setCurrentIndex(0);
}

