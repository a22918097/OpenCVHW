#ifndef HW5_H
#define HW5_H

#include <QDialog>
#include "opencv2/opencv.hpp"
namespace Ui {
class hw5;
}

class hw5 : public QDialog
{
    Q_OBJECT

public:
    explicit hw5(QWidget *parent = 0);
    void readImage(cv::Mat &img);
    void pseudocolortable();
    ~hw5();

private slots:

    void on_pushButton_CMY_clicked();

    void on_pushButton_HSI_clicked();

    void on_pushButton_XYZ_clicked();

    void on_pushButton_LAB_clicked();

    void on_pushButton_YUV_clicked();

    //void on_pushButton_SVM_clicked();

    void on_pushButton_pseudo_clicked();

    void on_pushButton_RGB_clicked();

private:
    Ui::hw5 *ui;
    void setShowImage(cv::Mat &img);
    QImage M2Q(const cv::Mat src);
    cv::Mat originImg;
    cv::Mat colortable;
    double min(double a,double b,double c);
};

#endif // HW5_H
