/*************************************************************************
              	  	  ListeDatesMaxBouchons.cpp  -  Objet 'ListeDatesMaxBouchons'
                             -------------------
    début                : 05/11/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/


//---------- Interface de la classe <ListeDatesMaxBouchons.cpp> (fichier ListeDatesMaxBouchons.h) ------

#ifndef LISTEDATESMAXBOUCHONS_H_
#define LISTEDATESMAXBOUCHONS_H_

//--------------------------------------------------- Interfaces utilisées
#include "Date.h"
#include "Constantes.h"

//------------------------------------------------------------- Structures

struct ElementListeDates
{
	int idCapteur;
	int trafic;
	Date dateEvenement;
	ElementListeDates *suivant;
	ElementListeDates *precedent;
};

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ListeDatesMaxBouchons>
//
//------------------------------------------------------------------------


class ListeDatesMaxBouchons {

	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques

	float AjouteCapteurEtRetourneTraficActuel(int idCapteur, int trafic, Date dateActuelle);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void DebugAffiche();
	// Mode d'emploi :
	//
	// Contrat :
	//

	//----------------------------------------------------- Constructeurs - destructeur
	ListeDatesMaxBouchons();
	virtual ~ListeDatesMaxBouchons();

	//----------------------------------------------------------------- PRIVE

private:
	//------------------------------------------------------- Méthodes privées
	void supprimeCapteursObsoletes(Date dateActuelle, int newIdCapteur);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void ajouteDansLaListe(ElementListeDates *newE);
	// Mode d'emploi :
	//
	// Contrat :
	//

	float calculeTraficActu();
	// Mode d'emploi :
	//
	// Contrat :
	//


	//------------------------------------------------------- Attributs privés
	ElementListeDates *root;
};


#endif /* LISTEDATESMAXBOUCHONS_H_ */
