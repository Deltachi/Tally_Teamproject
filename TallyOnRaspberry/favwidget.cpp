#include "favwidget.h"
#include "ui_favwidget.h"
#include "favcart.h"
#include "shoppingcart.h"
#include <QDebug>

FavWidget::FavWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FavWidget)
{
    ui->setupUi(this);
}

FavWidget::~FavWidget()
{
    delete ui;
}
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
QList<QListWidgetItem> FavWidget::getItems(){
    Shoppingcart *temp = (Shoppingcart*)ui->horizontalLayout->itemAt(0)->widget();
    QList<QListWidgetItem> test = temp->getItems();
    return test;
}
void FavWidget::forceFavCartUpdate(){
    FavCart *fCart = (FavCart*)ui->horizontalLayout->itemAt(1)->widget();
    fCart->lookAtItemsInShoppingcart();
}
