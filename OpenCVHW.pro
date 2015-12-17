#-------------------------------------------------
#
# Project created by QtCreator 2015-09-15T19:03:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = OpenCVHW
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    dialogfuzzylogic.cpp \
    qsmartlabel.cpp \
    hw5.cpp \


HEADERS  += mainwindow.h \
    qcustomplot.h \
    dialogfuzzylogic.h \
    qsmartlabel.h \
    hw5.h \


FORMS    += mainwindow.ui \
    dialogfuzzylogic.ui \
    hw5.ui


OpenCV_Lib = $$quote(G:\opencv\build\x86\vc11\lib)

INCLUDEPATH +=  $$quote(G:\opencv\build\include)

    Release: LIBS +=    $$OpenCV_Lib/opencv_ts300.lib\
                        $$OpenCV_Lib/opencv_world300.lib \
                        $$qdarkstyle/style.qrc

    Debug: LIBS +=      $$OpenCV_Lib/opencv_ts300d.lib\
                        $$OpenCV_Lib/opencv_world300d.lib \
                        $$qdarkstyle/style.qrc

RESOURCES += \
    qdarkstyle/style.qrc
