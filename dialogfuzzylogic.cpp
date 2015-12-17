#include "dialogfuzzylogic.h"
#include "ui_dialogfuzzylogic.h"

DialogFuzzyLogic::DialogFuzzyLogic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFuzzyLogic)
{
    ui->setupUi(this);

    bell.resize(511);
    triangWH.resize(256);
    triangBL.resize(256);
    Bell.mean     = 0;
    Bell.b        = 53;

    TriangWH.center = 255;
    TriangWH.left   = 209;
    TriangWH.right  = 1;
    TriangBL.center = 0;
    TriangBL.left   = -1;
    TriangBL.right  = 85;

    ui->spinBox_bellThreshold->setValue(Bell.b);
    ui->horizontalSlider_bellThreshold->setValue(Bell.b);
    ui->spinBox_outputLeftBound->setValue((TriangWH.center-TriangWH.left));
    ui->horizontalSlider_outputLeftBound->setValue((TriangWH.center-TriangWH.left));
    ui->spinBox_outputRightBound->setValue(TriangBL.center+TriangBL.right);
    ui->horizontalSlider_outputRightBound->setValue(TriangBL.center+TriangBL.right);
}

DialogFuzzyLogic::~DialogFuzzyLogic()
{
    delete ui;
}

void DialogFuzzyLogic::drawBell()
{
    ui->bellShapePlot->clearGraphs();
    QVector<double> x(511);
    int i=0;
    #pragma omp parallel for private(i)
    for(i = 0; i < 511 ; i++)
    {
        bell[i] = bellCurve(i-255, Bell.b, Bell.mean);
        x[i] = i-255;
    }
    ui->bellShapePlot->addGraph();
    ui->bellShapePlot->graph(0)->setData(x, bell);
    ui->bellShapePlot->xAxis->setRange(-255,255);
    ui->bellShapePlot->yAxis->setRange(0,1);
    ui->bellShapePlot->replot();
}

void DialogFuzzyLogic::drawTriang()
{
    ui->triangPlot->clearGraphs();
    QVector<double> x2(256);
    int i=0;
    #pragma omp parallel for private(i)
    for(i=0;i < 256; i++)
    {
        triangWH[i] = triangShape(i, TriangWH.center, TriangWH.left, TriangWH.right);
        x2[i] = i;
    }
    #pragma omp parallel for private(i)
    for(i=0;i < 256; i++)
    {
        triangBL[i] = triangShape(i, TriangBL.center, TriangBL.left, TriangBL.right);
    }
    ui->triangPlot->addGraph();
    ui->triangPlot->graph(0)->setData(x2,triangWH);
    ui->triangPlot->addGraph();
    ui->triangPlot->graph(1)->setData(x2,triangBL);
    ui->triangPlot->xAxis->setRange(0,255);
    ui->triangPlot->yAxis->setRange(0,1);
    ui->triangPlot->replot();
}

void DialogFuzzyLogic::setShowImage(cv::Mat &img)
{
    cv::Mat show;
    //myCV::myCvtColor(img, show, myCV::GRAY2GBR);
    if(img.type()==CV_8UC1)
        cv::cvtColor(img, show, cv::COLOR_GRAY2BGR);
    else
        show = img.clone();
    QImage qshow = QImage(show.data, show.cols, show.rows, show.step, QImage::Format_RGB888).rgbSwapped();
    qshow = qshow.scaled(ui->label_fuzzy->width(), ui->label_fuzzy->height(), Qt::KeepAspectRatio);
    ui->label_fuzzy->setPixmap(QPixmap::fromImage(qshow));
}

void DialogFuzzyLogic::readImage(cv::Mat &img)
{
    originImg = img.clone();

//    cv::Mat result;
//    fuzzy.setFuzzyFunctionType(1);
//    fuzzy.setBellCurveProperties(Bell.mean, Bell.b);
//    fuzzy.setTriangWHProperties(TriangWH.center, TriangWH.left, TriangWH.right);
//    fuzzy.setTriangBLProperties(TriangBL.center, TriangBL.left, TriangBL.right);
//    fuzzy.getBoundaries(originImg, result);
    setShowImage(originImg);
}

