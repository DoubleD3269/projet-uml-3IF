/*************************************************************************
                           Data  -  description
                             -------------------
    début                : 04/05/2026
    e-mail               : didac.espin@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Data> (fichier Data.h) ----------------
#if ! defined ( DATA_H )
#define DATA_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <vector>
#include <unordered_map>

#include "Sensor.h"
#include "AirCleaner.h"
#include "AirCleanerProvider.h"
#include "Individual.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Data>
// Reads and writes in the dataset files, and converts raw data into usable objects for the Service layer
//
//------------------------------------------------------------------------

class Data
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    vector<Sensor> getSensors();

    vector<AirCleaner> getCleaners();

    vector<AirCleanerProvider> getProviders();

    vector<Individual> getIndividuals();

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    Data ();
    // Calls loadData when called

    virtual ~Data ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    void loadData();
    // Reads the .csv dataset to create all data objects and add them to the Data object.

//----------------------------------------------------- Attributs protégés
    unordered_map<string, Sensor*> sensors;
    vector<AirCleaner> cleaners;
    vector<Individual> individuals;
    vector<AirCleanerProvider> providers;

};

//-------------------------------- Autres définitions dépendantes de <Data>

#endif // DATA_H
