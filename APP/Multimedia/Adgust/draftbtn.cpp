#include "draftbtn.h"
#include "ui_draftbtn.h"

DraftBtn::DraftBtn(int i, QPushButton *parent) :
    QPushButton(parent),
    ui(new Ui::DraftBtn)
{
    ui->setupUi(this);
    this->setText(QString::number(i));
    this->setMaximumSize(QSize(24, 24));
    m_save = new QAction("Save", this);
    m_menu = new QMenu(this);
    m_menu->addAction(m_save);
    connect(m_save, &QAction::triggered, [=]() {
        QList<Channel> project = App::instance().getProject();
        if (project.empty()) return;
        m_project = project;
        this->setStyleSheet("background-color: rgb(255, 255, 0);");
        ;
    });
}

DraftBtn::~DraftBtn()
{
    delete ui;
}

void DraftBtn::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        if (m_project.empty())
            return;
        QList<Channel> &project = App::instance().getProject();
        project = m_project;
        emit upData();
    }
    if(event->button() == Qt::RightButton){
        QPoint pt = rect().bottomLeft();
        QPoint globalPos = this->mapToGlobal(pt);
        m_menu->exec(globalPos);
    }
}
