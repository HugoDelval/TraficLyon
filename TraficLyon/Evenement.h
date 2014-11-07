/*
 * Evenement.h
 *
 *  Created on: 24 oct. 2014
 *      Author: Hugo
 */

#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <stddef.h>  // permet de connaitre 'NULL'
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
	Evenement *evenementSuivant;
	Evenement *evenementPrecedent;

friend class ListeEvenements;

};

#endif /* EVENEMENT_H */
