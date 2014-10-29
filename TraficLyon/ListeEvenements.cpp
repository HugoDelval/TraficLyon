/*
 * ListeEvenements.cpp
 *
 *  Created on: 28 oct. 2014
 *      Author: Papin
 */

#include "ListeEvenements.h"

void ListeEvenements::ajouterDansLaListe(Evenement *event)
{
	//evenementCourant=racine;
	if(racine==NULL)
	{
		racine=event;
		evenementCourant=event;
	} else
	{
		(*evenementCourant).evenementSuivant=event;
		evenementCourant=event;
	}
}

ListeEvenements::ListeEvenements()
{
	racine=NULL;
	evenementCourant=NULL;
}

ListeEvenements::~ListeEvenements()
{
	evenementCourant=racine;
	Evenement *evenementALiberer;
	while (evenementCourant != NULL)
	{
		evenementALiberer=evenementCourant;
		evenementCourant=evenementCourant->evenementSuivant;
		delete evenementALiberer;
	}
}

