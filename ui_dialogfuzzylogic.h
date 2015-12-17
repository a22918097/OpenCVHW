/********************************************************************************
** Form generated from reading UI file 'dialogfuzzylogic.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGFUZZYLOGIC_H
#define UI_DIALOGFUZZYLOGIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include <qsmartlabel.h>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_DialogFuzzyLogic
{
public:
    QDialogButtonBox *buttonBox;
    QSmartLabel *label_fuzzy;
    QGroupBox *groupBox;
    QCustomPlot *bellShapePlot;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSlider *horizontalSlider_bellThreshold;
    QSpinBox *spinBox_bellThreshold;
    QGroupBox *groupBox_2;
    QCustomPlot *triangPlot;
    QLabel *label_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QSlider *horizontalSlider_outputLeftBound;
    QSpinBox *spinBox_outputLeftBound;
    QLabel *label_3;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QSlider *horizontalSlider_outputRightBound;
    QSpinBox *spinBox_outputRightBound;

    void setupUi(QDialog *DialogFuzzyLogic)
    {
        if (DialogFuzzyLogic->objectName().isEmpty())
            DialogFuzzyLogic->setObjectName(QStringLiteral("DialogFuzzyLogic"));
        DialogFuzzyLogic->resize(1072, 567);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/simpleProcessing.ico"), QSize(), QIcon::Normal, QIcon::Off);
        DialogFuzzyLogic->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(DialogFuzzyLogic);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(900, 530, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);
        label_fuzzy = new QSmartLabel(DialogFuzzyLogic);
        label_fuzzy->setObjectName(QStringLiteral("label_fuzzy"));
        label_fuzzy->setGeometry(QRect(10, 10, 720, 550));
        label_fuzzy->setStyleSheet(QStringLiteral("background-color: rgb(76, 76, 76);"));
        label_fuzzy->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(DialogFuzzyLogic);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(740, 10, 321, 231));
        bellShapePlot = new QCustomPlot(groupBox);
        bellShapePlot->setObjectName(QStringLiteral("bellShapePlot"));
        bellShapePlot->setGeometry(QRect(10, 20, 300, 150));
        bellShapePlot->setStyleSheet(QStringLiteral("background-color: rgb(76, 76, 76);"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 180, 71, 16));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 200, 301, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSlider_bellThreshold = new QSlider(layoutWidget);
        horizontalSlider_bellThreshold->setObjectName(QStringLiteral("horizontalSlider_bellThreshold"));
        horizontalSlider_bellThreshold->setMaximum(255);
        horizontalSlider_bellThreshold->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider_bellThreshold);

        spinBox_bellThreshold = new QSpinBox(layoutWidget);
        spinBox_bellThreshold->setObjectName(QStringLiteral("spinBox_bellThreshold"));
        spinBox_bellThreshold->setMaximum(255);
        spinBox_bellThreshold->setValue(255);
        spinBox_bellThreshold->setDisplayIntegerBase(10);

        horizontalLayout->addWidget(spinBox_bellThreshold);

        groupBox_2 = new QGroupBox(DialogFuzzyLogic);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(740, 250, 321, 281));
        triangPlot = new QCustomPlot(groupBox_2);
        triangPlot->setObjectName(QStringLiteral("triangPlot"));
        triangPlot->setGeometry(QRect(10, 20, 300, 150));
        triangPlot->setStyleSheet(QStringLiteral("background-color: rgb(76, 76, 76);"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 180, 71, 16));
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 200, 301, 24));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSlider_outputLeftBound = new QSlider(layoutWidget1);
        horizontalSlider_outputLeftBound->setObjectName(QStringLiteral("horizontalSlider_outputLeftBound"));
        horizontalSlider_outputLeftBound->setMaximum(255);
        horizontalSlider_outputLeftBound->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider_outputLeftBound);

        spinBox_outputLeftBound = new QSpinBox(layoutWidget1);
        spinBox_outputLeftBound->setObjectName(QStringLiteral("spinBox_outputLeftBound"));
        spinBox_outputLeftBound->setMaximum(255);
        spinBox_outputLeftBound->setValue(255);
        spinBox_outputLeftBound->setDisplayIntegerBase(10);

        horizontalLayout_2->addWidget(spinBox_outputLeftBound);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 230, 81, 16));
        layoutWidget_2 = new QWidget(groupBox_2);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 250, 301, 24));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSlider_outputRightBound = new QSlider(layoutWidget_2);
        horizontalSlider_outputRightBound->setObjectName(QStringLiteral("horizontalSlider_outputRightBound"));
        horizontalSlider_outputRightBound->setMaximum(255);
        horizontalSlider_outputRightBound->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(horizontalSlider_outputRightBound);

        spinBox_outputRightBound = new QSpinBox(layoutWidget_2);
        spinBox_outputRightBound->setObjectName(QStringLiteral("spinBox_outputRightBound"));
        spinBox_outputRightBound->setMaximum(255);
        spinBox_outputRightBound->setValue(255);
        spinBox_outputRightBound->setDisplayIntegerBase(10);

        horizontalLayout_5->addWidget(spinBox_outputRightBound);


        retranslateUi(DialogFuzzyLogic);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogFuzzyLogic, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogFuzzyLogic, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogFuzzyLogic);
    } // setupUi

    void retranslateUi(QDialog *DialogFuzzyLogic)
    {
        DialogFuzzyLogic->setWindowTitle(QApplication::translate("DialogFuzzyLogic", "Fuzzy Edge", 0));
        label_fuzzy->setText(QString());
        groupBox->setTitle(QApplication::translate("DialogFuzzyLogic", "Edge Threshold", 0));
        label->setText(QApplication::translate("DialogFuzzyLogic", "Threshold:", 0));
        groupBox_2->setTitle(QApplication::translate("DialogFuzzyLogic", "Output Model", 0));
        label_2->setText(QApplication::translate("DialogFuzzyLogic", "WH delta:", 0));
        label_3->setText(QApplication::translate("DialogFuzzyLogic", "BL delta:", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogFuzzyLogic: public Ui_DialogFuzzyLogic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFUZZYLOGIC_H
