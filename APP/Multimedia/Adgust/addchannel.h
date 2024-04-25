#ifndef ADDCHANNEL_H
#define ADDCHANNEL_H

#include <QDialog>
#include "Module/app.h"

namespace Ui {
class AddChannel;
}

class AddChannel : public QDialog
{
    Q_OBJECT

public:
    explicit AddChannel(QDialog *parent = nullptr);
    ~AddChannel();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddChannel *ui;
};

#endif // ADDCHANNEL_H
