/*
 * EvenementsCapteur.h
 *
 *  Created on: 7 nov. 2014
 *      Author: Hugo
 */

#ifndef EVENEMENTSCAPTEUR_H_
#define EVENEMENTSCAPTEUR_H_

#include "Date.h"
#include <iostream>

using namespace std;

class EvenementsCapteur
{

public:
	EvenementsCapteur(int trafic, Date date);
	EvenementsCapteur();
	virtual ~EvenementsCapteur();
	void ajouter(int trafic, Date date);
	void afficher();

private:
	Date dateDernierEvenement;
	int traficDernierEvenement;
	int max5minutes(int nombreSecondes);

	int ***secondesPassees; // = nombre de secondes passees dans l'etat 'trafic' le jour x de la semaine a y heure
	// 24        * 7              * 5
	// heure , jour de la semaine , trafic

};

#endif /* EVENEMENTSCAPTEUR_H_ */