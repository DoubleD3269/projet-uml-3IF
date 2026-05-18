//---------- Interface de la classe <Measurement> (fichier Measurement.h) ----------------
#if ! defined ( MEASUREMENT_H )
#define MEASUREMENT_H


//--------------------------------------------------- Interfaces utilisées

#include <string>

using std::string;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// La classe <Measurement> permet de stocker une entrée d'un capteur

//------------------------------------------------------------------------

class Measurement 
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
        double getO3() const;
        // Return the value of the O3 measurement

        double getSO2() const;
        // Return the value of the SO2 measurement

        double getNO2() const;
        // Return the value of the NO2 measurement

        double getPM10() const;
        // Return the value of the PM10 measurement

        string getTimestamp() const;
        // Return the timestamp

        friend ostream & operator << (ostream & out, const Measurement & m);
        // Allows the display of a measurement in ostream

    //-------------------------------------------- Constructeurs - destructeur
        Measurement (string timestamp, double valueO3, double valueSO2, double valueNO2, double valuePM10 );

        Measurement(){};

        ~Measurement ( );
        
    //------------------------------------------------------------------ PRIVE

    protected:
    //----------------------------------------------------- Attributs protégés
        string timestamp;
        double valueO3;
        double valueSO2;
        double valueNO2;
        double valuePM10;
};
#endif