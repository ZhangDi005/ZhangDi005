/********************************************************************************
** Form generated from reading UI file 'adgustmag.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADGUSTMAG_H
#define UI_ADGUSTMAG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Module\voicechart.h"

QT_BEGIN_NAMESPACE

class Ui_AdgustMag
{
public:
    QHBoxLayout *horizontalLayout_5;
    QWidget *listWidget_style;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QListWidget *listWidget;
    QSplitter *splitter_3;
    QSplitter *splitter;
    QWidget *customWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QComboBox *spaceComBox;
    QComboBox *locationComBox;
    VoiceChart *specificChart;
    QWidget *customWidget_1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_D;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *spaceAllBox;
    VoiceChart *overallChart;
    QSplitter *splitter_2;
    QWidget *customWidget_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *addBtn;
    QPushButton *removeBtn;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *copyBtn;
    QPushButton *pasteBtn;
    QSpacerItem *horizontalSpacer_5;
    QComboBox *speakerBox;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QCheckBox *checkBox_2;
    QSpacerItem *horizontalSpacer_3;
    QListWidget *listWidget_EQ;
    QWidget *customWidget_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QDoubleSpinBox *startBox;
    QLabel *label_11;
    QDoubleSpinBox *stopBox;
    QComboBox *micLocation;
    QComboBox *spaceComBox_1;
    QComboBox *locationComBox_1;
    QComboBox *patternBox;
    VoiceChart *phaseChart;

    void setupUi(QWidget *AdgustMag)
    {
        if (AdgustMag->objectName().isEmpty())
            AdgustMag->setObjectName(QStringLiteral("AdgustMag"));
        AdgustMag->resize(1458, 541);
        AdgustMag->setStyleSheet(QStringLiteral(""));
        horizontalLayout_5 = new QHBoxLayout(AdgustMag);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(9, 9, 9, 9);
        listWidget_style = new QWidget(AdgustMag);
        listWidget_style->setObjectName(QStringLiteral("listWidget_style"));
        listWidget_style->setMinimumSize(QSize(340, 0));
        listWidget_style->setMaximumSize(QSize(340, 16777215));
        verticalLayout_5 = new QVBoxLayout(listWidget_style);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(9, -1, 9, 9);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(15, -1, 0, -1);
        checkBox = new QCheckBox(listWidget_style);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout->addWidget(checkBox);

        label_2 = new QLabel(listWidget_style);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(70, 0));
        label_2->setMaximumSize(QSize(70, 16777215));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(listWidget_style);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(70, 0));
        label_3->setMaximumSize(QSize(70, 16777215));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_3);

        label_4 = new QLabel(listWidget_style);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(70, 0));
        label_4->setMaximumSize(QSize(70, 16777215));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_4);

        label_5 = new QLabel(listWidget_style);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_5);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 3);
        horizontalLayout->setStretch(3, 3);
        horizontalLayout->setStretch(4, 2);

        verticalLayout_5->addLayout(horizontalLayout);

        listWidget = new QListWidget(listWidget_style);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMinimumSize(QSize(322, 0));
        listWidget->setMaximumSize(QSize(322, 16777215));
        listWidget->setStyleSheet(QStringLiteral(""));
        listWidget->setDragDropMode(QAbstractItemView::InternalMove);

        verticalLayout_5->addWidget(listWidget);


        horizontalLayout_5->addWidget(listWidget_style);

        splitter_3 = new QSplitter(AdgustMag);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_3);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        customWidget = new QWidget(splitter);
        customWidget->setObjectName(QStringLiteral("customWidget"));
        verticalLayout = new QVBoxLayout(customWidget);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 5, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        spaceComBox = new QComboBox(customWidget);
        spaceComBox->setObjectName(QStringLiteral("spaceComBox"));

        horizontalLayout_2->addWidget(spaceComBox);

        locationComBox = new QComboBox(customWidget);
        locationComBox->setObjectName(QStringLiteral("locationComBox"));

        horizontalLayout_2->addWidget(locationComBox);


        verticalLayout->addLayout(horizontalLayout_2);

        specificChart = new VoiceChart(customWidget);
        specificChart->setObjectName(QStringLiteral("specificChart"));

        verticalLayout->addWidget(specificChart);

        splitter->addWidget(customWidget);
        customWidget_1 = new QWidget(splitter);
        customWidget_1->setObjectName(QStringLiteral("customWidget_1"));
        verticalLayout_2 = new QVBoxLayout(customWidget_1);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(-1, -1, 5, -1);
        horizontalLayout_D = new QHBoxLayout();
        horizontalLayout_D->setObjectName(QStringLiteral("horizontalLayout_D"));

        horizontalLayout_8->addLayout(horizontalLayout_D);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        spaceAllBox = new QComboBox(customWidget_1);
        spaceAllBox->setObjectName(QStringLiteral("spaceAllBox"));

        horizontalLayout_8->addWidget(spaceAllBox);


        verticalLayout_2->addLayout(horizontalLayout_8);

        overallChart = new VoiceChart(customWidget_1);
        overallChart->setObjectName(QStringLiteral("overallChart"));

        verticalLayout_2->addWidget(overallChart);

        splitter->addWidget(customWidget_1);
        splitter_3->addWidget(splitter);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setLineWidth(3);
        splitter_2->setOrientation(Qt::Horizontal);
        splitter_2->setHandleWidth(5);
        customWidget_2 = new QWidget(splitter_2);
        customWidget_2->setObjectName(QStringLiteral("customWidget_2"));
        customWidget_2->setMinimumSize(QSize(528, 0));
        customWidget_2->setMaximumSize(QSize(528, 16777215));
        verticalLayout_4 = new QVBoxLayout(customWidget_2);
        verticalLayout_4->setSpacing(5);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(9, 9, 9, 9);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, -1, 5, -1);
        addBtn = new QPushButton(customWidget_2);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        addBtn->setMaximumSize(QSize(25, 24));

        horizontalLayout_6->addWidget(addBtn);

        removeBtn = new QPushButton(customWidget_2);
        removeBtn->setObjectName(QStringLiteral("removeBtn"));
        removeBtn->setMaximumSize(QSize(25, 24));
        removeBtn->setStyleSheet(QStringLiteral(""));

        horizontalLayout_6->addWidget(removeBtn);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        copyBtn = new QPushButton(customWidget_2);
        copyBtn->setObjectName(QStringLiteral("copyBtn"));
        copyBtn->setMaximumSize(QSize(50, 24));
        QFont font;
        font.setPointSize(7);
        copyBtn->setFont(font);

        horizontalLayout_6->addWidget(copyBtn);

        pasteBtn = new QPushButton(customWidget_2);
        pasteBtn->setObjectName(QStringLiteral("pasteBtn"));
        pasteBtn->setEnabled(true);
        pasteBtn->setMaximumSize(QSize(50, 24));
        pasteBtn->setFont(font);

        horizontalLayout_6->addWidget(pasteBtn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        speakerBox = new QComboBox(customWidget_2);
        speakerBox->setObjectName(QStringLiteral("speakerBox"));
        speakerBox->setMaximumSize(QSize(16777215, 24));

        horizontalLayout_6->addWidget(speakerBox);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_4 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        label_6 = new QLabel(customWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(120, 0));
        label_6->setMaximumSize(QSize(120, 16777215));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_6);

        label_7 = new QLabel(customWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(60, 0));
        label_7->setMaximumSize(QSize(60, 16777215));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_7);

        label_8 = new QLabel(customWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(80, 0));
        label_8->setMaximumSize(QSize(80, 16777215));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_8);

        label_9 = new QLabel(customWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(80, 0));
        label_9->setMaximumSize(QSize(80, 16777215));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_9);

        label_10 = new QLabel(customWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(80, 0));
        label_10->setMaximumSize(QSize(80, 16777215));
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_10);

        checkBox_2 = new QCheckBox(customWidget_2);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setMinimumSize(QSize(20, 0));
        checkBox_2->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_7->addWidget(checkBox_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);


        verticalLayout_4->addLayout(horizontalLayout_7);

        listWidget_EQ = new QListWidget(customWidget_2);
        listWidget_EQ->setObjectName(QStringLiteral("listWidget_EQ"));
        listWidget_EQ->setMinimumSize(QSize(510, 0));
        listWidget_EQ->setMaximumSize(QSize(510, 16777215));
        listWidget_EQ->setDragDropMode(QAbstractItemView::InternalMove);

        verticalLayout_4->addWidget(listWidget_EQ);

        verticalLayout_4->setStretch(2, 1);
        splitter_2->addWidget(customWidget_2);
        customWidget_3 = new QWidget(splitter_2);
        customWidget_3->setObjectName(QStringLiteral("customWidget_3"));
        verticalLayout_3 = new QVBoxLayout(customWidget_3);
        verticalLayout_3->setSpacing(5);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(9, 9, 9, 9);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(5);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, 5, -1);
        label = new QLabel(customWidget_3);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        startBox = new QDoubleSpinBox(customWidget_3);
        startBox->setObjectName(QStringLiteral("startBox"));

        horizontalLayout_4->addWidget(startBox);

        label_11 = new QLabel(customWidget_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_4->addWidget(label_11);

        stopBox = new QDoubleSpinBox(customWidget_3);
        stopBox->setObjectName(QStringLiteral("stopBox"));

        horizontalLayout_4->addWidget(stopBox);

        micLocation = new QComboBox(customWidget_3);
        micLocation->setObjectName(QStringLiteral("micLocation"));
        micLocation->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_4->addWidget(micLocation);

        spaceComBox_1 = new QComboBox(customWidget_3);
        spaceComBox_1->setObjectName(QStringLiteral("spaceComBox_1"));

        horizontalLayout_4->addWidget(spaceComBox_1);

        locationComBox_1 = new QComboBox(customWidget_3);
        locationComBox_1->setObjectName(QStringLiteral("locationComBox_1"));

        horizontalLayout_4->addWidget(locationComBox_1);

        patternBox = new QComboBox(customWidget_3);
        patternBox->setObjectName(QStringLiteral("patternBox"));

        horizontalLayout_4->addWidget(patternBox);


        verticalLayout_3->addLayout(horizontalLayout_4);

        phaseChart = new VoiceChart(customWidget_3);
        phaseChart->setObjectName(QStringLiteral("phaseChart"));

        verticalLayout_3->addWidget(phaseChart);

        verticalLayout_3->setStretch(1, 1);
        splitter_2->addWidget(customWidget_3);
        splitter_3->addWidget(splitter_2);

        horizontalLayout_5->addWidget(splitter_3);


        retranslateUi(AdgustMag);

        micLocation->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AdgustMag);
    } // setupUi

    void retranslateUi(QWidget *AdgustMag)
    {
        AdgustMag->setWindowTitle(QApplication::translate("AdgustMag", "Form", Q_NULLPTR));
        checkBox->setText(QString());
        label_2->setText(QApplication::translate("AdgustMag", "Channel", Q_NULLPTR));
        label_3->setText(QApplication::translate("AdgustMag", " Gain", Q_NULLPTR));
        label_4->setText(QApplication::translate("AdgustMag", "  Delay", Q_NULLPTR));
        label_5->setText(QApplication::translate("AdgustMag", "Invert", Q_NULLPTR));
        spaceComBox->clear();
        spaceComBox->insertItems(0, QStringList()
         << QApplication::translate("AdgustMag", "Front", Q_NULLPTR)
         << QApplication::translate("AdgustMag", "Rear", Q_NULLPTR)
        );
        locationComBox->clear();
        locationComBox->insertItems(0, QStringList()
         << QApplication::translate("AdgustMag", "Driver", Q_NULLPTR)
         << QApplication::translate("AdgustMag", "Pass", Q_NULLPTR)
         << QApplication::translate("AdgustMag", "row", Q_NULLPTR)
        );
        spaceAllBox->clear();
        spaceAllBox->insertItems(0, QStringList()
         << QApplication::translate("AdgustMag", "Front", Q_NULLPTR)
         << QApplication::translate("AdgustMag", "Rear", Q_NULLPTR)
        );
        addBtn->setText(QApplication::translate("AdgustMag", "+", Q_NULLPTR));
        removeBtn->setText(QApplication::translate("AdgustMag", "-", Q_NULLPTR));
        copyBtn->setText(QApplication::translate("AdgustMag", "\345\244\215\345\210\266", Q_NULLPTR));
        pasteBtn->setText(QApplication::translate("AdgustMag", "\347\262\230\350\264\264", Q_NULLPTR));
        label_6->setText(QApplication::translate("AdgustMag", "Fliter Type", Q_NULLPTR));
        label_7->setText(QApplication::translate("AdgustMag", "Order", Q_NULLPTR));
        label_8->setText(QApplication::translate("AdgustMag", "Fc", Q_NULLPTR));
        label_9->setText(QApplication::translate("AdgustMag", "Gain", Q_NULLPTR));
        label_10->setText(QApplication::translate("AdgustMag", "Q", Q_NULLPTR));
        checkBox_2->setText(QString());
        label->setText(QApplication::translate("AdgustMag", "start:", Q_NULLPTR));
        startBox->setSuffix(QApplication::translate("AdgustMag", "s", Q_NULLPTR));
        label_11->setText(QApplication::translate("AdgustMag", "end:", Q_NULLPTR));
        stopBox->setSuffix(QApplication::translate("AdgustMag", "s", Q_NULLPTR));
        micLocation->clear();
        micLocation->insertItems(0, QStringList()
         << QApplication::translate("AdgustMag", "3", Q_NULLPTR)
         << QApplication::translate("AdgustMag", "4", Q_NULLPTR)
        );
        spaceComBox_1->clear();
        spaceComBox_1->insertItems(0, QStringList()
         << QApplication::translate("AdgustMag", "Front", Q_NULLPTR)
         << QApplication::translate("AdgustMag", "Rear", Q_NULLPTR)
        );
        locationComBox_1->clear();
        locationComBox_1->insertItems(0, QStringList()
         << QApplication::translate("AdgustMag", "Driver", Q_NULLPTR)
         << QApplication::translate("AdgustMag", "Pass", Q_NULLPTR)
         << QApplication::translate("AdgustMag", "row", Q_NULLPTR)
        );
        patternBox->clear();
        patternBox->insertItems(0, QStringList()
         << QApplication::translate("AdgustMag", "pahse", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class AdgustMag: public Ui_AdgustMag {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADGUSTMAG_H
