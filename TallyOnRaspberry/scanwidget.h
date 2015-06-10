#ifndef SCANWIDGET_H
#define SCANWIDGET_H

#include <QWidget>
#include "shoppingcart.h"
#include <QListWidgetItem>

namespace Ui {
class ScanWidget;
}

class ScanWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ScanWidget(QWidget *parent = 0);
    ~ScanWidget();
    void setMainWindowPointer(QApplication *a,QList<QListWidgetItem> *cartItems);
    QList<QListWidgetItem> getItems();

private:
    Ui::ScanWidget *ui;
    QApplication *MainWindowPointer;
};

#endif // SCANWIDGET_H
