#include "hw6.h"
#include "ui_hw6.h"
#include "mainwindow.h"

hw6::hw6(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hw6)
{
    ui->setupUi(this);
}
void hw6::readImage(cv::Mat &img)
{
    originImg = img.clone();
    setShowImage(originImg);
}
void hw6::recieveimage(cv::Mat &img)
{
    receive=img.clone();
    //imshow("show",receive);

}
void hw6::setShowImage(cv::Mat &img)
{
    cv::Mat show;
    show=img.clone();
    if(img.type()==CV_8UC1)
        cv::cvtColor(img, show, cv::COLOR_GRAY2BGR);
    else
        show = img.clone();
    QImage qshow = QImage(show.data, show.cols, show.rows, show.step, QImage::Format_RGB888).rgbSwapped();
    qshow = qshow.scaled(ui->label_main->width(), ui->label_main->height(), Qt::KeepAspectRatio);
    ui->label_main->setPixmap(QPixmap::fromImage(qshow));
}
QImage hw6::M2Q(const cv::Mat src)
{

    if(src.type()==CV_8UC1)
    {
        QVector<QRgb> colorTable;
        for (int i=0; i<256; i++)
            colorTable.push_back(qRgb(i,i,i));
        const uchar *qImageBuffer = (const uchar*)src.data;
        QImage temp(qImageBuffer, src.cols, src.rows, src.step, QImage::Format_Indexed8);
        temp.setColorTable(colorTable);
        return temp;
    }

    if(src.type()==CV_8UC3)
    {
        const uchar *qImageBuffer = (const uchar*)src.data;
        QImage temp(qImageBuffer, src.cols, src.rows, src.step, QImage::Format_RGB888);
        return temp.rgbSwapped();
    }
    else
    {
        qDebug() << "Error! Can't convert image type.";
        return QImage();
    }
}

hw6::~hw6()
{
    delete ui;
}

void hw6::on_pushButton_trap_clicked()
{
    cv::Mat temp;
    cv::Mat final;
    cv::Mat mid;
    cv::resize(originImg,mid,cv::Size(ui->label_disp->width(),ui->label_disp->height()));
    cv::resize(originImg,temp,cv::Size(ui->label_disp->width(),ui->label_disp->height()));
    final=temp.zeros(cv::Size(temp.rows,temp.cols),CV_8UC3);
    mid=temp.zeros(cv::Size(temp.rows,temp.cols),CV_8UC3);
    for(int i=0;i<mid.rows;i++)
    {
        for(int j=0;j<mid.cols;j++)
        {
            if(4*i/3<800)
            {
                mid.at<cv::Vec3b>(i,j)[0]=temp.at<cv::Vec3b>(4*i/3,j)[0];
                mid.at<cv::Vec3b>(i,j)[1]=temp.at<cv::Vec3b>(4*i/3,j)[1];
                mid.at<cv::Vec3b>(i,j)[2]=temp.at<cv::Vec3b>(4*i/3,j)[2];
            }
        }
    }

    for(int i=0;i<final.rows*3/4;i++)
    {
        double ratio=i*0.5/final.rows*4/3;
        ratio=1-ratio;//最上面放大倍率一倍　最下面１／２倍
        //qDebug() << "ratio=" << ratio;
        for(int j=0;j<final.cols*ratio;j++)
        {
            final.at<cv::Vec3b>(i,j+final.rows*(1-ratio)/2)[0]=mid.at<cv::Vec3b>(i,j/ratio)[0];
            final.at<cv::Vec3b>(i,j+final.rows*(1-ratio)/2)[1]=mid.at<cv::Vec3b>(i,j/ratio)[1];
            final.at<cv::Vec3b>(i,j+final.rows*(1-ratio)/2)[2]=mid.at<cv::Vec3b>(i,j/ratio)[2];

        }
    }
    ui->label_disp->setPixmap(QPixmap::fromImage(M2Q(final)));
}
void hw6::on_pushButton_wavy_clicked()
{
    cv::Mat temp;
    cv::Mat final;
    cv::Mat mid;
    cv::resize(originImg,mid,cv::Size(ui->label_disp->width(),ui->label_disp->height()));
    cv::resize(originImg,temp,cv::Size(ui->label_disp->width(),ui->label_disp->height()));
    mid=temp.zeros(cv::Size(temp.rows,temp.cols),CV_8UC3);
    final.create(temp.rows,temp.cols,CV_8UC3);
    for(int i=0;i<mid.rows;i++)
    {
        for(int j=0;j<mid.cols;j++)
        {
            {
                mid.at<cv::Vec3b>(i,j)[0]=temp.at<cv::Vec3b>(i,j)[0];
                mid.at<cv::Vec3b>(i,j)[1]=temp.at<cv::Vec3b>(i,j)[1];
                mid.at<cv::Vec3b>(i,j)[2]=temp.at<cv::Vec3b>(i,j)[2];
            }
        }
    }
    //    imshow("mid",final);
    for(int i=0;i<mid.rows;i++)
    {
        for(int j=0;j<mid.cols;j++)
        {
            //int w = j;

            //            for(int w=0;w<360;w++)
            //            {
            if(i+30*sin(-2.5*j*3.14/180)>=0 && j+30*sin(-2.5*i*3.14/180)<mid.cols && i+30*sin(-2.5*j*3.14/180)<mid.rows && j+30*sin(-2.5*i*3.14/180)>=0){
                //                final.at<cv::Vec3b>(i+30*sin(j*3.14/180),j+30*sin(i*3.14/180))[0]=mid.at<cv::Vec3b>(i,j)[0];
                //                final.at<cv::Vec3b>(i+30*sin(j*3.14/180),j+30*sin(i*3.14/180))[1]=mid.at<cv::Vec3b>(i,j)[1];
                //                final.at<cv::Vec3b>(i+30*sin(j*3.14/180),j+30*sin(i*3.14/180))[2]=mid.at<cv::Vec3b>(i,j)[2];
                final.at<cv::Vec3b>(i,j)[0]=mid.at<cv::Vec3b>(i+30*sin(-2.5*j*3.14/180),j+30*sin(-2.5*i*3.14/180))[0];
                final.at<cv::Vec3b>(i,j)[1]=mid.at<cv::Vec3b>(i+30*sin(-2.5*j*3.14/180),j+30*sin(-2.5*i*3.14/180))[1];
                final.at<cv::Vec3b>(i,j)[2]=mid.at<cv::Vec3b>(i+30*sin(-2.5*j*3.14/180),j+30*sin(-2.5*i*3.14/180))[2];
                //                }
            }
        }
    }
    ui->label_disp->setPixmap(QPixmap::fromImage(M2Q(final)));
}

