/********************************************************************************
** Form generated from reading UI file 'draftbtn.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAFTBTN_H
#define UI_DRAFTBTN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DraftBtn
{
public:
    QGridLayout *gridLayout;

    void setupUi(QWidget *DraftBtn)
    {
        if (DraftBtn->objectName().isEmpty())
            DraftBtn->setObjectName(QStringLiteral("DraftBtn"));
        DraftBtn->resize(24, 24);
        gridLayout = new QGridLayout(DraftBtn);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(DraftBtn);

        QMetaObject::connectSlotsByName(DraftBtn);
    } // setupUi

    void retranslateUi(QWidget *DraftBtn)
    {
        DraftBtn->setWindowTitle(QApplication::translate("DraftBtn", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DraftBtn: public Ui_DraftBtn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAFTBTN_H
