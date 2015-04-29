#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QApplication *MainWindowPointer;
};

#endif // MAINWINDOW_H
