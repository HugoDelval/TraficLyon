/*
 * Evenements.h
 *
 *  Created on: 24 oct. 2014
 *      Author: Hugo
 */

#ifndef EVENEMENTS_H
#define EVENEMENTS_H

#include <iostream>
#include "ArbreIdentifiants.h"
#include "Evenement.h"
#include "ListeEvenements.h"


using namespace std;

class Evenements {
public:
	Evenements();
	virtual ~Evenements();


private:
	ArbreIdentifiants *arbreId;
	ListeEvenements *****evenements;
	// 1500 * 23 * 7 * 5 + une etoile car pointeur vers liste
	// id capteur , heure , jour de la semaine , trafic

public:
	void ajouterEvenement(int idCapteur, int heure, int jourSemaine, int trafic, int anneeEvent , int moisEvent, int nJourMoisEvent, int minutesEvent, int secondesEvent);
	void statistiquesCapteur(int idCapteur);
	void statistiquesJourSemaine(int nJour);
	void statistiquesJourHeureSemaine(int nJour, int heure);
	void maxBouchonsSimultanes();
};

#endif /* EVENEMENTS_H */
