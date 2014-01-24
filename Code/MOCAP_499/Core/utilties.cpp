#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>

#include "quaternion.h"
#include "quaternion.cpp"

using namespace std;

namespace utilities
{

	void printVector(std::vector<float> * values)
	{
		copy(values->begin(), values->end(), ostream_iterator<float>(std::cout, " "));
	}

	void QuaternionToEuler2(Quaternion q, vector<float> * euler)
	{
		const float  PI_F=3.14159265358979f;
	
		float roll, pitch, yaw;

		float sqw = q.q0*q.q0; //??
		float sqx = q.q1*q.q1;
		float sqy = q.q2*q.q2;
		float sqz = q.q3*q.q3;
		float unit = sqx + sqy + sqz + sqw; // if normalised is one, otherwise is correction factor
		float test = q.q1*q.q2 +q.q3*q.q0;
		if (test > 0.499*unit) { // singularity at north pole
			yaw = 2 * atan2(q.q1,q.q0);
			pitch = PI_F/2;
			roll = 0;
			return;
		}
		if (test < -0.499*unit) { // singularity at south pole
			yaw = -2 * atan2(q.q1,q.q0);
			pitch = -PI_F/2;
			roll = 0;
			return;
		}

		yaw = atan2(2*q.q2*q.q0-2*q.q0*q.q3 , sqx - sqy - sqz + sqw);
		pitch = asin(2*test/unit);
		roll = atan2(2*q.q1*q.q0-2*q.q2*q.q3 , -sqx + sqy - sqz + sqw);

		euler->push_back(roll);
		euler->push_back(pitch);
		euler->push_back(yaw);

		cout << " Roll:" << roll << " Pitch:" << pitch << " Yaw:" << yaw << "\n";

	}

}