/*************************************************************************
              	  	  Date.cpp  -  Objet 'date'
                             -------------------
    début                : 07/11/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/


//---------- Interface de la classe <Date.cpp> (fichier Date.h) ------
#ifndef DATE_H_
#define DATE_H_

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include "Constantes.h"
using namespace std;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Date>
//
//------------------------------------------------------------------------

class Date
{
	//----------------------------------------------------------------- PUBLIC
public:

	//----------------------------------------------------- Méthodes publiques
	bool EstEgal(Date const& dateAComparer) const;
	// Mode d'emploi :
	//
	// Contrat :
	//

	bool EstInf(Date const& dateAComparer) const;
	// Mode d'emploi :
	//
	// Contrat :
	//

	Date Additionner(int secondes);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void AfficheDateRelle();
	// Mode d'emploi :
	//
	// Contrat :
	//

	void DebugAffichage();
	// Mode d'emploi :
	//
	// Contrat :
	//

	int  Difference(Date const &dateAEnlever) const;
	// Mode d'emploi :
	//
	// Contrat :
	//

	//----------------------------------------------------- Constructeurs - destructeur
	Date(int jourDeLaSemaine, int annee, int mois, int jourDuMois, int heure, int minute, int seconde);
	// Mode d'emploi :
	//
	// Contrat :
	//

	Date(Date const &dateACopier);
	// Mode d'emploi :
	//
	// Contrat :
	//

	Date();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Date();
	// Mode d'emploi :
	//
	// Contrat :
	//


	//----------------------------------------------------------------- PRIVE
private:

	//------------------------------------------------------- Méthodes privées

	//------------------------------------------------------- Attributs privés
	int jourDeLaSemaine; // 0 -> 6
	int annee;
	int mois;            // 0 -> 12
	int jourDuMois;      // 0 -> 30
	int heure;           // 0 -> 23
	int minute;          // 0 -> 59
	int seconde;         // 0 -> 59
	int secondesDepuisDebutAnnee;

	//------------------------------------------------------- Classes amies
friend class EvenementsCapteur;
};

//------------------------------------------------------- Redefinition d'operateurs

bool operator==(Date const& date1, Date const& date2);
bool operator!=(Date const& date1, Date const& date2);
bool operator<(Date const& date1, Date const& date2);
bool operator<=(Date const& date1, Date const& date2);
bool operator>(Date const& date1, Date const& date2);
bool operator>=(Date const& date1, Date const& date2);
Date operator+(Date const& date1, int minutes);
Date operator-(Date const& date1, int minutes);
int operator-(Date const& date1, Date const& date2);

#endif /* DATE_H_ */
