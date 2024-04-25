/********************************************************************************
** Form generated from reading UI file 'range.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANGE_H
#define UI_RANGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Range
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *x_min;
    QLabel *label_3;
    QDoubleSpinBox *x_max;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *y_min;
    QLabel *label_4;
    QDoubleSpinBox *y_max;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;

    void setupUi(QDialog *Range)
    {
        if (Range->objectName().isEmpty())
            Range->setObjectName(QStringLiteral("Range"));
        Range->resize(264, 186);
        verticalLayout_2 = new QVBoxLayout(Range);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(Range);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        x_min = new QDoubleSpinBox(groupBox);
        x_min->setObjectName(QStringLiteral("x_min"));
        x_min->setMinimumSize(QSize(70, 0));
        x_min->setButtonSymbols(QAbstractSpinBox::NoButtons);
        x_min->setDecimals(0);
        x_min->setMinimum(-1000);
        x_min->setMaximum(20000);

        horizontalLayout->addWidget(x_min);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_3);

        x_max = new QDoubleSpinBox(groupBox);
        x_max->setObjectName(QStringLiteral("x_max"));
        x_max->setMinimumSize(QSize(70, 0));
        x_max->setButtonSymbols(QAbstractSpinBox::NoButtons);
        x_max->setDecimals(0);
        x_max->setMaximum(25000);

        horizontalLayout->addWidget(x_max);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        y_min = new QDoubleSpinBox(groupBox);
        y_min->setObjectName(QStringLiteral("y_min"));
        y_min->setMinimumSize(QSize(70, 0));
        y_min->setButtonSymbols(QAbstractSpinBox::NoButtons);
        y_min->setDecimals(0);
        y_min->setMinimum(-10000);
        y_min->setMaximum(20000);

        horizontalLayout_2->addWidget(y_min);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_4);

        y_max = new QDoubleSpinBox(groupBox);
        y_max->setObjectName(QStringLiteral("y_max"));
        y_max->setMinimumSize(QSize(70, 0));
        y_max->setButtonSymbols(QAbstractSpinBox::NoButtons);
        y_max->setDecimals(0);
        y_max->setMinimum(-10000);
        y_max->setMaximum(20000);

        horizontalLayout_2->addWidget(y_max);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        okBtn = new QPushButton(Range);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout_3->addWidget(okBtn);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalLayout_2->setStretch(0, 1);

        retranslateUi(Range);

        QMetaObject::connectSlotsByName(Range);
    } // setupUi

    void retranslateUi(QDialog *Range)
    {
        Range->setWindowTitle(QApplication::translate("Range", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Range", "Range", Q_NULLPTR));
        label->setText(QApplication::translate("Range", "X:", Q_NULLPTR));
        label_3->setText(QApplication::translate("Range", "-", Q_NULLPTR));
        label_2->setText(QApplication::translate("Range", "Y:", Q_NULLPTR));
        label_4->setText(QApplication::translate("Range", "-", Q_NULLPTR));
        okBtn->setText(QApplication::translate("Range", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Range: public Ui_Range {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANGE_H
