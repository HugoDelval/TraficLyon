/*
 * Evenement.h
 *
 *  Created on: 24 oct. 2014
 *      Author: Hugo
 */

#ifndef EVENEMENT_H
#define EVENEMENT_H

class Evenement {
public:
	Evenement();
	virtual ~Evenement();
private:
	int annee;
	int mois;
	int nJourMois;
	int minutes;
	int secondes;
};

#endif /* EVENEMENT_H */
