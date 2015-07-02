#include "BackpropagationLayerNeuralNetworkLearn.h"
#include <QtCore\qstring.h>

BackpropagationLayerNeuralNetworkLearn::BackpropagationLayerNeuralNetworkLearn()
{
}


BackpropagationLayerNeuralNetworkLearn::~BackpropagationLayerNeuralNetworkLearn()
{
}

void BackpropagationLayerNeuralNetworkLearn::learn(LayeredNeuralNetwork* network, QList<NeuronInputs>& trainingInputs, QList<bool>& trainingOutputs)
{
	///TODO: implement it!
	if (trainingInputs.count() != trainingOutputs.count())
	{
		throw QString("Input and output lists have different count!");
	}
	for (int input = 0; input < trainingInputs.count(); input++)
	{
		if (trainingInputs[input].count() != network->getInputCount())
		{
			throw QString("Some training vectors have different number of input than trained network itself");
		}
		network->setInputs(trainingInputs[input]);
		bool output = network->calculateOutput();
		QVector<QVector<NeuronWeights>> oldWeights;
		NeuronWeights oldOutputWeights;

		//Saving previous neuron data to work with.
		oldOutputWeights = network->outputNeuron->getWeights();
		for (int layer = 0; layer < network->hiddenLayers.count(); layer++)
		{
			oldWeights.push_back(QVector<NeuronWeights>());
			for (int neuron = 0; neuron < network->hiddenLayers[layer]->count(); neuron++)
			{
				oldWeights[layer].push_back((*network->hiddenLayers[layer])[neuron]->getWeights());
			}
		}

		QVector<double> previousLayerErrors;
		QVector<double> currentLayerErrors;
		//Learning
		currentLayerErrors.push_back(trainingOutputs[input] - output);
		///TODO: learn output neuron!
		for (int layer = network->hiddenLayers.count() - 1; layer >= 0; layer--)
		{
			previousLayerErrors = currentLayerErrors;
			currentLayerErrors.clear();
			for (int neuron = 0; neuron < network->hiddenLayers[layer]->count(); neuron++)
			{
				if (layer == network->hiddenLayers.count() - 1)
				{
					currentLayerErrors[neuron] = network->outputNeuron->getWeight(neuron);
				}
				else
				{
					currentLayerErrors[neuron] = 0;
					for (int parrentNeuron = 0; parrentNeuron < network->hiddenLayers[layer + 1]->count(); parrentNeuron++)
					{
						currentLayerErrors[neuron] += (*network->hiddenLayers[layer + 1])[parrentNeuron]->getWeight(neuron) * previousLayerErrors[parrentNeuron];
					}
				}
				///TODO: learn this neuron!
			}
		}
	}

}