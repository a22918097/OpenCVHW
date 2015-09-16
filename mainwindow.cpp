#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace cv;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_load_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"), "/G:", tr("Image Files (*.png *.jpg *.bmp)"));
    cv::Mat src = cv::imread(fileName.toStdString());

    int width = src.cols;
    int height = src.rows;
    cv::resize(src,src,cv::Size(width,height));
    this->img = src.clone();
    this->raw = src.clone();
    this->showImage(this->img);
    ui->horizontalSlider_BLUE->setEnabled(1);
    ui->horizontalSlider_bri->setEnabled(1);
    ui->horizontalSlider_GREEN->setEnabled(1);
    ui->horizontalSlider_RED->setEnabled(1);
    ui->pushButton_blur->setEnabled(1);
    ui->pushButton_gs->setEnabled(1);
    ui->pushButton_save->setEnabled(1);
    ui->pushButton_NI->setEnabled(1);
    ui->pushButton_save->setEnabled(1);
    ui->pushButton_clear->setEnabled(1);
}
void MainWindow::on_actionLoad_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"), "/G:", tr("Image Files (*.png *.jpg *.bmp)"));
    cv::Mat src = cv::imread(fileName.toStdString());

    int width = src.cols;
    int height = src.rows;
    cv::resize(src,src,cv::Size(width,height));
    this->img = src.clone();
    this->raw = src.clone();
    this->showImage(this->img);
    ui->horizontalSlider_BLUE->setEnabled(1);
    ui->horizontalSlider_bri->setEnabled(1);
    ui->horizontalSlider_GREEN->setEnabled(1);
    ui->horizontalSlider_RED->setEnabled(1);
    ui->pushButton_blur->setEnabled(1);
    ui->pushButton_gs->setEnabled(1);
    ui->pushButton_save->setEnabled(1);
    ui->pushButton_NI->setEnabled(1);
    ui->pushButton_save->setEnabled(1);
    ui->pushButton_clear->setEnabled(1);
}
void MainWindow::on_pushButton_clear_clicked()
{
    ui->horizontalSlider_BLUE->setValue(0);
    ui->horizontalSlider_bri->setValue(0);
    ui->horizontalSlider_GREEN->setValue(0);
    ui->horizontalSlider_RED->setValue(0);
    this->showImage(this->raw);
    this->img=raw.clone();

}
QImage MainWindow::Mat2QImage(const cv::Mat src)
{

    if(src.type()==CV_8UC1)
    {
        QVector<QRgb> colorTable;
        for (int i=0; i<256; i++)
            colorTable.push_back(qRgb(i,i,i));
        const uchar *qImageBuffer = (const uchar*)src.data;
        QImage img(qImageBuffer, src.cols, src.rows, src.step, QImage::Format_Indexed8);
        img.setColorTable(colorTable);
        return img;
    }

    if(src.type()==CV_8UC3)
    {
        const uchar *qImageBuffer = (const uchar*)src.data;
        QImage img(qImageBuffer, src.cols, src.rows, src.step, QImage::Format_RGB888);
        return img.rgbSwapped();
    }
    else
    {
        qDebug() << "Error! Can't convert image type.";
        return QImage();
    }
}
void MainWindow::showImage(const cv::Mat &src)
{

    cv::Mat dst;

    //why wrong???
//    int width = ui->image_label->width();
//    int height = ui->image_label->height();
//    double ratio = (double)width / (double)height;
//    double imgRatio = src.cols / src.rows;
//    if (ratio>imgRatio)
//    {
//        cv::resize(src,dst,cv::Size(width,src.rows/(src.cols/width)));
//    }
//    else
//    {
//        cv::resize(src,dst,cv::Size(src.cols/(src.rows/height),height));
//    }
    ui->image_label->setPixmap(QPixmap::fromImage(this->Mat2QImage(src)));
}



void MainWindow::on_horizontalSlider_bri_valueChanged(int value)
{
    //cv::Mat dst;
    //dst = this->img.clone();
    cv::Mat src = this->img;
        cv::Mat dst(src);
        for(int i = 0 ;i < this->img.rows ; i++)
        {
            for(int j = 0 ;j< this->img.cols ; j++)
            {
                for(int k = 0 ;k < this->img.channels() ; k++)
                {
                    if(this->img.at<cv::Vec3b>(i,j)[k]+value > 255)
                    {
                        dst.at<cv::Vec3b>(i,j)[k] = 255;
                    }
                    else if(this->img.at<cv::Vec3b>(i,j)[k]+value < 0)
                    {
                        dst.at<cv::Vec3b>(i,j)[k] = 0;
                    }
                    else
                    {
                        dst.at<cv::Vec3b>(i,j)[k] =
                                this->img.at<cv::Vec3b>(i,j)[k]+value;
                    }

                }
            }
        }

        this->showImage(dst);
}

