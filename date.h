/** **************************************************************
 \file date.h
 \author Martin Rancourt - 140 59 412
 \author Frederic Poitras - 140 61 677
 \brief Structure representant une date
 *****************************************************************/

#ifndef __DATE_H__
#define __DATE_H__

#include <stdio.h>
#include <string>

struct date_t
{
    int jour;
    int mois;
    int annee;
};

void init(date_t &);
void setDate(date_t &, int, int, int);
std::string dateToString(date_t);

#endif /* defined(__DATE_H__) */