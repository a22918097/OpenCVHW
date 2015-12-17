#include "hw5.h"
#include "ui_hw5.h"
#include "mainwindow.h"
//#include "svm.h"
hw5::hw5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hw5)
{
    ui->setupUi(this);
    pseudocolortable();
    ui->label_pseudocolor->setVisible(0);
}

void hw5::readImage(cv::Mat &img)
{
    originImg = img.clone();
    setShowImage(originImg);
}

void hw5::pseudocolortable()
{
    // ==== Produce pseudo-color table
    //int total_color = max_distance - min_distance + 1;
    //color_table = new QImage(total_color, 12, QImage::Format_RGB888) ;

    colortable.create(20,360,CV_8UC3);
    float hue_start_angle = 0.0;
    float hue_end_angle = 360.0;

    float h = 0;
    float s = 1.0;
    float v = 255.0;
    //float step = (hue_end_angle - hue_start_angle) / (total_color);

    float f;
    int hi, p, q, t;

//    for (int r = 0; r < color_table->height(); r++) {
//        uchar* ptr = color_table->scanLine(r);
//        for (int c =0; c < color_table->width(); c++) {
//            h = c * step;
//            hi = (int)(h / 60.0) % 6;
//            f = h / 60.0 - hi;
//            p = v * (1 - s);
//            q = v * (1 - f * s);
//            t = v * (1 - (1 - f) * s);

//            switch (hi) {
//            case 0:
//                ptr[3 * c + 0] = v;
//                ptr[3 * c + 1] = t;
//                ptr[3 * c + 2] = p;
//                break;
//            case 1:
//                ptr[3 * c + 0] = q;
//                ptr[3 * c + 1] = v;
//                ptr[3 * c + 2] = p;
//                break;
//            case 2:
//                ptr[3 * c + 0] = p;
//                ptr[3 * c + 1] = v;
//                ptr[3 * c + 2] = t;
//                break;
//            case 3:
//                ptr[3 * c + 0] = p;
//                ptr[3 * c + 1] = q;
//                ptr[3 * c + 2] = v;
//                break;
//            case 4:
//                ptr[3 * c + 0] = t;
//                ptr[3 * c + 1] = p;
//                ptr[3 * c + 2] = v;
//                break;
//            case 5:
//                ptr[3 * c + 0] = v;
//                ptr[3 * c + 1] = p;
//                ptr[3 * c + 2] = q;
//                break;
//            }
//        }
//    }
    for(int i=0;i<colortable.rows;i++)
        for(int j=0;j<colortable.cols;j++)
        {
            h = j ;
            hi = (int)(h / 60.0) % 6;
            f = h / 60.0 - hi;
            p = v * (1 - s);
            q = v * (1 - f * s);
            t = v * (1 - (1 - f) * s);
            switch (hi) {
            case 0:
                colortable.at<cv::Vec3b>(i,j)[0]= v;
                colortable.at<cv::Vec3b>(i,j)[1] = t;
                colortable.at<cv::Vec3b>(i,j)[2] = p;
                break;
            case 1:
                colortable.at<cv::Vec3b>(i,j)[0]= q;
                colortable.at<cv::Vec3b>(i,j)[1] = v;
                colortable.at<cv::Vec3b>(i,j)[2] = p;
                break;
            case 2:
                colortable.at<cv::Vec3b>(i,j)[0]= p;
                colortable.at<cv::Vec3b>(i,j)[1] = v;
                colortable.at<cv::Vec3b>(i,j)[2] = t;
                break;
            case 3:
                colortable.at<cv::Vec3b>(i,j)[0]= p;
                colortable.at<cv::Vec3b>(i,j)[1] = q;
                colortable.at<cv::Vec3b>(i,j)[2] = v;
                break;
            case 4:
                colortable.at<cv::Vec3b>(i,j)[0]= t;
                colortable.at<cv::Vec3b>(i,j)[1] = p;
                colortable.at<cv::Vec3b>(i,j)[2] = v;
                break;
            case 5:
                colortable.at<cv::Vec3b>(i,j)[0]= v;
                colortable.at<cv::Vec3b>(i,j)[1] = p;
                colortable.at<cv::Vec3b>(i,j)[2] = q;
                break;
            }
        }
    cv::resize(colortable,colortable,cv::Size(ui->label_colorbar->width(),ui->label_colorbar->height()));
//    imshow("colortable",colortable);
    ui->label_colorbar->setPixmap(QPixmap::fromImage(M2Q(colortable)));
}

hw5::~hw5()
{
    delete ui;
}


void hw5::setShowImage(cv::Mat &img)
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

