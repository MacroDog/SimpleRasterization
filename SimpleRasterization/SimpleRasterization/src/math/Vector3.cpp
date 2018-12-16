#include "Vector3.h"
#include <math.h>

Vector3::Vector3() {
}

Vector3::Vector3(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::~Vector3() {
}


Vector3  Vector3::operator+(const Vector3 & a)const {

	return Vector3(x + a.x, y + a.y, z + a.z);
}

Vector3 Vector3::operator-(const Vector3 & a)const {
	return Vector3(x - a.x, y - a.y, x - a.z);
}
Vector3  Vector3::operator*(float a) const {
	return Vector3(x * a, y*a, z*a);
}

Vector3 & Vector3::operator+=(const Vector3 & a) {
	x += a.x;
	y += a.y;
	z += a.z;
	return *this;
}

Vector3 & Vector3::operator-=(const Vector3 & a) {
	this->x -= x;
	this->y -= y;
	this->z -= z;
	return *this;
}

Vector3 & Vector3::operator*=(const Vector3 & a) {
	this->x *= a.x;
	this->y *= a.y;
	this->z *= a.z;
	return *this;
}

Vector3 & Vector3::operator/=(const Vector3 & a) {
	this->x /= a.x;
	this->y /= a.y;
	this->z /= a.z;
	return *this;
}

Vector3 Vector3::operator/(float a)const {
	float oneOverA = 1.0f / a;
	return Vector3(x*oneOverA, y*oneOverA, z*oneOverA);
}

bool Vector3::operator==(const Vector3 & a) const {
	return x == a.x&&y == a.y&&z == a.z;
}

Vector3 & Vector3::operator=(const Vector3 & a) {
	x = a.x;
	y = a.y;
	z = a.z;
	return *this;
}

void Vector3::zero() {
	x = y = z = 0;
}

Vector3 Vector3::operator-() const {
	return Vector3(-x, -y, -z);
}

void Vector3::normalize() {
	float magSq = x * x + y * y + z * z;
	if (magSq > 0) {
		float oneOverMag = 1.0f / sqrt(magSq);
		x *= oneOverMag;
		y *= oneOverMag;
		z *= oneOverMag;
	}
}

float Vector3::operator*(const Vector3 & a) const {
	return x * a.x + y * a.y + z * a.z;
}

inline float norm(const Vector3 & a) {
	return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}

inline Vector3 cross(const Vector3 & a, const Vector3 & b) {
	return Vector3(
		a.y*b.z - a.z*b.y,
		a.z*b.x - a.x*b.z,
		a.x*b.y - a.y*b.x
	);
}

inline Vector3 operator*(double		 k, const Vector3 & a) {
	return Vector3(k*a.x, k*a.y, k*a.z);
}

inline float distance(const Vector3 & a, const Vector3 & b) {
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float dz = a.z - b.z;
	return sqrt(dx*dx + dy * dy + dz * dz);
}
