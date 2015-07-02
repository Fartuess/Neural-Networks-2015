#include "Neuron.h"

Neuron::Neuron(int numberOfInputs, double threshold)
{
	this->numberOfInputs = numberOfInputs;
	inputs.reserve(numberOfInputs);
	weights.reserve(numberOfInputs);
	this->threshold = threshold;
}

Neuron::~Neuron()
{
}

bool Neuron::calculateOutput()
{
	double value = threshold;

	for (int i = 0; i < numberOfInputs; i++)
	{
		value += inputs[i] * weights[i];
	}

	return value >= 0;
}

bool Neuron::getOutput()
{
	return output;
}