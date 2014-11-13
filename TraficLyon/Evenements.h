/*************************************************************************
              	  	  Evenements.cpp  -  Objet 'Evenements'
                             -------------------
    début                : 24/10/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/


//---------- Interface de la classe <Evenements.cpp> (fichier Evenements.h) ------

#ifndef EVENEMENTS_H
#define EVENEMENTS_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include "ArbreIdentifiants.h"
#include "EvenementsCapteur.h"
#include "GestionMax.h"
#include "Constantes.h"

using namespace std;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Evenements>
// Gère l'ensemble des 'EvenementsCapteur' en stockant les 1500 pointeurs vers les 1500
// 'EvenementsCapteur' potentiels dans un tableau. Si l'utilisateur ajoute une nouvelle
// donnée, alors cette classe la redirigera vers l''EvenementsCapteur' associé.
// On peut :
//		-ajouter un nouvel état de capteur pour un capteur donné et une date donnée
//		-afficher les statistiques pour un capteur donné
//		-afficher les statistiques du trafic pour un jour de la semaine
//			pour l'ensemble des capteurs
//		-afficher les statistiques du trafic pour un jour de la semaine et
//			une heure de la journée pour l'ensemble des capteurs
//		-afficher le moment avec le plus de bouchons simultanés
//		-afficher les secondes passées dans chaque état pour chaque capteur
//------------------------------------------------------------------------


class Evenements {

	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques

	void AjouterEvenement(int idCapteur, int heure, int jourSemaine, int trafic, int anneeEvent , int moisEvent, int nJourMoisEvent, int minutesEvent, int secondesEvent);
	// Mode d'emploi :
	//			Permet d'ajouter un évenement :
	//				-met à jour 'capteurs' en ajoutant (méthode 'ajouter') l'evenement à insérer
	//						('idCapteur' et 'trafic' en parametres)
	//				-met à jour 'dateDernierEvenementTrafic' en remplacant cette date par la date
	//						de l'evenement à insérer ('anneeEvent', 'moisEvent', 'nJourMoisEvent',
	//						'jourSemaine', 'heure', 'minutesEvent', 'secondesEvent' en parametres)
	//				-recherche si la date d'ajout de l'evenement est le moment avec le plus de bouchons simultanés.
	//						Et si besoin, 'dateBouchonMax' et 'bouchonMax' sont mis à jour.
	// Contrat :
	//

	void StatistiquesCapteur(int idCapteurReel);
	// Mode d'emploi :
	//			Appel de la méthode 'StatistiquesParCapteur' pour l''EvenementsCapteur' se trouvant dans la case de
	//					'capteurs' pour le capteur correspondant à idCapteurReel. On trouve la position
	//					de ce capteur dans le tableau grace à sa position dans 'arbreId'.
	// Contrat :
	//

	void StatistiquesJourSemaine(int nJour);
	// Mode d'emploi :
	//			Affiche les pourcentages des temps passés dans chaque état pour un jour de la semaine
	//				'nJour' pour l'ensemble des capteurs.
	// Contrat :
	//

	void StatistiquesJourHeureSemaine(int nJour, int heure);
	// Mode d'emploi :
	//			Affiche les pourcentages des temps passés dans chaque état pour un jour de la semaine
	//				'nJour' et une heure donnée 'heure' pour l'ensemble des capteurs.
	// Contrat :
	//

	void MaxBouchonsSimultanes();
	// Mode d'emploi :
	//			Affiche 'bouchonMax', le moment avec le plus de bouchons simultanés;
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
	//			Appel de la méhode 'Afficher' de EvenementsCapteurs pour chaque identifiant de capteur.
	//					La méthode affiche donc les secondes passées dans chaque état pour chaque capteur.
	// Contrat :
	//

	//----------------------------------------------------- Constructeurs - destructeur
	Evenements();
	// Mode d'emploi :
	//			Initialise EvenementsCapteur :
	//				-'ArbreIdentifiants' initialisé à un arbre vierge (constructeur par défault)
	//				-Toutes les cases de 'capteur'  sont initialisées à 0
	//				-'BouchonsMax' est initialisé à 0
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
	//------------------------------------------------------- Méthodes privées

	//------------------------------------------------------- Attributs privés
	ArbreIdentifiants *arbreId;
	EvenementsCapteur **capteurs;  // tableau de pointeurs vers EvenementsCapteur : id*1500
	Date dateDernierEvenementTrafic;
	GestionMax gestionnaireMax;

};

#endif /* EVENEMENTS_H */
