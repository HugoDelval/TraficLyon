/*
 * ArbreIdentifiants.cpp
 *
 *  Created on: 24 oct. 2014
 *      Author: Hugo
 */

#include "ArbreIdentifiants.h"



static int determineHauteur(ArbreIdentifiants a)
{
	return (a == 0) ? -1 : a.hauteur;
}

static void calculerHauteur(ArbreIdentifiants a)
{
	a.hauteur = 1 + max(determineHauteur(a.filsG),determineHauteur(a.filsD));
}

static ArbreIdentifiants rotationG(ArbreIdentifiants a)
{
	ArbreIdentifiants b = a.filsD;
	ArbreIdentifiants c = new ArbreIdentifiants(a.filsG, a.idReel, a.idTableau, b.filsG);
	return new ArbreIdentifiants(c, a.idReel, a.idTableau, b.filsD);
}

static ArbreIdentifiants rotationD(ArbreIdentifiants a)
{
	ArbreIdentifiants b = a.filsG;
	ArbreIdentifiants c = new ArbreIdentifiants(a.filsD, a.idReel, a.idTableau, b.filsD);
	return new ArbreIdentifiants(c, a.idReel, a.idTableau, b.filsG);
}

static ArbreIdentifiants equilibrer(ArbreIdentifiants a)
{
	a.hauteur = 1 + max(determineHauteur(a.filsG), determineHauteur(a.filsD));
	if(determineHauteur(a.filsG) - determineHauteur(a.filsD) == 2)
	{
		if (determineHauteur(a.filsG.filsG) < determineHauteur(a.filsG.filsD))
		{
			a.filsG = rotationG(a.filsG);
		}
		return rotationD(a);
	} //else version symétrique
	if (determineHauteur(a.filsG) - determineHauteur(a.filsD) == -2)
	{
		if (determineHauteur(a.filsD.filsD) < determineHauteur(a.filsD.filsG))
		{
			a.filsD = rotationD(a.filsD);
		}
		return rotationG(a);
	}
	return a;
}




static ArbreIdentifiants inserer(int idR, int idT, ArbreIdentifiants a)
{
	if (a == 0)
	{
	    return new ArbreIdentifiants(0,idR ,idT ,0);
	}
	if (idR < a.idReel)
		a.filsG = inserer(idR, idT, a.filsG);
	else if (idR > a.idReel)
		a.filsD = inserer(idR, idT, a.filsD);
	return equilibrer(a); //seul changement
}


static ArbreIdentifiants supprimer(int idR, int idT, ArbreIdentifiants a)
{
	if (a == 0)
		return a;
	if (idR == a.idReel)
		return supprimerRacine(a);
	if (idR < a.idReel)
		a.filsG = supprimer(idR, idT, a.filsG);
	else
		a.filsD = supprimer(idR, idT, a.filsD);
	return equilibrer(a); // seul changement
}

static ArbreIdentifiants supprimerRacine(ArbreIdentifiants a)
{
	if (a.filsG == 0 && a.filsD == 0)
		return 0;
	if (a.filsG == 0)
		return equilibrer(a.filsD);
	if (a.filsD == 0)
		return equilibrer(a.filsG);
	ArbreIdentifiants b = dernierDescendant(a.filsG);
	a.contenu = b.contenu;
	a.filsG = supprimer(a.contenu, a.filsG);
	return equilibrer(a); // seul changement
}

static ArbreIdentifiants dernierDescendant(ArbreIdentifiants) // inchangée
{
	if (a.filsD == null)
		return a;
	return ArbreIdentifiants(a.filsD);
}



ArbreIdentifiants::ArbreIdentifiants(ArbreIdentifiants g, int idReel, int idTableau, ArbreIdentifiants d)
{
    filsG = g;
    this->idReel=idReel;
    this->idTableau=idTableau;
    filsD = d;

    hauteur = 1 + max(determineHauteur(g),determineHauteur(d));
}

ArbreIdentifiants::~ArbreIdentifiants()
{
	// TODO Auto-generated destructor stub
}

int max(int a, int b)
{
	int max=0;
	if(a<b)
	{
		max=b;
	}
	else
	{
		max=a;
	}
	return max;
}

//5.3.1.4  Implantation: la classe Avl


