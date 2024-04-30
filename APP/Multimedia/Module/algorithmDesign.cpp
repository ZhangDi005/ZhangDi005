#include "algorithmDesign.h"

const QVector<QString> CHANNEL_NAME = {"LFTW", "LFM", "LFW", "RFTW", "RFM",\
                                      "RFW", "LSTW", "LSM", "LSW", "RSTW",\
                                       "RSM", "RSW", "HLF", "HRF", "HLL",\
                                       "HLR", "LR", "RR", "HLS", "HRS",\
                                       "CTR", "CTR_TW", "SUB"};

const QMap<QString, int> CHANNEL_INDEX = {{"LFTW", 0}, {"LFM", 1}, {"LFW", 2}, {"RFTW", 3}, {"RFM", 4},\
                                         {"RFW", 5}, {"LSTW", 6}, {"LSM", 7}, {"LSW", 8}, {"RSTW", 9},\
                                         {"RSM", 10}, {"RSW", 11}, {"HLF", 12}, {"HRF", 13}, {"HLL", 14},\
                                         {"HLR", 15}, {"LR", 16}, {"RR", 17}, {"HLS", 18}, {"HRS", 10},\
                                         {"CTR", 20}, {"CTR_TW", 21}, {"SUB", 22}};
int SAMPLERATE = 48000;
double PAI = 3.1415926;

QVector<float> AudioDataManage::AVG()
{
    Add add;
    for (int i = 0; i < NUM_MIC; i++) {
        add+=audioData[i].getData();
    }
    return avg(add, NUM_MIC);
}

QDataStream & operator<<(QDataStream &stream, const AudioDataManage &info)
{
    AudioData audio_2 = info.audioData[2];
    stream<<audio_2.getData();
    AudioData audio_3 = info.audioData[2];
    stream<<audio_3.getData();
    return stream;
}

QDataStream & operator>>(QDataStream &stream, AudioDataManage &info)
{
    stream>>info.audioData[2].getData();
    stream>>info.audioData[3].getData();
    return stream;
}

void F_M_P::init() {
    name = "";
    freq.clear();
    magnitude.clear();
    phase.clear();
}

void F_M_P::initTargetCurve()
{
    for (size_t i = 0; i < 20000; i++) {
        freq.push_back(i+1);
    }
}

void F_M_P::operator=(F_M_P fmp){
    freq = fmp.freq;
    magnitude = fmp.magnitude;
    phase = fmp.phase;
}

void fft(AudioData &audio)
{
//    uint32_t totalSamples = audio.getDataSize() / (audio.getBitsPerSample() / 8);
    uint32_t totalSamples = audio.getData().size();
    fftwf_complex* inData = reinterpret_cast<fftwf_complex*>(fftwf_malloc(sizeof(fftwf_complex) * totalSamples));
    fftwf_complex* outData = reinterpret_cast<fftwf_complex*>(fftwf_malloc(sizeof(fftwf_complex) * totalSamples));
    // 创建FFTW计划
    fftwf_plan plan = fftwf_plan_dft_1d(totalSamples, inData, outData, FFTW_FORWARD, FFTW_ESTIMATE);
    // 将音频数据复制到输入数组中
    QVector<float> data = audio.getData();
    for (size_t i = 0; i < totalSamples; ++i) {
        inData[i][0] = static_cast<double>(data[i]);
        inData[i][1] = 0.0;
    }
    // 执行FFT变换
    fftwf_execute(plan);
    uint32_t sampleRate = audio.getSampleRate();
    for (size_t i = 0; i < totalSamples/2; ++i) {
        double freq = static_cast<double>(i) * sampleRate / totalSamples;
        double magnitude = sqrt(outData[i][0] * outData[i][0] + outData[i][1] * outData[i][1]);
        double phase = atan2f(outData[i][1], outData[i][0]);
        audio.getFreq().append(freq);
        double magnitude1 = magnitude / totalSamples * 2;
        double ref = 1;
        double magnitude2 = 20 * log10(magnitude1 / ref);
        audio.getMagnitude().append(magnitude2);
        audio.getPhase().append(phase * (180/3.1415926));
    }
    // 释放内存和FFTW计划
    fftwf_destroy_plan(plan);
    fftwf_free(inData);
    fftwf_free(outData);
}

