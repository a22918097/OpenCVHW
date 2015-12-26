#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "opencv2/opencv.hpp"
#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <QDebug>
#include <QVector>
#include <QImage>
#include <QRgb>
#include <QPixmap>
#include <QVector>
#include <QPen>
#include "qcustomplot.h"
#include "dialogfuzzylogic.h"
#include "hw5.h"
#include "hw6.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    cv::Mat final;
    cv::Mat finalrel;
    cv::Mat finalimg;

private slots:
    void on_actionLoad_triggered();

    void on_pushButton_gs_clicked();

    void on_horizontalSlider_bri_valueChanged(int value);


    void on_horizontalSlider_RED_valueChanged(int value);

    void on_horizontalSlider_GREEN_valueChanged(int value);

    void on_horizontalSlider_BLUE_valueChanged(int value);

    void on_pushButton_blur_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_NI_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_load_clicked();

    void on_horizontalSlider_Contrast_valueChanged(int value);

    void on_actionExit_triggered();

    void on_pushButton_gs_2_clicked();

    void on_pushButton_du_clicked();

    void on_pushButton_ZO_clicked();

    void on_pushButton_ChangeRes_clicked();

    void on_pushButton_ZI_clicked();

    void on_pushButton_eq__clicked();



    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_laplacian_clicked();


    void on_pushButton_smoothing_clicked();

    void on_pushButton_sobel_clicked();

    void on_pushButton_sobel_2_clicked();

    void on_pushButton_MH_clicked();

    void on_actionFuzzy_triggered();

    void on_pushButton_ZC_clicked();

    void on_actionFourier_triggered();

    void on_pushButton_Fourier_clicked();

    void on_actionIdeal_Filter_triggered();

    void on_pushButton_HW5_clicked();


    void on_pushButton_HW6_clicked();

    void on_pushButton_threshold_clicked();

private:
    Ui::MainWindow *ui;
    cv::Mat temp;
    cv::Mat raw;
    cv::Mat src;
    cv::Mat dst1;
    cv::Mat save;
    QImage Mat2QImage(const cv::Mat src);
    void changeColor(const cv::Mat &src,cv::Mat &dst,QVector<int> value);

    void showImage(const cv::Mat &src);
    cv::Mat dst;
    QVector<double> gray;
    QVector<double> x;
    int sum=0;
};

#endif // MAINWINDOW_H
