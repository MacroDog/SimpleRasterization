#pragma once

#ifndef __EULERANGLES_H_INCLUDED__
#define __EULERANGLES_H_INCLUDED__
#include <math.h>

class Quaternion;
class Matrix4x3;
class RotationMatrix;

//
// �������ڱ�ʾheading-pitch-bankŷ����ϵͳ
//

class EulerAngle {

public:
	float heading;
	float pitch;
	float bank;
public:
	EulerAngle();
	EulerAngle(float h, float p, float b) :heading(h), pitch(p), bank(b) {};
	//��Ϊ��
	void indentity() { heading = pitch = bank = 0.0f; };
	//�任Ϊ���Ƽ�ŷ����
	void canonize();

	//����Ԫ��ת����ŷ����
	void fromObjectToInertialQuterntion(const Quaternion &q);
	void fromInertialToObjectQuaternion(const Quaternion &q);

	void fromObjectToWorldMatrix(const Matrix4x3 &m);
	void fromWorldToObjectMatrix(const Matrix4x3 &m);
	void fromRotationMatrix(const RotationMatrix &m);

	~EulerAngle();

};
extern const EulerAngle kEulerAnglesIdentity;
#endif
