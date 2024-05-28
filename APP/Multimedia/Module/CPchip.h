#pragma once
/*
* Auther:	 sanfan66
*
* Date        | Change
*--------------------------------------------
* 231117      | <record>: Ver 1.1a
*             | (describe): pchip
*             | !warning!: none
*/
#pragma once
#include <iostream>//cout
using namespace std;//cout

class CPchip
{
public:
	CPchip(const double* X, const double* Y, const int n, const double x);
	~CPchip();
	int FindIndex(const double* X, const int n, const double x);
	double ComputeDiff(const double* h, const double* delta, const int n, const int k);
	double getY() { return y; };
private:
	double y;
	double* h;
	double* delta;
};
