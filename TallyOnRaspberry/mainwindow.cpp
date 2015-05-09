#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginscreen.h"
#include "mainmenue.h"
#include "passwordscreen.h"
#include "shoppingcart.h"
#include "buywidget.h"
#include "coffesweetsscann.h"

//constructer
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
//delete MainWindow
MainWindow::~MainWindow()
{
    delete ui;
}
//close application button
void MainWindow::on_pushButton_clicked()
{
    delete ui;
}
//sets the pointer to the window generated from qt
void MainWindow::setMainWindowPointer(QApplication *a){

    mainWindowPointer = a;
}
//inits the mainwindow with loginscreen
void MainWindow::init(){
    ui->label_username->setText("");
    myLoginScreen = new LoginScreen();
    ui->gridLayout_port->addWidget(myLoginScreen);
}
//updates ists current logged in user
void MainWindow::getUserFromLoginScreen(){

   ui->label_username->setText(myLoginScreen->getUsername());
}
void MainWindow::removeWidget(){

    QLayoutItem *oldItem = ui->gridLayout_port->itemAt(0);
    QWidget *oldWidget = oldItem->widget();
    ui->gridLayout_port->removeWidget(oldWidget);
    oldWidget->setVisible(false);
    delete oldWidget;
}
//switches to the MainMenueScreen
void MainWindow::setMainMenueScreen(){

    MainMenue *myMainMenue = new MainMenue();
    ui->gridLayout_port->addWidget(myMainMenue);
}
void MainWindow::showLoginPasswordWidget(){

    passwordscreen *myPwScreen = new passwordscreen();
    ui->gridLayout_port->addWidget(myPwScreen);
    myPwScreen->setUsername(ui->label_username->text());
}
