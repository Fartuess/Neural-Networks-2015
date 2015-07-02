#include <QtCore/QCoreApplication>

#include "Neuron.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Neuron notNeuron = Neuron(2);


	return a.exec();
}
