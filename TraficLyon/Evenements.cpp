/*
 * Evenements.cpp
 *
 *  Created on: 24 oct. 2014
 *      Author: Hugo
 */

#include <iostream>
#include "ArbreIdentifiants.h"
#include "Evenement.h"
#include "Evenements.h"

using namespace std;
/* ne pas oublier toutes ces inclusions !*/

Evenements::Evenements() {

	ArbreIdentifiants arbreId;
	evenements= new Evenement***[1500];
	for(int i=0 ; i<1500 ; i++)
	{
		evenements[i] = new Evenement**[23];
		for(int j=0 ; j<23 ; j++)
		{
			evenements[i][j] = new Evenement*[7];
			for(int k=0 ; k<7 ; k++)
			{
				evenements[i][j][k] = new Evenement[5];
			}
		}
	}
}

Evenements::~Evenements()
{
#ifdef MAP
	cout<< "Evenements::~Evenements()" <<endl;
#endif
	delete [] evenements;
// a modifier : boucles comme dans le constructeur
}

