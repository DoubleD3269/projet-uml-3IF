#include "Controller.h"
#include "./data_classes/Data.h"
#include <iostream>
#include <cmath>
using namespace std;

Controller::Controller()
{
    data = new Data();
}

Controller::~Controller() {}

double Distance(double lat1, double lon1, double lat2, double lon2) const
{
    const double R = 6371.0; // Earth radius in km
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1 * M_PI / 180.0) * cos(lat2 * M_PI / 180.0) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return R * c;
}

Controller::meanQuality(double lon, double lat, double radius, string startDate, string endDate)
{
    return 0;
}