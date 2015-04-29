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



    w.show();
    //w.setStyleSheet("color: black; background-color:brown;");
    return a.exec();
}

