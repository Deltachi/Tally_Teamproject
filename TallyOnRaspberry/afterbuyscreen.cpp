//This widget just shows "success" and does nothing else =)
#include "afterbuyscreen.h"
#include "ui_afterbuyscreen.h"
AfterBuyScreen::AfterBuyScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AfterBuyScreen)
{
    ui->setupUi(this);
}

AfterBuyScreen::~AfterBuyScreen()
{
    delete ui;
}
