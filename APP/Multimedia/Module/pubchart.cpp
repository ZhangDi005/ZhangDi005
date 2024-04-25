#include "pubchart.h"
#include "ui_pubchart.h"

PubChart::PubChart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PubChart)
{
    ui->setupUi(this);
    init();
}

PubChart::~PubChart()
{
    delete ui;
}
void PubChart::init()
{
    QLinearGradient plotGradient;
    plotGradient.setColorAt(0,QColor(255,255,255,0));
    ui->chart->setBackground(plotGradient);
    // 右上角坐标轴
    ui->chart->xAxis2->setVisible(false);
    ui->chart->yAxis2->setVisible(false);
    // 默认范围
    ui->chart->xAxis->setRange(-1,5);
    ui->chart->yAxis->setRange(-1,5);
    // 背景色设置
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    ui->chart->axisRect()->setBackground(axisRectGradient);   // 设置QCPAxisRect背景颜色
    //
    setChartType();
    ui->chart->xAxis->setBasePen(QPen(QColor(255,255,255,128), 1));  // 轴线的画笔
    ui->chart->xAxis->setTickPen(QPen(QColor(255,255,255,128), 1));  // 轴刻度线的画笔
    ui->chart->xAxis->setSubTickPen(QPen(QColor(255,255,255,128), 1)); // 轴子刻度线的画笔
    ui->chart->xAxis->setTickLabelColor(QColor(255,255,255,178));  // 轴刻度文字颜色
    ui->chart->xAxis->setLabelColor(QColor(255,255,255,178));   // 轴标签颜色
    ui->chart->yAxis->setBasePen(QPen(QColor(255,255,255,128), 1));  // 轴线的画笔
    ui->chart->yAxis->setTickPen(QPen(QColor(255,255,255,128), 1));  // 轴刻度线的画笔
    ui->chart->yAxis->setSubTickPen(QPen(QColor(255,255,255,128), 1)); // 轴子刻度线的画笔
    ui->chart->yAxis->setTickLabelColor(QColor(255,255,255,178));  // 轴刻度文字颜色
    ui->chart->yAxis->setLabelColor(QColor(255,255,255,178));   // 轴标签颜色
    // 每条网格对应一个刻度
    ui->chart->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));     // 网格线(对应刻度)画笔
    ui->chart->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->chart->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine)); // 子网格线(对应子刻度)画笔
    ui->chart->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->chart->xAxis->grid()->setSubGridVisible(true);     // 显示子网格线
    ui->chart->yAxis->grid()->setSubGridVisible(true);
    ui->chart->xAxis->grid()->setZeroLinePen(QPen(QColor(255,0,0,200)));   // 设置刻度为0时的网格线的画笔
    ui->chart->yAxis->grid()->setZeroLinePen(QPen(QColor(255,0,0,200)));

//    ui->chart->xAxis->setScaleType(QCPAxis::stLogarithmic); // x轴对数显示
//    QSharedPointer<QCPAxisTickerLog> logTicker(new QCPAxisTickerLog);
//    ui->chart->xAxis->setTicker(logTicker);

    ui->chart->xAxis->setLabelFont(QFont("微软雅黑"));
    ui->chart->yAxis->setLabelFont(QFont("微软雅黑"));
    ui->chart->xAxis->setTickLabelFont(QFont("方正兰亭细黑_GBK"));
    ui->chart->yAxis->setTickLabelFont(QFont("方正兰亭细黑_GBK"));
    ui->chart->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);// 设置轴线结束时的风格为 实角三角形但内部有凹陷的形状
    ui->chart->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->chart->legend->setTextColor(QColor(255,255,255));
    ui->chart->legend->setVisible(true);                  //设置图例可见
    ui->chart->legend->setBrush(QColor(0,0,0,0));   //设置背景透明
    ui->chart->axisRect()->insetLayout()->setInsetAlignment(0,Qt::AlignTop|Qt::AlignRight); // 右上

    ui->chart->setMultiSelectModifier(Qt::KeyboardModifier::NoModifier);//曲线单选
    ui->chart->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->chart->setSelectionRectMode(QCP::SelectionRectMode::srmZoom);//模式：框选放大

    //lambda表达式 mouseMoveEvent
    connect(ui->chart,&QCustomPlot::mouseMove,[=](QMouseEvent* event){

    });
    QAction * autoRange = new QAction("自动范围", this);
    QMenu * freq_menu = new QMenu(this);
    freq_menu->addAction(autoRange);
    connect(autoRange, &QAction::triggered, [=]() {
        rangeSelfAdaption();
    });
    ui->chart->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
    connect(ui->chart, &QCustomPlot::customContextMenuRequested, [=](const QPoint &pos)
    {
        freq_menu->exec(QCursor::pos());
    });
}

void PubChart::rangeSelfAdaption()
{
    // auto range
    try
    {
        int count = ui->chart->graphCount();
        QCPRange xRange(0, 5);
        QCPRange yRange(-1, 1);
        bool frist = true;
        for (int i = 0; i < count; i++)
        {
            QCPGraph* plot = ui->chart->graph(i);
            if (!plot->visible())continue;
            bool found = false;
            QCPRange x = plot->getKeyRange(found);
            QCPRange y = plot->getValueRange(found);
            if (found)
            {
                if (frist)
                {
                    xRange.upper = x.upper;
                    xRange.lower = x.lower;
                    yRange.upper = y.upper;
                    yRange.lower = y.lower;
                    frist = false;
                }
                else
                {
                    xRange.upper = std::max(xRange.upper, x.upper);
                    xRange.lower = std::min(xRange.lower, x.lower);
                    yRange.upper = std::max(yRange.upper, y.upper);
                    yRange.lower = std::min(yRange.lower, y.lower);
                }
            }

        }
        double xOffset = xRange.size() == 0 ? xRange.lower*0.1 : xRange.size()*0.1;
        xRange.lower -= xOffset - 2000;
        xRange.upper += xOffset;
        double yOffset = yRange.size() == 0 ? yRange.lower*0.1 : yRange.size()*0.1;
        yRange.lower -= yOffset;
        yRange.upper += yOffset;
        ui->chart->xAxis->setRange(xRange);
        ui->chart->yAxis->setRange(yRange);
        ui->chart->replot(QCustomPlot::rpQueuedReplot);
    }
    catch (const std::exception& e)
    {
        throw e;
    }
}

void PubChart::setChartType(QString x, QString y)
{
    ui->chart->xAxis->setLabel(x);
    ui->chart->yAxis->setLabel(y);
}

void PubChart::clearGraphs()
{
    ui->chart->clearGraphs();
    ui->chart->replot(QCustomPlot::rpQueuedReplot);
}
