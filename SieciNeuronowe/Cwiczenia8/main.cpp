#include <QtCore/QCoreApplication>
#include <QtCore\qvector.h>
#include <QtCore\qlist.h>
#include <QtCore\qmath.h>
#include <random>
#include <QtCore\qdebug.h>
#include <QtCore\qtextstream.h>

double E(QVector<int> path, QVector<QVector<double>> travelCost)
{
	double cost = 0;
	for (int i = 0; i < path.count() - 1; i++)
	{
		cost += travelCost[path[i]][path[i + 1]];
	}
	cost += travelCost[path[path.count() - 1]][path[0]];
	return cost;
}

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


	QVector<QVector<double>> travelCost;
	for (int a = 0; a < 10; a++)
	{
		travelCost.push_back(QVector<double>());
		for (int b = 0; b < 10; b++)
		{
			switch (selection)
			{
				default:
				case 1:
					if (((a == 0) && (b == 9)) || (((a == 9) && (b == 0))))
					{
						travelCost[a].push_back(1.0);
					}
					else
					{
						travelCost[a].push_back(qAbs((a - b)));
					}
					break;
				case 2:
					if ((a == 1 && b == 2) || (a == 9 && b == 10))
					{
						travelCost[a].push_back(1.0);
					}
					else
					{
						int c = a;
						int d = b;
						if (a > b)
						{
							c = b;
							d = a;
						}
						travelCost[a].push_back(c*c*c + d*d*d - c*c*d - c*d*d + 4 * c - 4 * d + 4 * c + 4 * d + 1.0);
					}
					break;
			}
		}
	}

	//Correct way of using randoms in C++. Might be a bit overkill for {0; 1} set.
	std::random_device randomDevice;
	std::mt19937 randomGenerator(randomDevice());
	std::uniform_int_distribution<int> uniformDistribution(0, 9);
	std::uniform_real_distribution<double> doubleUniformDistribution(0, 1);
	
	//Initialization of the path.
	QVector<int> path;
	{
		QList<int> initializePath;
		for (int i = 0; i < 10; i++)
		{
			initializePath.push_back(i);
		}
		while (!initializePath.isEmpty())
		{

			int random_id;
			do
			{
				random_id = uniformDistribution(randomGenerator);
			} while (random_id > initializePath.count() - 1);
			//} while (random_id > (initializePath.count() * qFloor((double)random_id / (double)initializePath.count()) - 1));
			random_id = random_id % initializePath.count();
			path.push_back(initializePath.takeAt(random_id));
		}
		for (int i : path)
		{
			qDebug() << i;
		}
	}
	qDebug() << "Initial travel cost: " + QString::number(E(path, travelCost));

	double initialTemperature = 1.0;
	double temperature = initialTemperature;

	int L = 3;
	int M = 100;

	if (!(L < M))
	{
		qDebug() << "Error";
	}

	//Algorithm
	int iteration = 0;
	int newSolutions = 0;
	int acceptedSolutions = 0;
	
	do
	{
		iteration++;
		newSolutions = 0;
		acceptedSolutions = 0;
		while (newSolutions < M)
		{
			QVector<int> newPath = path;	//s¹siednie rozwi¹zanie.

			{
				int a;
				int b;
				do
				{
					a = uniformDistribution(randomGenerator);
					b = uniformDistribution(randomGenerator);
				} while (a == b);
				newPath[a] = path[b];
				newPath[b] = path[a];
				newSolutions++;
			}

			double delta_E = E(newPath, travelCost) - E(path, travelCost);
			double random = doubleUniformDistribution(randomGenerator);
			if (delta_E < 0 || random < qExp(- delta_E / temperature))
			{
				path = newPath;
				acceptedSolutions++;
				qDebug() << "Current travel cost: " + QString::number(E(path, travelCost));
			}
		}
		temperature = initialTemperature / qLn(iteration + 1);
	} while (acceptedSolutions < L);
	qDebug() << "Final travel cost: " + QString::number(E(path, travelCost));

	return a.exec();
}
