#include "mainmenue.h"
#include "ui_mainmenue.h"

MainMenue::MainMenue(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenue)
{
    ui->setupUi(this);
}

MainMenue::~MainMenue()
{
    delete ui;
}
