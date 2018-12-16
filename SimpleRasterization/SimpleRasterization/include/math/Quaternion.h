#pragma once
#ifndef __QUATERNION_H_INCLUDED__
#define __QUATERNION_H_INCLUDED__
#include <assert.h>
#include "Vector3.h"
#include "EulerAngle.h"

class Quaternion {
public: float w, x, y, z;
		void identity() { w = 1.0f; x = y = z = 0.0f; };
		void setToRotationAboutX(float theta);
		void setToRotationAboutY(float theta);
		void setToRotationAboutZ(float theta);
		void setToRotationAboutAxis(const Vector3 &axis, float theta);
		void setToRotateObjectToInertial(const EulerAngle &orientation);
		void setToRotateInertialToObject(const EulerAngle &orientation);

		//叉乘
		Quaternion operator * (const Quaternion &a)const;
		Quaternion & operator*=(const Quaternion &a);
		void normalize();
		float getRotationAngle()const;
		Vector3 getRaotationAxis()const;
		Quaternion operator +(const Quaternion &a)const;
public:
	Quaternion();
	~Quaternion();
};

extern const Quaternion kQuaternionIdentity;
//点乘
extern float dot(const Quaternion &a, const Quaternion &b);
//球面插值
extern Quaternion slerp(const Quaternion &a, const Quaternion &b, float t);
//四元数共轭
extern Quaternion conjugate(const Quaternion &q);
//
extern Quaternion pow(const Quaternion &q, float ecponent);
#endif

