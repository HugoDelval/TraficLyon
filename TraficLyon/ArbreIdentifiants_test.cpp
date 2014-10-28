/*
 * ArbreIdentifiants_test.cpp
 *
 *  Created on: 24 oct. 2014
 *      Author: Hugo
 */
#include <iostream>
#include "ArbreIdentifiants.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>

using namespace std;

int main()
{
	/* initialize random seed: */
	srand (time(NULL));

	cout<<"GO!"<<endl;
	ArbreIdentifiants a(0,50,50,0);
	int iterations =10;
	int idCourant=0;
	a.afficher();
	for (int i=0 ; i<iterations ; i++)
	{
		idCourant = (rand() % (500000))+1;
		a.inserer(idCourant,i);
		a.afficher();
	}

}
