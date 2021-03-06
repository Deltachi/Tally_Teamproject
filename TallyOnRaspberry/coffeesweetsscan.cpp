//This widget is like the main menue if you are logged in.
#include "coffesweetsscann.h"
#include "ui_coffesweetsscann.h"
#include <QDebug>
#include <QString>
#include <QProcess>
#include "mainwindow.h"
#include "favcart.h"
//builds the GUI
CoffeSweetsScann::CoffeSweetsScann(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CoffeSweetsScann)
{
    ui->setupUi(this);
    ui->pushButton_preferences->setHidden(true);
}
//deletes the widget
CoffeSweetsScann::~CoffeSweetsScann()
{
    delete ui;
}
//event handling if user clicked coffee
void CoffeSweetsScann::on_pushButton_coffee_clicked()
{
    MainWindow w;
    w.setWatchDog();
    mainWindowPointer->exit(31);
}
//event handling if user clicked sweets
void CoffeSweetsScann::on_pushButton_sweets_clicked()
{
    MainWindow w;
    w.setWatchDog();
    mainWindowPointer->exit(32);
}
//this inits the widget.
void CoffeSweetsScann::setMainWindowPointer(QApplication *a,QString gUserId){
    mainWindowPointer = a;
    userId = gUserId;

    Data = QSqlDatabase::addDatabase("QSQLITE");
    Database_Link
    Data.open();
    SqlZugriff Database;
    Database.initGetUser(userId);
    if(Database.getString(11).toInt() == 4){//is the user an admin? Then show the settings button =)
        ui->pushButton_preferences->setHidden(false);
    }else{
        ui->pushButton_preferences->setHidden(true);
    }
    Data.close();
}
//adds a widget to the Fav/Shoppingcart slot. You should add a Favcart or a Shoppingcart with this function ;)
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
//enables or disables the back button.
void CoffeSweetsScann::enableBackButtonOnShoppingcart(bool enable){
    Shoppingcart *cart = (Shoppingcart*)ui->gridLayout_port->itemAt(0);
    cart->disableBackButton();
}
//this will get the selected item from the favcart. This only works if the favcart is active!
QListWidgetItem *CoffeSweetsScann::getFavSelectedItem(){
    FavCart *fCart = (FavCart*)ui->gridLayout_port->itemAt(0)->widget();
    return fCart->getSelectedItem();
}
//this will return a pointer to the active shoppingcart. If the shoppingcart is not active it will return NULL.
Shoppingcart *CoffeSweetsScann::getShoppingcart(){
    QLayoutItem *temp = ui->gridLayout_port->itemAt(0);
    return (Shoppingcart*)temp->widget();
}
//event handling for the preferences button.
void CoffeSweetsScann::on_pushButton_preferences_clicked()
{
    mainWindowPointer->exit(36);
}
