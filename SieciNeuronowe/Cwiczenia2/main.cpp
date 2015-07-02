#include "Neuron.h"
#include "PerceptronLearn.h"

#include <QtCore/QCoreApplication>
#include <QtCore\qdebug.h>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Neuron perceptron = Neuron(26);

	QList<NeuronInputs> trainingInputs = QList<NeuronInputs>();
	QList<bool> trainingOutputs = QList<bool>();

	NeuronInputs t1 = NeuronInputs(26);
	double t1_t[26] = { 0, 0, 0, 0, 0,
						0, 1, 1, 0, 0,
						0, 0, 1, 0, 0,
						0, 0, 1, 0, 0,
						0, 0, 1, 0, 0, 1 };
	for (int i = 0; i < 26; i++) t1[i] = t1_t[i];
	trainingInputs.push_back(t1);
	trainingOutputs.push_back(true);

	NeuronInputs t2 = NeuronInputs(26);
	double t2_t[26] = { 0, 0, 1, 1, 0,
						0, 0, 0, 1, 0,
						0, 0, 0, 1, 0,
						0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 1 };
	for (int i = 0; i < 26; i++) t2[i] = t2_t[i];
	trainingInputs.push_back(t2);
	trainingOutputs.push_back(true);

	NeuronInputs t3 = NeuronInputs(26);
	double t3_t[26] = { 0, 0, 0, 0, 0,
						1, 1, 0, 0, 0,
						0, 1, 0, 0, 0,
						0, 1, 0, 0, 0,
						0, 1, 0, 0, 0, 1 };
	for (int i = 0; i < 26; i++) t3[i] = t3_t[i];
	trainingInputs.push_back(t3);
	trainingOutputs.push_back(true);

	NeuronInputs f1 = NeuronInputs(26);
	double f1_t[26] = { 0, 0, 0, 0, 0,
						0, 1, 1, 1, 0,
						0, 1, 0, 1, 0,
						0, 1, 1, 1, 0,
						0, 0, 0, 0, 0, 1 };
	for (int i = 0; i < 26; i++) f1[i] = f1_t[i];
	trainingInputs.push_back(f1);
	trainingOutputs.push_back(false);

	NeuronInputs f2 = NeuronInputs(26);
	double f2_t[26] = { 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0,
						1, 1, 1, 0, 0,
						1, 0, 1, 0, 0,
						1, 1, 1, 0, 0, 1 };
	for (int i = 0; i < 26; i++) f2[i] = f2_t[i];
	trainingInputs.push_back(f2);
	trainingOutputs.push_back(false);

	//perceptron.learnSteps(PerceptronLearn(0.1), trainingInputs, trainingOutputs, 5);
	int n0 = perceptron.learnErrorThreshold(PerceptronLearn(0.1), trainingInputs, trainingOutputs, 0.0);

	qDebug() << "PERFORMING TESTS";
	perceptron.setInputs(t1);
	qDebug() << perceptron.calculateOutput();
	perceptron.setInputs(t2);
	qDebug() << perceptron.calculateOutput();
	perceptron.setInputs(t3);
	qDebug() << perceptron.calculateOutput();
	perceptron.setInputs(f1);
	qDebug() << perceptron.calculateOutput();
	perceptron.setInputs(f2);
	qDebug() << perceptron.calculateOutput();

	NeuronWeights weightsDebug = perceptron.getWeights();
	qDebug() << "Threshold:";
	qDebug() << weightsDebug.first;
	qDebug() << "Weights:";
	for (double weight : weightsDebug.second)
	{
		qDebug() << QString::number(weight);
	}
	qDebug() << "N0";
	qDebug() << QString::number(n0);

	return a.exec();
}
