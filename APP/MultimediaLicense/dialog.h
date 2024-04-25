#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include <QDataStream>
#include <QMessageBox>
#include "qaesencryption.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_btn_import_clicked();

    void on_btn_create_clicked();

private:
    Ui::Dialog *ui;
    QString m_id;
};
#endif // DIALOG_H
