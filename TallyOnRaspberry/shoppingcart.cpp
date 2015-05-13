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
