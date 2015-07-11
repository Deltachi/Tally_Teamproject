#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loginscreen.h"
#include "shoppingcart.h"
#include "favcart.h"
#include <QListWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setMainWindowPointer(QApplication *a);
    void getUserFromLoginScreen();
    void init();
    void showLoginPasswordWidget();
    void removeWidget();
    void setLogoutButton(bool a);
    void showCoffeeSweetWidget();
    bool showScanWidget();
    void getUserIDFromLoginScreen();
    QString getUserID();
    void updateQListCart();
    void setQListCart(QList<QListWidgetItem> item);
    void updateCartFromBuyWidget();
    void updateCartFromScanWidget();
    void showSweetsWidget();
    void showCoffeeWidget();
    void showFavWidget();
    bool showSettingsWidget();
    void updateFavWidget();
    void updateCartFromFavWidget();
    void showAfterBuyScreen();
    void showIpScreen(QString text);
    void setWatchDog();
    void updateFavScreenAmount();
    void getWatchDogTime_Database();
    QString getTimestamp();
    void updateBuyscreenAmount();

    #define Database_Path QString("C:/SQLite/database.sqlite")
    //#define Database_Path qPrintable(QString("/var/www/sqlitetest/database.sqlite"))

    #define Database_Link Data.setDatabaseName(Database_Path);

private slots:

    void on_pushButton_logout_clicked();

    void on_pushButton_clicked();

    void timerEvent(QTimerEvent *event);

    void keyPressEvent(QKeyEvent *ev);
private:
    Ui::MainWindow *ui;
    QApplication *mainWindowPointer;
    LoginScreen *myLoginScreen;
    QList<QListWidgetItem> myCartItems;
    bool showFavCart; //is the user fresh logged in? should he see when going into coffesweetsscan widget the favcart?
    bool favCartVisible; //is the favcart visible now?
    QString userID;
    int counter; //counts up to 3 so that you can see the after buy screen for 3 seconds!
    QString timestamp;
    int watchdogtime;
    QSqlDatabase Data;
    QString time;
    QString scanString;
};

#endif // MAINWINDOW_H
