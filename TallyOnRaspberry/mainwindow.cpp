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
#include "afterbuyscreen.h"
#include "sqlzugriff.h"
#include <QTime>
#include <QDate>
#include <QDebug>
#include <QKeyEvent>

//constructer
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showFavCart = true;

    QTime qtime = QTime::currentTime();
    QString stime = qtime.toString(Qt::LocalDate);
    ui->label_Time->setText(stime);
    startTimer(1000);

    QDate qdate = QDate::currentDate();
    QString sdate = qdate.toString(Qt::LocalDate);
    ui->label_Date->setText(sdate);
    timestamp = stime + ";" + sdate;

}

QString MainWindow::getTimestamp(){
    return timestamp;
}

//delete MainWindow
MainWindow::~MainWindow()
{
    delete ui;
}

//reset time and date
void MainWindow::timerEvent(QTimerEvent *event)
{
    QTime qtime = QTime::currentTime();
    QString stime = qtime.toString(Qt::LocalDate);
    ui->label_Time->setText(stime);

    QDate qdate = QDate::currentDate();
    QString sdate = qdate.toString(Qt::LocalDate);
    ui->label_Date->setText(sdate);


    if(watchdogtime == time.toInt()){
        mainWindowPointer->exit(100);
        watchdogtime = 0;
    }else
    {
        watchdogtime++;
    }


    if(counter == -1){
        //do nothing
    }else if(counter <= 1){
        counter++;
    }else if(counter > 1){ //was the after buy screen shown for more than 3 seconds?
        counter = -1;
        mainWindowPointer->exit(100);
    }

}
void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->text().at(0) == 0xD){
        mainWindowPointer->exit(34);
    }
    else scanString = scanString + ev->text();
}
void MainWindow::getWatchDogTime_Database(){
    Data = QSqlDatabase::addDatabase("QSQLITE");
    Database_Link
    Data.open();
    SqlZugriff Database;
    time = Database.getWatchDogtime();
    Data.close();
}

void MainWindow::setWatchDog(){
    watchdogtime = 0;
}

