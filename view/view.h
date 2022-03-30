#ifndef VIEW_H
#define VIEW_H

#include <QWidget>

class View
{
public:
    View();

signals:
    void menuClicked();

private slots:
    void on_back_clicked();
};



#endif // VIEW_H
