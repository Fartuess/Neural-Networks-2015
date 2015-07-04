#pragma once

#include "INeuronActivationFunction.h"

/**
  * Class for logistic activation function of neuron.
  */
class LogisticNeuronActivationFunction : public INeuronActivationFunction
{
public:
	/**
	  * Constructor
	  * @param beta exponent scalar of logistic function.
	  */
	LogisticNeuronActivationFunction(double beta);

	/**
	  * Default Destructor.
	  */
	~LogisticNeuronActivationFunction();

	/**
	  * Calculates logistic activation function output.
	  * @param neuron pointer to neuron for which it output will be calculated.
	  * @return calculated output value.
	  */
	double calculateOutput(Neuron* neuron) override;

private:
	double beta;
};

