/*************************************************************************
              GestionTrafic.cpp  -  Gere les donnes du trafic de Lyon
                             -------------------
    début                : 24/10/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/


//---------- Interface de la classe <GestionTrafic.cpp> (fichier GestionTrafic.h) ------

#ifndef GESTIONTRAFIC_H
#define GESTIONTRAFIC_H

using namespace std;
#include "Evenements.h"
#include <stdlib.h>

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes
const int COMMANDE_ADD = 0;
const int COMMANDE_STATS_C = 1;
const int COMMANDE_STATS_D7 = 2;
const int COMMANDE_STATS_D7_H24 = 3;
const int COMMANDE_MAX_TS = 4;
const int COMMANDE_EXIT = 5;

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

	void appelerStatistiquesJourHeureSemaine(string nJour, string heure);	// Mode d'emploi :
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
