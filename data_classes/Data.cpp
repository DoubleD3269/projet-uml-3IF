/*************************************************************************
                           Data  -  description
                             -------------------
    début                : 04/05/2026
    e-mail               : didac.espin@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Data> (fichier Data.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "Sensor.h"
#include "Measurement.h"

//------------------------------------------------------ Include personnel
#include "Data.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Data::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Data::Data()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Data>" << endl;
#endif
    loadData();
} //----- Fin de Data

Data::~Data()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Data>" << endl;
#endif
} //----- Fin de ~Data

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void Data::loadData()
{
    // Lecture de sensors.csv et measurements.csv
    ifstream f_sensors("../dataset/sensors.csv");
    // static_assert((f_sensors.is_open()==1),"sensors.csv not found");
    ifstream f_measurements("../dataset/measurements.csv");
    // assert(f_measurements.is_open(),"measurements.csv not found");

    string sensor_s;
    string measurement_s;

    while (getline (f_sensors, sensor_s)) {
        std::stringstream ss(sensor_s);
        string longitude_s;
        string latitude_s;
        string id;

        getline(ss, id, ';');
        getline(ss, longitude_s, ';');
        getline(ss, latitude_s, ';');

        vector<Measurement*> measurements;

        Sensor* sensor = new Sensor(id, stod(longitude_s), stod(latitude_s), measurements);

        sensors.insert({id, sensor});

    }

    while (getline (f_measurements, measurement_s)) {
        double valueO3 = -1;
        double valueSO2 = -1;
        double valueNO2 = -1;
        double valuePM10 = -1;

        std::stringstream ss(measurement_s);
        string time_s;
        string sensor_id;
        string measurement_type;
        string value_s;

        getline(ss, time_s, ';');
        getline(ss, sensor_id, ';');
        getline(ss, measurement_type, ';');
        getline(ss, value_s, ';');

        if (measurement_type == "O3"){
                valueO3 = stod(value_s);

            }
            else if (measurement_type == "NO2"){
                valueNO2 = stod(value_s);

            }
            else if (measurement_type == "SO2"){
                valueSO2 = stod(value_s);

            }
            else if (measurement_type == "PM10"){
                valuePM10 = stod(value_s);
            }

        for (int i =0;i<3;i++){

            if(getline (f_measurements, measurement_s)){

                std::stringstream ss(measurement_s);

                getline(ss, time_s, ';');
                getline(ss, sensor_id, ';');
                getline(ss, measurement_type, ';');
                getline(ss, value_s, ';');

            }

            if (measurement_type == "O3"){
                valueO3 = stod(value_s);

            }
            else if (measurement_type == "NO2"){
                valueNO2 = stod(value_s);

            }
            else if (measurement_type == "SO2"){
                valueSO2 = stod(value_s);

            }
            else if (measurement_type == "PM10"){
                valuePM10 = stod(value_s);
            }
        }

        Measurement* measurement = new Measurement(time_s,valueO3,valueSO2,valueNO2,valuePM10);


        sensors[sensor_id] -> addMeasurement(measurement);

    }
}

vector<Sensor> Data ::getSensors()
{
    return sensors;
}

vector<AirCleaner> Data ::getCleaners()
{
    return cleaners;
}