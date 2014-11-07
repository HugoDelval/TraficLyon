/*
 * EvenementsCapteur.h
 *
 *  Created on: 7 nov. 2014
 *      Author: Hugo
 */

#ifndef EVENEMENTSCAPTEUR_H_
#define EVENEMENTSCAPTEUR_H_

class EvenementsCapteur {
public:
	EvenementsCapteur(int heure, int jourSemaine, int trafic,
	 			  	  int anneeEvent , int moisEvent, int nJourMoisEvent,
	 			  	  int minutesEvent, int secondesEvent);
	virtual ~EvenementsCapteur();
	void ajouter(int heure, int jourSemaine, int trafic,
				 int anneeEvent , int moisEvent, int nJourMoisEvent,
				 int minutesEvent, int secondesEvent);
	void afficher();

private:
	int anneeDernierEvenement;
	int secondesAnneeDernierEvenement;
	int traficDernierEvenement;
	int heureDernierEvenement;
	int jourSemaineDernierEvenement;

	int ***secondesPassees; // = nombre de secondes passees dans l'etat 'trafic' le jour x de la semaine a y heure
	// 23        * 7              * 5
	// heure , jour de la semaine , trafic
};

#endif /* EVENEMENTSCAPTEUR_H_ */
