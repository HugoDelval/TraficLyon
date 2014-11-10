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
	//
	// Contrat :
	//

	//----------------------------------------------------- Constructeurs - destructeur
	ArbreIdentifiants();
	// Mode d'emploi :
	//
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

	//void supprimer(int idR,ptrOnAVLTreeNode &aSupprimer);
	//int deleteMin(ptrOnAVLTreeNode &p);
	//ptrOnAVLTreeNode findMin(ptrOnAVLTreeNode p);
	//ptrOnAVLTreeNode findMax(ptrOnAVLTreeNode p);
	//void vider(ptrOnAVLTreeNode &dest);
	//void copy(ptrOnAVLTreeNode &src,ptrOnAVLTreeNode &dest);
	//ptrOnAVLTreeNode nodeCopy(ptrOnAVLTreeNode &aCopier);
	//void preOrder(ptrOnAVLTreeNode p); //inutile ?
	//void inOrder(ptrOnAVLTreeNode p); //inutile ?
	//void postOrder(ptrOnAVLTreeNode p); //inutile ?

	//------------------------------------------------------- Attributs priv�s
	int hauteurSousArbre(ptrOnAVLTreeNode);
	ptrOnAVLTreeNode rotationSimpleGauche(ptrOnAVLTreeNode &p1);
	ptrOnAVLTreeNode rotationDoubleGauche(ptrOnAVLTreeNode &p1);
	ptrOnAVLTreeNode rotationSimpleDroite(ptrOnAVLTreeNode &p1);
	ptrOnAVLTreeNode rotationDoubleDroite(ptrOnAVLTreeNode &p1);
	int max(int value1, int value2);
	//int nombreNodes(ptrOnAVLTreeNode p); //inutile ?
	ptrOnAVLTreeNode root;
	int dernierIdTableau;

};
#endif
