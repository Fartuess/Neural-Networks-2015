#pragma once
#include <QtCore\qvector.h>

class Neuron
{
public:
	double threshold;
	QVector<double> inputs;
	QVector<double> weights;
private:
	int numberOfInputs;
	bool output;
public:
	Neuron(int numberOfInputs, double threshold = 1.0);
	~Neuron();

	bool calculateOutput();
	bool getOutput();
};