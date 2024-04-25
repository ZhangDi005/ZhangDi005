/********************************************************************************
** Form generated from reading UI file 'eqitem.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EQITEM_H
#define UI_EQITEM_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EqItem
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *type;
    QComboBox *Order;
    QDoubleSpinBox *spinBox_fc;
    QDoubleSpinBox *spinBox_gain;
    QDoubleSpinBox *spinBox_q;
    QCheckBox *selectedBtn;

    void setupUi(QWidget *EqItem)
    {
        if (EqItem->objectName().isEmpty())
            EqItem->setObjectName(QStringLiteral("EqItem"));
        EqItem->resize(485, 31);
        EqItem->setMaximumSize(QSize(501, 16777215));
        horizontalLayout = new QHBoxLayout(EqItem);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 3, -1, 3);
        label = new QLabel(EqItem);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        type = new QComboBox(EqItem);
        type->setObjectName(QStringLiteral("type"));
        type->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(type);

        Order = new QComboBox(EqItem);
        Order->setObjectName(QStringLiteral("Order"));
        Order->setMinimumSize(QSize(60, 0));
        Order->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(Order);

        spinBox_fc = new QDoubleSpinBox(EqItem);
        spinBox_fc->setObjectName(QStringLiteral("spinBox_fc"));
        spinBox_fc->setMaximumSize(QSize(80, 16777215));
        spinBox_fc->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_fc->setDecimals(0);
        spinBox_fc->setMaximum(20000);

        horizontalLayout->addWidget(spinBox_fc);

        spinBox_gain = new QDoubleSpinBox(EqItem);
        spinBox_gain->setObjectName(QStringLiteral("spinBox_gain"));
        spinBox_gain->setMaximumSize(QSize(80, 16777215));
        spinBox_gain->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_gain->setDecimals(2);
        spinBox_gain->setMinimum(-1000);
        spinBox_gain->setMaximum(1000);

        horizontalLayout->addWidget(spinBox_gain);

        spinBox_q = new QDoubleSpinBox(EqItem);
        spinBox_q->setObjectName(QStringLiteral("spinBox_q"));
        spinBox_q->setMaximumSize(QSize(80, 16777215));
        spinBox_q->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_q->setDecimals(3);
        spinBox_q->setMinimum(-1000);
        spinBox_q->setMaximum(1000.99);

        horizontalLayout->addWidget(spinBox_q);

        selectedBtn = new QCheckBox(EqItem);
        selectedBtn->setObjectName(QStringLiteral("selectedBtn"));

        horizontalLayout->addWidget(selectedBtn);


        retranslateUi(EqItem);

        QMetaObject::connectSlotsByName(EqItem);
    } // setupUi

    void retranslateUi(QWidget *EqItem)
    {
        EqItem->setWindowTitle(QApplication::translate("EqItem", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("EqItem", "1", Q_NULLPTR));
        type->clear();
        type->insertItems(0, QStringList()
         << QApplication::translate("EqItem", "Parametric", Q_NULLPTR)
         << QApplication::translate("EqItem", "Bass Shelf", Q_NULLPTR)
         << QApplication::translate("EqItem", "Treble Shelf", Q_NULLPTR)
         << QApplication::translate("EqItem", "Phase Changer", Q_NULLPTR)
         << QApplication::translate("EqItem", "Lowpass LR", Q_NULLPTR)
         << QApplication::translate("EqItem", "Highpass LR", Q_NULLPTR)
         << QApplication::translate("EqItem", "Lowpass BW", Q_NULLPTR)
         << QApplication::translate("EqItem", "Highpass BW", Q_NULLPTR)
         << QApplication::translate("EqItem", "Bandpass", Q_NULLPTR)
         << QApplication::translate("EqItem", "Bypass", Q_NULLPTR)
        );
        Order->clear();
        Order->insertItems(0, QStringList()
         << QApplication::translate("EqItem", "2", Q_NULLPTR)
        );
        selectedBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EqItem: public Ui_EqItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQITEM_H
