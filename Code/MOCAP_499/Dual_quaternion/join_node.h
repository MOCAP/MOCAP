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
		
		Quaternion<T> orientation;
		Quaternion<T> translation;
		
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
		Dual_quaternion<T> calcTransformation_delta();
		
		Joint * getParent(){return parent};
		Joint * setParent(Joing * _parent){parent = _parent;};
		
		list<* Joint> getChilds(){return childs;};
		bool addChild(Joint * child);
	}
	
	template <class T>
	Quaternion<T>::calcOrientation(){
	}
	
	template <class T>
	Quaternion<T>::calcTranslation(){
	}
	
	template <class T>
	Dual_quaternion<T>::calcTransformation_global(){
	}
	
	template <class T>
	Dual_quaternion<T>::calcTransformation_delta(){
	}
	
}

