using namespace std;
#include <Eigen>

namespace mocap_support {

	/*
	Simple node types denote the usage of an intermediate Joint_node that has fixed parameters 
	*/
	enum Joint_node_type{prismatic, revolute, simple};

	template <class T>
	class Joint_node
	{
	private:
		Quaternion<T> accelerometer_sensor_data;
		Quaternion<T> gyro_sensor_data;
		Quaternion<T> magnetic_sensor_data;
		T delta_t_ms;

		//STATIC, set by the constructor only
		Quaternion<T> q_orientation;
		Quaternion<T> q_translation;

		Quaternion<T> sensor_fusion_orientation;	//Orientation that comes out of the sensor algorithm 	
		Dual_quaternion<T> transformation_global; 
		Dual_quaternion<T> transformation_delta;
		
		Joint_node * parent;
		
		list<Joint_node*> children;
		
		Joint_node_type node_type;
	public:
		Joint_node();
		Joint_node(Quaternion<T> orientation,Quaternion<T> translation,Joint_node * _parent,Joint_node_type _node_type = revolute);
		Joint_node(vector<T> screw_axis,vector<T> translation,Joint_node * _parent,T theta=0,Joint_node_type _node_type = revolute);
		
		
		Quaternion<T> getAccelerometer_sensor_data();
		void setAccelerometer_sensor_data(Quaternion<T> _accelerometer_sensor_data);
		Quaternion<T> getGyro_sensor_data();
		void setGyro_sensor_data(Quaternion<T> _Gyro_sensor_data);
		Quaternion<T> getMagnetic_sensor_data();
		void setMagnetic_sensor_data(Quaternion<T> _magnetic_sensor_data);
		
		Quaternion<T> getOrientation();
		void calcOrientation();
		
		Quaternion<T> getTranslation();
		void calcTranslation();
		
		Dual_quaternion<T> getTransformation_global();
		Dual_quaternion<T> getTransformation_delta();
		void setTransformation_delta(Dual_quaternion<T> _transformation_delta);
		void Update_transformation_delta();
		void Update_transformation_global();
		void filterUpdate();
		
		Joint_node * getParent();
		void setParent(Joint_node * _parent);
		
		list<Joint_node*> getChildren();
		bool addChild(Joint_node * child);
	};
	
	template <class T>
	Joint_node<T>::Joint_node()
	{
		//Base constructor for usage by the root node only
		setParent(this);
		q_orientation = Quaternion<T>();
		q_translation = Quaternion<T>(0,0,0,0);
		
		transformation_global = Dual_quaternion<T>(q_orientation,q_translation);
		transformation_delta = Dual_quaternion<T>();
		sensor_fusion_orientation = Quaternion<T>();
		
		node_type = simple;
		
		delta_t_ms = 0;
		accelerometer_sensor_data = Quaternion<T>(0,0,0,0);
		gyro_sensor_data = Quaternion<T>(0,0,0,0);
		magnetic_sensor_data = Quaternion<T>(0,0,0,0);
	}
	
	template <class T>
	Joint_node<T>::Joint_node(Quaternion<T> _orientation,Quaternion<T> _translation,Joint_node * _parent,Joint_node_type _node_type)
	{
		setParent(_parent);
		q_orientation = _orientation;
		q_translation = _translation;
		
		transformation_global = Dual_quaternion<T>(q_orientation,q_translation);
		transformation_delta = Dual_quaternion<T>();
		sensor_fusion_orientation = Quaternion<T>();
		
		node_type = _node_type;
		
		delta_t_ms = 0;
		accelerometer_sensor_data = Quaternion<T>(0,0,0,0);
		gyro_sensor_data = Quaternion<T>(0,0,0,0);
		magnetic_sensor_data = Quaternion<T>(0,0,0,0);	
	}
	
