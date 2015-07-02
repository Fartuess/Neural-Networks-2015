#include "cwiczenia3.h"

Cwiczenia3::Cwiczenia3(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.DetectButton, SIGNAL(released()), this, SLOT(setOutput()));
	for (int i = 0; i < 25; i++)
	{
		neurons.push_back(new Neuron(25, 0.0));
	}
	double z0[25] = {	-1, -1, -1, -1, -1,
						-1,  1,  1,  1, -1,
						-1,  1, -1,  1, -1,
						-1,  1,  1,  1, -1,
						-1, -1, -1, -1, -1 };
	double z1[25] = {	-1, -1, -1, -1, -1,
						-1,  1,  1, -1, -1,
						-1, -1,  1, -1, -1,
						-1, -1,  1, -1, -1,
						-1, -1, -1, -1, -1 };

	for (int i = 0; i < 25; i++)
	{
		NeuronWeights weights = NeuronWeights();
		weights.second.resize(25);
		weights.first = 0.0;
		for (int j = 0; j < 25; j++)
		{
			weights.second[j] = (z0[i] * z0[j]) / 25 + (z1[i] * z1[j]) / 25;
		}
		neurons[i]->setWeights(weights);
	}
}

Cwiczenia3::~Cwiczenia3()
{

}

void Cwiczenia3::setOutput()
{
	QVector<double> inputValues = QVector<double>();
	inputValues.resize(25);
	QVector<bool> inputValues_temp = ui.InputGrid->getValues();
	QVector<bool> outpuValues = QVector<bool>();
	outpuValues.resize(25);
	for (int i = 0; i < 25; i++)
	{
		inputValues[i] = inputValues_temp[i];
	}
	for (int i = 0; i < 25; i++)
	{
		neurons[i]->setInputs(inputValues);
		outpuValues[i] = neurons[i]->calculateOutput();
	}
	ui.OutputGrid->setValues(outpuValues);
}