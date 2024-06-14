#include "EQ.h"

int fs = 48000;

//IN_data输入，OUT_data输出，in_len长度，a为分子系数，b分母系数，number滤波器阶数(系数的数组长度)
QVector<float> EQ::filter(QVector<float> IN_data_, Eq_ata* ata, int number)
{
    double tmp;
    int i, j;
    int in_len = IN_data_.size();
    float* IN_data = IN_data_.data();
    double* a = ata->a.data();
    double* b = ata->b.data();
    //double * OUT_data=nullptr;
    //double OUT_data[30] = { 0 };
    double * OUT_data = new double[in_len];

    //normalization
    if ((*a - 1.0 > EPS) || (*a - 1.0 < -EPS))
    {
        tmp = *a;
        for (i = 0; i < number; i++)
        {
            b[i] /= tmp;
            a[i] /= tmp;
        }
    }
    memset(OUT_data, 0, in_len * sizeof(double));

    a[0] = 0.0;
    for (i = 0; i < in_len; i++)
    {
        for (j = 0; i >= j && j < number; j++)
        {
            OUT_data[i] += (b[j] * IN_data[i - j] - a[j] * OUT_data[i - j]);
        }
        // if(zi&&i<nfilt-1) y[i] += zi[i];   //zi[i],查分方程可以不计，滤波的表达式 1.[y, zf] = filter(b ,a, X) 2.[y, zf] = filter(b, a, X, zi)
    }
    a[0] = 1.0;

    QVector<float> out;
    for (int num = 0; num < in_len; num++)
    {
        out.push_back(OUT_data[num]);
    }
    delete []OUT_data;
    return out;

}

//系数乘积
void EQ::series(double A0[3], double B0[3])
{


	double A1 = A0[0];
	double A2 = A0[1];
	double A3 = A0[2];

	double B1 = B0[0];
	double B2 = B0[1];
	double B3 = B0[2];

	double mole[5] = { 0 };    //分子
	double denom[5] = { 0 };   //分母

	mole[0] = A1 * A1;
	mole[1] = A1 * A2 + A2 * A1;
	mole[2] = A1 * A3 + A2 * A2 + A3 * A1;
	mole[3] = A2 * A3 + A3 * A2;
	mole[4] = A3 * A3;

	denom[0] = B1 * B1;
	denom[1] = B1 * B2 + B2 * B1;
	denom[2] = B1 * B3 + B2 * B2 + B3 * B1;
	denom[3] = B2 * B3 + B3 * B2;
	denom[4] = B3 * B3;

	for (int i = 0; i < 5; i++)
	{
		Mole_data.push_back(mole[i]);
		Denom_data.push_back(denom[i]);
	}

}

///////////////////////////////////////////////////EQ函数//////////////////////////////////////////////////////////////////////////////////////////////


//order :默认2阶
//EQ_fc  :频率
//EQ_Gain:无
//EQ_Q: 无
// fs : 采样率48000
EQ::Eq_ata* EQ::Phase_Changer(int EQ_fc, double EQ_Gain, double EQ_Q)
{
	Eq_ata *data = new Eq_ata();
	double w0 = 2 * PI * EQ_fc / fs;
    double Q = EQ_Q;
	double alpha = sin(w0) / (2 * Q);
	double b0 = 1 - alpha;
	double b1 = -2 * cos(w0);
	double b2 = 1 + alpha;
	double a0 = 1 + alpha;
	double a1 = -2 * cos(w0);
	double a2 = 1 - alpha;
	double b_[3] = {b0 / a0,b1 / a0, b2 / a0,};
	double a_[3] = { a0 / a0,a1 / a0, a2 / a0, };

	for (int i = 0; i < 3; i++)
	{
		data->a.push_back(a_[i]);
		data->b.push_back(b_[i]);
	}
	//data->a = a_;
	//data->b = b_;
	return data;
}