void MainWindow::changeColor(const cv::Mat &src, cv::Mat &dst, QVector<int> value)
{
    for(int i = 0 ;i < src.rows ; i++)
    {
        for(int j = 0 ;j< src.cols ; j++)
        {
            for(int k = 0 ;k < src.channels() ; k++)
            {
                if(src.at<cv::Vec3b>(i,j)[k]+value[k] > 255)
                {
                    dst.at<cv::Vec3b>(i,j)[k] = 255;
                }
                else if(src.at<cv::Vec3b>(i,j)[k]+value[k] < 0)
                {
                    dst.at<cv::Vec3b>(i,j)[k] = 0;
                }
                else
                {
                    dst.at<cv::Vec3b>(i,j)[k] =
                            src.at<cv::Vec3b>(i,j)[k]+value[k];
                }
            }
        }
    }
}



void MainWindow::on_horizontalSlider_RED_valueChanged(int value)
{
 //   cv::Mat dst;
        cv::Mat src = this->img;
        cv::Mat dst(src);
        QVector<int> valueVec(3);
        valueVec[0] = ui->horizontalSlider_BLUE->value();
        valueVec[1] = ui->horizontalSlider_GREEN->value();
        valueVec[2] = ui->horizontalSlider_RED->value();
        //dst = this->img.clone();
        this->changeColor(this->img,dst,valueVec);
        this->showImage(dst);
}

void MainWindow::on_horizontalSlider_GREEN_valueChanged(int value)
{
        //cv::Mat dst;
        cv::Mat src = this->img;
        cv::Mat dst(src);
        QVector<int> valueVec(3);
        valueVec[0] = ui->horizontalSlider_BLUE->value();
        valueVec[1] = ui->horizontalSlider_GREEN->value();
        valueVec[2] = ui->horizontalSlider_RED->value();
      //  dst = this->img.clone();
        this->changeColor(this->img,dst,valueVec);
        this->showImage(dst);
}

void MainWindow::on_horizontalSlider_BLUE_valueChanged(int value)
{
//    cv::Mat dst;
        cv::Mat src = this->img;
        cv::Mat dst(src);
        QVector<int> valueVec(3);
        valueVec[0] = ui->horizontalSlider_BLUE->value();
        valueVec[1] = ui->horizontalSlider_GREEN->value();
        valueVec[2] = ui->horizontalSlider_RED->value();
    //    dst = this->img.clone();
        this->changeColor(this->img,dst,valueVec);
        this->showImage(dst);
}

void MainWindow::on_pushButton_blur_clicked()
{
    cv::Mat src = this->img;
        cv::Mat dst(src);

        for(int i = 1 ;i < src.rows-1 ; i++)
        {
            for(int j = 1 ;j< src.cols-1 ; j++)
            {

                for(int k = 0;k < src.channels();k++)
                {
                    dst.at<cv::Vec3b>(i,j)[k] =
                            (src.at<cv::Vec3b>(i-1,j-1)[k]
                            +src.at<cv::Vec3b>(i-1,j)[k]
                            +src.at<cv::Vec3b>(i-1,j+1)[k]
                            +src.at<cv::Vec3b>(i,j-1)[k]
                            +src.at<cv::Vec3b>(i,j)[k]
                            +src.at<cv::Vec3b>(i,j+1)[k]
                            +src.at<cv::Vec3b>(i+1,j-1)[k]
                            +src.at<cv::Vec3b>(i+1,j)[k]
                            +src.at<cv::Vec3b>(i+1,j+1)[k])/9;
                }
            }
        }
        this->showImage(dst);
}
void MainWindow::on_pushButton_gs_clicked()
{
    {
        cv::Mat src = this->img;
        cv::Mat dst;
        dst.create(cv::Size(src.cols,src.rows),CV_8UC1);
        for(int i = 0 ;i < src.rows ; i++)
        {
            for(int j = 0 ;j < src.cols ; j++)
            {

                    dst.at<uchar>(i,j)
                   = (src.at<cv::Vec3b>(i,j)[0]+src.at<cv::Vec3b>(i,j)[1]+src.at<cv::Vec3b>(i,j)[2])/3;

            }
        }
        this->showImage(dst);
    }
}
void MainWindow::on_pushButton_save_clicked()
{
    Mat image=this->img;

    imwrite( "save.jpg", image);
}

void MainWindow::on_pushButton_NI_clicked()
{
//    cv::Mat dst;
//        dst = this->img.clone();
        cv::Mat src = this->img;
        cv::Mat dst(src);
        for(int i = 0 ;i < this->img.rows ; i++)
        {
            for(int j = 0 ;j< this->img.cols ; j++)
            {
                for(int k = 0 ;k < this->img.channels() ; k++)
                {

                    dst.at<cv::Vec3b>(i,j)[k] = 255-dst.at<cv::Vec3b>(i,j)[k] ;


                }
            }
        }
        this->showImage(dst);
}




