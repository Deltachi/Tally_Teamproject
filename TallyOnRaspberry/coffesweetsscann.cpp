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
