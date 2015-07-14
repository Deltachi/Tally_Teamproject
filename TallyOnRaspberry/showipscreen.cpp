//this screen will just show a given text.
#include "showipscreen.h"
#include "ui_showipscreen.h"
#include <QFileInfo>
#include <QDebug>
#include <QString>
//construct the GUI
ShowIpScreen::ShowIpScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowIpScreen)
{
    ui->setupUi(this);
}
//delete the Object
ShowIpScreen::~ShowIpScreen()
{
    delete ui;
}
//this inits the Widget.
void ShowIpScreen::setMainWindowPointer(QApplication *gMainWindowPointer,QString text){
    ui->label->setText(text);
    MainWindowPointer = gMainWindowPointer;
}
//event handling for continue button.
void ShowIpScreen::on_pushButton_clicked()
{
    MainWindowPointer->exit(10);
}
