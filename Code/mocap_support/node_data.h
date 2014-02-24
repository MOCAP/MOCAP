#ifndef MOCAP_NODE_DATA
#define MOCAP_NODE_DATA


#include <deque>
#include <boost/thread.hpp>


namespace mocap_support {


	//used to identify the type of data being passed around
	namespace sensor_value_type{
		enum{
			accel_x=0,
			accel_y=1,
			accel_z=2,
			gyro_x=3,
			gyro_y=4,
			gyro_z=5,
			mag_x=6,
			mag_y=7,
			mag_z=8
		};
	};


	//A single snapshot of data at an instant in time for one node
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
	
	//Holds one nodes calibration data
	class calibration_data {
		public:
			float g_steady_offset_x;
			float g_steady_offset_y;
			float g_steady_offset_z;

			float m_hard_offset_x;
			float m_hard_offset_y;
			float m_hard_offset_z;
			
			calibration_data(float _g_steady_offset_x=0,float _g_steady_offset_y=0,float _g_steady_offset_z=0,float _m_hard_offset_x=0,float _m_hard_offset_y=0,float _m_hard_offset_z=0);

	};

	//All incoming data and states for one node
	class node_data {
	private:
		boost::mutex mtx_;
		int calibration_state;
		std::deque<node_data_frame> data_values;
		int node_ID;
		unsigned int current_timestamp;
		calibration_data node_calibration;

	public:

		node_data(int _node_ID,unsigned int _initial_timestamp);
		float correct_using_calibration(int value_type_id, float sense_value);
		int insert_data(float _ax,float _ay, float _az, float _gx, float _gy, float _gz, float _mx, float _my, float _mz,unsigned int _time_val);
		mocap_support::node_data_frame get_next_frame();
		bool empty();
		int get_calibration_state();
		void set_calibrate_gyro();
		void set_calibrate_mag();
		bool calibrate_gyro(int _calibration_count=200);
		bool calibrate_mag(int _calibration_count=1000);
		int get_node_id();
		void lock();
		void unlock();
	};
};

mocap_support::node_data_frame mocap_support::node_data::get_next_frame(){
	boost::lock_guard<node_data> guard(*this);
	mocap_support::node_data_frame current_frame = mocap_support::node_data_frame(-1,0,0,0,0,0,0,0,0,0,0);
	
	if(!empty()){
		if(get_calibration_state() == 0){
			current_frame = data_values.front();
			data_values.pop_front();
		} else {
			switch(get_calibration_state()){
				case(1):// A
					//calibrate_accel();
					break;
				case(2): // G 
					calibrate_gyro();
					break;
				case(3): //A + G
					//calibrate_accel();
					calibrate_gyro();
					break;
				case(4): // M 
					calibrate_mag();
					break;
				case(5): // A + M 
					//calibrate_accel();
					calibrate_mag();
					break;
				case(6): // G + M
					calibrate_gyro();
					calibrate_mag();
					break;
				case(7): // A + G + M
					//calibrate_accel();
					calibrate_gyro();
					calibrate_mag();
					break;
			}

		}
	}
	
	return current_frame;
}

bool mocap_support::node_data::empty(){
	return data_values.empty();
}

void mocap_support::node_data::lock(){
	mtx_.lock();
}

void mocap_support::node_data::unlock(){
	mtx_.unlock();
}

int mocap_support::node_data::get_calibration_state(){
	//0 calibrated, file permission style
	//1 Gyro
	//3 Mag
	//4 Gyro + mag
	return calibration_state;
}

void mocap_support::node_data::set_calibrate_gyro(){
	calibration_state += 2;
}

void mocap_support::node_data::set_calibrate_mag(){
	calibration_state += 4;
}

bool mocap_support::node_data::calibrate_gyro(int _calibration_count){

	if(!(calibration_state == 2 | calibration_state == 3| calibration_state == 6 | calibration_state == 7)){
		return false;
	}

	int calibration_count = 100;

	if(data_values.size() >= calibration_count) {
	
		float gyro_x = 0;
		float gyro_y = 0;
		float gyro_z = 0;
		for (int i = 0; i < calibration_count; i++){
			gyro_x += data_values[i].gx_value;
			gyro_y += data_values[i].gy_value;
			gyro_z += data_values[i].gz_value;
		}
		
		node_calibration.g_steady_offset_x = gyro_x/(float)calibration_count;
		node_calibration.g_steady_offset_y = gyro_y/(float)calibration_count;
		node_calibration.g_steady_offset_z = gyro_z/(float)calibration_count;

		calibration_state -= 2;
		cout << "Gyro Calibration Complete\r\n";
		return true;
	} else {
		return false;	
	}
}

