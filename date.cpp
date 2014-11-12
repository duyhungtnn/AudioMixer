/** **************************************************************
 \file date.cpp
 \author Martin Rancourt - 140 59 412
 \author Frederic Poitras - 140 61 677
 \brief Structure representant une date
 *****************************************************************/

#include "date.h"
#include <string>

void init(date_t &date)
{
    const int INIT_JOUR = 1;
    const int INIT_MOIS = 1;
    const int INIT_ANNEE = 1970;
    
    date.jour = INIT_JOUR;
    date.mois = INIT_MOIS;
    date.annee = INIT_ANNEE;
}

void setDate(date_t &date, int jour, int mois, int annee)
{
    date.jour = jour;
    date.mois = mois;
    date.annee = annee;
}

std::string dateToString(date_t date)
{
    std::string toString = std::to_string(date.jour) + " " + std::to_string(date.mois) + " " + std::to_string(date.annee);
    
    return toString;
}