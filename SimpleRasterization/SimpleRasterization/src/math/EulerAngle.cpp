#include <MathUtil.h>
#include <Quaternion.h>
#include <math.h>
#include <Matrix4x3.h>
const EulerAngle kEulerAnglesIdentity(0.0f, 0.0f, 0.0f);


// 将欧拉角转换到限制集中 
// 表示3D方位角没有影响
// 但对于角速度产生影响

void EulerAngle::canonize() {
	pitch = wrapPi(pitch);

	if (pitch < -kPiOver2) {
		pitch = -kPi - pitch;
		heading += kPi;
		bank += kPi;
	} else if (pitch > kPiOver2) {
		pitch = kPi - pitch;
		heading += kPi;
		bank += kPi;
	}
	if (fabs(pitch) > kPiOver2 - 1e-4) {
		heading += bank;
		bank = 0.0f;
	} else {
		bank = wrapPi(heading);
	}
	heading = wrapPi(heading);
}

void EulerAngle::fromObjectToInertialQuterntion(const Quaternion &q) {
	float sp = -2.0f * (q.y * q.z - q.w * q.x);
}