QImage hw5::M2Q(const cv::Mat src)
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

double hw5::min(double a, double b, double c)
{
    double min;
    min=a;
    if(a>b)
        min=b;
    if(min>c)
        min=c;
    return min;
}

void hw5::on_pushButton_RGB_clicked()
{
    cv::Mat temp;
    temp=originImg.clone();
    cv::Mat R,G,B;
    R.create(temp.rows,temp.cols,CV_8UC1);
    G.create(temp.rows,temp.cols,CV_8UC1);
    B.create(temp.rows,temp.cols,CV_8UC1);

    for(int i=0;i<temp.rows;i++)
    {
        for(int j=0;j<temp.cols;j++)
        {
            R.at<uchar>(i,j)=temp.at<cv::Vec3b>(i,j)[0];
            G.at<uchar>(i,j)=temp.at<cv::Vec3b>(i,j)[1];
            B.at<uchar>(i,j)=temp.at<cv::Vec3b>(i,j)[2];
        }
    }
    ui->label_1->setVisible(1);
    ui->label_2->setVisible(1);
    ui->label_3->setVisible(1);
    ui->label_pseudocolor->setVisible(0);
    cv::resize(R,R,cv::Size(ui->label_1->width(),ui->label_1->height()));
    cv::resize(G,G,cv::Size(ui->label_2->width(),ui->label_2->height()));
    cv::resize(B,B,cv::Size(ui->label_3->width(),ui->label_3->height()));
    ui->label_1->setPixmap(QPixmap::fromImage(M2Q(R)));
    ui->label_2->setPixmap(QPixmap::fromImage(M2Q(G)));
    ui->label_3->setPixmap(QPixmap::fromImage(M2Q(B)));
}
void hw5::on_pushButton_CMY_clicked()
{
    cv::Mat temp;
    temp=originImg.clone();
    cv::Mat c,m,y;
    c.create(temp.rows,temp.cols,CV_8UC1);
    m.create(temp.rows,temp.cols,CV_8UC1);
    y.create(temp.rows,temp.cols,CV_8UC1);

    for(int i=0;i<temp.rows;i++)
    {
        for(int j=0;j<temp.cols;j++)
        {
            c.at<uchar>(i,j)=255-temp.at<cv::Vec3b>(i,j)[0];
            m.at<uchar>(i,j)=255-temp.at<cv::Vec3b>(i,j)[1];
            y.at<uchar>(i,j)=255-temp.at<cv::Vec3b>(i,j)[2];
        }
    }
    ui->label_1->setVisible(1);
    ui->label_2->setVisible(1);
    ui->label_3->setVisible(1);
    ui->label_pseudocolor->setVisible(0);
    cv::resize(c,c,cv::Size(ui->label_1->width(),ui->label_1->height()));
    cv::resize(m,m,cv::Size(ui->label_2->width(),ui->label_2->height()));
    cv::resize(y,y,cv::Size(ui->label_3->width(),ui->label_3->height()));
    ui->label_1->setPixmap(QPixmap::fromImage(M2Q(c)));
    ui->label_2->setPixmap(QPixmap::fromImage(M2Q(m)));
    ui->label_3->setPixmap(QPixmap::fromImage(M2Q(y)));
}

void hw5::on_pushButton_HSI_clicked()
{
    cv::Mat temp;
    double theta,R,G,B;
    temp=originImg.clone();
    cv::Mat H,S,I;
    H.create(temp.rows,temp.cols,CV_8UC1);
    S.create(temp.rows,temp.cols,CV_8UC1);
    I.create(temp.rows,temp.cols,CV_8UC1);
    for(int i=0;i<temp.rows;i++)
    {
        for(int j=0;j<temp.cols;j++)
        {

            R=temp.at<cv::Vec3b>(i,j)[2]/255.0;//normalize
            G=temp.at<cv::Vec3b>(i,j)[1]/255.0;//normalize
            B=temp.at<cv::Vec3b>(i,j)[0]/255.0;//normalize
            theta=acos((0.5*((R-G)+(R-B)))/(pow(((R-G)*(R-G)+(R-B)*(G-B)),0.5)));
            if(temp.at<cv::Vec3b>(i,j)[0]<=temp.at<cv::Vec3b>(i,j)[1])
                H.at<uchar>(i,j)=theta/3.14*255.0;
            else
                H.at<uchar>(i,j)=(3.14-theta)/3.14*255.0;

            S.at<uchar>(i,j)=(1-3*min(R,G,B)/(R+G+B))*255;
            I.at<uchar>(i,j)=255.0*(R+G+B)/3.0;
        }
    }
    ui->label_1->setVisible(1);
    ui->label_2->setVisible(1);
    ui->label_3->setVisible(1);
    ui->label_pseudocolor->setVisible(0);
    cv::resize(H,H,cv::Size(ui->label_1->width(),ui->label_1->height()));
    cv::resize(S,S,cv::Size(ui->label_2->width(),ui->label_2->height()));
    cv::resize(I,I,cv::Size(ui->label_3->width(),ui->label_3->height()));
    ui->label_1->setPixmap(QPixmap::fromImage(M2Q(H)));
    ui->label_2->setPixmap(QPixmap::fromImage(M2Q(S)));
    ui->label_3->setPixmap(QPixmap::fromImage(M2Q(I)));

}