F_M_P fft(QVector<float> data)
{
    uint32_t totalSamples = data.size();
    fftwf_complex* inData = reinterpret_cast<fftwf_complex*>(fftwf_malloc(sizeof(fftwf_complex) * totalSamples));
    fftwf_complex* outData = reinterpret_cast<fftwf_complex*>(fftwf_malloc(sizeof(fftwf_complex) * totalSamples));
    // 创建FFTW计划
    fftwf_plan plan = fftwf_plan_dft_1d(totalSamples, inData, outData, FFTW_FORWARD, FFTW_ESTIMATE);
    for (size_t i = 0; i < totalSamples; ++i) {
        inData[i][0] = static_cast<double>(data[i]);
        inData[i][1] = 0.0;
    }
    // 执行FFT变换
    fftwf_execute(plan);
    F_M_P fmp;
    for (size_t i = 0; i < totalSamples/2; ++i) {
        double freq = static_cast<double>(i) * SAMPLERATE / totalSamples; // 仅支持32位采样
        double magnitude = sqrt(outData[i][0] * outData[i][0] + outData[i][1] * outData[i][1]);
        double phase = atan2f(outData[i][1], outData[i][0]);
        fmp.freq.append(freq);
        double magnitude1 = magnitude / totalSamples * 2;
        double ref = 1;
        double magnitude2 = 20 * log10(magnitude1 / ref);
        fmp.magnitude.append(magnitude2);
        fmp.phase.append(phase * (180/3.1415926));
    }
    // 释放内存和FFTW计划
    fftwf_destroy_plan(plan);
    fftwf_free(inData);
    fftwf_free(outData);
    return fmp;
}

void Add::operator+=(QVector<float> datas) // 求和
{
    if (m_data.size() == 0) {
        m_data = datas;
        return;
    }
    int count = datas.size();
    for (int i = 0; i < count; i++) {
        m_data[i] += datas.at(i);
    }
}

QVector<float> Add::getData()
{
    return m_data;
}

QVector<float> avg(Add &add, int divisor)
{
    QVector<float> tag = add.getData();
    QVector<float> reData;
    for (int i = 0; i < tag.size(); i++) {
        reData.append(tag.at(i) / divisor);
    }
    return reData;
}

void Channel::aloneToMix()
{
    seatMag_m[0] = seatMag[0].AVG();
    seatMag_m[1] = seatMag[1].AVG();
    seatMag_m[2] = seatMag[2].AVG();
    seatMag_m[3] = seatMag[3].AVG();
}

bool const Channel::seatMagIsEmpty()
{
    return seatMag[0].audioData[0].isEmpty() || seatMag[1].audioData[0].isEmpty() \
            || seatMag[2].audioData[0].isEmpty() || seatMag[3].audioData[0].isEmpty();
}

bool const Channel::seatMag_mIsEmpty()
{
    return seatMag_m.size() == 4;
}

QDataStream & operator<<(QDataStream &stream, const Channel &info)
{
    stream<<info.channelName;
    stream<<info.isTargetCurve;
    stream<<info.seatMag;
    stream<<info.seatMag_m;
    stream<<info.m_channelData;
    stream<<info.m_eq;
    return stream;
}

QDataStream & operator>>(QDataStream &stream, Channel &info)
{
    stream>>info.channelName;
    stream>>info.isTargetCurve;
    stream>>info.seatMag;
    stream>>info.seatMag_m;
    stream>>info.m_channelData;
    stream>>info.m_eq;
    return stream;
}

