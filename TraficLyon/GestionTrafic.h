/*************************************************************************
              GestionTrafic.cpp  -  Gere les donnes du trafic de Lyon
                             -------------------
    d�but                : 24/10/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/


//---------- Interface de la classe <GestionTrafic.cpp> (fichier GestionTrafic.h) ------

#ifndef GESTIONTRAFIC_H
#define GESTIONTRAFIC_H

//--------------------------------------------------- Interfaces utilis�es
#include "Evenements.h"
#include "Constantes.h"
#include <stdlib.h>
using namespace std;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <GestionTrafic>
//
//------------------------------------------------------------------------

class GestionTrafic {

	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- M�thodes publiques

	void Start();
	// Mode d'emploi :
	//			Identifie la commande donn�e par l'utilisateur en ligne de commande gr�ce � la m�thode
	//					'determineTypeCommande' (qui renvoie une constante int) et appelle la m�thode
	//					correspondante � la constante, soit :
	//						-'appelerAjouter' pour "COMMANDE_ADD"
	//						-'appelerStatistiquesCapteur' pour "COMMANDE_STATS_C"
	//						-'appelerStatistiquesJourSemaine' pour "COMMANDE_STATS_D7"
	//						-'appelerStatistiquesJourHeureSemaine' pour "COMMANDE_STATS_D7_H24"
	//						-'appelerMaxBouchonsSimultanes' pour "COMMANDE_MAX_TS"
	//			Si l'utilisateur entre la commande de sortie ("COMMANDE_EXIT"), il y a arret de l'application.
	// Contrat :
	//

	void Start(string commande);
	// Mode d'emploi :
	//			Identifie la chaine de caract�res donn�e en param�tre gr�ce � la m�thode
	//					'determineTypeCommande' (qui renvoie une constante int) et appelle
	//					la m�thode correspondante � la constante, soit :
	//						-'appelerAjouter' pour "COMMANDE_ADD"
	//						-'appelerStatistiquesCapteur' pour "COMMANDE_STATS_C"
	//						-'appelerStatistiquesJourSemaine' pour "COMMANDE_STATS_D7"
	//						-'appelerStatistiquesJourHeureSemaine' pour "COMMANDE_STATS_D7_H24"
	//						-'appelerMaxBouchonsSimultanes' pour "COMMANDE_MAX_TS"
	//			Si commande = "COMMANDE_EXIT"), il y a arret de l'application.
	// Contrat :
	//

	//----------------------------------------------------- Constructeurs - destructeur

	GestionTrafic();
	// Mode d'emploi :
	//			Initialise EvenementsCapteur :
	//				-constructeur par d�faut de Evenements pour initialiser 'toutLeTrafic'
	// Contrat :
	//

	virtual ~GestionTrafic();
	// Mode d'emploi :
	//			supprime et libere l'espace memoire correspondant a GestionTrafic.
	//					(un 'Evenements')
	// Contrat :
	//

	//----------------------------------------------------------------- PRIVE
private:
	//------------------------------------------------------- M�thodes priv�es
	void appelerAjouter(string idCapteurReel,string annee, string mois, string jourDuMois, string heure, string minute, string seconde, string jourDeLaSemaine, string trafic);
	// Mode d'emploi :
	//			Convertie les chaines de caract�res en param�tre en int
	//					(Cas particulier : - 1 pour "V"
	//								       - 2 pour "J"
	//									   - 3 pour "R"
	//									   - 4 pour "N"
	//			Appelle la methode 'Ajouter' pour toutLeTraffic avec en param�tre les entiers g�n�r�s.
	// Contrat :
	//

	void appelerStatistiquesCapteur(string idCapteurReel);
	// Mode d'emploi :
	//			Convertie la chaine de caract�re en parametre en 'int'
	//			Appelle la m�thode 'StatitiquesCapteur' pour 'toutLeTrafic' avec l'entier g�n�r� en param�tre.
	// Contrat :
	//

	void appelerStatistiquesJourSemaine(string nJour);
	// Mode d'emploi :
	//			Convertie la chaine de caract�re en parametre en 'int'
	//			Appelle la m�thode 'StatitiquesJourSemaine' pour 'toutLeTrafic' avec l'entier g�n�r� en param�tre.
	// Contrat :
	//

	void appelerStatistiquesJourHeureSemaine(string nJour, string heure);
	// Mode d'emploi :
	//			Convertie la chaine de caract�re en parametre en 'int'
	//			Appelle la m�thode 'StatitiquesJourHeureSemaine' pour 'toutLeTrafic' avec l'entier g�n�r� en param�tre.
	// Contrat :
	//

	void appelerMaxBouchonsSimultanes();
	// Mode d'emploi :
	//			Appelle la m�thode 'MaxBouchonsSimultanes' pour 'toutLeTrafic'
	// Contrat :
	//

	int determineTypeCommande(const string &commande);
	// Mode d'emploi :
	//			Identifie la commande donn�e par l'utilisateur en ligne de commande et renvoie
	//					la constante correspondante, soit :
	//						-'COMMANDE_ADD' pour "ADD"
	//						-'COMMANDE_STATS_C' pour "STATS_C"
	//						-'COMMANDE_STATS_D7' pour "STATS_D7"
	//						-'COMMANDE_STATS_D7_H24' pour "STATS_D7_H24"
	//						-'COMMANDE_MAX_TS' pour "MAX_TS"
	//						-'COMMANDE_EXIT' pour "EXIT"
	// Contrat :
	//


	//------------------------------------------------------- Attributs priv�s
	Evenements *toutLeTrafic;

	//------------------------------------------------------- Classes amies
friend class TestsGestionTrafic;

};

#endif /* GESTIONTRAFIC_H */
