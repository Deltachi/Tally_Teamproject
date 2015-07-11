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
       price = price + (tempItem->data(5).toDouble() * tempItem->data(6).toInt());
       loop++;
    }
    QString tempString = QString::number(price);
    ui->label_2->setText(tempString);
    if(hasEnoughCredit(userId,price)){
        QPalette palette = ui->label_2->palette();
        palette.setColor(ui->label_2->backgroundRole(), Qt::yellow);
        palette.setColor(ui->label_2->foregroundRole(), Qt::black);
        ui->label_2->setPalette(palette);
    }else{
        QPalette palette = ui->label_2->palette();
        palette.setColor(ui->label_2->backgroundRole(), Qt::yellow);
        palette.setColor(ui->label_2->foregroundRole(), Qt::red);
        ui->label_2->setPalette(palette);
    }
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
    MainWindow w;
    w.setWatchDog();
}
void Shoppingcart::addItem(QListWidgetItem *item){
    MainWindow w;
    w.setWatchDog();
    bool found = false;
    int i;
    for(i = 0; i < ui->listWidget->count(); ++i) {
        if(ui->listWidget->item(i)->data(4).toInt() == item->data(4).toInt()) {
            found = true;
            break;
        }
    }
    if(found){
        int count = ui->listWidget->item(i)->data(6).toInt() + item->data(6).toInt();
        QString newText = ui->listWidget->item(i)->text();
        newText.remove(1,2);
        if(count >= 10){
            newText.insert(1,QString::number(count));
        }else{
            newText.insert(1,"0" + QString::number(count));
        }
        ui->listWidget->item(i)->setData(6,count);
        ui->listWidget->item(i)->setText(newText);
    }else{
        QListWidgetItem *tempItem = new QListWidgetItem();
        tempItem->setData(4,item->data(4));
        tempItem->setData(5,item->data(5));
        tempItem->setData(6,item->data(6));
        tempItem->setText(item->text());
        tempItem->setTextColor(QColor(0,0,0,255));
        ui->listWidget->addItem(tempItem);
    }
    updatePrice();
}

QList<QListWidgetItem> Shoppingcart::getItems(){
    QList<QListWidgetItem> itemList;
    int loop = 0;
    while(ui->listWidget->item(loop) != NULL){
       itemList.append(*(ui->listWidget->item(loop)));
       loop++;
    }
    return itemList;
}
void Shoppingcart::setMainWindowPointer(QApplication *a,QString gUserId){
    MainWindowPointer = a;
    userId = gUserId;

}
int Shoppingcart::getLatestDeletedItemId(){
    return latestDeletedItemId;
}
void Shoppingcart::clear(){
    ui->listWidget->clear();
}
void Shoppingcart::disableBackButton(){
    ui->pushButton_back->setEnabled(false);
}

void Shoppingcart::on_listWidget_itemClicked(QListWidgetItem *item)
{
    latestDeletedItemId = item->data(4).toInt();
    delete item;
    updatePrice();
    MainWindowPointer->exit(98);
}
bool Shoppingcart::hasEnoughCredit(QString userId,double price){
    Data = QSqlDatabase::addDatabase("QSQLITE");
    Database_Link
    Data.open();
    SqlZugriff Database;
    Database.getCredit(userId);
    QString credits = Database.getString(0);
    double maxOverdraw = Database.getMaxOverdrawValue();
    Data.close();
    if(credits.toDouble() - maxOverdraw >= price){
        return true;
    }
    return false;
}

void Shoppingcart::on_pushButton_buy_clicked()
{
    if(hasEnoughCredit(userId,price)){
        Data = QSqlDatabase::addDatabase("QSQLITE");
        Database_Link
        Data.open();
        SqlZugriff Database;
        Database.getCredit(userId);
        QString credits = Database.getString(0);
        Database.updateCredits(userId,QString::number(credits.toDouble()-price));

        int loop = 0;
        QListWidgetItem *tempItem;
        while(ui->listWidget->item(loop) != NULL){
            tempItem = ui->listWidget->item(loop);
            Database.getAmount(tempItem->data(4).toString());
            Database.updateAmount(tempItem->data(4).toString(),QString::number(Database.getString(0).toInt() - tempItem->data(6).toInt()));
            Database.addSell(userId,tempItem->data(4).toString(),tempItem->data(6).toString(),tempItem->data(5).toString());
            Database.updateConsumeIndex(userId,tempItem->data(4).toString(),tempItem->data(6).toString());
            loop++;
        }

        Data.close();
        MainWindowPointer->exit(99);
    }else{
        qDebug() << "Not enough money";
    }
}
