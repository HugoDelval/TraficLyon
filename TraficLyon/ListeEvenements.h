/*
 * ListeEvenements.h
 *
 *  Created on: 28 oct. 2014
 *      Author: Papin
 */

#ifndef LISTEEVENEMENTS_H_
#define LISTEEVENEMENTS_H_

#include "Evenement.h"
#include "Evenement.h"
#include <stddef.h>  // permet de connaitre 'NULL'


class ListeEvenements {
public:
	ListeEvenements();
	virtual ~ListeEvenements();
	void ajouterDansLaListe(Evenement *event);
	void afficherListe(int idCapteur, int heure, int jourSemaine, int trafic);

private:
	Evenement *racine;
	Evenement *evenementCourant;

};

#endif /* LISTEEVENEMENTS_H_ */
