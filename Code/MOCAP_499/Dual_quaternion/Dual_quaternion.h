/* Dual_quaternion.h

This is not a generic dual quaternion class, there will be many simplifications and nomenclature that is 
specific to kinematics usage for modeling a human body

See http://en.wikipedia.org/wiki/Dual_quaternion for operator definitions

*/

#ifndef MOCAP_DUAL_QUATERNION
#define MOCAP_DUAL_QUATERNION


#include <math.h>
#include <string>
#include "quaternion.h"

namespace mocap_support {

	template <typename T> 
	struct Dual_number { 
	  T first; 
	  T second; 
	}; 


	template <class T>	
	class Dual_quaternion
	{
	
	private:
		Quaternion<T> q_rotation;
		Quaternion<T> q_translation;
		vector<T> screw_axis;
		vector<T> translation;
		T theta;

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
		Dual_quaternion<T> operator*=(Dual_quaternion<T> & multiplicant);
		Dual_quaternion<T> operator+=(Dual_quaternion<T> & sum);
		Dual_quaternion<T> operator*(Dual_quaternion<T> & multiplicant);
		Dual_quaternion<T> operator+(Dual_quaternion<T> & sum);
		void normalize();
		Dual_quaternion<T> transform(Dual_quaternion<T> operation);

		/*
		Accessors
		*/
		
		void update_theta(T theta);
		Dual_quaternion<T> conjugate();
		Dual_number<T> norm();

		Quaternion<T> q_rot();
		Quaternion<T> q_trans();

	};
	
	/*
	Default constructor, not much use
	*/
	template <class T>
	Dual_quaternion<T>::Dual_quaternion(){
		q_rotation = Quaternion<T>(0,0,0,1);
		q_translation = Quaternion<T>(0,0,0,0);

		T screw_array[] = {0,0,1};
		T translation_array[] = {0,0,0};

		this->screw_axis = vector<T>(screw_array,screw_array+3);
		this->translation = vector<T>(translation_array,translation_array+3);
		this->theta = 0;
	}	
	
	/*
	Constructor with the rotational and translational quaternions already defined
	*/
	template <class T>
	Dual_quaternion<T>::Dual_quaternion(Quaternion<T> q_rotation, Quaternion<T> q_translation){
		this->q_rotation = q_rotation;
		this->q_translation = q_translation*q_rotation;
		this->screw_axis = this->q_rotation.get_axis();
		this->translation = this->q_translation.get_im();
		this->theta = 0;


	}		

	/*
	constructor from base info: rotation axis, translation, theta
	*/
	template <class T>
	Dual_quaternion<T>::Dual_quaternion(vector<T> screw_axis,vector<T> translation,T theta){
		q_rotation = Quaternion<T>(theta,screw_axis);
		this->screw_axis = screw_axis;
		this->translation = translation;
		this->theta = theta;
		//All lateral shifts on the joints should be done in the Z axis
		q_translation = Quaternion<T>(0,translation[0]/2,translation[1]/2,translation[2]/2);
	}	

	/*
	destructor, this will probably need a lot of work
	*/
	template <class T>
	Dual_quaternion<T>::~Dual_quaternion(){

	}	
	
	/*
	Multiplicant/transform should always be the right hand side 
	*/
	template <class T>
	Dual_quaternion<T> Dual_quaternion<T>::operator*=(Dual_quaternion<T>  & multiplicant){
	
		q_rotation = q_rotation*multiplicant.q_rot();
		q_translation = q_rotation*multiplicant.q_trans()+q_translation*multiplicant.q_rot();
		return (*this);
	}
	
	/*
	Add equals operator overload
	*/
	template <class T>
	Dual_quaternion<T> Dual_quaternion<T>::operator+=(Dual_quaternion<T>  & sum){
		q_rotation = q_rotation + sum.q_rot();
		q_translation = q_translation + sum.q_translation();
		
		return (*this);
	}

	/*
	this is the main function that will be used to combine dual quaternions. 
	This is a redefinition of the multiplier function with modifications made to the translational aspect

	See more details about its usage in the paper I am going to write - Xin
	*/
	template <class T>
	Dual_quaternion<T> Dual_quaternion<T>::transform(Dual_quaternion<T> operation){
	
		Quaternion<T> temp_q_rotation = operation.q_rot()*q_rotation*operation.q_rot().conjugate();

		Quaternion<T> rotated_q_translation = operation.q_trans();
		/*Global frame version
		only use the following line if working in global space ALL the time
		*/
		rotated_q_translation = q_rotation*rotated_q_translation*q_rotation.conjugate();

		rotated_q_translation = operation.q_rot()*rotated_q_translation*operation.q_rot().conjugate();

		Quaternion<T> temp_q_translation  = q_translation.vector_add(rotated_q_translation);

		return Dual_quaternion<T> (temp_q_rotation,temp_q_translation);
	}
	
	/*
		Multiplicant/transform should always be the right hand side 
	*/
	template <class T>
	Dual_quaternion<T> Dual_quaternion<T>::operator*(Dual_quaternion<T>  & multiplicant){
		return Dual_quaternion<T>(*this) *= multiplicant;
	}
	
	/*
			Add operator overload
	*/
	template <class T>
	Dual_quaternion<T> Dual_quaternion<T>::operator+(Dual_quaternion<T>  & sum){
		return Dual_quaternion<T>(*this) += sum;
	}
	
	/*
		Only the rotation matrix should ever be normalized. 
	*/
	template <class T>	
	void Dual_quaternion<T>::normalize(){
		q_rotation.normalize();
	}
	
	/*
		The axis should never change since it should be fixed according to the model
		new rotations based on the angle only
	*/
	template <class T>		
	void update_theta(T theta){
		q_rotation = Quaternion<T>(screw_axis,theta);
	}
	
	/*
	Conjugation of a dual quaternion is just the simple conjugation of its parts
	*/
	template <class T>	
	Dual_quaternion<T> Dual_quaternion<T>::conjugate(){
		return Dual_quaternion(q_rotation.conjugate(),q_translation.conjugate());
	}
	
	/*

	*/
	template <class T>	
	Dual_number<T> Dual_quaternion<T>::norm(){
		Dual_number dual_norm;
		//this.....is complicated and provides no use to me right now. 
		return dual_norm;
	}
		

	/* 

	*/
	template <class T>
	Quaternion<T> Dual_quaternion<T>::q_rot(){
		return q_rotation;
	}
	

	/*

	*/
	template <class T>
	Quaternion<T> Dual_quaternion<T>::q_trans(){
		return q_translation;
	}

	
};




#endif