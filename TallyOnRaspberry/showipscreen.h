#ifndef SHOWIPSCREEN_H
#define SHOWIPSCREEN_H

#include <QWidget>

namespace Ui {
class ShowIpScreen;
}

class ShowIpScreen : public QWidget
{
    Q_OBJECT

public:
    explicit ShowIpScreen(QWidget *parent = 0);
    void setMainWindowPointer(QApplication *gMainWindowPointer,QString text);
    ~ShowIpScreen();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ShowIpScreen *ui;
    QApplication *MainWindowPointer;
};

#endif // SHOWIPSCREEN_H
