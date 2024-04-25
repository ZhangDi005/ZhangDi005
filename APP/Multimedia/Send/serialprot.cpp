#include "serialprot.h"
#include "ui_serialprot.h"
#include <QMetaType>

SerialProt::SerialProt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SerialProt)
{
    ui->setupUi(this);
    refreshPort();
}

SerialProt::~SerialProt()
{
    delete ui;
    if (m_sendF != nullptr)
        m_sendF->deleteLater();
    if (m_t != nullptr)
        m_t->deleteLater();
    if (m_serial != nullptr)
        m_serial->deleteLater();
}

void SerialProt::refreshPort()
{
    ui->portBox->clear();
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts()) {
        ui->portBox->addItem(info.portName());
    }
}

void SerialProt::closeThread()
{
    if (m_t != nullptr && m_t->isRunning()) {
        m_t->requestInterruption();
        m_t->quit();
        m_t->wait();
    }
}

void SerialProt::on_refresh_clicked()
{
    refreshPort();
}

void SerialProt::on_openSerial_clicked()
{
    if (ui->portBox->currentText() == "")
        return;
    if (m_serial == nullptr) {
        m_serial = new QSerialPort;
    }
    m_serial->setPortName(ui->portBox->currentText());
    m_serial->open(QIODevice::ReadWrite);
    if (m_serial->isOpen()) {
        m_serial->setBaudRate(QSerialPort::Baud115200);
        m_serial->setParity(QSerialPort::NoParity);
        m_serial->setDataBits(QSerialPort::Data8);
        m_serial->setStopBits(QSerialPort::OneStop);
        m_serial->setFlowControl(QSerialPort::NoFlowControl);
        ui->led->setStyleSheet("background-color: rgb(0, 255, 0);");
        connect(m_serial, SIGNAL(readyRead()), this, SLOT(readData()));
    } else {
        QMessageBox::warning(this, "警告", "串口打开失败");
    }
}

void SerialProt::on_selectPath_clicked()
{
    QString FileName = QFileDialog::getOpenFileName();
    ui->filePath->setText(FileName);
}

void SerialProt::on_downLoad_clicked()
{
    QFile file(ui->filePath->text());
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "错误", ui->filePath->text() + "文件打开失败" + file.errorString());
        return;
    }
    QByteArray data = file.readAll();
    file.close();

    if (m_sendF == nullptr) {
        m_sendF = new ThreadWork;
        connect(this, &SerialProt::sendFile, m_sendF, &ThreadWork::working);
        connect(m_sendF, &ThreadWork::sendProgressBar, this, [=](int porB){
            ui->progressBar->setValue(porB);
        });
    }
    if (m_t == nullptr)
        m_t = new QThread;
    m_serial->moveToThread(m_t);
    m_sendF->moveToThread(m_t);
    emit sendFile(m_serial, data);
    m_t->start();
}


void SerialProt::on_closeSerial_clicked()
{
    if (m_serial != nullptr) {
        m_serial->close();
        m_serial->deleteLater();
        m_serial = nullptr;
        ui->led->setStyleSheet("background-color: rgb(255, 0, 0);");
    }
}

void SerialProt::readData()
{
    QByteArray array = m_serial->readAll();
}

void SerialProt::on_cancel_clicked()
{
    closeThread();
}
