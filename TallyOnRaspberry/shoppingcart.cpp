#include "shoppingcart.h"
#include "ui_shoppingcart.h"

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

void Shoppingcart::setMainWindowPointer(QApplication *a){
    MainWindowPointer = a;
}
void Shoppingcart::clear(){
    ui->listWidget->clear();
}