	template <class T>
	Joint_node<T>::Joint_node(vector<T> _screw_axis,vector<T> _translation,Joint_node * _parent,T _theta,Joint_node_type _node_type)
	{
		setParent(_parent);
		q_orientation = Quaternion<T>(_theta,_screw_axis);
		q_translation = Quaternion<T>(0,_translation[0]/2,_translation[1]/2,_translation[2]/2);
		
		transformation_global = Dual_quaternion<T>(q_orientation,q_translation);
		transformation_delta = Dual_quaternion<T>();
		sensor_fusion_orientation = Quaternion<T>();
		
		node_type = _node_type;
		
		delta_t_ms = 0;
		accelerometer_sensor_data = Quaternion<T>(0,0,0,0);
		gyro_sensor_data = Quaternion<T>(0,0,0,0);
		magnetic_sensor_data = Quaternion<T>(0,0,0,0);
	}
		
		
	template <class T>
	Joint_node<T>* Joint_node<T>::getParent(){
		return parent;
	}
	
	template <class T>
	void Joint_node<T>::setParent(Joint_node * _parent){
		parent = _parent;
	}
	
	template <class T>
	list<Joint_node<T>*> Joint_node<T>::getChildren(){
		return children;
	}
		
	template <class T>	
	Dual_quaternion<T> Joint_node<T>::getTransformation_global(){
		return transformation_global;
	}

	template <class T>	
	Dual_quaternion<T> Joint_node<T>::getTransformation_delta(){
		return transformation_global;
	}
	
	template <class T>
	void Joint_node<T>::setTransformation_delta(Dual_quaternion<T> _transformation_delta){
		transformation_delta = _transformation_delta;
	}
	
	template <class T>
	Quaternion<T> Joint_node<T>::getOrientation(){
		return orientation;
	}
	
	template <class T>
	Quaternion<T> Joint_node<T>::getTranslation(){
		return translation;
	}
			
	template <class T>
	Quaternion<T> Joint_node<T>::getAccelerometer_sensor_data() {
		return accelerometer_sensor_data;
	}
	
	template <class T>
	void Joint_node<T>::setAccelerometer_sensor_data(Quaternion<T> _accelerometer_sensor_data){
		accelerometer_sensor_data = _accelerometer_sensor_data;
	}
	
	template <class T>
	Quaternion<T> Joint_node<T>::getGyro_sensor_data(){
		return Gyro_sensor_data;
	}
	
	template <class T>
	void Joint_node<T>::setGyro_sensor_data(Quaternion<T> _Gyro_sensor_data){
		Gyro_sensor_data = _Gyro_sensor_data;
	}
	
	template <class T>
	Quaternion<T> Joint_node<T>::getMagnetic_sensor_data(){
		return magnetic_sensor_data;
	}
	
	template <class T>
	void Joint_node<T>::setMagnetic_sensor_data(Quaternion<T> _magnetic_sensor_data){	
		magnetic_sensor_data = _magnetic_sensor_data;
	}
			
	template <class T>
	void Joint_node<T>::calcOrientation(){
		//this is not neccesary, see notes about orientation and translation 
	}
	
	template <class T>
	void Joint_node<T>::calcTranslation(){
		//this is not neccesary, see notes about orientation and translation 
	}
	
	template <class T>
	void Joint_node<T>::Update_transformation_global(){
		Update_transformation_delta();
		transformation_global= (parent->getTransformation_global())*(getTransformation_delta());
	}
	
	template <class T>
	void Joint_node<T>::Update_transformation_delta(){
		filterUpdate();
		//Q_global = (Q_parent)(Q_delta), 
		//(Q_parent*)(Q_global) = (Q_parent*)(Q_parent)(Q_delta)
		//(Q_parent*)(Q_global) = (Q_delta)
		//Note, inverse = conjugate in unit quaternions
		transformation_delta.q_rot() = parent->getTransformation_global().q_rot().conjugate()*sensor_fusion_orientation;
	}
	
