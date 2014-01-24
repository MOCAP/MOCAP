
#include <math.h>


class Quaternion {

	private:
		

	public:
		float q0,q1,q2,q3; //should move to private..

		Quaternion();
		Quaternion(float q0, float q1, float q2, float q3);
		Quaternion(float q1, float q2,float q3);
		~Quaternion();
        
		float get_norm();
		float get_magnitude();
		float get_quaternion_as_vector();
		void normalize();
		Quaternion multiply(Quaternion multiplcant, Quaternion diff);
		Quaternion subtract(Quaternion base, Quaternion diff);
		void scalar_multiply(float scalar);
		void scalar_divide(float scalar);
		float sqrt(float base_value);
        
		
	};

}