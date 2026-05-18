#include <stdlib.h>
#include <string>
#include "AirCleaner.h"

AirCleaner::AirCleaner(){}

AirCleaner::AirCleaner(std::string cleanerID, double longitude, double latitude, std::string startTime, std::string endTime, AirCleanerProvider* provider)
    : cleanerID(cleanerID), longitude(longitude), latitude(latitude), startTime(startTime), endTime(endTime), provider(provider) {
}

AirCleaner::~AirCleaner(){
}

std::pair<double, double> AirCleaner::getCoords(){
    std::pair<double, double> coords (longitude,latitude);
    return coords;
}

std::string AirCleaner::getStart(){
    return startTime;
}

std::string AirCleaner::getEnd(){
    return endTime;
}

std::string AirCleaner::setProvider(AirCleanerProvider* newprov){
    provider = newprov;
}