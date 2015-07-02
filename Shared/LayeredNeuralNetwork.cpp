#include "LayeredNeuralNetwork.h"
#include "LogisticNeuronActivationFunction.h"
#include <QtCore/qstring.h>
#include <QtCore\qvector.h>


LayeredNeuralNetwork::LayeredNeuralNetwork(int numberOfInputs, double beta) : AbstractNeuralNetwork(numberOfInputs)
{
	isLocked = false;
	outputNeuron = nullptr;
	this->beta = beta;
}


LayeredNeuralNetwork::~LayeredNeuralNetwork()
{
	delete outputNeuron;
	for (QVector<Neuron*>* layer : hiddenLayers)
	{
		for (Neuron* neuron : *layer)
		{
			delete neuron;
		}
		delete layer;
	}
}

QVector<Neuron*> LayeredNeuralNetwork::getLayer(int layerId)
{
	if (layerId > hiddenLayers.count()
		|| layerId < 0)
	{
		throw QString("There is no layer with index " + QString::number(layerId));
	}
	else
	{
		if (layerId == hiddenLayers.count())
		{
			QVector<Neuron*> layer;
			layer.push_back(outputNeuron);
			return layer;
		}
		return QVector<Neuron*>(*hiddenLayers[layerId]);
	}
}

void LayeredNeuralNetwork::lock()
{
	if (!isLocked)
	{
		isLocked = true;
		if (outputNeuron != nullptr)
		{
			delete outputNeuron;
		}
		outputNeuron = new Neuron(hiddenLayers.last()->count());
		double random;
		random = (double)qrand() / (double)RAND_MAX;
		outputNeuron->setThreshold(random);
		for (int i = 0; i < outputNeuron->getInputCount(); i++)
		{
			random = (double)qrand() / (double)RAND_MAX;
			outputNeuron->setWeight(i, random);
		}
	}
}

void LayeredNeuralNetwork::unlock()
{
	isLocked = false;
}

void LayeredNeuralNetwork::pushBackLayer(int numberOfNeurons)
{
	if (numberOfNeurons == 0)
	{
		throw QString("Cannot add layer with no neurons");
	}
	if (isLocked)
	{
		throw QString("Cannot modify structure of locked network");
	}
	QVector<Neuron*>* layer;
	int inputNumber;
	if (hiddenLayers.isEmpty())
	{
		inputNumber = numberOfInputs;
	}
	else
	{
		inputNumber = hiddenLayers.last()->count();
	}
	layer = generateLayer(numberOfNeurons, inputNumber);
	
	hiddenLayers.push_back(layer);
}

void LayeredNeuralNetwork::pushFrontLayer(int numberOfNeurons)
{
	if (numberOfNeurons == 0)
	{
		throw QString("Cannot add layer with no neurons");
	}
	if (isLocked)
	{
		throw QString("Cannot modify structure of locked network");
	}
	QVector<Neuron*>* layer = generateLayer(numberOfNeurons, numberOfInputs);
	
	if (!hiddenLayers.isEmpty())
	{
		int secondNumberOfNeurons = hiddenLayers.first()->count();
		QVector<Neuron*>* secondLayer = generateLayer(secondNumberOfNeurons, numberOfNeurons);
		while (!hiddenLayers.first()->isEmpty())
		{
			Neuron* deletedNeuron = hiddenLayers.first()->takeFirst();
			delete deletedNeuron;
		}
		QVector<Neuron*>* deletedLayer = hiddenLayers.takeFirst();
		delete deletedLayer;

		hiddenLayers.push_front(secondLayer);
	}
	hiddenLayers.push_front(layer);
}

void LayeredNeuralNetwork::insertLayerAt(int index, int numberOfNeurons)
{
	if (numberOfNeurons == 0)
	{
		throw QString("Cannot add layer with no neurons");
	}
	if (isLocked)
	{
		throw QString("Cannot modify structure of locked network");
	}
	if (hiddenLayers.count() < index)
	{
		throw QString("Cannot add layer at index " + QString::number(index) + " as network currently have only " + QString::number(hiddenLayers.count()) + " layer");
	}
	if (index < 0)
	{
		throw QString("Cannot add layer at negative index");
	}
	if (index == 0)
	{
		pushFrontLayer(numberOfNeurons);
	}
	else if (index == hiddenLayers.count())
	{
		pushBackLayer(numberOfNeurons);
	}
	else
	{
		QVector<Neuron*>* layer = generateLayer(numberOfNeurons, hiddenLayers[index - 1]->count());

		int secondNumberOfNeurons = hiddenLayers[index]->count();
		QVector<Neuron*>* secondLayer = generateLayer(secondNumberOfNeurons, numberOfNeurons);
		while (!hiddenLayers[index]->isEmpty())
		{
			Neuron* deletedNeuron = hiddenLayers[index]->takeFirst();
			delete deletedNeuron;
		}
		QVector<Neuron*>* deletedLayer = hiddenLayers.takeAt(index);
		delete deletedLayer;

		hiddenLayers.insert(index, secondLayer);
		hiddenLayers.insert(index, layer);
	}
}

