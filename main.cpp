#include <iostream>
#include "data_classes/Data.h"
#include "data_classes/Sensor.h"

using std namespace;


int main() {
    // Initialization
    int choice;
    // Load users and data

    
    // Authentication : NOT IMPLEMENTED

    // Main menu
    while (true)
    {
        // All functions are available to every user
        cout << "1: Get statistics" << endl;
        cout << "Private user\n2: Add a private sensor" << endl;
        cout << "Agency member\n3: Classify a sensor as unreliable" << endl;
        cout << "AirCleaner Provider\n4: Calculate the radius of a cleaned zone\n5: Calculate the improvement in air quality"<< endl;
        cin >> choice;

        if (choix == 0) {
            cout << "Goodbye." << endl;
            break;
        }

        switch(choix)
        {
        case 1: // Get statistics
        {
            
            break;
        }
        case 2: // Add a private sensor
        {
            
            break;
        }
        case 3: // Classify a sensor as unreliable
        {
            
            break;
        }
        case 4: // Calculate the radius of a cleaned zone
        {
            
            break;
        }
        case 5: // Calculate the improvement in air quality
        {
            
            break;
        }
        default:
            cout << "Choix incorrect\n";
            continue;
        }
    }
    
    return 0;
}