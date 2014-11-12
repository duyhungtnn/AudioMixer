/** **************************************************************
 \file chanson.cpp
 \author Martin Rancourt - 140 59 412
 \author Frederic Poitras - 140 61 677
 \brief Structure representant un chanson
 *****************************************************************/

#include "chanson.h"

void init(chanson_t Chanson)
{
    Chanson.fichier = "";
    Chanson.nbCopies = 0;
    Chanson.titre = "UnTitre";
    Chanson.interprete = "UnInterprete";
    Chanson.attribut = "UnAttribut";
    
    Chanson.musiqueWav = MusiqueWAV();
}

string toString(chanson_t Chanson)
{
    
    string toString =
    "Fichier : " + Chanson.fichier + "\n" +
    "Titre : " + Chanson.titre + "\n" +
    "NbCopies : " + to_string(Chanson.nbCopies) + "\n" +
    "Interprete : " + Chanson.interprete + "\n" +
    "Attribut : " + Chanson.attribut;
    
    return toString;
}

string recupererProchaineVersion(int nbCopies)
{
    return to_string(++nbCopies);
}