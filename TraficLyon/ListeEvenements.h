/*
 * ListeEvenements.h
 *
 *  Created on: 28 oct. 2014
 *      Author: Papin
 */

#ifndef LISTEEVENEMENTS_H_
#define LISTEEVENEMENTS_H_

#include "Evenement.h"


class ListeEvenements {
public:
	ListeEvenements();
	virtual ~ListeEvenements();

private:
	Evenement *racine;
	Evenement *evenementCourant;

public:
	void ajouterDansLaListe(Evenement event);
};

#endif /* LISTEEVENEMENTS_H_ */
