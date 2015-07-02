#include <QtCore/QCoreApplication>
#include <QtCore/qvector.h>
#include <QtCore/qpair.h>
#include <QtCore/qmap.h>
#include <QtCore/qdebug.h>

#include "Polynomial.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	//QVector<QPair<double, QMap<QString, double>>> expression = QVector<QPair<double, QMap<QString, double>>>();
	//QPair<double, QMap<QString, double>> subexpression;
	//QMap<QString, double> subexpressionHelper;
	//
	//{
	//	subexpression = QPair<double, QMap<QString, double>>();
	//	subexpressionHelper = QMap<QString, double>();
	//
	//	subexpressionHelper["x"] = 2;
	//
	//	subexpression.first = 2.0;
	//	subexpression.second = subexpressionHelper;
	//	expression.push_back(subexpression);
	//}
	//
	//{
	//	subexpression = QPair<double, QMap<QString, double>>();
	//	subexpressionHelper = QMap<QString, double>();
	//
	//	subexpressionHelper["y"] = 2;
	//	subexpressionHelper["z"] = 2;
	//
	//	subexpression.first = 2.0;
	//	subexpression.second = subexpressionHelper;
	//	expression.push_back(subexpression);
	//}
	//
	//{
	//	subexpression = QPair<double, QMap<QString, double>>();
	//	subexpressionHelper = QMap<QString, double>();
	//
	//	subexpressionHelper["x"] = 1;
	//	subexpressionHelper["y"] = 1;
	//
	//	subexpression.first = 2.0;
	//	subexpression.second = subexpressionHelper;
	//	expression.push_back(subexpression);
	//}
	//
	//{
	//	subexpression = QPair<double, QMap<QString, double>>();
	//	subexpressionHelper = QMap<QString, double>();
	//
	//	subexpressionHelper["y"] = 1;
	//	subexpressionHelper["z"] = 1;
	//
	//	subexpression.first = 2.0;
	//	subexpression.second = subexpressionHelper;
	//	expression.push_back(subexpression);
	//}
	//
	//{
	//	subexpression = QPair<double, QMap<QString, double>>();
	//	subexpressionHelper = QMap<QString, double>();
	//
	//	subexpressionHelper["x"] = 1;
	//
	//	subexpression.first = 2.0;
	//	subexpression.second = subexpressionHelper;
	//	expression.push_back(subexpression);
	//}
	//
	//{
	//	subexpression = QPair<double, QMap<QString, double>>();
	//	subexpressionHelper = QMap<QString, double>();
	//
	//	subexpression.first = 3.0;
	//	subexpression.second = subexpressionHelper;
	//	expression.push_back(subexpression);
	//}
	//
	//Polynomial polynomial1 = Polynomial(expression);
	//Polynomial derivative1_x = polynomial1.derivative("x");
	//Polynomial derivative1_y = polynomial1.derivative("y");
	//Polynomial derivative1_z = polynomial1.derivative("z");
	//
	//
	//expression = QVector<QPair<double, QMap<QString, double>>>();
	//{
	//	subexpression = QPair<double, QMap<QString, double>>();
	//	subexpressionHelper = QMap<QString, double>();
	//
	//	subexpressionHelper["x"] = 4;
	//
	//	subexpression.first = 3.0;
	//	subexpression.second = subexpressionHelper;
	//	expression.push_back(subexpression);
	//}
	//
	//{
	//	subexpression = QPair<double, QMap<QString, double>>();
	//	subexpressionHelper = QMap<QString, double>();
	//
	//	subexpressionHelper["x"] = 3;
	//
	//	subexpression.first = 4.0;
	//	subexpression.second = subexpressionHelper;
	//	expression.push_back(subexpression);
	//}
	//
	//{
	//	subexpression = QPair<double, QMap<QString, double>>();
	//	subexpressionHelper = QMap<QString, double>();
	//
	//	subexpressionHelper["x"] = 2;
	//
	//	subexpression.first = -12.0;
	//	subexpression.second = subexpressionHelper;
	//	expression.push_back(subexpression);
	//}
	//
	//{
	//	subexpression = QPair<double, QMap<QString, double>>();
	//	subexpressionHelper = QMap<QString, double>();
	//
	//	subexpressionHelper["y"] = 2;
	//
	//	subexpression.first = 12.0;
	//	subexpression.second = subexpressionHelper;
	//	expression.push_back(subexpression);
	//}
	//
	//{
	//	subexpression = QPair<double, QMap<QString, double>>();
	//	subexpressionHelper = QMap<QString, double>();
	//
	//	subexpressionHelper["y"] = 1;
	//
	//	subexpression.first = -24.0;
	//	subexpression.second = subexpressionHelper;
	//	expression.push_back(subexpression);
	//}
	//
	//Polynomial polynomial2 = Polynomial(expression);
	//Polynomial derivative2_x = polynomial2.derivative("x");
	//Polynomial derivative2_y = polynomial2.derivative("y");
	//
	//QMap<QString, double> variables = QMap<QString, double>();
	//variables["x"] = 1.0;
	//variables["y"] = 1.0;
	//variables["z"] = 1.0;
	//QMap<QString, double> newVariables = QMap<QString, double>(variables);

	double constantScale = 0.01;
	double epsilon = 0.0000001;

	double x = 4.0;
	double y = -1.0;
	double z = 2.0;
	double x2, y2, z2;
	double dx, dy, dz;
	double maxDistance;
	do
	{
		dx = 4*x - 2*y - 2;
		dy = 4*y - 2*x - 2*z;
		dz = 2*z - 2*y;

		x2 = x - constantScale * dx;
		y2 = y - constantScale * dy;
		z2 = z - constantScale * dz;

		//newVariables["x"] = x2;
		//newVariables["y"] = y2;
		//newVariables["z"] = z2;

		maxDistance = 0.0;
		//for (QString variable : variables.keys())
		//{
		//	maxDistance = qMax(maxDistance, qAbs(variables[variable] - newVariables[variable]));
		//}
		maxDistance = qMax(maxDistance, qAbs(x - x2));
		maxDistance = qMax(maxDistance, qAbs(y - y2));
		maxDistance = qMax(maxDistance, qAbs(z - z2));
		//variables = newVariables;
		x = x2;
		y = y2;
		z = z2;
	} while (maxDistance > epsilon);
	qDebug() << "Funkcja nr 1:";
	qDebug() << "x: " + QString::number(x, 'f', 3);
	qDebug() << "y: " + QString::number(y, 'f', 3);
	qDebug() << "z: " + QString::number(z, 'f', 3);
	qDebug() << "f(x,y,z): " + QString::number(2*x*x + 2*y*y + z*z - 2*x*y - 2*y*z - 2*x + 3, 'f', 3);
	x = 4.0;
	y = -1.0;
	do
	{
		dx = 12*x*x*x + 12*x*x - 24*x;
		dy = 24*y - 24;

		x2 = x - constantScale * dx;
		y2 = y - constantScale * dy;

		maxDistance = 0.0;

		maxDistance = qMax(maxDistance, qAbs(x - x2));
		maxDistance = qMax(maxDistance, qAbs(y - y2));

		x = x2;
		y = y2;

	} while (maxDistance > epsilon);
	qDebug() << "Funkcja nr 2:";
	qDebug() << "x: " + QString::number(x, 'f', 3);
	qDebug() << "y: " + QString::number(y, 'f', 3);
	qDebug() << "g(x,y): " + QString::number(3*x*x*x*x + 4*x*x*x - 12*x*x + 12*y*y -24*y, 'f', 3);

	return a.exec();
}
