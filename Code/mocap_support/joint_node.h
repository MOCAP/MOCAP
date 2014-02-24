#ifndef MOCAP_JOINT_NODE
#define MOCAP_JOINT_NODE

using namespace std;
#include <Eigen>
#include "Quaternion.h"
#include "Dual_quaternion.h"
#include "node_data.h"

namespace mocap_support {

	/*
	Simple node types denote the usage of an intermediate Joint_node that has fixed parameters 
	*/
	namespace Joint_node_type{
		enum{
			prismatic=0,
			revolute=1,
			simple=2
		};
	};

	template <class T>
	class Joint_node
	{
	private:
		Quaternion<T> Grav_ref;
		//TODO, make this mag_ref a singleton
		Quaternion<T> Mag_ref;
		Quaternion<T> accelerometer_sensor_data;
		Quaternion<T> gyro_sensor_data;
		Quaternion<T> magnetic_sensor_data;
		T delta_t_ms;
		int ID;

		//STATIC, set by the constructor only
		Quaternion<T> q_base_orientation;
		Quaternion<T> q_base_translation;

		Quaternion<T> sensor_fusion_orientation;	//Orientation that comes out of the sensor algorithm 	
		Dual_quaternion<T> transformation_global; 
		Dual_quaternion<T> transformation_delta;
		
		Joint_node * parent;
		
		vector<Joint_node*> children;
		
		int node_type;
	public:
		Joint_node();
		Joint_node(Quaternion<T> orientation,Quaternion<T> translation,Joint_node * _parent,int _node_type = Joint_node_type::revolute, int ID =0);
		Joint_node(vector<T> screw_axis,vector<T> translation,Joint_node * _parent,T theta=0,int _node_type = Joint_node_type::revolute,int ID =0);
		
		void update_sensor_data(Quaternion<T> _accelerometer_sensor_data,Quaternion<T> _gyro_sensor_data, T _delta_t_ms);
		void update_sensor_data(Quaternion<T> _accelerometer_sensor_data,Quaternion<T> _gyro_sensor_data,Quaternion<T> _magnetic_sensor_data, T _delta_t_ms);
		void update_sensor_data(node_data_frame frame_data);
		void setMagnetic_sensor_data(Quaternion<T> _magnetic_sensor_data);
		void setGyro_sensor_data(Quaternion<T> _gyro_sensor_data);	
		void setAccelerometer_sensor_data(Quaternion<T> _accelerometer_sensor_data);
						
		Quaternion<T> getAccelerometer_sensor_data();
		Quaternion<T> getGyro_sensor_data();
		Quaternion<T> getMagnetic_sensor_data();

		vector<T> get_global_Orientation_as_vector();
		vector<T> get_global_Translation_as_vector();
	
		Quaternion<T> getOrientation();
		void calcOrientation();

		Quaternion<T> get_sensor_fusion_orientation();

		
		Quaternion<T> getTranslation();
		void calcTranslation();
		
		int get_id();

		Dual_quaternion<T> getTransformation_global();
		Dual_quaternion<T> getTransformation_delta();
		void setTransformation_delta(Dual_quaternion<T> _transformation_delta);
		void Update_transformation_delta();
		void Update_transformation_global();
		void filterUpdate();
		void filterUpdate2();
		void normalize_rotations();
		int update_frame();
		
		Joint_node * getParent();
		void setParent(Joint_node<T> * _parent);
		
		vector<Joint_node*> getChildren();
		void addChild(Joint_node<T> * child);
	};

	template <class T>
	vector<T> Joint_node<T>::get_global_Orientation_as_vector(){
		return transformation_global.q_rot().get_quaternion_as_vector();
	}

	template <class T>
	vector<T> Joint_node<T>::get_global_Translation_as_vector(){
		return transformation_global.q_trans().get_quaternion_as_vector();
	}
	
	template <class T>
	Joint_node<T>::Joint_node()
	{
		//Base constructor for usage by the root node only
		ID = 0;
		setParent(this);
		q_base_orientation = Quaternion<T>();
		q_base_translation = Quaternion<T>(0,0,0,0);
		

		transformation_delta = Dual_quaternion<T>(q_base_orientation,q_base_translation*q_base_orientation);
		transformation_global= (parent->getTransformation_global())*(getTransformation_delta());
		sensor_fusion_orientation = Quaternion<T>();
		
		node_type = Joint_node_type::simple;
		
		delta_t_ms = 0;
		accelerometer_sensor_data = Quaternion<T>(0,0,0,-1);
		gyro_sensor_data = Quaternion<T>(0,0,0,0);
		magnetic_sensor_data = Quaternion<T>(0,0,0,1);

		 Grav_ref = Quaternion<T>(0,0,0,1);
		 Mag_ref = Quaternion<T>(1,0,0,0);
	}
	
