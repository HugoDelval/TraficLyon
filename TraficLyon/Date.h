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

class Date
{
public:
	Date(int jourDeLaSemaine, int annee, int mois, int jourDuMois, int heure, int minute, int seconde);
	Date(const Date &dateACopier);
	Date();
	virtual ~Date();
	bool estEgal(Date const& dateAComparer);
	bool estInf(Date const& dateAComparer);
	Date additionner(int secondes);
	void afficheDate();

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


#endif /* DATE_H_ */
