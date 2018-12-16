
#include "EulerAngle.h"
#include "Quaternion.h"
#include "RotationMatrix.h"
#include "MathUtil.h"
#include <math.h>
const EulerAngle kEulerAnglesIdentity(0.0f, 0.0f, 0.0f);


// ��ŷ����ת�������Ƽ��� 
// ��ʾ3D��λ��û��Ӱ��
// �����ڽ��ٶȲ���Ӱ��

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

void EulerAngle::fromObjectToInertialQuterntion(const Quaternion & q) {
	float sp = -2.0f*(q.y*q.z - q.w*q.x);
}

