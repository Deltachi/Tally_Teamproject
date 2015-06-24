#include "coffesweetsscann.h"
#include "ui_coffesweetsscann.h"
#include <QDebug>
#include <QString>
#include "mainwindow.h"

CoffeSweetsScann::CoffeSweetsScann(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CoffeSweetsScann)
{
    ui->setupUi(this);
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

void CoffeSweetsScann::on_pushButton_scan_clicked()
{
    MainWindow w;
    w.setWatchDog();
    mainWindowPointer->exit(33);
}
void CoffeSweetsScann::setMainWindowPointer(QApplication *a,QString gUserId){
    mainWindowPointer = a;
    userId = gUserId;
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
Shoppingcart *CoffeSweetsScann::getShoppingcart(){
    QLayoutItem *temp = ui->gridLayout_port->itemAt(0);
    return (Shoppingcart*)temp->widget();
}
