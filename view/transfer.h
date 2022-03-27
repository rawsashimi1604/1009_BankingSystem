#ifndef TRANSFER_H
#define TRANSFER_H

#include <QWidget>

namespace Ui {
class transfer;
}

class transfer : public QWidget
{
    Q_OBJECT

public:
    explicit transfer(QWidget *parent = nullptr);
    ~transfer();

private:
    Ui::transfer *ui;
};

#endif // TRANSFER_H
