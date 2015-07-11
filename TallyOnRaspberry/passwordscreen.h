#ifndef PASSWORDSCREEN_H
#define PASSWORDSCREEN_H

#include <QWidget>
#include <QtDebug>
#include <QtSql>
#include <QFileInfo>
#include "sqlzugriff.h"

namespace Ui {
class passwordscreen;
}

class passwordscreen : public QWidget
{
    Q_OBJECT

public:
    explicit passwordscreen(QWidget *parent = 0);
    ~passwordscreen();
    void updatePasswordField();
    void setMainWindowPointer(QApplication *a,QString gUserId);
    void setUsername(QString name);
    void updateAccoutPicture(QString id);
    void setUserId(QString gUserId);

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

    void on_pushButton_back_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_login_clicked();

private:
    Ui::passwordscreen *ui;
    QApplication *mainWindowPointer;
    QString userName;
    QString userId;
    QString password;
    QSqlDatabase Data;
    QString blocked;
    bool tempBlocked;
};

#endif // PASSWORDSCREEN_H
