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
    w.setWatchDog();
    w.getWatchDogTime_Database();
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
                    w.getUserIDFromLoginScreen();
                    w.removeWidget();
                    w.showLoginPasswordWidget();
                    w.setLogoutButton(true);
                    w.setWatchDog();
                    state = 1;
                }else if(exitcode != 100){ //logout == 100
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
                }else if(exitcode == 21){ //password correct
                    w.removeWidget();
                    w.showCoffeeSweetWidget();
                    state = 2;
                    w.setWatchDog();
                }else if(exitcode != 100){ //logout == 100
                    return 0;
                }
            }break;
            case 2: {//coffee sweets scan screen
                if(exitcode == 31){ //coffee was clicked
                    w.updateQListCart();
                    w.removeWidget();
                    w.showCoffeeWidget();
                    state = 3;
                    w.setWatchDog();
                }else if(exitcode == 32){ //sweets was clicked
                    w.updateQListCart();
                    w.removeWidget();
                    w.showSweetsWidget();
                    state = 4;
                    w.setWatchDog();
                }else if(exitcode == 33){ //scan was clicked
                    w.updateQListCart();
                    w.removeWidget();
                    w.showScanWidget();
                    state = 5;
                    w.setWatchDog();
                }else if(exitcode == 99){ //buy was clicked
                    w.removeWidget();
                    w.showAfterBuyScreen();
                    w.setWatchDog();
                }else if(exitcode != 100 && exitcode != 98){ //logout == 100
                    return 0;
                }
            }break;
            case 3: { //buy coffee
                if(exitcode == 51){ //back was clicked
                    w.updateCartFromBuyWidget();
                    w.removeWidget();
                    w.showCoffeeSweetWidget();
                    state = 2;
                    w.setWatchDog();
                }else if(exitcode == 99){ //buy was clicked
                    w.removeWidget();
                    w.showAfterBuyScreen();
                    w.setWatchDog();
                }else if(exitcode == 98){ //item was remove from shoppingcart
                    qDebug() << "updating...";
                    w.updateBuyscreenAmount();
                }
            }break;
            case 4: { //buy sweets
                if(exitcode == 51){ //back was clicked
                    w.updateCartFromBuyWidget();
                    w.removeWidget();
                    w.showCoffeeSweetWidget();
                    state = 2;
                    w.setWatchDog();
                }else if(exitcode == 99){ //buy was clicked
                    w.removeWidget();
                    w.showAfterBuyScreen();
                    w.setWatchDog();
                }else if(exitcode == 98){ //item was remove from shoppingcart
                    qDebug() << "updating...";
                    w.updateBuyscreenAmount();
                }
            }break;
            case 5: { //user wants to scan things
                if(exitcode == 51){ //back was clicked
                    w.removeWidget();
                    w.showCoffeeSweetWidget();
                    state = 2;
                    w.setWatchDog();
                }else if(exitcode == 99){ //buy was clicked
                    w.removeWidget();
                    w.showAfterBuyScreen();
                    w.setWatchDog();
                }
            }break;
            default: {//something went wrong...

            }break;
        }
        exitcode = a.exec();
    }
    return exitcode;
}

