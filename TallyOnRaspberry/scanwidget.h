#ifndef SCANWIDGET_H
#define SCANWIDGET_H

#include <QWidget>

namespace Ui {
class ScanWidget;
}

class ScanWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ScanWidget(QWidget *parent = 0);
    ~ScanWidget();

private:
    Ui::ScanWidget *ui;
};

#endif // SCANWIDGET_H
