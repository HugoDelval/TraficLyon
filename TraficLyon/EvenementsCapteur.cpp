/*
 * EvenementsCapteur.cpp
 *
 *  Created on: 7 nov. 2014
 *      Author: Hugo
 */

#include "EvenementsCapteur.h"


void EvenementsCapteur::ajouter(int heure, int jourSemaine, int trafic,
				 	 	 	 	int anneeEvent , int moisEvent, int nJourMoisEvent,
				 	 	 	 	int minutesEvent, int secondesEvent)
{

}

void EvenementsCapteur::afficher()
{

}

void EvenementsCapteur::EvenementsCapteur(int heure, int jourSemaine, int trafic,
				 	 	 	 			  int anneeEvent , int moisEvent, int nJourMoisEvent,
				 	 	 	 			  int minutesEvent, int secondesEvent)
{
	secondesAnneeDernierEvenement=0;
	// TODO lsdcfs
	anneeDernierEvenement=anneeEvent;
	traficDernierEvenement=trafic;
	heureDernierEvenement=heure;
	jourSemaineDernierEvenement = jourSemaine;


	int ***secondesPassees;
}


EvenementsCapteur::~EvenementsCapteur()
{
	// TODO Auto-generated destructor stub
}

