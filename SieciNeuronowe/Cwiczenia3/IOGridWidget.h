#pragma once
#include "qwidget.h"

#include <QtCore/qvector.h>
#include <QtWidgets/qcheckbox.h>

class IOGridWidget :
	public QWidget
{
private:
	QVector<QCheckBox*> checkboxes;
public:
	IOGridWidget(QWidget* parent = 0);
	~IOGridWidget();

	QVector<bool> getValues();
	void setValues(QVector<bool>& values);
};

