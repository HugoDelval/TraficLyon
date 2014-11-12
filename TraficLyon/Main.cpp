/*************************************************************************
       	   	   	   	   	   	   	    Main
                             -------------------
    début                : 07/11/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Date.h"
#include "GestionTrafic.h"
#include "TestsGestionTrafic.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
static void LancementApplication()
{
	GestionTrafic g;
	g.Start();
}

static void LancementTests()
{
	TestsGestionTrafic testeur;
	testeur.LancementTests();
}

int main()
{
	 //LancementApplication();

	/* ou alors */

	LancementTests();

	return 0;
}
