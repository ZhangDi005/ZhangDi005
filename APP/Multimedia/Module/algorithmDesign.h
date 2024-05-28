#ifndef FFT_H
#define FFT_H

#include <QMap>
#include <QDataStream>
#include "Gather/audiodata.h"
#include "fftw3.h"

#define NUM_MIC 6
#define NUM_CHANNEL 24
#define NUM_SEAT 4

extern const QVector<QString> CHANNEL_NAME; // 依次与名字对应
extern const QMap<QString, int> CHANNEL_INDEX;

extern int SAMPLERATE;
extern double PAI;

// 麦克风采集的一组数据
struct AudioDataManage {
    AudioData audioData[NUM_MIC];
    QVector<float> AVG();
    friend QDataStream & operator<<(QDataStream &stream, const AudioDataManage &info);
    friend QDataStream & operator>>(QDataStream &stream, AudioDataManage &info);
};

// 每个扬声器对应4个位置
struct SeatManage {
    AudioDataManage seatData[NUM_SEAT];
};

// 6/8/10/12 多个扬声器对应的数据 默认24
struct SpeakerManage {
    SeatManage speaker[NUM_CHANNEL];
    AudioDataManage &getAudioMag(int speakId, int seatMag);
};

struct ChannelData {
    bool m_selected = false;
    float m_gain = 0;
    float m_delay = 0;
    bool m_invert = false;
    friend QDataStream & operator<<(QDataStream &stream, const ChannelData &info);
    friend QDataStream & operator>>(QDataStream &stream, ChannelData &info);
};

enum FilterType {
    Parametric = 0,
    Bass_Shelf,
    Treble_Shelf,
    Phase_Changer,
    Lowpass_LR,
    Highpass_LR,
    Lowpass_BW,
    Highpass_BW,
    Bandpass,
    Bypass,
};

struct EqData {
    FilterType m_type = FilterType::Parametric;
    int m_order = 2;
    int m_fc = 0;
    float m_gain = 0;
    float m_q = 0;
    bool m_selected = false;
    friend QDataStream & operator<<(QDataStream &stream, const EqData &info);
    friend QDataStream & operator>>(QDataStream &stream, EqData &info);
};

struct OverAll {
    ChannelData m_channelData;
    QVector<EqData> m_eq;
    friend QDataStream & operator<<(QDataStream &stream, const OverAll &info);
    friend QDataStream & operator>>(QDataStream &stream, OverAll &info);
};

struct BackupData {
    int m_flag;
    QString m_remark;
    QMap<QString, OverAll> m_overAll;
    friend QDataStream & operator<<(QDataStream &stream, const BackupData &info);
    friend QDataStream & operator>>(QDataStream &stream, BackupData &info);
};

struct Channel{
    QString channelName;
    bool isTargetCurve = false;
    QMap<int, AudioDataManage> seatMag;
    QMap<int, QVector<float>> seatMag_m;
    ChannelData m_channelData;
    QVector<EqData> m_eq;
    void aloneToMix();
    bool const seatMagIsEmpty();
    bool const seatMag_mIsEmpty();
    friend QDataStream & operator<<(QDataStream &stream, const Channel &info);
    friend QDataStream & operator>>(QDataStream &stream, Channel &info);
};

enum CHART_TYPE {
    NONE = 0,
    MAGNITUDE_CHART,
    PHASE_CHART
};

struct F_M_P {
    QString name;
    QVector<float> freq;
    QVector<float> magnitude;
    QVector<float> phase;
    bool isTargetCurve = false;
    void init();
    void initTargetCurve();
    void operator=(F_M_P fmp);
};

enum SMOOTH {
    noSmooth = 0,
    oneThird = 3,
    onesixth = 6,
    onetwelfth = 12,
    oneTwenty_fourth = 24,
    oneForty_eighth = 48
};

enum CURVEMODE {
    dbFs = 0,
    SPI
};

class Add {
public:
    void operator+=(QVector<float> datas);
    QVector<float> getData();
private:
    QVector<float> m_data;
};

void fft(AudioData &audio);
F_M_P fft(QVector<float> data, CURVEMODE mode);
QVector<float> avg(Add &add, int divisor);
void m_mid(QVector<float> &data, QPair<float, float> startAndStop);
double *vectorToArray(QVector<float> vec);
QVector<float> arrayToVector(double *bytes, size_t len);

// 平滑处理
void narrow_to_octave(QVector<float> &OUT_one_twenty_fourth_freq_preferred, QVector<float> &OUT_bands, QVector<float> frequencies, QVector<float> measurements, int N_Octave);
#endif // FFT_H
