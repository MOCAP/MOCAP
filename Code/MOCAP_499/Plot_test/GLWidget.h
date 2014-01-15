#ifndef _GLWIDGET_H
#define _GLWIDGET_H

#include <QtOpenGL/QGLWidget>
#include <QGLShaderProgram>

class GlWidget : public QGLWidget
{
	Q_OBJECT
public:
	GlWidget(QQuaternion * orientation,
				QWidget *parent = 0);
	~GlWidget();
	QSize sizeHint() const;
protected:
	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();
	void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
private:
	QMatrix4x4 pMatrix;
	QGLShaderProgram shaderProgram;
	QVector<QVector3D> vertices;
	QQuaternion * orientation;
	QVector<QVector3D> colors;

	double alpha;
    double beta;
    double distance;
    QPoint lastMousePosition;

};

#endif