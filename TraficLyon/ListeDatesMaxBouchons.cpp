/*
 * ListeDatesMaxBouchons.cpp
 *
 *  Created on: 5 nov. 2014
 *      Author: Hugo
 */

#include "ListeDatesMaxBouchons.h"


float ListeDatesMaxBouchons::ajouteCapteurEtRetourneTraficActuel(int idCapteur, int trafic, Date dateActuelle)
{
	if(trafic != 0) // si le capteur est actif
	{
		ElementListeDates *newE = new ElementListeDates();
		newE->idCapteur=idCapteur;
		newE->trafic=trafic;
		newE->dateEvenement=dateActuelle;
		ajouteDansLaListe(newE);
	}
	return calculeTraficActu();
}

void ListeDatesMaxBouchons::ajouteDansLaListe(ElementListeDates *newE)
{
	supprimeCapteursObsoletes(newE->dateEvenement, newE->idCapteur);
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

void ListeDatesMaxBouchons::debugAffiche()
{
	ElementListeDates *evenementCourant = root;
	while (evenementCourant != NULL)
	{
		cout<<"id:"<<evenementCourant->idCapteur<<" trafic:"<<evenementCourant->trafic<<" ";
		evenementCourant->dateEvenement.debugAffichage();
		evenementCourant=evenementCourant->suivant;
	}
}

void ListeDatesMaxBouchons::supprimeCapteursObsoletes(Date dateActuelle, int newIdCapteur)
{
	/*
	 * suppression de tous les elements ayant une date obsolete + ceux ayant le meme id que newE
	 */
	ElementListeDates *evenementCourant=root;

	while(evenementCourant != NULL)
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
		else if( evenementCourant->dateEvenement + (5*60) < dateActuelle )
		{

			//action : suppresion de toute la liste a partir d'ici + sortie boucle
			if(evenementCourant->precedent != NULL)
			{
				evenementCourant->precedent->suivant=NULL;
			}
			if(evenementCourant==root) //on doit supprimer toute la liste
			{
				root=NULL;
			}
			ElementListeDates *evenementALiberer;
			while (evenementCourant != NULL)
			{
				/*debugAffiche();
				cout<<endl;*/
				evenementALiberer=evenementCourant;
				evenementCourant=evenementCourant->suivant;
				delete evenementALiberer;
				/*debugAffiche();
				cout<<endl;*/
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
