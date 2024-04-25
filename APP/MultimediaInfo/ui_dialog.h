/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_company;
    QLineEdit *lineEdit_company;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_job;
    QLineEdit *lineEdit_job;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QToolButton *btn_create;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(590, 468);
        horizontalLayout_5 = new QHBoxLayout(Dialog);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        widget = new QWidget(Dialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(450, 450));
        widget->setMaximumSize(QSize(450, 450));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(450, 50));
        label->setMaximumSize(QSize(450, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_company = new QLabel(widget);
        label_company->setObjectName(QStringLiteral("label_company"));
        label_company->setMinimumSize(QSize(95, 50));
        label_company->setMaximumSize(QSize(95, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label_company->setFont(font1);

        horizontalLayout->addWidget(label_company);

        lineEdit_company = new QLineEdit(widget);
        lineEdit_company->setObjectName(QStringLiteral("lineEdit_company"));
        lineEdit_company->setMinimumSize(QSize(350, 50));
        lineEdit_company->setMaximumSize(QSize(350, 50));
        lineEdit_company->setFont(font1);

        horizontalLayout->addWidget(lineEdit_company);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_job = new QLabel(widget);
        label_job->setObjectName(QStringLiteral("label_job"));
        label_job->setMinimumSize(QSize(95, 50));
        label_job->setMaximumSize(QSize(95, 50));
        label_job->setFont(font1);
        label_job->setLayoutDirection(Qt::LeftToRight);
        label_job->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_job);

        lineEdit_job = new QLineEdit(widget);
        lineEdit_job->setObjectName(QStringLiteral("lineEdit_job"));
        lineEdit_job->setMinimumSize(QSize(350, 50));
        lineEdit_job->setMaximumSize(QSize(350, 50));
        lineEdit_job->setFont(font1);

        horizontalLayout_2->addWidget(lineEdit_job);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_name = new QLabel(widget);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setMinimumSize(QSize(95, 50));
        label_name->setMaximumSize(QSize(95, 50));
        label_name->setFont(font1);
        label_name->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_name);

        lineEdit_name = new QLineEdit(widget);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));
        lineEdit_name->setMinimumSize(QSize(350, 50));
        lineEdit_name->setMaximumSize(QSize(350, 50));
        lineEdit_name->setFont(font1);

        horizontalLayout_3->addWidget(lineEdit_name);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(5);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        btn_create = new QToolButton(widget);
        btn_create->setObjectName(QStringLiteral("btn_create"));
        btn_create->setMinimumSize(QSize(0, 43));
        btn_create->setFont(font1);
        btn_create->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_4->addWidget(btn_create);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_5->addWidget(widget);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "Multimedia License System", Q_NULLPTR));
        label_company->setText(QApplication::translate("Dialog", "\345\205\254\345\217\270\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        label_job->setText(QApplication::translate("Dialog", "\350\201\214  \344\275\215\357\274\232", Q_NULLPTR));
        label_name->setText(QApplication::translate("Dialog", "\345\247\223  \345\220\215\357\274\232", Q_NULLPTR));
        btn_create->setText(QApplication::translate("Dialog", "\347\224\237\346\210\220\344\277\241\346\201\257\347\240\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
