#include "scanwidget.h"
#include "ui_scanwidget.h"
#include "shoppingcart.h"

ScanWidget::ScanWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScanWidget)
{
    ui->setupUi(this);
    count = 0;
}

ScanWidget::~ScanWidget()
{
    delete ui;
}
void ScanWidget::setMainWindowPointer(QApplication *a,QList<QListWidgetItem> *cartItems,QString gUserId,QListWidgetItem *item){
    userId = gUserId;
    MainWindowPointer = a;
    Shoppingcart *cart = new Shoppingcart();
    cart->setMainWindowPointer(a,userId);
    ui->gridLayout_port->addWidget(cart);
    ui->listWidget->addItem(item);
    int loop = 0;
    while(cartItems->length() > loop){
        QListWidgetItem *temp = new QListWidgetItem();
        *temp = cartItems->at(loop);
        cart->addItem(temp);
        loop++;
    }
}
QList<QListWidgetItem> ScanWidget::getItems(){
    Shoppingcart *temp = (Shoppingcart*)ui->gridLayout_port->itemAt(0)->widget();
    QList<QListWidgetItem> test = temp->getItems();
    return test;
}

void ScanWidget::on_pushButton_plus_clicked()
{
    if(count < ui->listWidget->item(0)->data(6).toInt()){
        count++;
        ui->label_anzahl->setText(QString::number(count));
    }
}

void ScanWidget::on_pushButton_minus_clicked()
{
    if(count > 0){
        count--;
        ui->label_anzahl->setText(QString::number(count));
    }
}
