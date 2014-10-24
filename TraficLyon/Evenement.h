/*
 * Evenement.h
 *
 *  Created on: 24 oct. 2014
 *      Author: Hugo
 */

#ifndef EVENEMENT_H_
#define EVENEMENT_H_

class Evenement {
public:
	Evenement();
	virtual ~Evenement();
private:
	int mois;
	int nJourMois;
	int minutes;
	int secondes;
	int annee;
};

#endif /* EVENEMENT_H_ */
