#include "adgustmag.h"
#include "ui_adgustmag.h"

AdgustMag::AdgustMag(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdgustMag)
{
    ui->setupUi(this);
    ui->specificChart->setChartType(CHART_TYPE::MAGNITUDE_CHART);
    ui->overallChart->setChartType(CHART_TYPE::MAGNITUDE_CHART);
    ui->phaseChart->setChartType(CHART_TYPE::PHASE_CHART);
    ui->phaseChart->setYaxisRange(QPair<int, int>(-200, 200));
    ui->listWidget->setGridSize(QSize(292, 35));  // 设置item的宽高
    ui->listWidget_EQ->setGridSize(QSize(485, 35));
    ui->splitter_3->setStretchFactor(0, 85);
    ui->splitter_3->setStretchFactor(1, 15);
    ui->splitter->setStretchFactor(0, 40);
    ui->splitter->setStretchFactor(1, 60);
    m_BtnGroup = new QButtonGroup(this);
    m_BtnGroup->setExclusive(true);
    for (int i = 1; i < 9; i++) {
        DraftBtn *btn = new DraftBtn(i);
        m_BtnGroup->addButton(btn, i);
        connect(btn, &DraftBtn::upData, [=](QString remark){
            ui->lineEdit->setText(remark);
            on_speakerBox_currentIndexChanged(ui->speakerBox->currentText());
            showPlot();
        });
        connect(btn, &DraftBtn::backupData, [=](int id){
            App::instance().syncSave(id, ui->lineEdit->text());
        });
        ui->horizontalLayout_D->addWidget(btn);
    }
    this->setMouseTracking(true);
    ui->listWidget->viewport()->installEventFilter(this);
    m_action = new QAction("Add", this);
    connect(m_action, &QAction::triggered, [=](){
        AddChannel addchannel;
        if (addchannel.exec() == QDialog::Accepted) {
            upData();
            showPlot();
        }
    });
    m_menu = new QMenu(this);
    m_menu->addAction(m_action);
    connect(ui->listWidget->model(), &QAbstractItemModel::rowsMoved, this, [=](const QModelIndex &parent, int start, int end, const QModelIndex &destination, int row) {
        QList<Channel> &project = App::instance().getProject();
        project.move(start, row-1);
        QSignalBlocker blocker(ui->speakerBox);
        QString currentText = ui->speakerBox->currentText();
        ui->speakerBox->clear();
        for (auto channel : project) {
            if (channel.isTargetCurve || channel.seatMag_mIsEmpty()) {
                ui->speakerBox->addItem(channel.channelName);
            }
        }
        ui->speakerBox->setCurrentText(currentText);
    });
    connect(ui->listWidget_EQ->model(), &QAbstractItemModel::rowsMoved, this, [=](const QModelIndex &parent, int start, int end, const QModelIndex &destination, int row) {
        QList<Channel> &project = App::instance().getProject();
        for (auto &channel : project) {
            if (channel.channelName == ui->speakerBox->currentText()) {
                channel.m_eq.move(start, row-1);
                break;
            }
        }
    });
}

AdgustMag::~AdgustMag()
{
    delete ui;
}

void AdgustMag::upData()
{
    ui->listWidget->clear();
    ui->speakerBox->clear();
    QList<Channel> &project = App::instance().getProject();
    for (auto channel : project) {
        if (channel.isTargetCurve || channel.seatMag_mIsEmpty()) {
            ui->speakerBox->addItem(channel.channelName);
            ChannelItem * item = new ChannelItem(ui->listWidget);
            item->init(channel);
            connect(item, &ChannelItem::dataChanged, this, &AdgustMag::showPlot);
            connect(item, &ChannelItem::channelChanged, this, &AdgustMag::upData);
            QListWidgetItem * listItem = new QListWidgetItem(ui->listWidget);
            ui->listWidget->setItemWidget(listItem, item);
            continue;
        }
    }
    showPlot();
}

void AdgustMag::upDataRemark()
{
    QList<BackupData> backup = App::instance().getBackupData();
    for (auto data : backup) {
        static_cast<DraftBtn*>(m_BtnGroup->button(data.m_flag))->valid();
    }
}

