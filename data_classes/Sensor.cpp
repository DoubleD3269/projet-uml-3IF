#include "Sensor.h"
#include <iostream>
#include <vector>
using namespace std;

Sensor::Sensor ( string id, double lon, double lat, vector<Measurement*> measurements )
{
    this->measurements = measurements;
    this->sensorID = id;
    this->longitude = lon;
    this->latitude = lat;
    this->isReliable = true;
}

Sensor::~Sensor() {}

vector<Measurement*> *getMeasurements() const
{
    return &measurements;
}

double Sensor::getLongitude () const
{
    return longitude;
}

double Sensor::getLatitude () const
{
    return latitude;
}

string Sensor::getID () const
{
    return sensorID;
}

bool Sensor::getReliability () const
{
    return isReliable;
}

void Sensor::setReliability( bool reliability )
{
    this->isReliable = reliability;
}