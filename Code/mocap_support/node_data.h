#ifndef MOCAP_NODE_DATA
#define MOCAP_NODE_DATA


#include <queue>
namespace mocap_support {

	class node_data_frame {
	public:
		float ax_value;
		float ay_value;
		float az_value;
		float gx_value;
		float gy_value;
		float gz_value;
		float mx_value;
		float my_value;
		float mz_value;
		float time_delta;
		int node_ID;

		node_data_frame(int _node_ID,
		float _ax_value,
		float _ay_value,
		float _az_value,
		float _gx_value,
		float _gy_value,
		float _gz_value,
		float _mx_value,
		float _my_value,
		float _mz_value,
		float _time_delta);
	};
	
	class node_data {
	public:
		std::queue<node_data_frame> * data_values;
		int node_ID;
		unsigned int current_timestamp;

		node_data(int _node_ID,unsigned int _initial_timestamp);
	};
	
};

mocap_support::node_data_frame::node_data_frame(int _node_ID,
		float _ax_value,
		float _ay_value,
		float _az_value,
		float _gx_value,
		float _gy_value,
		float _gz_value,
		float _mx_value,
		float _my_value,
		float _mz_value,
		float _time_delta){
	node_ID = _node_ID;	
	ax_value = _ax_value;
	ay_value = _ay_value;
	az_value = _az_value;
	gx_value = _gx_value;
	gy_value = _gy_value;
	gz_value = _gz_value;
	mx_value = _mx_value;
	my_value = _my_value;
	mz_value = _mz_value;
	time_delta = _time_delta;

}

mocap_support::node_data::node_data(int _node_ID,unsigned int _initial_timestamp){

	node_ID= _node_ID;
	data_values = new std::queue<node_data_frame>();
	current_timestamp = _initial_timestamp;
}

#endif