void AdgustMag::showPlot()
{
    aloneShowPort();// 左
    on_spaceAllBox_currentIndexChanged(ui->spaceAllBox->currentIndex());//右
    phaseShowPort(); // 下
}

F_M_P AdgustMag::channelToFmp(Channel channel)
{
    F_M_P fmp;
    EQ eq;
    EQ::Eq_rsp *rsp;
    if (channel.isTargetCurve) {
        Add add;
        for (auto item : channel.m_eq) {
            if ((item.m_selected == true) && (item.m_fc > 0)) {
                EQ::Eq_ata *ata = getEqata(item);
                if (ata != nullptr) {
                    if (item.m_order == 2) {
                        EQ::coefft coe;
                        coe.init(ata);
                        rsp = eq.EQ_resp_2_order(coe, SAMPLERATE);
                    } else if(item.m_order == 4) {
                        EQ::coeff coe;
                        coe.init(ata);
                        rsp = eq.EQ_resp(coe, SAMPLERATE);
                    }
                    add += rsp->response;
                }
            }
        }
        QVector<float> curve_y(20000, channel.m_channelData.m_gain);
        add += curve_y;
        fmp.name = channel.channelName;
        fmp.isTargetCurve = true;
        fmp.initTargetCurve();
        fmp.magnitude = add.getData();
        return fmp;
    }

    if (m_space == SPACE::FRONT) {
        switch (m_location) {
        case (LOCATION::DRIVER) : {
            // 延迟 delay
            QVector<float> data = channel.seatMag_m.value(0);
            if (channel.m_channelData.m_invert)
                invert(data);
            dataDelayProces(channel.m_channelData.m_delay, data);
            // gain
            dataGainProces(channel.m_channelData.m_gain, data);
            // eq
            for (auto item : channel.m_eq) {
                if ((item.m_selected == true) && (item.m_fc > 0)) {
                    EQ::Eq_ata *ata = getEqata(item);
                    if (ata != nullptr)
                        data = eq.filter(data, ata, item.m_order + 1);
                }
            }
            fmp = fft(data, m_curvetype);
            fmp.name = channel.channelName;
            break;
        }
        case (LOCATION::PASS) : {
            // 延迟 delay
            QVector<float> data = channel.seatMag_m.value(1);
            if (channel.m_channelData.m_invert)
                invert(data);
            dataDelayProces(channel.m_channelData.m_delay, data);
            // gain
            dataGainProces(channel.m_channelData.m_gain, data);
            // eq
            for (auto item : channel.m_eq) {
                if ((item.m_selected == true) && (item.m_fc > 0)) {
                    EQ::Eq_ata *ata = getEqata(item);
                    if (ata != nullptr)
                        data = eq.filter(data, ata, item.m_order + 1);
                }
            }
            fmp = fft(data, m_curvetype);
            fmp.name = channel.channelName;
            break;
        }
        case (LOCATION::ROW) :
        {
            Add add;
            add += channel.seatMag_m.value(0);
            add += channel.seatMag_m.value(1);
            // 延迟 delay
            QVector<float> data = avg(add, 2);
            if (channel.m_channelData.m_invert)
                invert(data);
            dataDelayProces(channel.m_channelData.m_delay, data);
            // gain
            dataGainProces(channel.m_channelData.m_gain, data);
            // eq
            for (auto item : channel.m_eq) {
                if ((item.m_selected == true) && (item.m_fc > 0)) {
                    EQ::Eq_ata *ata = getEqata(item);
                    if (ata != nullptr)
                        data = eq.filter(data, ata, item.m_order + 1);
                }
            }
            fmp = fft(data, m_curvetype);
            fmp.name = channel.channelName + "ROW";
            break;
        }
        }
    } else if (m_space == SPACE::REAR) {
        switch (m_location) {
        case (LOCATION::DRIVER) : {
            // 延迟 delay
            QVector<float> data = channel.seatMag_m.value(2);
            if (channel.m_channelData.m_invert)
                invert(data);
            dataDelayProces(channel.m_channelData.m_delay, data);
            // gain
            dataGainProces(channel.m_channelData.m_gain, data);
            // eq
            for (auto item : channel.m_eq) {
                if ((item.m_selected == true) && (item.m_fc > 0)) {
                    EQ::Eq_ata *ata = getEqata(item);
                    if (ata != nullptr)
                        data = eq.filter(data, ata, item.m_order + 1);
                }
            }
            fmp = fft(data, m_curvetype);
            fmp.name = channel.channelName;
            break;
        }
        case (LOCATION::PASS) : {
            // 延迟 delay
            QVector<float> data = channel.seatMag_m.value(3);
            if (channel.m_channelData.m_invert)
                invert(data);
            dataDelayProces(channel.m_channelData.m_delay, data);
            // gain
            dataGainProces(channel.m_channelData.m_gain, data);
            // eq
            for (auto item : channel.m_eq) {
                if ((item.m_selected == true) && (item.m_fc > 0)) {
                    EQ::Eq_ata *ata = getEqata(item);
                    if (ata != nullptr)
                        data = eq.filter(data, ata, item.m_order + 1);
                }
            }
            fmp = fft(data, m_curvetype);
            fmp.name = channel.channelName;
            break;
        }
        case (LOCATION::ROW) :
        {
            Add add;
            add += channel.seatMag_m.value(2);
            add += channel.seatMag_m.value(3);
            // 延迟 delay
            QVector<float> data = avg(add, 2);
            if (channel.m_channelData.m_invert)
                invert(data);
            dataDelayProces(channel.m_channelData.m_delay, data);
            // gain
            dataGainProces(channel.m_channelData.m_gain, data);
            // eq
            for (auto item : channel.m_eq) {
                if ((item.m_selected == true) && (item.m_fc > 0)) {
                    EQ::Eq_ata *ata = getEqata(item);
                    if (ata != nullptr)
                        data = eq.filter(data, ata, item.m_order + 1);
                }
            }
            fmp = fft(data, m_curvetype);
            fmp.name = channel.channelName + "row";
            break;
        }
        }
    }
    return fmp;
}

