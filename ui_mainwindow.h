/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad;
    QWidget *centralWidget;
    QLabel *image_label;
    QLabel *label_b;
    QSlider *horizontalSlider_bri;
    QPushButton *pushButton_gs;
    QSlider *horizontalSlider_RED;
    QLabel *label;
    QSlider *horizontalSlider_GREEN;
    QSlider *horizontalSlider_BLUE;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_blur;
    QPushButton *pushButton_save;
    QPushButton *pushButton_NI;
    QPushButton *pushButton_clear;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1100, 590);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        image_label = new QLabel(centralWidget);
        image_label->setObjectName(QStringLiteral("image_label"));
        image_label->setGeometry(QRect(350, 30, 691, 411));
        label_b = new QLabel(centralWidget);
        label_b->setObjectName(QStringLiteral("label_b"));
        label_b->setGeometry(QRect(20, 137, 71, 31));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(16);
        label_b->setFont(font);
        horizontalSlider_bri = new QSlider(centralWidget);
        horizontalSlider_bri->setObjectName(QStringLiteral("horizontalSlider_bri"));
        horizontalSlider_bri->setEnabled(false);
        horizontalSlider_bri->setGeometry(QRect(110, 145, 160, 22));
        horizontalSlider_bri->setMinimum(-50);
        horizontalSlider_bri->setMaximum(50);
        horizontalSlider_bri->setSingleStep(5);
        horizontalSlider_bri->setValue(0);
        horizontalSlider_bri->setSliderPosition(0);
        horizontalSlider_bri->setOrientation(Qt::Horizontal);
        pushButton_gs = new QPushButton(centralWidget);
        pushButton_gs->setObjectName(QStringLiteral("pushButton_gs"));
        pushButton_gs->setEnabled(false);
        pushButton_gs->setGeometry(QRect(20, 460, 81, 71));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(14);
        pushButton_gs->setFont(font1);
        horizontalSlider_RED = new QSlider(centralWidget);
        horizontalSlider_RED->setObjectName(QStringLiteral("horizontalSlider_RED"));
        horizontalSlider_RED->setEnabled(false);
        horizontalSlider_RED->setGeometry(QRect(110, 190, 160, 22));
        horizontalSlider_RED->setMinimum(-100);
        horizontalSlider_RED->setMaximum(100);
        horizontalSlider_RED->setOrientation(Qt::Horizontal);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 184, 41, 31));
        label->setFont(font);
        horizontalSlider_GREEN = new QSlider(centralWidget);
        horizontalSlider_GREEN->setObjectName(QStringLiteral("horizontalSlider_GREEN"));
        horizontalSlider_GREEN->setEnabled(false);
        horizontalSlider_GREEN->setGeometry(QRect(110, 240, 160, 22));
        horizontalSlider_GREEN->setMinimum(-100);
        horizontalSlider_GREEN->setMaximum(100);
        horizontalSlider_GREEN->setOrientation(Qt::Horizontal);
        horizontalSlider_BLUE = new QSlider(centralWidget);
        horizontalSlider_BLUE->setObjectName(QStringLiteral("horizontalSlider_BLUE"));
        horizontalSlider_BLUE->setEnabled(false);
        horizontalSlider_BLUE->setGeometry(QRect(110, 290, 160, 22));
        horizontalSlider_BLUE->setMinimum(-100);
        horizontalSlider_BLUE->setMaximum(100);
        horizontalSlider_BLUE->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 230, 51, 31));
        label_2->setFont(font);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 280, 51, 31));
        label_3->setFont(font);
        pushButton_blur = new QPushButton(centralWidget);
        pushButton_blur->setObjectName(QStringLiteral("pushButton_blur"));
        pushButton_blur->setEnabled(false);
        pushButton_blur->setGeometry(QRect(130, 460, 81, 71));
        pushButton_blur->setFont(font1);
        pushButton_save = new QPushButton(centralWidget);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));
        pushButton_save->setEnabled(false);
        pushButton_save->setGeometry(QRect(20, 10, 101, 81));
        QFont font2;
        font2.setFamily(QStringLiteral("Agency FB"));
        font2.setPointSize(20);
        pushButton_save->setFont(font2);
        pushButton_NI = new QPushButton(centralWidget);
        pushButton_NI->setObjectName(QStringLiteral("pushButton_NI"));
        pushButton_NI->setEnabled(false);
        pushButton_NI->setGeometry(QRect(240, 460, 81, 71));
        pushButton_NI->setFont(font1);
        pushButton_clear = new QPushButton(centralWidget);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));
        pushButton_clear->setEnabled(false);
        pushButton_clear->setGeometry(QRect(170, 10, 101, 81));
        pushButton_clear->setFont(font2);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1100, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLoad);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0));
        image_label->setText(QString());
        label_b->setText(QApplication::translate("MainWindow", "Brightness", 0));
        pushButton_gs->setText(QApplication::translate("MainWindow", "GrayScale", 0));
        label->setText(QApplication::translate("MainWindow", "RED", 0));
        label_2->setText(QApplication::translate("MainWindow", "GREEN", 0));
        label_3->setText(QApplication::translate("MainWindow", "BLUE", 0));
        pushButton_blur->setText(QApplication::translate("MainWindow", "BLUR", 0));
        pushButton_save->setText(QApplication::translate("MainWindow", "SAVE", 0));
        pushButton_NI->setText(QApplication::translate("MainWindow", "NI", 0));
        pushButton_clear->setText(QApplication::translate("MainWindow", "CLEAR", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
