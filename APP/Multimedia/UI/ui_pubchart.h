/********************************************************************************
** Form generated from reading UI file 'pubchart.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUBCHART_H
#define UI_PUBCHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_PubChart
{
public:
    QHBoxLayout *horizontalLayout;
    QCustomPlot *chart;

    void setupUi(QWidget *PubChart)
    {
        if (PubChart->objectName().isEmpty())
            PubChart->setObjectName(QStringLiteral("PubChart"));
        PubChart->resize(593, 371);
        horizontalLayout = new QHBoxLayout(PubChart);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        chart = new QCustomPlot(PubChart);
        chart->setObjectName(QStringLiteral("chart"));

        horizontalLayout->addWidget(chart);


        retranslateUi(PubChart);

        QMetaObject::connectSlotsByName(PubChart);
    } // setupUi

    void retranslateUi(QWidget *PubChart)
    {
        PubChart->setWindowTitle(QApplication::translate("PubChart", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PubChart: public Ui_PubChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUBCHART_H
