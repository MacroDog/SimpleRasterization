#pragma once
class Vector3 {
public:
	double x, y, z;
public:
	Vector3();
	Vector3(double x, double y, double z);//¹¹Ôìº¯Êý
	~Vector3();

	Vector3 operator + (const Vector3 &a)const;
	Vector3 operator - (const Vector3 &a)const;
	Vector3 operator * (float a)const;
	Vector3 operator /(float a)const;

	Vector3 &operator /=(const Vector3 &a);
	Vector3 &operator +=(const Vector3 &a);
	Vector3 &operator -=(const Vector3 &a);
	Vector3 &operator *=(const Vector3 &a);

	bool operator == (const Vector3 &a) const;
	Vector3 &operator =(const Vector3 &a);
	void zero();
	Vector3 operator-()const;

	void normalize();

	float operator *(const Vector3 &a) const;
};
extern const Vector3 Zero;

inline float norm(const Vector3 &a);
inline Vector3 cross(const Vector3 &a, const Vector3 &b);
inline Vector3 operator *(double k, const Vector3 &a);
inline float distance(const Vector3 &a, const Vector3 &b);

