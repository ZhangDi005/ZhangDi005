#ifndef SERIALPROT_H
#define SERIALPROT_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QFileDialog>
#include <QMessageBox>
#include <QThread>
#include "threadwork.h"


namespace Ui {
class SerialProt;
}

class SerialProt : public QWidget
{
    Q_OBJECT

public:
    explicit SerialProt(QWidget *parent = nullptr);
    ~SerialProt();

    void closeThread();
private slots:
    void on_refresh_clicked();

    void on_openSerial_clicked();

    void on_selectPath_clicked();

    void on_downLoad_clicked();

    void on_closeSerial_clicked();

    void readData();

    void on_cancel_clicked();

private:
    void refreshPort();
signals:
    void sendFile(QSerialPort* serial, QByteArray data);

private:
    Ui::SerialProt *ui;
    QSerialPort* m_serial = nullptr;
    QThread *m_t = nullptr;
    ThreadWork *m_sendF = nullptr;
};

#endif // SERIALPROT_H
