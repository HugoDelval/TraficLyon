/*
 * ListeEvenements.cpp
 *
 *  Created on: 28 oct. 2014
 *      Author: Papin
 */

#include "ListeEvenements.h"

void ListeEvenements::ajouterDansLaListe(Evenement *event)
{

	if(racine==NULL)
	{
		racine=event;
		evenementCourant=event;
	}
	else
	{
		evenementCourant->evenementSuivant=event;
		evenementCourant=event;
	}
}

void ListeEvenements::afficherListe(int idCapteur, int heure, int jourSemaine, int trafic)
{
	if(racine==NULL)
	{
		// bloc vide : ne rien faire
	}
	else
	{
		Evenement *e=racine;
		while (e != NULL)
		{
			cout << idCapteur << " " << e->annee << " " << e->mois
					<< " " << e->nJourMois << " " << jourSemaine << " " << heure
						<< " " << e->minutes << " " << e->secondes
							<< " " <<  trafic << endl;
			e = e->evenementSuivant;
		}
	}
}


ListeEvenements::ListeEvenements()
{
	racine=NULL;
	evenementCourant=NULL;
}

ListeEvenements::~ListeEvenements()
{
	Evenement *e=racine;
	Evenement *evenementALiberer;
	while (e != NULL)
	{
		evenementALiberer=e;
		e=e->evenementSuivant;
		delete evenementALiberer;
	}
}

