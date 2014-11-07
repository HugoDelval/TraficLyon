/*
 * Date.cpp
 *
 *  Created on: 7 nov. 2014
 *      Author: Hugo
 */

#include "Date.h"

bool operator==(Date const& date1, Date const& date2)
{
	if (date1.annee == date2.annee && date1.jourDeLaSemaine==date2.jourDeLaSemaine
			&& date1.jourDuMois==date2.jourDuMois && date1.mois==date2.mois
			&& date1.heure== date2.heure && date1.minute==date2.minute && date1.seconde== date2.seconde)
	{
		return true;
	} else {
		 return false;
	}
}

bool operator!=(Date const& date1, Date const& date2)
{
	if (date1 == date2)
	{
		return false;
	} else {
		return true;
	}
}

bool operator<(Date const& date2, Date const& date1)
{
	if(date1.annee < date2.annee )
		return true;
	else if(date1.mois < date2.mois)
		return true;
	else if(date1.jourDuMois < date2.jourDuMois)
		return true;
	else if(date1.heure < date2.heure)
		return true;
	else if(date1.minute < date2.minute)
		return true;
	else if(date1.seconde < date2.seconde)
		return true;
	else
		return false;

}

bool operator<=(Date const& date1, Date const& date2)
{
	if (date1 < date2 || date1 == date2)
		return true;
	else
		return false;
}

bool operator>(Date const& date1, Date const& date2)
{
	if(date1 < date2)
		return false;
	else
		return true;
}

bool operator>=(Date const& date1, Date const& date2)
{
	if (date1 > date2 || date1 == date2)
		return true;
	else
		return false;
}

Date operator+(Date const& date1, int minutes)   // 0 <= minutes <= 60
{
	date1.minute += minutes;
	date1.secondesDepuisDebutAnnee += (minutes *60);

	if(date1.minute >= 60)
		date1.heure++;
		date1.minute -= 60;

	if(date1.heure >= 24)
		date1.jourDuMois++;
		date1.jourDeLaSemaine++;
		date1.heure =0;

	if((date1.jourDuMois > 28 && date1.mois == 2)
			|| (date1.jourDuMois > 30 && (date1.mois == 4 || date1.mois == 6 || date1.mois == 9
											|| date1.mois == 11))
			|| (date1.jourDuMois > 31 && (date1.mois == 1 || date1.mois == 3 || date1.mois == 5
											|| date1.mois == 7 || date1.mois == 8 || date1.mois == 10
											|| date1.mois==12)))
		date1.mois++;
		date1.jourDuMois=1;

	if(date1.mois  > 12)

		date1.annee++;
		date1.mois=1;
}



Date::Date()
{
	this->jourDeLaSemaine = 0;
	this->annee = 0;
	this->mois = 0;
	this->jourDuMois = 0;
	this->heure = 0;
	this->minute = 0;
	this->seconde = 0;

}

Date::Date(int jourDeLaSemaine, int annee, int mois, int jourDuMois, int heure, int minute, int seconde)
{
	this->jourDeLaSemaine = jourDeLaSemaine;
	this->annee = annee;
	this->mois = mois;
	this->jourDuMois = jourDuMois;
	this->heure = heure;
	this->minute = minute;
	this->seconde = seconde;
}

Date::~Date() {
	// TODO Auto-generated destructor stub
}
