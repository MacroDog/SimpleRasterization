#pragma once

#ifndef __EULERANGLES_H_INCLUDED__
#define __EULERANGLES_H_INCLUDED__
#include <math.h>

class Quaternion;
class Matrix4x3;
class RotationMatrix;

//
// 该类用于表示heading-pitch-bank欧拉角系统
//

class EulerAngle {

public:
	float heading;
	float pitch;
	float bank;
public:
	EulerAngle();
	EulerAngle(float h, float p, float b) :heading(h), pitch(p), bank(b) {};
	//置为零
	void indentity() { heading = pitch = bank = 0.0f; };
	//变换为限制集欧拉角
	void canonize();

	//从四元数转换到欧拉角
	void fromObjectToInertialQuterntion(const Quaternion &q);
	void fromInertialToObjectQuaternion(const Quaternion &q);

	void fromObjectToWorldMatrix(const Matrix4x3 &m);
	void fromWorldToObjectMatrix(const Matrix4x3 &m);
	void fromRotationMatrix(const RotationMatrix &m);

	~EulerAngle();

};
extern const EulerAngle kEulerAnglesIdentity;
#endif
