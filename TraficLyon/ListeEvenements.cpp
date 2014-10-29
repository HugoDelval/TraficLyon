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

void ListeEvenements::afficherListe(int idCapteur, int heure, int jourSemaine, int trafic)
{
	if(evenementCourant==NULL)
	{
		//cout << "Liste vide" << endl;
		// bloc vide : ne rien faire
	} else {
		evenementCourant=racine;
		while (evenementCourant != NULL)
		{
			cout << idCapteur << " " << evenementCourant->annee << " " << evenementCourant->mois
					<< " " << evenementCourant->nJourMois << " " << jourSemaine << " " << heure
						<< " " << evenementCourant->minutes << " " << evenementCourant->secondes
							<< " " <<  trafic << endl;
			evenementCourant = evenementCourant->evenementSuivant;
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
	evenementCourant=racine;
	Evenement *evenementALiberer;
	while (evenementCourant != NULL)
	{
		evenementALiberer=evenementCourant;
		evenementCourant=evenementCourant->evenementSuivant;
		delete evenementALiberer;
	}
}