	template <class T>
	Joint_node<T>::Joint_node(Quaternion<T> _orientation,Quaternion<T> _translation,Joint_node * _parent,int _node_type, int _ID)
	{
		ID = _ID;
		setParent(_parent);
		q_base_orientation = _orientation;
		q_base_translation = _translation;
		
		transformation_delta = Dual_quaternion<T>(q_base_orientation,q_base_translation*q_base_orientation);
		transformation_global= (parent->getTransformation_global())*(getTransformation_delta());
		sensor_fusion_orientation = Quaternion<T>();
		
		node_type = _node_type;
		
		delta_t_ms = 0;
		accelerometer_sensor_data = Quaternion<T>(0,0,0,-1);
		gyro_sensor_data = Quaternion<T>(0,0,0,0);
		magnetic_sensor_data = Quaternion<T>(0,0,0,1);	

		 Grav_ref = Quaternion<T>(0,0,0,1);
		 Mag_ref = Quaternion<T>(1,0,0,0);

		parent->addChild(this);
	}
	
	template <class T>
	Joint_node<T>::Joint_node(vector<T> _screw_axis,vector<T> _translation,Joint_node * _parent,T _theta,int _node_type, int _ID)
	{
		ID = _ID;		
		setParent(_parent);
		q_base_orientation = Quaternion<T>(_theta,_screw_axis);
		q_base_translation = Quaternion<T>(0,_translation[0]/2,_translation[1]/2,_translation[2]/2);
		
		transformation_delta = Dual_quaternion<T>(q_base_orientation,q_base_translation*q_base_orientation);
		transformation_global= (parent->getTransformation_global())*(getTransformation_delta());
		sensor_fusion_orientation = Quaternion<T>();
		
		node_type = _node_type;
		
		delta_t_ms = 0;
		accelerometer_sensor_data = Quaternion<T>(0,0,0,-1);
		gyro_sensor_data = Quaternion<T>(0,0,0,0);
		magnetic_sensor_data = Quaternion<T>(0,0,0,1);

		 Grav_ref = Quaternion<T>(0,0,0,1);
		 Mag_ref = Quaternion<T>(1,0,0,0);

		parent->addChild(this);
	}
	
	
	template <class T>	
	int Joint_node<T>::update_frame(){
		if (ID != 0){
			Update_transformation_global();
		}
		for (int i=0; i < children.size(); i++) {
			children[i]->update_frame();
		 }
		return 0;
	}

	template<class T>
	void Joint_node<T>::normalize_rotations(){
		transformation_global.normalize_rotation();

		for (int i=0; i < children.size(); i++) {
			children[i]->normalize_rotations();
		 }
	}
		
