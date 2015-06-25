#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QWidget>
#include <QListWidgetItem>
#include "sqlzugriff.h"
#include <QtDebug>
#include <QtSql>
#include <QFileInfo>

namespace Ui {
class Shoppingcart;
}

class Shoppingcart : public QWidget
{
    Q_OBJECT

public:
    explicit Shoppingcart(QWidget *parent = 0);
    ~Shoppingcart();
    bool isEmpyt();
    void setMainWindowPointer(QApplication *a,QString gUserId);
    void addSomething(QString text);
    void clear();
    QList<QListWidgetItem> getItems();
    void addItem(QListWidgetItem *item);
    void disableBackButton();
    void updatePrice();
    int getLatestDeletedItemId();

private slots:
    void on_pushButton_back_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_buy_clicked();

private:
    Ui::Shoppingcart *ui;
    QApplication *MainWindowPointer;
    double price;
    QSqlDatabase Data;
    QString userId;
    int latestDeletedItemId;
    bool hasEnoughCredit(QString userId,double price);
};

#endif // SHOPPINGCART_H
