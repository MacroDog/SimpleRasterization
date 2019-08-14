#include <Vector3.h>
#include <IRayIntersect.cpp>
class Sphere: public IRayIntersect {
private:
	Vector3 ori;
	float radius;
public:
	Sphere(Vector3 ori, float r);
	~Sphere();
	int RayIntersect(Ray ray) {
		Vector3 oo = ori - ray.ori;
		float pr = oo * ray.dir;
		Vector3 point = Vector3(0.0, 0.0, 0.0);
		if (pr >ray.length) {
			point = ray.dir * ray.length + ray.ori;
		} else {
			point = ray.dir * pr + ray.ori;
		}
		if (distance(point, this.ori) <= this.radius) {
			return 1;
		} else {
			return 0;
		}	   
		return 0;
	}

private:

};

Sphere::Sphere(Vector3 ori, float r) {
	this->ori = ori;
	this->radius = r;
}

Sphere::~Sphere() {
}