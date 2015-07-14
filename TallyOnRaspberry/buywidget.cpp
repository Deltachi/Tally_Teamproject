//This widget is the sweets and the coffee widget. It has a list which displays all the buyable items and will send some exit codes if an item should be added to the shoppingcart
#include "buywidget.h"
#include "ui_buywidget.h"
#include <QDebug>
#include <QString>
#include "sqlzugriff.h"
#include "mainwindow.h"
//inits the GUI
buywidget::buywidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::buywidget)
{
    ui->setupUi(this);
}
//delets the Object
buywidget::~buywidget()
{
    delete ui;
}
//removes the Widget which was put into gridLayout_port
void buywidget::removeWidget(){

    QLayoutItem *oldItem = ui->gridLayout_port->itemAt(0);
    if(oldItem != NULL){
        QWidget *oldWidget = oldItem->widget();
        ui->gridLayout_port->removeWidget(oldWidget);
        oldWidget->setVisible(false);
        delete oldWidget;
    }
}
//inits the Widget. SweetsActive is used to say if this widget should just show sweets or just coffee. Cart items should contain every items which is in the shoppingcart.
void buywidget::setMainWindowPointer(QApplication *a,QList<QListWidgetItem> *cartItems,bool gSweetsActive,QString gUserId){
    userId = gUserId;
    sweetsActive = gSweetsActive;
    removeWidget();
    Shoppingcart *cart = new Shoppingcart();
    cart->setMainWindowPointer(a,userId);
    ui->gridLayout_port->addWidget(cart);
    int loop = 0;
    while(cartItems->length() > loop){//copy every item into the new shoppingcart
        QListWidgetItem *temp = new QListWidgetItem();
        *temp = cartItems->at(loop);
        cart->addItem(temp);
        loop++;
    }
    update_label();
}
//returns every item which was in the actual shoppingcart.
QList<QListWidgetItem> buywidget::getItems(){
    Shoppingcart *temp = (Shoppingcart*)ui->gridLayout_port->itemAt(0)->widget();
    QList<QListWidgetItem> test = temp->getItems();
    return test;
}
//Updates every grocery in the list.
void buywidget::update_label(){
    ui->listWidget->clear();
    Data = QSqlDatabase::addDatabase("QSQLITE");
    Database_Link
    Data.open();
    SqlZugriff Database;

    Database.getPicturePath();
    Database.initGetGroceries(sweetsActive);
    QString tmp;
    while(Database.next()){
        int amount = Database.getString(5).toInt();
        if(amount > 0){
            QListWidgetItem *item = new QListWidgetItem();
            item->setIcon(Database.getPixmap(3)); //get pixmap
            tmp = Database.getString(2) + " " + Database.getString(6) + QChar(8364); //get name
            item->setText(tmp);
            item->setData(4,Database.getString(0).toInt());//get the id
            item->setData(5,Database.getString(6).toDouble()); //get the price
            item->setData(6,amount); //and get the amount.
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
    updateAmountEveryItem();
}
//If an item was removed in the shoppincart it should be averiable in the buywidget.
void buywidget::updateAmount(){
    Shoppingcart *tempCart = (Shoppingcart*)ui->gridLayout_port->itemAt(0)->widget();
    for(int i=0;i<ui->listWidget->count();i++){
        if(ui->listWidget->item(i)->data(4).toInt() == tempCart->getLatestDeletedItemId()){
            Data = QSqlDatabase::addDatabase("QSQLITE");
            Database_Link
            Data.open();
            SqlZugriff Database;
            Database.getAmount(QString::number(tempCart->getLatestDeletedItemId()));
            int amount = Database.getString(0).toInt();
            Data.close();
            ui->listWidget->item(i)->setData(6,amount);
            if(amount == 1){
                ui->listWidget->item(i)->setTextColor(QColor(255,51,51,255)); //red
                ui->listWidget->item(i)->setHidden(false);
            }else if(amount > 1 && amount <= 6){
                ui->listWidget->item(i)->setTextColor(QColor(255,128,0,255)); //yellow
                ui->listWidget->item(i)->setHidden(false);
            }else if(amount == 0){
                ui->listWidget->item(i)->setHidden(true);
            }else{
                ui->listWidget->item(i)->setTextColor(QColor(0,0,0,255)); //black
                ui->listWidget->item(i)->setHidden(false);
            }
            break;
        }
    }
}
//looks into the shoppingcart and updates the amount from every items so that it will not show you already bought items.
void buywidget::updateAmountEveryItem(){
    Shoppingcart *tempCart = (Shoppingcart*)ui->gridLayout_port->itemAt(0)->widget();
    QList<QListWidgetItem> testList = tempCart->getItems();
    for(int a=0;a<testList.length();a++){
        for(int i=0;i<ui->listWidget->count();i++){
            if(ui->listWidget->item(i)->data(4).toInt() == testList.at(a).data(4).toInt()){
                int amount = ui->listWidget->item(i)->data(6).toInt() - testList.at(a).data(6).toInt();
                ui->listWidget->item(i)->setData(6,amount);
                if(amount == 1){
                    ui->listWidget->item(i)->setTextColor(QColor(255,51,51,255)); //red
                    ui->listWidget->item(i)->setHidden(false);
                }else if(amount > 1 && amount <= 6){
                    ui->listWidget->item(i)->setTextColor(QColor(255,128,0,255)); //yellow
                    ui->listWidget->item(i)->setHidden(false);
                }else if(amount == 0){
                    ui->listWidget->item(i)->setHidden(true);
                }else{
                    ui->listWidget->item(i)->setTextColor(QColor(0,0,0,255)); //black
                    ui->listWidget->item(i)->setHidden(false);
                }
                break;
            }
        }
    }
}
//event handling if an item was clicked
void buywidget::on_listWidget_itemClicked(QListWidgetItem *item)
{
    MainWindow w;
    w.setWatchDog();
    if(item->data(6).toInt() - 1 >= 0){ //change the item data so that the shoppingcart can use it.
        int backupInt = item->data(6).toInt() - 1;
        QString backupString = item->text();

        item->setData(6,1);
        item->setText(item->text().insert(0,"x01 "));
        Shoppingcart *temp = (Shoppingcart*)ui->gridLayout_port->itemAt(0)->widget();
        temp->addItem(item);

        item->setData(6,backupInt);
        item->setText(backupString);
        if(backupInt == 1){
            item->setTextColor(QColor(255,51,51,255)); //red
        }else if(backupInt > 1 && backupInt <= 6){
            item->setTextColor(QColor(255,128,0,255)); //yellow
        }else if(backupInt == 0){
            item->setHidden(true);
        }else{
            item->setTextColor(QColor(0,0,0,255)); //black
        }
    }else{
        //not so much items left
    }
}
