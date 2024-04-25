/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include "Adgust\adgustmag.h"
#include "Gather\calculatemag.h"
#include "Send\serialprot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionfreqChart;
    QAction *actionphaseChart;
    QAction *actionGather;
    QAction *actionAdgust;
    QAction *actionSend;
    QAction *actionSmooth;
    QAction *actionimport;
    QAction *actionexport;
    QAction *actionNew_Import;
    QAction *actionSave;
    QAction *actionOpen;
    QAction *actionbnb;
    QAction *actionOne;
    QAction *actiontwo;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    CalculateMag *calculatemag;
    AdgustMag *adgustMag;
    SerialProt *serialPort;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menuEQF;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_H;
    QMenu *menu_5;
    QMenu *menuSetStyle;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1136, 705);
        actionfreqChart = new QAction(MainWindow);
        actionfreqChart->setObjectName(QStringLiteral("actionfreqChart"));
        actionfreqChart->setCheckable(true);
        actionphaseChart = new QAction(MainWindow);
        actionphaseChart->setObjectName(QStringLiteral("actionphaseChart"));
        actionphaseChart->setCheckable(true);
        actionGather = new QAction(MainWindow);
        actionGather->setObjectName(QStringLiteral("actionGather"));
        actionAdgust = new QAction(MainWindow);
        actionAdgust->setObjectName(QStringLiteral("actionAdgust"));
        actionSend = new QAction(MainWindow);
        actionSend->setObjectName(QStringLiteral("actionSend"));
        actionSmooth = new QAction(MainWindow);
        actionSmooth->setObjectName(QStringLiteral("actionSmooth"));
        actionimport = new QAction(MainWindow);
        actionimport->setObjectName(QStringLiteral("actionimport"));
        actionexport = new QAction(MainWindow);
        actionexport->setObjectName(QStringLiteral("actionexport"));
        actionNew_Import = new QAction(MainWindow);
        actionNew_Import->setObjectName(QStringLiteral("actionNew_Import"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionbnb = new QAction(MainWindow);
        actionbnb->setObjectName(QStringLiteral("actionbnb"));
        actionOne = new QAction(MainWindow);
        actionOne->setObjectName(QStringLiteral("actionOne"));
        actiontwo = new QAction(MainWindow);
        actiontwo->setObjectName(QStringLiteral("actiontwo"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        calculatemag = new CalculateMag();
        calculatemag->setObjectName(QStringLiteral("calculatemag"));
        stackedWidget->addWidget(calculatemag);
        adgustMag = new AdgustMag();
        adgustMag->setObjectName(QStringLiteral("adgustMag"));
        stackedWidget->addWidget(adgustMag);
        serialPort = new SerialProt();
        serialPort->setObjectName(QStringLiteral("serialPort"));
        stackedWidget->addWidget(serialPort);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1136, 29));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        menuEQF = new QMenu(menu);
        menuEQF->setObjectName(QStringLiteral("menuEQF"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        menu_H = new QMenu(menubar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        menu_5 = new QMenu(menubar);
        menu_5->setObjectName(QStringLiteral("menu_5"));
        menuSetStyle = new QMenu(menu_5);
        menuSetStyle->setObjectName(QStringLiteral("menuSetStyle"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menubar->addAction(menu_5->menuAction());
        menubar->addAction(menu_H->menuAction());
        menu->addAction(actionNew_Import);
        menu->addAction(menuEQF->menuAction());
        menu->addSeparator();
        menu->addAction(actionOpen);
        menu->addAction(actionSave);
        menuEQF->addAction(actionimport);
        menuEQF->addAction(actionexport);
        menu_3->addAction(actionfreqChart);
        menu_3->addAction(actionphaseChart);
        menu_4->addAction(actionGather);
        menu_4->addAction(actionAdgust);
        menu_4->addAction(actionSend);
        menu_H->addAction(actionbnb);
        menu_5->addAction(actionSmooth);
        menu_5->addAction(menuSetStyle->menuAction());
        menuSetStyle->addAction(actionOne);
        menuSetStyle->addAction(actiontwo);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionfreqChart->setText(QApplication::translate("MainWindow", "freqChart", Q_NULLPTR));
        actionphaseChart->setText(QApplication::translate("MainWindow", "phaseChart", Q_NULLPTR));
        actionGather->setText(QApplication::translate("MainWindow", "Gather", Q_NULLPTR));
        actionAdgust->setText(QApplication::translate("MainWindow", "Adgust", Q_NULLPTR));
        actionSend->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        actionSmooth->setText(QApplication::translate("MainWindow", "Smooth", Q_NULLPTR));
        actionimport->setText(QApplication::translate("MainWindow", "Import", Q_NULLPTR));
        actionexport->setText(QApplication::translate("MainWindow", "Export", Q_NULLPTR));
        actionNew_Import->setText(QApplication::translate("MainWindow", "New Import", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionbnb->setText(QApplication::translate("MainWindow", "\347\211\210\346\234\254\345\217\267", Q_NULLPTR));
        actionOne->setText(QApplication::translate("MainWindow", "one", Q_NULLPTR));
        actiontwo->setText(QApplication::translate("MainWindow", "two", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(F)", Q_NULLPTR));
        menuEQF->setTitle(QApplication::translate("MainWindow", "EQF", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(E)", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWindow", "\350\247\206\345\233\276(S)", Q_NULLPTR));
        menu_4->setTitle(QApplication::translate("MainWindow", "\346\250\241\345\274\217(P)", Q_NULLPTR));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(H)", Q_NULLPTR));
        menu_5->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256(I)", Q_NULLPTR));
        menuSetStyle->setTitle(QApplication::translate("MainWindow", "SetStyle", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
