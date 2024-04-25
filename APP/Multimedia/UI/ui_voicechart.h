/********************************************************************************
** Form generated from reading UI file 'voicechart.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOICECHART_H
#define UI_VOICECHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_VoiceChart
{
public:
    QGridLayout *gridLayout;
    QCustomPlot *chart;

    void setupUi(QWidget *VoiceChart)
    {
        if (VoiceChart->objectName().isEmpty())
            VoiceChart->setObjectName(QStringLiteral("VoiceChart"));
        VoiceChart->resize(828, 589);
        gridLayout = new QGridLayout(VoiceChart);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        chart = new QCustomPlot(VoiceChart);
        chart->setObjectName(QStringLiteral("chart"));

        gridLayout->addWidget(chart, 0, 0, 1, 1);


        retranslateUi(VoiceChart);

        QMetaObject::connectSlotsByName(VoiceChart);
    } // setupUi

    void retranslateUi(QWidget *VoiceChart)
    {
        VoiceChart->setWindowTitle(QApplication::translate("VoiceChart", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VoiceChart: public Ui_VoiceChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOICECHART_H
