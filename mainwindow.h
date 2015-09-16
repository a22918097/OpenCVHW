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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

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

private:
    Ui::MainWindow *ui;
    cv::Mat img;
    cv::Mat raw;
    void changeColor(const cv::Mat &src,cv::Mat &dst,QVector<int> value);
    QImage Mat2QImage(const cv::Mat src);
    void showImage(const cv::Mat &src);
};

#endif // MAINWINDOW_H
