#pragma once
#include <Quaternion.h>
#ifndef __ROTATIONMATRIX_H_INCLUDED__
#define __ROTATIONMATRIX_H_INCLUDED__
class RotationMatrix {
public:
	float m11, m12, m13;
	float m21, m22, m23;
	float m31, m32, m33;

	//重置为单位矩阵
	void identity();
	//制定发方位构造矩阵
	void setup(const EulerAngle &orientation);
	//四元数构造矩阵
	void fromInertialToObjectQuaternion(const Quaternion &q);
	void fromObjectToInertialQuaternion(const Quaternion &q);
	Vector3  intertialToObject(const Vector3 &v)const;
	Vector3 objectToIntertial(const Vector3 &v)const;
public:
	RotationMatrix();
	~RotationMatrix();

private:

};

RotationMatrix::RotationMatrix() {
}

RotationMatrix::~RotationMatrix() {
}
#endif // !__ROTATIONMATRIX_H_INCLUDED__
