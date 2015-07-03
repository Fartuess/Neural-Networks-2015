#pragma once
#include "AbstractNeuralNetwork.h"
#include "AbstractLayerNeuralNetworkLearn.h"

/**
  * Class for multilayered neural network.
  */
class LayeredNeuralNetwork : public AbstractNeuralNetwork
{
public:
	///TODO: remove class friendship, create helper methods.
	friend class AbstractLayerNeuralNetworkLearn;
	friend class BackpropagationLayerNeuralNetworkLearn;

	/**
	  * Constructor for creating layered neural network.
	  * @param numberOfInputs number of inputs of network.
	  * @param beta exponent scalar for logistic activation function used for neurons from this network.
	  */
	LayeredNeuralNetwork(int numberOfInputs, double beta = 1.0);

	/**
	  * Default destructor.
	  */
	~LayeredNeuralNetwork();

	/**
	  * Gets vector of neurons in asked layer.
	  * @param layerId Id of asked layer.
	  * @return vector of pointers to neurons.
	  */
	QVector<Neuron*> getLayer(int layerId);

	/**
	  * Locks and finishes creation of network. You cannot add new layers for locked network.
	  */
	void lock();

	/**
	  * Unlocks network, so new layers can be added.
	  */
	void unlock();

	/**
	  * Adds layer to the back of network.
	  * @param numberOfNeurons number of neurons which will be in new layer.
	  */
	void pushBackLayer(int numberOfNeurons);

	/**
	  * Adds layer to the front of network.
	  * @param numberOfNeurons number of neurons which will be in new layer.
	  */
	void pushFrontLayer(int numberOfNeurons);

	/**
	  * Adds layer at the given position in network.
	  * @param index index at which new layer will be created.
	  * @param numberOfNeurons number of neurons which will be in new layer.
	  */
	void insertLayerAt(int index, int numberOfNeurons);

	/**
	  * Calculates and returns output.
	  * @return output of network.
	  */
	double calculateOutput() override;

	/**
	  * Gets previously calculated output.
	  * @return output of network.
	  */
	double getOutput() override;

	/**
	  * Learns the Network using given learning strategy, input sets and expected outputs. Makes number of learning iterations given by parameter.
	  * @param learningStrategy reference to object of class implementing learning method we want to use for this network.
	  * @param trainingInputs list of training input vectors.
	  * @param trainingOutputs list of expected outputs for given input vectors.
	  * @param steps number of learning iterations to make.
	  */
	void learnSteps(AbstractLayerNeuralNetworkLearn& learningStrategy, QList<NeuronInputs>& trainingInputs, QList<bool>& trainingOutputs, int steps);

	/**
	  * Learns the Network using given learning strategy, input sets and expected outputs untill error is lower than error threshold.
	  * @param learningStrategy reference to object of class implementing learning method we want to use for this network.
	  * @param trainingInputs list of training input vectors.
	  * @param trainingOutputs list of expected outputs for given input vectors.
	  * @param errorThreshold all errors in iterations have to be lower than this to stop learning.
	  * @return number of iterations made.
	  */
	int learnErrorThreshold(AbstractLayerNeuralNetworkLearn& learningStrategy, QList<NeuronInputs>& trainingInputs, QList<bool>& trainingOutputs, double errorThreshold);

protected:
	bool isLocked;
	Neuron* outputNeuron;
	QVector<QVector<Neuron*>*> hiddenLayers;

	double beta;

	QVector<Neuron*>* generateLayer(int neuronNumber, int inputNumber);
	void clearLayer(QVector<Neuron*>* layer);

	QVector<double> calculateLayerOutput(int index);
	QVector<double> getLayerOutput(int index);
};
