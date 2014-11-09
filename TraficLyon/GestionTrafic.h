/*
 * GestionTrafic.h
 *
 *  Created on: 24 oct. 2014
 *      Author: Hugo
 */

#ifndef GESTIONTRAFIC_H
#define GESTIONTRAFIC_H

#include "Evenements.h"
#include <stdlib.h>

const int COMMANDE_ADD = 0;
const int COMMANDE_STATS_C = 1;
const int COMMANDE_STATS_D7 = 2;
const int COMMANDE_STATS_D7_H24 = 3;
const int COMMANDE_MAX_TS = 4;
const int COMMANDE_EXIT = 5;
//const int NOMBRE_MAX_CAPTEURS = 1500;

using namespace std;

class GestionTrafic {
public:
	GestionTrafic();
	virtual ~GestionTrafic();
	void start();
private:
	void appelerAjouter(string idCapteurReel,string annee, string mois, string jourDuMois, string heure, string minute, string seconde, string jourDeLaSemaine, string trafic);
	void appelerStatistiquesCapteur(string idCapteurReel);
	void appelerStatistiquesJourSemaine(string nJour);
	void appelerStatistiquesJourHeureSemaine(string nJour, string heure);
	void appelerMaxBouchonsSimultanes();
	int determineTypeCommande(const string &commande);

	Evenements *toutLeTrafic;
};

#endif /* GESTIONTRAFIC_H */
