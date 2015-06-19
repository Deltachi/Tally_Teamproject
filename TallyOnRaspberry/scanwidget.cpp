#include "scanwidget.h"
#include "ui_scanwidget.h"
#include "shoppingcart.h"

ScanWidget::ScanWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScanWidget)
{
    ui->setupUi(this);
}

ScanWidget::~ScanWidget()
{
    delete ui;
}
void ScanWidget::setMainWindowPointer(QApplication *a,QList<QListWidgetItem> *cartItems,QString gUserId){
    userId = gUserId;
    MainWindowPointer = a;
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
}
QList<QListWidgetItem> ScanWidget::getItems(){
    Shoppingcart *temp = (Shoppingcart*)ui->gridLayout_port->itemAt(0)->widget();
    QList<QListWidgetItem> test = temp->getItems();
    return test;
}
