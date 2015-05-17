#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginscreen.h"
#include "mainmenue.h"
#include "passwordscreen.h"
#include "shoppingcart.h"
#include "buywidget.h"
#include "coffesweetsscann.h"
#include "scanwidget.h"
#include "favcart.h"

//constructer
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showFavCart = true;
}
//delete MainWindow
MainWindow::~MainWindow()
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
    if(oldItem != NULL){
        QWidget *oldWidget = oldItem->widget();
        ui->gridLayout_port->removeWidget(oldWidget);
        oldWidget->setVisible(false);
        delete oldWidget;
    }
}
void MainWindow::showLoginPasswordWidget(){

    passwordscreen *myPwScreen = new passwordscreen();
    ui->gridLayout_port->addWidget(myPwScreen);
    myPwScreen->updateAccoutPicture(ui->label_username->text());
    myPwScreen->setUsername(ui->label_username->text());
}
void MainWindow::showCoffeeSweetWidget(){

    CoffeSweetsScann *myCoffeeWidget = new CoffeSweetsScann();
    ui->gridLayout_port->addWidget(myCoffeeWidget);
    myCoffeeWidget->setMainWindowPointer(mainWindowPointer);
    if(showFavCart){
        //shoppingCart.clear();
        FavCart *myFavCart = new FavCart();
        myCoffeeWidget->setQWidget(myFavCart);
    }else{
        myShoppingCart = new Shoppingcart();
        myCoffeeWidget->setQWidget(myShoppingCart);
    }
}
void MainWindow::setLogoutButton(bool a){
    ui->pushButton_logout->setEnabled(a);
}
void MainWindow::showBuyWidget(){
    buywidget *myBuyWidget = new buywidget();
    ui->gridLayout_port->addWidget(myBuyWidget);
}
void MainWindow::showScanWidget(){
    ScanWidget *myScanWidget = new ScanWidget();
    ui->gridLayout_port->addWidget(myScanWidget);
}
void MainWindow::on_pushButton_logout_clicked()
{
    //shoppingcart.clear();
    showFavCart = true;
    mainWindowPointer->exit(100);
}

void MainWindow::on_pushButton_clicked()
{
    mainWindowPointer->exit(0);
}
