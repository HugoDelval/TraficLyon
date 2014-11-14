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
// Cette classe ordonne les identifiants r�els de capteurs sous la forme d'un arbre. La position
// dans l'arbre de l'identifiant va devenir un nouvel identifiant pour chaque capteur. Ces
// nouveau identifiants seront tous les entiers compris entre 0 et 1499. Cela permettra de
// d�terminer la position d'un capteur dans un �ventuel tableau.
// On peut :
//		-ajouter un nouvel identifiant de capteur dans l'arbre
//		-d�terminer le nouvel identifiant du capteur gr�ce � sa potion dans l'arbre
//		-effectuer des op�rations sur l'arbres (rotations...)
//------------------------------------------------------------------------

class ArbreIdentifiants
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- M�thodes publiques
	int Insert(int idR);
	// Mode d'emploi :
	//			Insert un nouvel �lement dans l'arbre en fonction de 'idR' en param�tre.
	//			Retourne la position dans le tableau correspondante � 'idR'.
	// Contrat :
	//			Aucun

	int TrouverIdTableauCorrespondant(int idR);
	// Mode d'emploi :
	//				retourne la r�sultat de 'trouverIdTableauCorrespondantRec' avec 'idR' et 'root'
	//						en parametre.
	// Contrat :
	//			Aucun

	//----------------------------------------------------- Constructeurs - destructeur
	ArbreIdentifiants();
	// Mode d'emploi :
	//			Initialise un ArbreIdentifiants.
	//				- 'root' est initialis� � NULL
	//				- 'dernierIdTableau' est initialis� � 0
	// Contrat :
	//			Aucun

	virtual ~ArbreIdentifiants();
	// Mode d'emploi :
	//			Supprime et libere l'espace memoire correspondant a l' 'ArbreIdentifiants'
	//					(un 'ptrOnAVLTreeNode')
	// Contrat :
	//			Aucun

	//----------------------------------------------------------------- PRIVE
private:

	//------------------------------------------------------- M�thodes priv�es
	int trouverIdTableauCorrespondantRec(int idR,ptrOnAVLTreeNode &p);
	// Mode d'emploi :
	//			Recherche r�cursive de la position dans le tableau correspondant � la position dans l'arbre en
	//					Param�tre 'p'. Lorsque cette valeur de position est trouv�e, elle est retourn�e sous forme
	//					d'entier.
	//			La recherche de 'idR' dans l'arbre se fait � partir du noeud 'p'.
	//			Retourne -1 si 'p' est NULL.
	// Contrat :
	//			'p' appartient � l'ArbreIdentifiants

	void insert(int idR, int idT, ptrOnAVLTreeNode &p);
	// Mode d'emploi :
	//			Insert un noeud dans l'ArbreIdentifiants, dont les caract�ristiques sont
	//				l''idR' et l' 'idt' en param�tre. La position du noeud dans l'arbre
	//				est d�termin�e gr�ce � idR.
	//			Lors de cette insertion, il y a si besoin �quilibrage de l'arbre.
	// Contrat :
	//			-'idt' compris entre 0 et 1499
	//			-'p' appartient � l'ArbreIdentifiants


	ptrOnAVLTreeNode rotationSimpleGauche(ptrOnAVLTreeNode &p1);
	// Mode d'emploi :
	//			Passe � gauche le noeud droit du noeud en param�tre.
	//			Sert �ventuellement � �quilibrer l' ArbreIdentifiant.
	// Contrat :
	//			-'p1' appartient � l'ArbreIdentifiants

	ptrOnAVLTreeNode rotationDoubleGauche(ptrOnAVLTreeNode &p1);
	// Mode d'emploi :
	//			Retourne le noeud coorespondant � une double 'rotationDoubleGauche' avec le noeud en param�tre.
	// Contrat :
	//

	ptrOnAVLTreeNode rotationSimpleDroite(ptrOnAVLTreeNode &p1);
	// Mode d'emploi :
	//			Passe � droite le noeud gauche du noeud en param�tre.
	//			Sert �ventuellement � �quilibrer l' ArbreIdentifiant
	// Contrat :
	//			-'p1' appartient � l'ArbreIdentifiants

	ptrOnAVLTreeNode rotationDoubleDroite(ptrOnAVLTreeNode &p1);
	// Mode d'emploi :
	//			Retourne le noeud coorespondant � une double 'rotationDoubleDroite' avec le noeud en param�tre.
	// Contrat :
	//			-'p1' appartient � l'ArbreIdentifiants

	int hauteurSousArbre(ptrOnAVLTreeNode p);
	// Mode d'emploi :
	//			Retourne la hauteur sous arbre, c'est a dire le nombre de noeuds maximal
	//				pour arriver � une feuille.
	// Contrat :
	//			-'p' appartient � l'ArbreIdentifiants

	int max(int value1, int value2);
	// Mode d'emploi :
	//			Retourne la valeur la plus grande des 2 parametres
	// Contrat :
	//			Aucun

	void supprimeRecursivement(ptrOnAVLTreeNode nodeCourante);
	// Mode d'emploi :
	//			Supprime tous les elements de l'arbre de fa�on r�cursive � partir du noeud en parametre.
	// Contrat :
	//			-'nodeCourant' appartient � l'ArbreIdentifiants

	//------------------------------------------------------- Attributs priv�s
	ptrOnAVLTreeNode root;
	int dernierIdTableau;

};
#endif
