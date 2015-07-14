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
    bool setMainWindowPointer(QApplication *a);
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

<<<<<<< HEAD
    void on_pushButton_10_clicked();

    void on_pushButton_clicked();
=======
    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);
>>>>>>> 4d3d36e254b49d29208d9378047e18cb58552282

private:
    Ui::SettingsWidget *ui;
    QApplication *MainWindowPointer;
    QString text;
    QString originalText;
    int count;
    int countSetting;
    bool shiftActive;
    bool dirty;
    bool error;
};

#endif // SETTINGSWIDGET_H
