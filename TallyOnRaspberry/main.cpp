#include "mainwindow.h"
#include <QApplication>
#include <QDir>
#include <QDebug>
#include <QFileInfo>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    int state = 0;

    w.setWindowTitle("Tally");
    w.show();
    w.setMainWindowPointer(&a);
    int exitcode = 100;
    bool exit = false;

    while(!exit){
        if(exitcode == 100){ //logout was pressed
            state = 0;
            w.removeWidget();
            w.init();
            w.setLogoutButton(false);
        }
        switch(state){
            case 0: {//Loginscreen (showing Name list)
                if(exitcode == 10){ //->login was clicked
                    w.getUserFromLoginScreen();
                    w.removeWidget();
                    w.showLoginPasswordWidget();
                    w.setLogoutButton(true);
                    state = 1;
                }else if(exitcode != 100){ //init
                    return 0;
                }
            }
            break;
            case 1: {//password screen
                if(exitcode == 20){ //->back
                    w.removeWidget();
                    w.init();
                    state = 0;
                    w.setLogoutButton(false);
                }else if(exitcode == 21){
                    w.removeWidget();
                    w.showCoffeeSweetWidget();
                }else if(exitcode != 100){ //init
                    return 0;
                }
            }break;
            case 2: {//coffee sweets scan screen

            }break;
            default: {//something went wrong...

            }break;
        }
        exitcode = a.exec();
    }
    return exitcode;
}

