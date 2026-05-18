//---------- Interface de la classe <Controller> (fichier Controller.h) ----------------
#if !defined(CONTROLLER_H)
#define CONTROLLER_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <vector>
#include <string>
#include "./data_classes/Data.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Controller>
// Implements all the services available to the users
//
//------------------------------------------------------------------------

class Controller
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    double meanQuality(double lon, double lat, double radius, string startDate, string endDate);
    // Compute the mean quality of the air between the startDate and the endDate, in an area

    double meanQuality(double lon, double lat, double radius, string date);
    // Compute the mean quality of the air at a given date in an area within a certain radius

    double quality(double lon, double lat, string date);
    // Compute the quality of the air in an area at a given date. Find the closest sensor
    
    vector<string> rankSensors(string sensorID);
    // Rank every sensor considering their last entry. Calculate the squared difference with the given sensor's last entry

    vector<double> sensorData(string sensorID);
    // Return every data one sensor has produced

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    Controller(); // Initialize data

    ~Controller();

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Attributs et méthodes protégés
    Data data;

    double Distance(double lat1, double lon1, double lat2, double lon2) const; 
    // Compute the distance between two points in (longitude, latitude)
    
    int IQA(Measurement m) const; 
    // Compute Air Quality of a measurement, return the worst ATMO index between the four measurements (O3, SO2, NO2, PM10)
    
    int getAtmo(double val, vector<double>& thresholds) const;
    // return the ATMO index, given the thresholds and the value 
};

//-------------------------------- Autres définitions dépendantes de <Controller>

#endif // CONTROLLER_H