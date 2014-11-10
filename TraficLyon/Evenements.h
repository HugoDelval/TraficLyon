/*************************************************************************
              	  	  Evenements.cpp  -  Objet 'Evenements'
                             -------------------
    d�but                : 24/10/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/


//---------- Interface de la classe <Evenements.cpp> (fichier Evenements.h) ------

#ifndef EVENEMENTS_H
#define EVENEMENTS_H

#include <iostream>
#include "ArbreIdentifiants.h"
#include "EvenementsCapteur.h"
#include "ListeDatesMaxBouchons.h"

using namespace std;

//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes

const int NOMBRE_MAX_CAPTEURS = 1500;
const int NOMBRE_ETATS_CAPTEUR = 4;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Evenements>
//
//------------------------------------------------------------------------


class Evenements {

	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques

	void AjouterEvenement(int idCapteur, int heure, int jourSemaine, int trafic, int anneeEvent , int moisEvent, int nJourMoisEvent, int minutesEvent, int secondesEvent);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void StatistiquesCapteur(int idCapteurReel);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void StatistiquesJourSemaine(int nJour);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void StatistiquesJourHeureSemaine(int nJour, int heure);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void MaxBouchonsSimultanes();
	// Mode d'emploi :
	//
	// Contrat :
	//

	int AjouterIdAArbre(int idCapeurReel);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void AfficherTousLesEvenements();
	// Mode d'emploi :
	//
	// Contrat :
	//

	//----------------------------------------------------- Constructeurs - destructeur
	Evenements();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Evenements();
	// Mode d'emploi :
	//
	// Contrat :
	//

	//----------------------------------------------------------------- PRIVE

private:
	//------------------------------------------------------- M�thodes priv�es

	//------------------------------------------------------- Attributs priv�s
	ArbreIdentifiants *arbreId;
	EvenementsCapteur **capteurs;  // tableau de pointeurs vers EvenementsCapteur : id*1500
	Date dateDernierEvenementTrafic;
	Date dateBouchonMax;
	float bouchonMax;
	ListeDatesMaxBouchons gestionnaireMax;

};

#endif /* EVENEMENTS_H */
