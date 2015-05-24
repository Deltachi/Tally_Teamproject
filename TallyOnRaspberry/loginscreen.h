#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QWidget>
#include <QApplication>
#include <QString>
#include <QtDebug>
#include <QtSql>
#include <QFileInfo>
#include "sqlzugriff.h"

namespace Ui {
class LoginScreen;
}

class LoginScreen : public QWidget
{
    Q_OBJECT

public:
    explicit LoginScreen(QWidget *parent = 0);
    ~LoginScreen();
    void setMainWindowPointer(QApplication *a);
    void update_name_label();
    QString getUsername();
    QString getUserID();

private slots:


    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_loeschen_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_Weiter_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::LoginScreen *ui;
    QApplication *MainWindowPointer;
    QString NameField;          //REAL Name
    QString PasswordField;
    QString Username; //this is the logged in Username
    QString UserID; //this is the logged in User_ID
    QSqlDatabase Data;

};

#endif // LOGINSCREEN_H
