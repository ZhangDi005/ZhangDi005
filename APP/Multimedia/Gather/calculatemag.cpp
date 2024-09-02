#include "calculatemag.h"
#include "ui_calculatemag.h"


CalculateMag::CalculateMag(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculateMag)
{
    ui->setupUi(this);
    init();
    ui->freq_chart->setChartType(CHART_TYPE::MAGNITUDE_CHART);
    ui->phase_chart->setChartType(CHART_TYPE::PHASE_CHART);
}

CalculateMag::~CalculateMag()
{
    delete ui;
}

void CalculateMag::setPhaseChartIsVis(bool selected)
{
    ui->phase_chart->setVisible(selected);
}

void CalculateMag::init()
{
    speaker = new QButtonGroup(this);
    speaker->setExclusive(true);
    speaker->addButton(ui->speaker_LFTW, 0);
    speaker->addButton(ui->speaker_LFM, 1);
    speaker->addButton(ui->speaker_LFW, 2);
    speaker->addButton(ui->speaker_RFTW, 3);
    speaker->addButton(ui->speaker_RFM, 4);
    speaker->addButton(ui->speaker_RFW, 5);
    speaker->addButton(ui->speaker_LSTW, 6);
    speaker->addButton(ui->speaker_LSM, 7);
    speaker->addButton(ui->speaker_LSW, 8);
    speaker->addButton(ui->speaker_RSTW, 9);
    speaker->addButton(ui->speaker_RSM, 10);
    speaker->addButton(ui->speaker_RSW, 11);
    speaker->addButton(ui->speaker_HLF, 12);
    speaker->addButton(ui->speaker_HRF, 13);
    speaker->addButton(ui->speaker_HLL, 14);
    speaker->addButton(ui->speaker_HLR, 15);
    speaker->addButton(ui->speaker_LR, 16);
    speaker->addButton(ui->speaker_RR, 17);
    speaker->addButton(ui->speaker_HLS, 18);
    speaker->addButton(ui->speaker_HRS, 19);
    speaker->addButton(ui->speaker_CTR, 20);
    speaker->addButton(ui->speaker_CTR_TW, 21);
    speaker->addButton(ui->speaker_SUB, 22);

    location = new QButtonGroup(this);
    location->setExclusive(true);
    location->addButton(ui->location_LF, 0);
    location->addButton(ui->location_RF, 1);
    location->addButton(ui->location_MID_LS, 2);
    location->addButton(ui->location_MID_RS, 3);
    location->addButton(ui->location_LS, 4);
    location->addButton(ui->location_RS, 5);

    connect(speaker, static_cast<void (QButtonGroup::*)(int)>(&QButtonGroup::buttonPressed), this, [=](int id){
        speakerId = id;
        show_freqPlot();
    });
    connect(location, static_cast<void (QButtonGroup::*)(int)>(&QButtonGroup::buttonPressed), this, [=](int id){
        seatId = id;
        show_freqPlot();
    });
}

void CalculateMag::on_importBtn_clicked()
{
    if (speakerId == -1 || seatId == -1) {
        QMessageBox::warning(this, "提示", "选择扬声器&位置");
        return;
    }

    QSettings setting("./setting/imPort.ini", QSettings::IniFormat);
    QString lastPath = setting.value("LastInportwavPath").toString();
    QStringList fileNames = QFileDialog::getOpenFileNames(this,
                                                          "Select one or more files to open",
                                                          lastPath,
                                                          "Images (*.wav)");
    if (fileNames.isEmpty() || (fileNames.size() != NUM_MIC))
        return;
    setting.setValue("LastInportwavPath", fileNames.at(0));
    loadAudio(fileNames);

}

void CalculateMag::loadAudio(const QStringList fileNames)
{
    QList<Channel> &project = App::instance().getProject();
    Channel channel;
    channel.channelName = CHANNEL_INDEX.key(speakerId);
    bool flag = false;
    int index = 0;
    for (index = 0; index < project.size(); index++) {
        if (project.at(index).channelName == CHANNEL_INDEX.key(speakerId)) {
            channel = project.at(index);
            flag = true;
            break;
        }
    }
    AudioDataManage audioMag;
    for (int i = 0; i < NUM_MIC; i++) {
        if (!audioMag.audioData[i].init(fileNames.at(i))) {
            QMessageBox::question(this, "错误", "音频加载失败");
            return;
        }
        fft(audioMag.audioData[i]);
    }
    channel.seatMag.insert(seatId, audioMag);
    if (!channel.seatMagIsEmpty())
        channel.aloneToMix();

    if (!flag) {
        project.push_back(channel);
    } else
        project.replace(index, channel);

    show_freqPlot();
}

void CalculateMag::show_freqPlot()
{
    if (speakerId == -1 || seatId == -1)
        return;
    QList<Channel> project = App::instance().getProject();
    AudioDataManage audioDatas;
    for (auto channel : project) {
        if (channel.channelName == CHANNEL_NAME[speakerId]) {
            audioDatas = channel.seatMag.value(seatId);
            break;
        }
    }
    if (audioDatas.audioData[0].getDataSize() == 0) {
        ui->freq_chart->clearGraphs();
        ui->phase_chart->clearGraphs();
        return;
    }
    ui->freq_chart->setData(audioDatas);
    ui->phase_chart->setData(audioDatas);
    on_selectBox_currentIndexChanged(ui->selectBox->currentIndex());
}


void CalculateMag::on_selectBox_currentIndexChanged(int index)
{
    ui->freq_chart->setSelectPlot(index);
    ui->phase_chart->setSelectPlot(index);
}

void CalculateMag::on_tiggerBtn_clicked()
{
    ui->location_MID_LS->setVisible(!ui->location_MID_LS->isVisible());
    ui->location_MID_RS->setVisible(!ui->location_MID_RS->isVisible());
}
