#include "Measurement.h"
#include <iostream>
using namespace std;

Measurement::Measurement (string timestamp, double valueO3, double valueSO2, double valueNO2, double valuePM10 )
{
    this->timestamp = timestamp;
    this->valueO3 = valueO3;
    this->valueSO2 = valueSO2;
    this->valueNO2 = valueNO2;
    this->valuePM10 = valuePM10;
}

Measurement::~Measurement() {}

double Measurement::getO3()
{
    return valueO3;
}

double Measurement::getSO2()
{
    return valueSO2;
}

double Measurement::getNO2()
{
    return valueNO2;
}

double Measurement::getPM1O()
{
    return valuePM10;
}

string Measurement::getTimestamp()
{
    return timestamp;
}