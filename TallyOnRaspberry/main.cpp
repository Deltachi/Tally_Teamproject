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
    w.init();

    int exitcode = -1;
    bool exit = false;
    while(!exit){
        switch(state){
            case 0: {//Loginscreen (showing Name list)
                if(exitcode == 10){ //->login was clicked
                    w.getUserFromLoginScreen();
                    w.removeWidget();
                    w.showLoginPasswordWidget();
                    state = 1;
                }else if(exitcode != -1){ //init
                    return 0;
                }
            }
            break;
            case 1: {//password screen
                if(exitcode == 11){ //->back
                    w.removeWidget();
                    w.init();
                    state = 0;
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

