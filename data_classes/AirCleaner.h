#ifndef AIRCLEANER_H
#define AIRCLEANER_H
#include <stdlib.h>
#include <string>

class AirCleanerProvider;

// Represents an air cleaner device with location and operational timeframe
class AirCleaner{
    public:
        AirCleaner();
        AirCleaner(std::string cleanerID, double longitude, double latitude, std::string startTime, std::string endTime, AirCleanerProvider* provider);
        ~AirCleaner();

        // Returns geographic coordinates (longitude, latitude) as an std::pair
        std::pair<double, double> getCoords();
        // Returns cleaner operation start time
        std::string getStart();
        // Returns cleaner operation end time
        std::string getEnd();
        // Returns cleaner operation end time
        std::string setProvider(AirCleanerProvider* provider);

    private:
        std::string cleanerID;           // Unique identifier for the cleaner
        double longitude;           // Geographic longitude coordinate
        double latitude;            // Geographic latitude coordinate
        std::string startTime;                 // Operation start time (timestamp)
        std::string endTime;                   // Operation end time (timestamp)
        AirCleanerProvider* provider; // Reference to the provider managing this cleaner
};

#endif