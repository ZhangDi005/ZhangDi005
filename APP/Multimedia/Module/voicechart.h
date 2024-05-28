#ifndef VOICECHART_H
#include <QWidget>
#include "Module/range.h"
#include "Module/qcustomplot.h"
#include "Module/algorithmDesign.h"
#define VOICECHART_H

const QColor colors[7] = {
            QColor(Qt::blue),QColor(Qt::red),QColor(Qt::yellow), QColor(Qt::cyan),
            QColor(Qt::green),QColor(Qt::black),QColor(Qt::magenta)};

namespace Ui {
class VoiceChart;
}

class VoiceChart : public QWidget
{
    Q_OBJECT

public:
    explicit VoiceChart(QWidget *parent = nullptr);
    ~VoiceChart();
    void rangeSelfAdaption(); // menu自适应范围
    void clearGraphs();
    void addGraph(F_M_P fmp);
    void removeGraph(QString name);
    void setData(AudioDataManage audioDatas);
    void setData(QVector<F_M_P> fmps);
    void setChartType(CHART_TYPE);
    void setSelectPlot(int index);
    void tracerClear();
    void setYaxisRange(QPair<int, int> pair);
    void upDataAlonePlot(QString name, const QVector<double> &key, const QVector<double> &value);
    void setChartRange();
    void updata();
private slots:
    void mousePress(QMouseEvent* mevent);
    void mouseMove(QMouseEvent *mevent);
    void mouseRelease(QMouseEvent *mevent);
    void slot_SelectionChanged();

private:
    void init();

private:
    QCPGraph *find_plot(const QString & name);
    Ui::VoiceChart *ui;
    QCPItemTracer *tracer;
    QCPItemText *tracerLabel;
    QRubberBand *rubberBand;
    QCPGraph *tracerGraph;
    QPoint rubberOrigin;
    CHART_TYPE m_type = CHART_TYPE::NONE;
};

#endif // VOICECHART_H