//order :默认2阶
//EQ_fc  :频率
//EQ_Gain:无
//EQ_Q: 有
// fs : 采样率48000
EQ::Eq_ata* EQ::Bandpass(int EQ_FC, double EQ_Q)
{
    Eq_ata *data = new Eq_ata();
    if (EQ_Q == 0) {
        return nullptr;
    }
	double w0 = 2 * PI * EQ_FC / fs;
	double alpha = sin(w0) / (2 * EQ_Q);
	double b0 = sin(w0) / 2;
	double b1 = 0;
	double b2 = -sin(w0) / 2;
	double a0 = 1 + alpha;
	double a1 = -2 * cos(w0);
	double a2 = 1 - alpha;
	double b_[3] = { b0 / a0,b1 / a0, b2 / a0, };
	double a_[3] = { a0 / a0,a1  / a0, a2 / a0, };

	for (int i = 0; i < 3; i++)
	{
		data->a.push_back(a_[i]);
		data->b.push_back(b_[i]);
	}
	//data->a = a_;
	//data->b = b_;
	return data;
}

//order :默认2阶
//EQ_fc  :频率
//EQ_Gain:有
//EQ_Q: 有
// fs : 采样率48000
EQ::Eq_ata* EQ::Parametric(int EQ_FC, double EQ_Gain, double EQ_Q)
{
	Eq_ata *data = new Eq_ata();
    if ((EQ_Gain == 0) || (EQ_Q == 0)) {
        return nullptr;
    }
	double A = pow(10, EQ_Gain / 40);
	double w = 2 * PI * EQ_FC / fs;
	double sn = sin(w);
	double cs = cos(w);
	double a1 = sn  / (2 * EQ_Q);
	double a_1 = 1 + a1/ A;
	
    double b_[3] = { (1 + a1* A)  / a_1,(-2 * cs) / a_1,(1 - a1 * A) / a_1  };
	double a_[3] = { (1 + a1/ A)  / a_1,(-2 * cs)/ a_1,(1 - a1 / A) / a_1 };

	for (int i = 0; i < 3; i++)
	{
		data->a.push_back(a_[i]);
		data->b.push_back(b_[i]);
	}
	/*data->a = a_;
	data->b = b_;*/
	return data;
}

//输入参数：4阶高通滤波
//order :4阶
//EQ_fc  :频率
//EQ_Gain:无
//EQ_Q: 无
// fs : 采样率48000
EQ::Eq_ata* EQ::Highpass_LR(int EQ_FC)
{
	Eq_ata *data = new Eq_ata();
	double w0 = 2 * PI * EQ_FC  / fs;
	double Q = 0.707;
	double alpha = sin(w0) / (2 * Q);
	double b0 = (1 + cos(w0))  / 2;
	double b1 = -(1 + cos(w0));
	double b2 = (1 + cos(w0)) / 2;
	double a0 = 1 + alpha;
	double a1 = -2 * cos(w0);
	double a2 = 1 - alpha;
	double b_[3] = { b0  / a0,b1 / a0, b2  / a0, };
	double a_[3] = { a0  / a0,a1 / a0, a2  / a0, };


	series(a_,b_);

	double mole[5] = {0};
	double denom[5] = {0};

	for (int i = 0; i < 5; i++)
	{
		mole[i] = Mole_data[i];
		denom[i] = Denom_data[i];
	}

	for (int i = 0; i < 5; i++)
	{
		data->a.push_back(mole[i]);
		data->b.push_back(denom[i]);
	}

	//data->a = mole;
	//data->b = denom;
	return data;


}

