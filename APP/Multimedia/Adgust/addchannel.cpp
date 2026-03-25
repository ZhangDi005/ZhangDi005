#include "addchannel.h"
#include "ui_addchannel.h"

AddChannel::AddChannel(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::AddChannel)
{
    ui->setupUi(this);
}

AddChannel::~AddChannel()
{
    delete ui;
}

Channel AddChannel::getChannel()
{
    return this->channel;
}

void AddChannel::on_pushButton_clicked()
{
    close();
}

void AddChannel::on_pushButton_2_clicked()
{
    QString name = ui->nameEdit->text();
    if (name == "")
        return;
    channel.channelName = "*" + name;
    channel.isTargetCurve = true;
    channel.m_channelData.m_gain = ui->doubleSpinBox->value();
    this->accept();
    close();
}
