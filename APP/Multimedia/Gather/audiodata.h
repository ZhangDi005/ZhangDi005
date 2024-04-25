#ifndef AUDIODATA_H
#define AUDIODATA_H

#include <complex>
#include <fstream>
#include <QVector>
#include <QFileInfo>

using namespace std;
// WAV文件头结构
struct WavHeader {
    char chunkId[4];
    uint32_t chunkSize;
    char format[4];
    char subChunk1Id[4];
    uint32_t subChunk1Size;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
};

class AudioData
{
public:
    AudioData();
    ~AudioData();

    bool init(QString filePath);
    int getNumChannels();
    int getSampleRate();
    int getBitsPerSample();
    int getDataSize();
    QVector<float> & getData();
    QString getFileName();
    QVector<double> &getFreq();
    QVector<double> &getMagnitude();
    QVector<double> &getPhase();
    bool isEmpty();

private:
    QString m_name;
    int m_numChannels; // 通道数
    int m_sampleRate; // 采样率
    int m_bitsPerSample; // 位深
    int m_dataSize = 0; // 数据大小
    QVector<float> m_data; //音频数据
    // fft后的数据
    QVector<double> m_freq;
    QVector<double> m_magnitude;
    QVector<double> m_phase;

};

#endif // AUDIODATA_H
