// Sensor_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Sensor.h"
#include "quaternion.h"

using namespace FYDP;
using namespace std;
using namespace irr::core;

int _tmain(int argc, _TCHAR* argv[])
{
	Sensor sensor(1,2,3,4);
	int i;

	quaternion test_quat = sensor.get_orientation();
	float W = test_quat.W;
	float X = test_quat.X;
	float Y = test_quat.Y;
	float Z = test_quat.Z;


	cout << W << "\n";
	cout << X << "\n";
	cout << Y << "\n";
	cout << Z << "\n";
	cin >> i;
	
	
	return 0;
}

