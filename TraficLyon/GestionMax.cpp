/*************************************************************************
       PreStockageMax  -  implementation de PreStockageMax decrit dans GestionMax.h
                             -------------------
    début                : 07/11/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/
//-----Réalisation de la classe <GestionMax> (fichier GestionMax.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "GestionMax.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void GestionMax::Ajouter(int idTableau, int traficEvenement, Date dateEvenement)
{
	/* insertion dans la liste de date en faisant attention aux capteurs n'ayant pas agit les 5min precedentes */
	if(root == NULL)
	{
		root->dateAretenir=dateEvenement;
		root->suivant=NULL;
		root->precedent=NULL;
	}
	else
	{
		if(tabListeDate[idTableau]->suivant != NULL)
		{
			if((dateEvenement - tabListeDate[idTableau]->suivant->dateEvenement->dateAretenir) > NOMBRE_SECONDES_MINUTE*5)
			{
				Date dateIntermediaire = tabListeDate[idTableau]->suivant->dateEvenement->dateAretenir + NOMBRE_SECONDES_MINUTE*5 +1;
				ElementDate *e;
				e=tabListeDate[idTableau]->dateEvenement;
				while (e->suivant != NULL && e->suivant->dateAretenir > dateIntermediaire)
				{
					e=e->suivant;
				}
				if(e->suivant!=NULL)
				{
					if(e->suivant->dateAretenir != dateIntermediaire)
					{
						ElementDate *suivant = e->suivant;
						ElementDate *precedent = e->suivant;
						ElementDate *elementAInserer=new ElementDate();
						elementAInserer->dateAretenir=dateIntermediaire;
						elementAInserer->suivant = suivant;
						elementAInserer->precedent=precedent;
						elementAInserer->suivant->precedent = elementAInserer;
						if(elementAInserer->precedent != NULL)
						{
							elementAInserer->suivant->precedent = elementAInserer;
						}
					}
				}
				else
				{
					ElementDate *precedent = e->suivant;
					ElementDate *elementAInserer=new ElementDate();
					elementAInserer->dateAretenir=dateIntermediaire;
					elementAInserer->suivant = NULL;
					elementAInserer->precedent=precedent;
					if(elementAInserer->precedent != NULL)
					{
						elementAInserer->suivant->precedent = elementAInserer;
					}
				}

			}
		}
		if(root->dateAretenir != dateEvenement)
		{
			ElementDate *suivantRoot2 = root;
			root->dateAretenir=dateEvenement;
			root->suivant = suivantRoot2;
			root->precedent=NULL;
			if(root->suivant != NULL)
			{
				root->suivant->precedent = root;
			}
		}
	}

	if(tabListeDate[traficEvenement] == NULL)
	{
		tabListeDate[traficEvenement]->dateEvenement=root;
		tabListeDate[traficEvenement]->trafic=traficEvenement;
		tabListeDate[traficEvenement]->suivant=NULL;
		tabListeDate[traficEvenement]->precedent=NULL;
	}
	else
	{
		ElementEvenement *suivantRoot = tabListeDate[traficEvenement];
		tabListeDate[traficEvenement]->dateEvenement=root;
		tabListeDate[traficEvenement]->trafic=traficEvenement;
		tabListeDate[traficEvenement]->suivant = suivantRoot;
		tabListeDate[traficEvenement]->precedent=NULL;
		if(tabListeDate[traficEvenement]->suivant != NULL)
		{
			tabListeDate[traficEvenement]->suivant->precedent = tabListeDate[traficEvenement];
		}
	}
}


void GestionMax::AfficherMax()
{
	ElementDate *e=root;
	ElementDate *dateAPartirDeLaquelleOnPeutSupprimer = root;

	dateMax = root->dateAretenir;
	while (e != NULL)
	{
		for(int i=0 ; i<NOMBRE_MAX_CAPTEURS ; i++)
		{

		}



		e=e->suivant;
		while(dateAPartirDeLaquelleOnPeutSupprimer != NULL && dateAPartirDeLaquelleOnPeutSupprimer->suivant != NULL && dateAPartirDeLaquelleOnPeutSupprimer->suivant->dateAretenir + (5*NOMBRE_SECONDES_MINUTE+1) >= dateMax)
		{
			dateAPartirDeLaquelleOnPeutSupprimer = dateAPartirDeLaquelleOnPeutSupprimer->suivant;
		}
	}




	dateMax.AfficheDateRelle();
	cout << (int)(maxBouchon) << "%"
		 << '\r\n';
}


//----------------------------------------------------- Constructeurs - destructeur
GestionMax::GestionMax()
{
	tabListeDate = new ElementEvenement*[NOMBRE_MAX_CAPTEURS];
	for(int i(0) ; i<NOMBRE_MAX_CAPTEURS ; i++)
	{
		tabListeDate[i]=NULL;
	}
	root = NULL;
	maxBouchon=0.0;
}

GestionMax::~GestionMax() {
	ElementEvenement *e;
	ElementEvenement *evenementALiberer;
	for(int i=0 ; i<NOMBRE_MAX_CAPTEURS ; i++)
	{
		e=tabListeDate[i];
		evenementALiberer=NULL;
		while (e != NULL)
		{
			evenementALiberer=e;
			e=e->suivant;
			delete evenementALiberer;
		}
	}

}

//------------------------------------------------------------------ PRIVE

//------------------------------------------------------- Méthodes privées

