#include "buywidget.h"
#include "ui_buywidget.h"

buywidget::buywidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::buywidget)
{
    ui->setupUi(this);
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
void buywidget::setMainWindowPointer(QApplication *a,QList<QListWidgetItem> *cartItems){
    removeWidget();
    Shoppingcart *cart = new Shoppingcart();
    cart->setMainWindowPointer(a);
    ui->gridLayout_port->addWidget(cart);
}
