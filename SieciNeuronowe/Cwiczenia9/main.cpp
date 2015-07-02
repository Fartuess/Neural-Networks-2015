#include <QtCore/QCoreApplication>
#include <QtCore\qmath.h>
#include <QtCore/qpair.h>
#include <QtCore/qdebug.h>
#include <random>

int gcd(int a, int b)
{
	//Nonrecursive modification of algorithm to prevent stack overflows or high memory usage;
	while (true)
	{
		if (b == 0)
		{
			throw QString("Cannot divide by zero!");
		}
		if (a % b == 0)
		{
			return b;
		}
		else
		{
			int c = a;
			a = b;
			b = c % b;
		}
	}
}

int dl(int base, int modulo)
{
	for (int i = 2; i <= modulo; i += 2)
	{
		if ((int)qPow(base, i) % modulo == 1)
		{
			return i;
		}
	}
	return modulo;
}

QPair<int, int> factorizeShor(int n)
{
	//Correct way of using randoms in C++
	std::random_device randomDevice;
	std::mt19937 randomGenerator(randomDevice());
	std::uniform_int_distribution<int> uniformDistribution(0, n);

	while (true)
	{
		int a = uniformDistribution(randomGenerator);
		int f;
		try
		{
			f = gcd(n, a);
		}
		catch (QString)
		{
			continue;
		}
		if (f > 1)
		{
			return QPair<int, int>(f, n/f);
		}
		else
		{
			int r = dl(a, n);

			if (r % 2 == 0 && (int)(qPow(a, r/2)) % n != -1)
			{
				return QPair<int, int>(gcd(qPow(a, r / 2) + 1, n), gcd(qPow(a, r / 2) - 1, n));
			}
		}
	}
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QPair<int, int> factorized_12		=	factorizeShor(12);
	qDebug() << "Factorization of 12: " + QString::number(factorized_12.first) + ", " + QString::number(factorized_12.second);
	QPair<int, int> factorized_91		=	factorizeShor(91);
	qDebug() << "Factorization of 91: " + QString::number(factorized_91.first) + ", " + QString::number(factorized_91.second);
	QPair<int, int> factorized_143		=	factorizeShor(143);
	qDebug() << "Factorization of 143: " + QString::number(factorized_143.first) + ", " + QString::number(factorized_143.second);
	QPair<int, int> factorized_1737		=	factorizeShor(1737);
	qDebug() << "Factorization of 1737: " + QString::number(factorized_1737.first) + ", " + QString::number(factorized_1737.second);
	QPair<int, int> factorized_1859		=	factorizeShor(1859);
	qDebug() << "Factorization of 1859: " + QString::number(factorized_1859.first) + ", " + QString::number(factorized_1859.second);
	QPair<int, int> factorized_13843	=	factorizeShor(13843);
	qDebug() << "Factorization of 13843: " + QString::number(factorized_13843.first) + ", " + QString::number(factorized_13843.second);
	QPair<int, int> factorized_988027	=	factorizeShor(988027);
	qDebug() << "Factorization of 988027: " + QString::number(factorized_988027.first) + ", " + QString::number(factorized_988027.second);

	qDebug() << "Finished!";

	return a.exec();
}
