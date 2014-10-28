/*
 * GestionTrafic.h
 *
 *  Created on: 24 oct. 2014
 *      Author: Hugo
 */

#ifndef GESTIONTRAFIC_H
#define GESTIONTRAFIC_H

#include "Evenements.h"

using namespace std;

class GestionTrafic {
public:
	GestionTrafic();
	virtual ~GestionTrafic();
	void start();
private:
	void appelerAjouter(int idCapteurReel,int annee, int mois, int jourDuMois, int heure, int minute, int seconde, int jouerDeLaSemaine, char trafic);
	void appelerStatistiquesCapteur(int idCapteur);
	void appelerStatistiquesJourSemaine(int nJour);
	void appelerStatistiquesJourHeureSemaine(int nJour, int heure);
	void appelerMaxBouchonsSimultanes();
};

#endif /* GESTIONTRAFIC_H */
