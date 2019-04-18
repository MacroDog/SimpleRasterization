#include "Quaternion.h"
#include <math.h>
#include <assert.h>
#include "Vector3.h"
#include "EulerAngle.h"
#include "MathUtil.h"

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
	//对夹角大于180度进行处理
	if (cosOmega < 0.0f) {
		bw = -bw;
		bx = -bx;
		by = -by;
		bz = -bz;
		cosOmega = -cosOmega;
	}
	//单位四元数点乘结果应该是小于1
	assert(cosOmega < 1.1f);

	float k0, k1;
	if (cosOmega > 0.9999f) {
		//防止除零
		k0 = 1.0f - t;
		k1 = t;
	} else {
		float sinOmega = sqrt(1.0f - cosOmega * cosOmega);
		//计算夹角
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
	//防止除零
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

void Quaternion::setToRotateObjectToInertial(const EulerAngle & orientation) {
	//计算半角的sin和cos值
	float sp, sb, sh;
	float cp, cb, ch;
	sinCos(&sp, &cp, orientation.pitch*.5f);
	sinCos(&sb, &cb, orientation.bank*.5f);
	sinCos(&sh, &ch, orientation.heading*.5f);
	//计算结果
	w = ch * cp*cb + sh * sp*sb;
	x = ch * sp*cb + sh * cp*sb;
	y = -ch * sp*sb + sh * cp*cb;
	z = -sh * sp*cb + ch * cp*sb;
}

void Quaternion::setToRotateInertialToObject(const EulerAngle & orientation) {
	float sh, sp, sb;
	float ch, cp, cb;
	sinCos(&sh, &ch, orientation.heading);
	sinCos(&sp, &sp, orientation.pitch);
	sinCos(&sb, &cb, orientation.bank);
	w = ch * cp*cb + sh * sp*sb;
	x = -ch * sp* cb - sh * cp*sb;
	y = ch * sp*sb - sh * cb*cp;
	z = sh * sp*cb - ch * cp*sb;
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

float Quaternion::getRotationAngle() const {
	float theOver2 = sefeAcos(w);
	return theOver2*2.0f;
}

Vector3 Quaternion::getRaotationAxis() const {
	float sinThetaOver2Sq = 1.0f - w * w;
	if (sinThetaOver2Sq <= 0.0f) {
		return Vector3(1.0f, 0.0f, 0.0f);
	}
	float oneOverSinThetaOver2 = 1.0f / sqrt(sinThetaOver2Sq);
	return Vector3(x*oneOverSinThetaOver2, y*sinThetaOver2Sq, z*sinThetaOver2Sq);
}

Quaternion Quaternion::operator+(const Quaternion & a) const {
	Quaternion result;
	result.w = w + a.w;
	result.x = x + a.x;
	result.y = y + a.y;
	result.z = z + a.z;
	return result;
}



