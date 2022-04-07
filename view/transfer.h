#ifndef TRANSFER_H
#define TRANSFER_H

#include <QtWidgets>
#include "bankingapp.h"
#include "controller/transactionreader.h"
#include "controller/transactionhandler.h"
#include "utils.h"



namespace Ui {
class Transfer;
}



class Transfer : public QWidget
{
    Q_OBJECT

private:
    Ui::Transfer *ui;
    BankingApp* bankApp;
    QMessageBox  msgBox;
    CredentialsReader cReader;
    TransactionHandler transactHandler;

public:
    explicit Transfer(BankingApp* bankApp, QWidget *parent = nullptr);
    ~Transfer();
    void updateScreenBalance();


signals:
    void menuClicked();

private slots:
    void on_back_clicked();
    void on_cfmTransfer_clicked();
};

#endif // TRANSFER_H
