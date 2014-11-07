/*
 * Date.h
 *
 *  Created on: 7 nov. 2014
 *      Author: Hugo
 */

#ifndef DATE_H_
#define DATE_H_

class Date {
public:
	Date(int jourDeLaSemaine, int annee, int mois, int jourDuMois, int heure, int minute, int seconde);
	virtual ~Date();
private:
	int jourDeLaSemaine; // 0 -> 6
	int annee;
	int mois;            // 0 -> 12
	int jourDuMois;      // 0 -> 30
	int heure;           // 0 -> 23
	int minute;          // 0 -> 59
	int seconde;         // 0 -> 59

	int secondesDepuisDebutAnnee;
};

#endif /* DATE_H_ */
