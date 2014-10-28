/*
 * Evenements.cpp
 *
 *  Created on: 24 oct. 2014
 *      Author: Hugo
 */

#include "Evenements.h"

Evenements::Evenements() {

	//ArbreIdentifiants arbreId = new ArbreIdentifiants;
	evenements= new Evenement[1500][23][7][5];

}

Evenements::~Evenements()
{
#ifdef MAP
	cout<< "Evenements::~Evenements()" <<endl;
#endif
	delete [] evenements;

}

