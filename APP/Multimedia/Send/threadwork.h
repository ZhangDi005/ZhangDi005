#ifndef THREADWORK_H
#define THREADWORK_H
#include <QObject>
#include <QSerialPort>
#include <QThread>
#include <QDebug>

class ThreadWork :public QObject
{
    Q_OBJECT
public:
    ThreadWork() {}
    ~ThreadWork() {}

    void working(QSerialPort* serial, QByteArray data) {
        int count = 0;
        while (count < 100) {
            if (QThread::currentThread()->isInterruptionRequested()) {
                emit sendProgressBar(0);
                return;
            }

            count++;
            QThread::sleep(1);
            emit sendProgressBar(count %100);
        }
        serial->write(data);
    }
signals:
    void sendProgressBar(int proBar);
};

#endif // THREADWORK_H
