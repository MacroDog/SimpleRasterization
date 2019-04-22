#pragma once
#ifndef  __MATRIX4X3_H_INCLUDE__
#define __MATRUAX4X3_H_INCLUDE__

class Matrix4x3
{
public: float m11, m12, m13;
		float m21, m22, m23;
		float m31, m32, m33;
		float tx, ty, tz;
		//��λ����
		void identity();

		//ƽ��
		void zeroTranslation();
		void setTranslation(const  Vector3 &d);
		void setupTranslation(const Vector3 &d);
		
		//
		void setupLocalToParent(const Vector3 &pos, const EulerAngle &orient);
		void setupLocalToParent(const Vector3 &pos, const RotationMatrix &orient);
		void setupLocalToParent(const Vector3 &pos, const Quaternion &origent);
		
		//��ת h-p-b
		void setupRotate(int axis, float theta);
		
		//��������ת
		void setupRotate(const Vector3 &axis, float theta);
		
		//������ת���󣬽�λ������Ԫ����ʽ����
		void fromQuaternion(const Quaternion &q);

		//��������
		void setupScale(const Vector3 &s);

		//��������
		void setupScaleAlongAxis(const Vector3 &axis, float k);

		void setupShear(int axis, float s, float t);

		//ͶӰ����
		void setupProject(const Vector3 &n);

		//���÷������
		void setupReflect(int axis, float k = 0.0f);

		//����ƽ�淴�����
		void setupReflect(const Vector3 &n);


public:
	Matrix4x3();
	~Matrix4x3();
};

Vector3 operator*(const Vector3 &p,const Matrix4x3 &m);

Matrix4x3 operator*(const Matrix4x3 &a,const Matrix4x3 &b);

Matrix4x3 &operator*=(const Vector3 &p, const Matrix4x3 &m);

Matrix4x3 &operator*=(const Matrix4x3 &a, const Matrix4x3 &b);

//��������ʽ
float dateminant(const Matrix4x3 &m);

//����������
Matrix4x3 inverse(const Matrix4x3 &m);

//��ȡ����ƽ��
Vector3 getTranslation(const Matrix4x3 &m);

//
Vector3 getPositionFromParentToLocalMatrix(const Matrix4x3 &m);

//
Vector3 getPositionFromLocalToParentMatrix(const Matrix4x3 &m);
#endif // ! __MATRIX4X3_H_INCLUDE__

