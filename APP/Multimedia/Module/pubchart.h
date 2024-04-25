#ifndef PUBCHART_H
#define PUBCHART_H

#include <QWidget>
#include "Module/algorithmDesign.h"

namespace Ui {
class PubChart;
}

class PubChart : public QWidget
{
    Q_OBJECT

public:
    explicit PubChart(QWidget *parent = nullptr);
    ~PubChart();
    void setChartType(QString x = "--", QString y = "--");
    void clearGraphs();
private:
    Ui::PubChart *ui;
    void init();
    void rangeSelfAdaption();
};

#endif // PUBCHART_H
