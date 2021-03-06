/** **************************************************************
 \file date.h
 \author Martin Rancourt - 140 59 412
 \author Frederic Poitras - 140 61 677
 \brief Structure representant une date
 *****************************************************************/

#ifndef __DATE_H__
#define __DATE_H__

#include <string>

using namespace std;

/** ----------------------------------------------------------------------
 \brief Definition de la structure date_t
 ----------------------------------------------------------------------- **/
struct date_t
{
    int jour;
    string mois;
    int annee;
};

void init(date_t &);
void setDate(date_t &, int, string, int);
string dateToString(date_t);

#endif /* defined(__DATE_H__) */