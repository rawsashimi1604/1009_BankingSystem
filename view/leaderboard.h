#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <QWidget>

namespace Ui {
class Leaderboard;
}

class Leaderboard : public QWidget
{
    Q_OBJECT

public:
    explicit Leaderboard(QWidget *parent = nullptr);
    ~Leaderboard();

private slots:
    void on_back_clicked();

private:
    Ui::Leaderboard *ui;

signals:
    void menuClicked();
};



#endif // LEADERBOARD_H
