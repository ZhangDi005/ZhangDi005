/********************************************************************************
** Form generated from reading UI file 'helpdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPDLG_H
#define UI_HELPDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_HelpDlg
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;

    void setupUi(QDialog *HelpDlg)
    {
        if (HelpDlg->objectName().isEmpty())
            HelpDlg->setObjectName(QStringLiteral("HelpDlg"));
        HelpDlg->resize(523, 526);
        verticalLayout = new QVBoxLayout(HelpDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit = new QTextEdit(HelpDlg);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setStyleSheet(QStringLiteral(""));
        textEdit->setTabChangesFocus(false);
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);


        retranslateUi(HelpDlg);

        QMetaObject::connectSlotsByName(HelpDlg);
    } // setupUi

    void retranslateUi(QDialog *HelpDlg)
    {
        HelpDlg->setWindowTitle(QApplication::translate("HelpDlg", "Dialog", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("HelpDlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">\350\255\246\345\221\212\357\274\232\345\275\223\345\211\215\347\211\210\346\234\254\344\273\205\346\224\257\346\214\20148k\357\274\21432\344\275\215\346\267\261\351\207\207\346\240\267\347\216\207\357\274\233</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">\347\211\210\346\234\254\357\274\232v1.0.0</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-blo"
                        "ck-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">13.10.0.8469</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HelpDlg: public Ui_HelpDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPDLG_H
