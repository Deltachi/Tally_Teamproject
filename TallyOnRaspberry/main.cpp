#include "mainwindow.h"
#include <QApplication>
#include <QDir>
#include <QDebug>
#include <QFileInfo>
#include <QString>
#include <QList>
#include <QtNetwork/QNetworkInterface>
#include <QtNetwork/QNetworkConfigurationManager>
#include <QtNetwork/QNetworkSession>
#include <QtNetwork/QTcpSocket>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    int state = 0;

    w.setWindowTitle("Tally");
    w.show();
    w.getWatchDogTime_Database();
    w.setWatchDog();
    w.setMainWindowPointer(&a);

    QTcpSocket socket;
    QString ip;
    socket.connectToHost("8.8.8.8", 53); // google DNS, or something else reliable
    if (socket.waitForConnected()) {
        ip = socket.localAddress().toString();
    } else {
        ip = socket.errorString();
    }
    w.showIpScreen(ip);
    int exitcode;
    exitcode = a.exec();
    w.removeWidget();

    exitcode = 100;

    bool exit = false;

    while(!exit){
        if(exitcode == 100){ //logout was pressed
            state = 0;
            w.removeWidget();
            w.init();
            w.setLogoutButton(false);
            w.getWatchDogTime_Database();
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
                }else if(exitcode == 51){ //back was clicked -> logout
                    state = 0;
                    w.removeWidget();
                    w.init();
                    w.setLogoutButton(false);
                    w.getWatchDogTime_Database();
                }else if(exitcode == 34){ //scan
                    w.updateQListCart();
                    w.removeWidget();
                    if(w.showScanWidget()){
                        state = 5;
                    }else{
                        state = 2;
                        w.updateCartFromScanWidget();
                        w.removeWidget();
                        w.showCoffeeSweetWidget();
                        state = 2;
                        w.setWatchDog();
                    }
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
                    w.updateBuyscreenAmount();
                }
            }break;
            case 5: { //user wants to scan things
                if(exitcode == 51){ //back was clicked or item added
                    w.updateCartFromScanWidget();
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
