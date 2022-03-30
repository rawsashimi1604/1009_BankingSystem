#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QWidget>

namespace Ui {
class Deposit;
}

class Deposit : public QWidget
{
    Q_OBJECT

public:
    explicit Deposit(QWidget *parent = nullptr);
    ~Deposit();

private:
    Ui::Deposit *ui;

signals:
    void menuClicked();


private slots:
    void on_back_clicked();
};

#endif // DEPOSIT_H
