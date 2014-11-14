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
//Gere une date sous forme d'une année, un mois, un jour du mois, un jour de la semaine,
// 		une heure, une minute, une seconde et un nombre de secondes depuis le début de l'année.
// On peut effectuer plusieurs actions sur la Date :
//			- l'afficher
//			- la comparer avec une autre date (comparaison de superiorités et inferiorités strictes)
//			- la comparer avec une autre date (comparaison d'égalité)
//			- l'additioner avec une autre date
//			- la soustraire avec une autre date
// Les possibilités de comparaisons et les opérations serviront à la surcharge d'opérateurs
//					(située à l'exterieur de la classe) : <, >, >=, <=, !=, +, -
//------------------------------------------------------------------------

class Date
{
	//----------------------------------------------------------------- PUBLIC
public:

	//----------------------------------------------------- Méthodes publiques
	bool EstEgal(Date const& dateAComparer) const;
	// Mode d'emploi :
	//			'dateAComparer' est une autre Date
	//			Permet de vérifier l'égalité de la Date avec une autre Date en parametre
	//			Retourne 'true' si la Date est égal à 'dateAComparer'
	//			Retourne 'false' si la Date est different à 'dateAComparer'
	// Contrat :
	//          aucun

	bool EstInf(Date const& dateAComparer) const;
	// Mode d'emploi :
	//			'dateAComparer' est une autre Date
	//			Permet de vérifier l'inferiorité de la Date avec une autre Date en parametre
	//			Retourne 'true' si la Date est inferieure à 'dateAComparer'
	//			Retourne 'false' si la Date est superieure à 'dateAComparer'

	// Contrat :
	//			maximum une annee de difference entre les 2 Date a comparer

	Date Additionner(int secondes);
	// Mode d'emploi :
	//			Permet d'ajouter un nombre entier de secondes à la Date
	//			Retourne la Date modifiée
	// Contrat :
	//          nombre de secondes inferieur a 2annee

	int  Difference(Date const &dateAEnlever) const;
	// Mode d'emploi :
	//			Permet de soustraire une date en paramètre à la Date
	//			Retourne la Date modifiée
	// Contrat :
	//          nombre de secondes inferieur a 2annee

	void AfficheDateRelle();
	// Mode d'emploi :
	//			Permet d'afficher l'année, le moi, le jour du mois, l'heure de la journée, la minute de l'heure
	//					et la seconde dans la minute de la date
	// Contrat :
	//          aucun


	//----------------------------------------------------- Constructeurs - destructeur
	Date(int jourDeLaSemaine, int annee, int mois, int jourDuMois, int heure, int minute, int seconde);
	// Mode d'emploi :
	//			Initialise une Date en attribuant à ses attributs les valeurs en paramète
	// Contrat :
	//            aucun

	Date(Date const &dateACopier);
	// Mode d'emploi :
	//			Initialise une Date identique à la Date entrée en paramètre
	// Contrat :
	//           aucun

	Date();
	// Mode d'emploi :
	//			Initialise une Date.
	//			Tous les attributs de la Date son initialisés à 0.
	// Contrat :
	//           aucun

	virtual ~Date();
	// Mode d'emploi :
	//			Supprime et libere l'espace memoire correspondant a la Date.
	// Contrat :
	//          aucun


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

//
bool operator==(Date const& date1, Date const& date2);
bool operator!=(Date const& date1, Date const& date2);
bool operator<(Date const& date1, Date const& date2);
bool operator<=(Date const& date1, Date const& date2);
bool operator>(Date const& date1, Date const& date2);
bool operator>=(Date const& date1, Date const& date2);
Date operator+(Date const& date1, int minutes);
Date operator-(Date const& date1, int minutes);
int operator-(Date const& date1, Date const& date2);
//  repose sur les methodes ci-dessus

#endif /* DATE_H_ */
