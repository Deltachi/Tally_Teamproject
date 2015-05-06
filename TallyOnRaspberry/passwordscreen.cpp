#include "passwordscreen.h"
#include "ui_passwordscreen.h"
#include "sqlzugriff.h"


passwordscreen::passwordscreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::passwordscreen)
{
    ui->setupUi(this);

    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/SQLite/database.sqlite");
    database.open();

   // if(qry.exec("select * from User_table where Name = '"+username+"'")){


   // ui->label_name =
}

passwordscreen::~passwordscreen()
{
    delete ui;
}

void passwordscreen::on_pushButton_1_clicked()
{

}

void passwordscreen::on_pushButton_2_clicked()
{

}

void passwordscreen::on_pushButton_3_clicked()
{

}

void passwordscreen::on_pushButton_4_clicked()
{

}

void passwordscreen::on_pushButton_5_clicked()
{

}

void passwordscreen::on_pushButton_6_clicked()
{

}

void passwordscreen::on_pushButton_7_clicked()
{

}

void passwordscreen::on_pushButton_8_clicked()
{

}

void passwordscreen::on_pushButton_9_clicked()
{

}

void passwordscreen::on_pushButton_back_clicked()
{

}

void passwordscreen::on_pushButton_0_clicked()
{

}

void passwordscreen::on_pushButton_login_clicked()
{
    //if(qry.exec("select * from Benutzer where Name = '"+username+"' and Passwort='"+password+"'" ))
}
