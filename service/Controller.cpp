#include "Controller.h"
#include "../data_classes/Sensor.h"
#include "../data_classes/Data.h"
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <numeric>
#include <algorithm>
using namespace std;

Controller::Controller()
{
    data = Data();
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

int Controller::getAtmo(double val, vector<double> &thresholds) const
{
    for (int i = 0; i < thresholds.size(); i++)
    {
        if ( val < thresholds[i] ) return i + 1;
    }
    return 10;
}

int Controller::IQA(Measurement m) const
{
    double O3 = m.getO3();
    double SO2 = m.getSO2();
    double NO2 = m.getNO2();
    double PM10 = m.getPM10();

    // Upper bound of each index 1-9, index 10 is >= last value
    vector<double> O3_t = {30, 55, 80, 105, 130, 150, 180, 210, 240};
    vector<double> SO2_t = {40, 80, 120, 160, 200, 250, 300, 400, 500};
    vector<double> NO2_t = {30, 55, 85, 110, 135, 165, 200, 275, 400};
    vector<double> PM10_t = {7, 14, 21, 28, 35, 42, 50, 65, 80};

    int atmoO3 = getAtmo(O3, O3_t);
    int atmoSO2 = getAtmo(SO2, SO2_t);
    int atmoNO2 = getAtmo(NO2, NO2_t);
    int atmoPM10 = getAtmo(PM10, PM10_t);

    return max({atmoO3, atmoSO2, atmoNO2, atmoPM10});
}

double Controller::quality(double lon, double lat, string date)
{
    unordered_map<Sensor> s = data.getSensors();

    Sensor near_s = s[0];
    double diff = distance(near_s.getLatitude(), near_s.getLongitude(), lat, lon);
    double dist;
    s++;
    // Find the closest sensor
    for ( int i = 1 ; i < s.size() ; i++ )
    {
        dist = distance(s[i].getLatitude(), s.getLongitude(), lat, lon );
        if ( dist < diff ) {
            diff = dist;
            near_s = s[i];
        }
    }

    // Find the measurement at the given date
    auto ms = near_s.getMeasurements();
    for (auto measure: ms) {
        if ( measure.getTimestamp() == date )
        {
            return IQA( measure ); // Return quality
        }
    }
}

double Controller::meanQuality(double lon, double lat, double radius, string startDate, string endDate)
{
    for (int i = 0; i < thresholds.size(); i++)
    {
        if (value < thresholds[i])
            return i + 1;
    }
    return 10;
}

int Controller::IQA(Measurement m) const
{
    double O3 = m.getO3();
    double SO2 = m.getSO2();
    double NO2 = m.getNO2();
    double PM10 = m.getPM10();

    // Upper bound of each index 1-9, index 10 is >= last value
    vector<double> O3_t = {30, 55, 80, 105, 130, 150, 180, 210, 240};
    vector<double> SO2_t = {40, 80, 120, 160, 200, 250, 300, 400, 500};
    vector<double> NO2_t = {30, 55, 85, 110, 135, 165, 200, 275, 400};
    vector<double> PM10_t = {7, 14, 21, 28, 35, 42, 50, 65, 80};

    int atmoO3 = getAtmo(O3, O3_t);
    int atmoSO2 = getAtmo(SO2, SO2_t);
    int atmoNO2 = getAtmo(NO2, NO2_t);
    int atmoPM10 = getAtmo(PM10, PM10_t);

    return max({atmoO3, atmoSO2, atmoNO2, atmoPM10});
}

double Controller::quality(double lon, double lat, string date)
{
    Sensor s = data.sensors.begin();
    if (s != NULL)
    {
        Sensor near_s = s;
        double diff = distance(near_s.getLatitude(), near_s.getLongitude(), lat, lon);
        double dist;
        s++;
        // Find the closest sensor
        for (s; s != s.end(); s++)
        {
            dist = distance(s.getLatitude(), s.getLongitude(), lat, lon);
            if (dist < diff)
            {
                diff = dist;
                near_s = s;
            }
        }

        // Find the measurement at the given date
        ms = near_s.getMeasurements();
        for (auto measure : ms)
        {
            if (measure.getTimestamp() == date)
            {
                return IQA(measure); // Return quality
            }
        }
    }
    else
        cout << "Sensors empty" << endl;
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

double Controller ::meanQualityOverPeriod(double lon, double lat, double radius, string startDate, string endDate)
{

    vector<Sensor> allSensors = data.getSensors();
    vector<double> atmoValues;

    for (auto &s : allSensors)
    {
        if (!s.getReliability())
            continue;

        double dist = distance(lat, lon, s.getLatitude(), s.getLongitude());
        if (dist > radius)
            continue;

        for (const auto &m : *s.getMeasurements())
        {
            if (m->getTimestamp() >= startDate && m->getTimestamp() <= endDate)
            {
                int atmo = atmoIndex(m->getO3(), m->getSO2(), m->getNO2(), m->getPM1O());
                atmoValues.push_back(atmo);
            }
        }
    }

    return mean(atmoValues);
}