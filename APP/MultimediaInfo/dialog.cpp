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


void Dialog::on_btn_create_clicked()
{
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

    QString fileName = QFileDialog::getExistingDirectory(this, "save file", "C:\\Users\\ari_m\\Desktop");
    if (fileName == "") return;
    fileName += "\\";
    fileName += QHostInfo::localHostName();
    fileName += "-MultimediaInfoGenerate.info";
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        QDataStream stream(&file);
        stream << result;
        file.close();
    }
    close();
}
