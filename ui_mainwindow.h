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
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad;
    QAction *actionExit;
    QAction *actionFuzzy;
    QAction *actionFourier;
    QAction *actionIdeal_Filter;
    QAction *actionButterworth;
    QAction *actionGaussian_Filter;
    QWidget *centralWidget;
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
    QPushButton *pushButton_load;
    QSlider *horizontalSlider_Contrast;
    QLabel *label_4;
    QLabel *image_label;
    QPushButton *pushButton_gs_2;
    QCustomPlot *customPlot;
    QPushButton *pushButton_du;
    QPushButton *pushButton_ZO;
    QPushButton *pushButton_ChangeRes;
    QPushButton *pushButton_ZI;
    QPushButton *pushButton_eq_;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label_5;
    QLabel *label_6;
    QTextBrowser *textBrowser;
    QTableWidget *tableWidget;
    QSpinBox *spinBox;
    QPushButton *pushButton_laplacian;
    QPushButton *pushButton_smoothing;
    QPushButton *pushButton_sobel;
    QPushButton *pushButton_sobel_2;
    QPushButton *pushButton_MH;
    QPushButton *pushButton_ZC;
    QPushButton *pushButton_Fourier;
    QSlider *horizontalSlider;
    QLCDNumber *lcdNumber;
    QPushButton *pushButton_HW5;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuLow_Pass_Filter;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1905, 1000);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionFuzzy = new QAction(MainWindow);
        actionFuzzy->setObjectName(QStringLiteral("actionFuzzy"));
        actionFourier = new QAction(MainWindow);
        actionFourier->setObjectName(QStringLiteral("actionFourier"));
        actionIdeal_Filter = new QAction(MainWindow);
        actionIdeal_Filter->setObjectName(QStringLiteral("actionIdeal_Filter"));
        actionButterworth = new QAction(MainWindow);
        actionButterworth->setObjectName(QStringLiteral("actionButterworth"));
        actionGaussian_Filter = new QAction(MainWindow);
        actionGaussian_Filter->setObjectName(QStringLiteral("actionGaussian_Filter"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
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
        horizontalSlider_bri->setMinimum(-60);
        horizontalSlider_bri->setMaximum(60);
        horizontalSlider_bri->setSingleStep(5);
        horizontalSlider_bri->setValue(0);
        horizontalSlider_bri->setSliderPosition(0);
        horizontalSlider_bri->setOrientation(Qt::Horizontal);
        pushButton_gs = new QPushButton(centralWidget);
        pushButton_gs->setObjectName(QStringLiteral("pushButton_gs"));
        pushButton_gs->setEnabled(false);
        pushButton_gs->setGeometry(QRect(20, 450, 81, 71));
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
        pushButton_blur->setGeometry(QRect(130, 450, 81, 71));
        pushButton_blur->setFont(font1);
        pushButton_save = new QPushButton(centralWidget);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));
        pushButton_save->setEnabled(false);
        pushButton_save->setGeometry(QRect(120, 10, 101, 81));
        QFont font2;
        font2.setFamily(QStringLiteral("Agency FB"));
        font2.setPointSize(20);
        pushButton_save->setFont(font2);
        pushButton_NI = new QPushButton(centralWidget);
        pushButton_NI->setObjectName(QStringLiteral("pushButton_NI"));
        pushButton_NI->setEnabled(false);
        pushButton_NI->setGeometry(QRect(240, 450, 81, 71));
        pushButton_NI->setFont(font1);
        pushButton_clear = new QPushButton(centralWidget);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));
        pushButton_clear->setEnabled(false);
        pushButton_clear->setGeometry(QRect(230, 10, 101, 81));
        pushButton_clear->setFont(font2);
        pushButton_load = new QPushButton(centralWidget);
        pushButton_load->setObjectName(QStringLiteral("pushButton_load"));
        pushButton_load->setEnabled(true);
        pushButton_load->setGeometry(QRect(10, 10, 101, 81));
        pushButton_load->setFont(font2);
        horizontalSlider_Contrast = new QSlider(centralWidget);
        horizontalSlider_Contrast->setObjectName(QStringLiteral("horizontalSlider_Contrast"));
        horizontalSlider_Contrast->setEnabled(false);
        horizontalSlider_Contrast->setGeometry(QRect(110, 330, 160, 22));
        horizontalSlider_Contrast->setMinimum(100);
        horizontalSlider_Contrast->setMaximum(130);
        horizontalSlider_Contrast->setSingleStep(5);
        horizontalSlider_Contrast->setPageStep(5);
        horizontalSlider_Contrast->setValue(100);
        horizontalSlider_Contrast->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(16, 323, 71, 31));
        label_4->setFont(font);
        image_label = new QLabel(centralWidget);
        image_label->setObjectName(QStringLiteral("image_label"));
        image_label->setGeometry(QRect(380, 20, 1221, 891));
        image_label->setAlignment(Qt::AlignCenter);
        pushButton_gs_2 = new QPushButton(centralWidget);
        pushButton_gs_2->setObjectName(QStringLiteral("pushButton_gs_2"));
        pushButton_gs_2->setEnabled(false);
        pushButton_gs_2->setGeometry(QRect(20, 530, 81, 71));
        pushButton_gs_2->setFont(font1);
        customPlot = new QCustomPlot(centralWidget);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(20, 620, 341, 311));
        pushButton_du = new QPushButton(centralWidget);
        pushButton_du->setObjectName(QStringLiteral("pushButton_du"));
        pushButton_du->setEnabled(false);
        pushButton_du->setGeometry(QRect(130, 530, 81, 71));
        pushButton_du->setFont(font1);
        pushButton_ZO = new QPushButton(centralWidget);
        pushButton_ZO->setObjectName(QStringLiteral("pushButton_ZO"));
        pushButton_ZO->setEnabled(false);
        pushButton_ZO->setGeometry(QRect(240, 370, 81, 71));
        pushButton_ZO->setFont(font1);
        pushButton_ChangeRes = new QPushButton(centralWidget);
        pushButton_ChangeRes->setObjectName(QStringLiteral("pushButton_ChangeRes"));
        pushButton_ChangeRes->setEnabled(false);
        pushButton_ChangeRes->setGeometry(QRect(20, 370, 81, 71));
        pushButton_ChangeRes->setFont(font1);
        pushButton_ZI = new QPushButton(centralWidget);
        pushButton_ZI->setObjectName(QStringLiteral("pushButton_ZI"));
        pushButton_ZI->setEnabled(false);
        pushButton_ZI->setGeometry(QRect(130, 370, 81, 71));
        pushButton_ZI->setFont(font1);
        pushButton_eq_ = new QPushButton(centralWidget);
        pushButton_eq_->setObjectName(QStringLiteral("pushButton_eq_"));
        pushButton_eq_->setEnabled(false);
        pushButton_eq_->setGeometry(QRect(240, 530, 81, 71));
        pushButton_eq_->setFont(font1);
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setEnabled(true);
        radioButton->setGeometry(QRect(1700, 40, 101, 31));
        radioButton->setFont(font);
        radioButton_2 = new QRadioButton(centralWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setEnabled(true);
        radioButton_2->setGeometry(QRect(1700, 70, 101, 31));
        radioButton_2->setFont(font);
        radioButton_2->setCheckable(true);
        radioButton_2->setChecked(false);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setEnabled(true);
        label_5->setGeometry(QRect(1700, 10, 101, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Agency FB"));
        font3.setPointSize(18);
        label_5->setFont(font3);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setEnabled(true);
        label_6->setGeometry(QRect(1700, 120, 101, 31));
        label_6->setFont(font3);
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setEnabled(true);
        textBrowser->setGeometry(QRect(1690, 160, 161, 45));
        textBrowser->setFont(font);
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(1610, 310, 251, 261));
        QFont font4;
        font4.setPointSize(12);
        tableWidget->setFont(font4);
        tableWidget->setAutoScroll(false);
        tableWidget->setTextElideMode(Qt::ElideLeft);
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(1690, 220, 111, 31));
        spinBox->setFont(font1);
        spinBox->setMinimum(3);
        spinBox->setMaximum(30);
        spinBox->setSingleStep(2);
        spinBox->setValue(3);
        pushButton_laplacian = new QPushButton(centralWidget);
        pushButton_laplacian->setObjectName(QStringLiteral("pushButton_laplacian"));
        pushButton_laplacian->setGeometry(QRect(1670, 600, 151, 101));
        pushButton_laplacian->setFont(font);
        pushButton_smoothing = new QPushButton(centralWidget);
        pushButton_smoothing->setObjectName(QStringLiteral("pushButton_smoothing"));
        pushButton_smoothing->setGeometry(QRect(1670, 720, 151, 101));
        pushButton_smoothing->setFont(font);
        pushButton_sobel = new QPushButton(centralWidget);
        pushButton_sobel->setObjectName(QStringLiteral("pushButton_sobel"));
        pushButton_sobel->setGeometry(QRect(1500, 840, 151, 101));
        pushButton_sobel->setFont(font);
        pushButton_sobel_2 = new QPushButton(centralWidget);
        pushButton_sobel_2->setObjectName(QStringLiteral("pushButton_sobel_2"));
        pushButton_sobel_2->setGeometry(QRect(1670, 840, 151, 101));
        pushButton_sobel_2->setFont(font);
        pushButton_MH = new QPushButton(centralWidget);
        pushButton_MH->setObjectName(QStringLiteral("pushButton_MH"));
        pushButton_MH->setGeometry(QRect(1500, 720, 151, 101));
        pushButton_MH->setFont(font);
        pushButton_ZC = new QPushButton(centralWidget);
        pushButton_ZC->setObjectName(QStringLiteral("pushButton_ZC"));
        pushButton_ZC->setGeometry(QRect(1500, 600, 151, 101));
        pushButton_ZC->setFont(font);
        pushButton_Fourier = new QPushButton(centralWidget);
        pushButton_Fourier->setObjectName(QStringLiteral("pushButton_Fourier"));
        pushButton_Fourier->setEnabled(true);
        pushButton_Fourier->setGeometry(QRect(70, 820, 81, 71));
        pushButton_Fourier->setFont(font1);
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(60, 760, 231, 22));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(500);
        horizontalSlider->setValue(250);
        horizontalSlider->setOrientation(Qt::Horizontal);
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(60, 710, 231, 41));
        lcdNumber->setProperty("value", QVariant(250));
        pushButton_HW5 = new QPushButton(centralWidget);
        pushButton_HW5->setObjectName(QStringLiteral("pushButton_HW5"));
        pushButton_HW5->setEnabled(false);
        pushButton_HW5->setGeometry(QRect(20, 370, 331, 281));
        pushButton_HW5->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1905, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuLow_Pass_Filter = new QMenu(menuEdit);
        menuLow_Pass_Filter->setObjectName(QStringLiteral("menuLow_Pass_Filter"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionFuzzy);
        menuEdit->addAction(actionFourier);
        menuEdit->addAction(menuLow_Pass_Filter->menuAction());
        menuLow_Pass_Filter->addAction(actionIdeal_Filter);
        menuLow_Pass_Filter->addAction(actionButterworth);
        menuLow_Pass_Filter->addAction(actionGaussian_Filter);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), lcdNumber, SLOT(display(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionFuzzy->setText(QApplication::translate("MainWindow", "Fuzzy", 0));
        actionFourier->setText(QApplication::translate("MainWindow", "Fourier", 0));
        actionIdeal_Filter->setText(QApplication::translate("MainWindow", "Ideal Filter", 0));
        actionButterworth->setText(QApplication::translate("MainWindow", "Butterworth Filter", 0));
        actionGaussian_Filter->setText(QApplication::translate("MainWindow", "Gaussian Filter", 0));
        label_b->setText(QApplication::translate("MainWindow", "Brightness", 0));
        pushButton_gs->setText(QApplication::translate("MainWindow", "GrayScale", 0));
        label->setText(QApplication::translate("MainWindow", "RED", 0));
        label_2->setText(QApplication::translate("MainWindow", "GREEN", 0));
        label_3->setText(QApplication::translate("MainWindow", "BLUE", 0));
        pushButton_blur->setText(QApplication::translate("MainWindow", "BLUR", 0));
        pushButton_save->setText(QApplication::translate("MainWindow", "SAVE", 0));
        pushButton_NI->setText(QApplication::translate("MainWindow", "NI", 0));
        pushButton_clear->setText(QApplication::translate("MainWindow", "CLEAR", 0));
        pushButton_load->setText(QApplication::translate("MainWindow", "LOAD", 0));
        label_4->setText(QApplication::translate("MainWindow", "CONTRAST", 0));
        image_label->setText(QString());
        pushButton_gs_2->setText(QApplication::translate("MainWindow", "GrayScale2", 0));
        pushButton_du->setText(QApplication::translate("MainWindow", "Dualization", 0));
        pushButton_ZO->setText(QApplication::translate("MainWindow", "ZOOM OUT", 0));
        pushButton_ChangeRes->setText(QApplication::translate("MainWindow", "Change Res", 0));
        pushButton_ZI->setText(QApplication::translate("MainWindow", "ZOOM IN", 0));
        pushButton_eq_->setText(QApplication::translate("MainWindow", "Hist Eq.", 0));
        radioButton->setText(QApplication::translate("MainWindow", "Simple", 0));
        radioButton_2->setText(QApplication::translate("MainWindow", "Gaussian", 0));
        label_5->setText(QApplication::translate("MainWindow", "Mask Type", 0));
        label_6->setText(QApplication::translate("MainWindow", "Mask Size", 0));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Agency FB'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">3X3</p></body></html>", 0));
        pushButton_laplacian->setText(QApplication::translate("MainWindow", "Laplacian", 0));
        pushButton_smoothing->setText(QApplication::translate("MainWindow", "Smoothing", 0));
        pushButton_sobel->setText(QApplication::translate("MainWindow", "Sobel (I)", 0));
        pushButton_sobel_2->setText(QApplication::translate("MainWindow", "Sobel (II)", 0));
        pushButton_MH->setText(QApplication::translate("MainWindow", "Marr-Hildreth", 0));
        pushButton_ZC->setText(QApplication::translate("MainWindow", "Zero-Crossing", 0));
        pushButton_Fourier->setText(QApplication::translate("MainWindow", "Fourier", 0));
        pushButton_HW5->setText(QApplication::translate("MainWindow", "HW5", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuLow_Pass_Filter->setTitle(QApplication::translate("MainWindow", "Low Pass Filter", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
