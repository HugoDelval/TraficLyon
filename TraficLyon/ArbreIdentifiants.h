/*
 * ArbreIdentifiants.h
 *
 *  Created on: 24 oct. 2014
 *      Author: Hugo
 */

#ifndef ARBREIDENTIFIANTS_H
#define ARBREIDENTIFIANTS_H

class ArbreIdentifiants {
public:
	ArbreIdentifiants();
    ArbreIdentifiants(ArbreIdentifiants g, int idReel, int idTableau, ArbreIdentifiants d);
    ArbreIdentifiants(const ArbreIdentifiants &aCopier);
	virtual ~ArbreIdentifiants();
	int getId(int idReel);

private:
	int hauteur;
    int idReel;
    int idTableau;
    ArbreIdentifiants filsG, filsD;


};

#endif /* ARBREIDENTIFIANTS_H_ */
