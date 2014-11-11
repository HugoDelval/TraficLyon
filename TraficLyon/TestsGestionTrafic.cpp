/*************************************************************************
 TestsGestionTrafic  -  implementation de la classe TestsGestionTrafic decrite dans TestsGestionTrafic.h
                             -------------------
    début                : 07/11/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/

//---------- Réalisation de la classe <TestsGestionTrafic> (fichier TestsGestionTrafic.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "TestsGestionTrafic.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void LancementTests()
{
	testAdd();
	testStatsCapteur();
	testStatJourSemaine();
	testStatsJourSemaineHeure();
}


//------------------------------------------------------------------ PRIVE

//------------------------------------------------------- Méthodes privées
void testAdd()
{
	GestionTrafic g;
	g.Start();
	g.toutLeTrafic->AfficherTousLesEvenements();
	cin << "ADD 1422 2012 05 21 14 53 42 1 V" << endl;
}

void testStatsCapteur()
{

}

void testStatJourSemaine()
{

}

void testStatsJourSemaineHeure()
{

}

void testStatsMaxBouchons()
{

}