double LayeredNeuralNetwork::calculateOutput()
{
	if (!isLocked)
	{
		lock();
	}
	for (int i = 0; i < hiddenLayers.count(); i++)
	{
		calculateLayerOutput(i);
	}
	outputNeuron->setInputs(getLayerOutput(hiddenLayers.count() - 1));
	outputNeuron->calculateOutput();
	return outputNeuron->getOutput();
}

double LayeredNeuralNetwork::getOutput()
{
	if (!isLocked)
	{
		lock();
		calculateOutput();
	}
	return outputNeuron->getOutput();
}

void LayeredNeuralNetwork::learnSteps(AbstractLayerNeuralNetworkLearn& learningStrategy, QList<NeuronInputs>& trainingInputs, QList<bool>& trainingOutputs, int steps)
{
	for (int i = 0; i < steps; i++)
	{
		learningStrategy.learn(this, trainingInputs, trainingOutputs);
	}
}

int LayeredNeuralNetwork::learnErrorThreshold(AbstractLayerNeuralNetworkLearn& learningStrategy, QList<NeuronInputs>& trainingInputs, QList<bool>& trainingOutputs, double errorThreshold)
{
	bool changed;
	int iterationCounter = 0;
	do
	{
		changed = false;
		iterationCounter++;
		QVector<double> previousWeights;
		for (QVector<Neuron*>* layer : hiddenLayers)
		{
			for (Neuron* neuron : *layer)
			{
				previousWeights.push_back(neuron->getThreshold());
				previousWeights += neuron->getWeights().first;
			}
		}
		previousWeights.push_back(outputNeuron->getThreshold());
		previousWeights += outputNeuron->getWeights().first;

		learningStrategy.learn(this, trainingInputs, trainingOutputs);

		QVector<double> currentWeights;
		for (QVector<Neuron*>* layer : hiddenLayers)
		{
			for (Neuron* neuron : *layer)
			{
				currentWeights.push_back(neuron->getThreshold());
				currentWeights += neuron->getWeights().first;
			}
		}
		currentWeights.push_back(outputNeuron->getThreshold());
		currentWeights += outputNeuron->getWeights().first;

		for (int i = 0; i < previousWeights.count(); i++)
		{
			if (qAbs(previousWeights[i] - currentWeights[i]) > errorThreshold)
			{
				changed = true;
				break;
			}
		}
	} while (changed == true);
	return iterationCounter - 1;
}

QVector<Neuron*>* LayeredNeuralNetwork::generateLayer(int neuronNumber, int inputNumber)
{
	QVector<Neuron*>* layer = new QVector<Neuron*>();

	for (int i = 0; i < neuronNumber; i++)
	{
		Neuron* neuron = new Neuron(inputNumber, new LogisticNeuronActivationFunction(beta));

		double random;
		random = (double)qrand() / (double)RAND_MAX;
		neuron->setThreshold(random);
		for (int i = 0; i < neuron->getInputCount(); i++)
		{
			random = (double)qrand() / (double)RAND_MAX;
			neuron->setWeight(i, random);
		}

		layer->push_back(neuron);
	}

	return layer;
}

QVector<double> LayeredNeuralNetwork::calculateLayerOutput(int index)
{
	if (index > numberOfInputs)
	{
		throw QString("There is no layer with that high index.");
	}
	QVector<double> layerInputs;
	if (index == 0)
	{
		layerInputs = inputs;
	}
	else
	{
		layerInputs = getLayerOutput(index - 1);
	}
	for (Neuron* neuron : *hiddenLayers[index])
	{
		neuron->setInputs(layerInputs);
		neuron->calculateOutput();
	}
	return getLayerOutput(index);
}

QVector<double> LayeredNeuralNetwork::getLayerOutput(int index)
{
	if (index > numberOfInputs
		|| index < 0)
	{
		throw QString("There is no layer with that index.");
	}
	QVector<double> layerOutputs;
	for (Neuron* neuron : *hiddenLayers[index])
	{
		layerOutputs.push_back(neuron->getOutput());
	}
	return layerOutputs;
}