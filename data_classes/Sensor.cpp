#include "Sensor.h"
#include <iostream>
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

double Sensor::getLongitude () 
{
    return longitude;
}

double Sensor::getLatitude () 
{
    return latitude;
}

string Sensor::getID()
{
    return sensorID;
}

bool Sensor::getReliability () 
{
    return isReliable;
}

void Sensor::setReliability( bool reliability )
{
    this->isReliable = reliability;
}