#include "showipscreen.h"
#include "ui_showipscreen.h"
#include <QFileInfo>
#include <QDebug>
#include <QString>

ShowIpScreen::ShowIpScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowIpScreen)
{
    ui->setupUi(this);
}

ShowIpScreen::~ShowIpScreen()
{
    delete ui;
}
void ShowIpScreen::setMainWindowPointer(QApplication *gMainWindowPointer,QString text){
    ui->label->setText(text);
    MainWindowPointer = gMainWindowPointer;
}
void ShowIpScreen::on_pushButton_clicked()
{
    MainWindowPointer->exit(10);
}
