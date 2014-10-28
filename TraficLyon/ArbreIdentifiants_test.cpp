/*
 * ArbreIdentifiants_test.cpp
 *
 *  Created on: 24 oct. 2014
 *      Author: Hugo
 */
#include <iostream>
#include "ArbreIdentifiants.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>

using namespace std;
/*
int main()
{
	/* initialize random seed: */
	/*srand (time(NULL));

	cout<<"GO!"<<endl;
	ArbreIdentifiants *a = new ArbreIdentifiants();
	int iterations =30;
	int idCourant=0;
	for (int i=0 ; i<iterations ; i++)
	{
		idCourant = (rand() % (5000000))+1;
		cout<<idCourant<<endl;
		a->insert(a->createNewNode(idCourant,i));
	}
	a->printTree();
	delete a;
/*
	ArbreIdentifiants *theAVLTree=new ArbreIdentifiants();
	 cout << "\nAdding Node 50\n";
	   theAVLTree->insert(theAVLTree->createNewNode(50,1));
	   theAVLTree->printTree();
	   // Add 20
	   cout << "\nAdding Node 20\n";
	   theAVLTree->insert(theAVLTree->createNewNode(20,2));
	   theAVLTree->printTree();
	   // Add 70
	   cout << "\nAdding Node 70\n";
	   theAVLTree->insert(theAVLTree->createNewNode(70,3));
	   theAVLTree->printTree();
	   // Add 30
	   cout << "\nAdding Node 30\n";
	   theAVLTree->insert(theAVLTree->createNewNode(30,4));
	   theAVLTree->printTree();
	   // Add 10
	   cout << "\nAdding Node 10\n";
	   theAVLTree->insert(theAVLTree->createNewNode(10,5));
	   theAVLTree->printTree();
	   // Add 90
	    *
	    */
//}
