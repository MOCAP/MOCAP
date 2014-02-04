#ifndef MOCAP_MODEL
#define MOCAP_MODEL

#include <map>
#include <exception>
#include "joint_node.h"

namespace mocap_support {

	template <typename T>
	struct joint_base{
		int parent_ID;
		int ID;
		vector<T> displacement;
	};

	template<class T> 
	class Model {
	
	private:
		Joint_node<T>* root;
		std::map<int,Joint_node<T>*> table_of_nodes;
		int Model<T>::update_node_sensor(int ID,Quaternion<T> _accelerometer_sensor_data,Quaternion<T> _gyro_sensor_data, T _delta_t_ms);
		
	public:
	
		Model<T>();
		Model<T>( joint_base<T> model_configuration[], int length);
		
		
		Joint_node<T> get_node(int ID);
		int update_model_frame();

	};


	template<class T>
	Model<T>::Model(){
		Joint_node<T> root = Joint_node<T>();
		table_of_nodes[0] = root;
	}


	template<class T>
	Model<T>::Model( joint_base<T> model_configuration[], int length) {
		
		root = new Joint_node<T>();
		table_of_nodes[0] = root;
		
		//TODO: Do input validation on the array 
		
		for (int i = 1; i < length; i++) {
			
			int parent_ID = model_configuration[i].parent_ID;
			int joint_ID = model_configuration[i].ID;
			vector<T> segment_displacement = model_configuration[i].displacement;
			
			if(table_of_nodes.find(parent_ID) == table_of_nodes.end()){
				//throw an exception. the parent doesn't exist yet and this model is out of order
			} else {
				//Node creation includes the add to parent operation, no need to redo it
				Joint_node<T>* child = new Joint_node<T>(Quaternion<T>()
																	,Quaternion<T>(segment_displacement,quaternion_node_type::translation)
																	,table_of_nodes[parent_ID]
																	,Joint_node_type::revolute
																	,joint_ID);

				table_of_nodes[joint_ID] = child;


			}
		}
	}

	template<class T>
	Joint_node<T> Model<T>::get_node(int ID){
		if(table_of_nodes.find(ID) == table_of_nodes.end()){
			return null;
		} else {
			return table_of_nodes[ID];
		}
		
	}

	template<class T>
	int Model<T>::update_node_sensor(int ID,Quaternion<T> _accelerometer_sensor_data,Quaternion<T> _gyro_sensor_data, T _delta_t_ms){

		if(table_of_nodes[ID] == null){
			return -1;
		} else {
			table_of_nodes[ID].update_sensor_data(Quaternion<T> _accelerometer_sensor_data,Quaternion<T> _gyro_sensor_data, T _delta_t_ms);
			return 0;
		}
	}

	template<class T>
	int Model<T>::update_model_frame(){
		//Updating is a recursive process
		return root->update_frame();
	}


}

#endif