void narrow_to_octave(QVector<float> &OUT_one_twenty_fourth_freq_preferred, QVector<float> &OUT_bands, QVector<float> frequencies, QVector<float> measurements, int N_Octave)
{
    if (N_Octave == SMOOTH::noSmooth) {
        OUT_one_twenty_fourth_freq_preferred = frequencies;
        OUT_bands = measurements;
        return;
    }
    vector<float>  narrow_array;
    switch (N_Octave)
    {
    case 3:
        for (int i = -30; i < 14; i++)
        {
            narrow_array.push_back(i);
        }
        break;
    case 6:
        for (int i = -60; i < 27; i++)
        {
            narrow_array.push_back(i);
        }
        break;
    case 12:
        for (int i = -119; i < 53; i++)
        {
            narrow_array.push_back(i);
        }
        break;
    case 24:
        for (int i = -239; i < 105; i++)
        {
            narrow_array.push_back(i);
        }
        break;
    case 48:
        for (int i = -479; i < 209; i++)
        {
            narrow_array.push_back(i);
        }
        break;
    default:
        break;
    }

    int n = narrow_array.size();
    QVector<float> one_narrow_freq(n);
    vector<vector<float>> one_narrow_bands(2, vector<float>(n));

    for (int i = 0; i < n; i++)
    {
        float denom = pow(10, (3.0 / (10 * N_Octave)));
        int  numer = narrow_array[i];
        float freq = 1000 * pow(denom, numer);
        one_narrow_freq[i] = 1000 * pow(denom, numer);
        one_narrow_bands[0][i] = one_narrow_freq[i] * pow(2, (1.0 / (N_Octave * 2)));
        one_narrow_bands[1][i] = (one_narrow_freq[i] * 1.0) / (pow(2, (1.0 / (N_Octave * 2))));
    }
    OUT_one_twenty_fourth_freq_preferred = one_narrow_freq;
    vector<float> Nozero_idx;

    int one_third_bands_len = one_narrow_bands[1].size();
    vector<float> one_narrow_bands_data1 = one_narrow_bands[1];
    vector<float> one_narrow_bands_data0 = one_narrow_bands[0];


    float bands0;
    float bands1;
    for (int i = 0; i < one_third_bands_len; i++)
    {
        OUT_bands.push_back(0);
        bands1 = one_narrow_bands_data1[i];
        bands0 = one_narrow_bands_data0[i];

        int autoIndex = 0;

        for (auto num : frequencies)
        {

            if (num >= bands1 && num < bands0)
            {
                Nozero_idx.push_back(autoIndex);
            }
            autoIndex++;
        }

        if (Nozero_idx.size() == 0)
        {
        }
        else if (Nozero_idx.size() == 1)
        {
            OUT_bands[i] = measurements[Nozero_idx[0]];
        }
        else if (Nozero_idx.size() > 1)
        {
            for (int b = 0; b < Nozero_idx.size() - 1; b++)
            {
                OUT_bands[i] = OUT_bands[i] + (frequencies[Nozero_idx[0] + b + 1] - frequencies[Nozero_idx[0] + b]) * (measurements[Nozero_idx[0] + b + 1] + measurements[Nozero_idx[0] + b]) / 2;
            }
            OUT_bands[i] = OUT_bands[i] / (frequencies[Nozero_idx[Nozero_idx.size() - 1]] - frequencies[Nozero_idx[0]]);
        }

        Nozero_idx.clear();
    }
}

void m_mid(QVector<float> &data, QPair<float, float> startAndStop)
{
    float start = startAndStop.first * SAMPLERATE;
    float stop = (startAndStop.second - startAndStop.first) *SAMPLERATE;
    if (startAndStop.first > startAndStop.second || startAndStop.first == startAndStop.second ||\
            (startAndStop.second * SAMPLERATE > data.size()))
        return;
    data.mid(start, stop);
}

double *vectorToArray(QVector<float> vec)
{
    double *bytes = new double[vec.size()];
    for (int i = 0; i < vec.size(); ++i) {
       bytes[i] = vec[i];
    }
    return bytes;
}

QVector<float> arrayToVector(double *bytes, size_t len)
{
    QVector<float> vec;
    for (size_t i = 0; i < len; i++) {
        vec.push_back(bytes[i]);
    }
    return vec;
}

AudioDataManage &SpeakerManage::getAudioMag(int speakId, int seatId)
{
    return speaker[speakId].seatData[seatId];
}

QDataStream & operator<<(QDataStream &stream, const ChannelData &info)
{
    stream<<info.m_selected;
    stream<<info.m_gain;
    stream<<info.m_delay;
    stream<<info.m_invert;
    return stream;
}

QDataStream & operator>>(QDataStream &stream, ChannelData &info)
{
    stream>>info.m_selected;
    stream>>info.m_gain;
    stream>>info.m_delay;
    stream>>info.m_invert;
    return stream;
}

QDataStream & operator<<(QDataStream &stream, const EqData &info)
{
    stream<<(int)info.m_type;
    stream<<info.m_order;
    stream<<info.m_fc;
    stream<<info.m_gain;
    stream<<info.m_q;
    stream<<info.m_selected;
    return stream;
}

QDataStream & operator>>(QDataStream &stream, EqData &info)
{
    int type;
    stream>>type;
    info.m_type = (FilterType)type;
    stream>>info.m_order;
    stream>>info.m_fc;
    stream>>info.m_gain;
    stream>>info.m_q;
    stream>>info.m_selected;
    return stream;
}
