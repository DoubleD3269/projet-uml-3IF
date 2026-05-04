#include <stdlib.h>
#include <string>
#include "AirCleaner.h"

AirCleaner::AirCleaner() : longitude(0.0), latitude(0.0), startTime(0), endTime(0), provider(nullptr) {
}

AirCleaner::AirCleaner(std::string cleanerID, double longitude, double latitude, long startTime, long endTime, AirCleanerProvider* provider)
    : cleanerID(cleanerID), longitude(longitude), latitude(latitude), startTime(startTime), endTime(endTime), provider(provider) {
}

AirCleaner::~AirCleaner(){
}

std::pair<double, double> AirCleaner::getCoords(){
    std::pair<double, double> coords (longitude,latitude);
    return coords;
}

long AirCleaner::getStart(){
    return startTime;
}

long AirCleaner::getEnd(){
    return endTime;
}