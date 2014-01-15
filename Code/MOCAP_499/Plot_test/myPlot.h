#ifndef myPlot_H
#define myPlot_H

#include <QtWidgets/QApplication>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_symbol.h>
#include <qwt_legend.h>
#include <vector>
#include <string.h>
#include "data_vectors.h"

class myPlot : public QwtPlot
{
public:
	myPlot(std::vector<float> *Time, 
		data_vectors * xyz_data,
		std::string data_source,
		std::string data_units,
		QWidget *parent = 0);
	
protected:
    virtual void timerEvent( QTimerEvent *e );
	
private:
	int d_timerId;
	QwtPlotCurve *curve_x;
	QwtPlotCurve *curve_y;
	QwtPlotCurve *curve_z;
	int counter;
	std::vector<float> * Time;
	data_vectors * xyz_data;
	std::string data_source;

};



#endif