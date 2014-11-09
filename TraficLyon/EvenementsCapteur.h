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

const int NOMBRE_ETATS_CAPTEUR_UTILES = 4;
const int NOMBRE_ETATS_CAPTEUR_TOT = 5;
const int VERT = 1;
const int JAUNE = 2;
const int ROUGE = 3;
const int NOIR = 4;


class EvenementsCapteur
{

public:
	EvenementsCapteur(int trafic, Date date);
	EvenementsCapteur();
	virtual ~EvenementsCapteur();
	void ajouter(int trafic, Date date);
	void afficher();
	void statistiquesParCapteur();
	double* secondesPasseesDansChaqueEtat(int jour, Date dateDernierEvenementTrafic);
	double* secondesPasseesDansChaqueEtat(int jour, int heure, Date dateDernierEvenementTrafic);


private:
	int max5minutes(int nombreSecondes);

	Date dateDernierEvenement;
	int traficDernierEvenement;
	bool isEmpty;

	int ***secondesPassees; // = nombre de secondes passees dans l'etat 'trafic' le jour x de la semaine a y heure
	// 24        * 7              * 5
	// heure , jour de la semaine , trafic

};

#endif /* EVENEMENTSCAPTEUR_H_ */
