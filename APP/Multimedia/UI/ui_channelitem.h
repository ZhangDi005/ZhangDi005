/********************************************************************************
** Form generated from reading UI file 'channelitem.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANNELITEM_H
#define UI_CHANNELITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChannelItem
{
public:
    QHBoxLayout *horizontalLayout;
    QCheckBox *selected;
    QLabel *name;
    QDoubleSpinBox *gainSpinBox;
    QDoubleSpinBox *delaySpinBox;
    QCheckBox *invert;

    void setupUi(QWidget *ChannelItem)
    {
        if (ChannelItem->objectName().isEmpty())
            ChannelItem->setObjectName(QStringLiteral("ChannelItem"));
        ChannelItem->resize(312, 31);
        ChannelItem->setMinimumSize(QSize(312, 0));
        ChannelItem->setMaximumSize(QSize(312, 16777215));
        horizontalLayout = new QHBoxLayout(ChannelItem);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 3, -1, 3);
        selected = new QCheckBox(ChannelItem);
        selected->setObjectName(QStringLiteral("selected"));

        horizontalLayout->addWidget(selected);

        name = new QLabel(ChannelItem);
        name->setObjectName(QStringLiteral("name"));
        name->setMinimumSize(QSize(90, 0));
        name->setMaximumSize(QSize(90, 16777215));
        name->setStyleSheet(QStringLiteral(""));
        name->setFrameShadow(QFrame::Plain);
        name->setLineWidth(1);
        name->setMidLineWidth(0);
        name->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(name);

        gainSpinBox = new QDoubleSpinBox(ChannelItem);
        gainSpinBox->setObjectName(QStringLiteral("gainSpinBox"));
        gainSpinBox->setMaximumSize(QSize(70, 16777215));
        gainSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        gainSpinBox->setMinimum(-1000);
        gainSpinBox->setMaximum(1000.99);

        horizontalLayout->addWidget(gainSpinBox);

        delaySpinBox = new QDoubleSpinBox(ChannelItem);
        delaySpinBox->setObjectName(QStringLiteral("delaySpinBox"));
        delaySpinBox->setMaximumSize(QSize(70, 16777215));
        delaySpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        delaySpinBox->setMaximum(1000.99);

        horizontalLayout->addWidget(delaySpinBox);

        invert = new QCheckBox(ChannelItem);
        invert->setObjectName(QStringLiteral("invert"));

        horizontalLayout->addWidget(invert);


        retranslateUi(ChannelItem);

        QMetaObject::connectSlotsByName(ChannelItem);
    } // setupUi

    void retranslateUi(QWidget *ChannelItem)
    {
        ChannelItem->setWindowTitle(QApplication::translate("ChannelItem", "Form", Q_NULLPTR));
        selected->setText(QString());
        name->setText(QApplication::translate("ChannelItem", "test", Q_NULLPTR));
        invert->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChannelItem: public Ui_ChannelItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANNELITEM_H
