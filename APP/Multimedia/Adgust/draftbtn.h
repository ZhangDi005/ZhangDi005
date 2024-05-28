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
    void valid();
signals:
    void backupData(int id);
    void upData(QString remark);

private:
    Ui::DraftBtn *ui;
    QAction * m_save;
    QAction * m_delete;
    QMenu * m_menu;
};

#endif // DRAFTBTN_H
