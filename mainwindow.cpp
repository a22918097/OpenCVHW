#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidgetItem>
using namespace cv;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    gray.resize(256);
    for(int i = 0; i < gray.size(); i++)
    {
        gray[i] = 0;
    }

    ui->setupUi(this);
    ui->pushButton_ZC->setVisible(0);
    ui->customPlot->setVisible(0);
    setFixedSize(1905,1000);
    ui->tableWidget->setColumnCount(ui->spinBox->text().toInt());
    ui->tableWidget->setRowCount(ui->spinBox->text().toInt());
    ui->tableWidget->setFixedSize(30*ui->spinBox->text().toInt()+30,30*ui->spinBox->text().toInt()+40);
    for(int i=0;i<ui->spinBox->value();i++)
    {
        ui->tableWidget->setRowHeight(i,30);
        ui->tableWidget->setColumnWidth(i,30);

    }

    for(int i=0;i<ui->spinBox->text().toInt();i++)
    {
        for(int k=0;k<ui->spinBox->text().toInt();k++)
        {
            ui->tableWidget->setItem(i,k,new QTableWidgetItem("1"));
        }
    }
    //ui->tableWidget->setVisible(0);


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_load_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open Image", "/user", "Image Files (*.png *.jpg *.bmp)");
    if(fileName=="")
        return;
    src = cv::imread(fileName.toStdString());

    if(src.cols>ui->image_label->width())
    {
        if(src.cols>src.rows)
        {       double  ratio=double(ui->image_label->width())/src.cols;

            cv::resize(src,src,cv::Size(ui->image_label->width(),ratio*src.rows));
        }
        else
        {
            double  ratio=double(ui->image_label->height())/src.rows;

            cv::resize(src,src,cv::Size(ratio*src.cols,ui->image_label->height()));
        }
    }
    this->dst=src.clone();
    this->save=src.clone();
    this->temp = src.clone();
    this->raw = src.clone();
    this->showImage(this->temp);
    ui->horizontalSlider_BLUE->setEnabled(1);
    ui->horizontalSlider_bri->setEnabled(1);
    ui->horizontalSlider_GREEN->setEnabled(1);
    ui->horizontalSlider_RED->setEnabled(1);
    ui->horizontalSlider_Contrast->setEnabled(1);
    ui->pushButton_blur->setEnabled(1);
    ui->pushButton_gs->setEnabled(1);
    ui->pushButton_gs_2->setEnabled(1);
    ui->pushButton_save->setEnabled(1);
    ui->pushButton_NI->setEnabled(1);
    ui->pushButton_save->setEnabled(1);
    ui->pushButton_clear->setEnabled(1);
    ui->pushButton_du->setEnabled(1);
    ui->pushButton_ChangeRes->setEnabled(1);
    ui->pushButton_HW5->setEnabled(1);
}
void MainWindow::on_actionLoad_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open Image", "/user", "Image Files (*.png *.jpg *.bmp)");
    if(fileName=="")
        return;
    src = cv::imread(fileName.toStdString());

    if(src.cols>ui->image_label->width())
    {
        if(src.cols>src.rows)
        {       double  ratio=double(ui->image_label->width())/src.cols;

            cv::resize(src,src,cv::Size(ui->image_label->width(),ratio*src.rows));
        }
        else
        {
            double  ratio=double(ui->image_label->height())/src.rows;

            cv::resize(src,src,cv::Size(ratio*src.cols,ui->image_label->height()));
        }
    }
    this->dst=src.clone();
    this->save=src.clone();
    this->temp = src.clone();
    this->raw = src.clone();
    this->showImage(this->temp);
    ui->horizontalSlider_BLUE->setEnabled(1);
    ui->horizontalSlider_bri->setEnabled(1);
    ui->horizontalSlider_GREEN->setEnabled(1);
    ui->horizontalSlider_RED->setEnabled(1);
    ui->horizontalSlider_Contrast->setEnabled(1);
    ui->pushButton_blur->setEnabled(1);
    ui->pushButton_gs->setEnabled(1);
    ui->pushButton_gs_2->setEnabled(1);
    ui->pushButton_save->setEnabled(1);
    ui->pushButton_NI->setEnabled(1);
    ui->pushButton_save->setEnabled(1);
    ui->pushButton_clear->setEnabled(1);
    ui->pushButton_du->setEnabled(1);
    ui->pushButton_ChangeRes->setEnabled(1);
}
void MainWindow::on_pushButton_clear_clicked()
{
    ui->horizontalSlider_BLUE->setValue(0);
    ui->horizontalSlider_bri->setValue(0);
    ui->horizontalSlider_GREEN->setValue(0);
    ui->horizontalSlider_RED->setValue(0);
    ui->horizontalSlider_Contrast->setValue(0);
    ui->horizontalSlider_BLUE->setEnabled(1);
    ui->horizontalSlider_bri->setEnabled(1);
    ui->horizontalSlider_GREEN->setEnabled(1);
    ui->horizontalSlider_RED->setEnabled(1);
    ui->horizontalSlider_Contrast->setEnabled(1);
    ui->pushButton_blur->setEnabled(1);
    ui->pushButton_NI->setEnabled(1);
    ui->pushButton_gs->setEnabled(1);
    ui->pushButton_gs_2->setEnabled(1);
    ui->pushButton_du->setEnabled(1);
    ui->pushButton_ZO->setEnabled(0);
    ui->pushButton_ZI->setEnabled(0);
    ui->pushButton_eq_->setEnabled(0);
    ui->pushButton_ChangeRes->setEnabled(1);
    this->showImage(this->raw);
    this->temp=raw.clone();
    this->dst=raw.clone();
    this->src=raw.clone();
    this->save=raw.clone();
    for(int i=0;i<gray.size();i++)
        gray[i]=0;
    ui->customPlot->setVisible(0);
}


//??
QImage MainWindow::Mat2QImage(const cv::Mat src)
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

void MainWindow::showImage(const cv::Mat &src)
{

    ui->image_label->setPixmap(QPixmap::fromImage(this->Mat2QImage(src)));
}



void MainWindow::on_horizontalSlider_bri_valueChanged(int value)
{
    //*
    dst=temp.clone();
    src=dst.clone();//dst0
    temp=dst.clone();
    //*/
    for(int i = 0 ;i < this->raw.rows ; i++)
    {
        for(int j = 0 ;j< this->raw.cols ; j++)
        {
            for(int k = 0 ;k < this->raw.channels() ; k++)
            {
                if(this->temp.at<cv::Vec3b>(i,j)[k]+value > 255)
                {
                    dst.at<cv::Vec3b>(i,j)[k] = 255;
                }
                else if(this->temp.at<cv::Vec3b>(i,j)[k]+value < 0)
                {
                    dst.at<cv::Vec3b>(i,j)[k] = 0;
                }
                else
                {
                    dst.at<cv::Vec3b>(i,j)[k] =
                            this->temp.at<cv::Vec3b>(i,j)[k]+value;
                }

            }
        }
    }
    save=dst.clone();
    this->showImage(dst);//dst1
    save=dst.clone();
    temp=src.clone();//dst0



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
    src=dst.clone();//dst0
    temp=dst.clone();//dst0
    QVector<int> valueVec(3);
    valueVec[0] = ui->horizontalSlider_BLUE->value();
    valueVec[1] = ui->horizontalSlider_GREEN->value();
    valueVec[2] = ui->horizontalSlider_RED->value();
    this->changeColor(this->temp,dst,valueVec);
    this->showImage(dst);//dst1
    save=dst.clone();
    this->temp=dst.clone();//dst1
    this->dst=src.clone();//dst0
    this->src=dst.clone();
}

