#include <stdlib.h>
#include <string>
#include "AirCleanerProvider.h"

AirCleanerProvider::AirCleanerProvider() {};

AirCleanerProvider::AirCleanerProvider(std::string providerId, std::vector<AirCleaner*> cleaners)
    : providerId(providerId), cleaners(cleaners){
}

AirCleanerProvider::~AirCleanerProvider(){
}

std::vector<AirCleaner*> AirCleanerProvider::getCleaners(){
    return cleaners;
}