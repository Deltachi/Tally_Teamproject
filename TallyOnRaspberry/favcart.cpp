//this is a widget which displays the users favorites. The user can pick one and an exit code will be thrown.
#include "favcart.h"
#include "ui_favcart.h"
#include <QDebug>
#include <QString>
#include "mainwindow.h"
#include "shoppingcart.h"
//constructs the GUI
FavCart::FavCart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FavCart)
{
    ui->setupUi(this);
    myShoppingCart = NULL;
}
//deletes the object
FavCart::~FavCart()
{
    delete ui;
}
//inits the object
void FavCart::setMainWindowPointer(QApplication *a,QString gUserId){
    MainWindowPointer = a;
    userId = gUserId;
}
//This links the favcart to the shoppingcart. If the favcart was clicked it can directly tell the shoppingcart to add that item.
void FavCart::linkToShoppingCart(Shoppingcart *gCart){
    myShoppingCart = gCart;
}
//This will refresh the favcart items. It will not check if some items are already in the shoppingcart!
void FavCart::updateItems(){
    Data = QSqlDatabase::addDatabase("QSQLITE");
    Database_Link
    Data.open();
    SqlZugriff Database;
    Database.getPicturePath();
    Database.selectFavorites(userId);

    QString tmp;
    while(Database.next()){ //get next favorite from database
        int amount = Database.getString(9).toInt();
        if(amount > 0){
            QListWidgetItem *item = new QListWidgetItem();
            item->setIcon(Database.getPixmap(12));
            tmp = Database.getString(7) + " " + Database.getString(10) + QChar(8364);
            item->setText(tmp);
            item->setData(4,Database.getString(2).toInt());
            item->setData(5,Database.getString(10).toDouble());
            item->setData(6,amount);
            if(amount == 1){
                item->setTextColor(QColor(255,51,51,255)); //red
            }else if(amount > 1 && amount <= 6){
                item->setTextColor(QColor(255,128,0,255)); //yellow
            }else if(amount == 0){
                item->setHidden(true);
            }else{
                item->setTextColor(QColor(0,0,0,255)); //black
            }
            ui->listWidget->addItem(item);
        }
    }
    Data.close();
}
//if an item was removed from the shoppingcart this will update the favorites list.
void FavCart::lookAtItemsInShoppingcart(){
    int itemId = myShoppingCart->getLatestDeletedItemId();
    for(int i=0;i<ui->listWidget->count();i++){ //search for the deleted item and update the amount!
        if(ui->listWidget->item(i)->data(4).toInt()==itemId){
            Data = QSqlDatabase::addDatabase("QSQLITE");
            Database_Link
            Data.open();
            SqlZugriff Database;
            Database.getAmount(QString::number(itemId));
            int amount = Database.getString(0).toInt();
            Data.close();
            ui->listWidget->item(i)->setHidden(false);
            ui->listWidget->item(i)->setData(6,amount);
            if(amount == 1){
                ui->listWidget->item(i)->setTextColor(QColor(255,51,51,255)); //red
            }else if(amount > 1 && amount <= 6){
                ui->listWidget->item(i)->setTextColor(QColor(255,128,0,255)); //yellow
            }else if(amount == 0){
                ui->listWidget->item(i)->setHidden(true);
            }else{
                ui->listWidget->item(i)->setTextColor(QColor(0,0,0,255)); //black
            }
            break;
        }
    }
}
//this will remove an item with that id from the favcart.
void FavCart::removeOneItemFromId(int id){
    for(int i = 0; i < ui->listWidget->count();i++){
        if(ui->listWidget->item(i)->data(4).toInt() == id){
            ui->listWidget->item(i)->setData(6,ui->listWidget->item(i)->data(6).toInt()-1);
            int amount = ui->listWidget->item(i)->data(6).toInt();
            if(amount == 1){
                ui->listWidget->item(i)->setTextColor(QColor(255,51,51,255)); //red
            }else if(amount > 1 && amount <= 6){
                ui->listWidget->item(i)->setTextColor(QColor(255,128,0,255)); //yellow
            }else if(amount == 0){
                ui->listWidget->item(i)->setHidden(true);
            }else{
                ui->listWidget->item(i)->setTextColor(QColor(0,0,0,255)); //black
            }
            break;
        }
    }
}
//This will get the latest selected item from the favcart.
QListWidgetItem *FavCart::getSelectedItem(){
    return selectedItem;
}
//event handling for an clicked item in the favcart
void FavCart::on_listWidget_itemClicked(QListWidgetItem *item)
{
    if(item->data(6).toInt() > 0){
        if(myShoppingCart == NULL){//is there a link to the shoppingcart?
            selectedItem = item;
            MainWindowPointer->exit(35);
        }else{
            QListWidgetItem tempItem = *item;
            tempItem.setData(6,1);
            tempItem.setText("x01 " + tempItem.text());
            myShoppingCart->addItem(&tempItem);
            int amount = item->data(6).toInt() - 1;
            item->setData(6,amount);
            if(amount == 1){
                item->setTextColor(QColor(255,51,51,255)); //red
            }else if(amount > 1 && amount <= 6){
                item->setTextColor(QColor(255,128,0,255)); //yellow
            }else if(amount == 0){
                item->setHidden(true);
            }else{
                item->setTextColor(QColor(0,0,0,255)); //black
            }
        }
    }
}
