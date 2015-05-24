#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loginscreen.h"
#include "shoppingcart.h"
#include "favcart.h"

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

private slots:

    void on_pushButton_logout_clicked();

    void on_pushButton_clicked();

    void timerEvent(QTimerEvent *event);

private:
    Ui::MainWindow *ui;
    QApplication *mainWindowPointer;
    LoginScreen *myLoginScreen;
    Shoppingcart * myShoppingCart;
    bool showFavCart;
};

#endif // MAINWINDOW_H
