#ifndef ADGUSTMAG_H
#define ADGUSTMAG_H

#include <QWidget>
#include <QPair>
#include "Gather/calculatemag.h"
#include "channelitem.h"
#include "Module/app.h"
#include "Module/EQ.h"
#include "eqitem.h"
#include "draftbtn.h"
#include "addchannel.h"

namespace Ui {
class AdgustMag;
}

enum SPACE {
    FRONT = 0,
    REAR
};

enum LOCATION {
    DRIVER = 0,
    PASS,
    ROW
};

class AdgustMag : public QWidget
{
    Q_OBJECT

public:
    explicit AdgustMag(QWidget *parent = nullptr);
    ~AdgustMag();
    void upData();
    void showPlot();
    void aloneShowPort();
//    void rowShowPort(); 右
    void phaseShowPort();
    void setSmooth(SMOOTH smooth);

protected:
    bool eventFilter(QObject* watched, QEvent* event);


private slots:

    void on_spaceComBox_currentIndexChanged(int index);

    void on_locationComBox_currentIndexChanged(int index);

    void on_addBtn_clicked();

    void on_removeBtn_clicked();

    void on_spaceAllBox_currentIndexChanged(int index);

    void on_micLocation_currentIndexChanged(int index);

    void on_startBox_editingFinished();

    void on_stopBox_editingFinished();

    void on_spaceComBox_1_currentIndexChanged(int index);

    void on_locationComBox_1_currentIndexChanged(int index);

    void on_speakerBox_currentIndexChanged(const QString &arg1);

    void on_copyBtn_clicked();

    void on_pasteBtn_clicked();

    void on_checkBox_2_clicked(bool checked);

    void on_checkBox_clicked(bool checked);

private:
    EQ::Eq_ata *getEqata(EqData eqData);
    F_M_P channelToFmp(Channel channel);
    void listWidget_EqClear();
    void dataDelayProces(double delay, QVector<float> &data);
    void dataGainProces(double gain, QVector<float> &data);
    void invert(QVector<float> &data);
    Ui::AdgustMag *ui;
    SPACE m_space = SPACE::FRONT;
    LOCATION m_location = LOCATION::DRIVER;
    SMOOTH smooth = SMOOTH::onetwelfth;
    QString m_copyId;
    QAction *m_action;
    QMenu *m_menu;
};

#endif // ADGUSTMAG_H