	template <class T>	
	void  Joint_node<T>::filterUpdate(){


	//CONSTANTS
		//constant frame of reference for the acceleometer
		Quaternion<T> Grav_ref(0,0,0,1);
		T alpha = 100;
		//EQ50
		T beta = (0.866 * (0.34906585039));
		//float beta = (0.866 * (0.00305)); 
		//EQ51
		//zeta is not useful until mag is added
		T zeta = (0.866 * (0.002*4.36332313)); //Max deviation based on nonlinearity factor at max rate

	//DATA Setup
		T delta_t = delta_t_ms/1000;
		Quaternion<T> gyro_vals = this->gyro_sensor_data;
		Quaternion<T> accel_vals =this->accelerometer_sensor_data;
		Quaternion<T> last_estimate = transformation_global.q_rot();

	//Gyro calculations

		/* be wary of the following missing step

		// compute then integrate the estimated quaternion rate
			//cout << SEq_1 << ":" << SEq_2 << ":" << SEq_3 << ":"<< SEq_4 << "\n";
			SEq_1 += (SEqDot_omega_1 - (beta * SEqHatDot_1)) * deltat;
			SEq_2 += (SEqDot_omega_2 - (beta * SEqHatDot_2)) * deltat;
			SEq_3 += (SEqDot_omega_3 - (beta * SEqHatDot_3)) * deltat;
			SEq_4 += (SEqDot_omega_4 - (beta * SEqHatDot_4)) * deltat;

		*/

		//Be wary of this half
		Quaternion<T> gyro_derivative =(last_estimate*gyro_vals)*(1/2);


		Quaternion<T> gyro_orientation_estimate(last_estimate + gyro_derivative*delta_t);
		
		//normalize the accelerometer values. No need to worry about absolute values since this algo only cares about the accel ratios
		//gyro values need to be absolute 
	//Accel Calc
		accel_vals.normalize();

		//Miu factor 
		T Miu = alpha*gyro_derivative.get_magnitude()*delta_t;

		//EQ 21
		Quaternion<T> Estimated_accel_values = (last_estimate.conjugate()*Grav_ref)*last_estimate;
		Quaternion<T> f_accel
			(0, 
			Estimated_accel_values.x() - accel_vals.x(),
			Estimated_accel_values.y() - accel_vals.y(),
			Estimated_accel_values.z() - accel_vals.z());
		//Matrix form of the objective function for matrix mult usage
		Eigen::Matrix<T, 3,1> f_matrix_accel;
		f_matrix_accel << f_accel.x()
						,f_accel.y()
						,f_accel.z();


		//Jacobian is the differentiation of the objective funtion f.  
		//The following matrix Jacobian is simpflified due to Grav being a constant [0,0,0,1]
		//EQ 26
		Eigen::Matrix<T, 3,4> J_accel;
		J_accel << -2*(last_estimate.y()),2*(last_estimate.z()),-2*(last_estimate.w()),2*(last_estimate.x()),
					2*(last_estimate.x()),2*(last_estimate.w()),2*(last_estimate.z()),2*(last_estimate.y()),
					0,-4*(last_estimate.x()),-4*(last_estimate.y()),0;
					
		//EQ 34, top half

		Eigen::Matrix<T,4,1> Grad_f_matrix = J_accel.transpose()*f_matrix_accel;

		//EQ 33
		Grad_f_matrix.normalize();
		Grad_f_matrix *= Miu;
		
		Quaternion<T> accel_orientation_estimate(last_estimate.w() - Grad_f_matrix(0,0),
									last_estimate.x() - Grad_f_matrix(1,0),
									last_estimate.y() - Grad_f_matrix(2,0),
									last_estimate.z() - Grad_f_matrix(3,0));

	//Fusion Filter
		
		T gamma = beta/(Miu/delta_t+beta);
		//float gamma = 0;
		/*
		cout << "Counter " << counter << "\n";
		cout << "Gyro sens  Mag: " << gyro_vals.length() << "\n";
		cout << "Gyro deriv Mag: " << gyro_derivative.length() << "\n";
		cout << "Miu: " << Miu << "\n";
		cout << "Gamma: " << gamma << "\n";
		*/

		//Combined filter
		Quaternion<T> fused_state = accel_orientation_estimate*gamma + gyro_orientation_estimate*(1-gamma);

		fused_state.normalize();
		sensor_fusion_orientation = fused_state;
		//vector<float> * euler_angles= new vector<float>();
		//cout << "State is ";QuaternionToEuler(fused_state, euler_angles);
		//counter++;

		}

}