//4阶低通滤波
//order :4
//EQ_fc  :频率
//EQ_Gain:无
//EQ_Q: 无
// fs : 采样率48000
EQ::Eq_ata* EQ::Lowpass_LR(int EQ_FC)
{
    Eq_ata *data = new Eq_ata();
//    size_t th = PAI * EQ_FC / SAMPLERATE;
//    size_t Wc = PAI * EQ_FC;
//    size_t k = Wc / tan(th);

//    size_t d = pow(k, 2.0) + pow(Wc, 2.0) + 2.0 * k * Wc;
//    data->b.push_back(pow(Wc, 2.0) / d);
//    data->b.push_back(2.0 * pow(Wc, 2.0) / d);
//    data->b.push_back(pow(Wc, 2.0) / d);
//    data->a.push_back(1);
//    data->a.push_back((-2.0 * pow(k, 2.0) + 2.0 * pow(Wc, 2.0)) / d);
//    data->a.push_back((-2.0 * k * Wc + pow(k, 2.0) + pow(Wc, 2.0)) / d);
//    return data;
    double w0 = 2 * PI * EQ_FC  / fs;
    double Q = 0.707;
    double alpha = sin(w0) / (2 * Q);
    double b0 = (1 - cos(w0))  / 2;
    double b1 = 1 - cos(w0);
    double b2 = (1 - cos(w0))  / 2;
    double a0 = 1 + alpha;
    double a1 = -2 * cos(w0);
    double a2 = 1 - alpha;
    double b_[3] = { b0 / a0,b1 / a0, b2  / a0, };
    double a_[3] = { a0 / a0,a1  / a0, a2  / a0, };


    series(a_, b_);
    double mole[5] = { 0 };
    double denom[5] = { 0 };

    for (int i = 0; i < 5; i++)
    {
        mole[i] = Mole_data[i];
        denom[i] = Denom_data[i];
    }

    for (int i = 0; i < 5; i++)
    {
        data->a.push_back(mole[i]);
        data->b.push_back(denom[i]);
    }

//	data->a = mole;
//	data->b = denom;

    return data;

}

//order :2
//EQ_fc  :频率
//EQ_Gain:有
//EQ_Q: 有
// fs : 采样率48000
EQ::Eq_ata* EQ::Base_Shelf(int EQ_FC, double EQ_Gain, double EQ_Q)
{
    Eq_ata *data = new Eq_ata();

    double *value_a = nullptr;
    double *value_b = nullptr;
    double A = sqrt(pow(10, (EQ_Gain) / 20));
    double w0 = 2 * PI * EQ_FC / fs;
    double alpha = sin(w0) / (2 * EQ_Q);

    double b0 = A * ((A + 1) - (A - 1)*cos(w0) + 2 * sqrt(A)*alpha);
    double b1 = 2 * A*((A - 1) - (A + 1)*cos(w0));
    double b2 = A * ((A + 1) - (A - 1)*cos(w0) - 2 * sqrt(A)*alpha);
    double a0 = (A + 1) + (A - 1)*cos(w0) + 2 * sqrt(A)*alpha;
    double a1 = -2 * ((A - 1) + (A + 1)*cos(w0));
    double a2 = (A + 1) + (A - 1)*cos(w0) - 2 * sqrt(A)*alpha;

    double b_[5] = { b0 / a0,b1 / a0, b2 / a0 };
    double a_[5] = { a0 / a0,a1 / a0, a2 / a0 };
    value_a = a_;
    value_b = b_;

    for (int i = 0; i < 2 + 1; i++) // order + 1
    {
        data->a.push_back(value_a[i]);
        data->b.push_back(value_b[i]);
    }
    return data;
}

