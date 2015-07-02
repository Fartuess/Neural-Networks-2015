#include <QtCore/QCoreApplication>
#include <QtCore\qvector.h>
#include <QtCore\qpair.h>
#include <QtCore\qstring.h>

int main(int argc, char *argv[])
{

	typedef QPair<QString, int> Input;

	QCoreApplication a(argc, argv);

	QVector<bool> FredkinGate[2][2][2];

	FredkinGate[0][0][0] << 0 << 0 << 0;
	FredkinGate[0][0][1] << 0 << 0 << 1;
	FredkinGate[0][1][0] << 0 << 1 << 0;
	FredkinGate[0][1][1] << 0 << 1 << 1;

	FredkinGate[1][0][0] << 1 << 0 << 0;
	FredkinGate[1][0][1] << 1 << 1 << 0;
	FredkinGate[1][1][0] << 1 << 0 << 1;
	FredkinGate[1][1][1] << 1 << 1 << 1;

	QVector<Input&> inputsL1;
	QVector<Input&> inputsL2;

	Input A = Input("A", 0);
	Input B = Input("B", 0);
	Input One = Input("One", 1);
	Input Zero = Input("Zero", 0);

	Input OutA = Input("OutA", 0);
	Input OutB = Input("OutB", 0);
	Input OutC = Input("OutC", 0);

	inputsL1 << A << B << One << Zero;
	inputsL2 << A << B << One << Zero << OutA << OutB << OutC;
	for (Input& a1 : inputsL1) for (Input& b1 : inputsL1) for (Input& c1 : inputsL1)
	{
		for (Input& a2 : inputsL2) for (Input& b2 : inputsL2) for (Input& c2 : inputsL2)
		{
			///TODO: Check if too many uses
			{
				continue;
			}
			for (int output = 0; output < 3; output++)
			{
				int ok = 0;
				for (int a = 0; a <= 1; a++) for (int b = 0; b <= 1; b++)
				{
					///TODO: Calculate output
					///TODO: if (calc_out == wanted_out)
					{
						ok++;
					}
					//else
					{
						break;
					}
				}
				if (ok == 4)
				{
					///TODO: Print chosen structure
				}
			}
		}
	}

	return a.exec();
}
