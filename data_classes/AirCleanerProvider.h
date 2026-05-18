#ifndef AIRCLEANERPROVIDER_H
#define AIRCLEANERPROVIDER_H
#include "User.h"
#include <stdlib.h>
#include <string>
#include <vector>

class AirCleaner;

class AirCleanerProvider : public User{

    public:
        // Initializes a new provider
        AirCleanerProvider();

        AirCleanerProvider(std::string id);

        AirCleanerProvider(std::string providerId, std::vector<AirCleaner*> cleaners);

        // Cleans up resources
        ~AirCleanerProvider();

        // Returns all air cleaners managed by this provider
        std::vector<AirCleaner*> getCleaners();

        // Adds an AirCleaner to the provider's cleaners
        void addCleaner(AirCleaner* cleaner);

    private:
        std::string providerId;                      // Unique provider identifier
        std::vector<AirCleaner*> cleaners;      // List of managed air cleaners
};

#endif