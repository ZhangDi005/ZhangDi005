#include "voicechart.h"
#include "ui_voicechart.h"

VoiceChart::VoiceChart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VoiceChart)
{
    ui->setupUi(this);
    init();
}

VoiceChart::~VoiceChart()
{
    delete ui;
}

void VoiceChart::addGraph(F_M_P fmp)
{
    QCPGraph * graph = ui->chart->addGraph();
    int count = ui->chart->graphCount() + 1;
    graph->setName(fmp.name);
    graph->setAntialiasedFill(true);
    graph->setPen(QPen(QBrush(QColor(qSin(count*1+1.2)*80+80, qSin(count*0.6+0)*80+80, qSin(count*0.6+1.5)*80+80, 220)), 1));
    QCPSelectionDecorator * selection = graph->selectionDecorator();
    selection->setPen(QPen(QBrush(QColor(qSin(count*1+1.2)*80+80, qSin(count*0.3+0)*80+80, qSin(count*0.3+1.5)*80+80)), 2));
    graph->addData(fmp.freq, fmp.magnitude);
    ui->chart->replot(QCustomPlot::rpQueuedReplot);
}

void VoiceChart::removeGraph(QString name)
{
    for (size_t i = 0; i < ui->chart->graphCount(); i++)
    {
        if (ui->chart->graph(i)->name() == name)
        {
            ui->chart->removeGraph(i);
        }
    }
    ui->chart->replot(QCustomPlot::rpQueuedReplot);
}

void VoiceChart::setData(AudioDataManage audioDatas)
{
    ui->chart->clearGraphs();
    for (int i = 0; i < NUM_MIC; i++) {
        AudioData audio = audioDatas.audioData[i];
        QCPGraph* line = ui->chart->addGraph();
        line->setName(audio.getFileName());
        ui->chart->graph(i)->setAntialiasedFill(true);
        line->setPen(QPen(QBrush(QColor(qSin(i*1+1.2)*80+80, qSin(i*0.6+0)*80+80, qSin(i*0.6+1.5)*80+80, 220)), 1));
        QCPSelectionDecorator * selection = line->selectionDecorator();
        selection->setPen(QPen(QBrush(QColor(qSin(i*1+1.2)*80+80, qSin(i*0.3+0)*80+80, qSin(i*0.3+1.5)*80+80)), 2));
        if (m_type == CHART_TYPE::MAGNITUDE_CHART)
            line->addData(audio.getFreq(), audio.getMagnitude());
        else if (m_type == CHART_TYPE::PHASE_CHART)
            line->addData(audio.getFreq(), audio.getPhase());
        else
            ;
    }
    ui->chart->replot(QCustomPlot::rpQueuedReplot);
}

void VoiceChart::setData(QVector<F_M_P> fmps)
{
    ui->chart->clearGraphs();
    int count = fmps.size();
    for (int i = 0; i < count; i++) {
        F_M_P fmp = fmps.at(i);
        QCPGraph* line = ui->chart->addGraph();
        line->setName(fmp.name);
        ui->chart->graph(i)->setAntialiasedFill(true);
        Qt::PenStyle style = fmp.isTargetCurve ? Qt::PenStyle::DashLine : Qt::PenStyle::SolidLine;
        QPen pen(QBrush(QColor(qSin(i*1+1.2)*80+80, qSin(i*0.6+0)*80+80, qSin(i*0.6+1.5)*80+80, 220)), 1, style);
        line->setPen(pen);
//        QCPSelectionDecorator * selection = line->selectionDecorator();
//        QPen pen_(QBrush(QColor(qSin(i*1+1.2)*80+80, qSin(i*0.6+0)*80+80, qSin(i*0.6+1.5)*80+80, 220)), 2, style);
//        selection->setPen(pen_);
        if (m_type == CHART_TYPE::MAGNITUDE_CHART)
            line->addData(fmp.freq, fmp.magnitude);
        else if (m_type == CHART_TYPE::PHASE_CHART)
            line->addData(fmp.freq, fmp.phase);
        else
            ;
    }
    ui->chart->replot(QCustomPlot::rpQueuedReplot);
}

void VoiceChart::setChartType(CHART_TYPE type)
{
    m_type = type;
    if (m_type == CHART_TYPE::MAGNITUDE_CHART) {
        ui->chart->xAxis->setLabel("(Hz)");
        ui->chart->yAxis->setLabel("(db)");
        ui->chart->yAxis->setRange(-10,-120);
    } else if (m_type == CHART_TYPE::PHASE_CHART) {
        ui->chart->xAxis->setLabel("(Hz)");
        ui->chart->yAxis->setLabel("phase(°)");
        ui->chart->yAxis->setRange(180,-180);
    } else {

    }
}

