#pragma once
#include "AbstractNeuralNetwork.h"
#include "AbstractLayerNeuralNetworkLearn.h"

class LayeredNeuralNetwork : public AbstractNeuralNetwork
{
public:
	///TODO: remove class friendship, create helper methods.
	friend class AbstractLayerNeuralNetworkLearn;
	friend class BackpropagationLayerNeuralNetworkLearn;
protected:
	bool isLocked;
	Neuron* outputNeuron;
	QVector<QVector<Neuron*>*> hiddenLayers;

	double beta;
public:
	LayeredNeuralNetwork(int numberOfInputs, double beta = 1.0);
	~LayeredNeuralNetwork();

	QVector<Neuron*> getLayer(int layerId);

	void lock();
	void unlock();
	void pushBackLayer(int numberOfNeurons);
	void pushFrontLayer(int numberOfNeurons);
	void insertLayerAt(int index, int numberOfNeurons);

	double calculateOutput() override;
	double getOutput() override;

	void learnSteps(AbstractLayerNeuralNetworkLearn& learningStrategy, QList<QVector<double>>& trainingInputs, QList<bool>& trainingOutputs, int steps);
	int learnErrorThreshold(AbstractLayerNeuralNetworkLearn& learningStrategy, QList<QVector<double>>& trainingInputs, QList<bool>& trainingOutputs, double errorThreshold);

protected:
	QVector<Neuron*>* generateLayer(int neuronNumber, int inputNumber);
	void clearLayer(QVector<Neuron*>* layer);

	QVector<double> calculateLayerOutput(int index);
	QVector<double> getLayerOutput(int index);
};
