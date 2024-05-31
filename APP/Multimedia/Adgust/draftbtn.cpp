#include "draftbtn.h"
#include "ui_draftbtn.h"

DraftBtn::DraftBtn(int i, QPushButton *parent) :
    QPushButton(parent),
    ui(new Ui::DraftBtn)
{
    ui->setupUi(this);
    this->setCheckable(true);
    this->setChecked(false);
    this->setStyleSheet("QPushButton{width: 26px; height: 26px;border: 2px solid #FFFFFF;}");
    this->setText(QString::number(i));

    m_save = new QAction("Save", this);
    m_delete = new QAction("Delete", this);
    m_menu = new QMenu(this);
    m_menu->addAction(m_save);
    m_menu->addAction(m_delete);
    connect(m_save, &QAction::triggered, [=]() {
        emit backupData(text().toInt());
        valid();
    });
    connect(m_delete, &QAction::triggered, [=]() {
        App::instance().syncDelete(text().toInt());
        this->setStyleSheet("QPushButton{width: 26px; height: 26px;border: 2px solid #FFFFFF;}");
    });
}

DraftBtn::~DraftBtn()
{
    delete ui;
}

void DraftBtn::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        setChecked(!isChecked());
        QList<Channel> &project = App::instance().getProject();
        QList<BackupData> all = App::instance().getBackupData();
        BackupData alone;
        bool flag = false;
        for (BackupData backData : all) {
            if (backData.m_flag == text().toInt()) {
                alone = backData;
                flag = true;
                break;
            }
        }
        for (auto &channel : project) {
            if (!alone.m_overAll.contains(channel.channelName)) continue;
            OverAll overall = alone.m_overAll.value(channel.channelName);
            channel.m_channelData = overall.m_channelData;
            channel.m_eq = overall.m_eq;
        }
        if (flag) {
            emit upData(alone.m_remark);
        }
    }
    if(event->button() == Qt::RightButton){
        QPoint pt = rect().bottomLeft();
        QPoint globalPos = this->mapToGlobal(pt);
        m_menu->exec(globalPos);
    }
}

void DraftBtn::valid()
{
    this->setStyleSheet("QPushButton{width: 26px; height: 26px;border: 2px solid #00FF00; background: transparent;}\
                         QPushButton:checked{width: 26px; height: 26px;border: 2px solid #00FF00; background-color: rgb(0, 255, 0);}");

}