void hw5::on_pushButton_XYZ_clicked()
{
    cv::Mat temp;
    double R,G,B;
    temp=originImg.clone();
    cv::Mat X,Y,Z;
    X.create(temp.rows,temp.cols,CV_8UC1);
    Y.create(temp.rows,temp.cols,CV_8UC1);
    Z.create(temp.rows,temp.cols,CV_8UC1);

    for(int i=0;i<temp.rows;i++)
    {
        for(int j=0;j<temp.cols;j++)
        {
            R=temp.at<cv::Vec3b>(i,j)[2]/255.0;//normalize
            G=temp.at<cv::Vec3b>(i,j)[1]/255.0;//normalize
            B=temp.at<cv::Vec3b>(i,j)[0]/255.0;//normalize
            X.at<uchar>(i,j)=(0.412453*R+0.35758*G+0.180423*B)*255.0;
            Y.at<uchar>(i,j)=(0.212671*R+0.71516*G+0.072169*B)*255.0;
            Z.at<uchar>(i,j)=(0.019334*R+0.0119193*G+0.950227*B)*255;
        }
    }
    ui->label_1->setVisible(1);
    ui->label_2->setVisible(1);
    ui->label_3->setVisible(1);
    ui->label_pseudocolor->setVisible(0);
    cv::resize(X,X,cv::Size(ui->label_1->width(),ui->label_1->height()));
    cv::resize(Y,Y,cv::Size(ui->label_2->width(),ui->label_2->height()));
    cv::resize(Z,Z,cv::Size(ui->label_3->width(),ui->label_3->height()));
    ui->label_1->setPixmap(QPixmap::fromImage(M2Q(X)));
    ui->label_2->setPixmap(QPixmap::fromImage(M2Q(Y)));
    ui->label_3->setPixmap(QPixmap::fromImage(M2Q(Z)));
}

void hw5::on_pushButton_LAB_clicked()
{
    cv::Mat temp;
    double R,G,B,qx,qy,qz,hx,hy,hz;
    temp=originImg.clone();
    cv::Mat L,a,b,X,Y,Z;
    X.create(temp.rows,temp.cols,CV_32FC1);
    Y.create(temp.rows,temp.cols,CV_32FC1);
    Z.create(temp.rows,temp.cols,CV_32FC1);
    L.create(temp.rows,temp.cols,CV_8UC1);
    a.create(temp.rows,temp.cols,CV_8UC1);
    b.create(temp.rows,temp.cols,CV_8UC1);

    for(int i=0;i<temp.rows;i++)
    {
        for(int j=0;j<temp.cols;j++)
        {
            R=temp.at<cv::Vec3b>(i,j)[2]/255.0;//normalize
            G=temp.at<cv::Vec3b>(i,j)[1]/255.0;//normalize
            B=temp.at<cv::Vec3b>(i,j)[0]/255.0;//normalize
            X.at<float>(i,j)=(0.412453*R+0.35758*G+0.180423*B);
            Y.at<float>(i,j)=(0.212671*R+0.71516*G+0.072169*B);
            Z.at<float>(i,j)=(0.019334*R+0.0119193*G+0.950227*B);
            qx=X.at<float>(i,j)/0.3127;
            qy=Y.at<float>(i,j)/0.3290;
            qz=Z.at<float>(i,j)/0.3583;
            if(qy>0.008856)
                hy=pow(qy,0.333);
            else
                hy=7.787*qy+16/116;

            if(qx>0.008856)
                hx=pow(qx,0.333);
            else
                hx=7.787*qx+16/116;
            if(qz>0.008856)
                hz=pow(qz,0.333);
            else
                hz=7.787*qz+16/116;

            L.at<uchar>(i,j)=(116.0*hy-16);
            if(hx-hy<0)
                a.at<uchar>(i,j)=-500*(hx-hy);
            else
                a.at<uchar>(i,j)=500*(hx-hy);
            if(hy-hz<0)
                b.at<uchar>(i,j)=-200*(hy-hz);
            else
                b.at<uchar>(i,j)=200*(hy-hz);
        }

    }
    ui->label_1->setVisible(1);
    ui->label_2->setVisible(1);
    ui->label_3->setVisible(1);
    ui->label_pseudocolor->setVisible(0);
    cv::resize(L,L,cv::Size(ui->label_1->width(),ui->label_1->height()));
    cv::resize(a,a,cv::Size(ui->label_2->width(),ui->label_2->height()));
    cv::resize(b,b,cv::Size(ui->label_3->width(),ui->label_3->height()));
    ui->label_1->setPixmap(QPixmap::fromImage(M2Q(L)));
    ui->label_2->setPixmap(QPixmap::fromImage(M2Q(a)));
    ui->label_3->setPixmap(QPixmap::fromImage(M2Q(b)));
}

