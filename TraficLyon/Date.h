/*************************************************************************
              	  	  Date.cpp  -  Objet 'date'
                             -------------------
    d�but                : 07/11/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/


//---------- Interface de la classe <Date.cpp> (fichier Date.h) ------
#ifndef DATE_H_
#define DATE_H_

//--------------------------------------------------- Interfaces utilis�es
#include <iostream>
#include "Constantes.h"
using namespace std;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Date>
//Gere une date sous forme d'une ann�e, un mois, un jour du mois, un jour de la semaine,
// 		une heure, une minute, une seconde et un nombre de secondes depuis le d�but de l'ann�e.
// On peut effectuer plusieurs actions sur la Date :
//			- l'afficher
//			- la comparer avec une autre date (comparaison de superiorit�s et inferiorit�s strictes)
//			- la comparer avec une autre date (comparaison d'�galit�)
//			- l'additioner avec une autre date
//			- la soustraire avec une autre date
// Les possibilit�s de comparaisons et les op�rations serviront � la surcharge d'op�rateurs
//					(situ�e � l'exterieur de la classe) : <, >, >=, <=, !=, +, -
//------------------------------------------------------------------------

class Date
{
	//----------------------------------------------------------------- PUBLIC
public:

	//----------------------------------------------------- M�thodes publiques
	bool EstEgal(Date const& dateAComparer) const;
	// Mode d'emploi :
	//			'dateAComparer' est une autre Date
	//			Permet de v�rifier l'�galit� de la Date avec une autre Date en parametre
	//			Retourne 'true' si la Date est �gal � 'dateAComparer'
	//			Retourne 'false' si la Date est different � 'dateAComparer'
	// Contrat :
	//          aucun

	bool EstInf(Date const& dateAComparer) const;
	// Mode d'emploi :
	//			'dateAComparer' est une autre Date
	//			Permet de v�rifier l'inferiorit� de la Date avec une autre Date en parametre
	//			Retourne 'true' si la Date est inferieure � 'dateAComparer'
	//			Retourne 'false' si la Date est superieure � 'dateAComparer'

	// Contrat :
	//			maximum une annee de difference entre les 2 Date a comparer

	Date Additionner(int secondes);
	// Mode d'emploi :
	//			Permet d'ajouter un nombre entier de secondes � la Date
	//			Retourne la Date modifi�e
	// Contrat :
	//          nombre de secondes inferieur a 2annee

	int  Difference(Date const &dateAEnlever) const;
	// Mode d'emploi :
	//			Permet de soustraire une date en param�tre � la Date
	//			Retourne la Date modifi�e
	// Contrat :
	//          nombre de secondes inferieur a 2annee

	void AfficheDateRelle();
	// Mode d'emploi :
	//			Permet d'afficher l'ann�e, le moi, le jour du mois, l'heure de la journ�e, la minute de l'heure
	//					et la seconde dans la minute de la date
	// Contrat :
	//          aucun


	//----------------------------------------------------- Constructeurs - destructeur
	Date(int jourDeLaSemaine, int annee, int mois, int jourDuMois, int heure, int minute, int seconde);
	// Mode d'emploi :
	//			Initialise une Date en attribuant � ses attributs les valeurs en param�te
	// Contrat :
	//            aucun

	Date(Date const &dateACopier);
	// Mode d'emploi :
	//			Initialise une Date identique � la Date entr�e en param�tre
	// Contrat :
	//           aucun

	Date();
	// Mode d'emploi :
	//			Initialise une Date.
	//			Tous les attributs de la Date son initialis�s � 0.
	// Contrat :
	//           aucun

	virtual ~Date();
	// Mode d'emploi :
	//			Supprime et libere l'espace memoire correspondant a la Date.
	// Contrat :
	//          aucun


	//----------------------------------------------------------------- PRIVE
private:

	//------------------------------------------------------- M�thodes priv�es

	//------------------------------------------------------- Attributs priv�s
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
