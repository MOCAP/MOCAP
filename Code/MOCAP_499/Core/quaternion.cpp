// This is the main DLL file.

//#include "stdafx.h"
#include <math.h>

#include "quaternion.h"


Quaternion::Quaternion(){}

Quaternion::Quaternion(float i_q0, float i_q1, float i_q2, float i_q3){
	q0 = i_q0;
	q1 = i_q1;
	q2 = i_q2;
	q3 = i_q3;
}

Quaternion::Quaternion(float i_q1, float i_q2, float i_q3){
	q0 = 0;
	q1 = i_q1;
	q2 = i_q2;
	q3 = i_q3;
}

float Quaternion::get_norm(){
	return q0*q0+q1*q1*q1+q2*q2+q3*q3;
}

float  Quaternion::get_magnitude(){
	return sqrt(get_norm());
}

float Quaternion::sqrt( float base_value ){
	return math.sqrt(base_value); ///????
}

float Quaternion::scalar_multiply( float scalar ){
	q0 *= scalar;
	q1 *= scalar;
	q2 *= scalar;
	q3 *= scalar;
}

float Quaternion::scalar_divide( float scalar ){
	q0 /= scalar;
	q1 /= scalar;
	q2 /= scalar;
	q3 /= scalar;
}

Quaternion Quaternion::subtract(Quaternion base, Quaternion diff){
	return new Quaternion (
		 base.q0 - diff.q0,
		 base.q1 - diff.q1,
		 base.q2 - diff.q2,
	     base.q3 - diff.q3);
}

Quaternion Quaternion::multiply(Quaternion multiplcant, Quaternion base){
	float aW =  multiplcant.q0;  
	float aX = multiplcant.q1;
	float aY = multiplcant.q2;
	float aZ = multiplcant.q3;

	float bW = base.q0;
	float bX = base.q1;
	float bY = base.q2;
	float bZ = base.q3;

	return new Quaternion (
		aW * bW - aX * bX - aY * bY - aZ * bZ,
		aW * bX + aX * bW + aY * bZ - aZ * bY,
		aW * bY + aY * bW + aZ * bX - aX * bZ,
		aW * bZ + aZ * bW + aX * bY - aY * bX
		)
}

