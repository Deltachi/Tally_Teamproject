#include "loginscreen.h"
#include "ui_loginscreen.h"
#include "mainmenue.h"
#include <QDebug>
#include <QFileInfo>
#include <QString>

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
    if(ui->lineEdit_Name->text().toStdString() == "Philip" && ui->lineEdit_Password->text().toStdString() == "1234"){
        MainWindowPointer->exit(10);
    }else{
        ui->label_wrongPw->setVisible(true);
        ui->label_wrongPw->setText("Invalid login...");
        ui->label_wrongPw->setStyleSheet("QLabel { background-color : white; color : red; }");
    }
}
