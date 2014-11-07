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
#include "EvenementsCapteur.h"
#include "ListeDatesMaxBouchons.h"


using namespace std;

class Evenements {
public:
	Evenements();
	virtual ~Evenements();
	void ajouterEvenement(int idCapteur, int heure, int jourSemaine, int trafic, int anneeEvent , int moisEvent, int nJourMoisEvent, int minutesEvent, int secondesEvent);
	void statistiquesCapteur(int idCapteurReel);
	void statistiquesJourSemaine(int nJour);
	void statistiquesJourHeureSemaine(int nJour, int heure);
	void maxBouchonsSimultanes();
	int ajouterIdAArbre(int idCapeurReel);
	void afficherTousLesEvenements();

private:
	ArbreIdentifiants *arbreId;
	EvenementsCapteur **capteurs;
	// tableau de pointeurs vers EvenementsCapteur : id*1500
	Date dateBouchonMax;
	Date dateDebutAcquisition;
	float bouchonMax;

	ListeDatesMaxBouchons gestionnaireMax;

};

#endif /* EVENEMENTS_H */
