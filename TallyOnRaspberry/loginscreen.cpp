#include "loginscreen.h"
#include "ui_loginscreen.h"
#include "mainmenue.h"

LoginScreen::LoginScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginScreen)
{
    ui->setupUi(this);
}

LoginScreen::~LoginScreen()
{
    delete ui;
}
void LoginScreen::setMainWindowPointer(QApplication *a){
    MainWindowPointer = a;
}

void LoginScreen::on_pushButton_clicked()
{
    MainWindowPointer->exit(10);
}
