/*
 * Evenement.cpp
 *
 *  Created on: 24 oct. 2014
 *      Author: Hugo
 */

#include "Evenement.h"
#include <stddef.h>  // permet de connaitre 'NULL'

void Evenement::attribuerEvenementSuivant(Evenement *nextEvent)   // un setEvenementSuivant en gros...
{
	evenementSuivant=nextEvent;
}

Evenement::Evenement()
{

#ifdef MAP
	cout<< "Evenement::Evenement()" <<endl;
#endif
	annee=0;
	mois=0;
	nJourMois=0;
	minutes=0;
	secondes=0;
	evenementSuivant=NULL;
}

Evenement::Evenement(int anneeEvent , int moisEvent, int nJourMoisEvent, int minutesEvent, int secondesEvent)
{
#ifdef MAP
	cout<< "Evenement::Evenement(int anneeEvent , int moisEvent, int nJourMoisEvent, int minutesEvent, int secondesEvent)" <<endl;
#endif
	annee=anneeEvent;
	mois=moisEvent;
	nJourMois=nJourMoisEvent;
	minutes=minutesEvent;
	secondes=secondesEvent;
	evenementSuivant=NULL;

}


Evenement::~Evenement()
{
#ifdef MAP
	cout<< "Evenement::~Evenement()" <<endl;
#endif

}
