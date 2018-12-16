#pragma once
#ifndef  __MATHUTIL_H_INCLUED__


#include<math.h>;

const float kPi = 3.14159265f;
const float k2Pi = kPi * 2;
const float kPiOver2 = kPi / 2.0f;
const float k1OverPi = 1.0f / kPi;
const float k1Over2Pi = 1.0f / k2Pi;

//将角度归一到-pi到pi
extern float wrapPi(float theta);
//“安全” 反三角函数
extern float sefeAcos(float x);

inline void sinCos(float * returnSin, float * returnCos, float theta) {
	*returnSin = sin(theta);
	*returnCos = cos(theta);
}

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
