/*
 * ListeDatesMaxBouchons.h
 *
 *  Created on: 5 nov. 2014
 *      Author: Hugo
 */

#ifndef LISTEDATESMAXBOUCHONS_H_
#define LISTEDATESMAXBOUCHONS_H_

#include <stddef.h>  // permet de connaitre 'NULL'
#include "Date.h"

struct ElementListeDates
{
	int idCapteur;
	int trafic;
	Date dateEvenement;
	ElementListeDates *suivant;
	ElementListeDates *precedent;
};

class ListeDatesMaxBouchons {

public:
	ListeDatesMaxBouchons();
	virtual ~ListeDatesMaxBouchons();
	float ajouteCapteurEtRetourneTraficActuel(int idCapteur, int trafic, Date dateActuelle);
	void debugAffiche();

private:
	void supprimeCapteursObsoletes(Date dateActuelle, int newIdCapteur);
	void ajouteDansLaListe(ElementListeDates *newE);
	float calculeTraficActu();

	ElementListeDates *root;
};


#endif /* LISTEDATESMAXBOUCHONS_H_ */
