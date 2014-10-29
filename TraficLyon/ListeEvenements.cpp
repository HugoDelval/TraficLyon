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
		while((*evenementCourant)->evenementSuivant != NULL;// je crois quej'ai pas le droit vu que l'attribut est
															//privé... donc ca compile pas
															// j'éssayerai avec un double pointeur demain
		{
			evenementCourant=(*evenementCourant)->evenementSuivant;
		}
		(*evenementCourant)->evenementSuivant=(*event).evenementSuivant;
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

