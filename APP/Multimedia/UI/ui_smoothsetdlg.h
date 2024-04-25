/********************************************************************************
** Form generated from reading UI file 'smoothsetdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMOOTHSETDLG_H
#define UI_SMOOTHSETDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_SmoothSetDlg
{
public:
    QGridLayout *gridLayout;
    QRadioButton *noSmoothBtn;
    QRadioButton *oneThirdBtn;
    QRadioButton *onesixthBtn;
    QRadioButton *onetwelfthBtn;
    QRadioButton *oneTwenty_fourthBtn;
    QRadioButton *oneForty_eighthBtn;
    QPushButton *okBtn;

    void setupUi(QDialog *SmoothSetDlg)
    {
        if (SmoothSetDlg->objectName().isEmpty())
            SmoothSetDlg->setObjectName(QStringLiteral("SmoothSetDlg"));
        SmoothSetDlg->resize(437, 319);
        gridLayout = new QGridLayout(SmoothSetDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        noSmoothBtn = new QRadioButton(SmoothSetDlg);
        noSmoothBtn->setObjectName(QStringLiteral("noSmoothBtn"));

        gridLayout->addWidget(noSmoothBtn, 0, 0, 1, 1);

        oneThirdBtn = new QRadioButton(SmoothSetDlg);
        oneThirdBtn->setObjectName(QStringLiteral("oneThirdBtn"));

        gridLayout->addWidget(oneThirdBtn, 0, 1, 1, 1);

        onesixthBtn = new QRadioButton(SmoothSetDlg);
        onesixthBtn->setObjectName(QStringLiteral("onesixthBtn"));

        gridLayout->addWidget(onesixthBtn, 1, 0, 1, 1);

        onetwelfthBtn = new QRadioButton(SmoothSetDlg);
        onetwelfthBtn->setObjectName(QStringLiteral("onetwelfthBtn"));

        gridLayout->addWidget(onetwelfthBtn, 1, 1, 1, 1);

        oneTwenty_fourthBtn = new QRadioButton(SmoothSetDlg);
        oneTwenty_fourthBtn->setObjectName(QStringLiteral("oneTwenty_fourthBtn"));

        gridLayout->addWidget(oneTwenty_fourthBtn, 2, 0, 1, 1);

        oneForty_eighthBtn = new QRadioButton(SmoothSetDlg);
        oneForty_eighthBtn->setObjectName(QStringLiteral("oneForty_eighthBtn"));

        gridLayout->addWidget(oneForty_eighthBtn, 2, 1, 1, 1);

        okBtn = new QPushButton(SmoothSetDlg);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        gridLayout->addWidget(okBtn, 3, 1, 1, 1);


        retranslateUi(SmoothSetDlg);

        QMetaObject::connectSlotsByName(SmoothSetDlg);
    } // setupUi

    void retranslateUi(QDialog *SmoothSetDlg)
    {
        SmoothSetDlg->setWindowTitle(QApplication::translate("SmoothSetDlg", "Dialog", Q_NULLPTR));
        noSmoothBtn->setText(QApplication::translate("SmoothSetDlg", "NoSmppoth", Q_NULLPTR));
        oneThirdBtn->setText(QApplication::translate("SmoothSetDlg", "1/3", Q_NULLPTR));
        onesixthBtn->setText(QApplication::translate("SmoothSetDlg", "1/6", Q_NULLPTR));
        onetwelfthBtn->setText(QApplication::translate("SmoothSetDlg", "1/12", Q_NULLPTR));
        oneTwenty_fourthBtn->setText(QApplication::translate("SmoothSetDlg", "1/24", Q_NULLPTR));
        oneForty_eighthBtn->setText(QApplication::translate("SmoothSetDlg", "1/48", Q_NULLPTR));
        okBtn->setText(QApplication::translate("SmoothSetDlg", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SmoothSetDlg: public Ui_SmoothSetDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMOOTHSETDLG_H
