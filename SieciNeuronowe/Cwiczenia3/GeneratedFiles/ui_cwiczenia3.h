/********************************************************************************
** Form generated from reading UI file 'cwiczenia3.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CWICZENIA3_H
#define UI_CWICZENIA3_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "IOGridWidget.h"

QT_BEGIN_NAMESPACE

class Ui_Cwiczenia3Class
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    IOGridWidget *InputGrid;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    IOGridWidget *OutputGrid;
    QPushButton *DetectButton;

    void setupUi(QMainWindow *Cwiczenia3Class)
    {
        if (Cwiczenia3Class->objectName().isEmpty())
            Cwiczenia3Class->setObjectName(QStringLiteral("Cwiczenia3Class"));
        Cwiczenia3Class->resize(600, 400);
        centralWidget = new QWidget(Cwiczenia3Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        widget = new QWidget(frame_2);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(label);

        InputGrid = new IOGridWidget(widget);
        InputGrid->setObjectName(QStringLiteral("InputGrid"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(InputGrid->sizePolicy().hasHeightForWidth());
        InputGrid->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(InputGrid);


        horizontalLayout_2->addWidget(widget);

        widget_2 = new QWidget(frame_2);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(label_2);

        OutputGrid = new IOGridWidget(widget_2);
        OutputGrid->setObjectName(QStringLiteral("OutputGrid"));
        OutputGrid->setEnabled(false);

        verticalLayout_3->addWidget(OutputGrid);


        horizontalLayout_2->addWidget(widget_2);


        verticalLayout->addWidget(frame_2);

        DetectButton = new QPushButton(frame);
        DetectButton->setObjectName(QStringLiteral("DetectButton"));

        verticalLayout->addWidget(DetectButton);


        horizontalLayout->addWidget(frame);

        Cwiczenia3Class->setCentralWidget(centralWidget);

        retranslateUi(Cwiczenia3Class);

        QMetaObject::connectSlotsByName(Cwiczenia3Class);
    } // setupUi

    void retranslateUi(QMainWindow *Cwiczenia3Class)
    {
        Cwiczenia3Class->setWindowTitle(QApplication::translate("Cwiczenia3Class", "Cwiczenia3", 0));
        label->setText(QApplication::translate("Cwiczenia3Class", "Input", 0));
        label_2->setText(QApplication::translate("Cwiczenia3Class", "Output", 0));
        DetectButton->setText(QApplication::translate("Cwiczenia3Class", "Detect", 0));
    } // retranslateUi

};

namespace Ui {
    class Cwiczenia3Class: public Ui_Cwiczenia3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CWICZENIA3_H
