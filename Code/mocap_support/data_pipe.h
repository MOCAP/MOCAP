#ifndef MOCAP_DATA_PIPE
#define MOCAP_DATA_PIPE


#include <boost/asio.hpp>
#include <boost/regex.hpp>

#include <string>
#include "SimpleSerial.h"
#include <iostream>
#include <boost/thread.hpp>
#include "node_data.h"

namespace mocap_support {

	const std::string default_regex = "ID:(\\d)Time:(\\d*).*a\\/g\\/m:(-?\\d*)\\|(-?\\d*)\\|(-?\\d*)\\|(-?\\d*)\\|(-?\\d*)\\|(-?\\d*)\\|(-?\\d*)\\|(-?\\d*)\\|(-?\\d*).*";


	class data_pipe{
	
		private:
			boost::mutex mtx_;
			std::string serial_port_name;
			int baud_rate;
			boost::regex regex_rule;
			SimpleSerial * serial_port;
			boost::match_results<std::string::const_iterator> regex_match_results;
			std::map<int , node_data*> nodes_map;
			std::string current_data;
			int process_data;
			
			float convert_Accel(float input, int resolution_bits);
			float convert_Gyro(float input, int resolution_bits);
			float convert_Mag(float input, int resolution_bits);
			int insert_data(int node_id,float ax,float ay, float az, float gx, float gy, float gz, float mx, float my, float mz,unsigned int time_val);
		public:
			data_pipe(std::string _port_name,int _baud_rate = 9600,std::string regex_string = default_regex);
			node_data_frame get_next_frame(int id=1);
			int begin_serial();
			int Start();
			int begin_data_acquisition();
			int end_data_acquisition();
			void lock();
			void unlock();
			bool contains_node_data(int _node_id);
	};

};

void mocap_support::data_pipe::lock(){
	mtx_.lock();
}

void mocap_support::data_pipe::unlock(){
	mtx_.unlock();
}
mocap_support::node_data_frame mocap_support::data_pipe::get_next_frame(int _node_id){
	boost::lock_guard<data_pipe> guard(*this);
	if(nodes_map.find(_node_id) == nodes_map.end()){
		return mocap_support::node_data_frame(-1,0,0,0,0,0,0,0,0,0,0);
	}
	
	mocap_support::node_data_frame current_frame = nodes_map[_node_id]->get_next_frame();

	return current_frame;
}

bool mocap_support::data_pipe::contains_node_data(int _node_id){
	if(nodes_map.find(_node_id) != nodes_map.end()){
		if(!(nodes_map[_node_id]->empty())){
			return true;
		}
	}

	return false;
}



int mocap_support::data_pipe::insert_data(int _node_id,float _ax,float _ay, float _az, float _gx, float _gy, float _gz, float _mx, float _my, float _mz,unsigned int _time_val){
	boost::lock_guard<mocap_support::data_pipe> guard(*this);
	if(nodes_map.find(_node_id) == nodes_map.end()){
		//must pass in an initial timestamp
		nodes_map[_node_id] = new mocap_support::node_data(_node_id,_time_val);
		return 0;
	}
	return nodes_map[_node_id]->insert_data(_ax,_ay,_az,_gx,_gy,_gz,_mx,_my, _mz,_time_val);

}

mocap_support::data_pipe::data_pipe(std::string _port_name,int _baud_rate,std::string _regex_string) {
	
	serial_port_name = _port_name;
	regex_rule = boost::regex(_regex_string);
	baud_rate = _baud_rate;
	serial_port =  new SimpleSerial(serial_port_name,baud_rate);
	nodes_map = std::map<int,node_data*>();
	process_data = 0;
}

int mocap_support::data_pipe::begin_data_acquisition(){
	process_data =1;

	return 0;
}

int mocap_support::data_pipe::end_data_acquisition(){
	process_data =0;

	return 0;
}

int mocap_support::data_pipe::Start(){
	
	float a_x, a_y, a_z; // accelerometer measurements
	float g_x, g_y, g_z; // gyroscope measurements in rad/s
	float m_x, m_y, m_z; // magnetometer measurements

	int node_count =0;
	while (process_data) {
		current_data = serial_port->readLine();
		//std::cout << current_data << std::endl;
		if(!boost::regex_match(current_data, regex_match_results, regex_rule, boost::match_default | boost::match_partial))
		{
			std::cout << "Data error, not of MARG data type" << std::endl;
		} else {
			if (regex_match_results[1].matched) {
				std::string ID_string (regex_match_results[1].first, regex_match_results[1].second);
				int node_id = ::atoi(ID_string.c_str());
				std::string time_string (regex_match_results[2].first, regex_match_results[2].second);
				unsigned int time_val = ::atoi(time_string.c_str());
				std::string a_x_string (regex_match_results[3].first, regex_match_results[3].second);
				a_x = convert_Accel(::atof(a_x_string.c_str()),16);
				std::string a_y_string (regex_match_results[4].first, regex_match_results[4].second);
				a_y = convert_Accel(::atof(a_y_string.c_str()),16);
				std::string a_z_string (regex_match_results[5].first, regex_match_results[5].second);
				a_z = convert_Accel(::atof(a_z_string.c_str()),16);
				std::string g_x_string (regex_match_results[6].first, regex_match_results[6].second);
				g_x = convert_Gyro(::atof(g_x_string.c_str()),16);
				std::string g_y_string (regex_match_results[7].first, regex_match_results[7].second);
				g_y = convert_Gyro(::atof(g_y_string.c_str()),16);
				std::string g_z_string (regex_match_results[8].first, regex_match_results[8].second);
				g_z = convert_Gyro(::atof(g_z_string.c_str()),16);
				std::string m_x_string (regex_match_results[9].first, regex_match_results[9].second);
				m_x = convert_Mag(::atof(m_x_string.c_str()),12);
				std::string m_y_string (regex_match_results[10].first, regex_match_results[10].second);
				m_y = convert_Mag(::atof(m_y_string.c_str()),12);
				std::string m_z_string (regex_match_results[11].first, regex_match_results[11].second);
				m_z = convert_Mag(::atof(m_z_string.c_str()),12);
			
				insert_data(node_id,a_x,a_y,a_z,g_x,g_y,g_z,m_x,m_y,m_z,time_val);

			
			} else {
				std::cout << "partial match only " << std::endl;
				std::cout << current_data << std::endl;
			}
		}
	}
	return 0;
}


float mocap_support::data_pipe::convert_Accel(float input, int resolution_bits) {
	float FS_value = 4; // Full scale, measured in gs

	return FS_value*(input/(pow(2.0,resolution_bits)));
}

float mocap_support::data_pipe::convert_Gyro(float input, int resolution_bits) {
	float FS_value = 2.0*4.36332313; //Full scale, measured in radians 
	return FS_value*(input/pow(2.0,resolution_bits));
}

float mocap_support::data_pipe::convert_Mag(float input, int resolution_bits) {
	float FS_value = 1200; //Full scale, measured in micro Teslas
	return FS_value*(input/pow(2.0,resolution_bits));
}



#endif