//sets the pointer to the window generated from qt
void MainWindow::setMainWindowPointer(QApplication *a){

    mainWindowPointer = a;
}
//inits the mainwindow with loginscreen
void MainWindow::init(){
    counter = -1;
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

void MainWindow::getUserIDFromLoginScreen(){
    LoginScreen *loginS;
    loginS = (LoginScreen*)(ui->gridLayout_port->itemAt(0)->widget());
    userID = loginS->getUserID();
}

void MainWindow::showLoginPasswordWidget(){
    passwordscreen *myPwScreen = new passwordscreen();
    ui->gridLayout_port->addWidget(myPwScreen);
    myPwScreen->updateAccoutPicture(userID);
    myPwScreen->setUsername(ui->label_username->text());
    myPwScreen->setUserId(userID);
    showFavCart = true;
}
QString MainWindow::getUserID(){
    return userID;
}

void MainWindow::showCoffeeSweetWidget(){
    scanString = "";
    CoffeSweetsScann *myCoffeeWidget = new CoffeSweetsScann();
    ui->gridLayout_port->addWidget(myCoffeeWidget);
    myCoffeeWidget->setMainWindowPointer(mainWindowPointer,userID);

    if(showFavCart){
        FavCart *myFavCart = new FavCart();
        myCoffeeWidget->setQWidget(myFavCart);
        showFavCart = false;
        favCartVisible = true;
        myCartItems.clear();
    }else{
        Shoppingcart *cart = new Shoppingcart;
        cart->setMainWindowPointer(mainWindowPointer,userID);
        myCoffeeWidget->setQWidget(cart);
        int loop = 0;
        favCartVisible = false;
        CoffeSweetsScann *temp = (CoffeSweetsScann*)ui->gridLayout_port->itemAt(0)->widget();
        Shoppingcart *tempCart = temp->getShoppingcart();
        while(loop < myCartItems.length()){
            QListWidgetItem *test = new QListWidgetItem;
            *test = myCartItems.at(loop);
            tempCart->addItem(test);
            loop++;
        }
    }
}
void MainWindow::updateQListCart(){
    if(!favCartVisible){ //is there a shopping cart or is there the favcart?
        CoffeSweetsScann *temp = (CoffeSweetsScann*)ui->gridLayout_port->itemAt(0)->widget();
        Shoppingcart *tempCart = temp->getShoppingcart();
        myCartItems = tempCart->getItems();
    }
}
void MainWindow::setQListCart(QList<QListWidgetItem> item){
    myCartItems = item;
}
void MainWindow::updateCartFromBuyWidget(){
    buywidget *temp = (buywidget*)ui->gridLayout_port->itemAt(0)->widget();
    myCartItems = temp->getItems();
}
void MainWindow::updateCartFromScanWidget(){
    ScanWidget *temp = (ScanWidget*)ui->gridLayout_port->itemAt(0)->widget();
    myCartItems = temp->getItems();
}
void MainWindow::setLogoutButton(bool a){
    ui->pushButton_logout->setEnabled(a);
}
void MainWindow::showSweetsWidget(){
    buywidget *myBuyWidget = new buywidget();

    myBuyWidget->setMainWindowPointer(mainWindowPointer,&myCartItems,true,userID);
    ui->gridLayout_port->addWidget(myBuyWidget);
}
void MainWindow::showAfterBuyScreen(){
    AfterBuyScreen *myAfterBuyScreen = new AfterBuyScreen();
    ui->gridLayout_port->addWidget(myAfterBuyScreen);
    counter = 0;
}
void MainWindow::showCoffeeWidget(){
    buywidget *myBuyWidget = new buywidget();

    myBuyWidget->setMainWindowPointer(mainWindowPointer,&myCartItems,false,userID);
    ui->gridLayout_port->addWidget(myBuyWidget);
}
bool MainWindow::showScanWidget(){
    Data = QSqlDatabase::addDatabase("QSQLITE");
    Database_Link
    QListWidgetItem *item = new QListWidgetItem();
    Data.open();
    SqlZugriff database;
    bool valid = false;
    if(database.findGroceriesWithBarcode(scanString)){
        qDebug() << "true" << " " << scanString;
        item->setData(4,database.getString(0));
        item->setData(5,database.getString(5));
        item->setData(6,database.getString(4));
        item->setText(database.getString(2));
        int amount = database.getString(4).toInt();
        item->setIcon(database.getPixmap(7));
        Data.close();
        valid = true;
        if(amount == 1){
            item->setTextColor(QColor(255,51,51,255)); //red
         item->setHidden(false);
        }else if(amount > 1 && amount <= 6){
            item->setTextColor(QColor(255,128,0,255)); //yellow
            item->setHidden(false);
        }else if(amount == 0){
            item->setHidden(true);
            qDebug() << "Amount is == 0...";
            valid = false;
        }else{
            item->setTextColor(QColor(0,0,0,255)); //black
            item->setHidden(false);
        }
    }
    ScanWidget *myScanWidget = new ScanWidget();
    ui->gridLayout_port->addWidget(myScanWidget);
    scanString = "";
    if(valid){
        myScanWidget->setMainWindowPointer(mainWindowPointer,&myCartItems,userID,item);
        return true;
    }else{
        myScanWidget->setMainWindowPointer(mainWindowPointer,&myCartItems,userID,NULL);
        return false;
    }
}
void MainWindow::updateBuyscreenAmount(){
    buywidget *myBuyWidget = (buywidget*)ui->gridLayout_port->itemAt(0)->widget();
    myBuyWidget->updateAmount();
}
void MainWindow::on_pushButton_logout_clicked()
{
    showFavCart = true;
    mainWindowPointer->exit(100);
}

void MainWindow::on_pushButton_clicked()
{
    mainWindowPointer->exit(0);
}
