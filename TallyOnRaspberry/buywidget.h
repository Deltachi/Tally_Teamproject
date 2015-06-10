#ifndef BUYWIDGET_H
#define BUYWIDGET_H

#include <QWidget>
#include "shoppingcart.h"
#include <QListWidgetItem>

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
    void setMainWindowPointer(QApplication *a,QList<QListWidgetItem> *cartItems);
    QList<QListWidgetItem> getItems();

private slots:

private:
    Ui::buywidget *ui;
};

#endif // BUYWIDGET_H
