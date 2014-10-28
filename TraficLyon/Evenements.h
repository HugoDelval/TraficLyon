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

using namespace std;

class Evenements {
public:
	Evenements();
	virtual ~Evenements();


private:
	ArbreIdentifiants arbreId;
	Evenement ****evenements;
	// 1500 * 23 * 7 * 5
	// id capteur , heure , jour de la semaine , trafic

public:
	void statistiquesCapteur(int idCapteur);
	void statistiquesJourSemaine(int nJour);
	void statistiquesJourHeureSemaine(int nJour, int heure);
	void maxBouchonsSimultanes();
};

#endif /* EVENEMENTS_H */
