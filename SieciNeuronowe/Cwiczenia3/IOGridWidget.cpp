#include "IOGridWidget.h"

#include <QtWidgets/qgridlayout.h>

IOGridWidget::IOGridWidget(QWidget* parent) :QWidget(parent)
{
	checkboxes.resize(25);
	QGridLayout* layout = new QGridLayout();
	setLayout(layout);
	for (int i = 0; i < 25; i++)
	{
		QCheckBox* newCheckbox = new QCheckBox();
		checkboxes[i] = newCheckbox;
		layout->addWidget(newCheckbox, i / 5, i % 5);
	}
}


IOGridWidget::~IOGridWidget()
{
}

QVector<bool> IOGridWidget::getValues()
{
	QVector<bool> result = QVector<bool>(25);
	for (int i = 0; i < 25; i++)
	{
		result[i] = checkboxes[i]->isChecked();
	}
	return result;
}

void IOGridWidget::setValues(QVector<bool>& values)
{
	if (values.size() != 25)
	{
		throw QString("Vector size is not 25");
	}
	for (int i = 0; i < 25; i++)
	{
		checkboxes[i]->setChecked(values[i]);
	}
}