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
// G�re les evenements d'un capteur en stockant le nombre de secondes pass�es
// pour un jour, une heure et un �tat particulier. Stocke �galement la date
// du dernier �venement pour ce capteur et le dernier �tat du trafic pour ce
// capteur.
// On peut :
//		-ajouter un nouvel �tat du capteur a une date donn�e
//		-afficher le nombre de secondes pass�es dans chaque �tat
//		-afficher les statistiques du capteur
//		-afficher les statistiques du capteur � un jour donn�
//		-afficher les statistiques du capteur � un jour de la semaine donn�
//			et une heure de la journ�e donn�e
//------------------------------------------------------------------------


class EvenementsCapteur
{
	//----------------------------------------------------------------- PUBLIC
public:

	//----------------------------------------------------- M�thodes publiques
	void Ajouter(int trafic, Date date);
	// Mode d'emploi :
	//			Incr�mente la dur�e d'un �tat de trafic (en param�tre 'trafic') dans 'secondesPassees'
	//					� la dur�e qui �tait d�j� existante. Cette incr�mentation se fait �
	//					la Date correspondante au param�tre 'date' (case heure, jour de la semaine,
	//					�tat du trafic).
	//			Si la dur�e d'incr�mentation est sup�rieure � 5 min, alors 5 min sont ajout�es.
	//			Si la dur�e ajout�e est sur 2 jours ou sur 2 heures, alors l'incr�mentation se fait
	//					sur 2 cases diff�rentes de 'secondesPassees'.
	// Contrat :
	//

	void Afficher();
	// Mode d'emploi :
	//			Affiche succesivement les valeurs point�es par 'secondesPassees'.
	//						Elles correspondent au nombre de secondes pass�es pour chaque �tat,
	//						chaque jour de la semaine et chaque heure.
	// Contrat :
	//

	void StatistiquesParCapteur();
	// Mode d'emploi :
	//			Affiche le pourcentage de temps pass� dans chaque �tat.
	// Contrat :
	//

	double* SecondesPasseesDansChaqueEtat(int jour, Date dateDernierEvenementTrafic);
	// Mode d'emploi :
	//			Permet d'obtenir le temps pass� dans chaque �tat pour un jour de la semaine 'jour',
	//					et la date du derner evenement ajout� 'dateDernierEvenementTrafic' en param�tres.
	//			Retourne un tableau de pointeurs vers des double. Chaque case du tableau pointe vers des valeurs
	//					correspondantes au temps pass� dans un �tat donn� :
	//						-case 0 : vert
	//						-case 1 : jaune
	//						-case 2 : rouge
	//						-case 3 : noir
	//			Les temps point�s sont en secondes.
	// Contrat :
	//

	double* SecondesPasseesDansChaqueEtat(int jour, int heure, Date dateDernierEvenementTrafic);
	// Mode d'emploi :
	//			Permet d'obtenir le temps pass� dans chaque �tat pour un jour de la semaine 'jour',
	//					pour une heure de la journ�e 'heure', et la date du derner evenement ajout�
	//					'dateDernierEvenementTrafic' en param�tres.
	//			Retourne un tableau de pointeurs vers des double. Chaque case du tableau pointe vers des valeurs
	//					correspondantes au temps pass� dans un �tat donn� :
	//						-case 0 : vert
	//						-case 1 : jaune
	//						-case 2 : rouge
	//						-case 3 : noir
	//			Les temps point�s sont en secondes.
	// Contrat :
	//

	//----------------------------------------------------- Constructeurs - destructeur
	EvenementsCapteur(int trafic, Date date);
	// Mode d'emploi :
	//			Initialise EvenementsCapteur :
	//				-'isEmpty' initialis� � false
	//				-'traficDernierEvenement' est initialis� � la valeur de 'trafic'
	//				-'secondesPassees' a tous ses pointeurs initialis�s � 0
	//				-'dateDernierEvenement' est initialis� � 'date'
	// Contrat :
	//

	EvenementsCapteur();
	// Mode d'emploi :
	//			Initialise EvenementsCapteur :
	//				-'isEmpty' initialis� � true
	//				-'traficDernierEvenement' est initialis� � 0
	//				-'secondesPassees' a tous ses pointeurs initialis�s � 0
	// Contrat :
	//

	virtual ~EvenementsCapteur();
	// Mode d'emploi :
	//		     supprime et libere l'espace memoire correspondant a l'EvenementsCapteur.
	//					(une Date et un trableau de pointeurs � 3 dimensions)
	// Contrat :
	//

	//----------------------------------------------------------------- PRIVE

private:
	//------------------------------------------------------- M�thodes priv�es
	int max5minutes(int nombreSecondes);
	// Mode d'emploi :
	//			Permet de savoir combien de temps doit �tre ajout� � la dur�e d'un
	//					evenement.
	//			Retourne nombreSecondes si nombreSecondes est inf�rieur � 5 min.
	//			Retourne nombreSecondes si nombreSecondes est sup�rieur � 5 min.
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
