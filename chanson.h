/** **************************************************************
 \file chanson.h
 \author Martin Rancourt - 140 59 412
 \author Frederic Poitras - 140 61 677
 \brief Fichier d'entete de la structure representant un chanson
 *****************************************************************/

#ifndef __CHANSON_H__
#define __CHANSON_H__

#include <stdio.h>

#include "date.h"
#include "vlc/vlc.h"
#include "wav.h"

// ***** Declaration de structures tmp ***** //
struct chanson_t
{
    string titre;
    string interprete;
    string fichier;
    string attribut;
    date_t dateEnregistrement;
    MusiqueWAV musiqueWav;
    bool originale;
    int nbCopies;
};

void init(chanson_t &);
string toString(chanson_t);
string recupererProchaineVersion(int);

#endif /* defined(__CHANSON_H__) */
