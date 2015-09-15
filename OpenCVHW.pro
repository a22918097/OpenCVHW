#-------------------------------------------------
#
# Project created by QtCreator 2015-09-15T19:03:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenCVHW
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui


OpenCV_Lib = $$quote(G:\opencv\build\x86\vc11\lib)

INCLUDEPATH +=  $$quote(G:\opencv\build\include)

    Release: LIBS +=    $$OpenCV_Lib/opencv_ts300.lib\
                        $$OpenCV_Lib/opencv_world300.lib

    Debug: LIBS +=      $$OpenCV_Lib/opencv_ts300d.lib\
                        $$OpenCV_Lib/opencv_world300d.lib
