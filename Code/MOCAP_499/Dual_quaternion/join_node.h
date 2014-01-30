using namespace std;


namespace mocap_support {

	/*
	Simple node types denote the usage of an intermediate joint that has fixed parameters 
	*/
	enum DH_node_type{prismatic, revolute, simple}

	
	template <class T>
	class Joint
	{
	private:
		Quaternion<T> accelerometer_sensor_data;
		Quaternion<T> gravity_sensor_data;
		Quaternion<T> magnetic_sensor_data;

		//STATIC, set by the constructor only
		Quaternion<T> orientation;
		Quaternion<T> translation;

		Quaternion<T> sensor_fusion_orientation;	//Orientation that comes out of the sensor algorithm 	
		Dual_quaternion<T> transformation_global; 
		Dual_quaternion<T> transformation_delta;
		
		Joint * parent;
		
		list<* Joint> childs;
		

	public:
		Joint();
		
		Quaternion<T> getAccelerometer_sensor_data() {return accelerometer_sensor_data;};
		Quaternion<T> setAccelerometer_sensor_data(Quaternion<T> _accelerometer_sensor_data)
									{accelerometer_sensor_data = _accelerometer_sensor_data;};
		Quaternion<T> getGravity_sensor_data(){return gravity_sensor_data;};
		Quaternion<T> setGravity_sensor_data(Quaternion<T> _gravity_sensor_data)
									{gravity_sensor_data = _gravity_sensor_data;};
		Quaternion<T> getMagnetic_sensor_data(){return magnetic_sensor_data;};
		Quaternion<T> setMagnetic_sensor_data(Quaternion<T> _magnetic_sensor_data)
									{magnetic_sensor_data = _magnetic_sensor_data;};
		
		Quaternion<T> getOrientation(return orientation;);
		Quaternion<T> calcOrientation();
		
		Quaternion<T> getTranslation(return translation;);
		Quaternion<T> calcTranslation();
		
		Dual_quaternion<T> getTransformation_global(){return transformation_global;}; 
		Dual_quaternion<T> calcTransformation_global(); 
		
		Dual_quaternion<T> setTransformation_delta(){return transformation_delta;};
		Dual_quaternion<T> Update_transformation_delta();
		
		Joint * getParent(){return parent};
		Joint * setParent(Joing * _parent){parent = _parent;};
		
		list<* Joint> getChilds(){return childs;};
		bool addChild(Joint * child);
	}
	
	template <class T>
	Quaternion<T>::calcOrientation(){
		//this is not neccesary, see notes about orientation and translation 
	}
	
	template <class T>
	Quaternion<T>::calcTranslation(){
		//this is not neccesary, see notes about orientation and translation 
	}
	
	template <class T>
	Dual_quaternion<T>::Update_transformation_global(){
		Update_transformation_delta();
		transformation_global= (parent)*(getTransformation_delta());
	}
	
	template <class T>
	Dual_quaternion<T>::Update_transformation_delta(){
		//TODO, port the algorithm over and put it in the base quaternion class
		sensor_fusion_orientation = call_sensor_fusion_algorithm(transformation_global.q_rot(), accelerometer_sensor_data,gravity_sensor_data,magnetic_sensor_data );
		//Q_global = (Q_parent)(Q_delta), 
		//(Q_parent*)(Q_global) = (Q_parent*)(Q_parent)(Q_delta)
		//(Q_parent*)(Q_global) = (Q_delta)
		//Note, inverse = conjugate in unit quaternions
		transformation_delta.q_rot() = parent->q_rot().conjugate()*sensor_fusion_orientation;
	}
	
}

