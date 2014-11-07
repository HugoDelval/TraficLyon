/*
 * Date.cpp
 *
 *  Created on: 7 nov. 2014
 *      Author: Hugo
 */

#include "Date.h"


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
