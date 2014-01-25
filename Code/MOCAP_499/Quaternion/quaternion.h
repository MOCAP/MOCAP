// quaternion.h

/*
Authored by Xin Jin, Jan 24, 2014
*/ 

#include <math.h>
#include <string>

using namespace std;

namespace mocap_support {

	template <class T>
	class Quaternion {

	private:
		T q0,q1,q2,q3;

	public:
		Quaternion();
		Quaternion(T q0, T q1, T q2,T q3);
		Quaternion(T q1, T q2,T q3);
		Quaternion(T q1, vector<T> screw_axis);
		~Quaternion();
        
		Quaternion<T> operator*(Quaternion &multiplicant);
		Quaternion<T> operator-(Quaternion & diff);
		Quaternion<T> operator+(Quaternion & sum);
		Quaternion<T> operator*(T & scalar);
		Quaternion<T> operator/(T & scalar);

		Quaternion<T> operator*=(Quaternion &multiplicant);
		Quaternion<T> operator-=(Quaternion &diff);
		Quaternion<T> operator+=(Quaternion &sum);
		Quaternion<T> operator*=(T & scalar);
		Quaternion<T> operator/=(T & scalar);
		Quaternion<T> dot_product(Quaternion multiplcant, Quaternion base);
		Quaternion<T> conjugate();
		Quaternion<T> inverse();
		T get_norm();
		T get_magnitude();
		vector<T> get_quaternion_as_vector();
		void normalize();
		
	};

	template <class T>
	Quaternion<T>::Quaternion(){
    
		//Default constructor, not all that useful 
		this->q0 = 0;
		this->q1 = 0;
		this->q2 = 0;
		this->q3 = 1;
	}

	template <class T>
	Quaternion<T>::Quaternion(T q0, T q1, T q2,T q3){
    
		this->q0 = q0;
		this->q1 = q1;
		this->q2 = q2;
		this->q3 = q3;
	}

	template <class T>
	Quaternion<T>::Quaternion( T q1, T q2,T q3){
    
		this->q0 = 0;
		this->q1 = q1;
		this->q2 = q2;
		this->q3 = q3;
	}
	
		template <class T>
	Quaternion<T>::Quaternion(T theta, vector<T> screw_axis){
    
		if(screw_axis.size() != 3) {
			//TODO
			//THROW EXCEPTION
		}
		T screw_axis_mag = sqrt(screw_axis[0]*screw_axis[0]+ screw_axis[1]*screw_axis[1]+ screw_axis[2]*screw_axis[2]);

		this->q0 = cos(theta/2);
		this->q1 = sin(theta/2)*screw_axis[0]/screw_axis_mag;
		this->q2 = sin(theta/2)*screw_axis[1]/screw_axis_mag;
		this->q3 = sin(theta/2)*screw_axis[2]/screw_axis_mag;
	}
	
	template <class T>
	Quaternion<T>::~Quaternion(){
	
	};

	template <class T>
	T Quaternion<T>::get_norm(){
		return q0*q0+q1*q1+q2*q2+q3*q3;
	}

	template <class T>
	T Quaternion<T>::get_magnitude(){
		return sqrt(get_norm());
	}

	template <class T>
	void Quaternion<T>::normalize(){
		T scalar_divisor = get_magnitude();
		q0 /= scalar_divisor;
		q1 /= scalar_divisor;
		q2 /= scalar_divisor;
		q3 /= scalar_divisor;
	}



	template <class T>
	Quaternion<T> Quaternion<T>::operator/=(T &scalar_divisor){
		q0 /= scalar_divisor;
		q1 /= scalar_divisor;
		q2 /= scalar_divisor;
		q3 /= scalar_divisor;

		return *this;
	}

	template <class T>
	Quaternion<T> Quaternion<T>::operator-=(Quaternion &diff){
		q0 -= diff.q0;
		q1 -= diff.q1;
		q2 -= diff.q2;
		q3 -= diff.q3;
    
		return *this;
	}
	
