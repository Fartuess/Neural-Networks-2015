#include "AbstractNeuralNetwork.h"
#include <QtCore\qstring.h>

AbstractNeuralNetwork::AbstractNeuralNetwork(int numberOfInputs)
{
	this->numberOfInputs = numberOfInputs;
	inputs.resize(numberOfInputs);
}


AbstractNeuralNetwork::~AbstractNeuralNetwork()
{
}

int AbstractNeuralNetwork::getInputCount()
{
	return numberOfInputs;
}

double AbstractNeuralNetwork::getInput(int index)
{
	if (index < numberOfInputs)
	{
		return inputs[index];
	}
	else
	{
		throw QString("Couldn't get network input at index " + QString::number(index) + " as it have only " + QString::number(numberOfInputs) + "inputs.");
	}
}

void AbstractNeuralNetwork::setInput(int index, double value)
{
	if (index < numberOfInputs)
	{
		inputs[index] = value;
	}
	else
	{
		throw QString("Couldn't set network input at index " + QString::number(index) + " as it have only " + QString::number(numberOfInputs) + "inputs.");
	}
}

NeuronInputs AbstractNeuralNetwork::getInputs()
{
	return inputs;
}

void AbstractNeuralNetwork::setInputs(NeuronInputs& inputs)
{
	if (inputs.count() != numberOfInputs)
	{
		throw QString("Can't set input values because number of new values is different than number of network inputs");
	}
	else
	{
		this->inputs = inputs;
	}
}