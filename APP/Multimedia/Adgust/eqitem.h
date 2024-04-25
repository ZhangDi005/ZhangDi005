#ifndef EQITEM_H
#define EQITEM_H

#include <QWidget>
#include "Module/app.h"

namespace Ui {
class EqItem;
}

class EqItem : public QWidget
{
    Q_OBJECT

public:
    explicit EqItem(QString name, QWidget *parent = nullptr);
    ~EqItem();

    void setEqData(int row, EqData eqData);
    void setRow(int row);

signals:
    void eqDataChanged();

private slots:
    void on_type_currentIndexChanged(int index);

    void on_spinBox_fc_editingFinished();

    void on_spinBox_gain_editingFinished();

    void on_spinBox_q_editingFinished();

    void on_selectedBtn_clicked(bool checked);

    void on_Order_currentIndexChanged(const QString &arg1);

private:
    Ui::EqItem *ui;
    QString m_channelName;
    int m_row = 0;
};

#endif // EQITEM_H
