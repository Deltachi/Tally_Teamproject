#include "settingswidget.h"
#include "ui_settingswidget.h"
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QProcess>
#include <QMessageBox>
#include <QtNetwork/QNetworkInterface>
#include <QtNetwork/QNetworkConfigurationManager>
#include <QtNetwork/QNetworkSession>
#include <QtNetwork/QTcpSocket>

SettingsWidget::SettingsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsWidget)
{
    ui->setupUi(this);
    error = false;
}

SettingsWidget::~SettingsWidget()
{
    delete ui;
}
bool SettingsWidget::setMainWindowPointer(QApplication *a){
    MainWindowPointer = a;
    text = " ";
    count = 0;
    shiftActive = false;
    text = this->findLineWithText("wpa-ssid \"");
    ui->lineEdit->setText(text);
    ui->label_SettingName->setText("wpa-ssid:");
    countSetting = 0;
    count = text.length()-1;
    ui->lineEdit->setSelection(count,count);
    return !error;
}
QString SettingsWidget::findLineWithText(QString findThis){
    Interface_Path

    QFile file(filename);
    QString s;
    if(file.open(QIODevice::ReadWrite)){
        QTextStream stream(&file);
        while(!stream.atEnd()){
            QString line = stream.readLine();

            if(line.contains(findThis)){
                line.remove(0,findThis.length());
                s.append(line);
                file.close();
                for(int i=0;i<s.length();i++){
                    if(s.at(i) == '\"'){
                        s.remove(i,s.length()-i+1);
                        break;
                    }
                }
                return s;
            }
        }
        file.close();
    }else{
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(NULL, QObject::tr("Warning"), QObject::tr(qPrintable("Could not find:\r\n \"" + filename + "\"\r\nWLAN configuration wont work.\r\n:(")),QMessageBox::Close);
        error = true;
    }
    return s;
}
void SettingsWidget::replaceLineWithText(QString replaceHere,QString writeThis){
   Interface_Path
    QFile file(filename);
    QString s;
    if(file.open(QIODevice::ReadWrite | QIODevice::Text)){
        QTextStream stream(&file);
        while(!stream.atEnd()){
            QString line = stream.readLine();

            if(line.contains(replaceHere)){
                s.append(replaceHere + writeThis + "\"\r\n");
            }else{
                s.append(line + "\r\n");
            }
        }
        file.resize(0);
        stream << s;
        file.close();
    }else{
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(NULL, QObject::tr("Warning"), QObject::tr(qPrintable("Could not find:\r\n \"" + filename + "\"\r\nWLAN configuration wont work.\r\n:(")),QMessageBox::Close);
        error = true;
    }
}

void SettingsWidget::on_pushButton_1_clicked()
{
    switch(text.at(count).toAscii()){
        default : text.replace(count,1,'1'); break;
    }
    ui->lineEdit->setText(text);
    ui->lineEdit->setSelection(count,count);
}

void SettingsWidget::on_pushButton_2_clicked()
{
    if(shiftActive){
        switch((int)text.at(count).toAscii()){
            case 50: text.replace(count,1,'A'); break;
            case 65: text.replace(count,1,'B'); break;
            case 66: text.replace(count,1,'C'); break;
        default : text.replace(count,1,'2'); break;
        }
    }else{
        switch((int)text.at(count).toAscii()){
            case 50: text.replace(count,1,'a'); break;
            case 97: text.replace(count,1,'b'); break;
            case 98: text.replace(count,1,'c'); break;
        default : text.replace(count,1,'2'); break;
        }
    }
    ui->lineEdit->setText(text);
    ui->lineEdit->setSelection(count,count);
}

void SettingsWidget::on_pushButton_3_clicked()
{
    if(shiftActive){
        switch((int)text.at(count).toAscii()){
            case 51: text.replace(count,1,'D'); break;
            case 68: text.replace(count,1,'E'); break;
            case 69: text.replace(count,1,'F'); break;
        default : text.replace(count,1,'3'); break;
        }
    }else{
        switch((int)text.at(count).toAscii()){
            case 51: text.replace(count,1,'d'); break;
            case 100: text.replace(count,1,'e'); break;
            case 101: text.replace(count,1,'f'); break;
        default : text.replace(count,1,'3'); break;
        }
    }
    ui->lineEdit->setText(text);
    ui->lineEdit->setSelection(count,count);
}

