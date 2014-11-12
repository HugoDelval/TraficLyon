/*************************************************************************
              	  	  ArbreIdentifiants.cpp  -  Objet 'ArbreIdentifiants'
                             -------------------
    d�but                : 24/10/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/


//---------- Interface de la classe <ArbreIdentifiants.cpp> (fichier ArbreIdentifiants.h) ------

#ifndef ARBREIDENTIFIANTS_H
#define ARBREIDENTIFIANTS_H

//--------------------------------------------------- Interfaces utilis�es
using namespace std;
#include <iostream>
#include "Constantes.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------- Structures

struct AVLTreeNode
{
	int idReel;
	int idTableau;
	AVLTreeNode *left;
	AVLTreeNode *right;
	int height;
};

//------------------------------------------------------------------ Types
typedef struct AVLTreeNode* ptrOnAVLTreeNode;

//------------------------------------------------------------------------
// R�le de la classe <ArbreIdentifiants>
//
//------------------------------------------------------------------------

class ArbreIdentifiants
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- M�thodes publiques
	int Insert(int idR);
	// Mode d'emploi :
	//
	// Contrat :
	//

	int TrouverIdTableauCorrespondant(int idR);
	// Mode d'emploi :
	//				retourne la r�sultat de 'trouverIdTableauCorrespondantRec' avec 'idR' et 'root'
	//						en parametre.
	// Contrat :
	//

	//----------------------------------------------------- Constructeurs - destructeur
	ArbreIdentifiants();
	// Mode d'emploi :
	//			Initialise un ArbreIdentifiants.
	//				- 'root' est initialis� � NULL
	//				- 'dernierIdTableau' est initialis� � 0
	// Contrat :
	//

	virtual ~ArbreIdentifiants();
	// Mode d'emploi :
	//			Supprime et libere l'espace memoire correspondant a l' 'ArbreIdentifiants'
	//					(un 'ptrOnAVLTreeNode')
	// Contrat :
	//

	//----------------------------------------------------------------- PRIVE
private:

	//------------------------------------------------------- M�thodes priv�es
	int trouverIdTableauCorrespondantRec(int idR,ptrOnAVLTreeNode &p);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void insert(int idR, int idT, ptrOnAVLTreeNode &p);
	// Mode d'emploi :
	//
	// Contrat :
	//


	ptrOnAVLTreeNode rotationSimpleGauche(ptrOnAVLTreeNode &p1);
	// Mode d'emploi :
	//
	// Contrat :
	//

	ptrOnAVLTreeNode rotationDoubleGauche(ptrOnAVLTreeNode &p1);
	// Mode d'emploi :
	//
	// Contrat :
	//

	ptrOnAVLTreeNode rotationSimpleDroite(ptrOnAVLTreeNode &p1);
	// Mode d'emploi :
	//
	// Contrat :
	//

	ptrOnAVLTreeNode rotationDoubleDroite(ptrOnAVLTreeNode &p1);
	// Mode d'emploi :
	//
	// Contrat :
	//

	int hauteurSousArbre(ptrOnAVLTreeNode);
	// Mode d'emploi :
	//
	// Contrat :
	//

	int max(int value1, int value2);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void supprimeRecursivement(ptrOnAVLTreeNode nodeCourante);
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------------- Attributs priv�s
	ptrOnAVLTreeNode root;
	int dernierIdTableau;

};
#endif
