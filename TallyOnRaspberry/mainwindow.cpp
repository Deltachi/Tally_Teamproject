#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginscreen.h"
#include "mainmenue.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    LoginScreen *MyLoginScreen = new LoginScreen();
    ui->gridLayout_port->addWidget(MyLoginScreen);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    delete ui;
}
void MainWindow::setMainWindowPointer(QApplication *a){

    MainWindowPointer = a;
}

void MainWindow::setMainMenueScreen(){
    MainMenue *MyMainMenue = new MainMenue();

    QWidget *oldWidget = ui->gridLayout_port->widget();
    ui->gridLayout_port->removeWidget(oldWidget);

    ui->gridLayout_port->addWidget(MyMainMenue);
}
