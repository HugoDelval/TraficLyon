/*************************************************************************
              	  	  TestsGestionTrafic.cpp  -  Objet 'TestsGestionTrafic'
                             -------------------
    début                : 07/11/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/


//---------- Interface de la classe <Date.cpp> (fichier Date.h) ------

#ifndef TESTSGESTIONTRAFIC_H_
#define TESTSGESTIONTRAFIC_H_

//--------------------------------------------------- Interfaces utilisées
#include "GestionTrafic.h"

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Date>
//
//------------------------------------------------------------------------

class TestsGestionTrafic {

	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques
	void LancementTests();


	//----------------------------------------------------------------- PRIVE

	//------------------------------------------------------- Méthodes privées
private:
	void testAdd();
	void testStatsCapteur();
	void testStatJourSemaine();
	void testStatsJourSemaineHeure();
	void testStatsMaxBouchons();
};

#endif /* TESTSGESTIONTRAFIC_H_ */
