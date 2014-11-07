/*
 * ListeDatesMaxBouchons.h
 *
 *  Created on: 5 nov. 2014
 *      Author: Hugo
 */

#ifndef LISTEDATESMAXBOUCHONS_H_
#define LISTEDATESMAXBOUCHONS_H_

#include <stddef.h>  // permet de connaitre 'NULL'

struct ElementListeDates
{
	int idCapteur;
	int trafic;
	int annee;
	int secondesDansAnnee;
	ElementListeDates *suivant;
	ElementListeDates *precedent;
};

class ListeDatesMaxBouchons {

public:
	ListeDatesMaxBouchons();
	virtual ~ListeDatesMaxBouchons();
	float ajouteCapteurEtRetourneTraficActuel(int idCapteur, int trafic, int annee, int mois, int jourDuMois, int heure, int minute, int seconde);

private:
	void supprimeCapteursObsoletes(int anneeActu, int secondesDansAnneeActu, int newIdCapteur);
	void ajouteDansLaListe(ElementListeDates *newE);
	float calculeTraficActu();

	ElementListeDates *root;
};


#endif /* LISTEDATESMAXBOUCHONS_H_ */
