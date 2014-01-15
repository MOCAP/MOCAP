#ifndef PLOT_TEST_H
#define PLOT_TEST_H

#include <QtWidgets/QMainWindow>
#include "ui_plot_test.h"

class Plot_test : public QMainWindow
{
	Q_OBJECT

public:
	Plot_test(QWidget *parent = 0);
	~Plot_test();

private:
	Ui::Plot_testClass ui;
};

#endif // PLOT_TEST_H
