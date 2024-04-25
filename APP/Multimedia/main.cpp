#include "mainwindow.h"
#include <QProcess>
#include <QApplication>
#include <QMessageBox>
#include <QCryptographicHash>
#include "Module/qaesencryption.h"
#include "LodeQss.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont f("微软雅黑",8);
    a.setFont(f);
    LoadQss::loadQss(":/qss/two.qss");
    QString cmd="wmic csproduct get uuid";
    QProcess p;
    p.start(cmd);
    p.waitForFinished();
    QString result = QString::fromLocal8Bit(p.readAllStandardOutput());
    QStringList list = cmd.split(" ");
    result = result.remove(list.last(), Qt::CaseInsensitive);
    result = result.replace("\r", "");
    result = result.replace("\n", "");
    result = result.simplified();

    QString Licensepath = QCoreApplication::applicationDirPath() + "/License/MultimediaLicense.lic";
    QFile file(Licensepath);
    if (!file.exists())
    {
        if (QMessageBox::Yes == QMessageBox::question(nullptr, "", "是否导入License?", QMessageBox::No, QMessageBox::Yes))
        {
            QString importFile = QFileDialog::getOpenFileName(nullptr, "C:\\Users\\ari_m\\Desktop", "*.lic");
            if (!importFile.isEmpty())
            {
                if (!QFile::copy(importFile, Licensepath))
                {
                    QMessageBox::question(nullptr, "", "");
                }
            }
            else
                return 0;
        }
        else
            return 0;
    }
    QFile filelic(Licensepath);
    QByteArray licAry;
    if (filelic.open(QIODevice::ReadOnly)) {
        QDataStream stream(&filelic);
        stream>>licAry;
        filelic.close();
    }
    QByteArray key = QString("960417").toLocal8Bit();
    QAESEncryption encryption(QAESEncryption::AES_128, QAESEncryption::ECB , QAESEncryption::ISO);
    QByteArray decodedText = encryption.decode(licAry, key);
    QString decodedString = QString(QAESEncryption::RemovePadding(decodedText,QAESEncryption::ISO));

//    {
//        QString inputStr("The Advanced Encryption Standard (AES), also known by its original name Rijndael "
//                         "is a specification for the encryption of electronic data established by the U.S. "
//                         "National Institute of Standards and Technology (NIST) in 2001");
//        QString key("your-string-key");
//        QString iv("your-IV-vector");

//        QByteArray hashKey = QCryptographicHash::hash(key.toLocal8Bit(), QCryptographicHash::Sha256);
//        QByteArray hashIV = QCryptographicHash::hash(iv.toLocal8Bit(), QCryptographicHash::Md5);

//        //Static invocation
//        QByteArray encodeText = QAESEncryption::Crypt(QAESEncryption::AES_256, QAESEncryption::CBC,
//                                                      inputStr.toLocal8Bit(), hashKey, hashIV);
//        QByteArray decodeText = QAESEncryption::Decrypt(QAESEncryption::AES_256,QAESEncryption::CBC,encodeText, hashKey, hashIV);

//        // Removal of Padding via Static function
//        QString decodedString = QString(QAESEncryption::RemovePadding(decodeText,QAESEncryption::ISO));
//        qDebug() << decodedString;
//    }
//    /****************************************************************************************************/
//    {
//        QAESEncryption encryption(QAESEncryption::AES_256, QAESEncryption::CBC);

//        QString inputStr("The Advanced Encryption Standard (AES), also known by its original name Rijndael "
//                         "is a specification for the encryption of electronic data established by the U.S. "
//                         "National Institute of Standards and Technology (NIST) in 2001");
//        QString key("your-string-key");
//        QString iv("your-IV-vector");

//        QByteArray hashKey = QCryptographicHash::hash(key.toLocal8Bit(), QCryptographicHash::Sha256);
//        QByteArray hashIV = QCryptographicHash::hash(iv.toLocal8Bit(), QCryptographicHash::Md5);

//        QByteArray encodeText = encryption.encode(inputStr.toLocal8Bit(), hashKey, hashIV);
//        QByteArray decodeText = encryption.decode(encodeText, hashKey, hashIV);

//        QString decodedString = QString(encryption.removePadding(decodeText));

//        qDebug() << decodedString;
//    }
//    if (decodedString != result) {
//        QMessageBox::question(nullptr, "error", "no access");
//        return -1;
//    }
    MainWindow w;
    w.show();
    return a.exec();
}
