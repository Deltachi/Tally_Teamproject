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
    void setMainWindowPointer(QApplication *a,QList<QListWidgetItem> *cartItems,QString gUserId,QListWidgetItem *item);
    QList<QListWidgetItem> getItems();

private slots:
    void on_pushButton_plus_clicked();

    void on_pushButton_minus_clicked();

    void on_pushButton_add_clicked();

private:
    Ui::ScanWidget *ui;
    QApplication *MainWindowPointer;
    QString userId;
    int count;
    QString itemId;
};

#endif // SCANWIDGET_H
