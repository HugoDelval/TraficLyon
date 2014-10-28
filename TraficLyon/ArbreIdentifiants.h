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
    ArbreIdentifiants(ArbreIdentifiants *g, int idReel, int idTableau, ArbreIdentifiants *d);
	ArbreIdentifiants();
    ArbreIdentifiants(const ArbreIdentifiants &aCopier);
	virtual ~ArbreIdentifiants();
	int getId(int idReel);
	ArbreIdentifiants* inserer(int idR, int idT);
	ArbreIdentifiants* supprimer(int idR, ArbreIdentifiants &a);
	void afficher();

private:

    int determineHauteur();
    ArbreIdentifiants* supprimerRacine();
    ArbreIdentifiants* dernierDescendant();
    int max(int a, int b);
    void calculerHauteur();
    ArbreIdentifiants* equilibrer();
    ArbreIdentifiants* rotationG();
    ArbreIdentifiants* rotationD();
	int trouverIdTableau(int idReel);
	bool isEmpty();

    ArbreIdentifiants *filsD;
    ArbreIdentifiants *filsG;
	int hauteur;
    int idReel;
    int idTableau;

};

#endif /* ARBREIDENTIFIANTS_H */
