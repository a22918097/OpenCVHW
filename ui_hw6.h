/********************************************************************************
** Form generated from reading UI file 'hw6.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HW6_H
#define UI_HW6_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_hw6
{
public:
    QLabel *label_main;
    QLabel *label_disp;
    QPushButton *pushButton_trap;
    QPushButton *pushButton_wavy;
    QPushButton *pushButton_circular;
    QPushButton *pushButton_Hough;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *hw6)
    {
        if (hw6->objectName().isEmpty())
            hw6->setObjectName(QStringLiteral("hw6"));
        hw6->resize(1900, 1000);
        label_main = new QLabel(hw6);
        label_main->setObjectName(QStringLiteral("label_main"));
        label_main->setGeometry(QRect(40, 30, 800, 800));
        QFont font;
        font.setPointSize(30);
        label_main->setFont(font);
        label_main->setAlignment(Qt::AlignCenter);
        label_disp = new QLabel(hw6);
        label_disp->setObjectName(QStringLiteral("label_disp"));
        label_disp->setGeometry(QRect(960, 30, 800, 800));
        label_disp->setFont(font);
        label_disp->setAlignment(Qt::AlignCenter);
        pushButton_trap = new QPushButton(hw6);
        pushButton_trap->setObjectName(QStringLiteral("pushButton_trap"));
        pushButton_trap->setGeometry(QRect(50, 840, 161, 120));
        QFont font1;
        font1.setPointSize(24);
        pushButton_trap->setFont(font1);
        pushButton_wavy = new QPushButton(hw6);
        pushButton_wavy->setObjectName(QStringLiteral("pushButton_wavy"));
        pushButton_wavy->setGeometry(QRect(270, 840, 120, 120));
        pushButton_wavy->setFont(font1);
        pushButton_circular = new QPushButton(hw6);
        pushButton_circular->setObjectName(QStringLiteral("pushButton_circular"));
        pushButton_circular->setGeometry(QRect(490, 840, 120, 120));
        pushButton_circular->setFont(font1);
        pushButton_Hough = new QPushButton(hw6);
        pushButton_Hough->setObjectName(QStringLiteral("pushButton_Hough"));
        pushButton_Hough->setGeometry(QRect(710, 840, 120, 120));
        pushButton_Hough->setFont(font1);
        textBrowser = new QTextBrowser(hw6);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(880, 841, 231, 141));
        QFont font2;
        font2.setFamily(QStringLiteral("Adobe Devanagari"));
        font2.setPointSize(12);
        textBrowser->setFont(font2);

        retranslateUi(hw6);

        QMetaObject::connectSlotsByName(hw6);
    } // setupUi

    void retranslateUi(QDialog *hw6)
    {
        hw6->setWindowTitle(QApplication::translate("hw6", "Dialog", 0));
        label_main->setText(QApplication::translate("hw6", "Source Image", 0));
        label_disp->setText(QApplication::translate("hw6", "Display", 0));
        pushButton_trap->setText(QApplication::translate("hw6", "Trapezoidal", 0));
        pushButton_wavy->setText(QApplication::translate("hw6", "Wavy", 0));
        pushButton_circular->setText(QApplication::translate("hw6", "Circular", 0));
        pushButton_Hough->setText(QApplication::translate("hw6", "Hough", 0));
    } // retranslateUi

};

namespace Ui {
    class hw6: public Ui_hw6 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HW6_H
