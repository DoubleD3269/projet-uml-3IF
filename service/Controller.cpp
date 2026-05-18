#include "Controller.h"
#include "Sensor.h"
#include "./data_classes/Data.h"
#include <iostream>
#include <bits/stdc++.h>
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

double Controller::quality(double lon, double lat, string date)
{
    Sensor s = data.sensors.begin();
    if ( s != NULL )
    {
        Sensor near_s = s;
        double diff = distance(near_s.getLatitude(), near_s.getLongitude(), lat, lon);
        double dist;
        s++;
        // Find the closest sensor
        for ( s ; s != s.end() ; s++ )
        {
            dist = distance(s.getLatitude(), s.getLongitude(), lat, lon );
            if ( dist < diff ) {
                diff = dist;
                near_s = s;
            }
        }

        // Find the measurement at the given date
        ms = near_s.getMeasurements();
        for (auto measure: ms) {
            if ( measure.getTimestamp() == date )
            {
                return 0.0; // Return quality
            }
        }
    }
    else cout << "Sensors empty" << endl;
}

double Controller::meanQuality(double lon, double lat, double radius, string startDate, string endDate)
{
    return 0;
}