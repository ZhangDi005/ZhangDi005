#ifndef CHANNELITEM_H
#define CHANNELITEM_H

#include <QWidget>
#include <QMouseEvent>
#include <QEvent>
#include <QMenu>
#include "Module/app.h"
namespace Ui {
class ChannelItem;
}

class ChannelItem : public QWidget
{
    Q_OBJECT

public:
    explicit ChannelItem(QWidget *parent = nullptr);
    ~ChannelItem();

    void init(Channel channel);

protected:
    bool eventFilter(QObject *obj, QEvent *event);

signals:
    void dataChanged();
    void channelChanged();

private slots:

    void on_delaySpinBox_editingFinished();

    void on_gainSpinBox_editingFinished();

    void on_invert_clicked(bool checked);

    void on_selected_clicked(bool checked);

private:
    Ui::ChannelItem *ui;
    QAction *m_action;
    QMenu *m_menu;
};

#endif // CHANNELITEM_H
