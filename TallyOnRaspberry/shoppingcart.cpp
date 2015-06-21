#include "shoppingcart.h"
#include "ui_shoppingcart.h"
#include <QDebug>
#include <QString>
#include "mainwindow.h"

Shoppingcart::Shoppingcart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shoppingcart)
{
    ui->setupUi(this);
}

Shoppingcart::~Shoppingcart()
{
    delete ui;
}
bool Shoppingcart::isEmpyt(){
    if(ui->listWidget->count() <= 0){
        return true;
    }else{
        return false;
    }
}
void Shoppingcart::updatePrice(){
    int loop = 0;
    QListWidgetItem *tempItem;
    price = 0;
    while(ui->listWidget->item(loop) != NULL){
       tempItem = ui->listWidget->item(loop);
       price = price + tempItem->data(5).toDouble();
       loop++;
    }
    QString tempString = QString::number(price);
    ui->label_2->setText(tempString);
}

void Shoppingcart::on_pushButton_back_clicked()
{
    MainWindowPointer->exit(51);
}
void Shoppingcart::addSomething(QString text){
    QListWidgetItem *item = new QListWidgetItem();
    item->setData(0,1);
    item->setText(text);
    ui->listWidget->addItem(item);
}
void Shoppingcart::addItem(QListWidgetItem *item){
    QListWidgetItem *tempItem = new QListWidgetItem();
    *tempItem = *item;
    ui->listWidget->addItem(tempItem);
    updatePrice();
}

QList<QListWidgetItem> Shoppingcart::getItems(){
    QList<QListWidgetItem> itemList;
    int loop = 0;
    while(ui->listWidget->item(loop) != NULL){
       itemList.append(*(ui->listWidget->item(loop)));
       QString Text = itemList.at(loop).text();
       loop++;
    }
    return itemList;
}
void Shoppingcart::setMainWindowPointer(QApplication *a,QString gUserId){
    MainWindowPointer = a;
    userId = gUserId;

}
void Shoppingcart::clear(){
    ui->listWidget->clear();
}
void Shoppingcart::disableBackButton(){
    ui->pushButton_back->setEnabled(false);
}

void Shoppingcart::on_listWidget_itemClicked(QListWidgetItem *item)
{
    delete item;
    updatePrice();
}

void Shoppingcart::on_pushButton_buy_clicked()
{
    Data = QSqlDatabase::addDatabase("QSQLITE");
    Database_Link
    Data.open();
    SqlZugriff Database;
    Database.getCredit(userId);
    QString credits;
    credits = Database.getString(0);
    if(credits != NULL){
        if(credits.toDouble() >= price){
            Database.updateCredits(userId,QString::number(credits.toDouble()-price));
            Data.close();
            MainWindowPointer->exit(99);
        }else{
            qDebug() << "Not enough money";
        }
    }
    Data.close();
}
