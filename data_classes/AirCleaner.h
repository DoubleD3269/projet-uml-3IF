#ifndef AIRCLEANER_H
#define AIRCLEANER_H
#include <stdlib.h>
#include <string>

class AirCleanerProvider;

// Represents an air cleaner device with location and operational timeframe
class AirCleaner{
    public:
        AirCleaner();
        AirCleaner(std::string cleanerID, double longitude, double latitude, long startTime, long endTime, AirCleanerProvider* provider);
        ~AirCleaner();

        // Returns geographic coordinates (longitude, latitude) as an std::pair
        std::pair<double, double> getCoords();
        // Returns cleaner operation start time
        long getStart();
        // Returns cleaner operation end time
        long getEnd();

    private:
        std::string cleanerID;           // Unique identifier for the cleaner
        double longitude;           // Geographic longitude coordinate
        double latitude;            // Geographic latitude coordinate
        long startTime;                 // Operation start time (timestamp)
        long endTime;                   // Operation end time (timestamp)
        AirCleanerProvider* provider; // Reference to the provider managing this cleaner
};

#endif