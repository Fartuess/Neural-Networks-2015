#pragma once

#include "Neuron.h"

/**
  * Abstract neural network class.
  */
class AbstractNeuralNetwork
{
public:

	/**
	  * Constructor for creating neural network.
	  * @param numberOfInputs number of inputs of network.
	  */
	AbstractNeuralNetwork(int numberOfInputs);

	/**
	  * Default destructor.
	  */
	~AbstractNeuralNetwork();

	/**
	  * Gets number of network inputs.
	  */
	int getInputCount();

	/**
	  * Gets value of asked input.
	  * @param index index of asked input.
	  * @return value of asked input.
	  */
	double getInput(int index);

	/**
	  * Sets value for given input.
	  * @param index index of input to change.
	  * @param value value of asked input.
	  */
	void setInput(int index, double value);

	/**
	  * Gets values of all neuron inputs in form of a vector.
	  * @return vector of neuron inputs.
	  */
	NeuronInputs getInputs();

	/**
	  * Sets values of all neuron inputs.
	  * @param inputs vector of neuron input values to be set.
	  */
	void setInputs(NeuronInputs& inputs);

	/**
	  * Abstract methods for calculating and returning output.
	  * @return output of neuron.
	  */
	virtual double calculateOutput() = 0;

	/**
	  * Abstract method that gets previously calculated output.
	  * @return output of neuron.
	  */
	virtual double getOutput() = 0;

protected:
	int numberOfInputs;
	QVector<double> inputs;
};