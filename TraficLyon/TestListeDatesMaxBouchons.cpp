/*
 * TestListeDatesMaxBouchons.cpp
 *
 *  Created on: 8 nov. 2014
 *      Author: Papin
 */

#include "TestListeDatesMaxBouchons.h"

static void testSupprimeCapteursObsoletes()
{

}

static void testAjouteDansLaListe()
{
	ListeDatesMaxBouchons maListe1;

	ElementListeDates *element1;
	(*element1).idCapteur=1;
	Date maDate1(2, 2014, 5, 15, 22, 42, 24);
	(*element1).dateEvenement=maDate1;
	(*element1).trafic=2;

	ElementListeDates *element2;
	(*element2).idCapteur=1178;
	Date maDate2(4, 2014, 8, 16, 5, 43, 59);
	(*element2).dateEvenement=maDate2;
	(*element2).trafic=2;

	//maListe1.ajouteDansLaListe(element1);
	//maListe1.ajouteDansLaListe(element2);
	maListe1.debugAffiche();

}

static void testAjouteCapteurEtRetourneTraficActuel()
{

}
/*
int main()
{
	testAjouteDansLaListe();

	return 0;
}
*/


TestListeDatesMaxBouchons::TestListeDatesMaxBouchons() {
	// TODO Auto-generated constructor stub

}

TestListeDatesMaxBouchons::~TestListeDatesMaxBouchons() {
	// TODO Auto-generated destructor stub
}

