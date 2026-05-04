#ifndef AIRCLEANERPROVIDER_H
#define AIRCLEANERPROVIDER_H
#include "User.h"
#include "AirCleaner.h"
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

class AirCleanerProvider : public User{

    public:
        // Initializes a new provider
        AirCleanerProvider();

        // Cleans up resources
        ~AirCleanerProvider();

        // Returns all air cleaners managed by this provider
        std::vector<AirCleaner*> getCleaners();

    private:
        string providerId;                      // Unique provider identifier
        std::vector<AirCleaner*> cleaners;      // List of managed air cleaners
};

#endif