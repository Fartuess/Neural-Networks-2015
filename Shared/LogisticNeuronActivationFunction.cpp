#include "LogisticNeuronActivationFunction.h"
#include "Neuron.h"

#include <QtCore/qmath.h>

LogisticNeuronActivationFunction::LogisticNeuronActivationFunction(double beta)
{
	this->beta = beta;
}


LogisticNeuronActivationFunction::~LogisticNeuronActivationFunction()
{
}

double LogisticNeuronActivationFunction::calculateOutput(Neuron* neuron)
{
	double value = neuron->getThreshold();

	for (int i = 0; i < neuron->getInputCount(); i++)
	{
		value += neuron->getInput(i) * neuron->getWeight(i);
	}

	return (1.0 / (1.0 + qExp(-value * beta)));
}