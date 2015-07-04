#include <QtCore/QCoreApplication>
#include <QtCore/qvector.h>
#include <random>
#include <QtCore/qbuffer.h>
#include <QtCore/qtextstream.h>
#include <QtCore/qdebug.h>
#include <QtCore/qprocess.h>

/**
  * I'm fully aware that this code looks terrible. 
  */
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	int selection = 0;
	QTextStream io(stdin);
	do
	{
		qDebug() << "Select Task:\n1 - Task 1\n2 - Task 2";
		selection = io.readLine().toInt();
	} while (!(selection == 1 || selection == 2));

	QVector<double>& sample = QVector<double>();
	QVector<double> sample1;
	QVector<double> sample2;

	sample1	<< 0.0 << 0.0 << 0.0 << 0.0 << 0.0
			<< 0.0 << 1.0 << 1.0 << 0.0 << 0.0
			<< 0.0 << 0.0 << 1.0 << 0.0 << 0.0
			<< 0.0 << 0.0 << 1.0 << 0.0 << 0.0
			<< 0.0 << 0.0 << 1.0 << 0.0 << 0.0;

	sample2	<< 0.0 << 1.0 << 1.0 << 1.0 << 0.0
			<< 0.0 << 1.0 << 0.0 << 1.0 << 0.0
			<< 0.0 << 1.0 << 0.0 << 1.0 << 0.0
			<< 0.0 << 1.0 << 0.0 << 1.0 << 0.0
			<< 0.0 << 1.0 << 1.0 << 1.0 << 0.0;

	switch (selection)
	{
		case 1:
			sample = sample1;
		case 2:
			sample = sample2;
		default:
			sample = sample1;
	}

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

		QVector<double> D;
		for (int i = 0; i < 25; i++) for (int j = 0; j < 25; j++)
		{
			if (selection == 2)
			{
				if (i == j)
				{
					D.push_back(0.0);
				}
				else
				{
					D.push_back((sample2[i] - 0.5) * (sample2[j] - 0.5));
				}
			}
			else
			{
				D.push_back(0.0);
			}
		}

		for (int i = 0; i < 25; i++) for (int j = 0; j < 25; j++)
		{
			weights.push_back(2.0 * (C[25 * i + j] + D[25 * i + j]));
		}
		
		for (int i = 0; i < 25; i++)
		{
			theta.push_back(0.0);
			for (int j = 0; j < 25; j++)
			{
				theta[i] += C[25 * i + j] + D[25 * i + j];
			}
		}
	}

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
	qDebug() << "Press Enter.";
	io.readLine();

	//Learning
	for (int iteration = 1; iteration <= 25; iteration++)
	{
		QVector<double> resultsCopy = results;
		
		//Setting new values
		for (int j = 0; j < 25; j++)
		{
			double u = 0.0;
			for (int k = 0; k < 25; k++)
			{
				u += weights[k * 25 + j] * resultsCopy[k];
			}
			u = u - theta[j];

			if (u > 0.0)
			{
				results[j] = 1.0;
			}
			else
			{
				if (u < 0.0)
				{
					results[j] = 0.0;
				}
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
		qDebug() << "Press Enter.";
		io.readLine();
	}

	return a.exec();
}
