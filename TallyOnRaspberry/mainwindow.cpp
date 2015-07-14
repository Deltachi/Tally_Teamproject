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
#include "favwidget.h"
#include "afterbuyscreen.h"
#include "sqlzugriff.h"
#include "showipscreen.h"
#include "settingswidget.h"
#include <QTime>
#include <QDate>
#include <QDebug>
#include <QKeyEvent>
#include <QMessageBox>

//constructer
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showFavCart = true;
    counter = -1;

    QTime qtime = QTime::currentTime(); //Init the clock on the widget.
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
int MainWindow::watchdogtime = 0;
//reset time and date
void MainWindow::timerEvent(QTimerEvent *event)
{
    QTime qtime = QTime::currentTime();
    QString stime = qtime.toString(Qt::LocalDate);
    ui->label_Time->setText(stime);

    QDate qdate = QDate::currentDate();
    QString sdate = qdate.toString(Qt::LocalDate);
    ui->label_Date->setText(sdate);

    if(watchdogtime == time.toInt() && watchdogactive){   //Should the Watchdog automatically do a logout?
        mainWindowPointer->exit(100);
        watchdogtime = 0;
    }else
    {
        watchdogtime++;
    }


    if(counter == -1){                  //timer for the afterbuyscreen
        //do nothing
    }else if(counter <= 1){
        counter++;
    }else if(counter > 1){              //was the AfterBuy-Screen shown for more than 1 second? Then remove it and do a logout for the current user.
        counter = -1;
        mainWindowPointer->exit(100);
    }

}
//resets the watchdog
void MainWindow::setWatchDogactive(bool value){
    watchdogactive = value;
}

//read the Barcode-Scanner
void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->text().at(0) == 0xD){           //if /n/r was pressed the Barcode Scanner has finished transmitting.
        mainWindowPointer->exit(34);
    }
    else scanString = scanString + ev->text();
}

//get the Watchdogtime from the Database
void MainWindow::getWatchDogTime_Database(){
    Data = QSqlDatabase::addDatabase("QSQLITE");
    Database_Link
    Data.open();
    SqlZugriff Database;
    time = Database.getWatchDogtime();
    Data.close();
}