void AdgustMag::aloneShowPort()
{
    ui->specificChart->tracerClear();
    QList<Channel> project = App::instance().getProject();
    QVector<F_M_P> fmps_specific;
    for (auto channel : project) {
        if (channel.m_channelData.m_selected) {
            fmps_specific.append(channelToFmp(channel));
        }
    }
    // 平滑算法
    for (auto &fmp : fmps_specific) {
        if (!fmp.isTargetCurve) {
            QVector<float> out_freq,out_magnitude,freq,magnitude;
            narrow_to_octave(out_freq,out_magnitude,fmp.freq,fmp.magnitude,smooth);
            for (size_t i = 0; i < out_freq.size(); i++) {
                if (out_freq.at(i) > 10) {
                    freq.push_back(out_freq.at(i));
                    magnitude.push_back(out_magnitude.at(i));
                }
            }
            fmp.freq = freq;
            fmp.magnitude = magnitude;
        }
    }
    ui->specificChart->setData(fmps_specific);
}

void AdgustMag::phaseShowPort()
{
    EQ eq;
    ui->phaseChart->tracerClear();
    QList<Channel> project = App::instance().getProject();
    F_M_P fmp;
    QVector<F_M_P> fmps_specific;
    for (auto channel : project) {
        if (channel.isTargetCurve)
            continue;
        if (channel.m_channelData.m_selected) {
            fmp.init();
            if (ui->spaceComBox_1->currentIndex() == SPACE::FRONT) {
                switch (ui->locationComBox_1->currentIndex()) {
                case (LOCATION::DRIVER) : {
                    AudioData audiodata = channel.seatMag.value(0).audioData[ui->micLocation->currentText().toInt()-1];
                    QVector<float> data = audiodata.getData();
                    if (channel.m_channelData.m_invert)
                        invert(data);
                    m_mid(data, QPair<float,float>(ui->startBox->value(), ui->stopBox->value()));
                    dataDelayProces(channel.m_channelData.m_delay, data);
                    for (auto item : channel.m_eq) {
                        if ((item.m_selected == true) && (item.m_fc > 0)) {
                            EQ::Eq_ata *ata = getEqata(item);
                            if (ata != nullptr)
                                data = eq.filter(data, ata, item.m_order + 1);
                        }
                    }
                    fmp = fft(data, m_curvetype);
                    fmp.name = channel.channelName;
                    break;
                }
                case (LOCATION::PASS) : {
                    AudioData audiodata = channel.seatMag.value(1).audioData[ui->micLocation->currentText().toInt()-1];
                    QVector<float> data = audiodata.getData();
                    if (channel.m_channelData.m_invert)
                        invert(data);
                    m_mid(data, QPair<float,float>(ui->startBox->value(), ui->stopBox->value()));
                    dataDelayProces(channel.m_channelData.m_delay, data);
                    for (auto item : channel.m_eq) {
                        if ((item.m_selected == true) && (item.m_fc > 0)) {
                            EQ::Eq_ata *ata = getEqata(item);
                            if (ata != nullptr)
                                data = eq.filter(data, ata, item.m_order + 1);
                        }
                    }
                    fmp = fft(data, m_curvetype);
                    fmp.name = channel.channelName;
                }
                case (LOCATION::ROW) :
                {

                    break;
                }
                }
            } else if (ui->spaceComBox_1->currentIndex() == SPACE::REAR) {
                switch (ui->locationComBox_1->currentIndex()) {
                case (LOCATION::DRIVER) : {
                    AudioData audiodata = channel.seatMag.value(2).audioData[ui->micLocation->currentText().toInt()-1];
                    QVector<float> data = audiodata.getData();
                    if (channel.m_channelData.m_invert)
                        invert(data);
                    m_mid(data, QPair<float,float>(ui->startBox->value(), ui->stopBox->value()));
                    dataDelayProces(channel.m_channelData.m_delay, data);
                    for (auto item : channel.m_eq) {
                        if ((item.m_selected == true) && (item.m_fc > 0)) {
                            EQ::Eq_ata *ata = getEqata(item);
                            if (ata != nullptr)
                                data = eq.filter(data, ata, item.m_order + 1);
                        }
                    }
                    fmp = fft(data, m_curvetype);
                    fmp.name = channel.channelName;
                    break;
                }
                case (LOCATION::PASS) : {
                    AudioData audiodata = channel.seatMag.value(3).audioData[ui->micLocation->currentText().toInt()-1];
                    QVector<float> data = audiodata.getData();
                    if (channel.m_channelData.m_invert)
                        invert(data);
                    m_mid(data, QPair<float,float>(ui->startBox->value(), ui->stopBox->value()));
                    dataDelayProces(channel.m_channelData.m_delay, data);
                    for (auto item : channel.m_eq) {
                        if ((item.m_selected == true) && (item.m_fc > 0)) {
                            EQ::Eq_ata *ata = getEqata(item);
                            if (ata != nullptr)
                                data = eq.filter(data, ata, item.m_order + 1);
                        }
                    }
                    fmp = fft(data, m_curvetype);
                    fmp.name = channel.channelName;
                    break;
                }
                case (LOCATION::ROW) :
                {
                    break;
                }
                }
            }
        }
        fmps_specific.append(fmp);
    }
    ui->phaseChart->setData(fmps_specific);
}

