/*************************************************************************
              	  	  Date.cpp  -  Objet 'date'
                             -------------------
    début                : 07/11/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/


//---------- Interface de la classe <Date.cpp> (fichier Date.h) ------
#ifndef DATE_H_
#define DATE_H_

#include <iostream>

using namespace std;


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

const int NOMBRE_JOURS_ANNEE = 365;
const int NOMBRE_JOURS_MOIS_28 = 28;
const int NOMBRE_JOURS_MOIS_30= 30;
const int NOMBRE_JOURS_MOIS_31 = 31;
const int NOMBRE_JOURS_SEMAINE = 7;
const int NOMBRE_HEURES_JOURNEE = 24;
const int NOMBRE_MINUSTES_HEURE = 60;
const int NOMBRE_SECONDES_MINUTE = 60;
const int NOMBRE_MOIS_ANNEE = 12;
const int JANVIER = 0;
const int FEVRIER =1;
const int MARS = 2;
const int AVRIL =3;
const int MAI = 4;
const int JUIN =5;
const int JUILLET = 6;
const int AOUT =7;
const int SEPTEMBRE = 8;
const int OCTOBRE =9;
const int NOVEMBRE = 10;
const int DECEMBRE =11;

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
