/*************************************************************************
              	  	  Evenements.cpp  -  Objet 'Evenements'
                             -------------------
    d�but                : 24/10/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/


//---------- Interface de la classe <Evenements.cpp> (fichier Evenements.h) ------

#ifndef EVENEMENTS_H
#define EVENEMENTS_H

//--------------------------------------------------- Interfaces utilis�es
#include <iostream>
#include "ArbreIdentifiants.h"
#include "EvenementsCapteur.h"
#include "GestionMax.h"
#include "Constantes.h"

using namespace std;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Evenements>
// G�re l'ensemble des 'EvenementsCapteur' en stockant les 1500 pointeurs vers les 1500
// 'EvenementsCapteur' potentiels dans un tableau. Si l'utilisateur ajoute une nouvelle
// donn�e, alors cette classe la redirigera vers l''EvenementsCapteur' associ�.
// On peut :
//		-ajouter un nouvel �tat de capteur pour un capteur donn� et une date donn�e
//		-afficher les statistiques pour un capteur donn�
//		-afficher les statistiques du trafic pour un jour de la semaine
//			pour l'ensemble des capteurs
//		-afficher les statistiques du trafic pour un jour de la semaine et
//			une heure de la journ�e pour l'ensemble des capteurs
//		-afficher le moment avec le plus de bouchons simultan�s
//		-afficher les secondes pass�es dans chaque �tat pour chaque capteur
//------------------------------------------------------------------------


class Evenements {

	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques

	void AjouterEvenement(int idCapteur, int heure, int jourSemaine, int trafic, int anneeEvent , int moisEvent, int nJourMoisEvent, int minutesEvent, int secondesEvent);
	// Mode d'emploi :
	//			Permet d'ajouter un �venement :
	//				-met � jour 'capteurs' en ajoutant (m�thode 'ajouter') l'evenement � ins�rer
	//						('idCapteur' et 'trafic' en parametres)
	//				-met � jour 'dateDernierEvenementTrafic' en remplacant cette date par la date
	//						de l'evenement � ins�rer ('anneeEvent', 'moisEvent', 'nJourMoisEvent',
	//						'jourSemaine', 'heure', 'minutesEvent', 'secondesEvent' en parametres)
	//				-recherche si la date d'ajout de l'evenement est le moment avec le plus de bouchons simultan�s.
	//						Et si besoin, 'dateBouchonMax' et 'bouchonMax' sont mis � jour.
	// Contrat :
	//

	void StatistiquesCapteur(int idCapteurReel);
	// Mode d'emploi :
	//			Appel de la m�thode 'StatistiquesParCapteur' pour l''EvenementsCapteur' se trouvant dans la case de
	//					'capteurs' pour le capteur correspondant � idCapteurReel. On trouve la position
	//					de ce capteur dans le tableau grace � sa position dans 'arbreId'.
	// Contrat :
	//

	void StatistiquesJourSemaine(int nJour);
	// Mode d'emploi :
	//			Affiche les pourcentages des temps pass�s dans chaque �tat pour un jour de la semaine
	//				'nJour' pour l'ensemble des capteurs.
	// Contrat :
	//

	void StatistiquesJourHeureSemaine(int nJour, int heure);
	// Mode d'emploi :
	//			Affiche les pourcentages des temps pass�s dans chaque �tat pour un jour de la semaine
	//				'nJour' et une heure donn�e 'heure' pour l'ensemble des capteurs.
	// Contrat :
	//

	void MaxBouchonsSimultanes();
	// Mode d'emploi :
	//			Affiche 'bouchonMax', le moment avec le plus de bouchons simultan�s;
	// Contrat :
	//

	int AjouterIdAArbre(int idCapeurReel);
	// Mode d'emploi :
	//			Insert un nouvel identifiant de capteur dans 'arbreId' et retourne la position
	//					dans l'arbre. Cette position permettra d'identifier un capteur
	//					dans 'EvenementsCapteur' parmis les 1500 colones disponibles.
	// Contrat :
	//

	void AfficherTousLesEvenements();
	// Mode d'emploi :
	//			Appel de la m�hode 'Afficher' de EvenementsCapteurs pour chaque identifiant de capteur.
	//					La m�thode affiche donc les secondes pass�es dans chaque �tat pour chaque capteur.
	// Contrat :
	//

	//----------------------------------------------------- Constructeurs - destructeur
	Evenements();
	// Mode d'emploi :
	//			Initialise EvenementsCapteur :
	//				-'ArbreIdentifiants' initialis� � un arbre vierge (constructeur par d�fault)
	//				-Toutes les cases de 'capteur'  sont initialis�es � 0
	//				-'BouchonsMax' est initialis� � 0
	// Contrat :
	//

	virtual ~Evenements();
	// Mode d'emploi :
	//			 supprime et libere l'espace memoire correspondant a l'Evenements.
	//					(un arbre, un tableau de pointeurs vers EvenementsCapteur, 2 Dates, une ListeDatesMaxBouchons)
	// Contrat :
	//

	//----------------------------------------------------------------- PRIVE

private:
	//------------------------------------------------------- M�thodes priv�es

	//------------------------------------------------------- Attributs priv�s
	ArbreIdentifiants *arbreId;
	EvenementsCapteur **capteurs;  // tableau de pointeurs vers EvenementsCapteur : id*1500
	Date dateDernierEvenementTrafic;
	GestionMax gestionnaireMax;

};

#endif /* EVENEMENTS_H */
