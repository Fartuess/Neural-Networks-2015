#include "Neuron.h"

#include <QtCore/QCoreApplication>
#include <QtCore/qtextstream.h>
#include <QtCore/qdebug.h>


int main(int argc, char *argv[])
{
	Neuron notNeuron = Neuron(1);
	notNeuron.setWeight(0, -1.0);
	notNeuron.setThreshold(0.5);

	Neuron andNeuron = Neuron(2);
	andNeuron.setWeight(0, 0.5);
	andNeuron.setWeight(1, 0.5);
	andNeuron.setThreshold(-0.9);

	Neuron orNeuron = Neuron(2);
	orNeuron.setWeight(0, 0.5);
	orNeuron.setWeight(1, 0.5);
	orNeuron.setThreshold(-0.4);

	Neuron nandNeuron = Neuron(2);
	nandNeuron.setWeight(0, -0.5);
	nandNeuron.setWeight(1, -0.5);
	nandNeuron.setThreshold(0.9);

	int selection = 0;
	Neuron* selectedNeuron;

	QTextStream output(stdout);
	QTextStream input(stdin);
	while (true)
	{
		do
		{
			qDebug() << "Select logic gate:\n1 - NOT\n2 - AND\n3 - OR\n4 - NAND";
			input >> selection;
			switch (selection)
			{
			case 1:
				selectedNeuron = &notNeuron;
				qDebug() << "Selected NOT";
				break;
			case 2:
				selectedNeuron = &andNeuron;
				qDebug() << "Selected AND";
				break;
			case 3:
				selectedNeuron = &orNeuron;
				qDebug() << "Selected OR";
				break;
			case 4:
				selectedNeuron = &nandNeuron;
				qDebug() << "Selected NAND";
				break;
			}
		} while (selection <= 1 && selection >= 4);

		qDebug() << "Assign " + QString::number(selectedNeuron->getInputCount()) + " inputs.";
		for (int i = 0; i < selectedNeuron->getInputCount(); i++)
		{
			double value;
			input >> value;
			selectedNeuron->setInput(i, value);
		}

		selectedNeuron->calculateOutput();
		qDebug() << selectedNeuron->getOutput();
	}
}
