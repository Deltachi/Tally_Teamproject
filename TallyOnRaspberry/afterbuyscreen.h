#ifndef AFTERBUYSCREEN_H
#define AFTERBUYSCREEN_H

#include <QWidget>

namespace Ui {
class AfterBuyScreen;
}

class AfterBuyScreen : public QWidget
{
    Q_OBJECT

public:
    explicit AfterBuyScreen(QWidget *parent = 0);
    ~AfterBuyScreen();

private:
    Ui::AfterBuyScreen *ui;
};

#endif // AFTERBUYSCREEN_H
