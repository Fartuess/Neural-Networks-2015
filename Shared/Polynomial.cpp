#include <QtCore\qmath.h>

#include "Polynomial.h"

Polynomial::Polynomial(QVector<QPair<double, QMap<QString, double>>> expression)
{
	this->expression = expression;
}

Polynomial::~Polynomial()
{
}

double Polynomial::calculate(QMap<QString, double>& inputs)
{
	double result = 0.0;
	//if (inputs.count() != expression.count())
	//{
	//	throw QString("Given input count is not equal to number of polynomial variables!");
	//}
	for (int i = 0; i < expression.count(); i++)
	{
		QPair<double, QMap<QString, double>> subexpression = expression[i];
		double subresult = subexpression.first;
		for(QString variable : subexpression.second.keys())
		{
			if (inputs.keys().contains(variable))
			{
				subresult *= qPow(inputs[variable], subexpression.second[variable]);
			}
			else
			{
				throw QString("Polynomial does not have variable " + variable + "!");
			}
		}
		result += subresult;
	}
	return result;
}

Polynomial Polynomial::derivative(QString variable)
{
	Polynomial derivative = Polynomial(QVector<QPair<double, QMap<QString, double>>>());
	for (int i = 0; i < expression.count(); i++)
	{
		QPair<double, QMap<QString, double>> subexpression = expression[i];
		if (subexpression.second.contains(variable))
		{
			QPair<double, QMap<QString, double>> newSubexpression = QPair<double, QMap<QString, double>>();
			newSubexpression.first = subexpression.first;
			newSubexpression.first *= subexpression.second[variable];
			newSubexpression.second = subexpression.second;
			newSubexpression.second[variable] += -1.0;
			if (newSubexpression.second[variable] == 0.0)
			{
				newSubexpression.second.remove(variable);
			}
			derivative.expression.push_back(newSubexpression);
		}
		else
		{
			continue;
		}
	}
	//derivative.optimize();
	return derivative;
}

void Polynomial::optimize()
{
	///TODO: Implement polynomial optimization.
	QVector<QPair<double, QMap<QString, double>>> optimizedExpression = expression;
	for (int i = 0; i < expression.count(); i++)
	{
		for (int j = 0; j < expression.count(); j++)
		{

		}
	}
}