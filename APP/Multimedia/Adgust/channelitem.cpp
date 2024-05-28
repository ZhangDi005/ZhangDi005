#include "channelitem.h"
#include "ui_channelitem.h"

ChannelItem::ChannelItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChannelItem)
{
    ui->setupUi(this);
    this->installEventFilter(this);
    m_action = new QAction("remove", this);
    m_menu = new QMenu(this);
    m_menu->addAction(m_action);
    connect(m_action, &QAction::triggered, [=](){
        QList<Channel> &project = App::instance().getProject();
        for (int i = 0; i < project.size(); i++) {
            if (project.at(i).channelName == ui->name->text()) {
                project.removeAt(i);
                break;
            }
        }
        emit channelChanged();
    });
}

ChannelItem::~ChannelItem()
{
    delete ui;
}

void ChannelItem::init(Channel channel)
{
    ui->selected->setChecked(channel.m_channelData.m_selected);
    ui->name->setText(channel.channelName);
    ui->gainSpinBox->setValue(channel.m_channelData.m_gain);
    if (channel.isTargetCurve) {
        ui->delaySpinBox->setEnabled(false);
        ui->invert->setEnabled(false);
        return;
    }
    ui->delaySpinBox->setValue(channel.m_channelData.m_delay);
    ui->invert->setChecked(channel.m_channelData.m_invert);
}

bool ChannelItem::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == this) {
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *e = static_cast<QMouseEvent *>(event);
            if(e->button() == Qt::RightButton) {
                QList<Channel> &project = App::instance().getProject();
                for (int i = 0; i < project.size(); i++) {
                    if (project.at(i).channelName == ui->name->text()) {
                        if (project.at(i).isTargetCurve) {
                            m_menu->exec(QCursor::pos());
                            break;
                        }
                    }
                }
                return true;
            }
        }
    }
    return QWidget::eventFilter(obj, event);
}

void ChannelItem::on_delaySpinBox_editingFinished()
{
    QList<Channel> &project = App::instance().getProject();
    for (auto &channel : project) {
        if (channel.channelName == ui->name->text()) {
            channel.m_channelData.m_delay = ui->delaySpinBox->value();
            break;
        }
    }
    if (ui->selected->isChecked())
        emit dataChanged();
}

void ChannelItem::on_gainSpinBox_editingFinished()
{
    QList<Channel> &project = App::instance().getProject();
    for (auto &channel : project) {
        if (channel.channelName == ui->name->text()) {
            channel.m_channelData.m_gain = ui->gainSpinBox->value();
            break;
        }
    }
    if (ui->selected->isChecked())
        emit dataChanged();
}

void ChannelItem::on_invert_clicked(bool checked)
{
    QList<Channel> &project = App::instance().getProject();
    for (auto &channel : project) {
        if (channel.channelName == ui->name->text()) {
            channel.m_channelData.m_invert = checked;
            break;
        }
    }
    if (ui->selected->isChecked())
        emit dataChanged();
}

void ChannelItem::on_selected_clicked(bool checked)
{
    QList<Channel> &project = App::instance().getProject();
    for (auto &channel : project) {
        if (channel.channelName == ui->name->text()) {
            channel.m_channelData.m_selected = checked;
            break;
        }
    }
    emit dataChanged();
}
