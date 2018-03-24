#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),rng(12345)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    const int MAX_CLUSTERS = 5;
    Scalar colorTab[] =
    {
        Scalar(0, 0, 255),
        Scalar(0,255,0),
        Scalar(255,100,100),
        Scalar(255,0,255),
        Scalar(0,255,255)
    };

    Mat img(500, 500, CV_8UC3);//256

    int k, clusterCount = rng.uniform(2, MAX_CLUSTERS+1);
    int i, sampleCount = rng.uniform(1, 1001);//1~1001 pts
    Mat points(sampleCount, 1, CV_32FC2), labels;
    clusterCount = MIN(clusterCount, sampleCount);
    Mat centers;
    /* generate random sample from multigaussian distribution */
    for( k = 0; k < clusterCount; k++ )
    {
        Point center;
        center.x = rng.uniform(0, img.cols);
        center.y = rng.uniform(0, img.rows);
        Mat pointChunk = points.rowRange(k*sampleCount/clusterCount,
                                         k == clusterCount - 1 ? sampleCount :
                                                                 (k+1)*sampleCount/clusterCount);

        rng.fill(pointChunk, RNG::NORMAL, Scalar(center.x, center.y), Scalar(img.cols*0.05, img.rows*0.05));
    }
    randShuffle(points, 1, &rng);

    Kmean kmean;
    kmean.setInputData(points);
    kmean.setClusterNum(clusterCount);
    kmean.setCritera(TermCriteria( TermCriteria::EPS+TermCriteria::COUNT, 10, 1.0));
    kmean.setAttemps(3);
    kmean.setKmeanType(cv::KMEANS_PP_CENTERS);
    kmean.run();
    kmean.getClusterLabels(labels);
    kmean.getClusterCenter(centers);

    img = Scalar::all(0);
    for( i = 0; i < sampleCount; i++ )
    {
        int clusterIdx = labels.at<int>(i);
        Point ipt = points.at<Point2f>(i);
        circle( img, ipt, 2, colorTab[clusterIdx], FILLED, LINE_AA );
    }
    imshow("clusters", img);
}

void MainWindow::on_pushButton_2_clicked()
{
    cv::Mat inputImage = cv::imread("E:\\QTApp\\OpenCvTest\\123.jpg");
    assert(inputImage.type() == CV_8UC3);
    cv::imshow("RawImage", inputImage);

    //1-D
    cv::Mat reshapeImg = inputImage.reshape(1, inputImage.cols * inputImage.rows);
    assert(reshapeImg.type() == CV_8UC1);

    //normalize 0~1
    cv::Mat reshapeTo32f;
    reshapeImg.convertTo(reshapeTo32f, CV_32FC1, 1.0 / 255.0);
    assert(reshapeTo32f.type() == CV_32FC1);

    //kmean initial
    cv::Mat dataLabels;
    cv::Mat clusterCenters;
    cv::TermCriteria criteria(TermCriteria::EPS+TermCriteria::COUNT, 10, 1);
    int clusterNum = 5;

    Kmean kmean;
    kmean.setInputData(reshapeTo32f);
    kmean.setClusterNum(clusterNum);
    kmean.setCritera(criteria);
    kmean.setKmeanType(cv::KMEANS_PP_CENTERS);
    kmean.run();
    kmean.getClusterLabels(dataLabels);
    kmean.getClusterCenter(clusterCenters);

    showResultImg(dataLabels, clusterCenters, inputImage.rows,inputImage.cols);

}

void MainWindow::showResultImg(const cv::Mat& labels, const cv::Mat& centers, int height, int width)
{
    std::cout << "labels: " << labels.rows << " " << labels.cols << std::endl;
    std::cout << "centers: " << centers.rows << " " << centers.cols << std::endl;
    assert(labels.type() == CV_32SC1);
    assert(centers.type() == CV_32FC1);

    cv::Mat rgb_image(height, width, CV_8UC3);
    cv::MatIterator_<cv::Vec3b> rgb_first = rgb_image.begin<cv::Vec3b>();
    cv::MatIterator_<cv::Vec3b> rgb_last = rgb_image.end<cv::Vec3b>();
    cv::MatConstIterator_<int> label_first = labels.begin<int>();

    //rescle to 0~255
    cv::Mat centers_u8;
    centers.convertTo(centers_u8, CV_8UC1, 255.0);

    //1-D rgb to 3-D rgb
    cv::Mat centers_u8c3 = centers_u8.reshape(3);

    while ( rgb_first != rgb_last ) {

        const cv::Vec3b& rgb = centers_u8c3.ptr<cv::Vec3b>(*label_first)[0];
        *rgb_first = rgb;//fill color
        ++rgb_first;
        ++label_first;
    }
    cv::imshow("Result", rgb_image);
    cv::waitKey();
}
