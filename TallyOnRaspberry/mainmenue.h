#ifndef MAINMENUE_H
#define MAINMENUE_H

#include <QWidget>

namespace Ui {
class MainMenue;
}

class MainMenue : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenue(QWidget *parent = 0);
    ~MainMenue();

private:
    Ui::MainMenue *ui;
    QApplication *MainWindowPointer;
};

#endif // MAINMENUE_H