void MainWindow::on_horizontalSlider_GREEN_valueChanged(int value)
{
    src=dst.clone();//dst0
    temp=dst.clone();//dst0
    QVector<int> valueVec(3);
    valueVec[0] = ui->horizontalSlider_BLUE->value();
    valueVec[1] = ui->horizontalSlider_GREEN->value();
    valueVec[2] = ui->horizontalSlider_RED->value();

    this->changeColor(this->temp,dst,valueVec);
    this->showImage(dst);//dst1
    save=dst.clone();
    this->temp=dst.clone();//dst1
    this->dst=src.clone();//dst0
}

void MainWindow::on_horizontalSlider_BLUE_valueChanged(int value)
{
    src=dst.clone();//dst0
    temp=dst.clone();//dst0
    QVector<int> valueVec(3);
    valueVec[0] = ui->horizontalSlider_BLUE->value();
    valueVec[1] = ui->horizontalSlider_GREEN->value();
    valueVec[2] = ui->horizontalSlider_RED->value();
    //    dst = this->temp.clone();
    this->changeColor(this->temp,dst,valueVec);
    this->showImage(dst);//dst1
    save=dst.clone();
    this->temp=dst.clone();//dst1
    this->dst=src.clone();//dst0
}

void MainWindow::on_pushButton_blur_clicked()
{

    temp=dst.clone();
    for(int i = 1 ;i < temp.rows-1 ; i++)
    {
        for(int j = 1 ;j< temp.cols-1 ; j++)
        {

            for(int k = 0;k < temp.channels();k++)
            {
                dst.at<cv::Vec3b>(i,j)[k] =
                        (temp.at<cv::Vec3b>(i-1,j-1)[k]
                         +temp.at<cv::Vec3b>(i-1,j)[k]
                         +temp.at<cv::Vec3b>(i-1,j+1)[k]
                         +temp.at<cv::Vec3b>(i,j-1)[k]
                         +temp.at<cv::Vec3b>(i,j)[k]
                         +temp.at<cv::Vec3b>(i,j+1)[k]
                         +temp.at<cv::Vec3b>(i+1,j-1)[k]
                         +temp.at<cv::Vec3b>(i+1,j)[k]
                         +temp.at<cv::Vec3b>(i+1,j+1)[k])/9;
            }
        }
    }
    this->showImage(dst);
    save=dst.clone();
    temp=dst.clone();
}
void MainWindow::on_pushButton_gs_clicked()
{


    dst.create(cv::Size(src.cols,src.rows),CV_8UC3);
    for(int i = 0 ;i < src.rows ; i++)
    {
        for(int j = 0 ;j < src.cols ; j++)
        {
            for(int k = 0 ;k < 3 ; k++)
                dst.at<cv::Vec3b>(i,j)[k] = (src.at<cv::Vec3b>(i,j)[0]+src.at<cv::Vec3b>(i,j)[1]+src.at<cv::Vec3b>(i,j)[2])/3;

        }
    }

    this->showImage(dst);
    for(int i=0;i<dst.rows;i++)
    {
        for(int j=0;j<dst.cols;j++)
        {
            gray[dst.at<cv::Vec3b>(i,j)[1]]++;
        }
    }
    save=dst.clone();
    this->temp = dst.clone();


    int max = 0;
    for(int i = 0; i < gray.size(); i++)
    {
        if(max < gray[i]){max = gray[i];}
    }





    //plot
    QCustomPlot customPlot;
    // create empty bar chart objects:
    QCPBars *regen = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    ui->customPlot->addPlottable(regen);
    // set names and colors:
    QPen pen;
    pen.setWidthF(1.2);
    // fossil->setName("Fossil fuels");
    //pen.setColor(QColor(255, 131, 0));
    //fossil->setPen(pen);
    //fossil->setBrush(QColor(255, 131, 0, 50));
    //nuclear->setName("Nuclear");
    //pen.setColor(QColor(1, 92, 191));
    //nuclear.setPen(pen);
    //nuclear.setBrush(QColor(1, 92, 191, 50));
    regen->setName("Histogram");
    pen.setColor(QColor(150, 222, 0));
    regen->setPen(pen);
    regen->setBrush(QColor(150, 222, 0, 70));

    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    for(int i=0;i<256;i++)
    {
        ticks << i;
        labels << QString::number(i);
    }
    ui->customPlot->xAxis->setTickVectorLabels(labels);
    ui->customPlot->xAxis->setTickLabelRotation(60);
    ui->customPlot->xAxis->setSubTickCount(0);
    ui->customPlot->xAxis->setTickLength(0, 4);
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->setRange(0, 256);
    // prepare y axis:
    ui->customPlot->yAxis->setRange(0, max+5);
    ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    ui->customPlot->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    ui->customPlot->yAxis->grid()->setSubGridPen(gridPen);

    // Add data:
    QVector<double> regenData;
    for(int i=0;i<256;i++)
        regenData   << gray[i];

    regen->setData(ticks, regenData);

    // setup legend:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 200));
    QPen legendPen;
    legendPen.setColor(QColor(130, 130, 130, 200));
    ui->customPlot->legend->setBorderPen(legendPen);
    QFont legendFont = font();
    legendFont.setPointSize(18);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    ui->customPlot->replot();
    ui->customPlot->setVisible(1);
    ui->pushButton_ZO->setEnabled(1);
    ui->pushButton_ZI->setEnabled(1);
    ui->pushButton_gs->setEnabled(0);
    ui->pushButton_gs_2->setEnabled(0);
    ui->pushButton_ChangeRes->setEnabled(1);
    ui->pushButton_eq_->setEnabled(1);
}
void MainWindow::on_pushButton_ZO_clicked()
{
    //    cv::cvtColor(dst.clone(),temp,cv::COLOR_BGR2GRAY);

    temp.create(cv::Size(dst.cols,dst.rows),CV_8UC1);
    if(dst.channels()==3){
        for(int i = 0 ;i < dst.rows ; i++)
        {
            for(int j = 0 ;j < dst.cols ; j++)
            {

                temp.at<uchar>(i,j) = (dst.at<cv::Vec3b>(i,j)[0] + dst.at<cv::Vec3b>(i,j)[1] + dst.at<cv::Vec3b>(i,j)[2])/3;


            }
        }
    }


    dst.create(cv::Size(temp.cols/1.5,temp.rows/1.5),CV_8UC1);

    for(int i = 0 ;i < dst.rows ; i++)
    {
        for(int j = 0 ;j < dst.cols ; j++)
        {

            dst.at<uchar>(i,j)=temp.at<uchar>(i*1.5,j*1.5);

        }
    }

    this->showImage(dst);
    save=dst.clone();
    temp=dst.clone();

}
void MainWindow::on_pushButton_ZI_clicked()
{
    temp.create(cv::Size(dst.cols,dst.rows),CV_8UC1);
    if(dst.channels()==3){
        for(int i = 0 ;i < dst.rows ; i++)
        {
            for(int j = 0 ;j < dst.cols ; j++)
            {

                temp.at<uchar>(i,j) =
                        (dst.at<cv::Vec3b>(i,j)[0] + dst.at<cv::Vec3b>(i,j)[1] + dst.at<cv::Vec3b>(i,j)[2])/3;


            }
        }
    }


    dst.create(cv::Size(temp.cols*1.5,temp.rows*1.5),CV_8UC1);

    for(int i = 0 ;i < dst.rows ; i++)
    {
        for(int j = 0 ;j < dst.cols ; j++)
        {

            dst.at<uchar>(i,j)=temp.at<uchar>(i/1.5,j/1.5);

        }
    }

    this->showImage(dst);
    save=dst.clone();
    temp=dst.clone();
}

