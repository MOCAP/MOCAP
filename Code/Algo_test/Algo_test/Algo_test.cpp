// Algo_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Math library required for `sqrt'
#include <math.h>
#include <iostream>
// System constants
#define gyroMeasError 3.14159265358979 * (5.0f / 180.0f) // gyroscope measurement error in rad/s (shown as 5 deg/s)
#define gyroMeasDrift 3.14159265358979 * (0.2f / 180.0f) // gyroscope measurement error in rad/s/s (shown as 0.2f deg/s/s)
#define beta sqrt(3.0f / 4.0f) * gyroMeasError // compute beta
#define zeta sqrt(3.0f / 4.0f) * gyroMeasDrift // compute zeta
// Global system variables
float deltat;
float a_x, a_y, a_z; // accelerometer measurements
float w_x, w_y, w_z; // gyroscope measurements in rad/s
float m_x, m_y, m_z; // magnetometer measurements
float SEq_1 = 1, SEq_2 = 0, SEq_3 = 0, SEq_4 = 0; // estimated orientation quaternion elements with initial conditions
float b_x = 1, b_z = 0; // reference direction of flux in earth frame
float w_bx = 0, w_by = 0, w_bz = 0; // estimate gyroscope biases error


using namespace std;
// Function to compute one filter iteration
void filterUpdate(float w_x, float w_y, float w_z, float a_x, float a_y, float a_z, float m_x, float m_y, float m_z, float deltat)
{
	
	// local system variables
	float norm; // vector norm
	float SEqDot_omega_1, SEqDot_omega_2, SEqDot_omega_3, SEqDot_omega_4; // quaternion rate from gyroscopes elements
	float f_1, f_2, f_3, f_4, f_5, f_6; // objective function elements
	float J_11or24, J_12or23, J_13or22, J_14or21, J_32, J_33, // objective function Jacobian elements
	J_41, J_42, J_43, J_44, J_51, J_52, J_53, J_54, J_61, J_62, J_63, J_64; //
	float SEqHatDot_1, SEqHatDot_2, SEqHatDot_3, SEqHatDot_4; // estimated direction of the gyroscope error
	float w_err_x, w_err_y, w_err_z; // estimated direction of the gyroscope error (angular)
	float h_x, h_y, h_z; // computed flux in the earth frame
	// axulirary variables to avoid reapeated calcualtions
	float halfSEq_1 = 0.5f * SEq_1;
	float halfSEq_2 = 0.5f * SEq_2;
	float halfSEq_3 = 0.5f * SEq_3;
	float halfSEq_4 = 0.5f * SEq_4;
	float twoSEq_1 = 2.0f * SEq_1;
	float twoSEq_2 = 2.0f * SEq_2;
	float twoSEq_3 = 2.0f * SEq_3;
	float twoSEq_4 = 2.0f * SEq_4;
	float twob_x = 2.0f * b_x;
	float twob_z = 2.0f * b_z;
	float twob_xSEq_1 = 2.0f * b_x * SEq_1;
	float twob_xSEq_2 = 2.0f * b_x * SEq_2;
	float twob_xSEq_3 = 2.0f * b_x * SEq_3;
	float twob_xSEq_4 = 2.0f * b_x * SEq_4;
	float twob_zSEq_1 = 2.0f * b_z * SEq_1;
	float twob_zSEq_2 = 2.0f * b_z * SEq_2;
	float twob_zSEq_3 = 2.0f * b_z * SEq_3;
	float twob_zSEq_4 = 2.0f * b_z * SEq_4;
	float SEq_1SEq_2;
	float SEq_1SEq_3 = SEq_1 * SEq_3;
	float SEq_1SEq_4;
	float SEq_2SEq_3;
	float SEq_2SEq_4 = SEq_2 * SEq_4;
	float SEq_3SEq_4;
	float twom_x = 2.0f * m_x;
	float twom_y = 2.0f * m_y;
	float twom_z = 2.0f * m_z;
	// normalise the accelerometer measurement
	norm = sqrt(a_x * a_x + a_y * a_y + a_z * a_z);
	a_x /= norm;
	a_y /= norm;
	a_z /= norm;
	// normalise the magnetometer measurement
	norm = sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
	m_x /= norm;
	m_y /= norm;
	m_z /= norm;

	cout << a_x << " "  << a_y << " "  << a_z << " g\n"; 
	cout << w_x << " "  << w_y << " "  << w_z << " radians/s\n" ;
	cout << m_x << " "  << m_y << " "  << m_z << " uT\n" ;
	// compute the objective function and Jacobian
	f_1 = twoSEq_2 * SEq_4 - twoSEq_1 * SEq_3 - a_x;
	f_2 = twoSEq_1 * SEq_2 + twoSEq_3 * SEq_4 - a_y;
	f_3 = 1.0f - twoSEq_2 * SEq_2 - twoSEq_3 * SEq_3 - a_z;
	f_4 = twob_x * (0.5f - SEq_3 * SEq_3 - SEq_4 * SEq_4) + twob_z * (SEq_2SEq_4 - SEq_1SEq_3) - m_x;
	f_5 = twob_x * (SEq_2 * SEq_3 - SEq_1 * SEq_4) + twob_z * (SEq_1 * SEq_2 + SEq_3 * SEq_4) - m_y;
	f_6 = twob_x * (SEq_1SEq_3 + SEq_2SEq_4) + twob_z * (0.5f - SEq_2 * SEq_2 - SEq_3 * SEq_3) - m_z;
	//cout << f_1 << " "  << f_2 << " "  << f_3 << " " << f_4 << " "  << f_5 << " "  << f_6 << " g\n";

	J_11or24 = twoSEq_3; // J_11 negated in matrix multiplication
	J_12or23 = 2.0f * SEq_4;
	J_13or22 = twoSEq_1; // J_12 negated in matrix multiplication
	J_14or21 = twoSEq_2;
	J_32 = 2.0f * J_14or21; // negated in matrix multiplication
	J_33 = 2.0f * J_11or24; // negated in matrix multiplication
	J_41 = twob_zSEq_3; // negated in matrix multiplication
	J_42 = twob_zSEq_4;
	J_43 = 2.0f * twob_xSEq_3 + twob_zSEq_1; // negated in matrix multiplication
	J_44 = 2.0f * twob_xSEq_4 - twob_zSEq_2; // negated in matrix multiplication
	J_51 = twob_xSEq_4 - twob_zSEq_2; // negated in matrix multiplication
	J_52 = twob_xSEq_3 + twob_zSEq_1;
	J_53 = twob_xSEq_2 + twob_zSEq_4;
	J_54 = twob_xSEq_1 - twob_zSEq_3; // negated in matrix multiplication
	J_61 = twob_xSEq_3;
	J_62 = twob_xSEq_4 - 2.0f * twob_zSEq_2;
	J_63 = twob_xSEq_1 - 2.0f * twob_zSEq_3;
	J_64 = twob_xSEq_2;
	// compute the gradient (matrix multiplication)
	SEqHatDot_1 = J_14or21 * f_2 - J_11or24 * f_1 - J_41 * f_4 - J_51 * f_5 + J_61 * f_6;
	SEqHatDot_2 = J_12or23 * f_1 + J_13or22 * f_2 - J_32 * f_3 + J_42 * f_4 + J_52 * f_5 + J_62 * f_6;
	SEqHatDot_3 = J_12or23 * f_2 - J_33 * f_3 - J_13or22 * f_1 - J_43 * f_4 + J_53 * f_5 + J_63 * f_6;
	SEqHatDot_4 = J_14or21 * f_1 + J_11or24 * f_2 - J_44 * f_4 - J_54 * f_5 + J_64 * f_6;
	// normalise the gradient to estimate direction of the gyroscope error
	norm = sqrt(SEqHatDot_1 * SEqHatDot_1 + SEqHatDot_2 * SEqHatDot_2 + SEqHatDot_3 * SEqHatDot_3 + SEqHatDot_4 * SEqHatDot_4);
	SEqHatDot_1 = SEqHatDot_1 / norm;
	SEqHatDot_2 = SEqHatDot_2 / norm;
	SEqHatDot_3 = SEqHatDot_3 / norm;
	SEqHatDot_4 = SEqHatDot_4 / norm;
	// compute angular estimated direction of the gyroscope error
	w_err_x = twoSEq_1 * SEqHatDot_2 - twoSEq_2 * SEqHatDot_1 - twoSEq_3 * SEqHatDot_4 + twoSEq_4 * SEqHatDot_3;
	w_err_y = twoSEq_1 * SEqHatDot_3 + twoSEq_2 * SEqHatDot_4 - twoSEq_3 * SEqHatDot_1 - twoSEq_4 * SEqHatDot_2;
	w_err_z = twoSEq_1 * SEqHatDot_4 - twoSEq_2 * SEqHatDot_3 + twoSEq_3 * SEqHatDot_2 - twoSEq_4 * SEqHatDot_1;
	// compute and remove the gyroscope baises
	w_bx += w_err_x * deltat * zeta;
	w_by += w_err_y * deltat * zeta;
	w_bz += w_err_z * deltat * zeta;
	w_x -= w_bx;
	w_y -= w_by;
	w_z -= w_bz;
	// compute the quaternion rate measured by gyroscopes
	SEqDot_omega_1 = -halfSEq_2 * w_x - halfSEq_3 * w_y - halfSEq_4 * w_z;
	SEqDot_omega_2 = halfSEq_1 * w_x + halfSEq_3 * w_z - halfSEq_4 * w_y;
	SEqDot_omega_3 = halfSEq_1 * w_y - halfSEq_2 * w_z + halfSEq_4 * w_x;
	SEqDot_omega_4 = halfSEq_1 * w_z + halfSEq_2 * w_y - halfSEq_3 * w_x;

	// compute then integrate the estimated quaternion rate
	//cout << SEq_1 << ":" << SEq_2 << ":" << SEq_3 << ":"<< SEq_4 << "\n";
	SEq_1 += (SEqDot_omega_1 - (beta * SEqHatDot_1)) * deltat;
	SEq_2 += (SEqDot_omega_2 - (beta * SEqHatDot_2)) * deltat;
	SEq_3 += (SEqDot_omega_3 - (beta * SEqHatDot_3)) * deltat;
	SEq_4 += (SEqDot_omega_4 - (beta * SEqHatDot_4)) * deltat;
	//cout << SEq_1 << ":" << SEq_2 << ":" << SEq_3 << ":"<< SEq_4 << "\n";
	// normalise quaternion
	norm = sqrt(SEq_1 * SEq_1 + SEq_2 * SEq_2 + SEq_3 * SEq_3 + SEq_4 * SEq_4);
	SEq_1 /= norm;
	SEq_2 /= norm;
	SEq_3 /= norm;
	SEq_4 /= norm;
	// compute flux in the earth frame
	SEq_1SEq_2 = SEq_1 * SEq_2; // recompute axulirary variables
	SEq_1SEq_3 = SEq_1 * SEq_3;
	SEq_1SEq_4 = SEq_1 * SEq_4;
	SEq_3SEq_4 = SEq_3 * SEq_4;
	SEq_2SEq_3 = SEq_2 * SEq_3;
	SEq_2SEq_4 = SEq_2 * SEq_4;
	h_x = twom_x * (0.5f - SEq_3 * SEq_3 - SEq_4 * SEq_4) + twom_y * (SEq_2SEq_3 - SEq_1SEq_4) + twom_z * (SEq_2SEq_4 + SEq_1SEq_3);
	h_y = twom_x * (SEq_2SEq_3 + SEq_1SEq_4) + twom_y * (0.5f - SEq_2 * SEq_2 - SEq_4 * SEq_4) + twom_z * (SEq_3SEq_4 - SEq_1SEq_2);
	h_z = twom_x * (SEq_2SEq_4 - SEq_1SEq_3) + twom_y * (SEq_3SEq_4 + SEq_1SEq_2) + twom_z * (0.5f - SEq_2 * SEq_2 - SEq_3 * SEq_3);
	// normalise the flux vector to have only components in the x and z
	b_x = sqrt((h_x * h_x) + (h_y * h_y));
	b_z = h_z;
}