void VoiceChart::setSelectPlot(int index)
{
    if (ui->chart->graphCount() != 0) {
        for (int i = 0; i < ui->chart->graphCount(); i++) {
            if (index == 6)
                ui->chart->graph(i)->setVisible(true);
            else {
                if (i == index)
                    ui->chart->graph(i)->setVisible(true);
                else
                    ui->chart->graph(i)->setVisible(false);
            }
        }
    }
    ui->chart->replot(QCustomPlot::rpQueuedReplot);
}

void VoiceChart::tracerClear()
{
    tracerGraph = nullptr;
    tracer->setGraph(nullptr);
    tracer->setVisible(false);
    tracerLabel->setVisible(false);
}

void VoiceChart::setYaxisRange(QPair<int, int> pair)
{
    ui->chart->yAxis->setRange(pair.first, pair.second);
    QSharedPointer<QCPAxisTickerFixed>MyTicker(new QCPAxisTickerFixed);
    MyTicker->setTickStep(90);
    MyTicker->setTickCount(2);
    ui->chart->yAxis->setTicker(MyTicker);

//    ui->chart->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));     // SolidLine 网格线(对应刻度)画笔
//    ui->chart->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
//    ui->chart->xAxis->grid()->setSubGridVisible(0);     // 显示子网格线
//    ui->chart->yAxis->grid()->setSubGridVisible(0);
}

QCPGraph * VoiceChart::find_plot(const QString & name)
{
    for (size_t i = 0; i < ui->chart->graphCount(); i++)
    {
        if (ui->chart->graph(i)->name() == name)
        {
            return ui->chart->graph(i);
        }
    }
    return NULL;
}

void VoiceChart::upDataAlonePlot(QString name, const QVector<double> &key, const QVector<double> &value)
{
    QCPGraph *graph = find_plot(name);
    if (graph == nullptr)
        return;
    graph->data().clear();
    graph->addData(key, value);
}

void VoiceChart::setChartRange()
{
    QCPRange x = ui->chart->xAxis->range();
    QCPRange y = ui->chart->yAxis->range();
    Range range;
    range.init(QPair<int, int>(x.lower, x.upper), QPair<int, int>(y.lower, y.upper));
    if (range.exec() == QDialog::Accepted) {
        ui->chart->xAxis->setRange(range.get_X().first, range.get_X().second);
        ui->chart->yAxis->setRange(range.get_Y().first, range.get_Y().second);
        ui->chart->replot(QCustomPlot::rpQueuedReplot);
    }
}

