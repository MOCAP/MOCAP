// Algo_test.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
// Math library required for `sqrt'
#include <math.h>
#include <iostream>



using namespace std;
// Function to compute one filter iteration

//float convert_Accel(float input, int resolution_bits) {
//	int FS_value = 4; // Full scale, measured in gs
//
//	return FS_value*(input/(pow(2.0,resolution_bits)));
//}
//
//float convert_Gyro(float input, int resolution_bits) {
//	int FS_value = 4.36332313; //Full scale, measured in radians 
//	return FS_value*(input/pow(2.0,resolution_bits));
//}
//
//float convert_Mag(float input, int resolution_bits) {
//	int FS_value = 1200; //Full scale, measured in micro Teslas
//	return FS_value*(input/pow(2.0,resolution_bits));
//}

//int _tmain(int argc, _TCHAR* argv[])
//{
//	deltat = 30/1000;
//
//	a_x = convert_Accel(-328,16);
//	a_y = convert_Accel(-16456.0,16);
//	a_z = convert_Accel(-1248,16);
//	w_x = convert_Gyro(-77.0,16);
//	w_y = convert_Gyro(-290.0,16);
//	w_z = convert_Gyro(29.0,16);
//	m_x = convert_Mag(-9217.0,13);
//	m_y = convert_Mag(15360,13);
//	m_z = convert_Mag(28927,13);
//
//	cout << a_x << " "  << a_y << " "  << a_z << " g\n"; 
//	cout << w_x << " "  << w_y << " "  << w_z << " radians/s\n" ;
//	cout << m_x << " "  << m_y << " "  << m_z << " uT\n" ;
//	cin >> a_x;
//	filterUpdate(a_x,a_y,a_z,w_x,w_y,w_z,m_x,m_y,m_z);
//	
//	return 0;
//}
