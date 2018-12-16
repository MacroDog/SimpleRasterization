#pragma once
#ifndef __ROTATIONMATRIX_H_INCLUDED__
#define __ROTATIONMATRIX_H_INCLUDED__
class RotationMatrix {
public:
	float m11, m12, m13;
	float m21, m22, m23;
	float m31, m32, m33;
	
	//����Ϊ��λ����
	void identity();
	//�ƶ�����λ�������
	void setup(const EulerAngle &origintation);
	//��Ԫ���������
	void fromInertialToObjectQuaternion(const Quaternion &q);
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
