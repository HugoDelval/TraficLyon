/*************************************************************************
              GestionTrafic.cpp  -  Gere les donnes du trafic de Lyon
                             -------------------
    début                : 24/10/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/


//---------- Interface de la classe <GestionTrafic.cpp> (fichier GestionTrafic.h) ------

#ifndef GESTIONTRAFIC_H
#define GESTIONTRAFIC_H

//--------------------------------------------------- Interfaces utilisées
#include "Evenements.h"
#include "Constantes.h"
#include <stdlib.h>
using namespace std;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <GestionTrafic>
// Interprète les commandes données par l'utilisateur en lignes de commndes et appelle les méthodes
//		nécessaires dans les autres classes. Cette classe pointe donc vers l' 'Evenements' representant
//		l'ensemble du trafic de Lyon.
// On peut notament :
//			-interpréter les lignes de commandes données par l'utilisateur
//			-appeler chacune des méthodes d'ajout ou de statistiques pour l''Evenement' pointé
//				(avec d'éventuels paramètres nécessaires)
//
//------------------------------------------------------------------------

class GestionTrafic {

	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques

	void Start();
	// Mode d'emploi :
	//			Identifie la commande donnée par l'utilisateur en ligne de commande grâce à la méthode
	//					'determineTypeCommande' (qui renvoie une constante int) et appelle la méthode
	//					correspondante à la constante, soit :
	//						-'appelerAjouter' pour "COMMANDE_ADD"
	//						-'appelerStatistiquesCapteur' pour "COMMANDE_STATS_C"
	//						-'appelerStatistiquesJourSemaine' pour "COMMANDE_STATS_D7"
	//						-'appelerStatistiquesJourHeureSemaine' pour "COMMANDE_STATS_D7_H24"
	//						-'appelerMaxBouchonsSimultanes' pour "COMMANDE_MAX_TS"
	//			Si l'utilisateur entre la commande de sortie ("COMMANDE_EXIT"), il y a arret de l'application.
	// Contrat :
	//			Aucun

	void Start(string commande);
	// Mode d'emploi :
	//			Identifie la chaine de caractères donnée en paramètre grâce à la méthode
	//					'determineTypeCommande' (qui renvoie une constante int) et appelle
	//					la méthode correspondante à la constante, soit :
	//						-'appelerAjouter' pour "COMMANDE_ADD"
	//						-'appelerStatistiquesCapteur' pour "COMMANDE_STATS_C"
	//						-'appelerStatistiquesJourSemaine' pour "COMMANDE_STATS_D7"
	//						-'appelerStatistiquesJourHeureSemaine' pour "COMMANDE_STATS_D7_H24"
	//						-'appelerMaxBouchonsSimultanes' pour "COMMANDE_MAX_TS"
	//			Si commande = "COMMANDE_EXIT"), il y a arret de l'application.
	// Contrat :
	//			Aucun

	//----------------------------------------------------- Constructeurs - destructeur

	GestionTrafic();
	// Mode d'emploi :
	//			Initialise EvenementsCapteur :
	//				-constructeur par défaut de Evenements pour initialiser 'toutLeTrafic'
	// Contrat :
	//			Aucun

	virtual ~GestionTrafic();
	// Mode d'emploi :
	//			supprime et libere l'espace memoire correspondant a GestionTrafic.
	//					(un 'Evenements')
	// Contrat :
	//			Aucun

	//----------------------------------------------------------------- PRIVE
private:
	//------------------------------------------------------- Méthodes privées
	void appelerAjouter(string idCapteurReel,string annee, string mois, string jourDuMois, string heure, string minute, string seconde, string jourDeLaSemaine, string trafic);
	// Mode d'emploi :
	//			Convertie les chaines de caractères en paramètre en int
	//					(Cas particulier : - 1 pour "V"
	//								       - 2 pour "J"
	//									   - 3 pour "R"
	//									   - 4 pour "N"
	//			Appelle la methode 'Ajouter' pour toutLeTraffic avec en paramètre les entiers générés.
	// Contrat :
	//			-'mois' compris entre 1 et 12
	//			-'jourDuMois' compris entre 1 et 31 dépendant du mois
	//			-'heure' comrpis enre 0 et 23
	//			-'minute' compris entre 0 et 59
	// 			-'secondes' compris entre 0 et 59
	//			-'jourDeLaSemaine' compris entre 1 et 7
	//			-'trafic' = 'v' ou 'R' ou 'J' ou 'N'

	void appelerStatistiquesCapteur(string idCapteurReel);
	// Mode d'emploi :
	//			Convertie la chaine de caractère en parametre en 'int'
	//			Appelle la méthode 'StatitiquesCapteur' pour 'toutLeTrafic' avec l'entier généré en paramètre.
	// Contrat :
	//			Aucun

	void appelerStatistiquesJourSemaine(string nJour);
	// Mode d'emploi :
	//			Convertie la chaine de caractère en parametre en 'int'
	//			Appelle la méthode 'StatitiquesJourSemaine' pour 'toutLeTrafic' avec l'entier généré en paramètre.
	// Contrat :
	//			'njour' compris entre 1 et 7

	void appelerStatistiquesJourHeureSemaine(string nJour, string heure);
	// Mode d'emploi :
	//			Convertie la chaine de caractère en parametre en 'int'
	//			Appelle la méthode 'StatitiquesJourHeureSemaine' pour 'toutLeTrafic' avec l'entier généré en paramètre.
	// Contrat :
	//			-'njour' compris entre 1 et 7
	//			-'heure' compris entre 0 et 23

	void appelerMaxBouchonsSimultanes();
	// Mode d'emploi :
	//			Appelle la méthode 'MaxBouchonsSimultanes' pour 'toutLeTrafic'
	// Contrat :
	//			Aucun

	int determineTypeCommande(const string &commande);
	// Mode d'emploi :
	//			Identifie la commande donnée par l'utilisateur en ligne de commande et renvoie
	//					la constante correspondante, soit :
	//						-'COMMANDE_ADD' pour "ADD"
	//						-'COMMANDE_STATS_C' pour "STATS_C"
	//						-'COMMANDE_STATS_D7' pour "STATS_D7"
	//						-'COMMANDE_STATS_D7_H24' pour "STATS_D7_H24"
	//						-'COMMANDE_MAX_TS' pour "MAX_TS"
	//						-'COMMANDE_EXIT' pour "EXIT"
	// Contrat :
	//			Aucun


	//------------------------------------------------------- Attributs privés
	Evenements *toutLeTrafic;

	//------------------------------------------------------- Classes amies
friend class TestsGestionTrafic;

};

#endif /* GESTIONTRAFIC_H */