void DialogFuzzyLogic::computeResult(cv::Mat &outputResult)
{

//    fuzzy.setFuzzyFunctionType(1);
//    fuzzy.setBellCurveProperties(Bell.mean, Bell.b);
//    fuzzy.setTriangWHProperties(TriangWH.center, TriangWH.left, TriangWH.right);
//    fuzzy.setTriangBLProperties(TriangBL.center, TriangBL.left, TriangBL.right);
     getBoundaries(originImg, outputResult);


}
void DialogFuzzyLogic::getBoundaries(cv::Mat &inputArray, cv::Mat &outputArray)
{
    cv::Mat tmp;
    if(inputArray.type() == CV_8UC3)
    {cv::cvtColor(inputArray, tmp, CV_BGR2GRAY);}
    else
    {tmp = inputArray.clone();}
    cv::Mat&& dest = cv::Mat::zeros(tmp.size().height, tmp.size().width, CV_8UC1);


        int&& lThresh = Bell.mean - Bell.b;
        int&& rThresh = Bell.mean + Bell.b;
        int i;
        double memfunc;
        #pragma omp parallel for private(i) firstprivate(memfunc)
        for(int j = 0; j < tmp.size().height; j++)
            for(i = 0; i < tmp.size().width; i++)
            {
                memfunc = 0;
                int&& tjplus  = (j + 1) >= tmp.size().height ? j : j+1;
                int&& tjminus = (j - 1) < 0 ? j : j-1;
                int&& tiplus  = (i + 1) >= tmp.size().width ? i : i+1;
                int&& timinus = (i - 1) < 0 ? i : i-1;
                auto&& up_d   = tmp.at<uchar>(tjminus, i) - tmp.at<uchar>(j,i);
                auto&& down_d = tmp.at<uchar>(tjplus, i)  - tmp.at<uchar>(j,i);
                auto&& left_d = tmp.at<uchar>(j, timinus) - tmp.at<uchar>(j,i);
                auto&& right_d= tmp.at<uchar>(j, tiplus)  - tmp.at<uchar>(j,i);

                if(tjminus != j && up_d > (lThresh) && up_d < (rThresh))
                {
                    if(timinus != i && left_d > (lThresh) && left_d < (rThresh))
                    {
                        memfunc += bellCurve(up_d, Bell.b, Bell.mean);
                        memfunc += bellCurve(left_d, Bell.b, Bell.mean);
                        dest.at<uchar>(j,i) = (inverseTriangWH(memfunc/2)*(memfunc/2) + inverseTriangBL(1.0-memfunc/2)*(1.0-memfunc/2));
                    }
                    else if(tiplus != i && right_d > (lThresh) && right_d < (rThresh))
                    {
                        memfunc += bellCurve(up_d, Bell.b, Bell.mean);
                        memfunc += bellCurve(right_d, Bell.b, Bell.mean);
                        dest.at<uchar>(j,i) = (inverseTriangWH(memfunc/2)*(memfunc/2) + inverseTriangBL(1.0-memfunc/2)*(1.0-memfunc/2));
                    }
                }
                else if(tjplus !=j && down_d > (lThresh) && down_d < (rThresh))
                {
                    if(timinus != i && left_d > (lThresh) && left_d < (rThresh))
                    {
                        memfunc += bellCurve(down_d, Bell.b, Bell.mean);
                        memfunc += bellCurve(left_d, Bell.b, Bell.mean);
                        dest.at<uchar>(j,i) = (inverseTriangWH(memfunc/2)*(memfunc/2) + inverseTriangBL(1.0-memfunc/2)*(1.0-memfunc/2));
                    }
                    else if(tiplus != i && right_d > (lThresh) && right_d < (rThresh))
                    {
                        memfunc += bellCurve(down_d, Bell.b, Bell.mean);
                        memfunc += bellCurve(right_d, Bell.b, Bell.mean);
                        dest.at<uchar>(j,i) = (inverseTriangWH(memfunc/2)*(memfunc/2) + inverseTriangBL(1.0-memfunc/2)*(1.0-memfunc/2));
                    }
                }
                else
                {
                    memfunc += bellCurve(up_d, Bell.b, Bell.mean);
                    memfunc += bellCurve(right_d, Bell.b, Bell.mean);
                    memfunc += bellCurve(down_d, Bell.b, Bell.mean);
                    memfunc += bellCurve(left_d, Bell.b, Bell.mean);

                    dest.at<uchar>(j,i) = (inverseTriangBL(memfunc/4)*(memfunc/4)+inverseTriangWH(1.0-memfunc/4)*(1.0-memfunc/4));

                }

        outputArray.release();
        outputArray = dest.clone();
        tmp.release();
        dest.release();
    }
}
uchar DialogFuzzyLogic::inverseTriangWH(double memf)
{
    int&& ans = memf * (255-TriangWH.left) + TriangWH.left;
    if(ans < 0)
        ans = 0;
    else if(ans > 255)
        ans = 255;

    return ans;
}

