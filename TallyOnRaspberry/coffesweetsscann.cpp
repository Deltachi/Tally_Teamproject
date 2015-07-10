#include "coffesweetsscann.h"
#include "ui_coffesweetsscann.h"
#include <QDebug>
#include <QString>
#include "mainwindow.h"
#include "favcart.h"

CoffeSweetsScann::CoffeSweetsScann(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CoffeSweetsScann)
{
    ui->setupUi(this);
    ui->pushButton_preferences->setHidden(true);
}

CoffeSweetsScann::~CoffeSweetsScann()
{
    delete ui;
}

void CoffeSweetsScann::on_pushButton_coffee_clicked()
{
    MainWindow w;
    w.setWatchDog();
    mainWindowPointer->exit(31);
}

void CoffeSweetsScann::on_pushButton_sweets_clicked()
{
    MainWindow w;
    w.setWatchDog();
    mainWindowPointer->exit(32);
}
void CoffeSweetsScann::setMainWindowPointer(QApplication *a,QString gUserId){
    mainWindowPointer = a;
    userId = gUserId;

    Data = QSqlDatabase::addDatabase("QSQLITE");
    Database_Link
    Data.open();
    SqlZugriff Database;
    Database.initGetUser(userId);
    if(Database.getString(11).toInt() == 4){
        ui->pushButton_preferences->setHidden(false);
    }else{
        ui->pushButton_preferences->setHidden(true);
    }
    Data.close();
}
void CoffeSweetsScann::setQWidget(QWidget *a){
    QLayoutItem *oldItem = ui->gridLayout_port->itemAt(0);
    if(oldItem != NULL){ //delete old widget
        QWidget *oldWidget = oldItem->widget();
        ui->gridLayout_port->removeWidget(oldWidget);
        oldWidget->setVisible(false);
        delete oldWidget;
    }
    ui->gridLayout_port->addWidget(a);
}
void CoffeSweetsScann::enableBackButtonOnShoppingcart(bool enable){
    Shoppingcart *cart = (Shoppingcart*)ui->gridLayout_port->itemAt(0);
    cart->disableBackButton();
}
QListWidgetItem *CoffeSweetsScann::getFavSelectedItem(){
    FavCart *fCart = (FavCart*)ui->gridLayout_port->itemAt(0)->widget();
    return fCart->getSelectedItem();
}
Shoppingcart *CoffeSweetsScann::getShoppingcart(){
    QLayoutItem *temp = ui->gridLayout_port->itemAt(0);
    return (Shoppingcart*)temp->widget();
}

void CoffeSweetsScann::on_pushButton_preferences_clicked()
{
    mainWindowPointer->exit(36);
}
