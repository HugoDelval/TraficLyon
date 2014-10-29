#include <iostream>
#include <stdlib.h>
#include "ArbreIdentifiants.h"

using namespace std;


ArbreIdentifiants::ArbreIdentifiants()
{
	root = NULL;
}

int ArbreIdentifiants::insert(int idR)
{
	int idTableau=-1;
	if(root==NULL)
	{
		idTableau=0;
		insert(idR,idTableau,root);
	}
	else if(trouverIdTableauCorrespondant(idR,root)==-1 ) //si idR n'existe pas deja
	{
		idTableau=findMax(root)+1;
		insert(idR,idTableau,root);
	}
	else // il existe deja, on recupere idTableau
	{
		idTableau = trouverIdTableauCorrespondant(idR,root);
	}
	return idTableau;
}

// Finding an element
int ArbreIdentifiants::trouverIdTableauCorrespondant(int idR,ptrOnAVLTreeNode &p)
{
	if (p==NULL)
	{
		return -1;
	}
	else
	{
		if (idR < p->idReel)
		{
			trouverIdTableauCorrespondant(idR,p->left);
		}
		else
		{
			if (idR>p->idReel)
			{
				trouverIdTableauCorrespondant(idR,p->right);
			}
			else
			{
				return p->idTableau;
			}
		}
	}
	return -1;
}

// Finding the Smallest
ptrOnAVLTreeNode ArbreIdentifiants::findMin(ptrOnAVLTreeNode p)
{
	if (p==NULL)
	{
		cout<<"The tree is empty\n"<<endl;
		return p;
	}
	else
	{
		while(p->left !=NULL)
		{
			p=p->left;
			//return p;
		}
		return p;
	}
}

// Finding the Largest node
ptrOnAVLTreeNode ArbreIdentifiants::findMax(ptrOnAVLTreeNode p)
{
	if (p==NULL)
	{
		cout<<"The tree is empty\n"<<endl;
		return p;
	}
	else
	{
		while(p->right !=NULL)
		{
			p=p->right;
			//return p;
		}
		return p;
	}
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
		if (p==NULL)
		{
			cout<<"Out of Space\n"<<endl;
		}
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
		else
		{
			cout<<"Element Exists\n"<<endl;
		}
	}
	int m,n,d;
	m=hauteurSousArbre(p->left);
	n=hauteurSousArbre(p->right);
	d=max(m,n);
	p->height = d + 1;
}

// Copy a tree
void ArbreIdentifiants::copy(ptrOnAVLTreeNode &src,ptrOnAVLTreeNode &dest)
{
	vider(dest);
	dest = nodeCopy(src);
}
// Make a tree empty
void ArbreIdentifiants::vider(ptrOnAVLTreeNode &dest)
{
	ptrOnAVLTreeNode d;
	if (dest != NULL)
	{
		vider(dest->left);
		vider(dest->right);
		d=dest;
		free(d);
		dest=NULL;
	}
}
// Copy the nodes
ptrOnAVLTreeNode ArbreIdentifiants::nodeCopy(ptrOnAVLTreeNode &aCopier)
{
	ptrOnAVLTreeNode temp;
	if (aCopier==NULL)
	{
		return aCopier;
	}
	else
	{
		temp = new AVLTreeNode;
		temp->idReel = aCopier->idReel;
		temp->idTableau = aCopier->idTableau;
		temp->left = nodeCopy(aCopier->left);
		temp->right = nodeCopy(aCopier->right);
		return temp;
	}
}

// Deleting a node
void ArbreIdentifiants::supprimer(int idR,ptrOnAVLTreeNode &aSupprimer)
{
	ptrOnAVLTreeNode d;
	if (aSupprimer==NULL)
	{
		return;
	}
	else if ( idR < aSupprimer->idReel)
	{
		supprimer(idR,aSupprimer->left);
	}
	else if (idR > aSupprimer->idReel)
	{
		supprimer(idR,aSupprimer->right);
	}
	else if ((aSupprimer->left == NULL) && (aSupprimer->right == NULL))
	{
		d=aSupprimer;
		free(d);
		aSupprimer=NULL;
	}
	else if (aSupprimer->left == NULL)
	{
		d=aSupprimer;
		free(d);
		aSupprimer=aSupprimer->right;
	}
	else if (aSupprimer->right == NULL)
	{
		d=aSupprimer;
		aSupprimer=aSupprimer->left;
		free(d);
	}
	else
	{
		aSupprimer->idReel = deleteMin(aSupprimer->right);
	}
}

