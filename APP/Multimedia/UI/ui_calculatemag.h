/********************************************************************************
** Form generated from reading UI file 'calculatemag.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATEMAG_H
#define UI_CALCULATEMAG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Module\voicechart.h"

QT_BEGIN_NAMESPACE

class Ui_CalculateMag
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QPushButton *speaker_HLF;
    QPushButton *speaker_HRF;
    QPushButton *speaker_HLS;
    QPushButton *speaker_HRS;
    QPushButton *importBtn;
    QPushButton *speaker_LR;
    QPushButton *speaker_RR;
    QPushButton *speaker_CTR;
    QPushButton *speaker_CTR_TW;
    QPushButton *speaker_HLL;
    QPushButton *speaker_HLR;
    QPushButton *location_RF;
    QPushButton *location_LF;
    QPushButton *location_LS;
    QPushButton *location_RS;
    QPushButton *speaker_SUB;
    QPushButton *speaker_LFM;
    QPushButton *speaker_LFTW;
    QPushButton *speaker_LFW;
    QPushButton *speaker_LSW;
    QPushButton *speaker_LSM;
    QPushButton *speaker_LSTW;
    QPushButton *speaker_RFTW;
    QPushButton *speaker_RFM;
    QPushButton *speaker_RFW;
    QPushButton *speaker_RSW;
    QPushButton *speaker_RSM;
    QPushButton *speaker_RSTW;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QComboBox *selectBox;
    QWidget *calcu_chart_widget;
    QVBoxLayout *verticalLayout;
    VoiceChart *freq_chart;
    QWidget *phaseWidget;
    QVBoxLayout *verticalLayout_7;
    VoiceChart *phase_chart;

    void setupUi(QWidget *CalculateMag)
    {
        if (CalculateMag->objectName().isEmpty())
            CalculateMag->setObjectName(QStringLiteral("CalculateMag"));
        CalculateMag->resize(1002, 709);
        CalculateMag->setStyleSheet(QStringLiteral(""));
        horizontalLayout_2 = new QHBoxLayout(CalculateMag);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(9, 9, 9, 9);
        widget = new QWidget(CalculateMag);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(383, 691));
        widget->setMaximumSize(QSize(391, 691));
        widget->setStyleSheet(QLatin1String("QWidget#widget{\n"
"	image: url(:/image/images/vehicle.png);\n"
"}"));
        speaker_HLF = new QPushButton(widget);
        speaker_HLF->setObjectName(QStringLiteral("speaker_HLF"));
        speaker_HLF->setGeometry(QRect(120, 340, 41, 31));
        speaker_HLF->setMinimumSize(QSize(0, 0));
        speaker_HLF->setStyleSheet(QStringLiteral(""));
        speaker_HLF->setIconSize(QSize(30, 30));
        speaker_HLF->setCheckable(true);
        speaker_HLF->setChecked(false);
        speaker_HLF->setAutoRepeat(false);
        speaker_HRF = new QPushButton(widget);
        speaker_HRF->setObjectName(QStringLiteral("speaker_HRF"));
        speaker_HRF->setGeometry(QRect(220, 340, 41, 31));
        speaker_HRF->setMinimumSize(QSize(0, 0));
        speaker_HRF->setStyleSheet(QStringLiteral(""));
        speaker_HRF->setIconSize(QSize(30, 30));
        speaker_HRF->setCheckable(true);
        speaker_HRF->setChecked(false);
        speaker_HRF->setAutoRepeat(false);
        speaker_HLS = new QPushButton(widget);
        speaker_HLS->setObjectName(QStringLiteral("speaker_HLS"));
        speaker_HLS->setGeometry(QRect(130, 550, 41, 31));
        speaker_HLS->setMinimumSize(QSize(0, 0));
        speaker_HLS->setStyleSheet(QStringLiteral(""));
        speaker_HLS->setIconSize(QSize(30, 30));
        speaker_HLS->setCheckable(true);
        speaker_HLS->setChecked(false);
        speaker_HLS->setAutoRepeat(false);
        speaker_HRS = new QPushButton(widget);
        speaker_HRS->setObjectName(QStringLiteral("speaker_HRS"));
        speaker_HRS->setGeometry(QRect(210, 550, 41, 31));
        speaker_HRS->setMinimumSize(QSize(0, 0));
        speaker_HRS->setStyleSheet(QStringLiteral(""));
        speaker_HRS->setIconSize(QSize(30, 30));
        speaker_HRS->setCheckable(true);
        speaker_HRS->setChecked(false);
        speaker_HRS->setAutoRepeat(false);
        importBtn = new QPushButton(widget);
        importBtn->setObjectName(QStringLiteral("importBtn"));
        importBtn->setGeometry(QRect(140, 90, 100, 34));
        importBtn->setMaximumSize(QSize(100, 16777215));
        importBtn->setStyleSheet(QStringLiteral(""));
        speaker_LR = new QPushButton(widget);
        speaker_LR->setObjectName(QStringLiteral("speaker_LR"));
        speaker_LR->setGeometry(QRect(70, 530, 41, 31));
        speaker_LR->setMinimumSize(QSize(0, 0));
        speaker_LR->setStyleSheet(QStringLiteral(""));
        speaker_LR->setIconSize(QSize(30, 30));
        speaker_LR->setCheckable(true);
        speaker_LR->setChecked(false);
        speaker_LR->setAutoRepeat(false);
        speaker_RR = new QPushButton(widget);
        speaker_RR->setObjectName(QStringLiteral("speaker_RR"));
        speaker_RR->setGeometry(QRect(270, 530, 41, 31));
        speaker_RR->setMinimumSize(QSize(0, 0));
        speaker_RR->setStyleSheet(QStringLiteral(""));
        speaker_RR->setIconSize(QSize(30, 30));
        speaker_RR->setCheckable(true);
        speaker_RR->setChecked(false);
        speaker_RR->setAutoRepeat(false);
        speaker_CTR = new QPushButton(widget);
        speaker_CTR->setObjectName(QStringLiteral("speaker_CTR"));
        speaker_CTR->setGeometry(QRect(170, 280, 51, 21));
        speaker_CTR->setMinimumSize(QSize(0, 0));
        speaker_CTR->setStyleSheet(QStringLiteral(""));
        speaker_CTR->setIconSize(QSize(70, 70));
        speaker_CTR->setCheckable(true);
        speaker_CTR->setChecked(false);
        speaker_CTR->setAutoRepeat(false);
        speaker_CTR_TW = new QPushButton(widget);
        speaker_CTR_TW->setObjectName(QStringLiteral("speaker_CTR_TW"));
        speaker_CTR_TW->setGeometry(QRect(160, 310, 71, 21));
        speaker_CTR_TW->setMinimumSize(QSize(0, 0));
        speaker_CTR_TW->setStyleSheet(QStringLiteral(""));
        speaker_CTR_TW->setIconSize(QSize(70, 70));
        speaker_CTR_TW->setCheckable(true);
        speaker_CTR_TW->setChecked(false);
        speaker_CTR_TW->setAutoRepeat(false);
        speaker_HLL = new QPushButton(widget);
        speaker_HLL->setObjectName(QStringLiteral("speaker_HLL"));
        speaker_HLL->setGeometry(QRect(130, 440, 61, 31));
        speaker_HLL->setMinimumSize(QSize(0, 0));
        speaker_HLL->setStyleSheet(QStringLiteral(""));
        speaker_HLL->setIconSize(QSize(70, 70));
        speaker_HLL->setCheckable(true);
        speaker_HLL->setChecked(false);
        speaker_HLL->setAutoRepeat(false);
        speaker_HLR = new QPushButton(widget);
        speaker_HLR->setObjectName(QStringLiteral("speaker_HLR"));
        speaker_HLR->setGeometry(QRect(190, 440, 61, 31));
        speaker_HLR->setMinimumSize(QSize(0, 0));
        speaker_HLR->setStyleSheet(QStringLiteral(""));
        speaker_HLR->setIconSize(QSize(70, 70));
        speaker_HLR->setCheckable(true);
        speaker_HLR->setChecked(false);
        speaker_HLR->setAutoRepeat(false);
        location_RF = new QPushButton(widget);
        location_RF->setObjectName(QStringLiteral("location_RF"));
        location_RF->setGeometry(QRect(210, 400, 40, 40));
        location_RF->setMinimumSize(QSize(40, 40));
        location_RF->setStyleSheet(QStringLiteral(""));
        location_RF->setCheckable(true);
        location_LF = new QPushButton(widget);
        location_LF->setObjectName(QStringLiteral("location_LF"));
        location_LF->setGeometry(QRect(130, 400, 40, 40));
        location_LF->setMinimumSize(QSize(30, 30));
        location_LF->setStyleSheet(QStringLiteral(""));
        location_LF->setCheckable(true);
        location_LS = new QPushButton(widget);
        location_LS->setObjectName(QStringLiteral("location_LS"));
        location_LS->setGeometry(QRect(130, 470, 40, 40));
        location_LS->setMinimumSize(QSize(40, 40));
        location_LS->setStyleSheet(QStringLiteral(""));
        location_LS->setCheckable(true);
        location_LS->setChecked(false);
        location_RS = new QPushButton(widget);
        location_RS->setObjectName(QStringLiteral("location_RS"));
        location_RS->setGeometry(QRect(210, 470, 40, 40));
        location_RS->setMinimumSize(QSize(40, 40));
        location_RS->setStyleSheet(QStringLiteral(""));
        location_RS->setCheckable(true);
        speaker_SUB = new QPushButton(widget);
        speaker_SUB->setObjectName(QStringLiteral("speaker_SUB"));
        speaker_SUB->setGeometry(QRect(160, 600, 51, 31));
        speaker_SUB->setMinimumSize(QSize(0, 0));
        speaker_SUB->setStyleSheet(QStringLiteral(""));
        speaker_SUB->setIconSize(QSize(70, 70));
        speaker_SUB->setCheckable(true);
        speaker_SUB->setChecked(false);
        speaker_SUB->setAutoRepeat(false);
        speaker_LFM = new QPushButton(widget);
        speaker_LFM->setObjectName(QStringLiteral("speaker_LFM"));
        speaker_LFM->setGeometry(QRect(1, 388, 59, 26));
        speaker_LFM->setMinimumSize(QSize(0, 0));
        speaker_LFM->setStyleSheet(QStringLiteral(""));
        speaker_LFM->setIconSize(QSize(30, 30));
        speaker_LFM->setCheckable(true);
        speaker_LFM->setChecked(false);
        speaker_LFM->setAutoRepeat(false);
        speaker_LFTW = new QPushButton(widget);
        speaker_LFTW->setObjectName(QStringLiteral("speaker_LFTW"));
        speaker_LFTW->setGeometry(QRect(1, 361, 59, 27));
        speaker_LFTW->setMinimumSize(QSize(0, 0));
        speaker_LFTW->setStyleSheet(QStringLiteral(""));
        speaker_LFTW->setIconSize(QSize(20, 20));
        speaker_LFTW->setCheckable(true);
        speaker_LFTW->setChecked(false);
        speaker_LFTW->setAutoRepeat(false);
        speaker_LFW = new QPushButton(widget);
        speaker_LFW->setObjectName(QStringLiteral("speaker_LFW"));
        speaker_LFW->setGeometry(QRect(1, 414, 59, 26));
        speaker_LFW->setMinimumSize(QSize(0, 0));
        speaker_LFW->setStyleSheet(QStringLiteral(""));
        speaker_LFW->setIconSize(QSize(30, 30));
        speaker_LFW->setCheckable(true);
        speaker_LFW->setChecked(false);
        speaker_LFW->setAutoRepeat(false);
        speaker_LSW = new QPushButton(widget);
        speaker_LSW->setObjectName(QStringLiteral("speaker_LSW"));
        speaker_LSW->setGeometry(QRect(1, 524, 59, 26));
        speaker_LSW->setMinimumSize(QSize(0, 0));
        speaker_LSW->setStyleSheet(QStringLiteral(""));
        speaker_LSW->setIconSize(QSize(70, 70));
        speaker_LSW->setCheckable(true);
        speaker_LSW->setChecked(false);
        speaker_LSW->setAutoRepeat(false);
        speaker_LSM = new QPushButton(widget);
        speaker_LSM->setObjectName(QStringLiteral("speaker_LSM"));
        speaker_LSM->setGeometry(QRect(1, 498, 59, 26));
        speaker_LSM->setMinimumSize(QSize(0, 0));
        speaker_LSM->setStyleSheet(QStringLiteral(""));
        speaker_LSM->setIconSize(QSize(70, 70));
        speaker_LSM->setCheckable(true);
        speaker_LSM->setChecked(false);
        speaker_LSM->setAutoRepeat(false);
        speaker_LSTW = new QPushButton(widget);
        speaker_LSTW->setObjectName(QStringLiteral("speaker_LSTW"));
        speaker_LSTW->setGeometry(QRect(1, 471, 59, 27));
        speaker_LSTW->setMinimumSize(QSize(0, 0));
        speaker_LSTW->setStyleSheet(QStringLiteral(""));
        speaker_LSTW->setIconSize(QSize(70, 70));
        speaker_LSTW->setCheckable(true);
        speaker_LSTW->setChecked(false);
        speaker_LSTW->setAutoRepeat(false);
        speaker_RFTW = new QPushButton(widget);
        speaker_RFTW->setObjectName(QStringLiteral("speaker_RFTW"));
        speaker_RFTW->setGeometry(QRect(321, 364, 59, 27));
        speaker_RFTW->setMinimumSize(QSize(0, 0));
        speaker_RFTW->setStyleSheet(QStringLiteral(""));
        speaker_RFTW->setIconSize(QSize(30, 30));
        speaker_RFTW->setCheckable(true);
        speaker_RFTW->setChecked(false);
        speaker_RFTW->setAutoRepeat(false);
        speaker_RFM = new QPushButton(widget);
        speaker_RFM->setObjectName(QStringLiteral("speaker_RFM"));
        speaker_RFM->setGeometry(QRect(321, 391, 59, 26));
        speaker_RFM->setMinimumSize(QSize(0, 0));
        speaker_RFM->setStyleSheet(QStringLiteral(""));
        speaker_RFM->setIconSize(QSize(70, 70));
        speaker_RFM->setCheckable(true);
        speaker_RFM->setChecked(false);
        speaker_RFM->setAutoRepeat(false);
        speaker_RFW = new QPushButton(widget);
        speaker_RFW->setObjectName(QStringLiteral("speaker_RFW"));
        speaker_RFW->setGeometry(QRect(321, 417, 59, 26));
        speaker_RFW->setMinimumSize(QSize(0, 0));
        speaker_RFW->setStyleSheet(QStringLiteral(""));
        speaker_RFW->setIconSize(QSize(70, 70));
        speaker_RFW->setCheckable(true);
        speaker_RFW->setChecked(false);
        speaker_RFW->setAutoRepeat(false);
        speaker_RSW = new QPushButton(widget);
        speaker_RSW->setObjectName(QStringLiteral("speaker_RSW"));
        speaker_RSW->setGeometry(QRect(321, 520, 59, 23));
        speaker_RSW->setMinimumSize(QSize(0, 0));
        speaker_RSW->setStyleSheet(QStringLiteral(""));
        speaker_RSW->setIconSize(QSize(70, 70));
        speaker_RSW->setCheckable(true);
        speaker_RSW->setChecked(false);
        speaker_RSW->setAutoRepeat(false);
        speaker_RSM = new QPushButton(widget);
        speaker_RSM->setObjectName(QStringLiteral("speaker_RSM"));
        speaker_RSM->setGeometry(QRect(321, 497, 59, 23));
        speaker_RSM->setMinimumSize(QSize(0, 0));
        speaker_RSM->setStyleSheet(QStringLiteral(""));
        speaker_RSM->setIconSize(QSize(70, 70));
        speaker_RSM->setCheckable(true);
        speaker_RSM->setChecked(false);
        speaker_RSM->setAutoRepeat(false);
        speaker_RSTW = new QPushButton(widget);
        speaker_RSTW->setObjectName(QStringLiteral("speaker_RSTW"));
        speaker_RSTW->setGeometry(QRect(321, 474, 59, 23));
        speaker_RSTW->setMinimumSize(QSize(0, 0));
        speaker_RSTW->setStyleSheet(QStringLiteral(""));
        speaker_RSTW->setIconSize(QSize(70, 70));
        speaker_RSTW->setCheckable(true);
        speaker_RSTW->setChecked(false);
        speaker_RSTW->setAutoRepeat(false);

        horizontalLayout_2->addWidget(widget);

        widget_5 = new QWidget(CalculateMag);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        verticalLayout_2 = new QVBoxLayout(widget_5);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        selectBox = new QComboBox(widget_5);
        selectBox->setObjectName(QStringLiteral("selectBox"));
        selectBox->setMinimumSize(QSize(100, 30));

        horizontalLayout->addWidget(selectBox);


        verticalLayout_2->addLayout(horizontalLayout);

        calcu_chart_widget = new QWidget(widget_5);
        calcu_chart_widget->setObjectName(QStringLiteral("calcu_chart_widget"));
        verticalLayout = new QVBoxLayout(calcu_chart_widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        freq_chart = new VoiceChart(calcu_chart_widget);
        freq_chart->setObjectName(QStringLiteral("freq_chart"));

        verticalLayout->addWidget(freq_chart);


        verticalLayout_2->addWidget(calcu_chart_widget);

        phaseWidget = new QWidget(widget_5);
        phaseWidget->setObjectName(QStringLiteral("phaseWidget"));
        verticalLayout_7 = new QVBoxLayout(phaseWidget);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        phase_chart = new VoiceChart(phaseWidget);
        phase_chart->setObjectName(QStringLiteral("phase_chart"));

        verticalLayout_7->addWidget(phase_chart);


        verticalLayout_2->addWidget(phaseWidget);

        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 1);

        horizontalLayout_2->addWidget(widget_5);


        retranslateUi(CalculateMag);

        QMetaObject::connectSlotsByName(CalculateMag);
    } // setupUi

    void retranslateUi(QWidget *CalculateMag)
    {
        CalculateMag->setWindowTitle(QApplication::translate("CalculateMag", "Form", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        speaker_HLF->setToolTip(QApplication::translate("CalculateMag", "\345\267\246\345\211\215\351\241\266\346\243\232", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        speaker_HLF->setText(QApplication::translate("CalculateMag", "HLF", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        speaker_HRF->setToolTip(QApplication::translate("CalculateMag", "\345\217\263\345\211\215\351\241\266\346\243\232", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        speaker_HRF->setText(QApplication::translate("CalculateMag", "HRF", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        speaker_HLS->setToolTip(QApplication::translate("CalculateMag", "\345\267\246\345\220\216\351\241\266\346\243\232", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        speaker_HLS->setText(QApplication::translate("CalculateMag", "HLS", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        speaker_HRS->setToolTip(QApplication::translate("CalculateMag", "\345\217\263\345\220\216\351\241\266\346\243\232", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        speaker_HRS->setText(QApplication::translate("CalculateMag", "HRS", Q_NULLPTR));
        importBtn->setText(QApplication::translate("CalculateMag", "\345\257\274\345\205\245", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        speaker_LR->setToolTip(QApplication::translate("CalculateMag", "\345\267\246\345\220\216\347\216\257\347\273\225", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        speaker_LR->setText(QApplication::translate("CalculateMag", "LR", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        speaker_RR->setToolTip(QApplication::translate("CalculateMag", "\345\217\263\345\220\216\347\216\257\347\273\225", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        speaker_RR->setText(QApplication::translate("CalculateMag", "RR", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        speaker_CTR->setToolTip(QApplication::translate("CalculateMag", "\344\270\255\347\275\256", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        speaker_CTR->setText(QApplication::translate("CalculateMag", "CTR", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        speaker_CTR_TW->setToolTip(QApplication::translate("CalculateMag", "\344\270\255\347\275\256\351\253\230\351\237\263", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        speaker_CTR_TW->setText(QApplication::translate("CalculateMag", "CTR-TW", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        speaker_HLL->setToolTip(QApplication::translate("CalculateMag", "\345\267\246\345\244\264\346\236\225", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        speaker_HLL->setText(QApplication::translate("CalculateMag", "H-L-L", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        speaker_HLR->setToolTip(QApplication::translate("CalculateMag", "\345\217\263\345\244\264\346\236\225", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        speaker_HLR->setText(QApplication::translate("CalculateMag", "H-L-R", Q_NULLPTR));
        location_RF->setText(QString());
        location_LF->setText(QString());
        location_LS->setText(QString());
        location_RS->setText(QString());
#ifndef QT_NO_TOOLTIP
        speaker_SUB->setToolTip(QApplication::translate("CalculateMag", "\351\207\215\344\275\216\351\237\263", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        speaker_SUB->setText(QApplication::translate("CalculateMag", "SUB", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        speaker_LFM->setToolTip(QApplication::translate("CalculateMag", "\345\267\246\345\211\215\344\270\255\351\237\263", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        speaker_LFM->setText(QApplication::translate("CalculateMag", "LFM", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        speaker_LFTW->setToolTip(QApplication::translate("CalculateMag", "\345\267\246\345\211\215\351\253\230\351\237\263", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        speaker_LFTW->setText(QApplication::translate("CalculateMag", "LFTW", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        speaker_LFW->setToolTip(QApplication::translate("CalculateMag", "\345\267\246\345\211\215\344\275\216\351\237\263", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        speaker_LFW->setText(QApplication::translate("CalculateMag", "LFW", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        speaker_LSW->setToolTip(QApplication::translate("CalculateMag", "\345\267\246\345\220\216\344\275\216\351\237\263", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        speaker_LSW->setText(QApplication::translate("CalculateMag", "LSW", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        speaker_LSM->setToolTip(QApplication::translate("CalculateMag", "\345\267\246\345\220\216\344\270\255\351\237\263", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        speaker_LSM->setText(QApplication::translate("CalculateMag", "LSM", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        speaker_LSTW->setToolTip(QApplication::translate("CalculateMag", "\345\267\246\345\220\216\351\253\230\351\237\263", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        speaker_LSTW->setText(QApplication::translate("CalculateMag", "LSTW", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        speaker_RFTW->setToolTip(QApplication::translate("CalculateMag", "\345\217\263\345\211\215\351\253\230\351\237\263", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        speaker_RFTW->setText(QApplication::translate("CalculateMag", "RFTW", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        speaker_RFM->setToolTip(QApplication::translate("CalculateMag", "\345\217\263\345\211\215\344\270\255\351\237\263", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        speaker_RFM->setText(QApplication::translate("CalculateMag", "RFM", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        speaker_RFW->setToolTip(QApplication::translate("CalculateMag", "\345\217\263\345\211\215\344\275\216\351\237\263", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        speaker_RFW->setText(QApplication::translate("CalculateMag", "RFW", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        speaker_RSW->setToolTip(QApplication::translate("CalculateMag", "\345\217\263\345\220\216\344\275\216\351\237\263", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        speaker_RSW->setText(QApplication::translate("CalculateMag", "RSW", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        speaker_RSM->setToolTip(QApplication::translate("CalculateMag", "\345\217\263\345\220\216\344\270\255\351\237\263", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        speaker_RSM->setText(QApplication::translate("CalculateMag", "RSM", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        speaker_RSTW->setToolTip(QApplication::translate("CalculateMag", "\345\217\263\345\220\216\351\253\230\351\237\263", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        speaker_RSTW->setText(QApplication::translate("CalculateMag", "RSTW", Q_NULLPTR));
        selectBox->clear();
        selectBox->insertItems(0, QStringList()
         << QApplication::translate("CalculateMag", "oneself_01", Q_NULLPTR)
         << QApplication::translate("CalculateMag", "oneself_02", Q_NULLPTR)
         << QApplication::translate("CalculateMag", "oneself_03", Q_NULLPTR)
         << QApplication::translate("CalculateMag", "oneself_04", Q_NULLPTR)
         << QApplication::translate("CalculateMag", "oneself_05", Q_NULLPTR)
         << QApplication::translate("CalculateMag", "oneself_06", Q_NULLPTR)
         << QApplication::translate("CalculateMag", "ALL", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class CalculateMag: public Ui_CalculateMag {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATEMAG_H
