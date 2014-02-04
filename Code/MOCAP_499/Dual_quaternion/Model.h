#include <map>


template<T>
struct joint_base<T>{
	int parent;
	int ID;
	vector<T> displacement;
}

template<T> 
class Model<T> {

	Model<T>()
	Model<T>(vector<T> * model_configuration)
	
	
	private:
	std::map<int,joint_node<T>> table_of_nodes;
	update_node_sensor(/*sensor data*/);
	
	public:
	joint_node<T> get_node(/* node id*/);
	void update_model_frame();

}


template<T>
Model<T>(){
	joint_node<T> root();
	table_of_nodes[0] = root;
}


template<T>
Model<T>(joint_base[] model_configuration, int length) {
	
	joint_node<T> root();
	table_of_nodes[0] = root;
	
	//TODO: Do input validation on the array 
	
	for (int i = 1; i <= length; i++) {
		
		int parent_ID = model_configuration[i].parent;
		int joint_ID = model_configuration[i].ID;
		vector<T> segment_displacement = model_configuration[i].displacement;
		
		if(table_of_nodes[parent_ID] == null){
			//throw an exception. the parent doesn't exist yet and this model is out of order
		} else {
			table_of_nodes[parent_ID].add_child(new joint_node(segment_displacement, ID);
		}
	}
}

template<T>
joint_node get_node(int ID){
	
	if(table_of_nodes[ID] == null){
		return null;
	} else {
		return table_of_nodes[ID];
	}
	
}

int update_node_sensor(ID,data){

	if(table_of_nodes[ID] == null){
		return -1;
	} else {
		table_of_nodes[ID].update_sensor_data(data);
	}
}

int update_model_frame(){
	//Updating is a recursive process
	return root.update_frame();
}
