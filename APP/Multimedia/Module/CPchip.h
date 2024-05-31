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
    CPchip(const float* X, const float* Y, const int n, const float x);
	~CPchip();
    int FindIndex(const float* X, const int n, const float x);
    float ComputeDiff(const float* h, const float* delta, const int n, const int k);
    float getY() { return y; };
private:
    float y;
    float* h;
    float* delta;
};