//set the Watchdogtime
void MainWindow::setWatchDog(){
    watchdogtime = 0;
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
//removes any Widget laying in the gridLayout_port
void MainWindow::removeWidget(){

    QLayoutItem *oldItem = ui->gridLayout_port->itemAt(0);
    if(oldItem != NULL){
        QWidget *oldWidget = oldItem->widget();
        ui->gridLayout_port->removeWidget(oldWidget);
        oldWidget->setVisible(false);
        delete oldWidget;
    }
}
//Puts the IPScreen into the gridLayoutPort and inits it.
void MainWindow::showIpScreen(QString text){
    ShowIpScreen *myIpScreen = new ShowIpScreen();
    myIpScreen->setMainWindowPointer(mainWindowPointer,text);
    ui->gridLayout_port->addWidget(myIpScreen);
}
//if the Loginscreen is still active, it will get the UserId from it. Otherwise it will fail.
void MainWindow::getUserIDFromLoginScreen(){
    LoginScreen *loginS;
    loginS = (LoginScreen*)(ui->gridLayout_port->itemAt(0)->widget());
    userID = loginS->getUserID();
}
//Puts the LoginPasswordWidget into the gridLayoutPort and inits it.
void MainWindow::showLoginPasswordWidget(){
    passwordscreen *myPwScreen = new passwordscreen();
    myPwScreen->setUsername(ui->label_username->text());
    myPwScreen->setMainWindowPointer(mainWindowPointer,userID);
    ui->gridLayout_port->addWidget(myPwScreen);
    showFavCart = true;
}
//Puts the SettingsWidget into the gridLayoutPort and inits it.
bool MainWindow::showSettingsWidget(){
    this->removeWidget();
    SettingsWidget *mySettingsWidget = new SettingsWidget();
    if(mySettingsWidget->setMainWindowPointer(mainWindowPointer)){//could the settings File be read from the system? else return false!
        ui->gridLayout_port->addWidget(mySettingsWidget);
        return true;
    }
    return false;
}
//returns the userId. This just works if the userId was set before. E.g. via this.getUserIDFromLoginScreen();
QString MainWindow::getUserID(){
    return userID;
}
//If some Items have been manipulated the FavWidget will reset them.
void MainWindow::updateFavScreenAmount(){
    FavWidget *temp = (FavWidget*)ui->gridLayout_port->itemAt(0)->widget();
    temp->forceFavCartUpdate();
}
//Puts the CoffeeSweetScann widget into the gridLayoutPort and inits it.
void MainWindow::showCoffeeSweetWidget(){
    scanString = "";
    CoffeSweetsScann *myCoffeeWidget = new CoffeSweetsScann();
    ui->gridLayout_port->addWidget(myCoffeeWidget);
    myCoffeeWidget->setMainWindowPointer(mainWindowPointer,userID);
    if(showFavCart){
        myCartItems.clear();
    }
    if(myCartItems.length() == 0){//Is the shoppingcart empty? -> show the favcart.
        FavCart *myFavCart = new FavCart();
        myFavCart->setMainWindowPointer(mainWindowPointer,userID);
        myFavCart->updateItems();
        myCoffeeWidget->setQWidget(myFavCart);
        showFavCart = false;
        favCartVisible = true;
    }else{ //init the shoppingcart and place it into the CoffeeSweetsScan widget.
        Shoppingcart *cart = new Shoppingcart;
        cart->setMainWindowPointer(mainWindowPointer,userID);
        myCoffeeWidget->setQWidget(cart);
        int loop = 0;
        favCartVisible = false;
        CoffeSweetsScann *temp = (CoffeSweetsScann*)ui->gridLayout_port->itemAt(0)->widget();
        Shoppingcart *tempCart = temp->getShoppingcart();
        while(loop < myCartItems.length()){ //copy every item from the old shoppingcart into the new one.
            QListWidgetItem *test = new QListWidgetItem;
            *test = myCartItems.at(loop);
            tempCart->addItem(test);
            loop++;
        }
    }
}
//updates the qList "myCartItems" which backups all items from the shoppingcart. The items will be read from the CoffeeSweetsScann widget.
void MainWindow::updateQListCart(){
    if(!favCartVisible){ //is there a shopping cart or is there the favcart?
        CoffeSweetsScann *temp = (CoffeSweetsScann*)ui->gridLayout_port->itemAt(0)->widget();
        Shoppingcart *tempCart = temp->getShoppingcart();
        myCartItems = tempCart->getItems();
    }
}
//updates the qList "myCartItems" which backups all items from the shoppingcart.
void MainWindow::setQListCart(QList<QListWidgetItem> item){
    myCartItems = item;
}
//updates the qList "myCartItems" which backups all items from the shoppingcart. The items will be read from the Buywidget widget.
void MainWindow::updateCartFromBuyWidget(){
    buywidget *temp = (buywidget*)ui->gridLayout_port->itemAt(0)->widget();
    myCartItems = temp->getItems();
}
//updates the qList "myCartItems" which backups all items from the shoppingcart. The items will be read from the Scan widget.
void MainWindow::updateCartFromScanWidget(){
    ScanWidget *temp = (ScanWidget*)ui->gridLayout_port->itemAt(0)->widget();
    myCartItems = temp->getItems();
}
//updates the qList "myCartItems" which backups all items from the shoppingcart. The items will be read from the Fav widget.
void MainWindow::updateCartFromFavWidget(){
    FavWidget *temp = (FavWidget*)ui->gridLayout_port->itemAt(0)->widget();
    myCartItems = temp->getItems();
}
//enables/disables the logout button.
void MainWindow::setLogoutButton(bool a){
    ui->pushButton_logout->setEnabled(a);
}
//Puts the Buywidget into the gridLayoutPort and inits it.
void MainWindow::showSweetsWidget(){
    buywidget *myBuyWidget = new buywidget();

    myBuyWidget->setMainWindowPointer(mainWindowPointer,&myCartItems,true,userID);
    ui->gridLayout_port->addWidget(myBuyWidget);
}
//Puts the FavWidget into the gridLayoutPort and inits it.
void MainWindow::showFavWidget(){
    CoffeSweetsScann *c = (CoffeSweetsScann*)ui->gridLayout_port->itemAt(0)->widget();
    QListWidgetItem item = *(c->getFavSelectedItem());
    item.setData(6,1);
    item.setText("x01 " + item.text());
    this->removeWidget();
    FavWidget *myFavWidget = new FavWidget();
    myFavWidget->setMainWindowPointer(mainWindowPointer,userID,&item);
    ui->gridLayout_port->addWidget(myFavWidget);
}
//Puts the AfterBuyScreen into the gridLayout_Port and inits it.
void MainWindow::showAfterBuyScreen(){
    AfterBuyScreen *myAfterBuyScreen = new AfterBuyScreen();
    ui->gridLayout_port->addWidget(myAfterBuyScreen);
    counter = 0;
}
//Puts the Buywidget into the gridLayout_Port and inits it.
void MainWindow::showCoffeeWidget(){
    buywidget *myBuyWidget = new buywidget();

    myBuyWidget->setMainWindowPointer(mainWindowPointer,&myCartItems,false,userID);
    ui->gridLayout_port->addWidget(myBuyWidget);
}
//Puts the Scan into the gridLayout_Port and inits it.
bool MainWindow::showScanWidget(){
    Data = QSqlDatabase::addDatabase("QSQLITE");
    Database_Link
    QListWidgetItem *item = new QListWidgetItem();
    Data.open();
    SqlZugriff database;
    database.getPicturePath();
    bool valid = false;
    if(database.findGroceriesWithBarcode(scanString)){ //Find the scanned item and give it to the Scanwidget
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
//updates the qList "myCartItems" which backups all items from the buywidget. The items will be read from the Scan widget.
void MainWindow::updateBuyscreenAmount(){
    buywidget *myBuyWidget = (buywidget*)ui->gridLayout_port->itemAt(0)->widget();
    myBuyWidget->updateAmount();
}
//this will get called if the logout Button was clicked
void MainWindow::on_pushButton_logout_clicked()
{
    showFavCart = true;
    mainWindowPointer->exit(100);
}
void MainWindow::on_pushButton_clicked()
{
    mainWindowPointer->exit(0);
}
