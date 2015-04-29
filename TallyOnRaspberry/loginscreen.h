#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QWidget>
#include <QApplication>

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

private slots:
    void on_pushButton_clicked();

private:
    Ui::LoginScreen *ui;
    QApplication *MainWindowPointer;
};

#endif // LOGINSCREEN_H
