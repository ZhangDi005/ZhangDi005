/********************************************************************************
** Form generated from reading UI file 'serialprot.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPROT_H
#define UI_SERIALPROT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialProt
{
public:
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout_11;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *refresh;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *portBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *portBox_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *portBox_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *portBox_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QComboBox *portBox_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QComboBox *portBox_7;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *openSerial;
    QPushButton *closeSerial;
    QLabel *led;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *filePath;
    QPushButton *selectPath;
    QProgressBar *progressBar;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer;
    QPushButton *downLoad;
    QPushButton *cancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *SerialProt)
    {
        if (SerialProt->objectName().isEmpty())
            SerialProt->setObjectName(QStringLiteral("SerialProt"));
        SerialProt->resize(1001, 625);
        horizontalLayout_12 = new QHBoxLayout(SerialProt);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        groupBox = new QGroupBox(SerialProt);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        refresh = new QPushButton(groupBox);
        refresh->setObjectName(QStringLiteral("refresh"));

        verticalLayout->addWidget(refresh);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";"));

        horizontalLayout->addWidget(label);

        portBox = new QComboBox(groupBox);
        portBox->setObjectName(QStringLiteral("portBox"));
        portBox->setMinimumSize(QSize(0, 35));

        horizontalLayout->addWidget(portBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";"));

        horizontalLayout_3->addWidget(label_3);

        portBox_3 = new QComboBox(groupBox);
        portBox_3->setObjectName(QStringLiteral("portBox_3"));
        portBox_3->setMinimumSize(QSize(0, 35));

        horizontalLayout_3->addWidget(portBox_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";"));

        horizontalLayout_4->addWidget(label_4);

        portBox_4 = new QComboBox(groupBox);
        portBox_4->setObjectName(QStringLiteral("portBox_4"));
        portBox_4->setMinimumSize(QSize(0, 35));

        horizontalLayout_4->addWidget(portBox_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";"));

        horizontalLayout_5->addWidget(label_5);

        portBox_5 = new QComboBox(groupBox);
        portBox_5->setObjectName(QStringLiteral("portBox_5"));
        portBox_5->setMinimumSize(QSize(0, 35));

        horizontalLayout_5->addWidget(portBox_5);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";"));

        horizontalLayout_6->addWidget(label_6);

        portBox_6 = new QComboBox(groupBox);
        portBox_6->setObjectName(QStringLiteral("portBox_6"));
        portBox_6->setMinimumSize(QSize(0, 35));

        horizontalLayout_6->addWidget(portBox_6);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";"));

        horizontalLayout_7->addWidget(label_7);

        portBox_7 = new QComboBox(groupBox);
        portBox_7->setObjectName(QStringLiteral("portBox_7"));
        portBox_7->setMinimumSize(QSize(0, 35));

        horizontalLayout_7->addWidget(portBox_7);


        verticalLayout->addLayout(horizontalLayout_7);


        horizontalLayout_11->addWidget(groupBox);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        openSerial = new QPushButton(SerialProt);
        openSerial->setObjectName(QStringLiteral("openSerial"));

        horizontalLayout_8->addWidget(openSerial);

        closeSerial = new QPushButton(SerialProt);
        closeSerial->setObjectName(QStringLiteral("closeSerial"));

        horizontalLayout_8->addWidget(closeSerial);

        led = new QLabel(SerialProt);
        led->setObjectName(QStringLiteral("led"));
        led->setMinimumSize(QSize(25, 25));
        led->setMaximumSize(QSize(25, 25));
        led->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));

        horizontalLayout_8->addWidget(led);


        verticalLayout_2->addLayout(horizontalLayout_8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        filePath = new QLineEdit(SerialProt);
        filePath->setObjectName(QStringLiteral("filePath"));
        filePath->setMinimumSize(QSize(0, 35));
        filePath->setFrame(false);
        filePath->setReadOnly(true);

        horizontalLayout_9->addWidget(filePath);

        selectPath = new QPushButton(SerialProt);
        selectPath->setObjectName(QStringLiteral("selectPath"));
        selectPath->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_9->addWidget(selectPath);

        horizontalLayout_9->setStretch(0, 15);
        horizontalLayout_9->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_9);

        progressBar = new QProgressBar(SerialProt);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        verticalLayout_2->addWidget(progressBar);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);

        downLoad = new QPushButton(SerialProt);
        downLoad->setObjectName(QStringLiteral("downLoad"));

        horizontalLayout_10->addWidget(downLoad);

        cancel = new QPushButton(SerialProt);
        cancel->setObjectName(QStringLiteral("cancel"));

        horizontalLayout_10->addWidget(cancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_10);


        horizontalLayout_11->addLayout(verticalLayout_2);

        horizontalLayout_11->setStretch(0, 3);
        horizontalLayout_11->setStretch(1, 5);

        horizontalLayout_12->addLayout(horizontalLayout_11);

        horizontalLayout_12->setStretch(0, 3);

        retranslateUi(SerialProt);

        QMetaObject::connectSlotsByName(SerialProt);
    } // setupUi

    void retranslateUi(QWidget *SerialProt)
    {
        SerialProt->setWindowTitle(QApplication::translate("SerialProt", "Form", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("SerialProt", "\344\270\262\345\217\243\350\256\276\347\275\256", Q_NULLPTR));
        refresh->setText(QApplication::translate("SerialProt", "\345\210\267\346\226\260", Q_NULLPTR));
        label->setText(QApplication::translate("SerialProt", "\344\270\262\345\217\243\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("SerialProt", "\346\263\242\347\211\271\347\216\207\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("SerialProt", "\345\201\234\346\255\242\344\275\215\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("SerialProt", "\346\225\260\346\215\256\344\275\215\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("SerialProt", "\346\240\241\351\252\214\344\275\215\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("SerialProt", "\346\216\247\345\210\266\346\265\201\357\274\232", Q_NULLPTR));
        openSerial->setText(QApplication::translate("SerialProt", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        closeSerial->setText(QApplication::translate("SerialProt", "\345\205\263\351\227\255\344\270\262\345\217\243", Q_NULLPTR));
        led->setText(QString());
        filePath->setText(QString());
        selectPath->setText(QApplication::translate("SerialProt", "...", Q_NULLPTR));
        downLoad->setText(QApplication::translate("SerialProt", "\344\270\213\350\275\275", Q_NULLPTR));
        cancel->setText(QApplication::translate("SerialProt", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SerialProt: public Ui_SerialProt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPROT_H
