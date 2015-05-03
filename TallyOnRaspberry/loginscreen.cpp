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

void LoginScreen::update_name_label(){
    ui->listWidget->clear();
    QListWidgetItem Peter;//new QListWidgetItem(tr("Paul"),ui->listWidget );
    qDebug() << NameField;
   if(NameField.endsWith("1")){
       Peter.setText("Anna");
       ui->listWidget->addItem(&Peter);
       ui->listWidget->insertItem(1,"Anne Fresse");
   }else if(NameField.endsWith("2")){
       Peter.setText("Dieter");
       ui->listWidget->addItem(&Peter);

   }else if(NameField.endsWith("3")){
       Peter.setText("Gustavo");
       ui->listWidget->addItem(&Peter);
   }else{
       Peter.setText("Herbertina");
       ui->listWidget->addItem(&Peter);
   }
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

}
