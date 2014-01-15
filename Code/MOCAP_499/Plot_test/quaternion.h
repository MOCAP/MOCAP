// quaternion.h

#pragma once
#include <math.h>

namespace mocap_support {

	template <class T>
	class __declspec( dllexport ) Quaternion {

	private:
		T q0,q1,q2,q3;

	public:
		Quaternion();
		Quaternion(T q0, T q1, T q2,T q3);
		Quaternion(T q1, T q2,T q3);
		~Quaternion();
        
		T get_norm();
		T get_magnitude();
		T get_quaternion_as_vector();
		void normalize();
		Quaternion<T> multiply(Quaternion multiplcant, Quaternion diff);
		Quaternion<T> subtract(Quaternion base, Quaternion diff);
		void scalar_multiply(T scalar);
		void scalar_divide(T scalar);
		T sqrt(T base_value);
        
		
	};

}