void VoiceChart::init()
{
//    QLinearGradient plotGradient;
//    plotGradient.setColorAt(0,QColor(255,255,255,0));
//    ui->chart->setBackground(plotGradient); // 背景透明
    // 右上角坐标轴
    ui->chart->xAxis2->setVisible(false);
    ui->chart->yAxis2->setVisible(false);
    // 默认范围
    ui->chart->xAxis->setRange(10,20000);
    // 背景色设置
/*    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    ui->chart->axisRect()->setBackground(axisRectGradient); */  // 设置QCPAxisRect背景颜色
    //
//    ui->chart->xAxis->setBasePen(QPen(QColor(0,0,0,128), 1));  // 轴线的画笔
//    ui->chart->xAxis->setTickPen(QPen(QColor(0,0,0,0), 1));  // 轴刻度线的画笔
//    ui->chart->xAxis->setSubTickPen(QPen(QColor(0,0,0,0), 0.5)); // 轴子刻度线的画笔
//    ui->chart->xAxis->setTickLabelColor(QColor(0,0,0,178));  // 轴刻度文字颜色
//    ui->chart->xAxis->setLabelColor(QColor(0,0,0,178));   // 轴标签颜色
//    ui->chart->yAxis->setBasePen(QPen(QColor(0,0,0,128), 1));  // 轴线的画笔
//    ui->chart->yAxis->setTickPen(QPen(QColor(0,0,0,0), 1));  // 轴刻度线的画笔
//    ui->chart->yAxis->setSubTickPen(QPen(QColor(0,0,0,0), 0.5)); // 轴子刻度线的画笔
//    ui->chart->yAxis->setTickLabelColor(QColor(0,0,0,178));  // 轴刻度文字颜色
//    ui->chart->yAxis->setLabelColor(QColor(0,0,0,178));   // 轴标签颜色

//    ui->chart->xAxis->setLabelPadding(-5);
//    ui->chart->xAxis->setTickLabelPadding(3);
//    ui->chart->yAxis->setLabelPadding(-5);
//    ui->chart->yAxis->setTickLabelPadding(3);
//    // 每条网格对应一个刻度
//    ui->chart->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::SolidLine));     // SolidLine 网格线(对应刻度)画笔
//    ui->chart->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::SolidLine));
//    ui->chart->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine)); // 子网格线(对应子刻度)画笔
//    ui->chart->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
//    ui->chart->xAxis->grid()->setSubGridVisible(true);     // 显示子网格线
//    ui->chart->yAxis->grid()->setSubGridVisible(true);
    ui->chart->xAxis->grid()->setZeroLinePen(QPen(QColor(255,0,0,200)));   // 设置刻度为0时的网格线的画笔
    ui->chart->yAxis->grid()->setZeroLinePen(QPen(QColor(255,0,0,200)));

    ui->chart->xAxis->setScaleType(QCPAxis::stLogarithmic); // x轴对数显示
    QSharedPointer<QCPAxisTickerLog> logTicker(new QCPAxisTickerLog);
    ui->chart->xAxis->setTicker(logTicker);

    ui->chart->xAxis->setLabelFont(QFont("微软雅黑"));
    ui->chart->yAxis->setLabelFont(QFont("微软雅黑"));
    ui->chart->xAxis->setTickLabelFont(QFont("方正兰亭细黑_GBK"));
    ui->chart->yAxis->setTickLabelFont(QFont("方正兰亭细黑_GBK"));
    ui->chart->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);// 设置轴线结束时的风格为 实角三角形但内部有凹陷的形状
    ui->chart->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->chart->legend->setTextColor(QColor(0,0,0));
    ui->chart->legend->setVisible(true);                  //设置图例可见
    ui->chart->legend->setBrush(QColor(255,255,255,150));   //设置背景透明
    ui->chart->legend->setBorderPen(Qt::NoPen);

    ui->chart->axisRect()->insetLayout()->setInsetAlignment(0,Qt::AlignTop|Qt::AlignRight); // 右上

    ui->chart->setMultiSelectModifier(Qt::KeyboardModifier::NoModifier);//曲线单选
    ui->chart->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables| QCP::iSelectLegend);
