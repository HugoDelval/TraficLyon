/*
 * ListeDatesMaxBouchons.cpp
 *
 *  Created on: 5 nov. 2014
 *      Author: Hugo
 */

#include "ListeDatesMaxBouchons.h"


float ListeDatesMaxBouchons::ajouteCapteurEtRetourneTraficActuel(int idCapteur, int trafic,
										  int annee, int mois, int jourDuMois,
										  int heure, int minute, int seconde)
{
	ElementListeDates *newE = new ElementListeDates();
	newE->annee=annee;
	newE->idCapteur=idCapteur;
	newE->trafic=trafic;
	int secondesMois(0);
	int secondesMois30 (30*3600*24);
	int secondesMois31 (31*3600*24);
	int secondesMois28 (28*3600*24);
	switch (mois)
	{
	case 1: // fevrier
		secondesMois=secondesMois31;
		break;
	case 2: //mars
		secondesMois=secondesMois31 + secondesMois28;
		break;
	case 3: //avril
		secondesMois=secondesMois31 *2 + secondesMois28;
		break;
	case 4: //mai
		secondesMois=secondesMois31 *2 + secondesMois28 + secondesMois30;
		break;
	case 5: //juin
		secondesMois=secondesMois31 *3 + secondesMois28 + secondesMois30;
		break;
	case 6: //juillet
		secondesMois=secondesMois31 *3 + secondesMois28 + secondesMois30*2;
		break;
	case 7: //aout
		secondesMois=secondesMois31 *4 + secondesMois28 + secondesMois30 *2;
		break;
	case 8: //septembre
		secondesMois=secondesMois31 *5 + secondesMois28 + secondesMois30 *2;
		break;
	case 9: //octobre
		secondesMois=secondesMois31 *5 + secondesMois28 + secondesMois30 *3;
		break;
	case 10: //novembre
		secondesMois=secondesMois31 *6 + secondesMois28 + secondesMois30 *3;
		break;
	case 11: //decembre
		secondesMois=secondesMois31 *6 + secondesMois28 + secondesMois30 *4;
		break;
	}
	newE->secondesDansAnnee=seconde + minute*60 + heure*3600 + jourDuMois*3600*24 + secondesMois;
	if(trafic != 0) // si le capteur est actif
	{
		ajouteDansLaListe(newE);
	}
	return calculeTraficActu();
}

void ListeDatesMaxBouchons::ajouteDansLaListe(ElementListeDates *newE)
{
	supprimeCapteursObsoletes(newE->annee, newE->secondesDansAnnee, newE->idCapteur);
	if(root == NULL)
	{
		root = newE;
		root->suivant=NULL;
		root->precedent=NULL;
	}
	else
	{
		ElementListeDates *suivantRoot = root;
		root = newE;
		root->suivant = suivantRoot;
		root->precedent=NULL;
		if(root->suivant != NULL)
		{
			root->suivant->precedent = root;
		}
	}
}

void ListeDatesMaxBouchons::supprimeCapteursObsoletes(int anneeActu, int secondesDansAnneeActu, int newIdCapteur)
{
	/*
	 * suppression de tous les elements ayant une date obsolete + ceux ayant le meme id que newE
	 */
	ElementListeDates *evenementCourant=root;
	int nombreSecondesAnnee = 365 * 24 * 3600 ;
	while (evenementCourant != NULL)
	{
		if(evenementCourant->idCapteur == newIdCapteur)
		{
			//suppression
			if(evenementCourant==root)
			{
				root = evenementCourant->suivant;
				root->precedent=NULL;
				delete evenementCourant;
			}
			else
			{
				ElementListeDates *suivant =evenementCourant->suivant;
				ElementListeDates *precedent =evenementCourant->precedent;
				if(suivant != NULL)
				{
					suivant->precedent = precedent;
				}
				if(precedent != NULL)
				{
					precedent->suivant = suivant;
				}
				delete evenementCourant;
			}
		}
		else if( evenementCourant->annee+1 < anneeActu
				|| (evenementCourant->annee < anneeActu && secondesDansAnneeActu + (nombreSecondesAnnee-evenementCourant->secondesDansAnnee)>5*60 )
				|| (evenementCourant->annee == anneeActu && (secondesDansAnneeActu - evenementCourant->secondesDansAnnee) > 5*60 ) )
		{
			//suppresion de toute la liste a partir d'ici + sortie boucle
			ElementListeDates *evenementALiberer;
			while (evenementCourant != NULL)
			{
				evenementALiberer=evenementCourant;
				evenementCourant=evenementCourant->suivant;
				delete evenementALiberer;
			}
			//sortie boucle
			break;
		}
		evenementCourant=evenementCourant->suivant;
	}
}

float ListeDatesMaxBouchons::calculeTraficActu()
{
	float res(0.0);
	float nombreCapteursActifs(0.0);
	ElementListeDates *evenementCourant=root;
	while (evenementCourant != NULL)
	{
		nombreCapteursActifs++;
		if(evenementCourant->trafic==3 || evenementCourant->trafic==4) //si rouge ou noir
		{
			res++;
		}
		evenementCourant=evenementCourant->suivant;
	}

	return (res/nombreCapteursActifs)*100.0;
}

ListeDatesMaxBouchons::ListeDatesMaxBouchons()
{
	root = NULL;
}

ListeDatesMaxBouchons::~ListeDatesMaxBouchons()
{
	ElementListeDates *e=root;
	ElementListeDates *evenementALiberer;
	while (e != NULL)
	{
		evenementALiberer=e;
		e=e->suivant;
		delete evenementALiberer;
	}
}
