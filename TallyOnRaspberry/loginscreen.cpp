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
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/SQLite/database.sqlite");
}

LoginScreen::~LoginScreen()
{
    delete ui;
}
void LoginScreen::setMainWindowPointer(QApplication *a){
    MainWindowPointer = a;
}
QString LoginScreen::getUsername(){
    return Username;
}

void LoginScreen::update_name_label(){
    ui->listWidget->clear(); //clears the listwidget
    SqlZugriff Database;
    database.open();
    Database.initGetId();
    QString tempName;

    tempName = Database.getNextId();
    int i = 0;
    while(tempName.length() > 0){
        qDebug() << tempName;
        qDebug() << tempName.compare(NameField);

        if(tempName.compare(NameField)== NameField.length()){
            ui->listWidget->insertItem(i,tempName);
            i++;
        }
        tempName = Database.getNextId();
   }
   ui->lineEdit->setText(NameField);
}

void LoginScreen::on_pushButton_1_clicked()
{
    NameField.append("1");
    update_name_label();
}

void LoginScreen::on_pushButton_2_clicked()
{
    NameField.append("2");
    update_name_label();
}

void LoginScreen::on_pushButton_3_clicked()
{
    NameField.append("3");
    update_name_label();
}

void LoginScreen::on_pushButton_4_clicked()
{
    NameField.append("4");
    update_name_label();
}

void LoginScreen::on_pushButton_5_clicked()
{
    NameField.append("5");
    update_name_label();
}

void LoginScreen::on_pushButton_6_clicked()
{
    NameField.append("6");
    update_name_label();
}

void LoginScreen::on_pushButton_7_clicked()
{
    NameField.append("7");
    update_name_label();
}

void LoginScreen::on_pushButton_8_clicked()
{
    NameField.append("8");
    update_name_label();
}

void LoginScreen::on_pushButton_9_clicked()
{
    NameField.append("9");
    update_name_label();
}

void LoginScreen::on_pushButton_loeschen_clicked()
{
    NameField.clear();
    update_name_label();
}

void LoginScreen::on_pushButton_0_clicked()
{
    NameField.append("0");
    update_name_label();
}

void LoginScreen::on_pushButton_Weiter_clicked()
{
    if( ui->listWidget->selectedItems().length() > 0){
        Username = ui->listWidget->selectedItems().first()->text();
        MainWindowPointer->exit(10);
    }
}
