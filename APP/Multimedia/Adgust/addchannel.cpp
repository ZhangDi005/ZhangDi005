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

void AddChannel::on_pushButton_clicked()
{
    close();
}

void AddChannel::on_pushButton_2_clicked()
{
    QString name = ui->nameEdit->text();
    if (name == "")
        return;
    QList<Channel> &project = App::instance().getProject();
    Channel channel;
    channel.channelName = "*" + name;
    channel.isTargetCurve = true;
    channel.m_channelData.m_gain = ui->doubleSpinBox->value();
    project.push_back(channel);
    this->accept();
    close();
}
