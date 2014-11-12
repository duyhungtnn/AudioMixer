/** **************************************************************
 \file chanson.cpp
 \author Martin Rancourt - 140 59 412
 \author Frederic Poitras - 140 61 677
 \brief Fichier d'entete de la structure representant un chanson
 *****************************************************************/

#ifndef __CHANSON_H__
#define __CHANSON_H__

#include <stdio.h>

#include "vlc/vlc.h"
#include "wav.h"

// ***** Declaration de structures tmp ***** //
struct chanson_t
{
    string fichier;
    string titre;
    string interprete;
    string attribut;
    int nbCopies;
    MusiqueWAV musiqueWav;
};

void init(chanson_t);
string toString(chanson_t);
string recupererProchaineVersion(int);

#endif /* defined(__CHANSON_H__) */
