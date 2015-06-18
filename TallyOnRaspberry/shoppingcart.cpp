#include "shoppingcart.h"
#include "ui_shoppingcart.h"
#include <QDebug>
#include <QString>

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
    if(kosten == NULL){
        kosten = 0;
    }
    kosten = tempItem->data(5).toDouble() + kosten;
    QString test = QString::number(kosten);
    ui->label_2->setText(test);
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
void Shoppingcart::setMainWindowPointer(QApplication *a){
    MainWindowPointer = a;
}
void Shoppingcart::clear(){
    ui->listWidget->clear();
}
void Shoppingcart::disableBackButton(){
    ui->pushButton_back->setEnabled(false);
}
