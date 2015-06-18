#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QWidget>
#include <QListWidgetItem>

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
    QList<QListWidgetItem> getItems();
    void addItem(QListWidgetItem *item);
    void disableBackButton();
    void updatePrice();

private slots:
    void on_pushButton_back_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::Shoppingcart *ui;
    QApplication *MainWindowPointer;
    double price;
};

#endif // SHOPPINGCART_H