void hw6::on_pushButton_circular_clicked()
{
    cv::Mat temp;
    cv::Mat final;
    cv::Mat mid;
    cv::resize(originImg,mid,cv::Size(ui->label_disp->width(),ui->label_disp->height()));
    cv::resize(originImg,temp,cv::Size(ui->label_disp->width(),ui->label_disp->height()));
    mid=temp.zeros(cv::Size(temp.rows,temp.cols),CV_8UC3);
    final.create(temp.rows,temp.cols,CV_8UC3);
    for(int i=0;i<mid.rows;i++)
    {
        for(int j=0;j<mid.cols;j++)
        {
            {
                mid.at<cv::Vec3b>(i,j)[0]=temp.at<cv::Vec3b>(i,j)[0];
                mid.at<cv::Vec3b>(i,j)[1]=temp.at<cv::Vec3b>(i,j)[1];
                mid.at<cv::Vec3b>(i,j)[2]=temp.at<cv::Vec3b>(i,j)[2];
            }
        }
    }
    //        imshow("mid",mid);

    double d,w;
    double r=final.cols/2;
    for(int i=0;i<final.rows;i++)
    {
        d= sqrt(pow(r,2.0)-pow(r-i,2.0));
        w=r-d;
        for(int j=0;j<final.cols-2*w;j++)
        {
            double ratio=final.cols/(final.cols-2*w);
            final.at<cv::Vec3b>(i,j+w)[0]=mid.at<cv::Vec3b>(i,j*ratio)[0];
            final.at<cv::Vec3b>(i,j+w)[1]=mid.at<cv::Vec3b>(i,j*ratio)[1];
            final.at<cv::Vec3b>(i,j+w)[2]=mid.at<cv::Vec3b>(i,j*ratio)[2];
        }
    }
    ui->label_disp->setPixmap(QPixmap::fromImage(M2Q(final)));
}

void hw6::on_pushButton_Hough_clicked()
{
    cv::Mat final;
    cv::Mat ltplane;
    int l;
    cv::Mat img;
    img.create(receive.rows,receive.cols,CV_8UC3);
    img=originImg.clone();
    final=receive.clone();
    ltplane.create(1.414*final.rows*2,180,CV_8UC1);
    ltplane=ltplane.zeros(cv::Size(ltplane.cols,ltplane.rows),CV_8UC1);
    //    imshow("ltplane",ltplane);
    //    imshow("final",final);
    for(int i=0;i<final.rows;i++){
        for(int j=0;j<final.cols;j++)
        {
            if(final.at<uchar>(i,j)>70)
                if(final.at<uchar>(i,j)>125)
                    final.at<uchar>(i,j)=255;
                else
                    final.at<uchar>(i,j)=0;
        }
    }
    for(int i=0;i<final.rows;i++)
    {
        for(int j=0;j<final.cols;j++)
        {
            for(int t=-90;t<90;t++)
            {
                if(final.at<uchar>(i,j)==255)
                {
                    l=i*cos(t*3.14/180)+j*sin(t*3.14/180);
                    ltplane.at<uchar>(int(l+512*1.414),t+90)+=1 ;
                }
            }
        }
    }

    int max[20],maxi[20],maxj[20],k=0;
    for(int i=0;i<20;i++){
        max[i]=0;
        maxi[i]=0;
        maxj[i]=0;
    }


    for(int i=0;i<ltplane.rows;i++)
    {
        for(int j=0;j< ltplane.cols;j++)
        {

            if(ltplane.at<uchar>(i,j)>80){
                qDebug() << "me";
                max[k]=ltplane.at<uchar>(i,j);
                maxi[k]=i-ltplane.rows/2;
                maxj[k]=j-90;
                k++;

            }
        }
    }
    //for(int k=0;k<20;k++){
    //  qDebug()<<max[k]<<maxi[k]<<maxj[k];
    //}
    qDebug() << img.channels();
    int check;
    for(int i=0;i<final.rows;i++)
    {
        for(int j=0;j<final.cols;j++)
        {
            for(int k=0;k<20;k++)
            {

                if(max[k]!=0){
                    check=i*cos(maxj[k]*3.14/180)+j*sin(maxj[k]*3.14/180);
                    if(check==maxi[k]){
                        img.at<cv::Vec3b>(i,j)[2]=255;
                    }
                }
                if(i==511&&j==511&&k==19)
                    qDebug() << maxi[19] << check;
            }
        }
    }
    imshow("ltplane",ltplane);
    ui->label_disp->setPixmap(QPixmap::fromImage(M2Q(img)));
}
