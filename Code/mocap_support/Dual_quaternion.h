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
		Dual_quaternion(Quaternion<T> q_rotation,vector<T> translation);
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
		void normalize_rotation();
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
		q_rotation = Quaternion<T>(1,0,0,0,quaternion_node_type::rotation);
		q_translation = Quaternion<T>(0,0,0,0,quaternion_node_type::translation);

		T screw_array[] = {0,0,0};
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
		this->q_translation = q_translation;
		this->screw_axis = this->q_rotation.get_axis();
		this->translation = (q_translation*q_rotation.conjugate()).get_im();
		this->theta = 0;


	}		

	/*
	Constructor with the rotational and translational quaternions already defined
	*/
	template <class T>
	Dual_quaternion<T>::Dual_quaternion(Quaternion<T> q_rotation,vector<T> translation){
		this->q_rotation = q_rotation;

		this->q_translation = (Quaternion<T>(translation,quaternion_node_type::translation))*q_rotation;
		this->screw_axis = this->q_rotation.get_axis();
		this->translation = translation;
		this->theta = 0;


	}

	/*
	constructor from base info: rotation axis, translation, theta
	*/
	template <class T>
	Dual_quaternion<T>::Dual_quaternion(vector<T> screw_axis,vector<T> translation,T theta){
		q_rotation = Quaternion<T>(theta,screw_axis,quaternion_node_type::rotation);
		this->screw_axis = screw_axis;
		this->translation = translation;
		this->theta = theta;
		//All lateral shifts on the joints should be done in the Z axis
		q_translation = (Quaternion<T>(translation,quaternion_node_type::translation))*q_rotation;
	}	

	/*
	destructor, this will probably need a lot of work
	*/
	template <class T>
	Dual_quaternion<T>::~Dual_quaternion(){

	}	

	template <class T>
	void Dual_quaternion<T>::normalize_rotation(){
		q_rotation.normalize();
	}
	
	/*
	Multiplicant/transform should always be the right hand side 
	*/
	template <class T>
	Dual_quaternion<T> Dual_quaternion<T>::operator*=(Dual_quaternion<T>  & multiplicant){
	
		Quaternion<T> temp1 = q_rotation*multiplicant.q_trans();
		Quaternion<T> temp2 = q_translation*multiplicant.q_rot();
		q_translation = q_rotation*multiplicant.q_trans()+q_translation*multiplicant.q_rot();
		/** ORDER MATTERS, never do the rotation first**/
		q_rotation = q_rotation*multiplicant.q_rot();
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
		q_rotation = Quaternion<T>(screw_axis,theta,quaternion_node_type::rotation);
	}
	
	/*
	Conjugation of a dual quaternion is just the simple conjugation of its parts
	*/
	template <class T>	
	Dual_quaternion<T> Dual_quaternion<T>::conjugate(){
		return Dual_quaternion(q_rotation.conjugate(),q_translation.translation_conjugate());
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