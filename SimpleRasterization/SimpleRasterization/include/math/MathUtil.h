#pragma once
#include<math.h>
#ifndef  __MATHUTIL_H_INCLUED__
const float kPi = 3.14159265f;
const float k2Pi = kPi * 2;
const float kPiOver2 = kPi / 2.0f;
const float k1OverPi = 1.0f / kPi;
const float k1Over2Pi = 1.0f / k2Pi;

//将角度归一到-pi到pi
float wrapPi(float theta);
//“安全” 反三角函数
float sefeAcos(float x);

void sinCos(float * returnSin, float * returnCos, float theta);

#endif  // __MATHUTIL_H_INCLUED__
class MathUtil {
public:
	MathUtil();
	~MathUtil();
};

class MathUtil {
public:
	MathUtil();
	~MathUtil();
};
