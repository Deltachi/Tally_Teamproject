#include "buywidget.h"
#include "ui_buywidget.h"
#include <QDebug>
#include <QString>
#include "sqlzugriff.h"

buywidget::buywidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::buywidget)
{
    ui->setupUi(this);

    Data = QSqlDatabase::addDatabase("QSQLITE");
    Data.setDatabaseName("/home/pi/TallyProject/Tally_Teamproject/SQLite/database.sqlite");
}

buywidget::~buywidget()
{
    delete ui;
}
void buywidget::removeWidget(){

    QLayoutItem *oldItem = ui->gridLayout_port->itemAt(0);
    if(oldItem != NULL){
        QWidget *oldWidget = oldItem->widget();
        ui->gridLayout_port->removeWidget(oldWidget);
        oldWidget->setVisible(false);
        delete oldWidget;
    }
}
void buywidget::setMainWindowPointer(QApplication *a,QList<QListWidgetItem> *cartItems,bool gSweetsActive,QString gUserId){
    userId = gUserId;
    sweetsActive = gSweetsActive;
    removeWidget();
    Shoppingcart *cart = new Shoppingcart();
    cart->setMainWindowPointer(a,userId);
    ui->gridLayout_port->addWidget(cart);
    int loop = 0;
    while(cartItems->length() > loop){
        QListWidgetItem *temp = new QListWidgetItem();
        *temp = cartItems->at(loop);
        cart->addItem(temp);
        loop++;
    }
    update_label();
}
QList<QListWidgetItem> buywidget::getItems(){
    Shoppingcart *temp = (Shoppingcart*)ui->gridLayout_port->itemAt(0)->widget();
    QList<QListWidgetItem> test = temp->getItems();
    return test;
}

void buywidget::update_label(){
    ui->listWidget->clear();
    Data.open();
    SqlZugriff Database;
    Database.initGetGroceries(sweetsActive);
    QString tmp;
    while(Database.next()){
        QListWidgetItem *item = new QListWidgetItem();
        item->setIcon(Database.getPixmap());
        item->setText(Database.getString(2));
        item->setData(4,Database.getString(0).toInt());
        item->setData(5,Database.getString(6).toDouble());
        ui->listWidget->addItem(item);
    }
    Data.close();

}

void buywidget::on_listWidget_itemClicked(QListWidgetItem *item)
{
    Shoppingcart *temp = (Shoppingcart*)ui->gridLayout_port->itemAt(0)->widget();
    temp->addItem(item);
}
