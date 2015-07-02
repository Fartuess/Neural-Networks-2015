#ifndef CWICZENIA3_H
#define CWICZENIA3_H

#include <QtWidgets/QMainWindow>
#include <QtCore/qvector.h>
#include "ui_cwiczenia3.h"
#include "Neuron.h"

class Cwiczenia3 : public QMainWindow
{
	Q_OBJECT
public:
	Cwiczenia3(QWidget *parent = 0);
	~Cwiczenia3();

private:
	Ui::Cwiczenia3Class ui;
	QVector<Neuron*> neurons;
public slots:
	void setOutput();
};

#endif // CWICZENIA3_H
