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

    w.setWindowTitle("Tally");
    w.show();
    w.setMainWindowPointer(&a);

    //w.setStyleSheet("color: black; background-color:brown;");
    int exitcode;
    bool exit = false;
    while(!exit){
        exitcode = a.exec();
        if(exitcode == 10){ //Login was pressed?
            w.setMainMenueScreen();
            qDebug("Clicked^^");
        }else{
            exit = true;
        }
    }
    return exitcode;
}

