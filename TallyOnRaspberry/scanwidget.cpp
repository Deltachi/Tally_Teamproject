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
void ScanWidget::setMainWindowPointer(QApplication *a,QList<QListWidgetItem> *cartItems){
    MainWindowPointer = a;
    Shoppingcart *cart = new Shoppingcart();
    cart->setMainWindowPointer(a);
    ui->gridLayout_port->addWidget(cart);
}
