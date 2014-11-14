/*************************************************************************
              	  	  ArbreIdentifiants.cpp  -  Objet 'ArbreIdentifiants'
                             -------------------
    début                : 24/10/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/


//---------- Interface de la classe <ArbreIdentifiants.cpp> (fichier ArbreIdentifiants.h) ------

#ifndef ARBREIDENTIFIANTS_H
#define ARBREIDENTIFIANTS_H

//--------------------------------------------------- Interfaces utilisées
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
// Rôle de la classe <ArbreIdentifiants>
// Cette classe ordonne les identifiants réels de capteurs sous la forme d'un arbre. La position
// dans l'arbre de l'identifiant va devenir un nouvel identifiant pour chaque capteur. Ces
// nouveau identifiants seront tous les entiers compris entre 0 et 1499. Cela permettra de
// déterminer la position d'un capteur dans un éventuel tableau.
// On peut :
//		-ajouter un nouvel identifiant de capteur dans l'arbre
//		-déterminer le nouvel identifiant du capteur grâce à sa potion dans l'arbre
//		-effectuer des opérations sur l'arbres (rotations...)
//------------------------------------------------------------------------

class ArbreIdentifiants
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques
	int Insert(int idR);
	// Mode d'emploi :
	//			Insert un nouvel élement dans l'arbre en fonction de 'idR' en paramètre.
	//			Retourne la position dans le tableau correspondante à 'idR'.
	// Contrat :
	//			Aucun

	int TrouverIdTableauCorrespondant(int idR);
	// Mode d'emploi :
	//				retourne la résultat de 'trouverIdTableauCorrespondantRec' avec 'idR' et 'root'
	//						en parametre.
	// Contrat :
	//			Aucun

	//----------------------------------------------------- Constructeurs - destructeur
	ArbreIdentifiants();
	// Mode d'emploi :
	//			Initialise un ArbreIdentifiants.
	//				- 'root' est initialisé à NULL
	//				- 'dernierIdTableau' est initialisé à 0
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

	//------------------------------------------------------- Méthodes privées
	int trouverIdTableauCorrespondantRec(int idR,ptrOnAVLTreeNode &p);
	// Mode d'emploi :
	//			Recherche récursive de la position dans le tableau correspondant à la position dans l'arbre en
	//					Paramètre 'p'. Lorsque cette valeur de position est trouvée, elle est retournée sous forme
	//					d'entier.
	//			La recherche de 'idR' dans l'arbre se fait à partir du noeud 'p'.
	//			Retourne -1 si 'p' est NULL.
	// Contrat :
	//			'p' appartient à l'ArbreIdentifiants

	void insert(int idR, int idT, ptrOnAVLTreeNode &p);
	// Mode d'emploi :
	//			Insert un noeud dans l'ArbreIdentifiants, dont les caractéristiques sont
	//				l''idR' et l' 'idt' en paramètre. La position du noeud dans l'arbre
	//				est déterminée grâce à idR.
	//			Lors de cette insertion, il y a si besoin équilibrage de l'arbre.
	// Contrat :
	//			-'idt' compris entre 0 et 1499
	//			-'p' appartient à l'ArbreIdentifiants


	ptrOnAVLTreeNode rotationSimpleGauche(ptrOnAVLTreeNode &p1);
	// Mode d'emploi :
	//			Passe à gauche le noeud droit du noeud en paramètre.
	//			Sert éventuellement à équilibrer l' ArbreIdentifiant.
	// Contrat :
	//			-'p1' appartient à l'ArbreIdentifiants

	ptrOnAVLTreeNode rotationDoubleGauche(ptrOnAVLTreeNode &p1);
	// Mode d'emploi :
	//			Retourne le noeud coorespondant à une double 'rotationDoubleGauche' avec le noeud en paramètre.
	// Contrat :
	//

	ptrOnAVLTreeNode rotationSimpleDroite(ptrOnAVLTreeNode &p1);
	// Mode d'emploi :
	//			Passe à droite le noeud gauche du noeud en paramètre.
	//			Sert éventuellement à équilibrer l' ArbreIdentifiant
	// Contrat :
	//			-'p1' appartient à l'ArbreIdentifiants

	ptrOnAVLTreeNode rotationDoubleDroite(ptrOnAVLTreeNode &p1);
	// Mode d'emploi :
	//			Retourne le noeud coorespondant à une double 'rotationDoubleDroite' avec le noeud en paramètre.
	// Contrat :
	//			-'p1' appartient à l'ArbreIdentifiants

	int hauteurSousArbre(ptrOnAVLTreeNode p);
	// Mode d'emploi :
	//			Retourne la hauteur sous arbre, c'est a dire le nombre de noeuds maximal
	//				pour arriver à une feuille.
	// Contrat :
	//			-'p' appartient à l'ArbreIdentifiants

	int max(int value1, int value2);
	// Mode d'emploi :
	//			Retourne la valeur la plus grande des 2 parametres
	// Contrat :
	//			Aucun

	void supprimeRecursivement(ptrOnAVLTreeNode nodeCourante);
	// Mode d'emploi :
	//			Supprime tous les elements de l'arbre de façon récursive à partir du noeud en parametre.
	// Contrat :
	//			-'nodeCourant' appartient à l'ArbreIdentifiants

	//------------------------------------------------------- Attributs privés
	ptrOnAVLTreeNode root;
	int dernierIdTableau;

};
#endif
