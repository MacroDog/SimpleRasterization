#include <Vector3.h>
class  Ray {
public:
	Vector3 ori;
	Vector3 dir;
	float length;
public:
	Ray(Vector3 ori, Vector3 dir, float length);
	~Ray();


private:

};

Ray::Ray(Vector3 ori, Vector3 dir, float length) {
	this->ori = ori;
	this->length = length;
	this->dir = dir;
}

Ray::~Ray() {
}