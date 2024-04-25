#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btn_import_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "open file", "C:\\Users\\ari_m\\Desktop", "(*.info)");
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream stream(&file);
        stream>>m_id;
        file.close();
    }
}

void Dialog::on_btn_create_clicked()
{
    if (m_id == "") {
        QMessageBox::question(this, "error", "generate error!",  QMessageBox::Ok);
        this->close();
        return;
    }
    QAESEncryption encryption(QAESEncryption::AES_128, QAESEncryption::ECB , QAESEncryption::ISO);
    QByteArray input = m_id.toLocal8Bit();
    QByteArray key = QString("960417").toLocal8Bit();
    QByteArray license = encryption.encode(input, key);
    QString fileName = QFileDialog::getExistingDirectory(this, "save file", "C:\\Users\\ari_m\\Desktop");
    if (fileName == "") return;
    fileName += "\\";
    fileName += "MultimediaLicense.lic";
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        QDataStream stream(&file);
        stream<<license;
        file.close();
    }
    close();
}
