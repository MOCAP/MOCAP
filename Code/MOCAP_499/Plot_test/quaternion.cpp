// This is the main DLL file.

//#include "stdafx.h"

#include "quaternion.h"
namespace mocap_support {

	template <class T>
	Quaternion<T>::Quaternion(){
    
		//Default constructor, not all that useful 
		this.q0 = 0;
		this.q1 = 0;
		this.q2 = 0;
		this.q3 = 1;
	}

	template <class T>
	Quaternion<T>::Quaternion(T q0, T q1, T q2,T q3){
    
		this.q0 = q0;
		this.q1 = q1;
		this.q2 = q2;
		this.q3 = q3;
	}

	template <class T>
	Quaternion<T>::Quaternion( T q1, T q2,T q3){
    
		this.q0 = 0;
		this.q1 = q1;
		this.q2 = q2;
		this.q3 = q3;
	}

	template <class T>
	T Quaternion<T>::get_norm(){
    
		return q0*q0+q1*q1*q1+q2*q2+q3*q3;
    
	}

	template <class T>
	T Quaternion<T>::get_magnitude(){
    
		return sqrt(get_norm());
	}

	template <class T>
	T Quaternion<T>::sqrt(T base_value){
    
		//TODO sqrt function may need to be changed to a fast aproximation
    
		return math.sqrt(base_value);
	}

	template <class T>
	void Quaternion<T>::scalar_multiply(T scalar){
		//Don't want to deal with the complexities of operator overlaoding for now;
		q0 *= scalar;
		q1 *= scalar;
		q2 *= scalar;
		q3 *= scalar;
	}

	template <class T>
	void Quaternion<T>::scalar_divide(T scalar){
		//Don't want to deal with the complexities of operator overlaoding for now;
		q0 /= scalar;
		q1 /= scalar;
		q2 /= scalar;
		q3 /= scalar;
	}

	template <class T>
	Quaternion<T> Quaternion<T>::subtract(Quaternion base, Quaternion diff){
		//Don't want to deal with the complexities of operator overlaoding for now;
		T sub_q0 = base.q0 - diff.q0;
		T sub_q1 = base.q1 - diff.q1;
		T sub_q2 = base.q2 - diff.q2;
		T sub_q3 = base.q3 - diff.q3;
    
		return new Quaternion(sub_q0,sub_q1,sub_q2,sub_q3);
	}


	template <class T>
	Quaternion<T> Quaternion<T>::multiply(Quaternion multiplcant, Quaternion base){
    
		T aW = multiplcant.q0;  
		T aX = multiplcant.q1;
		T aY = multiplcant.q2;
		T aZ = multiplcant.q3;

		T bW = base.q0;
		T bX = base.q1;
		T bY = base.q2;
		T bZ = base.q3;

		/*    based on x=q0, y=q1,z=q2,w=q3
		$q0 = $aW * $bX + $aX * $bW + $aY * $bZ - $aZ * $bY;
		$q1 = $aW * $bY + $aY * $bW + $aZ * $bX - $aX * $bZ;
		$q2 = $aW * $bZ + $aZ * $bW + $aX * $bY - $aY * $bX;
		$q3 = $aW * $bW - $aX * $bX - $aY * $bY - $aZ * $bZ;
		*/
    
		T prod_q0 = aW * bW - aX * bX - aY * bY - aZ * bZ;
		T prod_q1 = aW * bX + aX * bW + aY * bZ - aZ * bY;
		T prod_q2 = aW * bY + aY * bW + aZ * bX - aX * bZ;
		T prod_q3 = aW * bZ + aZ * bW + aX * bY - aY * bX;
    
		return new Quaternion(prod_q0,prod_q1,prod_q2,prod_q3);
	}

}