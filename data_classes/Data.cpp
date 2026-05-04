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
#include <fstream>
#include <cstring>

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
Data::Data ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Data>" << endl;
#endif
    loadData();
} //----- Fin de Data


Data::~Data ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Data>" << endl;
#endif
} //----- Fin de ~Data




//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void Data::loadData(){
    // Lecture de sensors.csv et measurements.csv
    ifstream f_sensors("../dataset/sensors.csv");
    //static_assert((f_sensors.is_open()==1),"sensors.csv not found");
    ifstream f_measurements("../dataset/measurements.csv");
    //assert(f_measurements.is_open(),"measurements.csv not found");

    while (!f_measurements.eof())

    


    sensors.push_back();

}