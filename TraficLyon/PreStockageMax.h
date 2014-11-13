/*************************************************************************
              	  	  PreStockageMax.cpp  -  Objet 'PreStockageMax'
                             -------------------
    d�but                : 07/11/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/


//---------- Interface de la classe <PreStockageMax.cpp> (fichier PreStockageMax.h) ------
#ifndef PRESTOCKAGEMAX_H_
#define PRESTOCKAGEMAX_H_
#include "Constantes.h"
#include "Date.h"

//------------------------------------------------------------------ Structure

struct ElementEvenement
{
	int trafic;
	Date dateEvenement;
	ElementEvenement *suivant;
	ElementEvenement *precedent;
};

//------------------------------------------------------------------------
// R�le de la classe <PreStockageMax>
//
//------------------------------------------------------------------------

class PreStockageMax {
//----------------------------------------------------------------- PUBLIC
public:

	//----------------------------------------------------- M�thodes publiques
	void AjouterDansTableau(int trafic, Date dateEvenement);

	//----------------------------------------------------- Constructeurs - destructeur
	PreStockageMax();
	virtual ~PreStockageMax();

	//----------------------------------------------------------------- PRIVE
private:
	//------------------------------------------------------- M�thodes priv�es

	//------------------------------------------------------- Attributs priv�s
	ElementEvenement* root;
};

#endif /* PRESTOCKAGEMAX_H_ */