//order :2
//EQ_fc  :频率
//EQ_Gain:有
//EQ_Q: 有
// fs : 采样率48000
EQ::Eq_ata* EQ::Treble_Shelf(int EQ_FC, double EQ_Gain, double EQ_Q)
{
    Eq_ata *data = new Eq_ata();

    double *value_a = nullptr;
    double *value_b = nullptr;
    double A = sqrt(pow(10, (EQ_Gain) / 20));
    double w0 = 2 * PI * EQ_FC / fs;
    double alpha = sin(w0) / (2 * EQ_Q);

    double b0 = A * ((A + 1) + (A - 1)*cos(w0) + 2 * sqrt(A)*alpha);
    double b1 = -2 * A*((A - 1) + (A + 1)*cos(w0));
    double b2 = A * ((A + 1) + (A - 1)*cos(w0) - 2 * sqrt(A)*alpha);
    double a0 = (A + 1) - (A - 1)*cos(w0) + 2 * sqrt(A)*alpha;
    double a1 = 2 * ((A - 1) - (A + 1)*cos(w0));
    double a2 = (A + 1) - (A - 1)*cos(w0) - 2 * sqrt(A)*alpha;

    double b_[5] = { b0 / a0,b1 / a0, b2 / a0};
    double a_[5] = { a0 / a0,a1 / a0, a2 / a0 };
    value_a = a_;
    value_b = b_;

    for (int i = 0; i < 2 + 1; i++)
    {
        data->a.push_back(value_a[i]);
        data->b.push_back(value_b[i]);
    }
    return data;
}


//高阶滤波合集
//order :1/2/3/4
//EQ_fc  :频率
//EQ_Gain:无
//EQ_Q: 无
// fs : 采样率48000
EQ::Eq_ata* EQ::Highpass_BW(int order, int EQ_FC)
{
	Eq_ata *data = new Eq_ata();
	double *value_a = nullptr;
	double *value_b = nullptr;
	switch (order)
	{
	case 1:
	{
		double th = 2.0 * PI * EQ_FC / fs;
		double g = cos(th) / (1.0 + sin(th));
		double b0 = (1.0 + g) / 2.0;
		double b1 = -((1.0 + g) / 2.0);
		double a0 = 1.0;
		double a1 = -g;
		double b_[2] = { b0 ,b1 };
		double a_[2] = { a0 ,a1 };
		value_a = a_;
		value_b = b_;
		break;
	}
	case 2:
	{
		double w0 = 2 * PI * EQ_FC / fs;
		double Q = 0.707;
		double alpha = sin(w0) / (2 * Q);
		double b0 = (1 + cos(w0)) / 2;
		double b1 = -(1 + cos(w0));
		double b2 = (1 + cos(w0)) / 2;
		double a0 = 1 + alpha;
		double a1 = -2 * cos(w0);
		double a2 = 1 - alpha;
		double b_[3] = { b0 / a0,b1 / a0, b2 / a0, };
		double a_[3] = { a0 / a0,a1 / a0, a2 / a0, };
		value_a = a_;
		value_b = b_;
		break;
	}
	case 3:
	{
		double T_ = 1.0 / fs;
		double wc = 2 * PI * EQ_FC * T_;
		double theta = 1.0 / tan(wc / 2);   //余切
		double b0 = theta * theta * theta;
		double b1 = -theta * theta * theta * 3;
		double b2 = theta * theta * theta * 3;
		double b3 = -theta * theta * theta;
		double a0 = 2 * theta * theta + 2 * theta + 1 + theta * theta * theta;
		double a1 = -3 * theta * theta * theta - 2 * theta * theta + 2 * theta + 3;
		double a2 = 3 * theta * theta * theta - 2 * theta * theta - 2 * theta + 3;
		double a3 = 1 - 2 * theta + 2 * theta * theta - theta * theta * theta;

		double b_[4] = { b0 / a0,b1 / a0, b2 / a0,b3 / a0 };
		double a_[4] = { a0 / a0,a1 / a0, a2 / a0,a3 / a0 };
		value_a = a_;
		value_b = b_;
		break;
	}
	case 4:
	{
		double num1 = 2.6131259;
		double num2 = 3.4142136;
		double T_ = 1.0 / fs;
		double wc = 2 * PI * EQ_FC * T_;
		double theta = 1.0 / tan(wc / 2);    //余切
		double b0 = theta * theta * theta * theta;
		double b1 = -theta * theta * theta * theta * 4;
		double b2 = theta * theta * theta * theta * 6;
		double b3 = -theta * theta * theta * theta * 4;
		double b4 = theta * theta * theta * theta;

		double a0 = theta * theta * theta * theta + num1 * theta * theta * theta + num2 * theta * theta + num1 * theta + 1;
		double a1 = -4 * theta * theta * theta * theta - 2 * num1 * theta * theta * theta + 2 * num1 * theta + 4;
		double a2 = 6 * theta * theta * theta * theta - 2 * num2 * theta * theta + 6;
        double a3 = -4 * theta * theta * theta * theta + 2 * num1 * theta * theta * theta - 2 * num1 * theta + 4;
		double a4 = theta * theta * theta * theta - num1 * theta * theta * theta + num2 * theta * theta - num1 * theta + 1;

		double b_[5] = { b0 / a0,b1 / a0, b2 / a0,b3 / a0, b4 / a0 };
		double a_[5] = { a0 / a0,a1 / a0, a2 / a0,a3 / a0 ,a4 / a0 };
		value_a = a_;
		value_b = b_;
		break;
	}
	default:
		break;
	}

		for (int i = 0; i < order+1; i++)
		{
			data->a.push_back(value_a[i]);
			data->b.push_back(value_b[i]);
		}
		return data;
	}

