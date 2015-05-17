#ifndef COFFESWEETSSCANN_H
#define COFFESWEETSSCANN_H

#include <QWidget>

namespace Ui {
class CoffeSweetsScann;
}

class CoffeSweetsScann : public QWidget
{
    Q_OBJECT

public:
    explicit CoffeSweetsScann(QWidget *parent = 0);
    ~CoffeSweetsScann();
    void setMainWindowPointer(QApplication *a);
    void setQWidget(QWidget *a);

private slots:
    void on_pushButton_coffee_clicked();

    void on_pushButton_sweets_clicked();

    void on_pushButton_scan_clicked();

private:
    Ui::CoffeSweetsScann *ui;
    QApplication *mainWindowPointer;
};

#endif // COFFESWEETSSCANN_H
