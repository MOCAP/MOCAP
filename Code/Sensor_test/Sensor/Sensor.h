#pragma once

#include <quaternion.h>

using namespace irr::core; // refer to http://irrlicht.sourceforge.net/docu/ for quaternion class documentation
namespace FYDP 
{
	class Sensor
	{
		private:
			quaternion orientation_quat;
			quaternion earth_vector_quat;
			quaternion gravity_vector_quat;
		public:

			__declspec(dllexport) Sensor(void);
			__declspec(dllexport) Sensor(float q0,float q1, float q2, float q3); 

			__declspec(dllexport) ~Sensor(void);
			//Add in overloads to get specific values of the euler and quad objects
			__declspec(dllexport) quaternion get_orientation();
			__declspec(dllexport) void update_attitude(float ax, float ay, float az
				,float gx, float gy, float gz
				,float mx, float my, float mz
				,float timestep);
	};

}