void AdgustMag::on_spaceAllBox_currentIndexChanged(int index)
{
    ui->overallChart->tracerClear();
    EQ eq;
    QVector<F_M_P> target;
    QVector<F_M_P> fmps_overall;
    Add add_dr;
    Add add_ps;
    QList<Channel> project = App::instance().getProject();
    int count = 0;
    for (auto channel : project) {
        if(!channel.m_channelData.m_selected)
            continue;
        if(channel.isTargetCurve) {
            target.append(channelToFmp(channel));
            continue;
        }
        count++;
        if (SPACE(index) == SPACE::FRONT) {
            QVector<float> data_lf = channel.seatMag_m.value(0);
            if (channel.m_channelData.m_invert)
                invert(data_lf);
            dataDelayProces(channel.m_channelData.m_delay, data_lf);
            dataGainProces(channel.m_channelData.m_gain, data_lf);
            for (auto item : channel.m_eq) {
                if ((item.m_selected == true) && (item.m_fc > 0)) {
                    EQ::Eq_ata *ata = getEqata(item);
                    if (ata != nullptr)
                        data_lf = eq.filter(data_lf, ata, item.m_order + 1);
                }
            }
            add_dr += data_lf;
            QVector<float> data_rf = channel.seatMag_m.value(1);
            if (channel.m_channelData.m_invert)
                invert(data_rf);
            dataDelayProces(channel.m_channelData.m_delay, data_rf);
            dataGainProces(channel.m_channelData.m_gain, data_rf);
            for (auto item : channel.m_eq) {
                if ((item.m_selected == true) && (item.m_fc > 0)) {
                    EQ::Eq_ata *ata = getEqata(item);
                    if (ata != nullptr)
                        data_rf = eq.filter(data_rf, ata, item.m_order + 1);
                }
            }
            add_ps += data_rf;
        } else if (SPACE(index) == SPACE::REAR) {
            QVector<float> data_ls = channel.seatMag_m.value(2);
            if (channel.m_channelData.m_invert)
                invert(data_ls);
            dataDelayProces(channel.m_channelData.m_delay, data_ls);
            dataGainProces(channel.m_channelData.m_gain, data_ls);
            for (auto item : channel.m_eq) {
                if ((item.m_selected == true) && (item.m_fc > 0)) {
                    EQ::Eq_ata *ata = getEqata(item);
                    if (ata != nullptr)
                        data_ls = eq.filter(data_ls, ata, item.m_order + 1);
                }
            }
            add_dr += data_ls;
            QVector<float> data_rs = channel.seatMag_m.value(3);
            if (channel.m_channelData.m_invert)
                invert(data_rs);
            dataDelayProces(channel.m_channelData.m_delay, data_rs);
            dataGainProces(channel.m_channelData.m_gain, data_rs);
            for (auto item : channel.m_eq) {
                if ((item.m_selected == true) && (item.m_fc > 0)) {
                    EQ::Eq_ata *ata = getEqata(item);
                    if (ata != nullptr)
                        data_rs = eq.filter(data_rs, ata, item.m_order + 1);
                }
            }
            add_ps += data_rs;
        }
    }
    F_M_P fmp;
    if (count > 0) {
        fmp.init();
        fmp = fft(avg(add_dr, count), m_curvetype);
        fmp.name = "driver";
        fmps_overall.append(fmp);
        fmp.init();
        fmp = fft(avg(add_ps, count), m_curvetype);
        fmp.name = "passenger";
        fmps_overall.append(fmp);
        Add add_row;
        add_row += add_dr.getData();
        add_row += add_ps.getData();
        fmp.init();
        fmp = fft(avg(add_row, 2), m_curvetype);
        fmp.name = "driver+pass";
        fmps_overall.append(fmp);
    }
    fmps_overall += target;
    // 平滑算法
    for (auto &fmp : fmps_overall) {
        if (!fmp.isTargetCurve) {
            QVector<float> out_freq,out_magnitude,freq,magnitude;
            narrow_to_octave(out_freq,out_magnitude,fmp.freq,fmp.magnitude,smooth);
            for (size_t i = 0; i < out_freq.size(); i++) {
                if (out_freq.at(i) > 10) {
                    freq.push_back(out_freq.at(i));
                    magnitude.push_back(out_magnitude.at(i));
                }
            }
            fmp.freq = freq;
            fmp.magnitude = magnitude;
        }
    }
    ui->overallChart->setData(fmps_overall);
}

