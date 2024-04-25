#pragma once
#include<stdio.h>
#include<QVector>
#include<cmath>
#include<string>
#include <complex>
#include "algorithmDesign.h"
using namespace std;

#define PI 3.14159
#define EPS 0.000001
#define EQ_ORDER_LEN 200000

class EQ
{
public:
    enum nfilt {
        one = 2,
        two = 3,
        three = 4,
        four = 5
    };
    typedef struct {
        QVector<float> f;
        QVector<float> response;
    } Eq_rsp;

    typedef struct {
        QVector<double> a;
        QVector<double> b;
    } Eq_ata;

    typedef struct {
        long double getB0= 0.988944660156398813732891994732199236751;
        long double getB1 = -3.955778640625595254931567978928796947002;
        long double getB2 = 5.933667960938392660352747043361887335777;
        long double getB3 = -3.955778640625595254931567978928796947002;
        long double getB4 = 0.988944660156398813732891994732199236751;
        long double getA0 = 1;
        long double getA1 = -3.977766302563939149194993660785257816315;
        long double getA2 = 5.93354574299089065902990114409476518631;
        long double getA3 = -3.933790976095695945957686490146443247795;
        long double getA4 = 0.978011540851855154521388158173067495227;
        void init(Eq_ata *ata) {
            getB0= ata->a.at(0);
            getB1 = ata->a.at(1);
            getB2 = ata->a.at(2);
            getB3 = ata->a.at(3);
            getB4 = ata->a.at(4);
            getA0 = ata->b.at(0);
            getA1 = ata->b.at(1);
            getA2 = ata->b.at(2);
            getA3 = ata->b.at(3);
            getA4 = ata->b.at(4);
        }
    } coeff;

    typedef struct {
        long double getB0 = 1.00798628871370;
        long double getB1 = -1.99110687438684;
        long double getB2 = 0.983229765312789;
        long double getA0 = 1;
        long double getA1 = -1.99110687438684;
        long double getA2 = 0.991216054026484;
        void init(Eq_ata *ata) {
            getB0= ata->a.at(0);
            getB1 = ata->a.at(1);
            getB2 = ata->a.at(2);
            getA0 = ata->b.at(0);
            getA1 = ata->b.at(1);
            getA2 = ata->b.at(2);
        }
    } coefft;



	//typedef struct {
	//	double *a;
	//	double *b;
	//} Eq_ata;

	typedef struct {
		vector<double> mole;
		vector<double> denom;
	} series_data;

	void series(double A0[3], double B0[3]);

	//IN_data输入，OUT_data输出，in_len长度，a为分子系数，b分母系数，number滤波器阶数(系数的数组长度)
    QVector<float> filter(QVector<float> IN_data_, Eq_ata* ata, int number);

	//2阶
	//EQ_fc  :EQ参数
	// fs : 频率
	//输出参数：
    Eq_ata* Phase_Changer(int EQ_fc, double EQ_Gain, double EQ_Q);

	//	2阶
	//EQ_fc  :EQ参数
	// fs : 频率
	// EQ_Q : eq参数
	//输出参数：
    Eq_ata* Bandpass(int EQ_fc, double EQ_Q);

	//	2阶
	//EQ_Gain  :EQ参数
	//EQ_Q  :EQ参数
	// fs : 频率
	// EQ_fc : eq参数
	//输出参数：
    Eq_ata* Parametric(int EQ_fc, double EQ_Gain, double EQ_Q);


	//	 4阶
	// EQ_fc : eq参数
	// fs : 频率
    Eq_ata* Highpass_LR(int EQ_fc);


	//	 4阶低通滤波
	// EQ_fc : eq参数
	// fs : 频率
    Eq_ata* Lowpass_LR(int EQ_fc);

	//	2阶
	//EQ_Gain  :EQ参数
	// EQ_fc : eq参数
	//EQ_Q  :EQ参数
	// fs : 频率
    Eq_ata* Base_Shelf(int EQ_FC, double EQ_Gain, double EQ_Q);
    Eq_ata* Treble_Shelf(int EQ_FC, double EQ_Gain, double EQ_Q);




	//高阶滤波合集
    Eq_ata* Highpass_BW(int order, int EQ_fc);

	//低阶滤波合集
    Eq_ata* Lowpass_BW(int order, int EQ_fc);

    Eq_rsp* EQ_resp(coeff coeff,int fs);
    Eq_rsp* EQ_resp_2_order(coefft coeff, int fs);

private:
	vector<double> Mole_data;    //分子
	vector<double>  Denom_data;    //分母
};

