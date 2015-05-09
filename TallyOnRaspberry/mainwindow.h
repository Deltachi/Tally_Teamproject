#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loginscreen.h"
#include "shoppingcart.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setMainMenueScreen();
    void setMainWindowPointer(QApplication *a);
    void getUserFromLoginScreen();
    void init();
    void showLoginPasswordWidget();
    void removeWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QApplication *mainWindowPointer;
    LoginScreen *myLoginScreen;
    Shoppingcart * myShoppingCart;
};

#endif // MAINWINDOW_H
