//This widget will show the favcart and the shoppingcart together, and init them correctly.
#include "favwidget.h"
#include "ui_favwidget.h"
#include "favcart.h"
#include "shoppingcart.h"
#include <QDebug>
//constructs the gui
FavWidget::FavWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FavWidget)
{
    ui->setupUi(this);
}
//delete the object
FavWidget::~FavWidget()
{
    delete ui;
}
//this inits the object. *item will be directly added to the shoppingcart.
void FavWidget::setMainWindowPointer(QApplication *a,QString userId,QListWidgetItem *item){
    MainWindowPointer = a;
    Shoppingcart *sCart = new Shoppingcart();
    FavCart *fCart = new FavCart();
    sCart->setMainWindowPointer(a,userId);
    fCart->setMainWindowPointer(a,userId);
    fCart->updateItems();
    sCart->addItem(item);
    fCart->linkToShoppingCart(sCart);
    fCart->removeOneItemFromId(item->data(4).toInt());
    ui->horizontalLayout->addWidget(sCart);
    ui->horizontalLayout->addWidget(fCart);
}
//this will return the items from the shoppingcart
QList<QListWidgetItem> FavWidget::getItems(){
    Shoppingcart *temp = (Shoppingcart*)ui->horizontalLayout->itemAt(0)->widget();
    QList<QListWidgetItem> test = temp->getItems();
    return test;
}
//this will force the favcart to update its amount if an item from the shoppingcart was deleted
void FavWidget::forceFavCartUpdate(){
    FavCart *fCart = (FavCart*)ui->horizontalLayout->itemAt(1)->widget();
    fCart->lookAtItemsInShoppingcart();
}