//低阶滤波合集
//order :1/2/3/4
//EQ_fc  :频率
//EQ_Gain:无
//EQ_Q: 无
// fs : 采样率48000
EQ::Eq_ata* EQ::Lowpass_BW(int order, int EQ_FC)
{
	Eq_ata *data = new Eq_ata();
	double *value_a = nullptr;
	double *value_b = nullptr;
	switch (order)
	{
	case 1:
	{
		double th = 2.0 * PI * EQ_FC / fs;
		double g = cos(th) / (1.0 + sin(th));
		double b0 = (1.0 - g) / 2.0;
		double b1 = (1.0 - g) / 2.0;
		double a0 = 1.0;
		double a1 = -g;
		double b_[2] = { b0, b1 };
		double a_[2] = { a0 ,a1 };
		value_a = a_;
		value_b = b_;
		break;
	}
	case 2:
	{
		double w0 = 2 * PI * EQ_FC / fs;
		double Q = 0.707;
		double alpha = sin(w0) / (2 * Q);
		double b0 = (1 - cos(w0)) / 2;
		double b1 = 1 - cos(w0);
		double b2 = (1 - cos(w0)) / 2;
		double a0 = 1 + alpha;
		double a1 = -2 * cos(w0);
		double a2 = 1 - alpha;
		double b_[3] = { b0 / a0,b1 / a0, b2 / a0, };
		double a_[3] = { a0 / a0,a1 / a0, a2 / a0, };
		value_a = a_;
		value_b = b_;
		break;
	}
	case 3:
	{
		double T_ = 1.0 / fs;
		double wc = 2 * PI * EQ_FC * T_;
		double theta = tan(wc / 2);   //正切
		double b0 = theta * theta * theta;
		double b1 = theta * theta * theta * 3;
		double b2 = theta * theta * theta * 3;
		double b3 = theta * theta * theta;

		double a0 = 2 * theta * theta + 2 * theta + 1 + theta * theta * theta;
		double a1 = -3 - 2 * theta + 2 * theta * theta + 3 * theta * theta * theta;
		double a2 = 3 - 2 * theta - 2 * theta * theta + 3 * theta * theta * theta;
		double a3 = 2 * theta - 1 + 2 * theta * theta + theta * theta * theta;

		double b_[4] = { b0 / a0,b1 / a0, b2 / a0,b3 / a0 };
		double a_[4] = { a0 / a0,a1 / a0, a2 / a0,a3 / a0 };
		value_a = a_;
		value_b = b_;
		break;
	}
	case 4:
	{
		double num1 = 2.6131259;
		double num2 = 3.4142136;
		double T_ = 1.0 / fs;
		double wc = 2 * PI * EQ_FC * T_;
		double theta = tan(wc / 2);    //正切
		double b0 = theta * theta * theta * theta;
		double b1 = theta * theta * theta * theta * 4;
		double b2 = theta * theta * theta * theta * 6;
		double b3 = theta * theta * theta * theta * 4;
		double b4 = theta * theta * theta * theta;

		double a0 = theta * theta * theta * theta + num1 * theta * theta * theta + num2 * theta * theta + num1 * theta + 1;
		double a1 = 4 * theta * theta * theta * theta + 2 * num1 * theta * theta * theta - 2 * num1 * theta - 4;
		double a2 = 6 * theta * theta * theta * theta - 2 * num2 * theta * theta + 6;
		double a3 = 4 * theta * theta * theta * theta - 2 * num1 * theta * theta * theta + 2 * num1 * theta - 4;
		double a4 = theta * theta * theta * theta - num1 * theta * theta * theta + num2 * theta * theta - num1 * theta + 1;

		double b_[5] = { b0 / a0,b1 / a0, b2 / a0,b3 / a0, b4 / a0 };
		double a_[5] = { a0 / a0,a1 / a0, a2 / a0,a3 / a0 ,a4 / a0 };
		value_a = a_;
		value_b = b_;
		break;
	}
	default:
		break;
	}

	for (int i = 0; i < order + 1; i++)
	{
		data->a.push_back(value_a[i]);
		data->b.push_back(value_b[i]);
	}
	return data;
}
complex<long double> * divisionComplex(complex<long double>* value1, complex<long double>* vlaue2)
{
    complex<long double> *freq_response = new complex<long double>[EQ_ORDER_LEN];
    for (int i = 0; i < EQ_ORDER_LEN; i++)
    {
        //   a+bi/c+di=(ac+bd)/(c*c +d*d) +(bc-ad)(c*c+d*d)i
            double a = value1[i].real();
            double b = value1[i].imag();
            double c = vlaue2[i].real();
            double d = vlaue2[i].imag();
            double trueValue_real = (a*c + b * d) / (c * c + d * d);
            double trueValue_image = (b * c - a * d) / (c * c + d * d);
            freq_response[i] = complex<double>(trueValue_real, trueValue_image);
    }

    return freq_response;
}

