/** **************************************************************
 \file date.cpp
 \author Martin Rancourt - 140 59 412
 \author Frederic Poitras - 140 61 677
 \brief Structure representant une date
 *****************************************************************/

#include "date.h"
#include <string>

using namespace std;

/** ----------------------------------------------------------------------
 \brief Fonction permettant d'initialiser la date
 \param [in] date : Date de type date_t
 \param [out] date : Date initialisee
 ----------------------------------------------------------------------- **/
void init(date_t &date)
{
    // Declaration des constantes pour la date par defaut
    const int INIT_JOUR = 1;
    const string INIT_MOIS = "janvier";
    const int INIT_ANNEE = 1970;
    
    // Initialisation des attributs de la date
    date.jour = INIT_JOUR;
    date.mois = INIT_MOIS;
    date.annee = INIT_ANNEE;
}

/** ----------------------------------------------------------------------
 \brief Fonction permettant de definir le jour, le mois et l'annee de la date
 \param [in] date : Date de type date_t
 \param [in] jour : jour de la date
 \param [in] mois : mois de la date
 \param [in] annee : annee de la date
 \param [out] date : Date modifiee
 ----------------------------------------------------------------------- **/
void setDate(date_t &date, int jour, string mois, int annee)
{
    // Affectation des valeurs de la nouvelle date
    date.jour = jour;
    date.mois = mois;
    date.annee = annee;
}

/** ----------------------------------------------------------------------
 \brief Fonction retournant une date au format de chaîne de caracteres
 \param [in] date : Date de type date_t
 \return : Date au format chaaîne de caracteres
 ----------------------------------------------------------------------- **/
string dateToString(date_t date)
{
    // Conversion en chaine de caracteres
    string toString = to_string(date.jour) + " " + date.mois + " " + to_string(date.annee);
    
    return toString;
}