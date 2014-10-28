/*
 * Evenement.cpp
 *
 *  Created on: 24 oct. 2014
 *      Author: Hugo
 */

#include "Evenement.h"


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

}

Evenement::~Evenement()
{
#ifdef MAP
	cout<< "Evenement::~Evenement()" <<endl;
#endif

}
