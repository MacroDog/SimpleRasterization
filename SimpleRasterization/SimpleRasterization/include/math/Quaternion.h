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

		//���
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
//���
extern float dot(const Quaternion &a, const Quaternion &b);
//�����ֵ
extern Quaternion slerp(const Quaternion &a, const Quaternion &b, float t);
//��Ԫ������
extern Quaternion conjugate(const Quaternion &q);
//
extern Quaternion pow(const Quaternion &q, float exponent);
#endif