void SettingsWidget::on_pushButton_4_clicked()
{
    if(shiftActive){
        switch((int)text.at(count).toAscii()){
            case 52: text.replace(count,1,'G'); break;
            case 71: text.replace(count,1,'H'); break;
            case 72: text.replace(count,1,'I'); break;
        default : text.replace(count,1,'4'); break;
        }
    }else{
        switch((int)text.at(count).toAscii()){
            case 52: text.replace(count,1,'g'); break;
            case 103: text.replace(count,1,'h'); break;
            case 104: text.replace(count,1,'i'); break;
        default : text.replace(count,1,'4'); break;
        }
    }
    ui->lineEdit->setText(text);
    ui->lineEdit->setSelection(count,count);
}

void SettingsWidget::on_pushButton_5_clicked()
{
    if(shiftActive){
        switch((int)text.at(count).toAscii()){
            case 53: text.replace(count,1,'J'); break;
            case 74: text.replace(count,1,'K'); break;
            case 75: text.replace(count,1,'L'); break;
        default : text.replace(count,1,'5'); break;
        }
    }else{
        switch((int)text.at(count).toAscii()){
            case 53: text.replace(count,1,'j'); break;
            case 106: text.replace(count,1,'k'); break;
            case 107: text.replace(count,1,'l'); break;
        default : text.replace(count,1,'5'); break;
        }
    }
    ui->lineEdit->setText(text);
    ui->lineEdit->setSelection(count,count);
}

void SettingsWidget::on_pushButton_6_clicked()
{
    if(shiftActive){
        switch((int)text.at(count).toAscii()){
            case 54: text.replace(count,1,'M'); break;
            case 77: text.replace(count,1,'N'); break;
            case 78: text.replace(count,1,'O'); break;
        default : text.replace(count,1,'6'); break;
        }
    }else{
        switch((int)text.at(count).toAscii()){
            case 54: text.replace(count,1,'m'); break;
            case 109: text.replace(count,1,'n'); break;
            case 110: text.replace(count,1,'o'); break;
        default : text.replace(count,1,'6'); break;
        }
    }
    ui->lineEdit->setText(text);
    ui->lineEdit->setSelection(count,count);
}

void SettingsWidget::on_pushButton_7_clicked()
{
    if(shiftActive){
        switch((int)text.at(count).toAscii()){
            case 55: text.replace(count,1,'P'); break;
            case 80: text.replace(count,1,'Q'); break;
            case 81: text.replace(count,1,'R'); break;
            case 82: text.replace(count,1,'S'); break;
        default : text.replace(count,1,'7'); break;
        }
    }else{
        switch((int)text.at(count).toAscii()){
            case 55: text.replace(count,1,'p'); break;
            case 112: text.replace(count,1,'q'); break;
            case 113: text.replace(count,1,'r'); break;
            case 114: text.replace(count,1,'s'); break;
        default : text.replace(count,1,'7'); break;
        }
    }
    ui->lineEdit->setText(text);
    ui->lineEdit->setSelection(count,count);
}

void SettingsWidget::on_pushButton_8_clicked()
{
    if(shiftActive){
        switch((int)text.at(count).toAscii()){
            case 56: text.replace(count,1,'T'); break;
            case 84: text.replace(count,1,'U'); break;
            case 85: text.replace(count,1,'V'); break;
        default : text.replace(count,1,'8'); break;
        }
    }else{
        switch((int)text.at(count).toAscii()){
            case 56: text.replace(count,1,'t'); break;
            case 116: text.replace(count,1,'u'); break;
            case 117: text.replace(count,1,'v'); break;
        default : text.replace(count,1,'8'); break;
        }
    }
    ui->lineEdit->setText(text);
    ui->lineEdit->setSelection(count,count);
}

void SettingsWidget::on_pushButton_9_clicked()
{
    if(shiftActive){
        switch((int)text.at(count).toAscii()){
            case 57: text.replace(count,1,'W'); break;
            case 87: text.replace(count,1,'X'); break;
            case 88: text.replace(count,1,'Y'); break;
            case 89: text.replace(count,1,'Z'); break;
        default : text.replace(count,1,'9'); break;
        }
    }else{
        switch((int)text.at(count).toAscii()){
            case 57: text.replace(count,1,'w'); break;
            case 119: text.replace(count,1,'x'); break;
            case 120: text.replace(count,1,'y'); break;
            case 121: text.replace(count,1,'z'); break;
        default : text.replace(count,1,'9'); break;
        }
    }
    ui->lineEdit->setText(text);
    ui->lineEdit->setSelection(count,count);
}

