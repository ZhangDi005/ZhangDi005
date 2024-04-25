/********************************************************************************
** Form generated from reading UI file 'addchannel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCHANNEL_H
#define UI_ADDCHANNEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddChannel
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *nameEdit;
    QLabel *label_2;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *AddChannel)
    {
        if (AddChannel->objectName().isEmpty())
            AddChannel->setObjectName(QStringLiteral("AddChannel"));
        AddChannel->resize(292, 148);
        verticalLayout = new QVBoxLayout(AddChannel);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(AddChannel);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(30, -1, 30, -1);
        nameEdit = new QLineEdit(groupBox);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setClearButtonEnabled(false);

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(groupBox);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox->setMinimum(-1000);
        doubleSpinBox->setMaximum(1000.99);
        doubleSpinBox->setValue(-30);

        gridLayout->addWidget(doubleSpinBox, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, -1, 20, -1);
        pushButton = new QPushButton(AddChannel);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(AddChannel);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AddChannel);

        QMetaObject::connectSlotsByName(AddChannel);
    } // setupUi

    void retranslateUi(QWidget *AddChannel)
    {
        AddChannel->setWindowTitle(QApplication::translate("AddChannel", "Form", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("AddChannel", "Add", Q_NULLPTR));
        nameEdit->setInputMask(QString());
        nameEdit->setText(QString());
        label_2->setText(QApplication::translate("AddChannel", "Gain:", Q_NULLPTR));
        label->setText(QApplication::translate("AddChannel", "Name:", Q_NULLPTR));
        doubleSpinBox->setSuffix(QApplication::translate("AddChannel", "db", Q_NULLPTR));
        pushButton->setText(QApplication::translate("AddChannel", "Cancel", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("AddChannel", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddChannel: public Ui_AddChannel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCHANNEL_H
