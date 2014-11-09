/*
 * Date.h
 *
 *  Created on: 7 nov. 2014
 *      Author: Hugo
 */

#ifndef DATE_H_
#define DATE_H_

#include <iostream>

using namespace std;

const int NOMBRE_JOURS_ANNEE = 365;
const int NOMBRE_JOURS_MOIS_28 = 28;
const int NOMBRE_JOURS_MOIS_30= 30;
const int NOMBRE_JOURS_MOIS_31 = 31;
const int NOMBRE_JOURS_SEMAINE = 7;
const int NOMBRE_HEURES_JOURNEE = 24;
const int NOMBRE_MINUSTES_HEURE = 60;
const int NOMBRE_SECONDES_MINUTE = 60;
const int NOMBRE_MOIS_ANNEE = 12;
const int JANVIER = 0;
const int FEVRIER =1;
const int MARS = 2;
const int AVRIL =3;
const int MAI = 4;
const int JUIN =5;
const int JUILLET = 6;
const int AOUT =7;
const int SEPTEMBRE = 8;
const int OCTOBRE =9;
const int NOVEMBRE = 10;
const int DECEMBRE =11;

class Date
{
public:
	Date(int jourDeLaSemaine, int annee, int mois, int jourDuMois, int heure, int minute, int seconde);
	Date(Date const &dateACopier);
	Date();
	virtual ~Date();
	bool estEgal(Date const& dateAComparer) const;
	bool estInf(Date const& dateAComparer) const;
	Date additionner(int secondes);
	void afficheDateRelle();
	void debugAffichage();
	int  difference(Date const &dateAEnlever) const;

private:
	int jourDeLaSemaine; // 0 -> 6
	int annee;
	int mois;            // 0 -> 12
	int jourDuMois;      // 0 -> 30
	int heure;           // 0 -> 23
	int minute;          // 0 -> 59
	int seconde;         // 0 -> 59

	int secondesDepuisDebutAnnee;

friend class EvenementsCapteur;
};

bool operator==(Date const& date1, Date const& date2); // surcharge '=='
bool operator!=(Date const& date1, Date const& date2); // surcharge '!='
bool operator<(Date const& date1, Date const& date2); //surcharge <
bool operator<=(Date const& date1, Date const& date2); // surcharge <=
bool operator>(Date const& date1, Date const& date2); // surcharge >
bool operator>=(Date const& date1, Date const& date2); // surcharge >=
Date operator+(Date const& date1, int minutes); // surcharge +
Date operator-(Date const& date1, int minutes);
int operator-(Date const& date1, Date const& date2);

#endif /* DATE_H_ */