void hw5::on_pushButton_YUV_clicked()
{
    cv::Mat temp;
    double R,G,B;
    temp=originImg.clone();
    cv::Mat Y,U,V;
    Y.create(temp.rows,temp.cols,CV_8UC1);
    U.create(temp.rows,temp.cols,CV_8UC1);
    V.create(temp.rows,temp.cols,CV_8UC1);
    for(int i=0;i<temp.rows;i++)
    {
        for(int j=0;j<temp.cols;j++)
        {
            R=temp.at<cv::Vec3b>(i,j)[2]/255.0;
            G=temp.at<cv::Vec3b>(i,j)[1]/255.0;
            B=temp.at<cv::Vec3b>(i,j)[0]/255.0;
            Y.at<uchar>(i,j)=(0.299*R+0.587*G+0.114*B)*255;
            U.at<uchar>(i,j)=(-0.1687*R-0.3313*G+0.5*B+128)*255;
            V.at<uchar>(i,j)=(0.5*R-0.419*G-0.081*B+128)*255;
        }
    }
    ui->label_1->setVisible(1);
    ui->label_2->setVisible(1);
    ui->label_3->setVisible(1);
    ui->label_pseudocolor->setVisible(0);
    cv::resize(Y,Y,cv::Size(ui->label_1->width(),ui->label_1->height()));
    cv::resize(U,U,cv::Size(ui->label_2->width(),ui->label_2->height()));
    cv::resize(V,V,cv::Size(ui->label_3->width(),ui->label_3->height()));
    ui->label_1->setPixmap(QPixmap::fromImage(M2Q(Y)));
    ui->label_2->setPixmap(QPixmap::fromImage(M2Q(U)));
    ui->label_3->setPixmap(QPixmap::fromImage(M2Q(V)));
}

//void hw5::on_pushButton_SVM_clicked()
//{
//    svm_parameter params;
//    svm_model model;

//    params.svm_type = C_SVC;
//    params.kernel_type = LINEAR;

//    svm_problem *prob;
//    prob = new svm_problem[10];

//    //model = svm_train(prob,&params);

//    svm_node node;
//}

void hw5::on_pushButton_pseudo_clicked()
{
    cv::Mat temp;
    temp=originImg.clone();
    cv::cvtColor(temp,temp,CV_RGB2GRAY);
    //qDebug() << temp.channels();
    cv::Mat pseudoimg;
    pseudoimg.create(temp.rows,temp.cols,CV_8UC3);
    //imshow("temp",temp);

//    return;
//     qDebug () <<pseudoimg.at<cv::Vec3b>(620,0)[2];
    for(int i=0;i<temp.rows;i++)
    {
        for(int j=0;j<temp.cols;j++)
        {
            pseudoimg.at<cv::Vec3b>(i,j)[0]=colortable.at<cv::Vec3b>(0,temp.at<uchar>(i,j))[0];
            pseudoimg.at<cv::Vec3b>(i,j)[1]=colortable.at<cv::Vec3b>(0,temp.at<uchar>(i,j))[1];
            pseudoimg.at<cv::Vec3b>(i,j)[2]=colortable.at<cv::Vec3b>(0,temp.at<uchar>(i,j))[2];
        }
    }
    //imshow("pseudoimg",pseudoimg);
    cv::resize(pseudoimg,pseudoimg,cv::Size(ui->label_pseudocolor->width(),ui->label_pseudocolor->height()));
    ui->label_pseudocolor->setPixmap(QPixmap::fromImage(M2Q(pseudoimg)));
    ui->label_1->setVisible(0);
    ui->label_2->setVisible(0);
    ui->label_3->setVisible(0);
    ui->label_pseudocolor->setVisible(1);

}


