#include "kmean.h"

Kmean::Kmean():_clusterNum(0),_attemps(1)
  ,_critera(cv::TermCriteria::EPS+cv::TermCriteria::COUNT,10,1)
  ,_kmeanType(cv::KMEANS_PP_CENTERS)
{

}

void Kmean::run()
{
     cv::kmeans(_inputData, _clusterNum, _clusterlabels,
                _critera, _attemps, _kmeanType, _clusterCenters);
}

void Kmean::setInputData(cv::Mat inputData)
{
    inputData.copyTo(_inputData);
}

void Kmean::setClusterNum(int clusterNum)
{
    _clusterNum = clusterNum;
}

void Kmean::setCritera(cv::TermCriteria critera)
{
    _critera = critera;
}

void Kmean::setAttemps(int attemps)
{
    _attemps= attemps;
}

void Kmean::setKmeanType(cv::KmeansFlags kmeanType)
{
    _kmeanType = kmeanType;
}

void Kmean::getClusterLabels(cv::Mat& outClusterLabels)
{
    _clusterlabels.copyTo(outClusterLabels);
}

void Kmean::getClusterCenter(cv::Mat& outClusterCenters)
{
    _clusterCenters.copyTo(outClusterCenters);
}


