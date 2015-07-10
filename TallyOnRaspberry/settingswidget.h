#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QWidget>

namespace Ui {
class SettingsWidget;
}

class SettingsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsWidget(QWidget *parent = 0);
    ~SettingsWidget();
    void setMainWindowPointer(QApplication *a);
    QString findLineWithText(QString findThis);
    void replaceLineWithText(QString replaceHere,QString writeThis);

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_Shift_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_Hashtag_clicked();

    void on_pushButton_backwards_clicked();

    void on_pushButton_forward_clicked();

    void on_pushButton_accept_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_next_clicked();

private:
    Ui::SettingsWidget *ui;
    QApplication *MainWindowPointer;
    QString text;
    QString originalText;
    int count;
    int countSetting;
    bool shiftActive;
    bool dirty;
};

#endif // SETTINGSWIDGET_H
