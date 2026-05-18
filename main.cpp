#include <iostream>
#include "data_classes/Data.h"
#include "data_classes/Sensor.h"
#include "service/Controller.h"
#include <string>

using namespace std;


int main() {
    Controller c;

    int choice;
    // Load users and data

    
    // Authentication : NOT IMPLEMENTED

    // Main menu
    while (true)
    {
        // All functions are available to every user
        cout << "Enter the number of the chosen action" << endl;
        cout << "1: Get statistics" << endl;
        cout << "Private user :" << endl;
        cout << "2: Add a private sensor" << endl;
        cout << "Agency member :" << endl;
        cout << "3: Classify a sensor as unreliable" << endl;
        cout << "Air Cleaner Provider :" << endl;
        cout << "4: Calculate the radius of a cleaned zone"<<endl;
        cout << "5: Calculate the improvement in air quality"<< endl;
        cin >> choice;

        if (choice == 0) {
            cout << "Goodbye." << endl;
            break;
        }

        switch(choice)
        {
            case 1: // Get statistics
            {
                cout << "1: All data from a sensor" << endl;
                cout << "2: Mean quality of air in an area" << endl;
                cout << "3: Quality of air at a geographical position" << endl;
                cout << "4: Rank similarity of sensors"<< endl;
                cin >> choice;

                switch(choice){
                    case 1:
                    {
                        string sensor;
                        cout << ">> Enter a sensor id : " << endl;
                        cin >> sensor;
                        vector<Measurement> measurements = c.sensorData();
                        cout << sensor << " measurements :" << endl;
                        for (int i=0;i<measurements.size();++i){
                            cout << measurements[i] << endl;
                        }
                        break;
                    }
                    case 2:
                    {
                        double lat,lon,rd;
                        string startdate,enddate="";
                        cout << ">> Enter the coordinates of the center of the area :" << endl;
                        cout << "> Latitude : " << endl;
                        cin >> lat;
                        cout << "> Longitude : " << endl;
                        cin >> lon;
                        cout << ">> Enter the radius of the area (km): " << endl;
                        cin >> rd;
                        cout << ">> Enter the chosen moment (or start of period) in format : yyyy-mm-dd hh:mm:ss" << endl;
                        cin >> startdate;
                        cout << ">> (Optional) Enter the end of period in format : yyyy-mm-dd hh:mm:ss" << endl;
                        cin >> enddate;
                        if (enddate==""){
                            cout << "Mean air quality in the area on " << startdate << " : " << c.meanQualityAtMoment(lon,lat,rd,startdate) << endl;
                        }
                        else {
                            cout << "Mean air quality in the area from " << startdate << " to " << enddate << " : " << c.meanQualityOverPeriod(lon,lat,rd,startdate,enddate) << endl;
                        }
                        break;
                    }
                }
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