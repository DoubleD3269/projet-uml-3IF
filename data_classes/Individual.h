#ifndef Individual_H
#define Individual_H
#include "User.h"
#include <stdlib.h>
#include <string>
#include <vector>

class Sensor;

// Class representing a Individual inheriting from User
class Individual : public User{

    public:
        // Constructor - initializes a new Individual object with points = 0, isReliable = true
        Individual(){
            points = 0;
            isReliable = true;
        }

        // Destructor - cleans up Individual object resources
        ~Individual();

        void addPoints(int points);
        std::vector<Sensor*> getSensors();
        void classifySensors(bool reliable);
        
        void addSensor(Sensor* sensor){
            sensors.push_back(sensor);
        }

    private:
        int points;
        std::vector<Sensor*> sensors;
        bool isReliable;

};

#endif