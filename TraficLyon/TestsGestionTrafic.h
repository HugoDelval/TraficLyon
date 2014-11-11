/*************************************************************************
              	  	  TestsGestionTrafic.cpp  -  Objet 'TestsGestionTrafic'
                             -------------------
    d�but                : 07/11/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/


//---------- Interface de la classe <Date.cpp> (fichier Date.h) ------

#ifndef TESTSGESTIONTRAFIC_H_
#define TESTSGESTIONTRAFIC_H_

//--------------------------------------------------- Interfaces utilis�es
#include "GestionTrafic.h"

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Date>
//
//------------------------------------------------------------------------

class TestsGestionTrafic {

	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- M�thodes publiques
	void LancementTests();


	//----------------------------------------------------------------- PRIVE

	//------------------------------------------------------- M�thodes priv�es
private:
	void testAdd();
	void testStatsCapteur();
	void testStatJourSemaine();
	void testStatsJourSemaineHeure();
	void testStatsMaxBouchons();
};

#endif /* TESTSGESTIONTRAFIC_H_ */
