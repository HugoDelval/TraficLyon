/*************************************************************************
              	  	  EvenementsCapteur.cpp  -  Objet 'EvenementsCapteur'
                             -------------------
    d�but                : 07/11/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/


//---------- Interface de la classe <EvenementsCapteur.cpp> (fichier EvenementsCapteur.h) ------
#ifndef EVENEMENTSCAPTEUR_H_
#define EVENEMENTSCAPTEUR_H_

//--------------------------------------------------- Interfaces utilis�es
#include "Date.h"
#include <iostream>
#include "Constantes.h"

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <EvenementsCapteur>
//
//------------------------------------------------------------------------


class EvenementsCapteur
{
	//----------------------------------------------------------------- PUBLIC
public:

	//----------------------------------------------------- M�thodes publiques
	void Ajouter(int trafic, Date date);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void Afficher();
	// Mode d'emploi :
	//
	// Contrat :
	//

	void StatistiquesParCapteur();
	// Mode d'emploi :
	//
	// Contrat :
	//

	double* SecondesPasseesDansChaqueEtat(int jour, Date dateDernierEvenementTrafic);
	// Mode d'emploi :
	//
	// Contrat :
	//

	double* SecondesPasseesDansChaqueEtat(int jour, int heure, Date dateDernierEvenementTrafic);
	// Mode d'emploi :
	//
	// Contrat :
	//

	//----------------------------------------------------- Constructeurs - destructeur
	EvenementsCapteur(int trafic, Date date);
	// Mode d'emploi :
	//
	// Contrat :
	//

	EvenementsCapteur();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~EvenementsCapteur();
	// Mode d'emploi :
	//
	// Contrat :
	//

	//----------------------------------------------------------------- PRIVE

private:
	//------------------------------------------------------- M�thodes priv�es
	int max5minutes(int nombreSecondes);
	// Mode d'emploi :
	//
	// Contrat :
	//


	//------------------------------------------------------- Attributs priv�s
	Date dateDernierEvenement;
	int traficDernierEvenement;
	bool isEmpty;
	int ***secondesPassees; // = nombre de secondes passees dans l'etat 'trafic' le jour x de la semaine a y heure
	// 24        * 7              * 5
	// heure , jour de la semaine , trafic

};

#endif /* EVENEMENTSCAPTEUR_H_ */
