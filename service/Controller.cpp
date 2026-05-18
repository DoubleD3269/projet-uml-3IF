#include "Controller.h"
#include "./data_classes/Data.h"
#include <iostream>
using namespace std;

Controller::Controller ( )
{
    data = new Data();
}

Controller::~Controller() {}

Controller::meanQuality(double lon, double lat, double radius, string startDate, string endDate) 
{
    return 0;
}