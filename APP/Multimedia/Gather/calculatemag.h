#ifndef CALCULATEMAG_H
#define CALCULATEMAG_H

#include <QWidget>
#include <QFileDialog>
#include "Module/qcustomplot.h"
#include "Module/app.h"

namespace Ui {
class CalculateMag;
}

class CalculateMag : public QWidget
{
    Q_OBJECT

public:
    explicit CalculateMag(QWidget *parent = nullptr);
    ~CalculateMag();
    void setPhaseChartIsVis(bool selected);
signals:
    void setData(int flag, SeatManage m_project);

private slots:
    void on_importBtn_clicked();

    void on_selectBox_currentIndexChanged(int index);

private:
    Ui::CalculateMag *ui;
    int speakerId = 0;
    int seatId = 0;
    QButtonGroup *speaker;
    QButtonGroup *location;
private:
    void init();
    void loadAudio(const QStringList);
    void show_freqPlot();
};

#endif // CALCULATEMAG_H
