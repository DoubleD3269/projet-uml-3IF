#include "Sensor.h"
#include <iostream>
using namespace std;

Sensor::Sensor ( string id, double lon, double lat, vector<Measurement*> measurements )
{
    this->measurements = measurements;
    this->attributeID = id;
    this->longitude = lon;
    this->latitude = lat;
    this->isReliable = true;
}

Sensor::~Sensor() {}

Sensor::getLongitude () 
{
    return longitude;
}

Sensor::getLatitude () 
{
    return latitude;
}

Sensor::getID()
{
    return sensorID;
}

Sensor::getReliability () 
{
    return isReliable;
}

Sensor::setReliability( bool reliability )
{
    this->isReliable = reliability;
}