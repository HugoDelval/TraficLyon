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
//
//------------------------------------------------------------------------

class GestionMax {
//----------------------------------------------------------------- PUBLIC
public:

	//----------------------------------------------------- M�thodes publiques
	void Ajouter(int idTableau, int trafic, Date dateEvenement);
	void AfficherMax();

	//----------------------------------------------------- Constructeurs - destructeur
	GestionMax();
	virtual ~GestionMax();

	//----------------------------------------------------------------- PRIVE
private:
	//------------------------------------------------------- M�thodes priv�es

	//------------------------------------------------------- Attributs priv�s
	ElementEvenement ** tabListeDate; // *1500(id)
	ElementDate *root;
	float maxBouchon;
	Date dateMax;
};

#endif /* GESTIONMAX_H_ */
