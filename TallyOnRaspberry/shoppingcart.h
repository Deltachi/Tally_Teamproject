#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QWidget>

namespace Ui {
class Shoppingcart;
}

class Shoppingcart : public QWidget
{
    Q_OBJECT

public:
    explicit Shoppingcart(QWidget *parent = 0);
    ~Shoppingcart();
    bool isEmpyt();
    void setMainWindowPointer(QApplication *a);
    void addSomething(QString text);
    void clear();

private slots:
    void on_pushButton_back_clicked();

private:
    Ui::Shoppingcart *ui;
    QApplication *MainWindowPointer;
};

#endif // SHOPPINGCART_H