void SettingsWidget::on_pushButton_Shift_clicked()
{
    if(shiftActive){
        ui->pushButton_2->setText("2 abc");
        ui->pushButton_3->setText("3 def");
        ui->pushButton_4->setText("4 ghi");
        ui->pushButton_5->setText("5 jkl");
        ui->pushButton_6->setText("6 mno");
        ui->pushButton_7->setText("7 pqrs");
        ui->pushButton_8->setText("8 tuv");
        ui->pushButton_9->setText("9 wxyz");
        ui->pushButton_Shift->setText("shift");
        shiftActive = false;
    }else{
        ui->pushButton_2->setText("2 ABC");
        ui->pushButton_3->setText("3 DEF");
        ui->pushButton_4->setText("4 GHI");
        ui->pushButton_5->setText("5 JKL");
        ui->pushButton_6->setText("6 MNO");
        ui->pushButton_7->setText("7 PQRS");
        ui->pushButton_8->setText("8 TUV");
        ui->pushButton_9->setText("9 WXYZ");
        ui->pushButton_Shift->setText("SHIFT");
        shiftActive = true;
    }
}

void SettingsWidget::on_pushButton_0_clicked()
{
    switch(text.at(count).toAscii()){
        case 30: text.replace(count,1,' '); break;
        default : text.replace(count,1,'0'); break;
    }
    ui->lineEdit->setText(text);
    ui->lineEdit->setSelection(count,count);
}

void SettingsWidget::on_pushButton_Hashtag_clicked()
{
    switch((int)text.at(count).toAscii()){
        case 23: text.replace(count,1,'!'); break;
        case 21: text.replace(count,1,'?'); break;
    default : text.replace(count,1,'#'); break;
    }
    ui->lineEdit->setText(text);
    ui->lineEdit->setSelection(count,count);
}

void SettingsWidget::on_pushButton_backwards_clicked()
{
    if(count > 0){
        count--;
    }
    ui->lineEdit->setSelection(count,count);
}

void SettingsWidget::on_pushButton_forward_clicked()
{
    count++;
    if(count >= text.length()){
        text.append(32);
    }
    ui->lineEdit->setText(text);
    ui->lineEdit->setSelection(count,count);
}

void SettingsWidget::on_pushButton_accept_clicked()
{
    ui->pushButton_back->setText("Res LAN");
    if(countSetting == 0){
        this->replaceLineWithText("wpa-ssid \"",text);
    }else{
        this->replaceLineWithText("wpa-psk \"",text);
    }
}

void SettingsWidget::on_pushButton_delete_clicked()
{
    if(count > 0){
        text.remove(text.length()-1,1);
        count--;
        ui->lineEdit->setText(text);
        ui->lineEdit->setSelection(count,count);
    }
}

void SettingsWidget::on_pushButton_back_clicked()
{
    MainWindowPointer->exit(71);
}

void SettingsWidget::on_pushButton_next_clicked()
{
    if(countSetting == 1){
        countSetting = 0;
        ui->label_SettingName->setText("wpa-ssid:");
        text = this->findLineWithText("wpa-ssid \"");
    }else{
        countSetting = 1;
        ui->label_SettingName->setText("wpa-psk:");
        text = this->findLineWithText("wpa-psk \"");
    }
    count = text.length()-1;
    ui->lineEdit->setText(text);
    ui->lineEdit->setSelection(count,count);
}

void SettingsWidget::on_pushButton_10_clicked() //showip
{
    QString ip;
    foreach(const QHostAddress &address,QNetworkInterface::allAddresses()){
        ip.append(address.toString()+"\r\n");
    }
    QMessageBox::StandardButton reply;
    reply = QMessageBox::information(NULL, QObject::tr("Ips:"), QObject::tr(qPrintable("Tally found this:\r\n \"" + ip)),QMessageBox::Close);
}

void SettingsWidget::on_pushButton_clicked()//reset lan
{
    QProcess process;
    process.start("sudo service networking restart");
}
