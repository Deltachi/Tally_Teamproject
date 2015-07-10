#ifndef COFFESWEETSSCANN_H
#define COFFESWEETSSCANN_H

#include <QWidget>
#include "shoppingcart.h"
#include <QtSql>
#include <QFileInfo>

namespace Ui {
class CoffeSweetsScann;
}

class CoffeSweetsScann : public QWidget
{
    Q_OBJECT

public:
    explicit CoffeSweetsScann(QWidget *parent = 0);
    ~CoffeSweetsScann();
    void setMainWindowPointer(QApplication *a,QString gUserId);
    void setQWidget(QWidget *a);
    Shoppingcart *getShoppingcart();
    void enableBackButtonOnShoppingcart(bool enable);
    QListWidgetItem *getFavSelectedItem();

private slots:
    void on_pushButton_coffee_clicked();

    void on_pushButton_sweets_clicked();

    void on_pushButton_preferences_clicked();

private:
    Ui::CoffeSweetsScann *ui;
    QApplication *mainWindowPointer;
    QString userId;
    QSqlDatabase Data;
};

#endif // COFFESWEETSSCANN_H
