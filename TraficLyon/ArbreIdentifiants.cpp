/*
 * ArbreIdentifiants.cpp
 *
 *  Created on: 24 oct. 2014
 *      Author: Hugo
 */

#include <iostream>
#include "ArbreIdentifiants.h"

using namespace std;

ArbreIdentifiants::ArbreIdentifiants(ArbreIdentifiants *g, int idReel, int idTableau, ArbreIdentifiants *d)
{
#ifdef MAP
	cout<< "ArbreIdentifiants::ArbreIdentifiants(ArbreIdentifiants *g, "<< idReel<<", "<< idTableau<<", ArbreIdentifiants *d)" <<endl;
#endif
	if (g->isEmpty())
	{
		filsG=0;
	}
	else
	{
		*filsG=*g;
	}
    this->idReel=idReel;
    this->idTableau=idTableau;
    if (d->isEmpty())
    {
    	filsD=0;
    }
    else
    {
    	*filsD=*d;
    }

    hauteur = 1 + max(g->determineHauteur(),d->determineHauteur());
}

ArbreIdentifiants::ArbreIdentifiants()
{
#ifdef MAP
	cout<< "ArbreIdentifiants::ArbreIdentifiants()" <<endl;
#endif
    filsG = 0;
    idReel=-1;
    idTableau=-1;
    filsD = 0;
    hauteur = -1;
}

ArbreIdentifiants::~ArbreIdentifiants()
{
#ifdef MAP
	cout<< "ArbreIdentifiants::~ArbreIdentifiants()" <<endl;
#endif
	delete filsD;
	delete filsG;
}


int ArbreIdentifiants::determineHauteur()
{
	return isEmpty() ? -1 : hauteur;
}

void ArbreIdentifiants::calculerHauteur()
{
	hauteur = 1 + max(filsG->determineHauteur(),filsD->determineHauteur());
}


ArbreIdentifiants* ArbreIdentifiants::supprimerRacine()
{
#ifdef MAP
	cout<< "ArbreIdentifiants* ArbreIdentifiants::supprimerRacine()" <<endl;
#endif
	if ( filsG->isEmpty() && filsD->isEmpty())
		return 0;
	if ( filsG->isEmpty())
		return filsD->equilibrer();
	if ( filsD->isEmpty())
		return filsG->equilibrer();
	ArbreIdentifiants *b = filsG->dernierDescendant();
	idReel = b->idReel;
	idTableau = b->idTableau;
	filsG = supprimer(idReel, *(this->filsG));
	return this->equilibrer();
}

ArbreIdentifiants* ArbreIdentifiants::dernierDescendant()
{
	if ( filsD->isEmpty())
		return this;
	return filsD;
}


int ArbreIdentifiants::max(int a, int b)
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

int ArbreIdentifiants::trouverIdTableau(int idReel)
{
#ifdef MAP
	cout<< "int ArbreIdentifiants::trouverIdTableau(int idReel)" <<endl;
#endif
	if(this != 0)
	{
		if(this->idReel == idReel)
		{
			return this->idTableau;
		}
		else if(this->idReel < idReel)
		{
			return filsG->trouverIdTableau(idReel);
		}
		else
		{
			return filsD->trouverIdTableau(idReel);
		}
	}

	return -1;
}


ArbreIdentifiants* ArbreIdentifiants::rotationG()
{
#ifdef MAP
	cout<< "ArbreIdentifiants* ArbreIdentifiants::rotationG()" <<endl;
#endif
	ArbreIdentifiants *b = filsD;
	ArbreIdentifiants *c = new ArbreIdentifiants(filsG, idReel,idTableau, (b->filsG));
	ArbreIdentifiants *res = new ArbreIdentifiants(c, b->idReel, b->idTableau, (b->filsD));
	delete c;
	return res;
}

ArbreIdentifiants* ArbreIdentifiants::rotationD()
{
#ifdef MAP
	cout<< "ArbreIdentifiants* ArbreIdentifiants::rotationD()" <<endl;
#endif
	ArbreIdentifiants *b = filsG;
	ArbreIdentifiants *c = new ArbreIdentifiants(b->filsD, idReel, idTableau, filsG);
	ArbreIdentifiants *res = new ArbreIdentifiants((b->filsG), b->idReel, b->idTableau, c);
	delete c;
	return res;
}

ArbreIdentifiants* ArbreIdentifiants::equilibrer()
{
#ifdef MAP
	cout<< "ArbreIdentifiants* ArbreIdentifiants::equilibrer()" <<endl;
#endif
	hauteur = 1 + max(filsG->determineHauteur(), filsD->determineHauteur());
	if(filsG->determineHauteur() - filsD->determineHauteur() == 2)
	{
		if (filsG->filsG->determineHauteur() < filsG->filsD->determineHauteur())
		{
			filsG = filsG->rotationG();
		}
		return rotationD();
	} //version symétrique
	if (filsG->determineHauteur() - filsD->determineHauteur() == -2)
	{
		if (filsD->filsD->determineHauteur() < filsD->filsG->determineHauteur())
		{
			filsD = filsD->rotationD();
		}
		return rotationG();
	}
	return this;
}

bool ArbreIdentifiants::isEmpty()
{
	return (this==0) || (idReel==-1 && idTableau==-1 && hauteur==-1 && filsD==0 && filsG==0);
}

//Public

ArbreIdentifiants* ArbreIdentifiants::inserer(int idR, int idT)
{
#ifdef MAP
	cout<< "ArbreIdentifiants* ArbreIdentifiants::inserer(int idR, int idT)" <<endl;
#endif
	if (isEmpty())
	{
	    return new ArbreIdentifiants(0,idR ,idT ,0);
	}
	if (idR < this->idReel)
		filsG = filsG->inserer(idR, idT);
	else if (idR > this->idReel)
		filsD = filsD->inserer(idR, idT);
	return equilibrer();
}


ArbreIdentifiants* ArbreIdentifiants::supprimer(int idR, ArbreIdentifiants &a)
{
#ifdef MAP
	cout<< "ArbreIdentifiants* ArbreIdentifiants::supprimer(int idR, ArbreIdentifiants &a)" <<endl;
#endif
	if ( a.isEmpty())
		return &a;
	if (idR == a.idReel)
		return a.supprimerRacine();
	if (idR < a.idReel)
		a.filsG = supprimer(idR, *(a.filsG));
	else
		a.filsD = supprimer(idR, *(a.filsD));
	return a.equilibrer(); // seul changement
}

int ArbreIdentifiants::getId(int idReel)
{
#ifdef MAP
	cout<< "int ArbreIdentifiants::getId(int idReel)" <<endl;
#endif
	return trouverIdTableau(idReel);
}

void ArbreIdentifiants::afficher()
{
	if(!isEmpty())
	{
		cout << idTableau << endl;
		filsG->afficher();
		filsD->afficher();
	}
}


