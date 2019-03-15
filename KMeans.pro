#-------------------------------------------------
#
# Project created by QtCreator 2018-01-06T12:49:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KMeans
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    form.cpp \
    kmean.cpp

HEADERS += \
        mainwindow.h \
    form.h \
    kmean.h

FORMS += \
        mainwindow.ui \
    form.ui \
    form.ui

INCLUDEPATH += D:\OpenCv331\install\include\
D:\OpenCv331\install\include\opencv2\
E:\QTApp\OpenCVKMean\thridPart\

CONFIG(debug, debug|release){
LIBS+=D:/OpenCv331/install/x64/vc14/lib/opencv_core331d.lib\
D:/OpenCv331/install/x64/vc14/lib/opencv_highgui331d.lib\
D:/OpenCv331/install/x64/vc14/lib/opencv_imgproc331d.lib\
D:/OpenCv331/install/x64/vc14/lib/opencv_imgcodecs331d.lib\
D:/OpenCv331/install/x64/vc14/lib/opencv_cudev331d.lib\
D:/OpenCv331/install/x64/vc14/lib/opencv_cudafilters331d.lib\
D:/OpenCv331/install/x64/vc14/lib/opencv_cudawarping331d.lib\
E:/QTApp/OpenCVKMean/thridPart/opencv331Wrap.lib\
}
