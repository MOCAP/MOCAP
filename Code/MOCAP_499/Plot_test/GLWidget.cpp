#include "GLWidget.h"
#include <QMouseEvent>
#include <QWheelEvent>
#include <stdio.h>
#include <iostream>
#include <QTimer>


using namespace std;

//http://qt-project.org/doc/qt-4.8/opengl-cube.html




GlWidget::GlWidget(QQuaternion * orientation , QWidget *parent)
: QGLWidget(QGLFormat(/* Additional format options */), parent)
{
	alpha = 0;
    beta = 0;
    distance = 15;
	this->orientation = orientation;
	QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(100);
	show();
}
void QuaternionToEuler2(QQuaternion q1, vector<float> * euler)
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


GlWidget::~GlWidget()
{
}


QSize GlWidget::sizeHint() const
{
return QSize(640, 480);
}

void GlWidget::initializeGL()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	qglClearColor(QColor(Qt::black));
	shaderProgram.addShaderFromSourceFile(QGLShader::Vertex, ":/vertexShader.vsh");
	shaderProgram.addShaderFromSourceFile(QGLShader::Fragment, ":/fragmentShader.fsh");
	shaderProgram.link();

	//Working Diamond
	//vertices << QVector3D(1, 0, -2) << QVector3D(0, 1, -2) << QVector3D(0, -1, -2) << vertices << QVector3D(-1, 0, -2) << QVector3D(0, -1, -2) << QVector3D(0, 1, -2) ; //Front

	
	//Z
    vertices << QVector3D(-0.5, -0.5, 5) << QVector3D( 0.5, -0.5, 5) << QVector3D( 0.5,  0.5,5) // Front
             << QVector3D( 0.5,  0.5, 5) << QVector3D(-0.5,  0.5, 5) << QVector3D(-0.5, -0.5, 5)

             << QVector3D( 0.5, -0.5, -0.5) << QVector3D(-0.5, -0.5, -0.5) << QVector3D(-0.5,  0.5, -0.5) // Back
             << QVector3D(-0.5,  0.5, -0.5) << QVector3D( 0.5,  0.5, -0.5) << QVector3D( 0.5, -0.5, -0.5)

             << QVector3D(-0.5,  0.5, -0.5) << QVector3D(-0.5, -0.5, -0.5) << QVector3D(-0.5,  0.5, 5) // Left
             << QVector3D(-0.5, -0.5, -0.5) << QVector3D(-0.5,  -0.5, 5)   << QVector3D(-0.5,  0.5, 5) 

		     << QVector3D(0.5,  0.5, 5) << QVector3D(0.5, -0.5, -0.5) << QVector3D(0.5,  0.5, -0.5) // Right
             << QVector3D(0.5,  0.5, 5) << QVector3D(0.5,  -0.5, 5) << QVector3D(0.5, -0.5, -0.5)

             << QVector3D(-0.5,  0.5, 5) << QVector3D( 0.5,  0.5, 5) << QVector3D( 0.5,  0.5, -0.5) // Top
             << QVector3D( 0.5,  0.5, -0.5) << QVector3D(-0.5,  0.5, -0.5) << QVector3D(-0.5,  0.5, 5)

             << QVector3D(-0.5, -0.5, -0.5) << QVector3D( 0.5, -0.5, -0.5) << QVector3D( 0.5, -0.5, 5) // Bottom
             << QVector3D( 0.5, -0.5, 5) << QVector3D(-0.5, -0.5, 5) << QVector3D(-0.5, -0.5, -0.5);


	// Y Cube
    vertices << QVector3D(-0.5, 0.5, 0.5) << QVector3D( 0.5, 0.5, 0.5) << QVector3D( 0.5, 5, 0.5) // Front
             << QVector3D( 0.5,  5, 0.5) << QVector3D(-0.5,  5, 0.5) << QVector3D(-0.5, 0.5, 0.5)
			 
             << QVector3D( 0.5, 0.5, -0.5) << QVector3D(-0.5, 0.5, -0.5) << QVector3D(-0.5,  5, -0.5) // Back
             << QVector3D(-0.5,  5, -0.5) << QVector3D( 0.5,  5, -0.5) << QVector3D( 0.5, 0.5, -0.5)
			 
             << QVector3D(-0.5, 0.5, -0.5) << QVector3D(-0.5, 0.5, 0.5) << QVector3D(-0.5,  5, 0.5) // Left
             << QVector3D(-0.5,  5, 0.5) << QVector3D(-0.5,  5, -0.5) << QVector3D(-0.5, 0.5, -0.5)
			 
             << QVector3D( 0.5, 0.5, 0.5) << QVector3D( 0.5, 0.5, -0.5) << QVector3D( 0.5,  5, -0.5) // Right
             << QVector3D( 0.5,  5, -0.5) << QVector3D( 0.5,  5, 0.5) << QVector3D( 0.5, 0.5, 0.5)
			 
             << QVector3D(-0.5,  5, 0.5) << QVector3D( 0.5,  5, 0.5) << QVector3D( 0.5,  5, -0.5) // Top
             << QVector3D( 0.5,  5, -0.5) << QVector3D(-0.5,  5, -0.5) << QVector3D(-0.5,  5, 0.5)
			 
             << QVector3D(-0.5, 0.5, -0.5) << QVector3D( 0.5, 0.5, -0.5) << QVector3D( 0.5, 0.5, 0.5) // Bottom
             << QVector3D( 0.5, 0.5, 0.5) << QVector3D(-0.5, 0.5, 0.5) << QVector3D(-0.5, 0.5, -0.5);
	
	//X
    vertices << QVector3D(0.5, -0.5, 0.5) << QVector3D( 5, -0.5, 0.5) << QVector3D( 5,  0.5, 0.5) // Front
             << QVector3D( 5,  0.5, 0.5) << QVector3D(0.5,  0.5, 0.5) << QVector3D(0.5, -0.5, 0.5)
			 
             << QVector3D( 5, -0.5, -0.5) << QVector3D(0.5, -0.5, -0.5) << QVector3D(0.5,  0.5, -0.5) // Back
             << QVector3D(0.5,  0.5, -0.5) << QVector3D( 5,  0.5, -0.5) << QVector3D( 5, -0.5, -0.5)
			 
             << QVector3D(0.5, -0.5, -0.5) << QVector3D(0.5, -0.5, -0.5) << QVector3D(0.5,  0.5, -0.5) // Left
             << QVector3D(0.5,  0.5, 0.5) << QVector3D(0.5,  0.5, -0.5) << QVector3D(0.5, -0.5, -0.5)
			 
             << QVector3D( 5, -0.5, 0.5) << QVector3D( 5, -0.5, -0.5) << QVector3D( 5,  0.5, -0.5) // Right
             << QVector3D( 5,  0.5, -0.5) << QVector3D( 5,  0.5, 0.5) << QVector3D( 5, -0.5, 0.5)
			 
             << QVector3D(0.5,  0.5, 0.5) << QVector3D( 5,  0.5, 0.5) << QVector3D( 5,  0.5, -0.5) // Top
             << QVector3D( 5,  0.5, -0.5) << QVector3D(0.5,  0.5, -0.5) << QVector3D(0.5,  0.5, 0.5)

             << QVector3D(0.5, -0.5, -0.5) << QVector3D( 5, -0.5, -0.5) << QVector3D( 5, -0.5, 0.5) // Bottom
             << QVector3D( 5, -0.5, 0.5) << QVector3D(0.5, -0.5, 0.5) << QVector3D(0.5, -0.5, -0.5);
	
		//Z
	    colors << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) // Front
           << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) << QVector3D(1, 0, 0)

           << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) // Back
           << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) << QVector3D(1, 0, 0)
		   << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) // Left
           << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) << QVector3D(1, 0, 0)
		   << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) // Right
           << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) << QVector3D(1, 0, 0)
		   << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) // Top
           << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) << QVector3D(1, 0, 0)
		   << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) // Bottom
           << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) << QVector3D(1, 0, 0);
		
		//Y
		colors << QVector3D(0, 1, 0) << QVector3D(0, 1, 0) << QVector3D(0, 1, 0) // Front
           << QVector3D(0, 1, 0) << QVector3D(0, 1, 0) << QVector3D(0, 1, 0)

		   << QVector3D(0, 1, 0) << QVector3D(0, 1, 0) << QVector3D(0, 1, 0) // Back
           << QVector3D(0, 1, 0) << QVector3D(0, 1, 0) << QVector3D(0, 1, 0)
		   << QVector3D(0, 1, 0) << QVector3D(0, 1, 0) << QVector3D(0, 1, 0) // Left
           << QVector3D(0, 1, 0) << QVector3D(0, 1, 0) << QVector3D(0, 1, 0)
		   << QVector3D(0, 1, 0) << QVector3D(0, 1, 0) << QVector3D(0, 1, 0) // Right
           << QVector3D(0, 1, 0) << QVector3D(0, 1, 0) << QVector3D(0, 1, 0)
		   << QVector3D(0, 1, 0) << QVector3D(0, 1, 0) << QVector3D(0, 1, 0) // Top
           << QVector3D(0, 1, 0) << QVector3D(0, 1, 0) << QVector3D(0, 1, 0)
		   << QVector3D(0, 1, 0) << QVector3D(0, 1, 0) << QVector3D(0, 1, 0) // Bottom
           << QVector3D(0, 1, 0) << QVector3D(0, 1, 0) << QVector3D(0, 1, 0);

		//X
		colors << QVector3D(0, 0, 1) << QVector3D(0, 0, 1) << QVector3D(0, 0, 1) // Front
           << QVector3D(0, 0, 1) << QVector3D(0, 0, 1) << QVector3D(0, 0, 1)
		   << QVector3D(0, 0, 1) << QVector3D(0, 0, 1) << QVector3D(0, 0, 1) // Back
           << QVector3D(0, 0, 1) << QVector3D(0, 0, 1) << QVector3D(0, 0, 1)
		   << QVector3D(0, 0, 1) << QVector3D(0, 0, 1) << QVector3D(0, 0, 1) // Left
           << QVector3D(0, 0, 1) << QVector3D(0, 0, 1) << QVector3D(0, 0, 1)
		   << QVector3D(0, 0, 1) << QVector3D(0, 0, 1) << QVector3D(0, 0, 1) // Right
           << QVector3D(0, 0, 1) << QVector3D(0, 0, 1) << QVector3D(0, 0, 1)
		   << QVector3D(0, 0, 1) << QVector3D(0, 0, 1) << QVector3D(0, 0, 1) // Top
           << QVector3D(0, 0, 1) << QVector3D(0, 0, 1) << QVector3D(0, 0, 1)
		   << QVector3D(0, 0, 1) << QVector3D(0, 0, 1) << QVector3D(0, 0, 1) // Bottom
           << QVector3D(0, 0, 1) << QVector3D(0, 0, 1) << QVector3D(0, 0, 1);
		  
}

