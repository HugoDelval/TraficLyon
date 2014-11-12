/*************************************************************************
       	   	   	   	   	   	   	    Main
                             -------------------
    d�but                : 07/11/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

//------------------------------------------------------ Include personnel
#include "Date.h"
#include "GestionTrafic.h"
#include "TestsGestionTrafic.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
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
