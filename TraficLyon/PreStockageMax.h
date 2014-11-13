/*************************************************************************
              	  	  PreStockageMax.cpp  -  Objet 'PreStockageMax'
                             -------------------
    début                : 07/11/2014
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
// Rôle de la classe <PreStockageMax>
//
//------------------------------------------------------------------------

class PreStockageMax {
//----------------------------------------------------------------- PUBLIC
public:

	//----------------------------------------------------- Méthodes publiques
	void AjouterDansTableau(int trafic, Date dateEvenement);

	//----------------------------------------------------- Constructeurs - destructeur
	PreStockageMax();
	virtual ~PreStockageMax();

	//----------------------------------------------------------------- PRIVE
private:
	//------------------------------------------------------- Méthodes privées

	//------------------------------------------------------- Attributs privés
	ElementEvenement* root;
};

#endif /* PRESTOCKAGEMAX_H_ */
