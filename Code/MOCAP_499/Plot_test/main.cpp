#include "plot_test.h"
#include <QtWidgets/QApplication>
#include <qapplication.h>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_symbol.h>
#include <qwt_legend.h>
#include <vector>
#include <qvector.h>
#include <boost/asio.hpp>
#include <boost/regex.hpp>
#include <boost/thread.hpp>
#include <conio.h>
#include <windows.h>
#include <Eigen>
//NOTE there is some stupidity going on with Eigen2 support involving arrays, just delete \eigen-eigen-5097c01bcdc4\Eigen\Array

//http://eigen.tuxfamily.org/dox-devel/AsciiQuickReference.txt

#include <QQuaternion>

#include "SimpleSerial.h"
#include "guicon.h"
#include "MainWindow.h"
#include "myPlot.h"
#include "data_vectors.h"



using namespace std;
using namespace Eigen;

#pragma comment(linker, "/subsystem:\"console\" /entry:\"WinMainCRTStartup\"")
#include <windows.h>
#include <stdio.h>

#include "GLUT_fcts.h"

int clear_vectors_flag;
vector<float>* MARG_values[9];


vector<float> * Time;
data_vectors accel_data;
data_vectors gyro_data;
data_vectors mag_data;

QQuaternion * Orientation_state;

boost::mutex data_mutex;

float a_x, a_y, a_z; // accelerometer measurements
float w_x, w_y, w_z; // gyroscope measurements in rad/s
float m_x, m_y, m_z; // magnetometer measurements

int counter;


float convert_Accel(float input, int resolution_bits) {
	int FS_value = 2; // Full scale, measured in gs

	return FS_value*(input/(pow(2.0,resolution_bits)));
}

float convert_Gyro(float input, int resolution_bits) {
	int FS_value = 4.36332313; //Full scale, measured in radians 
	return FS_value*(input/pow(2.0,resolution_bits));
}

float convert_Mag(float input, int resolution_bits) {
	int FS_value = 1200; //Full scale, measured in micro Teslas
	return FS_value*(input/pow(2.0,resolution_bits));
}

void QuaternionToEuler(QQuaternion q1, vector<float> * euler)
{
    const float  PI_F=3.14159265358979f;
	
	float roll, pitch, yaw;

    float sqw = q1.scalar()*q1.scalar();
    float sqx = q1.x()*q1.x();
    float sqy = q1.y()*q1.y();
    float sqz = q1.z()*q1.z();
	float unit = sqx + sqy + sqz + sqw; // if normalised is one, otherwise is correction factor
	float test = q1.x()*q1.y() + q1.z()*q1.scalar();
	if (test > 0.499*unit) { // singularity at north pole
		yaw = 2 * atan2(q1.x(),q1.scalar());
		pitch = PI_F/2;
		roll = 0;
		return;
	}
	if (test < -0.499*unit) { // singularity at south pole
		yaw = -2 * atan2(q1.x(),q1.scalar());
		pitch = -PI_F/2;
		roll = 0;
		return;
	}

    yaw = atan2(2*q1.y()*q1.scalar()-2*q1.x()*q1.z() , sqx - sqy - sqz + sqw);
	pitch = asin(2*test/unit);
	roll = atan2(2*q1.x()*q1.scalar()-2*q1.y()*q1.z() , -sqx + sqy - sqz + sqw);

	euler->push_back(roll);
	euler->push_back(pitch);
	euler->push_back(yaw);

	cout << " Roll:" << roll << " Pitch:" << pitch << " Yaw:" << yaw << "\n";

}


