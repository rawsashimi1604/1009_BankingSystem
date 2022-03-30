#ifndef WITHDRAW_H
#define WITHDRAW_H

#include <iostream>
#include <QWidget>

namespace Ui {
class Withdraw;
}

class Withdraw : public QWidget
{
    Q_OBJECT

public:
    explicit Withdraw(QWidget *parent = nullptr);
    ~Withdraw();

private slots:
    void on_back_clicked();

private:
    Ui::Withdraw *ui;

signals:
    void menuClicked();

};

#endif // WITHDRAW_H
