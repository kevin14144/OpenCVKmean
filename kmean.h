#ifndef KMEAN_H
#define KMEAN_H

#include <core.hpp>
#include <highgui.hpp>
#include <qdebug.h>
class Kmean
{
public:
    Kmean();
    void run();
    void setInputData(cv::Mat inputData);
    void setClusterNum(int clusterNum);
    void setCritera(cv::TermCriteria critera);
    void setAttemps(int attemps);
    void setKmeanType(cv::KmeansFlags kmeanType);
    void getClusterLabels(cv::Mat &outClusterLabels);
    void getClusterCenter(cv::Mat &outClusterCenters);
private:
    cv::Mat _inputData;
    cv::Mat _clusterlabels;
    cv::Mat _clusterCenters;
    cv::TermCriteria _critera;
    cv::KmeansFlags _kmeanType;
    int _attemps;
    int _clusterNum;
};

#endif // KMEAN_H
