/*************************************************************************
              	  	  GestionMax.cpp  -  Objet 'GestionMax'
                             -------------------
    début                : 07/11/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/


//---------- Interface de la classe <GestionMax.cpp> (fichier GestionMax.h) ------
#ifndef GESTIONMAX_H_
#define GESTIONMAX_H_

#include "Constantes.h"
#include "Date.h"

//------------------------------------------------------------------ Structure

struct ElementDate
{
	Date dateAretenir;
	ElementDate *suivant;
	ElementDate *precedent;
};
struct ElementEvenement
{
	int trafic;
	ElementDate *dateEvenement;
	ElementEvenement *suivant;
	ElementEvenement *precedent;
};

//------------------------------------------------------------------------
// Rôle de la classe <PreStockageMax>
// Gère les données nécessaires au calcul du maximum de bouchons simultanés.
//------------------------------------------------------------------------

class GestionMax {
//----------------------------------------------------------------- PUBLIC
public:

	//----------------------------------------------------- Méthodes publiques
	void Ajouter(int idTableau, int trafic, Date dateEvenement);
	// Mode d'emploi :
	//			- ajoute l’évènement [trafic, dateEvenement] à la case du tableau correspondant à idTableau.
	//			- ajoute la date à la liste des dates pointée par ‘root’ , pour pouvoir tester chaque date
	//				lorsque l’on appellera MAX_TS
	//			- au cas échéant, ajout d’une date matérialisant l’extinction d’un capteur (donc 5min après
	//				le dernier évènement de ce capteur). Ceci facilite le traitement de la commande MAX_TS

	// Contrat :
	//

	void AfficherMax();
	// Mode d'emploi :
	//				Affiche le maximum de bouchons simultanés
	// Contrat :
	//

	void AfficheListes();
	// Mode d'emploi :
	//				Affiche toutes les listes du tableau.
	// Contrat :
	//

	//----------------------------------------------------- Constructeurs - destructeur
	GestionMax();
	// Mode d'emploi :
	//		Initialise GestionMax :
	//			-toutes les cases de ‘tabListeDate’ sont initialisées à NULL
	//			-‘root’ est initialisé NULL
	//			-‘maxBouchon’ est initialisé à 0
	// Contrat :
	//

	virtual ~GestionMax();
	// Mode d'emploi :
	//			Supprime et libère l'espace mémoire correspondant à GestionMax
	// Contrat :
	//

	//----------------------------------------------------------------- PRIVE
private:
	//------------------------------------------------------- Méthodes privées
	ElementEvenement* trouverEInteressant(Date dateACalculer, int idTableau);
	// Mode d'emploi :
	//			Recherche les deux états du capteur (à 2 temps différents)  qui vont
	//				influencer le calcul du bouchon à la date donnée.
	// Contrat :
	//

	int max5minutes(int nombreSecondes);
	// Mode d'emploi :
	//			Permet de savoir combien de temps doit être ajouté à la durée d'un evenement.
	//			Retourne nombreSecondes si nombreSecondes est inférieur à 5 min.
	//			Retourne nombreSecondes si nombreSecondes est supérieur à 5 min.
	// Contrat :
	//

	void supprimerToutApres(Date dateDebutSuppression);
	// Mode d'emploi :
	//			Supprime toutes les dates du tableau après 'dateDebutSuppression'
	// Contrat :
	//

	//------------------------------------------------------- Attributs privés
	ElementEvenement ** tabListeDate; // *1500(id)
	ElementDate *root;
	float maxBouchon;
	Date dateMax;
};

#endif /* GESTIONMAX_H_ */
