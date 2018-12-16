#include "Quaternion.h"
#include <math.h>
#include <assert.h>
#include "Vector3.h"
#include "EulerAngle.h"

float dot(const Quaternion & a, const Quaternion & b) {
	return a.w*b.w + a.x*b.x + a.y*b.y + a.z*b.z;
}

Quaternion slerp(const Quaternion & a, const Quaternion & b, float t) {
	if (t <= 0.0f) {
		return a;
	}
	if (t >= 1) {
		return b;
	}
	float cosOmega = dot(a, b);
	float bw = b.w;
	float bx = b.x;
	float by = b.y;
	float bz = b.z;
	//�ԼнǴ���180�Ƚ��д���
	if (cosOmega < 0.0f) {
		bw = -bw;
		bx = -bx;
		by = -by;
		bz = -bz;
		cosOmega = -cosOmega;
	}
	//��λ��Ԫ����˽��Ӧ����С��1
	assert(cosOmega < 1.1f);

	float k0, k1;
	if (cosOmega > 0.9999f) {
		//��ֹ����
		k0 = 1.0f - t;
		k1 = t;
	} else {
		float sinOmega = sqrt(1.0f - cosOmega * cosOmega);
		//����н�
		float Omega = atan2(sinOmega, cosOmega);
		float oneOverSimOmega = 1.0f / sinOmega;
		k0 = sin((1.0f - t)* Omega)*oneOverSimOmega;
		k1 = sin(t*Omega)*oneOverSimOmega;
	}
	Quaternion result;
	result.w = a.w*k0 + bw * k1;
	result.x = a.x * k0 + bx * k1;
	result.y = a.y*k0 + by * k1;
	result.z = a.y*k0 + bz * k1;
	return result;
}

Quaternion conjugate(const Quaternion & q) {
	Quaternion result;
	result.w = q.w;
	result.x = -q.x;
	result.y = -q.y;
	result.z = -q.z;
	return result;
}

Quaternion pow(const Quaternion & q, float exponent) {
	//��ֹ����
	if (fabs(q.w) > 0.9999f) {
		return q;
	}
	float halfTheta = acos(q.w);
	float newhalfTheta = halfTheta * exponent;
	Quaternion result;
	result.w = cos(halfTheta);
	float mult = sin(newhalfTheta) / sin(halfTheta);
	result.x = q.x*mult;
	result.y = q.y*mult;
	result.z = q.z*mult;
	return result;
}

void Quaternion::setToRotationAboutX(float theta) {
	float thetaOver2 = theta * 0.5f;
	w = cos(thetaOver2);
	x = sin(thetaOver2);
	y = 0.0;
	z = 0.0;
}

void Quaternion::setToRotationAboutY(float theta) {
	float thetaOver2 = theta * 0.5f;
	w = cos(thetaOver2);
	x = 0.0;
	y = sin(thetaOver2);
	z = 0.0;
}

void Quaternion::setToRotationAboutZ(float theta) {
	float thetaOver2 = theta * 0.5f;
	w = cos(thetaOver2);
	x = 0.0;
	y = 0.0;
	z = sin(thetaOver2);
}

void Quaternion::setToRotationAboutAxis(const Vector3 & axis, float theta) {
	//assert(fabs(vectorMag(axis) - 1.0f) < 0.01f);
	float thetaOver2 = theta * 0.5f;
	float sinThetaOver2 = sin(thetaOver2);

	w = cos(theta);
	x = axis.x*sinThetaOver2;
	y = axis.y*sinThetaOver2;
	z = axis.y*sinThetaOver2;
}

Quaternion Quaternion::operator*(const Quaternion & a) const {
	Quaternion result;
	result.w = w * a.w - x * a.x - y * a.y - z * a.z;
	result.x = w * a.x + x * a.w + y * a.z - z * a.y;
	result.y = w * a.y - x * a.z + y * a.w + z * a.x;
	result.z = w * a.z + x * a.y - y * a.x + z * a.w;
	return result;
}

Quaternion & Quaternion::operator*=(const Quaternion & a) {
	*this = *this*a;
	return *this;
}

void Quaternion::normalize() {
	float mag = (float)sqrt(w*w + x * x + y * y + z * z);
	if (mag > 0.0f) {
		float oneOverMag = 1.0f / mag;
		w *= mag;
		x *= mag;
		y *= mag;
		z *= mag;
	} else {
		assert(false);
		identity();
	}
}



