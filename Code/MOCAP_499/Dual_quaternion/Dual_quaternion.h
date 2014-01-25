/* Dual_quaternion.h

This is not a generic dual quaternion class, there will be many simplifications and nomenclature that is 
specific to kinematics usage

See http://en.wikipedia.org/wiki/Dual_quaternion for operator definitions

*/


#include <math.h>
#include <string>
#include "quaternion.h"

using namespace std;

namespace mocap_support {

using namespace std;

	template <typename T> 
	struct dual_number { 
	  T first; 
	  T second; 
	}; 

	template <class T>	
	class Dual_quaternion
	{
	
	private:
		Quaternion<T> q_rotation;
		Quaternion<T> q_translation;
		
	public:

		/*
		Constructor and destructor
		*/
		Dual_quaternion();
		Dual_quaternion(Quaternion<T> q_rotation, Quaternion<T> q_translation);
		Dual_quaternion(vector<T> screw_axis,vector<T> translation,T theta=0);
		~Dual_quaternion();
		
		/*
		Operators
		*/
		Dual_quaternion<T> operator*=(Dual_quaternion & multiplicant);
		Dual_quaternion<T> operator+=(Dual_quaternion & sum);
		Dual_quaternion<T> operator*(Dual_quaternion & multiplicant);
		Dual_quaternion<T> operator+(Dual_quaternion & sum);
		void normalize();
		
		/*
		Accessors
		*/
		
		Dual_quaternion<T> conjugate();
		dual_number<T> norm();

		Quaternion<T> q_rot();
		Qquaternion<T> q_trans();

	}
	
	template <class T>
	Quaternion<T>::Dual_quaternion(){
		q_rotation(1,0,0,0);
		q_translation(1,0,0,0);
	}	
	
	template <class T>
	Quaternion<T>::Dual_quaternion(Quaternion<T> q_rotation, Quaternion<T> q_translation){
		this->q_rotation = q_rotation;
		this->q_translation = q_translation;
	}		

	template <class T>
	Quaternion<T>::Dual_quaternion(vector<T> screw_axis,vector<T> translation,T theta){
		q_rotation(theta,screw_axis);
		//All lateral shifts on the joints should be done in the Z axis
		q_translation(1,translation[0],translation[1],translation[2]);
	}	

	template <class T>
	~Quaternion<T>::Dual_quaternion(){

	}	
	
	template <class T>
	Dual_quaternion<T> operator*=(Dual_quaternion & multiplicant){
	
		q_rotation = q_rotation*multiplicant.q_rot();
		q_translation = q_rotation*multiplicant.q_trans()+q_translation*multiplicant.q_rot();
		return (*this);
	}
	
	template <class T>
	Dual_quaternion<T> operator+=(Dual_quaternion & sum){
		q_rotation = q_rotation + sum.q_rot();
		q_translation = q_translation + sum.q_translation();
		
		return (*this);
	}
	
	template <class T>
	Dual_quaternion<T> operator*(Dual_quaternion & multiplicant){
		return Dual_quaternion<T>(*this) *= multiplicant;
	}
	
	template <class T>
	Dual_quaternion<T> operator+(Dual_quaternion & sum){
		return Dual_quaternion<T>(*this) += sum;
	}
	
	template <class T>	
	void normalize(){
		q_rotation.normalize();
	}
	
	template <class T>	
	Dual_quaternion<T> conjugate(){
		return Dual_quaternion(q_rotation.conjugate(),q_translation.conjugate());
	}
	
	template <class T>	
	Dual_quaternion<T> norm(){
		dual_number dual_norm;
		//this.....is complicated and provides no use to me right now. 
	}
		
	template <class T>
	Quaternion<T> q_rot(){
		return q_rotation;
	}
	
	template <class T>
	Quaternion<T> q_trans(){
		return q_translation;
	}
	
};