void AdgustMag::setSmooth(SMOOTH smooth)
{
    this->smooth = smooth;
    showPlot();
}

bool AdgustMag::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->listWidget->viewport()) {
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *e = static_cast<QMouseEvent *>(event);
            if(e->button() == Qt::RightButton) {
                m_menu->exec(QCursor::pos());
            }
        }
    }
    return QWidget::eventFilter(watched, event);
}

void AdgustMag::on_spaceComBox_currentIndexChanged(int index)
{
    if (index == SPACE::FRONT)
        m_space = SPACE::FRONT;
    if (index == SPACE::REAR)
        m_space = SPACE::REAR;
    aloneShowPort();
}

void AdgustMag::on_locationComBox_currentIndexChanged(int index)
{
    if (index == LOCATION::DRIVER)
        m_location = LOCATION::DRIVER;
    if (index == LOCATION::PASS)
        m_location = LOCATION::PASS;
    if (index == LOCATION::ROW)
        m_location = LOCATION::ROW;
    aloneShowPort();
}

void AdgustMag::listWidget_EqClear()
{
    int count = ui->listWidget_EQ->count();
    if (count > 0) {
        for (size_t i = 0; i < count; i++)
        {
            QListWidgetItem * item = ui->listWidget->takeItem(0);
            delete item;
        }
    }
}