uchar DialogFuzzyLogic::inverseTriangBL(double memf)
{
    int&& ans = memf * TriangBL.right;
    if(ans < 0)
        ans = 0;
    else if(ans > 255)
        ans = 255;

    return ans;
}
double DialogFuzzyLogic::sShape(int x, int a, int b, int c)
{
    if(x < a)
    {
        return 0;
    }
    else if(x >= a && x <= b)
    {
        return 2*pow((double)(x-a)/(double)(c-a),2);
    }
    else if(x > b && x <= c)
    {
        return 1-2*pow((double)(x-c)/(double)(c-a),2);
    }
    else
        return 1;
}

double DialogFuzzyLogic::bellCurve(int x, int b, int c)
{
    if(x <= c)
    {
        return sShape(x, c-b, c-((double)b/2),c);
    }
    else
    {
        return 1 - sShape(x, c, c+((double)b/2), c+b);
    }
}

double DialogFuzzyLogic::triangShape(int x, int center, int a, int b)
{
    if(center - a <= x && x < center)
    {
        return  1-((center-x)/(double)a);
    }
    else if(center <= x && x < center + b)
    {
        return 1-((x-center)/(double)b);
    }
    else
    {
        return 0;
    }
}

void DialogFuzzyLogic::on_horizontalSlider_bellThreshold_valueChanged(int value)
{
    ui->spinBox_bellThreshold->setValue(value);
}

void DialogFuzzyLogic::on_spinBox_bellThreshold_valueChanged(int arg1)
{
    ui->horizontalSlider_bellThreshold->setValue(arg1);
    Bell.b = ui->spinBox_bellThreshold->value();
    drawBell();
}

void DialogFuzzyLogic::on_horizontalSlider_outputLeftBound_valueChanged(int value)
{
    ui->spinBox_outputLeftBound->setValue(value);
}

void DialogFuzzyLogic::on_spinBox_outputLeftBound_valueChanged(int arg1)
{
    ui->horizontalSlider_outputLeftBound->setValue(arg1);
    TriangWH.left = TriangWH.center - ui->spinBox_outputLeftBound->value();
    drawTriang();
}

void DialogFuzzyLogic::on_horizontalSlider_outputRightBound_valueChanged(int value)
{
    ui->spinBox_outputRightBound->setValue(value);
}

void DialogFuzzyLogic::on_spinBox_outputRightBound_valueChanged(int arg1)
{
    ui->horizontalSlider_outputRightBound->setValue(arg1);
    TriangBL.right = TriangBL.center + ui->spinBox_outputRightBound->value();
    drawTriang();
}

void DialogFuzzyLogic::on_horizontalSlider_bellThreshold_sliderReleased()
{

    cv::Mat result;
    computeResult(result);
    setShowImage(result);
}

void DialogFuzzyLogic::on_spinBox_bellThreshold_editingFinished()
{
    cv::Mat result;
    computeResult(result);
    setShowImage(result);
}

void DialogFuzzyLogic::on_horizontalSlider_outputLeftBound_sliderReleased()
{
    cv::Mat result;
    computeResult(result);
    setShowImage(result);
}

void DialogFuzzyLogic::on_spinBox_outputLeftBound_editingFinished()
{
    cv::Mat result;
    computeResult(result);
    setShowImage(result);
}

void DialogFuzzyLogic::on_horizontalSlider_outputRightBound_sliderReleased()
{
    cv::Mat result;
    computeResult(result);
    setShowImage(result);
}

void DialogFuzzyLogic::on_spinBox_outputRightBound_editingFinished()
{
    cv::Mat result;
    computeResult(result);
    setShowImage(result);
}