	template <class T>
	Quaternion<T> Quaternion<T>::operator+=(Quaternion &add){
		q0 = q0 + add.q0;
		q1 = q1 + add.q1;
		q2 = q2 + add.q2;
		q3 = q3 + add.q3;
    
		return *this;
	}

	template <class T>
	Quaternion<T> Quaternion<T>::conjugate()
	{
		return Quaternion<T>(q0,-q1,-q2,-q3);
	}

	template <class T>
	Quaternion<T> Quaternion<T>::inverse()
	{
		T norm = get_norm();
		
		return Quaternion<T>(q0/norm,-q1/norm,-q2/norm,-q3/norm);
	}
	
	template <class T>
	Quaternion<T> Quaternion<T>::operator*=(Quaternion & multiplcant){

		T bW = multiplcant.q0;  
		T bX = multiplcant.q1;
		T bY = multiplcant.q2;
		T bZ = multiplcant.q3;

		T aW = q0;
		T aX = q1;
		T aY = q2;
		T aZ = q3;
    
		T prod_q0 = aW * bW - aX * bX - aY * bY - aZ * bZ;
		T prod_q1 = aW * bX + aX * bW + aY * bZ - aZ * bY;
		T prod_q2 = aW * bY + aY * bW + aZ * bX - aX * bZ;
		T prod_q3 = aW * bZ + aZ * bW + aX * bY - aY * bX;

		q0 = prod_q0;
		q1 = prod_q1;
		q2 = prod_q2;
		q3 = prod_q3;
    
		/*
		more optimized version, consider changing it sometime
		from: http://jsperf.com/quaternion-multiplication
		var aX = dest[0],
		aY = dest[1],
		aZ = dest[2],
		aW = dest[3],
		bX = q[0],
		bY = q[1],
		bZ = q[2],
		bW = q[3],
		ww = (aZ + aX) * (bX + bY),
		yy = (aW - aY) * (bW + bZ),
		zz = (aW + aY) * (bW - bZ),
		xx = ww + yy + zz,
		qq = 0.5 * (xx + (aZ - aX) * (bX - bY));

		dest[0] = qq - xx + (aX + aW) * (bX + bW);
		dest[1] = qq - yy + (aW - aX) * (bY + bZ);
		dest[2] = qq - zz + (aZ + aY) * (bW - bX);
		dest[3] = qq - ww + (aZ - aY) * (bY - bZ);

		*/	

		return *this;
	}


	template <class T>
	Quaternion<T> Quaternion<T>::operator*(Quaternion & multiplcant){
    
		return Quaternion<T>(*this) *= multiplcant;
	}

	template <class T>
	Quaternion<T> Quaternion<T>::operator+(Quaternion & sum){
    
		return Quaternion<T>(*this) += sum;
	}

	template <class T>
	Quaternion<T> Quaternion<T>::operator-(Quaternion & diff){
    
		return Quaternion<T>(*this) -= diff;
	}

	template <class T>
	Quaternion<T> Quaternion<T>::operator*(T & scalar_multiplier){
    
		return Quaternion<T>(*this) *= scalar_multiplier;
	}

	template <class T>
	Quaternion<T> Quaternion<T>::operator/(T & scalar_divisor){
    
		return Quaternion<T>(*this) /= scalar_divisor;
	}

	template <class T>
	Quaternion<T> Quaternion<T>::dot_product(Quaternion multiplcant, Quaternion base){
    
		T aW = multiplcant.q0;  
		T aX = multiplcant.q1;
		T aY = multiplcant.q2;
		T aZ = multiplcant.q3;

		T bW = base.q0;
		T bX = base.q1;
		T bY = base.q2;
		T bZ = base.q3;

		T prod_q0 = aW * bW;
		T prod_q1 = aX * bX;
		T prod_q2 = aY * bY;
		T prod_q3 = aZ * bZ;
    
		return new Quaternion(prod_q0,prod_q1,prod_q2,prod_q3);
	}
	
	template <class T>
	vector<T> Quaternion<T>::get_quaternion_as_vector(){
		T q_array[4] = {q0,q1,q2,q3};
		vector<T> q_vector(q_array,q_array +4);
		return q_vector;
	}	

}
