#pragma once

#include "LayeredNeuralNetwork.h"

/**
  * Class for learning neural network by method of Backpropagation - WARNING! UNFINISHED!
  */
class BackpropagationLayerNeuralNetworkLearn : public AbstractLayerNeuralNetworkLearn
{
public:

	/**
	  * Default constructor.
	  */
	BackpropagationLayerNeuralNetworkLearn();

	/**
	  * Default destructor.
	  */
	~BackpropagationLayerNeuralNetworkLearn();

	/**
	  * Single interation of learning a neural network using backpropagation method - WARNING! UNFINISHED!
	  * @param network pointer to etwork which will be learnt.
	  * @param trainingInputs list of training input vectors.
	  * @param trainingOutputs list of expected outputs for given input vectors.
	  */
	void learn(LayeredNeuralNetwork* network, QList<NeuronInputs>& trainingInputs, QList<bool>& trainingOutputs) override;
};

