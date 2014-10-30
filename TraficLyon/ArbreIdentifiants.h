/*
 * ArbreIdentifiants.h
 *
 *  Created on: 24 oct. 2014
 *      Author: Hugo
 */

#ifndef ARBREIDENTIFIANTS_H
#define ARBREIDENTIFIANTS_H

struct AVLTreeNode
{
	int idReel;
	int idTableau;
	AVLTreeNode *left;
	AVLTreeNode *right;
	int height;
};
typedef struct AVLTreeNode* ptrOnAVLTreeNode;
class ArbreIdentifiants
{
public:
	ArbreIdentifiants();
	int insert(int idR);
	int trouverIdTableauCorrespondant(int idR,ptrOnAVLTreeNode &p);


	void insert(int idR, int idT, ptrOnAVLTreeNode &p);
		void supprimer(int idR,ptrOnAVLTreeNode &aSupprimer);
		int deleteMin(ptrOnAVLTreeNode &p);
		ptrOnAVLTreeNode findMin(ptrOnAVLTreeNode p);
		ptrOnAVLTreeNode findMax(ptrOnAVLTreeNode p);
		void vider(ptrOnAVLTreeNode &dest);
		void copy(ptrOnAVLTreeNode &src,ptrOnAVLTreeNode &dest);
		ptrOnAVLTreeNode nodeCopy(ptrOnAVLTreeNode &aCopier);
		void preOrder(ptrOnAVLTreeNode p); //inutile ?
		void inOrder(ptrOnAVLTreeNode p); //inutile ?
		void postOrder(ptrOnAVLTreeNode p); //inutile ?
		int hauteurSousArbre(ptrOnAVLTreeNode);
		ptrOnAVLTreeNode rotationSimpleGauche(ptrOnAVLTreeNode &p1);
		ptrOnAVLTreeNode rotationDoubleGauche(ptrOnAVLTreeNode &p1);
		ptrOnAVLTreeNode rotationSimpleDroite(ptrOnAVLTreeNode &p1);
		ptrOnAVLTreeNode rotationDoubleDroite(ptrOnAVLTreeNode &p1);
		int max(int value1, int value2);
		int nombreNodes(ptrOnAVLTreeNode p); //inutile ?

		ptrOnAVLTreeNode root;
		int dernierIdTableau;

private:

};
#endif
