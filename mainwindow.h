#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <core.hpp>
#include <highgui.hpp>

#include <cudabgsegm.hpp>
#include <cudaarithm.hpp>
#include <cudafeatures2d.hpp>
#include <cudaimgproc.hpp>
#include <cudawarping.hpp>

#include "imgproc.hpp"
#include <iostream>
#include <kmean.h>
#include <QDebug>
#include <ctime>
#include "vector"

using namespace cv;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();


private:
    void showResultImg(const cv::Mat& labels, const cv::Mat& centers, int height, int width);
    Ui::MainWindow *ui;
    RNG rng;


};

#endif // MAINWINDOW_H
