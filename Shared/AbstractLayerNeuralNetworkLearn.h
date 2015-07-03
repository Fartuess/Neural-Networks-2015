#pragma once

#include "AbstractNeuralNetwork.h"

/**
  * Abstract class for learning neural network.
  */
class AbstractLayerNeuralNetworkLearn
{
public:

	/**
	  * Single interation of learning a neural network.
	  * @param network pointer to etwork which will be learnt.
	  * @param trainingInputs list of training input vectors.
	  * @param trainingOutputs list of expected outputs for given input vectors. 
	  */
	virtual void learn(class LayeredNeuralNetwork* network, QList<NeuronInputs>& trainingInputs, QList<bool>& trainingOutputs) = 0;
};

