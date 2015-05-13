#include "favcart.h"
#include "ui_favcart.h"

FavCart::FavCart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FavCart)
{
    ui->setupUi(this);
}

FavCart::~FavCart()
{
    delete ui;
}
