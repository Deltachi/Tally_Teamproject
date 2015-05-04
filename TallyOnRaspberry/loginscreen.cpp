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
QString LoginScreen::getUsername(){
    return Username;
}

void LoginScreen::update_name_label(){
    ui->listWidget->clear(); //clears the listwidget

   if(NameField.endsWith("1")){ //which letter have we added? update lineEdit and listWidget!

       ui->listWidget->insertItem(1,"Anne Fresse");
       ui->listWidget->insertItem(2,"Anne Bar");
       ui->listWidget->insertItem(3,"Anna Hinderlich");

   }else if(NameField.endsWith("2")){

       ui->listWidget->insertItem(1,"Dieter Knebel");
       ui->listWidget->insertItem(2,"Donut Essen");

   }else if(NameField.endsWith("3")){

       ui->listWidget->insertItem(1,"Gelatina");
       ui->listWidget->insertItem(2,"Indiane Nesjo");
       ui->listWidget->insertItem(3,"Gustavo Machdichfertig");

   }else{
       if(NameField.length() > 0){
           ui->listWidget->insertItem(1,"Mir faellt nichts mehr ein...");
           ui->listWidget->insertItem(2,"Drueck was anders..");
       }
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
    Username = ui->listWidget->selectedItems().first()->text();
    MainWindowPointer->exit(10);
}
