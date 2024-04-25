#ifndef DRAFTBTN_H
#define DRAFTBTN_H

#include <QPushButton>
#include <QMenu>
#include <QMouseEvent>
#include "Module/app.h"

namespace Ui {
class DraftBtn;
}

class DraftBtn : public QPushButton
{
    Q_OBJECT

public:
    explicit DraftBtn(int i, QPushButton *parent = nullptr);
    ~DraftBtn();
    void mousePressEvent(QMouseEvent *event);
signals:
    void upData();

private:
    Ui::DraftBtn *ui;
    QAction * m_save;
    QMenu * m_menu;
    QList<Channel> m_project;
};

#endif // DRAFTBTN_H
