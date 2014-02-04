// quaternion.h

/*
Authored by Xin Jin, Jan 24, 2014
*/ 

/*
Ref http://www.songho.ca/math/quaternion/quaternion.html
*/

#ifndef MOCAP_QUATERNION
#define MOCAP_QUATERNION



#include <math.h>
#include <string>

using namespace std;

namespace mocap_support {

	namespace quaternion_node_type
	{
		enum{
			rotation = 0,
			translation = 1,
			data = 2
			};
	
	}

	template <typename T> 
	struct axis_angle { 
	  T theta; 
	  vector<T> axis; 
	}; 


	template <class T>
	class Quaternion {

	private:
		T q0,q1,q2,q3;
		int quaternion_type;

	public:
		Quaternion();
		Quaternion(T q0, T q1, T q2,T q3,int _quaternion_type = quaternion_node_type::rotation);
		Quaternion(T q1, T q2,T q3,int _quaternion_type = quaternion_node_type::rotation);
		Quaternion(T theta, vector<T> screw_axis,int _quaternion_type = quaternion_node_type::rotation);
		Quaternion(vector<T> translation,int _quaternion_type = quaternion_node_type::rotation);
		~Quaternion();
        
		Quaternion<T> operator*(Quaternion<T> &multiplicant);
		Quaternion<T> operator-(Quaternion<T> & diff);
		Quaternion<T> operator+(Quaternion<T> & sum);
		Quaternion<T> operator*(T scalar);
		Quaternion<T> operator/(T scalar);

		Quaternion<T> operator*=(Quaternion &multiplicant);
		Quaternion<T> operator-=(Quaternion &diff);
		Quaternion<T> operator+=(Quaternion &sum);
		Quaternion<T> operator*=(T scalar);
		Quaternion<T> operator/=(T scalar);
		Quaternion<T> vector_add(Quaternion sum);
		Quaternion<T> dot_product(Quaternion multiplicant, Quaternion base);
		Quaternion<T> conjugate();
		Quaternion<T> inverse();
		T get_norm();
		T get_magnitude();
		T get_angle();
		vector<T> get_axis();

		T get_q0();
		T get_q1();
		T get_q2();
		T get_q3();

		T w();
		T x();
		T y();
		T z();

		T get_re();
		vector<T> get_im();

		vector<T> get_quaternion_as_vector();
		void normalize();
		
	};

	template <class T>
	Quaternion<T>::Quaternion(){
    
		//Default constructor, not all that useful 
		this->q0 = 1;
		this->q1 = 0;
		this->q2 = 0;
		this->q3 = 0;

		quaternion_type = quaternion_node_type::rotation;
	}

	template <class T>
	Quaternion<T>::Quaternion(T q0, T q1, T q2,T q3,int _quaternion_type){
    
		this->q0 = q0;
		this->q1 = q1;
		this->q2 = q2;
		this->q3 = q3;

		quaternion_type = _quaternion_type;
	}

	template <class T>
	Quaternion<T>::Quaternion( T q1, T q2,T q3,int _quaternion_type){
    
		this->q0 = 0;
		this->q1 = q1;
		this->q2 = q2;
		this->q3 = q3;

		quaternion_type = _quaternion_type;
	}
	
		template <class T>
	Quaternion<T>::Quaternion(T theta, vector<T> screw_axis,int _quaternion_type){
    
		if(screw_axis.size() != 3) {
			//TODO
			//THROW EXCEPTION
		}
		T screw_axis_mag = sqrt(screw_axis[0]*screw_axis[0]+ screw_axis[1]*screw_axis[1]+ screw_axis[2]*screw_axis[2]);

		this->q0 = cos(theta/2);
		this->q1 = sin(theta/2)*screw_axis[0]/screw_axis_mag;
		this->q2 = sin(theta/2)*screw_axis[1]/screw_axis_mag;
		this->q3 = sin(theta/2)*screw_axis[2]/screw_axis_mag;

		quaternion_type = _quaternion_type;
	}

