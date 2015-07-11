#ifndef FAVCART_H
#define FAVCART_H

#include <QWidget>
#include <QListWidgetItem>
#include <QtSql>
#include <QFileInfo>
#include "shoppingcart.h"

namespace Ui {
class FavCart;
}

class FavCart : public QWidget
{
    Q_OBJECT

public:
    explicit FavCart(QWidget *parent = 0);
    ~FavCart();
    QListWidgetItem *getSelectedItem();
    void updateItems();
    void setMainWindowPointer(QApplication *a,QString gUserId);
    void linkToShoppingCart(Shoppingcart *gCart);
    void removeOneItemFromId(int id);
    void lookAtItemsInShoppingcart();

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::FavCart *ui;
    QString userId;
    QSqlDatabase Data;
    QListWidgetItem *selectedItem;
    QApplication *MainWindowPointer;
    Shoppingcart *myShoppingCart;
};

#endif // FAVCART_H