void MainWindow::on_pushButton_du_clicked()
{
    temp=dst.clone();
    for(int i = 0 ;i < temp.rows ; i++)
    {
        for(int j = 0 ;j< temp.cols ; j++)
        {
            for(int k=0;k<temp.channels();k++)
            {
                if((dst.at<cv::Vec3b>(i,j)[k] = (src.at<cv::Vec3b>(i,j)[0]+src.at<cv::Vec3b>(i,j)[1]+src.at<cv::Vec3b>(i,j)[2])/3)>125)
                    dst.at<cv::Vec3b>(i,j)[k]=255;
                else
                    dst.at<cv::Vec3b>(i,j)[k]=0;
            }
        }
    }

    this->showImage(dst);
    save=dst.clone();
    temp=dst.clone();
}
void MainWindow::on_pushButton_ChangeRes_clicked()
{
    temp=dst.clone();
    qDebug() << dst.cols;
    for(int i = 0 ;i < temp.rows ; i++)
    {
        for(int j = 0 ;j< temp.cols ; j++)
        {
            for(int k=0;k<temp.channels();k++)
            {

                dst.at<cv::Vec3b>(i,j)[k]=int(dst.at<cv::Vec3b>(i,j)[k]/10);
                dst.at<cv::Vec3b>(i,j)[k]=dst.at<cv::Vec3b>(i,j)[k]*10;
            }
        }
    }
    ui->pushButton_ChangeRes->setEnabled(0);
    this->showImage(dst);
    save=dst.clone();
    temp=dst.clone();
}

void MainWindow::on_pushButton_gs_2_clicked()
{

    dst.create(cv::Size(src.cols,src.rows),CV_8UC3);
    for(int i = 0 ;i < src.rows ; i++)
    {
        for(int j = 0 ;j < src.cols ; j++)
        {
            for(int k = 0 ;k < 3 ; k++)
                dst.at<cv::Vec3b>(i,j)[k] = src.at<cv::Vec3b>(i,j)[0]*0.114+src.at<cv::Vec3b>(i,j)[1]*0.587+src.at<cv::Vec3b>(i,j)[2]*0.299;

        }
    }

    this->showImage(dst);
    for(int i=0;i<dst.rows;i++)
    {
        for(int j=0;j<dst.cols;j++)
        {
            gray[dst.at<cv::Vec3b>(i,j)[1]]++;
        }
    }
    save=dst.clone();
    this->temp = dst.clone();


    int max = 0;
    for(int i = 0; i < gray.size(); i++)
    {
        if(max < gray[i]){max = gray[i];}
    }





    //plot
    QCustomPlot customPlot;
    // create empty bar chart objects:
    QCPBars *regen = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    ui->customPlot->addPlottable(regen);
    // set names and colors:
    QPen pen;
    pen.setWidthF(1.2);
    // fossil->setName("Fossil fuels");
    //pen.setColor(QColor(255, 131, 0));
    //fossil->setPen(pen);
    //fossil->setBrush(QColor(255, 131, 0, 50));
    //nuclear->setName("Nuclear");
    //pen.setColor(QColor(1, 92, 191));
    //nuclear.setPen(pen);
    //nuclear.setBrush(QColor(1, 92, 191, 50));
    regen->setName("Histogram");
    pen.setColor(QColor(150, 222, 0));
    regen->setPen(pen);
    regen->setBrush(QColor(150, 222, 0, 70));

    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    for(int i=0;i<256;i++)
    {
        ticks << i;
        labels << QString::number(i);
    }
    ui->customPlot->xAxis->setTickVectorLabels(labels);
    ui->customPlot->xAxis->setTickLabelRotation(60);
    ui->customPlot->xAxis->setSubTickCount(0);
    ui->customPlot->xAxis->setTickLength(0, 4);
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->setRange(0, 256);
    // prepare y axis:
    ui->customPlot->yAxis->setRange(0, max+5);
    ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    ui->customPlot->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    ui->customPlot->yAxis->grid()->setSubGridPen(gridPen);

    // Add data:
    QVector<double> regenData;
    for(int i=0;i<256;i++)
        regenData   << gray[i];

    regen->setData(ticks, regenData);

    // setup legend:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 200));
    QPen legendPen;
    legendPen.setColor(QColor(130, 130, 130, 200));
    ui->customPlot->legend->setBorderPen(legendPen);
    QFont legendFont = font();
    legendFont.setPointSize(18);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    ui->customPlot->replot();
    ui->customPlot->setVisible(1);
    ui->pushButton_ZO->setEnabled(1);
    ui->pushButton_ZI->setEnabled(1);
    ui->pushButton_gs->setEnabled(0);
    ui->pushButton_gs_2->setEnabled(0);
    ui->pushButton_ChangeRes->setEnabled(1);
    ui->pushButton_eq_->setEnabled(1);
}
void MainWindow::on_pushButton_save_clicked()
{
    Mat image=this->save;
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save Image"), "G:", tr("Image Files (*.jpg )"));
    if(fileName=="")
        return;
    else
        imwrite( fileName.toStdString(), image);
}

void MainWindow::on_pushButton_NI_clicked()
{
    //    cv::Mat dst;
    //        dst = this->temp.clone();
    //        cv::Mat src = this->temp;
    //       cv::Mat dst(src);
    for(int i = 0 ;i < this->temp.rows ; i++)
    {
        for(int j = 0 ;j< this->temp.cols ; j++)
        {
            for(int k = 0 ;k < this->temp.channels() ; k++)
            {

                dst.at<cv::Vec3b>(i,j)[k] = 255-dst.at<cv::Vec3b>(i,j)[k] ;


            }
        }
    }
    this->showImage(dst);
    save=dst.clone();
    temp=dst.clone();
}





