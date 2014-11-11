/*
 * Main.cpp
 *
 *  Created on: 11 nov. 2014
 *      Author: Papin
 */
#include "GestionTrafic.h"
#include "TestsGestionTrafic.h"

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
	// ou alors les tests :
	LancementTests();
	return 0;
}