long double* getAmplitude(complex<long double> *freq_response)
{
    long double *result = new long double[EQ_ORDER_LEN];

    for (size_t i = 0; i < EQ_ORDER_LEN; i++)
    {
        long double value = sqrt(freq_response[i].real() * freq_response[i].real() + freq_response[i].imag() * freq_response[i].imag());
        result[i] = 20 * log10(value);
    }

    return result;
}

long double* addComplex(complex<long double> *b1, complex<long double> *b2, complex<long double> *b3, complex<long double> *b4, long double number_b, complex<long double> *a1, complex<long double> *a2, complex<long double> *a3, complex<long double> *a4, long double number_a)
{
    complex<long double> *hup = new complex<long double>[EQ_ORDER_LEN];
    complex<long double> *hdown = new complex<long double>[EQ_ORDER_LEN];
//    complex<long double> *freq_response = new complex<long double>[EQ_ORDER_LEN];
//    long double *response = new long double[EQ_ORDER_LEN];

    for (int i = 0; i < EQ_ORDER_LEN; i++)
    {
        double realvalue = b1[i].real() + b2[i].real() + b3[i].real() + b4[i].real() + number_b;
        double imagvalue = b1[i].imag() + b2[i].imag() + b3[i].imag() + b4[i].imag();
        hup[i] = complex<double>(realvalue, imagvalue);
        double realvalue1 = a1[i].real() + a2[i].real() + a3[i].real() + a4[i].real() + number_a;
        double imagvalue1 = a1[i].imag() + a2[i].imag() + a3[i].imag() + a4[i].imag();
        hdown[i] = complex<double>(realvalue1, imagvalue1);
    }

    complex<long double> *freq_response = divisionComplex(hup, hdown);
    long double *response = getAmplitude(freq_response);
    delete []hup;
    delete []hdown;
    delete []freq_response;

    return response;
}

