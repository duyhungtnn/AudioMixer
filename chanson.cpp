/** **************************************************************
 \file chanson.cpp
 \author Martin Rancourt - 140 59 412
 \author Frederic Poitras - 140 61 677
 \brief Structure representant un chanson
 *****************************************************************/

#include "chanson.h"

void init(chanson_t Chanson)
{
    Chanson.titre = "UnTitre";
    Chanson.interprete = "UnInterprete";
    Chanson.attribut = "UnAttribut";
    Chanson.musiqueWav = MusiqueWAV();
}

string toString(chanson_t Chanson)
{
    
    string toString = "Titre : " + Chanson.titre + "\n" +
    "Interprete : " + Chanson.interprete + "\n" +
    "Attribut : " + Chanson.attribut;
    
    return toString;
}