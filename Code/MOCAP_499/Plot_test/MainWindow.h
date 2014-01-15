#include <qapplication.h>
#include <qmainwindow.h>
#include <qtoolbar.h>
#include <qtoolbutton.h>
#include <qslider.h>
#include "myPlot.h"
#include "GLWidget.h"

#include "data_vectors.h"

class MainWindow: public QMainWindow
{
public:
	MainWindow(std::vector<float> *Time, 
		data_vectors * accel_data,
		data_vectors * gyro_data,
		data_vectors * mag_data,
		QQuaternion * orientation,
		QWidget *parent = 0);

private:
    myPlot *d_plot;
	myPlot *d_plot2;
	myPlot *d_plot3;
	GlWidget *d_GLwidget;
	QQuaternion * orientation;
	std::vector<float> * Time;
	data_vectors * accel_data;
	data_vectors * gyro_data;
	data_vectors * mag_data;

};