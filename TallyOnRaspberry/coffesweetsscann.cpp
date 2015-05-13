#include "coffesweetsscann.h"
#include "ui_coffesweetsscann.h"

CoffeSweetsScann::CoffeSweetsScann(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CoffeSweetsScann)
{
    ui->setupUi(this);
}

CoffeSweetsScann::~CoffeSweetsScann()
{
    delete ui;
}

void CoffeSweetsScann::on_pushButton_coffee_clicked()
{
    mainWindowPointer->exit(31);
}

void CoffeSweetsScann::on_pushButton_sweets_clicked()
{
    mainWindowPointer->exit(32);
}

void CoffeSweetsScann::on_pushButton_scan_clicked()
{
    mainWindowPointer->exit(33);
}
void CoffeSweetsScann::setMainWindowPointer(QApplication *a){
    mainWindowPointer = a;
}
void CoffeSweetsScann::setQWidget(QWidget *a){
    QLayoutItem *oldItem = ui->gridLayout_port->itemAt(0);
    if(oldItem != NULL){ //delete old widget
        QWidget *oldWidget = oldItem->widget();
        ui->gridLayout_port->removeWidget(oldWidget);
        oldWidget->setVisible(false);
        delete oldWidget;
    }
    ui->gridLayout_port->addWidget(a);
}