float convert_Accel(float input, int resolution_bits) {
	int FS_value = 4; // Full scale, measured in gs

	return FS_value*(input/(pow(2.0,resolution_bits)));
}

float convert_Gyro(float input, int resolution_bits) {
	int FS_value = 4.36332313; //Full scale, measured in radians 
	return FS_value*(input/pow(2.0,resolution_bits));
}

float convert_Mag(float input, int resolution_bits) {
	int FS_value = 1200; //Full scale, measured in micro Teslas
	return FS_value*(input/pow(2.0,resolution_bits));
}

int _tmain(int argc, _TCHAR* argv[])
{
	deltat = 30/1000;

	a_x = convert_Accel(-328,16);
	a_y = convert_Accel(-16456.0,16);
	a_z = convert_Accel(-1248,16);
	w_x = convert_Gyro(-77.0,16);
	w_y = convert_Gyro(-290.0,16);
	w_z = convert_Gyro(29.0,16);
	m_x = convert_Mag(-9217.0,13);
	m_y = convert_Mag(15360,13);
	m_z = convert_Mag(28927,13);

	//cout << a_x << " "  << a_y << " "  << a_z << " g\n"; 
	//cout << w_x << " "  << w_y << " "  << w_z << " radians/s\n" ;
	//cout << m_x << " "  << m_y << " "  << m_z << " uT\n" ;
	
	filterUpdate(w_x,w_y,w_z,a_x,a_y,a_z,m_x,m_y,m_z,0.002);
	cin >> a_x;
	return 0;
}
