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

private:
    Ui::Shoppingcart *ui;
};

#endif // SHOPPINGCART_H
