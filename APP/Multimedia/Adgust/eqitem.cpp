#include "eqitem.h"
#include "ui_eqitem.h"

EqItem::EqItem(QString name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EqItem),
    m_channelName(name)
{
    ui->setupUi(this);
}

EqItem::~EqItem()
{
    delete ui;
}

void EqItem::setEqData(int row, EqData eqData)
{
    m_row = row + 1;
    ui->label->setText(QString::number(m_row));
    ui->type->setCurrentIndex(eqData.m_type);
    ui->Order->setCurrentText(QString::number(eqData.m_order));
    ui->spinBox_fc->setValue(eqData.m_fc);
    ui->spinBox_gain->setValue(eqData.m_gain);
    ui->spinBox_q->setValue(eqData.m_q);
    ui->selectedBtn->setChecked(eqData.m_selected);
}

void EqItem::setRow(int row)
{
    m_row = row + 1;
    ui->label->setText(QString::number(m_row));
}

void EqItem::on_type_currentIndexChanged(int index)
{
//    QSignalBlocker blocker(ui->Order);
    switch(index) {
    case FilterType::Parametric: {
        ui->Order->clear();
        QStringList orders;
        orders << "2";
        ui->Order->addItems(orders);
        ui->spinBox_gain->setEnabled(true);
        ui->spinBox_q->setEnabled(true);
        break;
    }
    case FilterType::Bass_Shelf: {
        ui->Order->clear();
        QStringList orders;
        orders << "2";
        ui->Order->addItems(orders);
        ui->spinBox_gain->setEnabled(true);
        ui->spinBox_q->setEnabled(true);
        break;
    }
    case FilterType::Treble_Shelf: {
        ui->Order->clear();
        QStringList orders;
        orders << "2";
        ui->Order->addItems(orders);
        ui->spinBox_gain->setEnabled(true);
        ui->spinBox_q->setEnabled(true);
        break;
    }
    case FilterType::Phase_Changer: {
        ui->Order->clear();
        QStringList orders;
        orders << "2";
        ui->Order->addItems(orders);
        ui->spinBox_gain->setEnabled(false);
        ui->spinBox_q->setEnabled(true);
        break;
    }
    case FilterType::Lowpass_LR: {
        ui->Order->clear();
        QStringList orders;
        orders << "4";
        ui->Order->addItems(orders);
        ui->spinBox_gain->setEnabled(false);
        ui->spinBox_q->setEnabled(false);
        break;
    }
    case FilterType::Highpass_LR: {
        ui->Order->clear();
        QStringList orders;
        orders << "4";
        ui->Order->addItems(orders);
        ui->spinBox_gain->setEnabled(false);
        ui->spinBox_q->setEnabled(false);
        break;
    }
    case FilterType::Lowpass_BW: {
        ui->Order->clear();
        QStringList orders;
        orders << "2" << "4";
        ui->Order->addItems(orders);
        ui->spinBox_gain->setEnabled(false);
        ui->spinBox_q->setEnabled(false);
        break;
    }
    case FilterType::Highpass_BW: {
        ui->Order->clear();
        QStringList orders;
        orders << "2" << "4";
        ui->Order->addItems(orders);
        ui->spinBox_gain->setEnabled(false);
        ui->spinBox_q->setEnabled(false);
        break;
    }
    case FilterType::Bandpass: {
        ui->Order->clear();
        QStringList orders;
        orders << "2";
        ui->Order->addItems(orders);
        ui->spinBox_gain->setEnabled(false);
        ui->spinBox_q->setEnabled(true);
        break;
    }
    case FilterType::Bypass: {
        break;
    }
    }
    QList<Channel> &project = App::instance().getProject();
    for (auto &channel : project) {
        if (channel.channelName == m_channelName) {
            channel.m_eq[m_row-1].m_type = FilterType(index);
        }
    }
    if (ui->selectedBtn->isChecked())
        emit eqDataChanged();
}

void EqItem::on_Order_currentIndexChanged(const QString &arg1)
{
    QList<Channel> &project = App::instance().getProject();
    for (auto &channel : project) {
        if (channel.channelName == m_channelName) {
            channel.m_eq[m_row-1].m_order = arg1.toInt();
        }
    }
//    if (ui->selectedBtn->isChecked())
//        emit eqDataChanged();
}

void EqItem::on_spinBox_fc_editingFinished()
{
    QList<Channel> &project = App::instance().getProject();
    for (auto &channel : project) {
        if (channel.channelName == m_channelName) {
            channel.m_eq[m_row-1].m_fc = ui->spinBox_fc->value();
        }
    }
    if (ui->selectedBtn->isChecked())
        emit eqDataChanged();
}

void EqItem::on_spinBox_gain_editingFinished()
{
    QList<Channel> &project = App::instance().getProject();
    for (auto &channel : project) {
        if (channel.channelName == m_channelName) {
            channel.m_eq[m_row-1].m_gain = ui->spinBox_gain->value();
        }
    }
    if (ui->selectedBtn->isChecked())
        emit eqDataChanged();
}

void EqItem::on_spinBox_q_editingFinished()
{
    QList<Channel> &project = App::instance().getProject();
    for (auto &channel : project) {
        if (channel.channelName == m_channelName) {
            channel.m_eq[m_row-1].m_q = ui->spinBox_q->value();
        }
    }
    if (ui->selectedBtn->isChecked())
        emit eqDataChanged();
}

void EqItem::on_selectedBtn_clicked(bool checked)
{
    QList<Channel> &project = App::instance().getProject();
    for (auto &channel : project) {
        if (channel.channelName == m_channelName) {
            channel.m_eq[m_row-1].m_selected = checked;
        }
    }
    emit eqDataChanged();
}