void MainWindow::on_horizontalSlider_Contrast_valueChanged(int value)
{


    dst=temp.clone();
    src=dst.clone();//dst0
    temp=dst.clone();


    /*
        temp=src.clone();
        src=dst.clone();//dst0
        temp=dst.clone();//dst0
*/

    for(int i = 0 ;i < this->temp.rows ; i++)
    {
        for(int j = 0 ;j < this->temp.cols ; j++)
        {
            for(int k = 0 ;k < this->temp.channels() ; k++)
            {
                if(this->temp.at<cv::Vec3b>(i,j)[k]*value/100 > 255)
                {
                    dst.at<cv::Vec3b>(i,j)[k] = 255;
                }
                else if(this->temp.at<cv::Vec3b>(i,j)[k]*value/100 < 0)
                {
                    dst.at<cv::Vec3b>(i,j)[k] = 0;
                }
                else
                {
                    dst.at<cv::Vec3b>(i,j)[k] =
                            this->temp.at<cv::Vec3b>(i,j)[k]*value/100;
                }

            }
        }
    }
    save=dst.clone();
    this->showImage(dst);//dst1
    /*
        temp=src.clone();//dst0
        */
    temp=src.clone();//dst1
    //dst=src.clone();//dst0
}

void MainWindow::on_actionExit_triggered()
{
    close();
}





void MainWindow::on_pushButton_eq__clicked()
{
    temp=dst.clone();
    double p[256];
    for(int i=0;i < gray.size();i++)
    {
        sum=sum+gray[i];
        p[i]=round((255*sum)/(dst.cols*dst.rows));

    }

    for(int i = 0 ;i < dst.rows ; i++)
    {
        for(int j = 0 ;j < dst.cols ; j++)
        {
            for(int k=0;k<3;k++)
            {
                dst.at<cv::Vec3b>(i,j)[k]=p[temp.at<cv::Vec3b>(i,j)[k]];
            }
        }
    }
    this->showImage(dst);
    save=dst.clone();
    temp=dst.clone();
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    //ui->tableWidget->setVisible(1);
    ui->tableWidget->setFixedSize(30*ui->spinBox->value()+40,30*ui->spinBox->value()+50);
    ui->textBrowser->setText(QString::number( ui->spinBox->value()) + "X" + QString::number( ui->spinBox->value()));
    ui->tableWidget->setColumnCount(ui->spinBox->value());
    ui->tableWidget->setRowCount(ui->spinBox->value());
    for(int i=0;i<ui->spinBox->value();i++)
    {
        ui->tableWidget->setRowHeight(i,30);
        ui->tableWidget->setColumnWidth(i,30);
    }
    for(int i=0;i<ui->spinBox->text().toInt();i++)
    {
        for(int k=0;k<ui->spinBox->text().toInt();k++)
        {
            ui->tableWidget->setItem(i,k,new QTableWidgetItem("1"));
        }
    }
}

