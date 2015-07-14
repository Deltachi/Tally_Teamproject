//the password screen is used to ask the user for a password so that he can correctly login. It can also block users if they misspell their password.
#include "passwordscreen.h"
#include "ui_passwordscreen.h"
#include "sqlzugriff.h"
#include "mainwindow.h"

//this inits the GUI
passwordscreen::passwordscreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::passwordscreen)
{
    ui->setupUi(this);
    tempBlocked = false;
}
//deletes the object
passwordscreen::~passwordscreen()
{
    delete ui;
}
//this checks if the already typed in text matches to the password from the selected user. If it matches the function will throw an exitcode. It also looks if the user is not blocked.
void passwordscreen::updatePasswordField(){
    short loop;
    ui->lineEdit_password->setText("");
    for(loop=0;loop<password.length();loop++){ //sync the password string with the text edit field
        ui->lineEdit_password->setText(ui->lineEdit_password->text() + "*");
    }

    Data = QSqlDatabase::addDatabase("QSQLITE");
    Database_Link
    Data.open();
    SqlZugriff database;
    if(database.checkUserLoginCount(userId)){ //check if the user is valid/not temp blocked
        if(tempBlocked){ //was user blocked before?
            ui->label_credit->setText(" ");
            ui->label_name->setText(" ");
            tempBlocked = false;
        }
        if(database.checkPassword(userId,password) && blocked != "1" && database.checkUserLoginCount(userId)){  //Was the password correctly? is the user not blocked?
            database.updateLoginAttempt(userId,true);
            Data.close();
            mainWindowPointer->exit(21);
        }
    }else{ //If the user is blocked, this will be the error handling
        ui->label_name->setText("Error:");
        QFont font;
        font.setPointSize(13);
        ui->label_name->setFont(font);
        ui->label_credit->setFont(font);
        ui->label_credit->setText("Temp blocked.");
        ui->label_2->setVisible(false);
    }
    Data.close();
    MainWindow w;
    w.setWatchDog();

}
//This inits the widget
void passwordscreen::setMainWindowPointer(QApplication *a,QString gUserId){
    mainWindowPointer = a;
    userId = gUserId;
    password.clear();
    updateAccoutPicture(userId);
    updatePasswordField();
}
//this will set the username
void passwordscreen::setUsername(QString name){
    userName = name;
}
//this will set the userId
void passwordscreen::setUserId(QString gUserId){
    userId = gUserId;
}
//this will force an update so that the widget will reload the account picture from the database. It will also refresh the credits displayed and the username.
void passwordscreen::updateAccoutPicture(QString id){

    Data = QSqlDatabase::addDatabase("QSQLITE");
    Database_Link
    Data.open();
    SqlZugriff database;
    QPixmap icon;
    QString money;

    database.getPicturePath();
    database.initGetUser();
    while(database.next()){
        if(database.getString(0) == id){
            icon = database.getPixmap(3);
            money = database.getString(4);
        }
    }
    ui->label_pic->setPixmap(icon);
    ui->label_credit->setText(money);
    blocked = database.blocked(id);
    if(blocked == "1"){
        ui->label_credit->setVisible(false);
        ui->label_2->setVisible(false);
        QFont font;
        font.setPointSize(13);
        ui->label_name->setFont(font);
        ui->label_credit->setFont(font);
        ui->label_name->setText("User blocked");
    }

    Data.close();
}
//event handling for a button to enter the password
void passwordscreen::on_pushButton_1_clicked()
{
    password.append("1");
    updatePasswordField();
}
//event handling for a button to enter the password
void passwordscreen::on_pushButton_2_clicked()
{
    password.append("2");
    updatePasswordField();
}
//event handling for a button to enter the password
void passwordscreen::on_pushButton_3_clicked()
{
    password.append("3");
    updatePasswordField();
}
//event handling for a button to enter the password
void passwordscreen::on_pushButton_4_clicked()
{
    password.append("4");
    updatePasswordField();
}
//event handling for a button to enter the password
void passwordscreen::on_pushButton_5_clicked()
{
    password.append("5");
    updatePasswordField();
}
//event handling for a button to enter the password
void passwordscreen::on_pushButton_6_clicked()
{
    password.append("6");
    updatePasswordField();
}
//event handling for a button to enter the password
void passwordscreen::on_pushButton_7_clicked()
{
    password.append("7");
    updatePasswordField();
}
//event handling for a button to enter the password
void passwordscreen::on_pushButton_8_clicked()
{
    password.append("8");
    updatePasswordField();
}
//event handling for a button to enter the password
void passwordscreen::on_pushButton_9_clicked()
{
    password.append("9");
    updatePasswordField();
}
//event handling for the back button. It will throw an exit code and tell the database that the user failed to login.
void passwordscreen::on_pushButton_back_clicked()
{
    password.clear();
    updatePasswordField();
    Data = QSqlDatabase::addDatabase("QSQLITE");
    Database_Link
    Data.open();
    SqlZugriff database;
    database.updateLoginAttempt(userId,false);
    if(!database.checkUserLoginCount(userId)){ //has the user already failed to login?  should he get temp banned?
        Data.close();
        QFont font;
        font.setPointSize(13);
        ui->label_name->setFont(font);
        ui->label_credit->setFont(font);
        ui->label_name->setText("Wrong login!");
        ui->label_credit->setText("Temp blocked.");
        ui->label_2->setVisible(false);
        tempBlocked = true;
        return;
    }
    Data.close();
}
//event handling for a button to enter the password
void passwordscreen::on_pushButton_0_clicked()
{
    password.append("0");
    updatePasswordField();
}
//event handling for login clicked. It will look at the database if the user typed the right password and will finish the login. Or it can temp block the user if he misspelled the password for 3 times.
void passwordscreen::on_pushButton_login_clicked()
{
    Data = QSqlDatabase::addDatabase("QSQLITE");
    Database_Link
    Data.open();
    SqlZugriff database;
    qDebug() << userName << " " << password << " " << userId;
    if(database.checkPassword(userName,password)){
        if(database.checkUserLoginCount(userId)){ //should the user get a temp block for misspelling his password?
            database.updateLoginAttempt(userId,true);
            Data.close();
            mainWindowPointer->exit(21);
        }else{
            QFont font;
            font.setPointSize(13);
            ui->label_name->setFont(font);
            ui->label_credit->setFont(font);
            ui->label_name->setText("Wrong login!");
            ui->label_credit->setText("Temp blocked.");
            ui->label_2->setVisible(false);
            tempBlocked = true;
        }
    }
    database.updateLoginAttempt(userId,false);
    Data.close();
    updatePasswordField();
}
