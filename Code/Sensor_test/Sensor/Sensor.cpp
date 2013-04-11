// Sensor.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Sensor.h"

#include <iostream>
#include <math.h>
#include <Eigen/Dense>

using namespace std;
using namespace FYDP;

using Eigen::MatrixXd; // see http://eigen.tuxfamily.org/dox/GettingStarted.html for documentation

Sensor::Sensor()
	{
		orientation_quat = quaternion(0,0,0,0);
		gravity_vector_quat = quaternion(0,0,0,1);
		earth_vector_quat = quaternion(0,1,0,1);
	}


Sensor::Sensor(float q0,float q1, float q2, float q3)
{
		orientation_quat = quaternion(q0,q1,q2,q3);
		gravity_vector_quat = quaternion(0,0,0,1);
		earth_vector_quat = quaternion(0,1,0,1);

}

Sensor::~Sensor(void)
{
}

quaternion Sensor::get_orientation() 
{
	return orientation_quat;
}

void Sensor::update_attitude(float ax, float ay, float az, 
	float gx, float gy, float gz,
	float mx, float my, float mz,
	float timestep)
{
	//Sensor readings - raw or filtered
	quaternion s_g(0,gx,gy,gz);
	quaternion s_a(0,ax,ay,az);
	quaternion s_m(0,mx,my,mz);

	//TODO May need a step here to normalize the input quaternions

	//TODO - Create a function to update the earth vector  based on last orientation 
	//Temporarily, we will find out the local magnetic field/calibrate it manually and put it in the constructor
	//But eventually we will need dynamic periodic calibration of the earth field vector
	//update_earth_vector();

	//Measurement Vectors 
	quaternion s_g_complement = s_g;
	quaternion s_a_complement = s_a;
	quaternion s_m_complement = s_m;

	//NOTE from here on out, we will be switching between raw matrices and quaternions so be very careful
	//The author fo the paper shortened the quaternions to a 3 row vector early but I want to make use of our the libaries
	//Quat multiplicaiton rather than redefining it. 


	//TODO
	//Calculate Objective function of accel - Eq 25
	//Calculate Objective funciton of mag - Eq 29
	//Calculate jacobian of fct of accel eq 26 
	//Calculate jacobian of fct of amg - eq 30 

	//TODO
	//Do not understand how the following two equations combine
	//Combine objective functions - eq 31 
	//Combine jacobians  - eq 32

	//TODO 
	//Calculate deriveative using gyro, eq 35, also refer to eq12 
	//Calculate step value - eq 35 

	//TODO
	//Somebody research and understand that sentence after eq 36
	//Define Beta according to specific device spec 
	//In the future, we may be playing aorund with Beta alot, 
	//	for ex if you are mving really fast, the accel is less reliable than the gyro
	//Define Gamma according to step size beta, and timestep, see eq 38

	//TODO 
	//Calculate estimated derivative - eq 43
	//Calculate unit gradient - eq 44

	//TODO 
	//Evaluate eq 42

	//End of update 
}