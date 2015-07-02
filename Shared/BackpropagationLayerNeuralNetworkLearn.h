#pragma once
#include "LayeredNeuralNetwork.h"

class BackpropagationLayerNeuralNetworkLearn : public AbstractLayerNeuralNetworkLearn
{
public:
	BackpropagationLayerNeuralNetworkLearn();
	~BackpropagationLayerNeuralNetworkLearn();

	void learn(LayeredNeuralNetwork* network, QList<NeuronInputs>& trainingInputs, QList<bool>& trainingOutputs) override;
};

