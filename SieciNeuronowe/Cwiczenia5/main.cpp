#include <QtCore/QCoreApplication>
#include "LayeredNeuralNetwork.h"
#include "BackpropagationLayerNeuralNetworkLearn.h"
#include <QtCore\qtextstream.h>
#include <QtCore\qdebug.h>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	LayeredNeuralNetwork xorNetwork(2);
	xorNetwork.pushBackLayer(2);
	xorNetwork.lock();

	QVector<Neuron*> l0 = xorNetwork.getLayer(0);
	NeuronWeights initialWeights;
	initialWeights.first = 2.0;
	initialWeights.second << 0.0 << 1.0;
	l0[0]->setWeights(initialWeights);
	l0[1]->setWeights(initialWeights);
	xorNetwork.getLayer(1)[0]->setWeights(initialWeights);

	QList<NeuronInputs> trainingInputs = QList<NeuronInputs>();
	QList<bool> trainingOutputs = QList<bool>();

	NeuronInputs t1 = NeuronInputs();
	t1 << 0.0 << 0.0;
	trainingInputs.push_back(t1);
	trainingOutputs.push_back(false);

	NeuronInputs t2 = NeuronInputs();
	t2 << 1.0 << 0.0;
	trainingInputs.push_back(t2);
	trainingOutputs.push_back(true);

	NeuronInputs t3 = NeuronInputs();
	t3 << 0.0 << 1.0;
	trainingInputs.push_back(t3);
	trainingOutputs.push_back(true);

	NeuronInputs t4 = NeuronInputs();
	t4 << 1.0 << 1.0;
	trainingInputs.push_back(t4);
	trainingOutputs.push_back(false);

	xorNetwork.learnSteps(BackpropagationLayerNeuralNetworkLearn(), trainingInputs, trainingOutputs, 4);

	//Printing out weigths results

	QVector<QPair<QString, Neuron*>> neurons;
	neurons << QPair<QString, Neuron*>("Layer 1 Neuron 1", l0[0]);
	neurons << QPair<QString, Neuron*>("Layer 1 Neuron 2", l0[1]);
	neurons << QPair<QString, Neuron*>("Layer 2 Neuron 1", xorNetwork.getLayer(1)[0]);
	for (int i = 0; i < neurons.count(); i++)
	{
		qDebug() << neurons[i].first;
		Neuron& iNeuron = *(neurons[i].second);
		NeuronWeights weightsDebug = iNeuron.getWeights();
		qDebug() << "Threshold:";
		qDebug() << weightsDebug.first;
		qDebug() << "Weights:";
		for (double weight : weightsDebug.second)
		{
			qDebug() << QString::number(weight);
		}
	}

	//Testing results

	QTextStream input(stdin);
	while (true)
	{
		qDebug() << "Assign 2 inputs.";
		for (int i = 0; i < xorNetwork.getInputCount(); i++)
		{
			double value;
			input >> value;
			xorNetwork.setInput(i, value);
		}

		xorNetwork.calculateOutput();
		qDebug() << xorNetwork.getOutput();
	}

	return a.exec();
}
