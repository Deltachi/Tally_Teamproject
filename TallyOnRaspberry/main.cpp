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
    w.showFullScreen();
    w.getWatchDogTime_Database();
    w.setWatchDog();
    w.setMainWindowPointer(&a);
    w.setWatchDogactive(false);

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
            w.setWatchDogactive(false);
        }
        switch(state){
            case 0: {//Loginscreen (showing Name list)
                if(exitcode == 10){ //->login was clicked
                    w.setWatchDogactive(true);
                    w.getUserFromLoginScreen();
                    w.getUserIDFromLoginScreen();
                    w.removeWidget();
                    w.showLoginPasswordWidget();
                    w.setLogoutButton(true);
                    w.setWatchDog();
                    state = 1;
                }else if(exitcode != 34 && exitcode != 100){ //something scanned == 34
                    return 0;
                }
            }
            break;
            case 1: {//password screen
                if(exitcode == 21){ //password correct
                    w.removeWidget();
                    w.showCoffeeSweetWidget();
                    state = 2;
                    w.setWatchDog();
                }else if(exitcode != 34){ //logout == 100   something scanned == 34
                    return exitcode;
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
                }else if(exitcode == 51){ //back was clicked -> logout
                    state = 0;
                    w.removeWidget();
                    w.init();
                    w.setLogoutButton(false);
                    w.getWatchDogTime_Database();
                }else if(exitcode == 36){ //settings was clicked
                    w.removeWidget();
                    w.setWatchDog();
                    if(w.showSettingsWidget()){//could the WLAN file be read?
                        state = 7;
                    }else{ //return to coffesweetsscan widget, config file was missing...
                        w.removeWidget();
                        w.showCoffeeSweetWidget();
                        state = 2;
                    }
                }else if(exitcode == 34){ //scan
                    w.updateQListCart();
                    w.removeWidget();
                    if(w.showScanWidget()){
                        state = 5;
                    }else{
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
                }else if(exitcode == 35){ //favourite was selected! Go to Favwidget
                    w.showFavWidget();
                    w.setWatchDog();
                    state = 6;
                }else if(exitcode != 98){ //logout == 100
                    return exitcode;
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
                }else if(exitcode != 34){
                    return exitcode;
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
                }else if(exitcode != 34){
                    return exitcode;
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
                }else if(exitcode != 34){
                    return exitcode;
                }
            }break;
            case 6: { //Favwidget
                 if(exitcode == 99){ //buy was clicked
                    w.removeWidget();
                    w.showAfterBuyScreen();
                    w.setWatchDog();
                 }else if(exitcode == 51){ //back was clicked
                    w.updateCartFromFavWidget();
                    w.removeWidget();
                    w.showCoffeeSweetWidget();
                    state = 2;
                    w.setWatchDog();
                 }else if(exitcode == 98){
                    w.updateFavScreenAmount();
                 }
            }break;
            case 7: { //settings screen
                if(exitcode == 71){
                    w.removeWidget();
                    w.showCoffeeSweetWidget();
                    state = 2;
                    w.setWatchDog();
                }else if(exitcode != 34){
                    return exitcode;
                }
            }
            default: {//something went wrong...

            }break;
        }
        exitcode = a.exec();
    }
    return exitcode;
}
