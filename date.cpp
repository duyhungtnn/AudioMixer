/** **************************************************************
 \file date.cpp
 \author Martin Rancourt - 140 59 412
 \author Frederic Poitras - 140 61 677
 \brief Structure representant une date
 *****************************************************************/

#include "date.h"
#include <string>

using namespace std;

void init(date_t &date)
{
    const int INIT_JOUR = 1;
    const string INIT_MOIS = "janvier";
    const int INIT_ANNEE = 1970;
    
    date.jour = INIT_JOUR;
    date.mois = INIT_MOIS;
    date.annee = INIT_ANNEE;
}

void setDate(date_t &date, int jour, string mois, int annee)
{
    date.jour = jour;
    date.mois = mois;
    date.annee = annee;
}

string dateToString(date_t date)
{
    string toString = to_string(date.jour) + " " + date.mois + " " + to_string(date.annee);
    
    return toString;
}