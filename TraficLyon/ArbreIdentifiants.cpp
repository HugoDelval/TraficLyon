/*************************************************************************
       ArbreIdentifiants  -  implementation de l'ArbreIdentifiants decrit dans ArbreIdentifiants.h
                             -------------------
    début                : 24/10/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/

//---------- Réalisation de la classe <ArbreIdentifiants> (fichier ArbreIdentifiants.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système


//------------------------------------------------------ Include personnel
#include "ArbreIdentifiants.h"

//------------------------------------------------------------- Constantes


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

int ArbreIdentifiants::Insert(int idR)
{
	int res(-1);
	if(root==NULL)
	{
		dernierIdTableau++;
		insert(idR,dernierIdTableau,root);
		res = dernierIdTableau;
	}
	else if(trouverIdTableauCorrespondantRec(idR,root)==-1 ) //si idR n'existe pas deja
	{
		dernierIdTableau++;
		insert(idR,dernierIdTableau,root);
		res = dernierIdTableau;
	}
	else // il existe deja, on recupere idTableau
	{
		res = trouverIdTableauCorrespondantRec(idR,root);
	}
	return res;
}

int ArbreIdentifiants::TrouverIdTableauCorrespondant(int idR)
{
	return trouverIdTableauCorrespondantRec(idR,root);
}

//-------------------------------------------- Constructeurs - destructeur

ArbreIdentifiants::ArbreIdentifiants()
{
	root = NULL;
	dernierIdTableau = -1;
}

virtual ArbreIdentifiants::~ArbreIdentifiants()
{
	supprimeRecursivement(root);
}

//------------------------------------------------------------------ PRIVE

//------------------------------------------------------- Méthodes privées


// Finding an element
int ArbreIdentifiants::trouverIdTableauCorrespondantRec(int idR,ptrOnAVLTreeNode &p)
{
	if (p==NULL)
	{
		return -1;
	}
	else
	{
		if (idR < p->idReel)
		{
			return trouverIdTableauCorrespondantRec(idR,p->left);
		}
		else
		{
			if (idR>p->idReel)
			{
				return trouverIdTableauCorrespondantRec(idR,p->right);
			}
			else
			{
				return p->idTableau;
			}
		}
	}
	return -1;
}

// Inserting a node
void ArbreIdentifiants::insert(int idR, int idT,ptrOnAVLTreeNode &p)
{
	if (p == NULL)
	{
		p = new AVLTreeNode;
		p->idReel = idR;
		p->idTableau = idT;
		p->left=NULL;
		p->right = NULL;
		p->height=0;
	}
	else
	{
		if (idR<p->idReel)
		{
			insert(idR,idT,p->left);
			if ((hauteurSousArbre(p->left) - hauteurSousArbre(p->right))==2)
			{
				if (idR < p->left->idReel)
				{
					p=rotationSimpleGauche(p);
				}
				else
				{
					p =rotationDoubleGauche(p);
				}
			}
		}
		else if (idR>p->idReel)
		{
			insert(idR,idT,p->right);
			if ((hauteurSousArbre(p->right) - hauteurSousArbre(p->left))==2)
			{
				if (idR > p->right->idReel)
				{
					p = rotationSimpleDroite(p);
				}
				else
				{
					p = rotationDoubleDroite(p);
				}
			}
		}
	}
	int m,n,d;
	m=hauteurSousArbre(p->left);
	n=hauteurSousArbre(p->right);
	d=max(m,n);
	p->height = d + 1;
}

int ArbreIdentifiants::max(int value1, int value2)
{
	return ((value1 > value2) ? value1 : value2);
}

int ArbreIdentifiants::hauteurSousArbre(ptrOnAVLTreeNode p)
{
	int t;
	if (p == NULL)
	{
		return -1;
	}
	else
	{
		t = p->height;
		return t;
	}
}

ptrOnAVLTreeNode ArbreIdentifiants::rotationSimpleGauche(ptrOnAVLTreeNode &p1)
{
	ptrOnAVLTreeNode p2;
	p2 = p1->left;
	p1->left = p2->right;
	p2->right = p1;
	p1->height = max(hauteurSousArbre(p1->left),hauteurSousArbre(p1->right)) + 1;
	p2->height = max(hauteurSousArbre(p2->left),p1->height) + 1;
	return p2;
}

ptrOnAVLTreeNode ArbreIdentifiants:: rotationSimpleDroite(ptrOnAVLTreeNode &p1)
{
	ptrOnAVLTreeNode p2;
	p2 = p1->right;
	p1->right = p2->left;
	p2->left = p1;
	p1->height = max(hauteurSousArbre(p1->left),hauteurSousArbre(p1->right)) + 1;
	p2->height = max(p1->height,hauteurSousArbre(p2->right)) + 1;
	return p2;
}

ptrOnAVLTreeNode ArbreIdentifiants:: rotationDoubleGauche(ptrOnAVLTreeNode &p1)
{
	p1->left=rotationSimpleDroite(p1->left);
	return rotationSimpleGauche(p1);
}

ptrOnAVLTreeNode ArbreIdentifiants::rotationDoubleDroite(ptrOnAVLTreeNode &p1)
{
	p1->right = rotationSimpleGauche(p1->right);
	return rotationSimpleDroite(p1);
}

void ArbreIdentifiants::supprimeRecursivement(ptrOnAVLTreeNode nodeCourante)
{
	if(nodeCourante != NULL)
	{
		supprimeRecursivement(nodeCourante->left);
		supprimeRecursivement(nodeCourante->right);
		delete nodeCourante;
	}
}