//    ui->chart->setSelectionRectMode(QCP::SelectionRectMode::srmZoom);//模式：框选放大
    ui->chart->setInteraction(QCP::iRangeDrag, true); //鼠标单击拖动
    ui->chart->setInteraction(QCP::iRangeZoom, true); //滚轮滑动缩放
    //游标
    tracer = new QCPItemTracer(ui->chart);       //生成游标
    ui->chart->setMouseTracking(true);           //让游标自动随鼠标移动，若不想游标随鼠标动，则禁止
    //tracer->setPen(QPen(QBrush(QColor(Qt::red)),Qt::DashLine));   //虚线游标
    tracer->setPen(QPen(Qt::red));                    //圆圈轮廓颜色
    tracer->setBrush(QBrush(Qt::red));                //圆圈圈内颜色
    tracer->setStyle(QCPItemTracer::tsCircle);        //圆圈
    tracer->setSize(5);
    //tracer->setVisible(false);                      //设置可见性
    //游标说明
    tracerLabel = new QCPItemText(ui->chart);                     //生成游标说明
    //tracerLabel->setVisible(false);                                  //设置可见性
    tracerLabel->setLayer("overlay");
    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::black);
    tracerLabel->setPen(pen);                              //设置游标说明颜色
    tracerLabel->setPositionAlignment(Qt::AlignLeft | Qt::AlignTop);   //左上
    tracerLabel->setFont(QFont(font().family(),10));                   //字体大小
    tracerLabel->setPadding(QMargins(4,4,4,4));                        //文字距离边框几个像素
    tracerLabel->position->setParentAnchor(tracer->position);          //设置标签自动随着游标移动

    //选择不同的曲线
    connect(ui->chart,SIGNAL(selectionChangedByUser()),this,SLOT(slot_SelectionChanged()));

    //连接鼠标事件发出的信号，实现绑定
    connect(ui->chart,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(mousePress(QMouseEvent*)));
    connect(ui->chart,SIGNAL(mouseMove(QMouseEvent*)),this,SLOT(mouseMove(QMouseEvent*)));
    connect(ui->chart,SIGNAL(mouseRelease(QMouseEvent*)),this,SLOT(mouseRelease(QMouseEvent*)));

    //lambda表达式 mouseMoveEvent
    connect(ui->chart,&QCustomPlot::mouseMove,[=](QMouseEvent* event) {
        if(tracer->graph() == nullptr)
        {
            return;
        }
        if(tracer->graph()->data()->isEmpty())
        {
            return;
        }
        if(tracer->visible())
        {
            if(tracerGraph)
            {
                double x = ui->chart->xAxis->pixelToCoord(event->pos().x());
                tracer->setGraphKey(x);             //将游标横坐标设置成刚获得的横坐标数据x
                //tracer->setInterpolating(true);   //自动计算y值,若只想看已有点,不需要这个
                tracer->updatePosition();           //使得刚设置游标的横纵坐标位置生效
                tracerLabel->setText(QString("x:%1\ny:%2").arg(tracer->position->key()).arg(tracer->position->value()));
                ui->chart->replot(QCustomPlot::rpQueuedReplot);
            }
        }
    });

    //lambda表达式 mouseMoveEvent
    connect(ui->chart,&QCustomPlot::mouseMove,[=](QMouseEvent* event){

    });
    QAction * autoRange = new QAction("自动范围", this);
    QAction * setRange = new QAction("设置范围", this);
    QMenu * freq_menu = new QMenu(this);
    freq_menu->addAction(autoRange);
    freq_menu->addAction(setRange);
    connect(autoRange, &QAction::triggered, [=]() {
        rangeSelfAdaption();
    });
    connect(setRange, &QAction::triggered, [=]() {
        setChartRange();
    });
    ui->chart->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
    connect(ui->chart, &QCustomPlot::customContextMenuRequested, [=](const QPoint &pos)
    {
        freq_menu->exec(QCursor::pos());
    });
}

//鼠标按下槽函数
void VoiceChart::mousePress(QMouseEvent* mevent)
{

}

//鼠标移动槽函数
void VoiceChart::mouseMove(QMouseEvent *mevent)
{

}

//鼠标释放槽函数
void VoiceChart::mouseRelease(QMouseEvent *mevent)
{

}

void VoiceChart::slot_SelectionChanged()
{
    tracerGraph = nullptr;
    tracer->setGraph(nullptr);
    int num = ui->chart->graphCount();
    for(int i=0;i<num;i++)
    {
        QCPGraph *graph = ui->chart->graph(i);
        if(graph == nullptr)
        {
            return;
        }
        QCPPlottableLegendItem *item = ui->chart->legend->itemWithPlottable(graph);
        if(item->selected() || graph->selected())   //选中了哪条曲线或者曲线的图例
        {
            tracerGraph = graph;
            if(tracer != nullptr)
            {
                tracer->setGraph(tracerGraph);
            }
            item->setSelected(true);
            QPen pen(graph->pen().color(), 2, graph->pen().style());
            graph->selectionDecorator()->setPen(pen);
            graph->setSelection(QCPDataSelection(graph->data()->dataRange()));
        }
    }
    tracer->setVisible(tracerGraph);
    tracerLabel->setVisible(tracerGraph);
}


void VoiceChart::rangeSelfAdaption()
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
        xRange.lower = 10;
        xRange.upper = 20000;
//        double xOffset = xRange.size() == 0 ? xRange.lower*0.1 : xRange.size()*0.1;
//        xRange.lower -= xOffset - 2000;
//        xRange.upper += xOffset;
        double yOffset = yRange.size() == 0 ? yRange.lower*0.1 : yRange.size()*0.1;
        yRange.lower -= m_type == CHART_TYPE::PHASE_CHART ? yOffset : yOffset*3;
        yRange.upper += m_type == CHART_TYPE::PHASE_CHART ? yOffset : yOffset*3;
        ui->chart->xAxis->setRange(xRange);
        ui->chart->yAxis->setRange(yRange);
        ui->chart->replot(QCustomPlot::rpQueuedReplot);
    }
    catch (const std::exception& e)
    {
        throw e;
    }
}

void VoiceChart::clearGraphs()
{
    ui->chart->clearGraphs();
    ui->chart->replot(QCustomPlot::rpQueuedReplot);
}