void filterUpdate(QQuaternion * orientation_state, float w_x, float w_y, float w_z, float a_x, float a_y, float a_z, float delta_t_ms)
{

	float delta_t = delta_t_ms/1000;
	//CONSTANTS
	//constant frame of reference for the acceleometer
	QQuaternion Grav_ref(0,0,0,1);

	float alpha = 100;
	//EQ50
	float beta = (0.866 * (0.34906585039));
	//float beta = (0.866 * (0.00305)); 
	//EQ51
	//zeta is not useful until mag is added
	float zeta = (0.866 * (0.002*4.36332313)); //Max deviation based on nonlinearity factor at max rate

	QQuaternion last_estimate = *orientation_state;

	QQuaternion gyro_vals(0,w_x,w_y,w_z);
	//QQuaternion gyro_vals(0,0,0,0);
	QQuaternion accel_vals(0,a_x,a_y,a_z);

	//Gyro calculations

	/* be wary of the following missing step

	// compute then integrate the estimated quaternion rate
        //cout << SEq_1 << ":" << SEq_2 << ":" << SEq_3 << ":"<< SEq_4 << "\n";
        SEq_1 += (SEqDot_omega_1 - (beta * SEqHatDot_1)) * deltat;
        SEq_2 += (SEqDot_omega_2 - (beta * SEqHatDot_2)) * deltat;
        SEq_3 += (SEqDot_omega_3 - (beta * SEqHatDot_3)) * deltat;
        SEq_4 += (SEqDot_omega_4 - (beta * SEqHatDot_4)) * deltat;

	*/

	QQuaternion gyro_derivative =(0.5f)*(last_estimate*gyro_vals);


	QQuaternion gyro_orientation_estimate(last_estimate + gyro_derivative*delta_t);
	
	//normalize the accelerometer values. No need to worry about absolute values since this algo only cares about the accel ratios
	//gyro values need to be absolute 
	accel_vals.normalize();

	//Miu factor 
	float Miu = alpha*gyro_derivative.length()*delta_t;

	//EQ 21
	QQuaternion Estimated_accel_values = (last_estimate.conjugate()*Grav_ref)*last_estimate;
	QQuaternion f_accel
		(0, 
		Estimated_accel_values.x() - accel_vals.x(),
		Estimated_accel_values.y() - accel_vals.y(),
		Estimated_accel_values.z() - accel_vals.z());
	//Matrix form of the objective function for matrix mult usage
	Matrix<float, 3,1> f_matrix_accel;
	f_matrix_accel << f_accel.x()
					,f_accel.y()
					,f_accel.z();


	//Jacobian is the differentiation of the objective funtion f.  
	//The following matrix Jacobian is simpflified due to Grav being a constant [0,0,0,1]
	//EQ 26
	Matrix<float, 3,4> J_accel;
	J_accel << -2*(last_estimate.y()),2*(last_estimate.z()),-2*(last_estimate.scalar()),2*(last_estimate.x()),
				2*(last_estimate.x()),2*(last_estimate.scalar()),2*(last_estimate.z()),2*(last_estimate.y()),
				0,-4*(last_estimate.x()),-4*(last_estimate.y()),0;
				
	//EQ 34, top half

	Matrix<float,4,1> Grad_f_matrix = J_accel.transpose()*f_matrix_accel;

	//EQ 33
	Grad_f_matrix.normalize();
	Grad_f_matrix *= Miu;
	
	QQuaternion accel_orientation_estimate(last_estimate.scalar() - Grad_f_matrix(0,0),
								last_estimate.x() - Grad_f_matrix(1,0),
								last_estimate.y() - Grad_f_matrix(2,0),
								last_estimate.z() - Grad_f_matrix(3,0));

	//Fusion Filter
	
	float gamma = beta/(Miu/delta_t+beta);
	//float gamma = 0;
	/*
	cout << "Counter " << counter << "\n";
	cout << "Gyro sens  Mag: " << gyro_vals.length() << "\n";
	cout << "Gyro deriv Mag: " << gyro_derivative.length() << "\n";
	cout << "Miu: " << Miu << "\n";
	cout << "Gamma: " << gamma << "\n";
	*/

	//Combined filter
	QQuaternion fused_state = gamma*accel_orientation_estimate + (1-gamma)*gyro_orientation_estimate;

	fused_state.normalize();
	*orientation_state = fused_state;
	//vector<float> * euler_angles= new vector<float>();
	//cout << "State is ";QuaternionToEuler(fused_state, euler_angles);
	counter++;

}