void AdgustMag::dataDelayProces(double delay, QVector<float> &data)
{
    QVector<float> d(delay * (SAMPLERATE/1000), 0);
    d += data;
    d.resize(data.size());
    data = d;
}

void AdgustMag::dataGainProces(double gain, QVector<float> &data)
{
    float x = pow(10, gain / 20);
    int count = data.size();
    for (size_t i = 0; i < count; i++) {
        data[i] = data.at(i) * x;
    }
}

void AdgustMag::invert(QVector<float> &data)
{
    int count = data.size();
    for (size_t i = 0; i < count; i++) {
        data[i] = data.at(i) *-1;
    }
}

void AdgustMag::on_addBtn_clicked()
{
    if (ui->speakerBox->currentIndex() == -1) return;
    QList<Channel> &project = App::instance().getProject();
    EqItem *item = new EqItem(ui->speakerBox->currentText(), ui->listWidget_EQ);
    connect(item, &EqItem::eqDataChanged, this, &AdgustMag::showPlot);
    item->setRow(ui->listWidget_EQ->count());
    QListWidgetItem *widgetItem = new QListWidgetItem(ui->listWidget_EQ);
    ui->listWidget_EQ->setItemWidget(widgetItem, item);
    QString channelName = ui->speakerBox->currentText();
    for (auto &channel : project) {
        if (channel.channelName == channelName) {
            channel.m_eq.push_back(EqData());
            break;
        }
    }
}

void AdgustMag::on_removeBtn_clicked()
{
    QList<QListWidgetItem*> items = ui->listWidget_EQ->selectedItems();
    if (items.size() == 0)
        return;
    QList<Channel> &project = App::instance().getProject();
    for (auto item : items) {
        int index = ui->listWidget_EQ->row(item);
        QString channelName = ui->speakerBox->currentText();
        for (auto &channel : project) {
            if (channel.channelName == channelName)
                channel.m_eq.remove(index);
        }
        QListWidgetItem * it = ui->listWidget_EQ->takeItem(index);
        delete it;
    }
    //重新排序
    on_speakerBox_currentIndexChanged(ui->speakerBox->currentText());
}

void AdgustMag::on_micLocation_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    phaseShowPort();
}

void AdgustMag::on_startBox_editingFinished()
{
    phaseShowPort();
}

void AdgustMag::on_stopBox_editingFinished()
{
    phaseShowPort();
}

void AdgustMag::on_spaceComBox_1_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    phaseShowPort();
}

void AdgustMag::on_locationComBox_1_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    phaseShowPort();
}

EQ::Eq_ata *AdgustMag::getEqata(EqData eqData)
{
    EQ::Eq_ata *ata = new EQ::Eq_ata();
    EQ eq;
    switch(eqData.m_type) {
    case FilterType::Parametric:
    {
        ata = eq.Parametric(eqData.m_fc, eqData.m_gain, eqData.m_q);
        break;
    }
    case FilterType::Bass_Shelf:
    {
        ata = eq.Base_Shelf(eqData.m_fc, eqData.m_gain, eqData.m_q);
        break;
    }
    case FilterType::Treble_Shelf:
    {
        ata = eq.Treble_Shelf(eqData.m_fc, eqData.m_gain, eqData.m_q);
        break;
    }
    case FilterType::Phase_Changer:
    {
        ata = eq.Phase_Changer(eqData.m_fc, eqData.m_gain, eqData.m_q);
        break;
    }
    case FilterType::Lowpass_LR:
    {
        ata = eq.Lowpass_LR(eqData.m_fc);
        break;
    }
    case FilterType::Highpass_LR:
    {
        ata = eq.Highpass_LR(eqData.m_fc);
        break;
    }
    case FilterType::Lowpass_BW:
    {
        ata = eq.Lowpass_BW(eqData.m_order, eqData.m_fc);
        break;
    }
    case FilterType::Highpass_BW:
    {
        ata = eq.Highpass_BW(eqData.m_order, eqData.m_fc);
        break;
    }
    case FilterType::Bandpass:
    {
        ata = eq.Bandpass(eqData.m_fc, eqData.m_q);
        break;
    }
    case FilterType::Bypass:
    {
        ata = nullptr;
        break;
    }
    }
    return ata;
}

