//---------- Interface de la classe <Sensor> (fichier Sensor.h) ----------------
#if ! defined ( SENSOR_H )
#define SENSOR_H


//--------------------------------------------------- Interfaces utilisées
#include "Measurement.h"
#include <string>
#include <vector>

using std::string;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// La classe <Sensor> permet de stocker les caractéristiques d'un capteur

//------------------------------------------------------------------------

class Sensor 
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
        vector<Measurement*>* getMeasurements();
        // Return the pointer of the vector
        
        string getID();

        double getLongitude();
        
        double getLatitude();

        bool getReliability();

        void setReliability( bool reliability );

    //-------------------------------------------- Constructeurs - destructeur
        Sensor ( string id, double lon, double lat, vector<Measurement*> measurements );

        ~Sensor ( );
        
    //------------------------------------------------------------------ PRIVE

    protected:
    //----------------------------------------------------- Attributs protégés
        string sensorID;
        double longitude;
        double latitude;
        bool isReliable; // initialized at true
        vector<Measurement*> measurements; // Liste de Measurements, objet qui contient une donnée fournie par un capteur
    };
#endif