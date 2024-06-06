#ifndef ADGUSTMAG_H
#define ADGUSTMAG_H

#include <QWidget>
#include <QPair>
#include <QButtonGroup>
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
    REAR,
    ROW_ALL
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
    void upDataRemark();
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

    void on_modeSpeakerBox_currentIndexChanged(int index);

private:
    EQ::Eq_ata *getEqata(EqData eqData);
    F_M_P channelToFmp(Channel channel);
    void dataDelayProces(double delay, QVector<float> &data);
    void dataGainProces(double gain, QVector<float> &data);
    void invert(QVector<float> &data);
    QVector<float> AddToOnleOne(Channel channel, int loca);
    QVector<F_M_P> AddToFFT(Add add_dr, Add add_ps, int count, QString loca);
    Ui::AdgustMag *ui;
    QButtonGroup *m_BtnGroup;
    SPACE m_space = SPACE::FRONT;
    LOCATION m_location = LOCATION::DRIVER;
    SMOOTH smooth = SMOOTH::noSmooth;
    QString m_copyId;
    QAction *m_action;
    QMenu *m_menu;
    CURVEMODE m_curvetype = CURVEMODE::dbFs;
};

#endif // ADGUSTMAG_H
