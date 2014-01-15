#include <QtWidgets/QApplication>
#include <qapplication.h>
#include <iostream>
#include "myPlot.h"
#include "data_vectors.h"
#include <string.h>
#include <Qstring.h>

using namespace std;

myPlot::myPlot(std::vector<float> *Time, 
		data_vectors * xyz_data,
		std::string data_source,
		std::string data_units,
		QWidget *parent) :
    QwtPlot( parent )
{
	this->Time = Time;
	this->xyz_data = xyz_data;
	string s_plot_title (data_source + " data plot");
	QString q_plot_title(s_plot_title.c_str());

	setTitle( q_plot_title);

    // Show the axes
    setAxisTitle( xBottom, "Time(s)" );

	QString y_label(data_units.c_str());
    setAxisTitle( yLeft, y_label );

    setCanvasBackground( Qt::white );
    //setAxisScale( QwtPlot::yLeft, 0.0, 10.0 );
    insertLegend( new QwtLegend() );

    curve_x = new QwtPlotCurve();
	curve_y = new QwtPlotCurve();
	curve_z = new QwtPlotCurve();

	string s_curve_name_x (data_source + " _x");
	QString q_curve_name_x(s_curve_name_x.c_str());

	string s_curve_name_y (data_source + " _y");
	QString q_curve_name_y(s_curve_name_y.c_str());

	string s_curve_name_z (data_source + " _z");
	QString q_curve_name_z(s_curve_name_z.c_str());


    curve_x->setTitle( q_curve_name_x );
	curve_y->setTitle( q_curve_name_y );
	curve_z->setTitle( q_curve_name_z);

    curve_x->setPen( Qt::red, 4 );
    curve_x->setRenderHint( QwtPlotItem::RenderAntialiased, true );

	curve_x->setStyle(QwtPlotCurve::CurveStyle::NoCurve);

    QwtSymbol *symbol_x = new QwtSymbol( QwtSymbol::Ellipse,QBrush( Qt::yellow ), QPen( Qt::blue, 2 ), QSize( 8, 8 ) );
    QwtSymbol *symbol_y = new QwtSymbol( QwtSymbol::Ellipse,QBrush( Qt::yellow ), QPen( Qt::green, 2 ), QSize( 8, 8 ) ); 
	QwtSymbol *symbol_z = new QwtSymbol( QwtSymbol::Ellipse,QBrush( Qt::yellow ), QPen( Qt::red, 2 ), QSize( 8, 8 ) );

    curve_x->setSymbol( symbol_x );
	curve_y->setSymbol( symbol_y );
	curve_z->setSymbol( symbol_z );

	curve_x->setLegendAttribute(QwtPlotCurve::LegendAttribute::LegendShowSymbol,true);
	curve_y->setLegendAttribute(QwtPlotCurve::LegendAttribute::LegendShowSymbol,true);
	curve_z->setLegendAttribute(QwtPlotCurve::LegendAttribute::LegendShowSymbol,true);

	curve_x->attach( this );
	curve_y->attach( this );
	curve_z->attach( this );

    resize( 600, 400 );
    show();

	    if ( d_timerId >= 0 )
        killTimer( d_timerId );

    d_timerId = startTimer( 20 /*update interval in milliseconds */ );

	counter = 1;
}

void myPlot::timerEvent( QTimerEvent * )
{
    QVector<QPointF> data_x; 
	QVector<QPointF> data_y; 
	QVector<QPointF> data_z; 

	int time_last = Time->size();

	for( int i = 0; i < 100; i++){
		if(time_last-1-i*1 > 0) {
			//std::cout <<time_last-1-i*10 <<":"<<i << "\n";
			float time_val = (*Time)[time_last-1-i*1];
			
			data_x << QPointF(time_val,(*(*xyz_data).x_values)[time_last-1-i*1]);
			data_y << QPointF(time_val,(*(*xyz_data).y_values)[time_last-1-i*1]);
			data_z << QPointF(time_val,(*(*xyz_data).z_values)[time_last-1-i*1]);

		} else {
			break;
		}
	}
	
	curve_x->setSamples( data_x );
	curve_y->setSamples( data_y );
	curve_z->setSamples( data_z );

	replot();
	counter++;
}