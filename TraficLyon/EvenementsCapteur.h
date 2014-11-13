/*************************************************************************
              	  	  EvenementsCapteur.cpp  -  Objet 'EvenementsCapteur'
                             -------------------
    début                : 07/11/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/


//---------- Interface de la classe <EvenementsCapteur.cpp> (fichier EvenementsCapteur.h) ------
#ifndef EVENEMENTSCAPTEUR_H_
#define EVENEMENTSCAPTEUR_H_

//--------------------------------------------------- Interfaces utilisées
#include "Date.h"
#include <iostream>
#include "Constantes.h"

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <EvenementsCapteur>
// Gère les evenements d'un capteur en stockant le nombre de secondes passées
// pour un jour, une heure et un état particulier. Stocke également la date
// du dernier évenement pour ce capteur et le dernier état du trafic pour ce
// capteur.
// On peut :
//		-ajouter un nouvel état du capteur a une date donnée
//		-afficher le nombre de secondes passées dans chaque état
//		-afficher les statistiques du capteur
//		-afficher les statistiques du capteur à un jour donné
//		-afficher les statistiques du capteur à un jour de la semaine donné
//			et une heure de la journée donnée
//------------------------------------------------------------------------


class EvenementsCapteur
{
	//----------------------------------------------------------------- PUBLIC
public:

	//----------------------------------------------------- Méthodes publiques
	void Ajouter(int trafic, Date date);
	// Mode d'emploi :
	//			Incrémente la durée d'un état de trafic (en paramètre 'trafic') dans 'secondesPassees'
	//					à la durée qui était déjà existante. Cette incrémentation se fait à
	//					la Date correspondante au paramètre 'date' (case heure, jour de la semaine,
	//					état du trafic).
	//			Si la durée d'incrémentation est supérieure à 5 min, alors 5 min sont ajoutées.
	//			Si la durée ajoutée est sur 2 jours ou sur 2 heures, alors l'incrémentation se fait
	//					sur 2 cases différentes de 'secondesPassees'.
	// Contrat :
	//

	void Afficher();
	// Mode d'emploi :
	//			Affiche succesivement les valeurs pointées par 'secondesPassees'.
	//						Elles correspondent au nombre de secondes passées pour chaque état,
	//						chaque jour de la semaine et chaque heure.
	// Contrat :
	//

	void StatistiquesParCapteur();
	// Mode d'emploi :
	//			Affiche le pourcentage de temps passé dans chaque état.
	// Contrat :
	//

	double* SecondesPasseesDansChaqueEtat(int jour, Date dateDernierEvenementTrafic);
	// Mode d'emploi :
	//			Permet d'obtenir le temps passé dans chaque état pour un jour de la semaine 'jour',
	//					et la date du derner evenement ajouté 'dateDernierEvenementTrafic' en paramètres.
	//			Retourne un tableau de pointeurs vers des double. Chaque case du tableau pointe vers des valeurs
	//					correspondantes au temps passé dans un état donné :
	//						-case 0 : vert
	//						-case 1 : jaune
	//						-case 2 : rouge
	//						-case 3 : noir
	//			Les temps pointés sont en secondes.
	// Contrat :
	//

	double* SecondesPasseesDansChaqueEtat(int jour, int heure, Date dateDernierEvenementTrafic);
	// Mode d'emploi :
	//			Permet d'obtenir le temps passé dans chaque état pour un jour de la semaine 'jour',
	//					pour une heure de la journée 'heure', et la date du derner evenement ajouté
	//					'dateDernierEvenementTrafic' en paramètres.
	//			Retourne un tableau de pointeurs vers des double. Chaque case du tableau pointe vers des valeurs
	//					correspondantes au temps passé dans un état donné :
	//						-case 0 : vert
	//						-case 1 : jaune
	//						-case 2 : rouge
	//						-case 3 : noir
	//			Les temps pointés sont en secondes.
	// Contrat :
	//

	//----------------------------------------------------- Constructeurs - destructeur
	EvenementsCapteur(int trafic, Date date);
	// Mode d'emploi :
	//			Initialise EvenementsCapteur :
	//				-'isEmpty' initialisé à false
	//				-'traficDernierEvenement' est initialisé à la valeur de 'trafic'
	//				-'secondesPassees' a tous ses pointeurs initialisés à 0
	//				-'dateDernierEvenement' est initialisé à 'date'
	// Contrat :
	//

	EvenementsCapteur();
	// Mode d'emploi :
	//			Initialise EvenementsCapteur :
	//				-'isEmpty' initialisé à true
	//				-'traficDernierEvenement' est initialisé à 0
	//				-'secondesPassees' a tous ses pointeurs initialisés à 0
	// Contrat :
	//

	virtual ~EvenementsCapteur();
	// Mode d'emploi :
	//		     supprime et libere l'espace memoire correspondant a l'EvenementsCapteur.
	//					(une Date et un trableau de pointeurs à 3 dimensions)
	// Contrat :
	//

	//----------------------------------------------------------------- PRIVE

private:
	//------------------------------------------------------- Méthodes privées
	int max5minutes(int nombreSecondes);
	// Mode d'emploi :
	//			Permet de savoir combien de temps doit être ajouté à la durée d'un
	//					evenement.
	//			Retourne nombreSecondes si nombreSecondes est inférieur à 5 min.
	//			Retourne nombreSecondes si nombreSecondes est supérieur à 5 min.
	// Contrat :
	//


	//------------------------------------------------------- Attributs privés
	Date dateDernierEvenement;
	int traficDernierEvenement;
	bool isEmpty;
	int ***secondesPassees; // = nombre de secondes passees dans l'etat 'trafic' le jour x de la semaine a y heure
	// 24        * 7              * 5
	// heure , jour de la semaine , trafic

};

#endif /* EVENEMENTSCAPTEUR_H_ */
