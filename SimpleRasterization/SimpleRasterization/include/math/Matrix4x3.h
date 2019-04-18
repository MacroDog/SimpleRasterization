#pragma once
#ifndef  __MATRIX4X3_H_INCLUDE__
#define __MATRUAX4X3_H_INCLUDE__

class Matrix4x3
{
public: float m11, m12, m13;
		float m21, m22, m23;
		float m31, m32, m33;
		float tx, ty, tz;
		//单位矩阵
		void identity();

		//平移
		void zeroTranslation();
		void setTranslation(const  Vector3 &d);
		void setupTranslation(const Vector3 &d);
		
		//
		void setupLocalToParent(const Vector3 &pos, const EulerAngle &orient);
		void setupLocalToParent(const Vector3 &pos, const RotationMatrix &orient);
		void setupLocalToParent(const Vector3 &pos, const Quaternion &origent);
		
		//旋转 h-p-b
		void setupRotate(int axis, float theta);
		
		//任意轴旋转
		void setupRotate(const Vector3 &axis, float theta);
		
		//构造旋转矩阵，角位移由四元数形式给出
		void fromQuaternion(const Quaternion &q);

		//设置缩放
		void setupScale(const Vector3 &s);

		//沿轴缩放
		void setupScaleAlongAxis(const Vector3 &axis, float k);

		void setupShear(int axis, float s, float t);

		//投影矩阵
		void setupProject(const Vector3 &n);

		//设置反射矩阵
		void setupReflect(int axis, float k = 0.0f);

		//设置平面反射矩阵
		void setupReflect(const Vector3 &n);


public:
	Matrix4x3();
	~Matrix4x3();
};

Vector3 operator*(const Vector3 &p,const Matrix4x3 &m);

Matrix4x3 operator*(const Matrix4x3 &a,const Matrix4x3 &b);

Matrix4x3 &operator*=(const Vector3 &p, const Matrix4x3 &m);

Matrix4x3 &operator*=(const Matrix4x3 &a, const Matrix4x3 &b);

//计算行列式
float dateminant(const Matrix4x3 &m);

//计算矩阵的逆
Matrix4x3 inverse(const Matrix4x3 &m);

//提取矩阵平移
Vector3 getTranslation(const Matrix4x3 &m);

//
Vector3 getPositionFromParentToLocalMatrix(const Matrix4x3 &m);

//
Vector3 getPositionFromLocalToParentMatrix(const Matrix4x3 &m);
#endif // ! __MATRIX4X3_H_INCLUDE__

