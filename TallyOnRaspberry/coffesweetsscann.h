#ifndef COFFESWEETSSCANN_H
#define COFFESWEETSSCANN_H

#include <QWidget>
#include "shoppingcart.h"

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

private slots:
    void on_pushButton_coffee_clicked();

    void on_pushButton_sweets_clicked();

    void on_pushButton_scan_clicked();

private:
    Ui::CoffeSweetsScann *ui;
    QApplication *mainWindowPointer;
    QString userId;
};

#endif // COFFESWEETSSCANN_H
