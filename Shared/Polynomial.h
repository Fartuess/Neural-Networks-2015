#pragma once

#include <QtCore\qmap.h>
#include <QtCore\qpair.h>
#include <QtCore\qvector.h>
#include <QtCore\qstring.h>

// TODO remove this class.

class Polynomial
{
private:
	QVector<QPair<double, QMap<QString, double>>> expression;
public:
	Polynomial(QVector<QPair<double, QMap<QString, double>>> expression);
	~Polynomial();

	double calculate(QMap<QString, double>& inputs);
	Polynomial derivative(QString variable);
private:
	void optimize();
};

