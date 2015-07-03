#pragma once

#include <QtCore\qvector.h>
#include "Neuron.h"

// TODO Rename class to INeuronLearn.
/**
  * Abstract class for learning neuron.
  */
class AbstractNeuronLearn
{
public:

	/**
	  * Single interation of learning a neuron.
	  * @param neuron pointer to neuron which will be learnt.
	  * @param trainingInputs list of training input vectors.
	  * @param trainingOutputs list of expected outputs for given input vectors.
	  * @return new weights after single iteration of learning.
	  */
	virtual NeuronWeights learn(Neuron* neuron, QList<NeuronInputs>& trainingInputs, QList<bool>& trainingOutputs) = 0;
};

