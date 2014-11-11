/*************************************************************************
 TestsGestionTrafic  -  implementation de la classe TestsGestionTrafic decrite dans TestsGestionTrafic.h
                             -------------------
    d�but                : 07/11/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/

//---------- R�alisation de la classe <TestsGestionTrafic> (fichier TestsGestionTrafic.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

//------------------------------------------------------ Include personnel
#include "TestsGestionTrafic.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
void LancementTests()
{
	testAdd();
	testStatsCapteur();
	testStatJourSemaine();
	testStatsJourSemaineHeure();
}


//------------------------------------------------------------------ PRIVE

//------------------------------------------------------- M�thodes priv�es
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
