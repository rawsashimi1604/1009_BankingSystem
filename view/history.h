#ifndef HISTORY_H
#define HISTORY_H

#include <QWidget>

namespace Ui {
class History;
}

class History : public QWidget
{
    Q_OBJECT

public:
    explicit History(QWidget *parent = nullptr);
    ~History();

private:
    Ui::History *ui;

signals:
    void menuClicked();
private slots:
    void on_back_clicked();
};

#endif // HISTORY_H