void AdgustMag::on_speakerBox_currentIndexChanged(const QString &arg1)
{
    ui->listWidget_EQ->clear();
    QList<Channel> project = App::instance().getProject();
    QVector<EqData> eqs;
    for (auto channel : project) {
        if (channel.channelName == arg1) {
            eqs = channel.m_eq;
            break;
        }
    }
    for (int i = 0; i < eqs.size(); i++) {
        EqItem *item = new EqItem(arg1, ui->listWidget_EQ);
        connect(item, &EqItem::eqDataChanged, this, &AdgustMag::showPlot);
        item->setEqData(i, eqs.at(i));
        QListWidgetItem *widgetItem = new QListWidgetItem(ui->listWidget_EQ);
        ui->listWidget_EQ->setItemWidget(widgetItem, item);
    }
}

void AdgustMag::on_copyBtn_clicked()
{
    if(ui->speakerBox->currentText() == "") return;
    m_copyId = ui->speakerBox->currentText();
    ui->copyBtn->setToolTip(m_copyId);
    QMessageBox::information(this, "提示", ui->speakerBox->currentText() + "copy成功", QMessageBox::Ok);
}

void AdgustMag::on_pasteBtn_clicked()
{
    if (m_copyId == "")
        QMessageBox::warning(this, "提示", "没选择copy对象", QMessageBox::Ok);
    if (m_copyId == ui->speakerBox->currentText())
        return;

    ui->listWidget_EQ->clear();
    QList<Channel> &project = App::instance().getProject();
    QVector<EqData> eqs;
    for (auto channel : project) {
        if (channel.channelName == m_copyId) {
            eqs = channel.m_eq;
            break;
        }
    }
    for (auto &channel : project) {
        if (channel.channelName == ui->speakerBox->currentText()) {
            channel.m_eq.clear();
            channel.m_eq = eqs;
            break;
        }
    }
    for (int i = 0; i < eqs.size(); i++) {
        EqItem *item = new EqItem(ui->speakerBox->currentText(), ui->listWidget_EQ);
        connect(item, &EqItem::eqDataChanged, this, &AdgustMag::showPlot);
        item->setEqData(i, eqs.at(i));
        QListWidgetItem *widgetItem = new QListWidgetItem(ui->listWidget_EQ);
        ui->listWidget_EQ->setItemWidget(widgetItem, item);
    }
    showPlot();
}

void AdgustMag::on_checkBox_2_clicked(bool checked)
{
    QString id = ui->speakerBox->currentText();
    if (id == "")
        return;
    QList<Channel> &project = App::instance().getProject();
    for (auto &channel : project)
        if (channel.channelName == id) {
            for (auto &eq : channel.m_eq)
                eq.m_selected = checked;
        }
    on_speakerBox_currentIndexChanged(id);
    showPlot();
}

void AdgustMag::on_checkBox_clicked(bool checked)
{
    QList<Channel> &project = App::instance().getProject();
    for (auto &channel : project) {
        if (!channel.isTargetCurve) {
            channel.m_channelData.m_selected = checked;
        }
    }
    upData();
    showPlot();
}

void AdgustMag::on_modeSpeakerBox_currentIndexChanged(int index)
{
    m_curvetype = CURVEMODE(index);
    aloneShowPort();// 左
    on_spaceAllBox_currentIndexChanged(ui->spaceAllBox->currentIndex());//右
}
