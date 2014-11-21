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

/** ----------------------------------------------------------------------
 \brief Fonction permettant d'initialiser la chanson
 \param [in] chanson : chanson de type chanson_t
 \param [out] chanson : chanson initialisee
 ----------------------------------------------------------------------- **/
void init(chanson_t &chanson)
{

    // Initialisation de la date
    date_t date;
    init(date);
    
    // Initialisation des attributs
    chanson.titre = "";
    chanson.interprete = "";
    chanson.fichier = "";
    chanson.attribut = "";
    chanson.dateEnregistrement = date;
    chanson.originale = true;
    chanson.nbCopies = 0;
    chanson.musiqueWav = MusiqueWAV();
}

/** ----------------------------------------------------------------------
 \brief Fonction retournant une chanson au format de chaîne de caracteres
 \param [in] chanson : chanson de type chanson_t
 \return : chanson au format chaaîne de caracteres
 ----------------------------------------------------------------------- **/
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

/** ----------------------------------------------------------------------
 \brief Fonction retournant le prochain numero d'une chanson au format de 
 chaîne de caracteres
 \param [in] nbCopie : Numero courant de la copie
 \return numero de la prochaine version au format chaine de caracteres
 ----------------------------------------------------------------------- **/
string recupererProchaineVersion(int nbCopies)
{
    return to_string(++nbCopies);
}