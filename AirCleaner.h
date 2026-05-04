#ifndef AIRCLEANER_H
#define AIRCLEANER_H
#include <stdlib.h>
#include <string>

using namespace std;

class AirCleanerProvider;

// Represents an air cleaner device with location and operational timeframe
class AirCleaner{
    public:
        AirCleaner();
        ~AirCleaner();

        // Returns geographic coordinates (longitude, latitude)
        std::pair<double, double> getCoords();
        // Returns cleaner operation start time
        long getStart();
        // Returns cleaner operation end time
        long getEnd();

    private:
        string cleanerID;           // Unique identifier for the cleaner
        double longitude;           // Geographic longitude coordinate
        double latitude;            // Geographic latitude coordinate
        long start;                 // Operation start time (timestamp)
        long end;                   // Operation end time (timestamp)
        AirCleanerProvider& provider; // Reference to the provider managing this cleaner
};

#endif