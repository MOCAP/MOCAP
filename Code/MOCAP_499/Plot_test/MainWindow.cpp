#include <qstatusbar.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qevent.h>
#include <qdatetime.h>
#include <qwt_plot_canvas.h>
#include "MainWindow.h"

MainWindow::MainWindow(std::vector<float> *Time, 
		data_vectors * accel_data,
		data_vectors * gyro_data,
		data_vectors * mag_data,
		QQuaternion * orientation,
		QWidget *parent) :
    QMainWindow( parent )
{
   	this->Time = Time;
	this->accel_data = accel_data;
	this->gyro_data = gyro_data;
	this->mag_data = mag_data;
	this->orientation = orientation;



	QWidget *w = new QWidget( this );

	d_plot = new myPlot(Time , accel_data,"Accel","g", w);
	d_plot2 = new myPlot(Time ,gyro_data,"Gyro","rads/s", w);
	d_plot3 = new myPlot(Time , mag_data, "Mag","uT", w);

	d_GLwidget = new GlWidget(orientation,w);
	d_GLwidget->update();

    QBoxLayout *hLayout = new QHBoxLayout( w );
	hLayout->addWidget( d_GLwidget);
	hLayout->addWidget( d_plot);
	hLayout->addWidget( d_plot2);
	hLayout->addWidget( d_plot3);


    setCentralWidget( w );

}
