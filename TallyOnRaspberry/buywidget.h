#ifndef BUYWIDGET_H
#define BUYWIDGET_H

#include <QWidget>
#include "shoppingcart.h"
#include <QListWidgetItem>
#include "sqlzugriff.h"

namespace Ui {
class buywidget;
}

class buywidget : public QWidget
{
    Q_OBJECT

public:
    explicit buywidget(QWidget *parent = 0);
    ~buywidget();
    void removeWidget();
    void setMainWindowPointer(QApplication *a,QList<QListWidgetItem> *cartItems,bool gSweetsActive);
    QList<QListWidgetItem> getItems();
    void update_label();

private slots:

private:
    Ui::buywidget *ui;
    QSqlDatabase Data;
    bool sweetsActive;
};

#endif // BUYWIDGET_H