void Read_arduino()
{
	//TODO add code to search for the right port
	SimpleSerial serial ("COM19",9600);
	string cur_data = "";
	boost::regex arduino_data_regex("Time:(\\d*).*a\\/g\\/m:(-?\\d*)\\|(-?\\d*)\\|(-?\\d*)\\|(-?\\d*)\\|(-?\\d*)\\|(-?\\d*)\\|(-?\\d*)\\|(-?\\d*)\\|(-?\\d*).*");
	boost::match_results<std::string::const_iterator> regex_match_results;
	
	
	while (1) {
	cur_data = serial.readLine();
	

	if(!boost::regex_match(cur_data, regex_match_results, arduino_data_regex, boost::match_default | boost::match_partial))
	{
		cout << "Data error, not of MARG data type" << endl;
	} else {
		if (regex_match_results[1].matched) {
			string time_string (regex_match_results[1].first, regex_match_results[1].second);
			int time_val = ::atof(time_string.c_str());
			string a_x_string (regex_match_results[2].first, regex_match_results[2].second);
			a_x = convert_Accel(::atof(a_x_string.c_str()),15);
			string a_y_string (regex_match_results[3].first, regex_match_results[3].second);
			a_y = convert_Accel(::atof(a_y_string.c_str()),15);
			string a_z_string (regex_match_results[4].first, regex_match_results[4].second);
			a_z = convert_Accel(::atof(a_z_string.c_str()),15);
			string g_x_string (regex_match_results[5].first, regex_match_results[5].second);
			w_x = convert_Gyro(::atof(g_x_string.c_str()),15);
			string g_y_string (regex_match_results[6].first, regex_match_results[6].second);
			w_y = convert_Gyro(::atof(g_y_string.c_str()),15);
			string g_z_string (regex_match_results[7].first, regex_match_results[7].second);
			w_z = convert_Gyro(::atof(g_z_string.c_str()),15);
			string m_x_string (regex_match_results[8].first, regex_match_results[8].second);
			m_x = convert_Mag(::atof(m_x_string.c_str()),12);
			string m_y_string (regex_match_results[9].first, regex_match_results[9].second);
			m_y = convert_Mag(::atof(m_y_string.c_str()),12);
			string m_z_string (regex_match_results[10].first, regex_match_results[10].second);
			m_z = convert_Mag(::atof(m_z_string.c_str()),12);

			QQuaternion Gyro_zero_bias(0, convert_Gyro(-168,15), convert_Gyro(-83,15),convert_Gyro(121,15));
			accel_data.x_values->push_back(a_x);
			accel_data.y_values->push_back(a_y);
			accel_data.z_values->push_back(a_z);

			gyro_data.x_values->push_back(w_x-Gyro_zero_bias.x());
			gyro_data.y_values->push_back(w_y-Gyro_zero_bias.y());
			//gyro_data.y_values->push_back(0);
			gyro_data.z_values->push_back(w_z-Gyro_zero_bias.z());
			//gyro_data.z_values->push_back(0);

			mag_data.x_values->push_back(m_x);
			mag_data.y_values->push_back(m_y);
			mag_data.z_values->push_back(m_z);

			Time->push_back(time_val);

			//TimeHack

			filterUpdate(Orientation_state,w_x,w_y,w_z,a_x,a_y,a_z,6.5f);

		} else {
			cout << "partial match only " << endl;
			cout << cur_data << endl;
		}
	}


	}

}


int main(int argc, char *argv[])
{
   // g_PreviousTicks = std::clock();
 
    //InitGL( argc, argv );
	RedirectIOToConsole();
    QApplication a( argc, argv );

	counter = 0;

	Time = new std::vector<float>();
	Orientation_state = new QQuaternion(1,0,0,0);
	boost::thread workerThread(Read_arduino);
    MainWindow mainWindow (Time, &accel_data, &gyro_data, &mag_data,Orientation_state);
    mainWindow.resize( 1000, 400 );
    mainWindow.show();

    return a.exec();
}




