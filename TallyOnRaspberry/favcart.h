#ifndef FAVCART_H
#define FAVCART_H

#include <QWidget>

namespace Ui {
class FavCart;
}

class FavCart : public QWidget
{
    Q_OBJECT

public:
    explicit FavCart(QWidget *parent = 0);
    ~FavCart();

private:
    Ui::FavCart *ui;
};

#endif // FAVCART_H