bool mocap_support::node_data::calibrate_mag(int _calibration_count){
	
	if(!(calibration_state == 4 | calibration_state == 5| calibration_state == 6 | calibration_state == 7)){
		return false;
	}

	int calibration_count = _calibration_count;

	if(data_values.size() >= calibration_count) {
	
		float mag_x_min = data_values[0].mx_value;
		float mag_y_min = data_values[0].my_value;
		float mag_z_min = data_values[0].mz_value;
		float mag_x_max = data_values[0].mx_value;
		float mag_y_max = data_values[0].my_value;
		float mag_z_max = data_values[0].mz_value;

		for (int i = 0; i < calibration_count; i++){

			if(mag_x_min > data_values[i].mx_value) {
				mag_x_min = data_values[i].mx_value;
			}

			if(mag_y_min > data_values[i].my_value) {
				mag_y_min = data_values[i].my_value;
			}
			if(mag_z_min > data_values[i].mz_value) {
				mag_z_min = data_values[i].mz_value;
			}

			if(mag_x_max < data_values[i].mx_value) {
				mag_x_max = data_values[i].mx_value;
			}

			if(mag_y_max < data_values[i].my_value) {
				mag_y_max = data_values[i].my_value;
			}
			if(mag_z_max < data_values[i].mz_value) {
				mag_z_max = data_values[i].mz_value;
			}
		}
		
		node_calibration.m_hard_offset_x = mag_x_min+(mag_x_max-mag_x_min)/(2.0);
		node_calibration.m_hard_offset_y = mag_y_min+(mag_y_max-mag_y_min)/(2.0);
		node_calibration.m_hard_offset_z = mag_z_min+(mag_z_max-mag_z_min)/(2.0);

		cout << "Mag Calibration Complete\r\n";
		calibration_state -= 4;
		return true;
	} else {
		return false;	
	}
}
 
int mocap_support::node_data::get_node_id(){
	return node_ID;
} 
 
int mocap_support::node_data::insert_data(float _ax,float _ay, float _az, float _gx, float _gy, float _gz, float _mx, float _my, float _mz,unsigned int _time_val){
		boost::lock_guard<mocap_support::node_data> guard(*this);
		
		float delta_t = _time_val - current_timestamp ;
		current_timestamp = _time_val;
		
		if(calibration_state == 0){
			data_values.push_back(node_data_frame(
			get_node_id()
			,correct_using_calibration(mocap_support::sensor_value_type::accel_x,_ax)
			,correct_using_calibration(mocap_support::sensor_value_type::accel_y,_ay)
			,correct_using_calibration(mocap_support::sensor_value_type::accel_z,_az)
			,correct_using_calibration(mocap_support::sensor_value_type::gyro_x,_gx)
			,correct_using_calibration(mocap_support::sensor_value_type::gyro_y,_gy)
			,correct_using_calibration(mocap_support::sensor_value_type::gyro_z,_gz)
			,correct_using_calibration(mocap_support::sensor_value_type::mag_x,_mx)
			,correct_using_calibration(mocap_support::sensor_value_type::mag_y,_my)
			,correct_using_calibration(mocap_support::sensor_value_type::mag_z,_mz)
			,delta_t));
		} else {
			//only use raw data when doing calibration
			data_values.push_back(node_data_frame(
			get_node_id()
			,_ax
			,_ay
			,_az
			,_gx
			,_gy
			,_gz
			,_mx
			,_my
			,_mz
			,delta_t));
		}
		
		return 0;
}


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
	data_values = std::deque<node_data_frame>();
	current_timestamp = _initial_timestamp;
	node_calibration = calibration_data();
	calibration_state = 0;
	//set_calibrate_gyro();
	//set_calibrate_mag();
}

mocap_support::calibration_data::calibration_data(float _g_steady_offset_x,float _g_steady_offset_y,float _g_steady_offset_z,float _m_hard_offset_x,float _m_hard_offset_y,float _m_hard_offset_z){
	g_steady_offset_x = _g_steady_offset_x;
	g_steady_offset_y = _g_steady_offset_y;
	g_steady_offset_z = _g_steady_offset_z;

	m_hard_offset_x = _m_hard_offset_x;
	m_hard_offset_y = _m_hard_offset_y;
	m_hard_offset_z = _m_hard_offset_z;
}

float mocap_support::node_data::correct_using_calibration(int value_type_id, float sense_value){

	switch(value_type_id){
		case(mocap_support::sensor_value_type::accel_x):
		case(mocap_support::sensor_value_type::accel_y):
		case(mocap_support::sensor_value_type::accel_z):
			return sense_value;
			break;
		case(mocap_support::sensor_value_type::gyro_x):		
			return sense_value-node_calibration.g_steady_offset_x;
			break;
		case(mocap_support::sensor_value_type::gyro_y):		
			return sense_value-node_calibration.g_steady_offset_y;
			break;		
		case(mocap_support::sensor_value_type::gyro_z):		
			return sense_value-node_calibration.g_steady_offset_z;
			break;
		case(mocap_support::sensor_value_type::mag_x):
		case(mocap_support::sensor_value_type::mag_y):
		case(mocap_support::sensor_value_type::mag_z):
			return sense_value;
			break;		
	}

	return sense_value;
}

#endif