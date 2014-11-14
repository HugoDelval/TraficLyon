/*************************************************************************
              	  	  GestionMax.cpp  -  Objet 'GestionMax'
                             -------------------
    d�but                : 07/11/2014
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
// R�le de la classe <PreStockageMax>
// G�re les donn�es n�cessaires au calcul du maximum de bouchons simultan�s.
//------------------------------------------------------------------------

class GestionMax {
//----------------------------------------------------------------- PUBLIC
public:

	//----------------------------------------------------- M�thodes publiques
	void Ajouter(int idTableau, int trafic, Date dateEvenement);
	// Mode d'emploi :
	//			- ajoute l��v�nement [trafic, dateEvenement] � la case du tableau correspondant � idTableau.
	//			- ajoute la date � la liste des dates point�e par �root� , pour pouvoir tester chaque date
	//				lorsque l�on appellera MAX_TS
	//			- au cas �ch�ant, ajout d�une date mat�rialisant l�extinction d�un capteur (donc 5min apr�s
	//				le dernier �v�nement de ce capteur). Ceci facilite le traitement de la commande MAX_TS

	// Contrat :
	//

	void AfficherMax();
	// Mode d'emploi :
	//				Affiche le maximum de bouchons simultan�s
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
	//			-toutes les cases de �tabListeDate� sont initialis�es � NULL
	//			-�root� est initialis� NULL
	//			-�maxBouchon� est initialis� � 0
	// Contrat :
	//

	virtual ~GestionMax();
	// Mode d'emploi :
	//			Supprime et lib�re l'espace m�moire correspondant � GestionMax
	// Contrat :
	//

	//----------------------------------------------------------------- PRIVE
private:
	//------------------------------------------------------- M�thodes priv�es
	ElementEvenement* trouverEInteressant(Date dateACalculer, int idTableau);
	// Mode d'emploi :
	//			Recherche les deux �tats du capteur (� 2 temps diff�rents)  qui vont
	//				influencer le calcul du bouchon � la date donn�e.
	// Contrat :
	//

	int max5minutes(int nombreSecondes);
	// Mode d'emploi :
	//			Permet de savoir combien de temps doit �tre ajout� � la dur�e d'un evenement.
	//			Retourne nombreSecondes si nombreSecondes est inf�rieur � 5 min.
	//			Retourne nombreSecondes si nombreSecondes est sup�rieur � 5 min.
	// Contrat :
	//

	void supprimerToutApres(Date dateDebutSuppression);
	// Mode d'emploi :
	//			Supprime toutes les dates du tableau apr�s 'dateDebutSuppression'
	// Contrat :
	//

	//------------------------------------------------------- Attributs priv�s
	ElementEvenement ** tabListeDate; // *1500(id)
	ElementDate *root;
	float maxBouchon;
	Date dateMax;
};

#endif /* GESTIONMAX_H_ */
