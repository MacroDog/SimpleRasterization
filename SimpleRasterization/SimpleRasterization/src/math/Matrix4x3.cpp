#include "Matrix4x3.h"
#include "Vector3.h"
#include "EulerAngle.h"
#include "RotationMatrix.h"
#include "Quaternion.h"
Matrix4x3::Matrix4x3() {
}


Matrix4x3::~Matrix4x3() {
}

void Matrix4x3::identity() {
	m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
	m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
	m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
	tx = 0.0f; ty = 0.0f; tz = 1.0f;
}

void Matrix4x3::zeroTranslation() {
	tx = 0.0f; ty = 0.0f; tz = 0.0f;
}

void Matrix4x3::setTranslation(const Vector3 & d) {
	tx = d.x; ty = d.y; tz = d.z;
}

void Matrix4x3::setupTranslation(const Vector3 & d) {
	m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
	m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
	m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
	tx = d.x; ty = d.y; tz = d.z;
}

void Matrix4x3::setupLocalToParent(const Vector3 & pos, const EulerAngle & orient) {
	RotationMatrix orientMatrix;
	orientMatrix.setup(orient);
	setupLocalToParent(pos, orientMatrix);
}

void Matrix4x3::setupLocalToParent(const Vector3 & pos, const RotationMatrix & orient) {
	m11 = orient.m11; m12 = orient.m12; m13 = orient.m13;
	m21 = orient.m21; m22 = orient.m22; m23 = orient.m23;
	m31 = orient.m31; m32 = orient.m32; m33 = orient.m33;
	tx = pos.x; ty = pos.y; tz = pos.z;
}

void Matrix4x3::setupLocalToParent(const Vector3 & pos, const Quaternion & origent){
	RotationMatrix orientMatrix;
	orientMatrix.fromObjectToInertialQuaternion(origent);
	setupLocalToParent(pos, orientMatrix);
}

void Matrix4x3::setupRotate(int axis, float theta)
{
	float s, c;
	sinCos(&s, &c, theta);
	switch (axis)
	{
	case 1:
		m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
		m21 = 0.0f; m22 = c; m23 = s;
		m31 = 0.0f; m32 = -s; m33 = c;
		break;
	case 2:
		m11 =c; m12 = 0.0f; m13 =-s;
		m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
		m31 = s, m32 = 0.0f; m33 =c;
		break;
	case 3:
		m11 = c; m12 =s; m13 = 0.0f;
		m21 = -s; m22 = c; m23 = 0.0f;
		m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
	default:
		break;
	}
	tx =0; ty = 0; tz = 0;
}
Vector3 Matrix4x3::getTranslation(const Matrix4x3 &m){
	return  Vector3(m.tx,m.ty,m.tz);
}