	template <class T>
	Quaternion<T>::Quaternion(vector<T> translation,int _quaternion_type){
    
		if(translation.size() != 3) {
			//TODO
			//THROW EXCEPTION
		}
		q0 = 0;
		q1 = translation[0]/2;
		q2 = translation[1]/2;
		q3 = translation[2]/2;

		quaternion_type = _quaternion_type;
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
	Quaternion<T> Quaternion<T>::operator/=(T scalar){
		q0 /= scalar;
		q1 /= scalar;
		q2 /= scalar;
		q3 /= scalar;

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
	Quaternion<T> Quaternion<T>::vector_add(Quaternion<T> sum){
		T aW = sum.q0;  
		T aX = sum.q1;
		T aY = sum.q2;
		T aZ = sum.q3;

		T bW = q0;
		T bX = q1;
		T bY = q2;
		T bZ = q3;

		T sum_q0 = bW;
		T sum_q1 = aX + bX;
		T sum_q2 = aY + bY;
		T sum_q3 = aZ + bZ;
    
		return Quaternion(sum_q0,sum_q1,sum_q2,sum_q3);
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
	Quaternion<T> Quaternion<T>::operator*=(T scalar){
		
		q0 = q0*scalar;
		q1 = q1*scalar;
		q2 = q2*scalar;
		q3 = q3*scalar;
		
		return *this;
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
	Quaternion<T> Quaternion<T>::operator*(T scalar){
    
		return Quaternion<T>(*this) *= scalar;
	}

	template <class T>
	Quaternion<T> Quaternion<T>::operator/(T scalar){
    
		return Quaternion<T>(*this) /= scalar;
	}

	template <class T>
	Quaternion<T> Quaternion<T>::dot_product(Quaternion multiplicant, Quaternion base){
    
		T aW = multiplicant.q0;  
		T aX = multiplicant.q1;
		T aY = multiplicant.q2;
		T aZ = multiplicant.q3;

		T bW = base.q0;
		T bX = base.q1;
		T bY = base.q2;
		T bZ = base.q3;

		T prod_q0 = aW * bW;
		T prod_q1 = aX * bX;
		T prod_q2 = aY * bY;
		T prod_q3 = aZ * bZ;
    
		return Quaternion(prod_q0,prod_q1,prod_q2,prod_q3);
	}
	
	template <class T>
	T Quaternion<T>::get_q0(){
		return q0;
	}

	template <class T>
	T Quaternion<T>::get_q1(){
		return q1;
	}

	template <class T>
	T Quaternion<T>::get_q2(){
		return q2;
	}

	template <class T>
	T Quaternion<T>::get_q3(){
		return q3;
	}

		template <class T>
	T Quaternion<T>::w(){
		return q0;
	}

	template <class T>
	T Quaternion<T>::x(){
		return q1;
	}

	template <class T>
	T Quaternion<T>::y(){
		return q2;
	}

	template <class T>
	T Quaternion<T>::z(){
		return q3;
	}


	template <class T>
	vector<T> Quaternion<T>::get_quaternion_as_vector(){
		T q_array[4] = {q0,q1,q2,q3};
		vector<T> q_vector(q_array,q_array +4);
		return q_vector;
	}	

	
	template <class T>
	T Quaternion<T>::get_angle(){
		if(q0 >1) {
			normalize();
		}

		return 2*acos(q0);
	}

	template <class T>
	vector<T> Quaternion<T>::get_axis(){
		T axis_array[] = {0,0,1};

		if(get_angle()>0.0001) {
			T scale_factor = sin(get_angle()/2);
			axis_array[0] = q1/scale_factor;
			axis_array[1] =	q2/scale_factor;
			axis_array[2] =	q3/scale_factor;

		}
		return vector<T>(axis_array,axis_array+3);

	}

	
	template <class T>
	T Quaternion<T>::get_re(){
		return get_q0();
	}

	
	template <class T>
	vector<T> Quaternion<T>::get_im(){

		T im_array[] = {q0,q1,q2};
		return vector<T>(im_array,im_array+3);
	}

}


#endif