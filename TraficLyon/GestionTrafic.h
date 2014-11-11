/*************************************************************************
              GestionTrafic.cpp  -  Gere les donnes du trafic de Lyon
                             -------------------
    début                : 24/10/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/


//---------- Interface de la classe <GestionTrafic.cpp> (fichier GestionTrafic.h) ------

#ifndef GESTIONTRAFIC_H
#define GESTIONTRAFIC_H

//--------------------------------------------------- Interfaces utilisées
#include "Evenements.h"
#include "Constantes.h"
#include <stdlib.h>
using namespace std;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <GestionTrafic>
//
//------------------------------------------------------------------------

class GestionTrafic {

	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques
	GestionTrafic();
	// Mode d'emploi :
	//
	// Contrat :
	//

	//----------------------------------------------------- Constructeurs - destructeur
	virtual ~GestionTrafic();
	// Mode d'emploi :
	//
	// Contrat :
	//

	void Start();
	// Mode d'emploi :
	//
	// Contrat :
	//

	//----------------------------------------------------------------- PRIVE
private:
	//------------------------------------------------------- Méthodes privées
	void appelerAjouter(string idCapteurReel,string annee, string mois, string jourDuMois, string heure, string minute, string seconde, string jourDeLaSemaine, string trafic);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void appelerStatistiquesCapteur(string idCapteurReel);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void appelerStatistiquesJourSemaine(string nJour);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void appelerStatistiquesJourHeureSemaine(string nJour, string heure);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void appelerMaxBouchonsSimultanes();
	// Mode d'emploi :
	//
	// Contrat :
	//

	int determineTypeCommande(const string &commande);
	// Mode d'emploi :
	//
	// Contrat :
	//


	//------------------------------------------------------- Attributs privés
	Evenements *toutLeTrafic;
};

#endif /* GESTIONTRAFIC_H */
