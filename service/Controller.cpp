#include "Controller.h"
#include "./data_classes/Data.h"
#include <iostream>
#include <cmath>
#include <numeric>
#include <algorithm>
using namespace std;

Controller::Controller()
{
    data = new Data();
}

Controller::~Controller() {}

double Controller::distance(double lat1, double lon1, double lat2, double lon2) const
{
    const double R = 6371.0; // Earth radius in km
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1 * M_PI / 180.0) * cos(lat2 * M_PI / 180.0) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return R * c;
}

double Controller::mean(const vector<double> &values) const
{
    if (values.empty())
        return -1.0;
    return accumulate(values.begin(), values.end(), 0.0) / values.size();
}

int Controller::subIndex(double val, double s1, double s2, double s3, double s4, double s5) const
{
    if (val <= s1)
        return 1;
    if (val <= s2)
        return 2;
    if (val <= s3)
        return 3;
    if (val <= s4)
        return 4;
    if (val <= s5)
        return 5;
    return 6;
}

int Controller::atmoIndex(double o3, double so2, double no2, double pm10) const
{
    return max({subIndex(o3, 50, 100, 130, 240, 380),
                subIndex(so2, 100, 200, 350, 500, 750),
                subIndex(no2, 40, 90, 120, 230, 340),
                subIndex(pm10, 20, 40, 50, 100, 150)});
}

double Controller::meanQualityAtMoment(double lon, double lat, double radius, string date)
{
    vector<Sensor> allSensors = data.getSensors();
    vector<double> atmoValues;

    for (auto &s : allSensors)
    {
        // Ignorer les capteurs non fiables
        if (!s.getReliability())
            continue;

        // Ignorer les capteurs hors de la zone
        double dist = distance(lat, lon, s.getLatitude(), s.getLongitude());
        if (dist > radius)
            continue;

        // Chercher la mesure a ce timestamp
        for (const auto &m : *s.getMeasurements())
        {
            if (m->getTimestamp() == date)
            {
                int atmo = atmoIndex(m->getO3(), m->getSO2(), m->getNO2(), m->getPM1O());
                atmoValues.push_back(atmo);
                break; // un seul timestamp par capteur
            }
        }
    }

    return mean(atmoValues);
}

Controller::meanQuality(double lon, double lat, double radius, string startDate, string endDate)
{
    return 0;
}