void GlWidget::resizeGL(int width, int height)
{
    if (height == 0) {
        height = 1;
    }

    pMatrix.setToIdentity();
    pMatrix.perspective(60.0, (float) width / (float) height, 0.001, 1000);

    glViewport(0, 0, width, height);
}

void GlWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    QMatrix4x4 mMatrix;
    QMatrix4x4 vMatrix;

	//std::vector<float> * euler_angles= new vector<float>();
	//std::cout << "State is ";QuaternionToEuler2(*orientation, euler_angles);
	
	QMatrix4x4 cameraTransformation;
    cameraTransformation.rotate(alpha, 0, 1, 0);
    cameraTransformation.rotate(beta, 1, 0, 0);
	cameraTransformation.rotate(*orientation);

    QVector3D cameraPosition = cameraTransformation * QVector3D(0, 0, distance);
    QVector3D cameraUpDirection = cameraTransformation * QVector3D(0, 1, 0);

    vMatrix.lookAt(cameraPosition, QVector3D(0, 0, 0), cameraUpDirection);
	

    shaderProgram.bind();

	 QMatrix4x4 quat_matrix;
     quat_matrix.rotate(0,0,1,0);

	 
    shaderProgram.setUniformValue("mvpMatrix", pMatrix * vMatrix * mMatrix * quat_matrix);

    shaderProgram.setAttributeArray("vertex", vertices.constData());
    shaderProgram.enableAttributeArray("vertex");

	shaderProgram.setAttributeArray("color", colors.constData());
    shaderProgram.enableAttributeArray("color");

	glRotatef(90, 0, 0, 1.0);
    glDrawArrays(GL_TRIANGLES, 0, vertices.size());

    shaderProgram.disableAttributeArray("vertex");

    shaderProgram.disableAttributeArray("color");

    shaderProgram.release();
}

void GlWidget::mousePressEvent(QMouseEvent *event)
{
    lastMousePosition = event->pos();

    event->accept();
}

void GlWidget::mouseMoveEvent(QMouseEvent *event)
{
    int deltaX = event->x() - lastMousePosition.x();
    int deltaY = event->y() - lastMousePosition.y();

    if (event->buttons() & Qt::LeftButton) {
        alpha -= deltaX;
        while (alpha < 0) {
            alpha += 360;
        }
        while (alpha >= 360) {
            alpha -= 360;
        }

        beta -= deltaY;
        if (beta < -90) {
            beta = -90;
        }
        if (beta > 90) {
            beta = 90;
        }

        updateGL();
    }

    lastMousePosition = event->pos();

    event->accept();
}

void GlWidget::wheelEvent(QWheelEvent *event)
{
    int delta = event->delta();

    if (event->orientation() == Qt::Vertical) {
        if (delta < 0) {
            distance *= 1.1;
        } else if (delta > 0) {
            distance *= 0.9;
        }

        updateGL();
    }

    event->accept();
}