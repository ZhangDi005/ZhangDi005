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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QToolButton *btn_import;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QToolButton *btn_create;
    QTextBrowser *text_info;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(498, 468);
        horizontalLayout_2 = new QHBoxLayout(Dialog);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        widget = new QWidget(Dialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(480, 450));
        widget->setMaximumSize(QSize(480, 450));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(480, 50));
        label->setMaximumSize(QSize(480, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_import = new QToolButton(widget);
        btn_import->setObjectName(QStringLiteral("btn_import"));
        btn_import->setMinimumSize(QSize(0, 35));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        btn_import->setFont(font1);
        btn_import->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(btn_import);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 35));
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 45));
        lineEdit->setFont(font1);
        lineEdit->setClearButtonEnabled(false);

        horizontalLayout->addWidget(lineEdit);

        btn_create = new QToolButton(widget);
        btn_create->setObjectName(QStringLiteral("btn_create"));
        btn_create->setMinimumSize(QSize(0, 35));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(9);
        btn_create->setFont(font2);
        btn_create->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(btn_create);


        verticalLayout->addLayout(horizontalLayout);

        text_info = new QTextBrowser(widget);
        text_info->setObjectName(QStringLiteral("text_info"));
        text_info->setMaximumSize(QSize(16777215, 300));
        text_info->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        text_info->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        verticalLayout->addWidget(text_info);


        horizontalLayout_2->addWidget(widget);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "Multimedia License System", Q_NULLPTR));
        btn_import->setText(QApplication::translate("Dialog", "\345\257\274\345\205\245\344\277\241\346\201\257", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "\344\275\277\347\224\250\345\244\251\346\225\260", Q_NULLPTR));
        btn_create->setText(QApplication::translate("Dialog", "\347\224\237\346\210\220License", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