	template <class T>
	int Joint_node<T>::get_id(){
			return ID;
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
	vector<Joint_node<T>*> Joint_node<T>::getChildren(){
		return children;
	}
		
	template <class T>	
	Dual_quaternion<T> Joint_node<T>::getTransformation_global(){
		return transformation_global;
	}

	template <class T>	
	Dual_quaternion<T> Joint_node<T>::getTransformation_delta(){
		return transformation_delta;
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
	Quaternion<T> Joint_node<T>::get_sensor_fusion_orientation(){
		return sensor_fusion_orientation;
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
		return gyro_sensor_data;
	}
	
	template <class T>
	void Joint_node<T>::setGyro_sensor_data(Quaternion<T> _gyro_sensor_data){
		gyro_sensor_data = _gyro_sensor_data;
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
	void Joint_node<T>::update_sensor_data(Quaternion<T> _accelerometer_sensor_data,Quaternion<T> _gyro_sensor_data,Quaternion<T> _magnetic_sensor_data,T _delta_t_ms){
		setMagnetic_sensor_data(_magnetic_sensor_data);
		setGyro_sensor_data(_gyro_sensor_data);
		setAccelerometer_sensor_data(_accelerometer_sensor_data);

		delta_t_ms = _delta_t_ms;
	}
	
	template <class T>
	void Joint_node<T>::update_sensor_data(Quaternion<T> _accelerometer_sensor_data,Quaternion<T> _gyro_sensor_data,T _delta_t_ms){
		setGyro_sensor_data(_gyro_sensor_data);
		setAccelerometer_sensor_data(_accelerometer_sensor_data);

		delta_t_ms = _delta_t_ms;
	}

	template <class T>
	void Joint_node<T>::update_sensor_data(node_data_frame frame_data){

		Quaternion<T> _accelerometer_sensor_data = Quaternion<T>(0,frame_data.ax_value,frame_data.ay_value,frame_data.az_value,mocap_support::quaternion_node_type::data);
		Quaternion<T> _gyro_sensor_data = Quaternion<T>(0,frame_data.gx_value,frame_data.gy_value,frame_data.gz_value,mocap_support::quaternion_node_type::data);
		Quaternion<T> _magnetic_sensor_data = Quaternion<T>(0,frame_data.mx_value,frame_data.my_value,frame_data.mz_value,mocap_support::quaternion_node_type::data);

		setMagnetic_sensor_data(_magnetic_sensor_data);
		setGyro_sensor_data(_gyro_sensor_data);
		setAccelerometer_sensor_data(_accelerometer_sensor_data);

		delta_t_ms = frame_data.time_delta;
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
		//May want to do some work here to counteract floating point error by reinitializing from base data for translation
		//also may want to do some normalizion at this point too
 		transformation_global = getTransformation_delta()*(parent->getTransformation_global());
	}
	
	template <class T>
	void Joint_node<T>::Update_transformation_delta(){
		filterUpdate();
		//Q_global = (Q_delta)(Q_parent), 
		//(Q_global)(Q_parent*) = (Q_delta)(Q_parent)(Q_parent*), 
		//(Q_global)(Q_parent*) = (Q_delta)
		//Note, inverse = conjugate in unit quaternions
		
		Quaternion<T> delta_rot = (sensor_fusion_orientation)*(parent->getTransformation_global().q_rot().conjugate());
		transformation_delta = Dual_quaternion<T>(delta_rot,q_base_translation*delta_rot);
		Quaternion<T> temp = q_base_translation*delta_rot;
		Quaternion<T> temp2 = delta_rot.conjugate()*q_base_translation;
		//transformation_delta = Dual_quaternion<T>(sensor_fusion_orientation
		//											,Quaternion<T>(0,0,0,0,mocap_support::quaternion_node_type::translation));
	}
	
	template <class T>
	void Joint_node<T>::addChild(Joint_node<T> * child){
		children.push_back(child);
	}

	template <class T>	
	void  Joint_node<T>::filterUpdate2(){


	//CONSTANTS
		//constant frame of reference for the acceleometer
		Quaternion<T> Grav_ref(0,0,0,1);
		Quaternion<T> Mag_ref(0,0,1,0);
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
		Quaternion<T> last_estimate;

		//Doing a NAN check
		if(transformation_global.q_rot().get_q0() != transformation_global.q_rot().get_q0()){
				last_estimate = Quaternion<T>();			
		} else {
				last_estimate = transformation_global.q_rot();
		}

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
		Quaternion<T> gyro_derivative =(last_estimate*gyro_vals)*(0.5);


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
		if(!(Grad_f_matrix.isZero()))
		{
			Grad_f_matrix.normalize();
			Grad_f_matrix *= Miu;
		}

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
		//Quaternion<T> fused_state = gyro_orientation_estimate;

		fused_state.normalize();
		sensor_fusion_orientation = fused_state;
		//vector<float> * euler_angles= new vector<float>();
		//cout << "State is ";QuaternionToEuler(fused_state, euler_angles);
		//counter++;

		}


	template <class T>	
	void  Joint_node<T>::filterUpdate(){


	//CONSTANTS
		//constant frame of reference for the acceleometer

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
		Quaternion<T> mag_vals =this->magnetic_sensor_data;
		Quaternion<T> last_estimate;

		
		//TODO These are expensive and do not need to be run this many times
		accel_vals.normalize();
		mag_vals.normalize();

		//Doing a NAN check
		//TODO, this node currently is not recovering from a NAN very well. Could have to add the following to the 
		if(transformation_global.q_rot().get_q0() != transformation_global.q_rot().get_q0()){
				last_estimate = Quaternion<T>();			
		} else {
				last_estimate = transformation_global.q_rot();
		}

		if (Mag_ref.w() == 1){
			Quaternion<T> mag_ref_temp = (last_estimate.conjugate()*mag_vals)*last_estimate;
			float norm_x_y = sqrt(mag_ref_temp.get_q1()*mag_ref_temp.get_q1() +mag_ref_temp.get_q2()*mag_ref_temp.get_q2());
			Mag_ref = Quaternion<T>(0,norm_x_y,0,mag_ref_temp.get_q3());
			//Mag_ref = mag_ref_temp;
		}

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
		Quaternion<T> gyro_derivative =(last_estimate*gyro_vals)*(0.5);


		Quaternion<T> gyro_orientation_estimate(last_estimate + gyro_derivative*delta_t);
		
		//normalize the accelerometer values. No need to worry about absolute values since this algo only cares about the accel ratios
		//gyro values need to be absolute 
	//Accel Calc


		//Miu factor 
		T Miu = alpha*gyro_derivative.get_magnitude()*delta_t;

		//EQ 21
		Quaternion<T> Estimated_accel_values = (last_estimate.conjugate()*Grav_ref)*last_estimate;
		Quaternion<T> f_accel
			(0, 
			Estimated_accel_values.x() - accel_vals.x(),
			Estimated_accel_values.y() - accel_vals.y(),
			Estimated_accel_values.z() - accel_vals.z());
		Eigen::Matrix<T, 3,1> f_matrix_accel;
		f_matrix_accel << f_accel.x()
						,f_accel.y()
						,f_accel.z();


		Quaternion<T> Estimated_mag_values = (last_estimate.conjugate()*Mag_ref)*last_estimate;
		Quaternion<T> f_mag
			(0, 
			Estimated_mag_values.x() - mag_vals.x(),
			Estimated_mag_values.y() - mag_vals.y(),
			Estimated_mag_values.z() - mag_vals.z());
		//Matrix form of the objective function for matrix mult usage
		Eigen::Matrix<T, 3,1> f_matrix_mag;
		f_matrix_mag << f_mag.x()
						,f_mag.y()
						,f_mag.z();


		//Jacobian is the differentiation of the objective funtion f.  
		//The following matrix Jacobian is simpflified due to Grav being a constant [0,0,0,1]
		//EQ 26
		Eigen::Matrix<T, 3,4> J_mag;
		J_mag << 
											  -2*Mag_ref.z()*(last_estimate.y()),	
											   2*Mag_ref.z()*(last_estimate.z()),	
			-4*Mag_ref.x()*(last_estimate.y())-2*Mag_ref.z()*(last_estimate.w()),
			-4*Mag_ref.x()*(last_estimate.z())+2*Mag_ref.z()*(last_estimate.x()),

			-2*Mag_ref.x()*(last_estimate.z())+2*Mag_ref.z()*(last_estimate.x()),	
			2*Mag_ref.x()*(last_estimate.y())+2*Mag_ref.z()*(last_estimate.w()), 
			2*Mag_ref.x()*(last_estimate.x())+2*Mag_ref.z()*(last_estimate.z()), 								
			-2*Mag_ref.x()*(last_estimate.w())+2*Mag_ref.z()*(last_estimate.y()), 

			2*Mag_ref.x()*(last_estimate.y()),
			2*Mag_ref.x()*(last_estimate.z())-4*Mag_ref.z()*(last_estimate.x()), 
			2*Mag_ref.x()*(last_estimate.w())-4*Mag_ref.z()*(last_estimate.y()), 
			2*Mag_ref.x()*(last_estimate.x());
		
		Eigen::Matrix<T, 3,4> J_accel;
		J_accel << 
			-2*(last_estimate.y())
			,2*(last_estimate.z())
			,-2*(last_estimate.w())
			,2*(last_estimate.x())

			,2*(last_estimate.x())
			,2*(last_estimate.w())
			,2*(last_estimate.z())
			,2*(last_estimate.y())
					
			,0
			,-4*(last_estimate.x())
			,-4*(last_estimate.y())
			,0;
					

		//EQ 34, top half

		Eigen::Matrix<T,4,6> Combined_J_transpose;
		Combined_J_transpose << J_accel.transpose(),J_mag.transpose();

		Eigen::Matrix<T,6,1> Combined_f;
		Combined_f << f_matrix_accel,f_matrix_mag;

		Eigen::Matrix<T,4,1> Grad_f_matrix = Combined_J_transpose*Combined_f;
		//Eigen::Matrix<T,4,1> Grad_f_matrix = J_accel.transpose()*f_matrix_accel;


		//EQ 33
		if(!(Grad_f_matrix.isZero()))
		{
			Grad_f_matrix.normalize();
			Grad_f_matrix *= Miu;
		}

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
		//Quaternion<T> fused_state = accel_orientation_estimate;
		//Quaternion<T> fused_state = gyro_orientation_estimate;

		fused_state.normalize();
		sensor_fusion_orientation = fused_state;
		//vector<float> * euler_angles= new vector<float>();
		//cout << "State is ";QuaternionToEuler(fused_state, euler_angles);
		//counter++;

		}

}


#endif