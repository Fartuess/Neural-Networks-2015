#include <QtCore/QCoreApplication>
#include <QtCore\qvector.h>
#include <random>
#include <QtCore\qmath.h>
#include <QtCore\qtextstream.h>
#include <QtCore\qdebug.h>

double _temperature = 2.5;

double activationFunction(double input, double temperature)
{
	return 1.0 / (1 + qExp(-input / temperature));
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QVector<double> sample;

	sample	<< 0.0 << 0.0 << 0.0 << 0.0 << 0.0
			<< 0.0 << 1.0 << 1.0 << 0.0 << 0.0
			<< 0.0 << 0.0 << 1.0 << 0.0 << 0.0
			<< 0.0 << 0.0 << 1.0 << 0.0 << 0.0
			<< 0.0 << 0.0 << 1.0 << 0.0 << 0.0;

	//Correct way of using randoms in C++. Might be a bit overkill for {0; 1} set.
	std::random_device randomDevice;
	std::mt19937 randomGenerator(randomDevice());
	std::uniform_int_distribution<int> uniformDistribution(0, 1);

	//initialization
	QVector<double> results;
	for (int i = 0; i < 25; i++)
	{
		results.push_back((double)uniformDistribution(randomGenerator));
	}

	QVector<double> weights;
	QVector<double> theta;
	{
		QVector<double> C;
		for (int i = 0; i < 25; i++) for (int j = 0; j < 25; j++)
		{
			if (i == j)
			{
				C.push_back(0.0);
			}
			else
			{
				C.push_back((sample[i] - 0.5) * (sample[j] - 0.5));
			}
		}

		for (int i = 0; i < 25; i++) for (int j = 0; j < 25; j++)
		{
			weights.push_back(2.0 * (C[25 * i + j]));
		}

		for (int i = 0; i < 25; i++)
		{
			theta.push_back(0.0);
			for (int j = 0; j < 25; j++)
			{
				theta[i] += C[25 * i + j];
			}
		}
	}

	QTextStream io(stdin);
	QString line;
	std::system("cls");
	qDebug() << "Initialized values";
	for (int j = 1; j <= 25; j++)
	{
		if (results[j - 1] == 1.0)
		{
			line += "*";
		}
		else
		{
			line += " ";
		}
		if (j % 5 == 0)
		{
			qDebug() << line;
			line.clear();
		}
	}
	io.readLine();

	qDebug() << "Annealing:\n1 - No\n2 - Yes";
	bool annealing = io.readLine().toInt() == 2;
	//qDebug() << "Set starting temperature";
	//_temperature = io.readLine().toDouble();
	double temperature = _temperature;

	std::uniform_real_distribution<double> uniformRealDistribution(0, 1);
	int iteration = 0;
	while (true)
	{
		QVector<double> resultsCopy = results;
		iteration++;
		if (annealing)
		{
			temperature = _temperature / (1 + qLn(iteration + 1));
		}
		
		for (int i = 0; i < 25; i++)
		{
			double u = 0;
			for (int j = 0; j < 25; j++)
			{
				u += weights[j * 25 + i] * resultsCopy[j];
			}
			u = u - theta[i];
			double f = activationFunction(u, temperature);
			double random = uniformRealDistribution(randomGenerator);
			if (random <= f)
			{
				results[i] = 1.0;
			}
			else
			{
				results[i] = 0.0;
			}
		}

		//Printing effects on the screen
		std::system("cls");	//Qt equivalent does not work.
		qDebug() << "Iteration " + QString::number(iteration);
		for (int j = 1; j <= 25; j++)
		{
			if (results[j - 1] == 1.0)
			{
				line += "*";
			}
			else
			{
				line += " ";
			}
			if (j % 5 == 0)
			{
				qDebug() << line;
				line.clear();
			}
		}
		io.readLine();
	}

	return a.exec();
}
