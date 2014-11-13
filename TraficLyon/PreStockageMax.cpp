/*************************************************************************
       PreStockageMax  -  implementation de PreStockageMax decrit dans PreStockageMax.h
                             -------------------
    d�but                : 07/11/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/
//-----R�alisation de la classe <PreStockageMax> (fichier PreStockageMax.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

//------------------------------------------------------ Include personnel
#include "PreStockageMax.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
void PreStockageMax::AjouterDansTableau(int traficEvenement, Date dateEvenement)
{
	if(root == NULL)
		{
			root->dateEvenement=dateEvenement;
			root->trafic=traficEvenement;
			root->suivant=NULL;
			root->precedent=NULL;
		}
		else
		{
			ElementListeDates *suivantRoot = root;
			root->dateEvenement=dateEvenement;
			root->trafic=traficEvenement;
			root->suivant = suivantRoot;
			root->precedent=NULL;
			if(root->suivant != NULL)
			{
				root->suivant->precedent = root;
			}
		}
}



//----------------------------------------------------- Constructeurs - destructeur
PreStockageMax::PreStockageMax()
{
root=NULL;
}

PreStockageMax::~PreStockageMax() {
	ElementEvenement *e=root;
	ElementEvenement *evenementALiberer;
	while (e != NULL)
	{
		evenementALiberer=e;
		e=e->suivant;
		delete evenementALiberer;
}

//------------------------------------------------------------------ PRIVE

//------------------------------------------------------- M�thodes priv�es

