#include "audiodata.h"
#include <QDebug>
size_t get_DATA_Pos(QString filePath)
{
    std::ifstream file(filePath.toLocal8Bit().toStdString(), std::ios::binary);
    if (!file.is_open())
        return 0;
    string line;
    int line_num = 0; // 行号
    size_t pos = 0;
    while (getline(file, line)) {
        line_num++;
        pos = line.find("data");
        if (pos != string::npos)
            break;
    }
    return pos+4;
}

AudioData::AudioData()
{

}

AudioData::~AudioData()
{

}

bool AudioData::init(QString filePath)
{
    std::ifstream file(filePath.toLocal8Bit().toStdString(), std::ios::binary);
    if (!file.is_open())
        return false;
    WavHeader header{};
    file.read(reinterpret_cast<char*>(&header), sizeof(WavHeader));
    {
//    qDebug() << "chunkid" << sizeof(WavHeader);
//    qDebug() << "chunkid" << header.chunkId;
//    qDebug() << "chunkSize" << header.chunkSize;
//    qDebug() << "format" << header.format;
//    qDebug() << "subChunk1Id" << header.subChunk1Id;
//    qDebug() << "subChunk1Size" << header.subChunk1Size;
//    qDebug() << "audioFormat" << header.audioFormat;
//    qDebug() << "numChannels" << header.numChannels;
//    qDebug() << "sampleRate" << header.sampleRate;
//    qDebug() << "byteRate" << header.byteRate;
//    qDebug() << "blockAlign" << header.blockAlign;
//    qDebug() << "bitsPerSample" << header.bitsPerSample;
    }

    // 初始化audio数据
    m_name = QFileInfo(filePath).fileName();
    m_numChannels = header.numChannels;
    m_sampleRate = header.sampleRate;
    m_bitsPerSample = header.bitsPerSample;
    size_t pos = get_DATA_Pos(filePath);
    file.seekg(pos, std::ios::beg);
    file.read(reinterpret_cast<char*>(&m_dataSize), sizeof(uint32_t));
    // 确定每个样本的字节数
    uint16_t bytesPerSample = header.bitsPerSample / 8;

    // 计算音频数据的总采样数
    uint32_t totalSamples = m_dataSize / bytesPerSample;
    char *data = (char*)malloc(m_dataSize);
    file.read(data, m_dataSize);
    file.close();
    if (totalSamples < 100000) return false; // 正常情况 数据永远大于10000，避免程序崩溃
    for (int i = 0; i < totalSamples; i++) { // 对于所有fft的幅值图，取原始数据的[0,100000]范围的数据；
        if (bytesPerSample == 2)
            m_data << ((short*)data)[i];
        else if (bytesPerSample == 4)
            m_data << ((float*)data)[i];
    }
    free(data);
    return !m_data.empty();
}

int AudioData::getNumChannels()
{
    return m_numChannels;
}

int AudioData::getSampleRate()
{
    return m_sampleRate;
}

int AudioData::getBitsPerSample()
{
    return m_bitsPerSample;
}

int AudioData::getDataSize()
{
    return m_dataSize;
}

QVector<float> & AudioData::getData()
{
    return m_data;
}

QString AudioData::getFileName()
{
    return m_name;
}

QVector<double> &AudioData::getFreq()
{
    return m_freq;
}

QVector<double> &AudioData::getMagnitude()
{
    return m_magnitude;
}

QVector<double> &AudioData::getPhase()
{
    return m_phase;
}

bool AudioData::isEmpty()
{
    return m_data.empty();
}

