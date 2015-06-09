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
    void showBuyWidget();
    void showScanWidget();
    void setUserID(QString id);
    QString getUserIDFromLoginScreen();
    QString getUserID();
    void updateQListCart();
    void setQListCart(QList<QListWidgetItem> item);
    void updateCartFromBuyWidget();
    void updateCartFromScanWidget();

private slots:

    void on_pushButton_logout_clicked();

    void on_pushButton_clicked();

    void timerEvent(QTimerEvent *event);
private:
    Ui::MainWindow *ui;
    QApplication *mainWindowPointer;
    LoginScreen *myLoginScreen;
    QList<QListWidgetItem> myCartItems;
    bool showFavCart; //is the user fresh logged in? should he see when going into coffesweetsscan widget the favcart?
    bool favCartVisible; //is the favcart visible now?
    QString userID;
};

#endif // MAINWINDOW_H
