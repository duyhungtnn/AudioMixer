/** **************************************************************
 \file chanson.cpp
 \author Martin Rancourt - 140 59 412
 \author Frederic Poitras - 140 61 677
 \brief Structure representant un chanson
 *****************************************************************/

#include <ios>

#include "chanson.h"
#include "date.h"

using namespace std;

void init(chanson_t &Chanson)
{

    // Initialisation de la date
    date_t date;
    init(date);
    
    // Initialisation des attributs
    Chanson.titre = "";
    Chanson.interprete = "";
    Chanson.fichier = "";
    Chanson.attribut = "";
    Chanson.dateEnregistrement = date;
    Chanson.originale = true;
    Chanson.nbCopies = 0;
    Chanson.musiqueWav = MusiqueWAV();
}

string toString(chanson_t Chanson)
{
    
    const string OUI = "Oui";
    const string NON = "Non";
    
    string originale = Chanson.originale ? OUI : NON;
    
    string toString =
    "Titre : " + Chanson.titre + "\n" +
    "Interprete : " + Chanson.interprete + "\n" +
    "Fichier : " + Chanson.fichier + "\n" +
    "Date enr.: " + dateToString(Chanson.dateEnregistrement) + "\n" +
    "NbCopies : " + to_string(Chanson.nbCopies) + "\n" +
    "Attribut : " + Chanson.attribut + "\n"
    "Originale : " + originale;
    
    return toString;
}

string recupererProchaineVersion(int nbCopies)
{
    return to_string(++nbCopies);
}