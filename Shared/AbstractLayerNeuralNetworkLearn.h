#pragma once

#include "AbstractNeuralNetwork.h"

/**
  * Abstract class for learning neural network.
  */
class AbstractLayerNeuralNetworkLearn
{
public:
	//AbstractLayerNeuralNetworkLearn();
	//~AbstractLayerNeuralNetworkLearn();

	/**
	  * 
	  */
	virtual void learn(class LayeredNeuralNetwork* network, QList<NeuronInputs>& trainingInputs, QList<bool>& trainingOutputs) = 0;
};

