#ifndef FAVWIDGET_H
#define FAVWIDGET_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class FavWidget;
}

class FavWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FavWidget(QWidget *parent = 0);
    ~FavWidget();
    void setMainWindowPointer(QApplication *a,QString userId,QListWidgetItem *item);
    QList<QListWidgetItem> getItems();
    void forceFavCartUpdate();

private:
    Ui::FavWidget *ui;
    QApplication *MainWindowPointer;
};

#endif // FAVWIDGET_H