void MainWindow::on_pushButton_laplacian_clicked()
{
    cv::Mat test;

    test.create(cv::Size(dst.cols,dst.rows),CV_8UC1);
    for(int i=0;i<dst.rows;i++)
    {
        for (int j=0;j<dst.cols;j++)
        {
            test.at<uchar>(i,j)=dst.at<Vec3b>(i,j)[0];
        }
    }
    int sum=0;
    int count=0;
    int val;
    int size=ui->spinBox->text().toInt()*ui->spinBox->text().toInt();
    int *mask=new int[size];



    ui->tableWidget->setItem(0,0,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem("1"));
    ui->tableWidget->setItem(0,2,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(1,0,new QTableWidgetItem("1"));
    ui->tableWidget->setItem(1,1,new QTableWidgetItem("-4"));
    ui->tableWidget->setItem(1,2,new QTableWidgetItem("1"));
    ui->tableWidget->setItem(2,0,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(2,1,new QTableWidgetItem("1"));
    ui->tableWidget->setItem(2,2,new QTableWidgetItem("0"));
    Sleep(500);


    for(int i=0;i<ui->spinBox->text().toInt();i++)
    {
        for(int j=0;j<ui->spinBox->text().toInt();j++)
        {
            mask[count]=ui->tableWidget->item(i,j)->text().toInt();
            sum=sum+ui->tableWidget->item(i,j)->text().toInt();
            count++;
        }
    }

    for(int i =  2; i < dst.rows-2 ; i++)
    {
        for(int j = 2 ;j < dst.cols-2 ; j++)
        {
            val=0;
            int k=0;

            for(int m=((ui->spinBox->text().toInt()-1)/-2);m<=((ui->spinBox->text().toInt()-1)/2);m++)
            {
                for(int n=((ui->spinBox->text().toInt()-1)/-2);n<=((ui->spinBox->text().toInt()-1)/2);n++)
                {
                    val=val+mask[k]*dst.at<Vec3b>(i+m,j+n)[1];
                    k++;
                }
            }

            test.at<uchar>(i,j)= saturate_cast<uchar>(val);

        }
    }
    for(int i=0;i<test.rows;i++)
    {
        for(int j=0;j<test.cols;j++)
        {
            test.at<uchar>(i,j)=test.at<uchar>(i,j);
        }

    }
    delete [] mask;
    dst=test.clone();
    //this->showImage(dst);
    imshow("dst",test);
    save=dst.clone();
    temp=dst.clone();

}



void MainWindow::on_pushButton_smoothing_clicked()
{
    cv::Mat test;
    int size=ui->spinBox->text().toInt()*ui->spinBox->text().toInt();
    int *mask=new int[size];
    test.create(cv::Size(dst.cols,dst.rows),CV_8UC1);
    for(int i=0;i<dst.rows;i++)
    {
        for (int j=0;j<dst.cols;j++)
        {
            test.at<uchar>(i,j)=dst.at<Vec3b>(i,j)[0];
        }
    }
    int sum=0;
    int count=0;
    int val;
    for(int i=0;i<ui->spinBox->text().toInt();i++)
    {
        for(int j=0;j<ui->spinBox->text().toInt();j++)
        {
            mask[count]=ui->tableWidget->item(i,j)->text().toInt();
            sum=sum+ui->tableWidget->item(i,j)->text().toInt();
            count++;
        }
    }

    for(int i = ((ui->spinBox->text().toInt()-1)/2) ; i < dst.rows-((ui->spinBox->text().toInt()-1)/2) ; i++)
    {
        for(int j = ((ui->spinBox->text().toInt()-1)/2) ;j < dst.cols-((ui->spinBox->text().toInt()-1)/2) ; j++)
        {
            val=0;
            int k=0;

            for(int m=((ui->spinBox->text().toInt()-1)/-2);m<=((ui->spinBox->text().toInt()-1)/2);m++)
            {
                for(int n=((ui->spinBox->text().toInt()-1)/-2);n<=((ui->spinBox->text().toInt()-1)/2);n++)
                {
                    val=val+mask[k]*dst.at<Vec3b>(i+m,j+n)[1];
                    k++;
                }
            }

            test.at<uchar>(i,j)= saturate_cast<uchar>(val/sum);

        }
    }

    delete [] mask;
    dst=test.clone();
    //this->showImage(dst);
    imshow("dst",test);
    save=dst.clone();
    temp=dst.clone();

}

void MainWindow::on_pushButton_sobel_clicked()
{
    cv::Mat test;

    test.create(cv::Size(dst.cols,dst.rows),CV_8UC1);
    for(int i=0;i<dst.rows;i++)
    {
        for (int j=0;j<dst.cols;j++)
        {
            test.at<uchar>(i,j)=dst.at<Vec3b>(i,j)[0];
        }
    }
    int sum=0;
    int count=0;
    int val;
    int size=ui->spinBox->text().toInt()*ui->spinBox->text().toInt();
    int *mask=new int[size];
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("-1"));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem("-2"));
    ui->tableWidget->setItem(0,2,new QTableWidgetItem("-1"));
    ui->tableWidget->setItem(1,0,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(1,1,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(1,2,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(2,0,new QTableWidgetItem("1"));
    ui->tableWidget->setItem(2,1,new QTableWidgetItem("2"));
    ui->tableWidget->setItem(2,2,new QTableWidgetItem("1"));
    Sleep(1000);


    for(int i=0;i<ui->spinBox->text().toInt();i++)
    {
        for(int j=0;j<ui->spinBox->text().toInt();j++)
        {
            mask[count]=ui->tableWidget->item(i,j)->text().toInt();
            sum=sum+ui->tableWidget->item(i,j)->text().toInt();
            count++;
        }
    }
    for(int i=0;i<size;i++)
        qDebug() <<  mask[i];
    qDebug() <<  sum;

    for(int i =  2; i < dst.rows-2 ; i++)
    {
        for(int j = 2 ;j < dst.cols-2 ; j++)
        {
            val=0;
            int k=0;

            for(int m=((ui->spinBox->text().toInt()-1)/-2);m<=((ui->spinBox->text().toInt()-1)/2);m++)
            {
                for(int n=((ui->spinBox->text().toInt()-1)/-2);n<=((ui->spinBox->text().toInt()-1)/2);n++)
                {
                    val=val+mask[k]*dst.at<Vec3b>(i+m,j+n)[1];
                    k++;
                }
            }

            test.at<uchar>(i,j)= saturate_cast<uchar>(val);

        }
    }
    delete [] mask;
    dst=test.clone();
    //this->showImage(dst);
    imshow("dst",test);
    save=dst.clone();
    temp=dst.clone();
}

void MainWindow::on_pushButton_sobel_2_clicked()
{
    cv::Mat test;

    test.create(cv::Size(dst.cols,dst.rows),CV_8UC1);
    for(int i=0;i<dst.rows;i++)
    {
        for (int j=0;j<dst.cols;j++)
        {
            test.at<uchar>(i,j)=dst.at<Vec3b>(i,j)[0];
        }
    }
    int sum=0;
    int count=0;
    int val;
    int size=ui->spinBox->text().toInt()*ui->spinBox->text().toInt();
    int *mask=new int[size];
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("-1"));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(0,2,new QTableWidgetItem("1"));
    ui->tableWidget->setItem(1,0,new QTableWidgetItem("-2"));
    ui->tableWidget->setItem(1,1,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(1,2,new QTableWidgetItem("2"));
    ui->tableWidget->setItem(2,0,new QTableWidgetItem("-1"));
    ui->tableWidget->setItem(2,1,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(2,2,new QTableWidgetItem("1"));
    Sleep(1000);


    for(int i=0;i<ui->spinBox->text().toInt();i++)
    {
        for(int j=0;j<ui->spinBox->text().toInt();j++)
        {
            mask[count]=ui->tableWidget->item(i,j)->text().toInt();
            sum=sum+ui->tableWidget->item(i,j)->text().toInt();
            count++;
        }
    }
    for(int i=0;i<size;i++)
        qDebug() <<  mask[i];
    qDebug() <<  sum;

    for(int i =  2; i < dst.rows-2 ; i++)
    {
        for(int j = 2 ;j < dst.cols-2 ; j++)
        {
            val=0;
            int k=0;

            for(int m=((ui->spinBox->text().toInt()-1)/-2);m<=((ui->spinBox->text().toInt()-1)/2);m++)
            {
                for(int n=((ui->spinBox->text().toInt()-1)/-2);n<=((ui->spinBox->text().toInt()-1)/2);n++)
                {
                    val=val+mask[k]*dst.at<Vec3b>(i+m,j+n)[1];
                    k++;
                }
            }

            test.at<uchar>(i,j)= saturate_cast<uchar>(val);

        }
    }
    delete [] mask;
    dst=test.clone();
    //this->showImage(dst);
    imshow("dst",test);
    save=dst.clone();
    temp=dst.clone();
}



void MainWindow::on_actionFuzzy_triggered()
{
    DialogFuzzyLogic func;
    func.readImage(dst);
    func.exec();
}
void MainWindow::on_pushButton_MH_clicked()
{
    ui->spinBox->setValue(5);
    cv::Mat test;

    test.create(cv::Size(dst.cols,dst.rows),CV_8UC1);
    for(int i=0;i<dst.rows;i++)
    {
        for (int j=0;j<dst.cols;j++)
        {
            test.at<uchar>(i,j)=dst.at<Vec3b>(i,j)[0];
        }
    }
    int sum=0;
    int count=0;
    int val;
    int size=ui->spinBox->text().toInt()*ui->spinBox->text().toInt();
    int *mask=new int[size];
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setFixedSize(30*5+30,30*5+40);
    for(int i=0;i<5;i++)
    {
        ui->tableWidget->setRowHeight(i,30);
        ui->tableWidget->setColumnWidth(i,30);

    }
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(0,2,new QTableWidgetItem("-1"));
    ui->tableWidget->setItem(0,3,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(0,4,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(1,0,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(1,1,new QTableWidgetItem("-1"));
    ui->tableWidget->setItem(1,2,new QTableWidgetItem("-2"));
    ui->tableWidget->setItem(1,3,new QTableWidgetItem("-1"));
    ui->tableWidget->setItem(1,4,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(2,0,new QTableWidgetItem("-1"));
    ui->tableWidget->setItem(2,1,new QTableWidgetItem("-2"));
    ui->tableWidget->setItem(2,2,new QTableWidgetItem("16"));
    ui->tableWidget->setItem(2,3,new QTableWidgetItem("-2"));
    ui->tableWidget->setItem(2,4,new QTableWidgetItem("-1"));
    ui->tableWidget->setItem(3,0,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(3,1,new QTableWidgetItem("-1"));
    ui->tableWidget->setItem(3,2,new QTableWidgetItem("-2"));
    ui->tableWidget->setItem(3,3,new QTableWidgetItem("-1"));
    ui->tableWidget->setItem(3,4,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(4,0,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(4,1,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(4,2,new QTableWidgetItem("-1"));
    ui->tableWidget->setItem(4,3,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(4,4,new QTableWidgetItem("0"));

    Sleep(1000);


    for(int i=0;i<ui->spinBox->text().toInt();i++)
    {
        for(int j=0;j<ui->spinBox->text().toInt();j++)
        {
            mask[count]=ui->tableWidget->item(i,j)->text().toInt();
            sum=sum+ui->tableWidget->item(i,j)->text().toInt();
            count++;
        }
    }

    for(int i =  2; i < dst.rows-2 ; i++)
    {
        for(int j = 2 ;j < dst.cols-2 ; j++)
        {
            val=0;
            int k=0;

            for(int m=((ui->spinBox->text().toInt()-1)/-2);m<=((ui->spinBox->text().toInt()-1)/2);m++)
            {
                for(int n=((ui->spinBox->text().toInt()-1)/-2);n<=((ui->spinBox->text().toInt()-1)/2);n++)
                {
                    val=val+mask[k]*dst.at<Vec3b>(i+m,j+n)[1];
                    k++;
                }
            }

            test.at<uchar>(i,j)= saturate_cast<uchar>(val);

        }
    }
    delete [] mask;
    dst=test.clone();
    //this->showImage(dst);
    imshow("dst",test);
    //save=dst.clone();
    //temp=dst.clone();
}
void MainWindow::on_pushButton_ZC_clicked()
{
    ui->spinBox->setValue(5);
    cv::Mat test;
    cv::Mat output;
    output.create(cv::Size(dst.cols-4,dst.rows-4),CV_16SC1);
    test.create(cv::Size(output.cols-1,output.rows),CV_8UC1);
    int count=0;
    int val;
    int size=ui->spinBox->text().toInt()*ui->spinBox->text().toInt();
    int *mask=new int[size];
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setFixedSize(30*5+30,30*5+40);

    for(int i=0;i<5;i++)
    {
        ui->tableWidget->setRowHeight(i,30);
        ui->tableWidget->setColumnWidth(i,30);

    }

    ui->tableWidget->setItem(0,0,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(0,2,new QTableWidgetItem("-1"));
    ui->tableWidget->setItem(0,3,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(0,4,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(1,0,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(1,1,new QTableWidgetItem("-1"));
    ui->tableWidget->setItem(1,2,new QTableWidgetItem("-2"));
    ui->tableWidget->setItem(1,3,new QTableWidgetItem("-1"));
    ui->tableWidget->setItem(1,4,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(2,0,new QTableWidgetItem("-1"));
    ui->tableWidget->setItem(2,1,new QTableWidgetItem("-2"));
    ui->tableWidget->setItem(2,2,new QTableWidgetItem("16"));
    ui->tableWidget->setItem(2,3,new QTableWidgetItem("-2"));
    ui->tableWidget->setItem(2,4,new QTableWidgetItem("-1"));
    ui->tableWidget->setItem(3,0,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(3,1,new QTableWidgetItem("-1"));
    ui->tableWidget->setItem(3,2,new QTableWidgetItem("-2"));
    ui->tableWidget->setItem(3,3,new QTableWidgetItem("-1"));
    ui->tableWidget->setItem(3,4,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(4,0,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(4,1,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(4,2,new QTableWidgetItem("-1"));
    ui->tableWidget->setItem(4,3,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(4,4,new QTableWidgetItem("0"));

    Sleep(1000);

    //
    for(int i=0;i<ui->spinBox->text().toInt();i++)
    {
        for(int j=0;j<ui->spinBox->text().toInt();j++)
        {
            mask[count]=ui->tableWidget->item(i,j)->text().toInt();

            count++;
        }
    }

    for(int i =  2; i < dst.rows-2 ; i++)
    {
        for(int j = 2 ;j < dst.cols-2 ; j++)
        {
            val=0;
            int k=0;

            for(int m=((ui->spinBox->text().toInt()-1)/-2);m<=((ui->spinBox->text().toInt()-1)/2);m++)
            {
                for(int n=((ui->spinBox->text().toInt()-1)/-2);n<=((ui->spinBox->text().toInt()-1)/2);n++)
                {
                    val=val+mask[k]*dst.at<Vec3b>(i+m,j+n)[1];
                    k++;

                }
            }
            output.at<char>(i-2,j-2) = val;

        }
    }
    for(int i=0; i < output.rows;i++)
    {

        for(int j=0; j <output.cols-1;j++)
        {
            int d=output.at<char>(i,j)*output.at<char>(i,j+1);

            if( d < 0)
            {
                test.at<uchar>(i,j)=255;

            }
            else
            {
                test.at<uchar>(i,j)=0;
            }
        }
    }

    delete [] mask;
    //this->showImage(dst);
    imshow("test",test);
    save=dst.clone();
    temp=dst.clone();
}

//void MainWindow::on_actionFourier_triggered()
//{
//    //const char* filename = argc >=2 ? argv[1] : "001.jpg";
//    QString filename = "001.bmp";
//    Mat I = imread(filename.toStdString(), CV_LOAD_IMAGE_GRAYSCALE);
////    if( I.empty())
////        return -1;

//    Mat padded;                            //expand input image to optimal size
//    int m = getOptimalDFTSize( I.rows );
//    int n = getOptimalDFTSize( I.cols ); // on the border add zero values
//    copyMakeBorder(I, padded, 0, m - I.rows, 0, n - I.cols, BORDER_CONSTANT, Scalar::all(0));

//    Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};
//    Mat complexI;
//    merge(planes, 2, complexI);         // Add to the expanded another plane with zeros

//    dft(complexI, complexI);            // this way the result may fit in the source matrix

//    // compute the magnitude and switch to logarithmic scale
//    // => log(1 + sqrt(Re(DFT(I))^2 + Im(DFT(I))^2))
//    split(complexI, planes);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
//    magnitude(planes[0], planes[1], planes[0]);// planes[0] = magnitude
//    Mat magI = planes[0];

//    magI += Scalar::all(1);                    // switch to logarithmic scale
//    log(magI, magI);

//    // crop the spectrum, if it has an odd number of rows or columns
//    magI = magI(Rect(0, 0, magI.cols & -2, magI.rows & -2));

//    // rearrange the quadrants of Fourier image  so that the origin is at the image center
//    int cx = magI.cols/2;
//    int cy = magI.rows/2;

//    Mat q0(magI, Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant
//    Mat q1(magI, Rect(cx, 0, cx, cy));  // Top-Right
//    Mat q2(magI, Rect(0, cy, cx, cy));  // Bottom-Left
//    Mat q3(magI, Rect(cx, cy, cx, cy)); // Bottom-Right

//    Mat tmp;                           // swap quadrants (Top-Left with Bottom-Right)
//    q0.copyTo(tmp);
//    q3.copyTo(q0);
//    tmp.copyTo(q3);

//    q1.copyTo(tmp);                    // swap quadrant (Top-Right with Bottom-Left)
//    q2.copyTo(q1);
//    tmp.copyTo(q2);

//    normalize(magI, magI, 0, 1, CV_MINMAX); // Transform the matrix with float values into a
//    // viewable image form (float between values 0 and 1).

//    imshow("Input Image"       , I   );    // Show the result
//    imshow("spectrum magnitude", magI);
//    waitKey();
//}

void MainWindow::on_actionFourier_triggered()
{
    ui->pushButton_Fourier->click();
}

void MainWindow::on_pushButton_Fourier_clicked()
{
    cv::cvtColor(temp,temp,CV_BGR2GRAY);
    Mat temp2;
    Mat temp3;
    qDebug() << temp.cols;
    qDebug() << temp.rows;
    if(temp.rows%2!=0)
    {
        temp2.create(temp.rows-1,temp.cols,CV_8UC1);
        for(int i=0 ;i<temp.rows-1;i++)
        {
            for(int j=0;j<temp.cols;j++)
            {
                temp2.at<uchar>(i,j)=temp.at<uchar>(i,j);
            }
        }

    }

    else
        temp2=temp;
    qDebug() << temp2.cols;
    qDebug() << temp2.rows;
    if(temp.cols%2!=0)
    {

        temp3.create(temp2.rows,temp.cols-1,CV_8UC1);

        for(int i=0 ;i<temp2.rows;i++)
        {
            for(int j=0;j<temp.cols-1;j++)
            {
                temp3.at<uchar>(i,j)=temp2.at<uchar>(i,j);
            }
        }

    }
    else
        temp3=temp2;
    qDebug() << temp3.cols;
    qDebug() << temp3.rows;
    imshow("temp3",temp3);
    Mat I=temp3;
    if( I.empty())
        return ;
    qDebug() << I.cols;
    qDebug() << I.rows;
    Mat padded;
    padded.create(temp3.rows,temp3.cols,CV_32F);
    Mat complexI;//expand input image to optimal size

    //copyMakeBorder(I, padded, 0, m - I.rows, 0, n - I.cols, BORDER_CONSTANT, Scalar::all(0));

    complexI.create(temp3.rows,temp3.cols,CV_32FC2);
    complexI.zeros(temp3.rows,temp3.cols,CV_32FC2);

    for(int i=0; i< I.rows;i++)
    {
        for(int j=0; j <I.cols;j++)
        {
            complexI.at<Vec2f>(i,j)[0]=I.at<uchar>(i,j);
        }
    }
    Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};
    dft(complexI, complexI);            // this way the result may fit in the source matrix
    // compute the magnitude and switch to logarithmic scale
    // => log(1 + sqrt(Re(DFT(I))^2 + Im(DFT(I))^2))

    //split(complexI, planes);
    planes[0].create(complexI.rows,complexI.cols,CV_32F);
    planes[0].zeros(complexI.rows,complexI.cols,CV_32F);
    planes[1].create(complexI.rows,complexI.cols,CV_32F);
    planes[1].zeros(complexI.rows,complexI.cols,CV_32F);


    for(int i=0; i< I.rows;i++)
    {
        for(int j=0; j <I.cols;j++)
        {
            planes[0].at<float>(i,j)=complexI.at<Vec2f>(i,j)[0];
            planes[1].at<float>(i,j)=complexI.at<Vec2f>(i,j)[1];
        }
    }
    //planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))


    //magnitude(planes[0], planes[1], planes[0]);// planes[0] = magnitude
    for(int i=0; i< I.rows;i++)
    {
        for(int j=0; j <I.cols;j++)
        {
            planes[0].at<float>(i,j)=sqrt(pow(planes[0].at<float>(i,j),2)+pow(planes[1].at<float>(i,j),2));
        }
    }


    Mat magI = planes[0];

    //magI += Scalar::all(1);                    // switch to logarithmic scale
    log(magI, magI);

    // crop the spectrum, if it has an odd number of rows or columns
    //magI = magI(Rect(0, 0, magI.cols & -2, magI.rows & -2));

    // rearrange the quadrants of Fourier image  so that the origin is at the image center
    int mx = magI.cols/2;//x
    int my = magI.rows/2;//y
    qDebug() << magI.cols;
    qDebug() << magI.rows;
    qDebug() << mx;
    qDebug() << my;
    Mat q0;
    q0.create(my,mx,CV_32F);
    Mat q0m;
    q0m.create(my,mx,CV_32F);
    Mat q0i;
    q0i.create(my,mx,CV_32F);
    //Mat q0(magI, Rect(0, 0, mx, my));   // Top-Left - Create a ROI per quadrant
    for(int i=0; i< my;i++)
    {
        for(int j=0; j <mx;j++)
        {
            q0.at<float>(i,j)=magI.at<float>(i,j);
            q0m.at<float>(i,j)=planes[0].at<float>(i,j);
            q0i.at<float>(i,j)=planes[1].at<float>(i,j);
        }
    }

    //normalize(q0, q0, 0, 1, CV_MINMAX);
    //imshow("q0",q0);
    //        return;
    Mat q1;
    q1.create(my,mx,CV_32F);
    Mat q1m;
    q1m.create(my,mx,CV_32F);
    Mat q1i;
    q1i.create(my,mx,CV_32F);
    for(int i= 0 ; i< my;i++)
    {
        for(int j=mx; j < magI.cols;j++)
        {
            q1.at<float>(i,j-mx)=magI.at<float>(i,j);
            q1m.at<float>(i,j-mx)=planes[0].at<float>(i,j);
            q1i.at<float>(i,j-mx)=planes[1].at<float>(i,j);
        }
    }

    //normalize(q1, q1, 0, 1, CV_MINMAX);
    //imshow("q1",q1);

    //        Mat q1(magI, Rect(mx, 0, mx, my));  // Top-Right
    //        Mat q2(magI, Rect(0, my, mx, my));  // Bottom-Left
    //        Mat q3(magI, Rect(mx, my, mx, my)); // Bottom-Right
    Mat q2;
    q2.create(my,mx,CV_32F);
    Mat q2m;
    q2m.create(my,mx,CV_32F);
    Mat q2i;
    q2i.create(my,mx,CV_32F);
    for(int i= 0; i< magI.rows-my;i++)
    {
        for(int j=0; j < mx;j++)
        {
            if(i < q2.rows && j< q2.cols){
                q2.at<float>(i,j)=magI.at<float>(i+my,j);
                q2m.at<float>(i,j)=planes[0].at<float>(i+my,j);
                q2i.at<float>(i,j)=planes[1].at<float>(i+my,j);
            }
        }

    }

    //  normalize(q2, q2, 0, 1, CV_MINMAX);
    // imshow("q2",q2);
    // viewable image form (float between values 0 and 1).
    Mat q3;
    q3.create(my,mx,CV_32F);
    Mat q3m;
    q3m.create(my,mx,CV_32F);
    Mat q3i;
    q3i.create(my,mx,CV_32F);
    for(int i=0; i< magI.rows+my;i++)
    {
        for(int j=0; j <magI.cols+mx;j++)
        {
            if(i < q3.rows && j< q3.cols){
                q3.at<float>(i,j)=magI.at<float>(i+my,j+mx);
                q3m.at<float>(i,j)=planes[0].at<float>(i+my,j+mx);
                q3i.at<float>(i,j)=planes[1].at<float>(i+my,j+mx);
            }
        }
    }

    //normalize(q3, q3, 0, 1, CV_MINMAX);
    //imshow("q3",q3);
    Mat temp;
    temp.create(magI.rows,magI.cols,CV_32F);
    Mat temprel;
    temprel.create(magI.rows,magI.cols,CV_32F);
    Mat tempimg;
    tempimg.create(magI.rows,magI.cols,CV_32F);
    for(int i=0; i< my;i++)
    {
        for(int j=0; j < mx ;j++)
        {
            temp.at<float>(i+my,j+mx)=q0.at<float>(i,j);
            temprel.at<float>(i+my,j+mx)=q0.at<float>(i,j);
            tempimg.at<float>(i+my,j+mx)=q0.at<float>(i,j);
        }

    }

    for(int i=0; i< my;i++)
    {
        for(int j=0; j < mx ;j++)
        {
            temp.at<float>(i,j+mx)=q2.at<float>(i,j);
            temprel.at<float>(i,j+mx)=q2.at<float>(i,j);
            tempimg.at<float>(i,j+mx)=q2.at<float>(i,j);
        }
    }
    for(int i=0; i< my;i++)
    {
        for(int j=0; j < mx ;j++)
        {
            temp.at<float>(i+my,j)=q1.at<float>(i,j);
            temprel.at<float>(i+my,j)=q1.at<float>(i,j);
            tempimg.at<float>(i+my,j)=q1.at<float>(i,j);
        }
    }
    for(int i=0; i< my;i++)
    {
        for(int j=0; j < mx ;j++)
        {
            temp.at<float>(i,j)=q3.at<float>(i,j);
            temprel.at<float>(i,j)=q3.at<float>(i,j);
            tempimg.at<float>(i,j)=q3.at<float>(i,j);
        }
    }

    //        for(int i=0; i< temp.cols;i++)
    //        {
    //            for(int j=0; j < temp.rows ;j++)
    //                {
    //                 temp.at<float>(i,j)=temp.at<float>(i,j)/32;
    //            }
    //        }



    normalize(temp, temp, 0, 1, CV_MINMAX);
    imshow("Input Image"       , I   );    // Show the result
    imshow("temp",temp);
    final=temp.clone();
    finalrel=temprel.clone();
    finalimg=tempimg.clone();
    imshow("final",final);
    cv::Mat inverseTransform;
    cv::dft(complexI, inverseTransform, cv::DFT_INVERSE|cv::DFT_REAL_OUTPUT);
    normalize(inverseTransform, inverseTransform, 0, 1, CV_MINMAX);

}

void MainWindow::on_actionIdeal_Filter_triggered()
{


    ui->pushButton_Fourier->click();
    imshow("finalrel",finalrel);
    imshow("finalimg",finalimg);
    Mat distance;
    Mat ideal;

    imshow("final",final);
    distance.create(final.rows,final.cols,CV_32F);
    ideal.create(final.rows,final.cols,CV_32F);
    Mat ans;
    ans.create(final.rows,final.cols,CV_32FC2);
    for(int i=0;i<final.rows;i++)
    {
        for(int j=0;j<final.cols;j++)
        {
            distance.at<float>(i,j)=sqrt(pow(i-final.rows/2,2)+pow(j-final.cols/2,2));
            //qDebug() << distance.at<float>(i,j);
        }
    }
    for(int i=0;i<final.rows;i++)
    {
        for(int j=0;j<final.cols;j++)
        {
            if(distance.at<float>(i,j)<=ui->lcdNumber->value())
                ideal.at<float>(i,j)=1;
            else
                ideal.at<float>(i,j)=0;
        }
    }

    Mat finalmove;
    finalmove.create(final.rows,final.cols,CV_32FC2);
    int mx = final.cols/2;//x
    int my = final.rows/2;//y
    Mat q0mf;
    q0mf.create(my,mx,CV_32F);
    Mat q0if;
    q0if.create(my,mx,CV_32F);
    //Mat q0(magI, Rect(0, 0, mx, my));   // Top-Left - Create a ROI per quadrant
    for(int i=0; i< my;i++)
    {
        for(int j=0; j <mx;j++)
        {
            q0mf.at<float>(i,j)=finalrel.at<float>(i,j);
            q0if.at<float>(i,j)=finalimg.at<float>(i,j);
        }
    }
    imshow("q0mf",q0mf);
    imshow("q0if",q0if);
    Mat q1mf;
    q1mf.create(my,mx,CV_32F);
    Mat q1if;
    q1if.create(my,mx,CV_32F);
    for(int i= 0 ; i< my;i++)
    {
        for(int j=mx; j < final.cols;j++)
        {
            q1mf.at<float>(i,j-mx)=finalrel.at<float>(i,j);
            q1if.at<float>(i,j-mx)=finalimg.at<float>(i,j);
        }
    }
    imshow("q1mf",q1mf);
    imshow("q1if",q1if);
    Mat q2mf;
    q2mf.create(my,mx,CV_32F);
    Mat q2if;
    q2if.create(my,mx,CV_32F);
    for(int i= 0; i< final.rows-my;i++)
    {
        for(int j=0; j < mx;j++)
        {
            if(i < q2mf.rows && j< q2mf.cols){
                q2mf.at<float>(i,j)=finalrel.at<float>(i+my,j);
                q2if.at<float>(i,j)=finalimg.at<float>(i+my,j);
            }
        }

    }
    imshow("q2mf",q2mf);
    imshow("q2if",q2if);
    Mat q3mf;
    q3mf.create(my,mx,CV_32F);
    Mat q3if;
    q3if.create(my,mx,CV_32F);


    for(int i=0; i< final.rows+my;i++)
    {
        for(int j=0; j <final.cols+mx;j++)
        {
            if(i < q3mf.rows && j< q3mf.cols){
                q3mf.at<float>(i,j)=finalrel.at<float>(i+my,j+mx);
                q3if.at<float>(i,j)=finalrel.at<float>(i+my,j+mx);
            }
        }
    }
    imshow("q3mf",q3mf);
    imshow("q3if",q3if);

    for(int i=0; i< my;i++)
    {
        for(int j=0; j < mx ;j++)
        {
            finalmove.at<Vec2f>(i+my,j+mx)[0]=q0mf.at<float>(i,j);
            finalmove.at<Vec2f>(i+my,j+mx)[1]=q0if.at<float>(i,j);
        }
    }

    for(int i=0; i< my;i++)
    {
        for(int j=0; j < mx ;j++)
        {
            finalmove.at<Vec2f>(i,j+mx)[0]=q2mf.at<float>(i,j);
            finalmove.at<Vec2f>(i,j+mx)[1]=q2if.at<float>(i,j);
        }
    }
    for(int i=0; i< my;i++)
    {
        for(int j=0; j < mx ;j++)
        {
            finalmove.at<Vec2f>(i+my,j)[0]=q1mf.at<float>(i,j);
            finalmove.at<Vec2f>(i+my,j)[1]=q1if.at<float>(i,j);
        }
    }
    for(int i=0; i< my;i++)
    {
        for(int j=0; j < mx ;j++)
        {
            finalmove.at<Vec2f>(i,j)[0]=q3mf.at<float>(i,j);
            finalmove.at<Vec2f>(i,j)[1]=q3if.at<float>(i,j);
        }
    }
    for(int i=0;i<final.rows;i++)
    {
//        qDebug() << i;
        for(int j=0;j<final.cols;j++)
        {
            ans.at<Vec2f>(i,j)[0]=ideal.at<float>(i,j)*finalmove.at<Vec2f>(i,j)[0];
            ans.at<Vec2f>(i,j)[1]=ideal.at<float>(i,j)*finalmove.at<Vec2f>(i,j)[1];
        }
    }
    cv::Mat inverseideal;
    cv::dft(ans, inverseideal, cv::DFT_INVERSE|cv::DFT_REAL_OUTPUT);
    normalize(inverseideal, inverseideal, 0, 1, CV_MINMAX);
    imshow("inverseideal",inverseideal);


}



void MainWindow::on_pushButton_HW5_clicked()
{
    hw5 hahaha;
    hahaha.readImage(src);
    hahaha.exec();
}