int ArbreIdentifiants::deleteMin(ptrOnAVLTreeNode &p)
{
	int c;
	if (p->left == NULL)
	{
		c=p->idReel;
		p=p->right;
		return c;
	}
	else
	{
		c=deleteMin(p->left);
		return c;
	}
}
void ArbreIdentifiants::preOrder(ptrOnAVLTreeNode p)
{
	if (p!=NULL)
	{
		cout<<p->idReel<<"\t";
		preOrder(p->left);
		preOrder(p->right);
	}
}

// Inorder Printing
void ArbreIdentifiants::inOrder(ptrOnAVLTreeNode p)
{
	if (p!=NULL)
	{
		inOrder(p->left);
		cout<<p->idReel<<"\t";
		inOrder(p->right);
	}
}

// PostOrder Printing
void ArbreIdentifiants::postOrder(ptrOnAVLTreeNode p)
{
	if (p!=NULL)
	{
		postOrder(p->left);
		postOrder(p->right);
		cout<<p->idReel<<"\t";
	}
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

int ArbreIdentifiants::nombreNodes(ptrOnAVLTreeNode p)
{
	int count=0;
	if (p!=NULL)
	{
		nombreNodes(p->left);
		nombreNodes(p->right);
		count++;
	}
	return count;
}
/*
int main()
{
	ptrOnAVLTreeNode root,root1,min,max;//,flag;
	int idR,idT,choice,findele,delele;
	char ch='y';
	ArbreIdentifiants bst;

	//system("clear");
	root = NULL;
	root1=NULL;
	cout<<"\n\t\t\t\tWELCOME TO AVL TREE"<<endl;
	cout<<"\t\t\t\t:::::::::::::::::::\n"<<endl;

	for(int i=0 ; i<1500 ; i++)
	{
		bst.insert(i,i,root);
	}

	do
	{
		cout<<"\t\t::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
		cout<<"\t\t::::Enter 1 to insert a new node::::::::::::::::"<<endl;
		cout<<"\t\t::::Enter 4 to search a value:::::::::::::::::::"<<endl;
		cout<<"\t\t::::Enter 5 to delete a value:::::::::::::::::::"<<endl;
		cout<<"\t\t::::Enter 6 to display Preorder:::::::::::::::::"<<endl;
		cout<<"\t\t::::Enter 7 to display Inorder::::::::::::::::::"<<endl;
		cout<<"\t\t::::Enter 8 to display Postorder::::::::::::::::"<<endl;
		cout<<"\t\t::::Enter 9 to display the height of the tree:::"<<endl;
		cout<<"\t\t::::Enter 0 to exit:::::::::::::::::::::::::::::"<<endl;
		cout<<"\t\t::::::::::::::::::::::::::::::::::::::::::::::::\n"<<endl;

		cout<<"\nEnter the choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				cout<<"\n\t\tADDING NEW NODE"<<endl;
				cout<<"\t\t:::::::::::::\n"<<endl;
				cout<<"Enter a new idTab value: ";
				cin>>idT;
				cout<<"Enter a new idR value: ";
				cin>>idR;
				bst.insert(idR,idT,root);
				cout<<"\nThe new value have been added to your tree successfully\n"<<endl;
				break;
			case 4:
				cout<<"\nEnter idR to search: ";
				cin>>findele;
				if (root != NULL)
				{
					bst.trouverIdTableauCorrespondant(findele,root);
				}
				break;
			case 5:
				cout<<"\nEnter node to delete: ";
				cin>>delele;
				bst.supprimer(delele,root);
				bst.inOrder(root);
				cout<<endl;
				break;
			case 6:
				cout<<"\n\t\tPRE-ORDER TRAVERSAL"<<endl;
				bst.preOrder(root);
				cout<<endl;
				break;
			case 7:
				cout<<"\n\t\tIN-ORDER TRAVERSAL"<<endl;
				bst.inOrder(root);
				cout<<endl;
				break;
			case 8:
				cout<<"\n\t\tPOST ORDER TRAVERSAL"<<endl;
				bst.postOrder(root);
				cout<<endl;
				break;
			case 9:
				cout<<"\n\t\tHEIGHT\n"<<endl;
				cout<<"The height of the tree is: "<<bst.hauteurSousArbre(root)<<endl;

				break;
			case 0:
				cout<<"\n\tThank your for using AVL tree program\n"<<endl;
				break;
			default:
				cout<<"Sorry! wrong input\n"<<endl;
				break;
		}
	}while(choice != 0);
	return 0;
}*/