long double* addComplex_2(complex<long double> *b1, complex<long double> *b2, long double number_b, complex<long double> *a1, complex<long double> *a2,long double number_a)
{
    complex<long double> *hup =new complex<long double>[EQ_ORDER_LEN];
    complex<long double> *hdown=new complex<long double>[EQ_ORDER_LEN];
//    complex<long double> *freq_response = new complex<long double>[EQ_ORDER_LEN];
//    long double *response =new long double[EQ_ORDER_LEN];


    for (int i = 0; i < EQ_ORDER_LEN; i++)
    {
        double realvalue = b1[i].real() + b2[i].real() + number_b;
        double imagvalue = b1[i].imag() + b2[i].imag();
        hup[i] = complex<double>(realvalue, imagvalue);
        double realvalue1 = a1[i].real() + a2[i].real()  + number_a;
        double imagvalue1 = a1[i].imag() + a2[i].imag();
        hdown[i] = complex<double>(realvalue1, imagvalue1);
    }

    complex<long double> *freq_response=divisionComplex(hup, hdown);
    long double *response = getAmplitude(freq_response);
    delete []hup;
    delete []hdown;
    delete []freq_response;
    return response;
}
long double * getFreqw(EQ::coeff coeff, long double w[EQ_ORDER_LEN])
{

    complex<long double> *b4 = new complex<long double>[EQ_ORDER_LEN];
    complex<long double> *b3 = new complex<long double>[EQ_ORDER_LEN];
    complex<long double> *b2 = new complex<long double>[EQ_ORDER_LEN];
    complex<long double> *b1 = new complex<long double>[EQ_ORDER_LEN];
    complex<long double> *a4 = new complex<long double>[EQ_ORDER_LEN];
    complex<long double> *a3 = new complex<long double>[EQ_ORDER_LEN];
    complex<long double> *a2 = new complex<long double>[EQ_ORDER_LEN];
    complex<long double> *a1 = new complex<long double>[EQ_ORDER_LEN];
//    long double *response = new long double[EQ_ORDER_LEN];
    for (int i = 0; i < EQ_ORDER_LEN; i++)
    {
        long double b1_real = coeff.getB1 * cos(w[i]);
        long double b1_image = -sin(w[i]) * coeff.getB1;
        long double b2_real = coeff.getB2 * cos(2 * w[i]);
        long double b2_image = -sin(2 * w[i]) * coeff.getB2;
        long double b3_real = coeff.getB3 * cos(3 * w[i]);
        long double b3_image = -sin(3 * w[i]) * coeff.getB3;
        long double b4_real = coeff.getB4 * cos(4 * w[i]);
        long double b4_image = -sin(4 * w[i]) * coeff.getB4;

        b4[i] = complex<long double>(b4_real, b4_image);
        b3[i] = complex<long double>(b3_real, b3_image);
        b2[i] = complex<long double>(b2_real, b2_image);
        b1[i] = complex<long double>(b1_real, b1_image);
        /////////////////////////////////////////////////////
        long double a1_real = coeff.getA1 * cos(w[i]);
        long double a1_image = -sin(w[i]) * coeff.getA1;
        long double a2_real = coeff.getA2 * cos(2 * w[i]);
        long double a2_image = -sin(2 * w[i]) * coeff.getA2;
        long double a3_real = coeff.getA3 * cos(3 * w[i]);
        long double a3_image = -sin(3 * w[i]) * coeff.getA3;
        long double a4_real = coeff.getA4 * cos(4 * w[i]);
        long double a4_image = -sin(4 * w[i]) * coeff.getA4;
        a4[i] = complex<long double>(a4_real, a4_image);
        a3[i] = complex<long double>(a3_real, a3_image);
        a2[i] = complex<long double>(a2_real, a2_image);
        a1[i] = complex<long double>(a1_real, a1_image);

    }
    long double number_A = coeff.getA0;
    long double number_B = coeff.getB0;

    long double *response=addComplex(b1,b2,b3,b4, number_B,a1,a2,a3,a4,number_A);
    delete []b4;
    delete []b3;
    delete []b2;
    delete []b1;
    delete []a4;
    delete []a3;
    delete []a2;
    delete []a1;
    return response;
}

