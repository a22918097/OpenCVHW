/********************************************************************************
** Form generated from reading UI file 'hw5.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HW5_H
#define UI_HW5_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_hw5
{
public:
    QLabel *label_main;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_CMY;
    QPushButton *pushButton_HSI;
    QPushButton *pushButton_XYZ;
    QPushButton *pushButton_LAB;
    QPushButton *pushButton_YUV;
    QLabel *label_colorbar;
    QPushButton *pushButton_pseudo;
    QLabel *label_pseudocolor;
    QPushButton *pushButton_RGB;

    void setupUi(QDialog *hw5)
    {
        if (hw5->objectName().isEmpty())
            hw5->setObjectName(QStringLiteral("hw5"));
        hw5->resize(1900, 1000);
        label_main = new QLabel(hw5);
        label_main->setObjectName(QStringLiteral("label_main"));
        label_main->setGeometry(QRect(1400, 10, 481, 371));
        label_1 = new QLabel(hw5);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setGeometry(QRect(60, 390, 600, 600));
        label_2 = new QLabel(hw5);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(680, 390, 600, 600));
        label_3 = new QLabel(hw5);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1290, 390, 600, 600));
        pushButton_CMY = new QPushButton(hw5);
        pushButton_CMY->setObjectName(QStringLiteral("pushButton_CMY"));
        pushButton_CMY->setGeometry(QRect(30, 30, 91, 71));
        QFont font;
        font.setPointSize(18);
        pushButton_CMY->setFont(font);
        pushButton_HSI = new QPushButton(hw5);
        pushButton_HSI->setObjectName(QStringLiteral("pushButton_HSI"));
        pushButton_HSI->setGeometry(QRect(170, 30, 91, 71));
        pushButton_HSI->setFont(font);
        pushButton_XYZ = new QPushButton(hw5);
        pushButton_XYZ->setObjectName(QStringLiteral("pushButton_XYZ"));
        pushButton_XYZ->setGeometry(QRect(310, 30, 91, 71));
        pushButton_XYZ->setFont(font);
        pushButton_LAB = new QPushButton(hw5);
        pushButton_LAB->setObjectName(QStringLiteral("pushButton_LAB"));
        pushButton_LAB->setGeometry(QRect(450, 30, 91, 71));
        pushButton_LAB->setFont(font);
        pushButton_YUV = new QPushButton(hw5);
        pushButton_YUV->setObjectName(QStringLiteral("pushButton_YUV"));
        pushButton_YUV->setGeometry(QRect(590, 30, 91, 71));
        pushButton_YUV->setFont(font);
        label_colorbar = new QLabel(hw5);
        label_colorbar->setObjectName(QStringLiteral("label_colorbar"));
        label_colorbar->setGeometry(QRect(270, 160, 256, 51));
        pushButton_pseudo = new QPushButton(hw5);
        pushButton_pseudo->setObjectName(QStringLiteral("pushButton_pseudo"));
        pushButton_pseudo->setGeometry(QRect(30, 140, 141, 71));
        pushButton_pseudo->setFont(font);
        label_pseudocolor = new QLabel(hw5);
        label_pseudocolor->setObjectName(QStringLiteral("label_pseudocolor"));
        label_pseudocolor->setGeometry(QRect(400, 220, 800, 800));
        pushButton_RGB = new QPushButton(hw5);
        pushButton_RGB->setObjectName(QStringLiteral("pushButton_RGB"));
        pushButton_RGB->setGeometry(QRect(30, 250, 91, 71));
        pushButton_RGB->setFont(font);

        retranslateUi(hw5);

        QMetaObject::connectSlotsByName(hw5);
    } // setupUi

    void retranslateUi(QDialog *hw5)
    {
        hw5->setWindowTitle(QApplication::translate("hw5", "Dialog", 0));
        label_main->setText(QString());
        label_1->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        pushButton_CMY->setText(QApplication::translate("hw5", "CMY", 0));
        pushButton_HSI->setText(QApplication::translate("hw5", "HSI", 0));
        pushButton_XYZ->setText(QApplication::translate("hw5", "XYZ", 0));
        pushButton_LAB->setText(QApplication::translate("hw5", "L*A*b", 0));
        pushButton_YUV->setText(QApplication::translate("hw5", "YUV", 0));
        label_colorbar->setText(QString());
        pushButton_pseudo->setText(QApplication::translate("hw5", "Pseudo color", 0));
        label_pseudocolor->setText(QString());
        pushButton_RGB->setText(QApplication::translate("hw5", "RGB", 0));
    } // retranslateUi

};

namespace Ui {
    class hw5: public Ui_hw5 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HW5_H
