/*
 * Evenement.h
 *
 *  Created on: 24 oct. 2014
 *      Author: Hugo
 */

#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <iostream>
using namespace std;

class Evenement {
public:
	Evenement();
	Evenement(int anneeEvent , int moisEvent, int nJourMoisEvent, int minutesEvent, int secondesEvent);
	virtual ~Evenement();
private:
	int annee;
	int mois;
	int nJourMois;
	int minutes;
	int secondes;
};

#endif /* EVENEMENT_H */