long double *getFreqwt(EQ::coefft coefft, long double w[EQ_ORDER_LEN])
{
    complex<long double> *b2 = new complex<long double>[EQ_ORDER_LEN];
    complex<long double> *b1 = new complex<long double>[EQ_ORDER_LEN];
    complex<long double> *a2 = new complex<long double>[EQ_ORDER_LEN];
    complex<long double> *a1 = new complex<long double>[EQ_ORDER_LEN];
//    long double *response = new long double[EQ_ORDER_LEN];

    for (int i = 0; i < EQ_ORDER_LEN; i++)
    {
        long double b1_real = coefft.getB1 * cos(w[i]);
        long double b1_image = -sin(w[i]) * coefft.getB1;
        long double b2_real = coefft.getB2 * cos(2 * w[i]);
        long double b2_image = -sin(2 * w[i]) * coefft.getB2;

        b2[i] = complex<long double>(b2_real, b2_image);
        b1[i] = complex<long double>(b1_real, b1_image);
        /////////////////////////////////////////////////////
        long double a1_real = coefft.getA1 * cos(w[i]);
        long double a1_image = -sin(w[i]) * coefft.getA1;
        long double a2_real = coefft.getA2 * cos(2 * w[i]);
        long double a2_image = -sin(2 * w[i]) * coefft.getA2;

        a2[i] = complex<long double>(a2_real, a2_image);
        a1[i] = complex<long double>(a1_real, a1_image);

    }

    long double number_A = coefft.getA0;
    long double number_B = coefft.getB0;

    long double *response=addComplex_2(b1, b2,number_B, a1, a2,number_A);
    delete []a2;
    delete []a1;
    delete []b2;
    delete []b1;
    return response;
}

EQ::Eq_rsp* EQ::EQ_resp(EQ::coeff coeff, int fs)
{
    Eq_rsp *data = new Eq_rsp();
    long double *w = new long double[EQ_ORDER_LEN];
    long double *f = new long double[EQ_ORDER_LEN];
//    long double *response = new long double[EQ_ORDER_LEN];

    for (int i = 0; i < EQ_ORDER_LEN; i++)
    {
        f[i] = i * 0.1;
        w[i] = i * 0.1 *2 *PI /fs;
    }
    long double *response=getFreqw(coeff,w);

    for (int i = 0; i < EQ_ORDER_LEN; i++)
    {
        data->f.push_back(f[i]);
        if (i%10 == 0)
            data->response.push_back(response[i] * -1.0);
    }
    delete []f;
    delete []w;
    delete []response;
    return data;
}

EQ::Eq_rsp* EQ::EQ_resp_2_order(EQ::coefft coefft, int fs)
{
    Eq_rsp *data = new Eq_rsp();

    long double *w = new long double[EQ_ORDER_LEN];
    long double *f = new long double[EQ_ORDER_LEN];
//    long double *response = new long double[EQ_ORDER_LEN];


    for (int i = 0; i < EQ_ORDER_LEN; i++)
    {
        f[i] = i * 0.1;
        w[i] = i * 0.1 * 2 * PI / fs;
    }
    long double *response=getFreqwt(coefft, w);

    for (int i = 0; i < EQ_ORDER_LEN; i++)
    {
        data->f.push_back(f[i]);
        if (i%10 == 0)
            data->response.push_back(response[i] * -1.0);
    }
    delete []w;
    delete []f;
    delete []response;
    return data;
}
