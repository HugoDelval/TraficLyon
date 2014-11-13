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
	bool aEteModifie;
};

//------------------------------------------------------------------------
// Rôle de la classe <PreStockageMax>
//
//------------------------------------------------------------------------

class GestionMax {
//----------------------------------------------------------------- PUBLIC
public:

	//----------------------------------------------------- Méthodes publiques
	void Ajouter(int idTableau, int trafic, Date dateEvenement);
	void AfficherMax();
	void AfficheListes();

	//----------------------------------------------------- Constructeurs - destructeur
	GestionMax();
	virtual ~GestionMax();

	//----------------------------------------------------------------- PRIVE
private:
	//------------------------------------------------------- Méthodes privées
	ElementEvenement* trouverEInteressant(Date dateACalculer, int idTableau);
	int max5minutes(int nombreSecondes);
	//------------------------------------------------------- Attributs privés
	ElementEvenement ** tabListeDate; // *1500(id)
	ElementDate *root;
	float maxBouchon;
	Date dateMax;
};

#endif /* GESTIONMAX_H_ */
