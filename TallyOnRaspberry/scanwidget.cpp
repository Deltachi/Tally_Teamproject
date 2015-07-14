//This widget will help the user to chose how many items he wants to buy.
#include "scanwidget.h"
#include "ui_scanwidget.h"
#include "shoppingcart.h"
#include "mainwindow.h"
#include <QDebug>
#include <QString>
//constructs the GUI
ScanWidget::ScanWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScanWidget)
{
    ui->setupUi(this);
    count = 0;
}
//deletes the object
ScanWidget::~ScanWidget()
{
    delete ui;
}
//this will init the Widget. *cartItems should be a pointer to a list with every Item in the shoppingcart. *item should be a pointer to the item which the user wants to buy.
void ScanWidget::setMainWindowPointer(QApplication *a,QList<QListWidgetItem> *cartItems,QString gUserId,QListWidgetItem *item){
    userId = gUserId;
    MainWindowPointer = a;
    Shoppingcart *cart = new Shoppingcart();
    cart->setMainWindowPointer(a,userId);
    ui->gridLayout_port->addWidget(cart);
    ui->listWidget->addItem(item);
    int loop = 0;
    while(cartItems->length() > loop){//this will update the new created shoppingcart.
        QListWidgetItem *temp = new QListWidgetItem();
        *temp = cartItems->at(loop);
        cart->addItem(temp);
        loop++;
    }
    updateAmountEveryItem();
}
//this will return the items from the shoppingcart.
QList<QListWidgetItem> ScanWidget::getItems(){
    Shoppingcart *temp = (Shoppingcart*)ui->gridLayout_port->itemAt(0)->widget();
    QList<QListWidgetItem> test = temp->getItems();
    return test;
}
//event handling if the user clicked the plus button
void ScanWidget::on_pushButton_plus_clicked()
{
    if(count < maxAmount){
        count++;
        ui->label_anzahl->setText(QString::number(count));
    }
    updateAmountEveryItem();
}
//event handling if the user clicked the minus button.
void ScanWidget::on_pushButton_minus_clicked()
{
    if(count > 0){
        count--;
        ui->label_anzahl->setText(QString::number(count));
    }
    updateAmountEveryItem();
}
//event handling if the user clicked the add button.
void ScanWidget::on_pushButton_add_clicked()
{
    ui->listWidget->item(0)->setData(6,count);
    if(count < 10){//this will change the text displayed by the item so that the shoppingcart will display the amount correctly.
        ui->listWidget->item(0)->setText(ui->listWidget->item(0)->text().insert(0,"x0" + QString::number(count) + " "));
    }else{
        ui->listWidget->item(0)->setText(ui->listWidget->item(0)->text().insert(0,"x" + QString::number(count) + " "));
    }
    Shoppingcart *temp = (Shoppingcart*)ui->gridLayout_port->itemAt(0)->widget();
    temp->addItem(ui->listWidget->item(0));
    MainWindowPointer->exit(51);
}
//this will check if the selected item exists in the shoppingcart. If yes, it will update the max amount the user can buy from this item so that the user can not buy more items than averiable.
void ScanWidget::updateAmountEveryItem(){
    MainWindow w;
    w.setWatchDog();
    if(ui->listWidget->item(0) != NULL){//do we have selected an item?
        Shoppingcart *tempCart = (Shoppingcart*)ui->gridLayout_port->itemAt(0)->widget();
        QList<QListWidgetItem> testList = tempCart->getItems();
        maxAmount = ui->listWidget->item(0)->data(6).toInt();
        for(int a=0;a<testList.length();a++){ //check every item id
            if(ui->listWidget->item(0)->data(4).toInt() == testList.at(a).data(4).toInt()){
                maxAmount = ui->listWidget->item(0)->data(6).toInt() - testList.at(a).data(6).toInt();
                if((maxAmount - count) == 1){
                    ui->listWidget->item(0)->setTextColor(QColor(255,51,51,255)); //red
                    ui->listWidget->item(0)->setHidden(false);
                }else if((maxAmount - count) > 1 && (maxAmount - count) <= 6){
                    ui->listWidget->item(0)->setTextColor(QColor(255,128,0,255)); //yellow
                    ui->listWidget->item(0)->setHidden(false);
                }else if((maxAmount - count) <= 0){
                    ui->listWidget->item(0)->setTextColor(QColor(255,0,0,100));
                }else{
                    ui->listWidget->item(0)->setTextColor(QColor(0,0,0,255)); //black
                    ui->listWidget->item(0)->setHidden(false);
                }
                break;
            }
        }
    }
}
