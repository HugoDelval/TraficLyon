/*
 * ListeEvenements.cpp
 *
 *  Created on: 28 oct. 2014
 *      Author: Papin
 */

#include "ListeEvenements.h"
#include "Evenement.h"
#include <stddef.h>  // permet de connaitre 'NULL'

void ListeEvenements::ajouterDansLaListe(Evenement event)
{
	evenementCourant=racine;
	if(racine==NULL)
	{
		*racine=event;
	} else {
		while((*evenementCourant)->evenementSuivant != NULL)  // comment acceder a evenement suivant
															 // sans 'getEvenementSuivant' ?
		{
			evenementCourant=(*evenementCourant)->evenementSuivant;
		}
		evenementCourant->attribuerEvenementSuivant((*event).evenementSuivant);
	}
}

ListeEvenements::ListeEvenements() {
	racine=NULL;
	evenementCourant=NULL;
}

ListeEvenements::~ListeEvenements() {
	evenementCourant=racine;
	Evenement *evenementALiberer;
	while (evenementCourant != NULL)
	{
		evenementALiberer=evenementCourant;
		evenementCourant=evenementCourant->evenementSuivant;
		delete *evenementCourant;
	}
}

