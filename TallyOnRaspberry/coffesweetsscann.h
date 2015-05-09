#ifndef COFFESWEETSSCANN_H
#define COFFESWEETSSCANN_H

#include <QWidget>

namespace Ui {
class CoffeSweetsScann;
}

class CoffeSweetsScann : public QWidget
{
    Q_OBJECT

public:
    explicit CoffeSweetsScann(QWidget *parent = 0);
    ~CoffeSweetsScann();

private:
    Ui::CoffeSweetsScann *ui;
};

#endif // COFFESWEETSSCANN_H
