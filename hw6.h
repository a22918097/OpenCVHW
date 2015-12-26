#ifndef HW6_H
#define HW6_H

#include <QDialog>
#include "opencv2/opencv.hpp"
namespace Ui {
class hw6;
}

class hw6 : public QDialog
{
    Q_OBJECT

public:
    explicit hw6(QWidget *parent = 0);
    void recieveimage(cv::Mat &img);

    void readImage(cv::Mat &img);
    ~hw6();

private slots:
    void on_pushButton_trap_clicked();

    void on_pushButton_wavy_clicked();

    void on_pushButton_circular_clicked();

    void on_pushButton_Hough_clicked();

private:
    Ui::hw6 *ui;
    void setShowImage(cv::Mat &img);
    cv::Mat originImg;
    QImage M2Q(const cv::Mat src);
    cv::Mat receive;
};

#endif // HW6_H
