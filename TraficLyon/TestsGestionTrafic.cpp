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
void TestsGestionTrafic::LancementTests()
{
	testAdd();
	testStatsCapteur();
	testStatJourSemaine();
	testStatsJourSemaineHeure();
	testStatsMaxBouchons();
}


//------------------------------------------------------------------ PRIVE

//------------------------------------------------------- Méthodes privées
void TestsGestionTrafic::testAdd()
{
	cout << "----------------------ADD----------------------"<<endl;
	/* dans une heure, cas basique */
	GestionTrafic g;
	string s = "ADD 1422 2014 05 21 14 53 42 1 V";
	g.Start(s);
	s = "ADD 1422 2014 05 21 14 53 59 1 V";
	g.Start(s);
	g.toutLeTrafic->AfficherTousLesEvenements();
	cout << "attendu : 17s" << endl<<endl;

	/* entre deux minutes */
	GestionTrafic g1;
	s = "ADD 1422 2014 05 21 14 53 42 1 V";
	g1.Start(s);
	s = "ADD 1422 2014 05 21 14 54 10 1 V";
	g1.Start(s);
	g1.toutLeTrafic->AfficherTousLesEvenements();
	cout << "attendu : 28s" << endl<<endl;

	/* entre deux heures */
	GestionTrafic g2;
	s = "ADD 1422 2014 05 21 14 58 0 1 V";
	g2.Start(s);
	s = "ADD 1422 2014 05 21 15 1 0 1 V";
	g2.Start(s);
	g2.toutLeTrafic->AfficherTousLesEvenements();
	cout << "attendu : 180s" << endl<<endl;

	/* entre deux jours */
	GestionTrafic g3;
	s = "ADD 1422 2014 05 21 23 58 0 1 V";
	g3.Start(s);
	s = "ADD 1422 2014 05 22 0 1 0 2 V";
	g3.Start(s);
	g3.toutLeTrafic->AfficherTousLesEvenements();
	cout << "attendu : 180s" << endl<<endl;

	/* entre deux semaines */
	GestionTrafic g4;
	s = "ADD 1422 2014 05 21 23 58 0 7 V";
	g4.Start(s);
	s = "ADD 1422 2014 05 22 0 1 0 1 V";
	g4.Start(s);
	g4.toutLeTrafic->AfficherTousLesEvenements();
	cout << "attendu : 180s" << endl<<endl;

	/* entre deux mois */
	GestionTrafic g5;
	s = "ADD 1422 2014 5 31 23 58 0 7 V";
	g5.Start(s);
	s = "ADD 1422 2014 6 1 0 1 0 1 V";
	g5.Start(s);
	g5.toutLeTrafic->AfficherTousLesEvenements();
	cout << "attendu : 180s" << endl<<endl;
	cout << "-------------------FIN ADD----------------------"<<endl;
}

void TestsGestionTrafic::testStatsCapteur()
{
	cout << "----------------------STATS CAPTEUR----------------------"<<endl;
	/* dans une heure, cas basique */
	GestionTrafic g;
	string s = "ADD 1422 2014 05 21 14 53 0 1 V";
	g.Start(s);
	s = "ADD 1422 2014 05 21 14 53 10 1 J";
	g.Start(s);
	s = "ADD 1422 2014 05 21 14 53 30 1 R";
	g.Start(s);
	s = "ADD 1422 2014 05 21 14 54 0 1 N";
	g.Start(s);
	s = "ADD 1422 2014 05 21 14 54 40 1 N";
	g.Start(s);
	g.toutLeTrafic->StatistiquesCapteur(1422);
	cout << "attendu : V:10% J:20% R:30% N:40%" << endl<<endl;

	/* entre deux mois et deux semaines (cas le plus limite) */
	GestionTrafic g2;
	s = "ADD 1422 2014 05 31 23 59 0 7 V";
	g2.Start(s);
	s = "ADD 1422 2014 05 31 23 59 10 7 J";
	g2.Start(s);
	s = "ADD 1422 2014 05 31 23 59 30 7 R";
	g2.Start(s);
	s = "ADD 1422 2014 6 1 0 0 0 1 N";
	g2.Start(s);
	s = "ADD 1422 2014 6 1 0 0 40 1 N";
	g2.Start(s);
	g2.toutLeTrafic->StatistiquesCapteur(1422);
	cout << "attendu : V:10% J:20% R:30% N:40%" << endl<<endl;

	/* extinction d'un capteur */
	GestionTrafic g3;
	s = "ADD 1422 2014 05 31 23 59 0 7 V";
	g3.Start(s);
	s = "ADD 1422 2014 6 1 0 0 0 1 J";
	g3.Start(s);
	s = "ADD 1422 2014 6 1 0 7 0 1 N";
	g3.Start(s);
	g3.toutLeTrafic->StatistiquesCapteur(1422);
	cout << "attendu : V:16% J:83% R:0% N:0%" << endl<<endl;

	cout << "----------------------FIN STATS CAPTEUR----------------------"<<endl;
}

void TestsGestionTrafic::testStatJourSemaine()
{
	cout << "----------------------STATS JOUR SEMAINE----------------------"<<endl;
	/* cas basique */
	GestionTrafic g;
	string s = "ADD 1422 2014 05 21 14 53 0 1 V";
	g.Start(s);
	s = "ADD 1422 2014 05 21 14 53 10 1 J";
	g.Start(s);
	s = "ADD 1423 2014 05 21 14 53 30 1 R";
	g.Start(s);
	s = "ADD 1423 2014 05 21 14 54 0 1 N";
	g.Start(s);
	s = "ADD 1423 2014 05 21 14 54 40 1 N";
	g.Start(s);
	g.toutLeTrafic->StatistiquesJourSemaine(0);
	// vert:10s jaune:90s rouge:30s noir:40s tot:170s
	cout << "attendu : V:5% J:52% R:17% N:23%" << endl<<endl;

	/* entre deux mois et deux semaines (cas le plus limite) + chevauchement des capteurs */
	GestionTrafic g2;
	s = "ADD 1422 2014 05 31 23 59 0 7 V";
	g2.Start(s);
	s = "ADD 1423 2014 05 31 23 59 10 7 J";
	g2.Start(s);
	s = "ADD 1422 2014 05 31 23 59 30 7 R";
	g2.Start(s);
	s = "ADD 1423 2014 6 1 0 0 10 1 N";
	g2.Start(s);
	s = "ADD 1423 2014 6 1 0 0 40 1 N";
	g2.Start(s);
	// jour 7: V:30s J:50s R:30s tot:110s
	g2.toutLeTrafic->StatistiquesJourSemaine(6);
	cout << "attendu : V:27% J:45% R:27% N:0%" << endl;
	// jour 1: V:0s J:10s R:40s N:30s tot:80s
	g2.toutLeTrafic->StatistiquesJourSemaine(0);
	cout << "attendu : V:0% J:12% R:50% N:37%" << endl<<endl;

	/* extinction d'un capteur */
	GestionTrafic g3;
	s = "ADD 1422 2014 6 1 0 0 0 1 J";
	g3.Start(s);
	s = "ADD 1422 2014 6 1 0 7 0 1 N";
	g3.Start(s);
	s = "ADD 1422 2014 6 1 0 8 0 1 N";
	g3.Start(s);
	g3.toutLeTrafic->StatistiquesJourSemaine(0);
	cout << "attendu : V:0% J:83% R:0% N:16%" << endl<<endl;
	cout << "----------------------FIN STATS JOUR SEMAINE----------------------"<<endl;
}

void TestsGestionTrafic::testStatsJourSemaineHeure()
{
	cout << "----------------------STATS JOUR SEMAINE HEURE----------------------"<<endl;
	/* cas basique */
	GestionTrafic g;
	string s = "ADD 1422 2014 05 21 14 53 0 1 V";
	g.Start(s);
	s = "ADD 1422 2014 05 21 14 53 10 1 J";
	g.Start(s);
	s = "ADD 1423 2014 05 21 14 53 30 1 R";
	g.Start(s);
	s = "ADD 1423 2014 05 21 14 54 0 1 N";
	g.Start(s);
	s = "ADD 1423 2014 05 21 14 54 40 1 N";
	g.Start(s);
	g.toutLeTrafic->StatistiquesJourHeureSemaine(0,14);
	// vert:10s jaune:90s rouge:30s noir:40s tot:170s
	cout << "attendu : V:5% J:52% R:17% N:23%" << endl<<endl;

	/* entre deux mois et deux semaines (cas le plus limite) + chevauchement des capteurs */
	GestionTrafic g2;
	s = "ADD 1422 2014 05 31 23 59 0 7 V";
	g2.Start(s);
	s = "ADD 1423 2014 05 31 23 59 10 7 J";
	g2.Start(s);
	s = "ADD 1422 2014 05 31 23 59 30 7 R";
	g2.Start(s);
	s = "ADD 1423 2014 6 1 0 0 10 1 N";
	g2.Start(s);
	s = "ADD 1423 2014 6 1 0 0 40 1 N";
	g2.Start(s);
	// jour 7: V:30s J:50s R:30s tot:110s
	g2.toutLeTrafic->StatistiquesJourHeureSemaine(6,23);
	cout << "attendu : V:27% J:45% R:27% N:0%" << endl;
	// jour 1: V:0s J:10s R:40s N:30s tot:80s
	g2.toutLeTrafic->StatistiquesJourHeureSemaine(0,0);
	cout << "attendu : V:0% J:12% R:50% N:37%" << endl<<endl;

	/* extinction d'un capteur */
	GestionTrafic g3;
	s = "ADD 1422 2014 6 1 0 0 0 1 J";
	g3.Start(s);
	s = "ADD 1422 2014 6 1 0 7 0 1 N";
	g3.Start(s);
	s = "ADD 1422 2014 6 1 0 8 0 1 N";
	g3.Start(s);
	g3.toutLeTrafic->StatistiquesJourHeureSemaine(0,0);
	cout << "attendu : V:0% J:83% R:0% N:16%" << endl<<endl;
	cout << "----------------------FIN STATS JOUR SEMAINE HEURE----------------------"<<endl;
}

void TestsGestionTrafic::testStatsMaxBouchons()
{
/*
 * On assume ici que les tests sur les effets de bords vis-a-vis des dates
 * (passage d'une minute a une autre, d'une heure a une autre, d'un mois a un autre etc..)
 * on ete assez testes.
 *
 * Nous nous interessons donc au fait de savoir si la date et la
 * valeur du maximum de bouchonn s'actualise bien au cours du temps
 *
 * raisons de croire que ca pourrait ne pas marcher :
 * si les tests basiques fonctionnent c'est que la listeDateMaxBouchons renvoie une valeure correct du % de bouchon su la liste
 * cependant si cette liste n'est pas correctement mise a jour
 * (2capteurs du meme id presents ou un evenement etant trop vieux (>5min) pour rester dans la liste
 * alors il peut y avoir des erreurs
 */
	cout << "----------------------MAX BOUCHONS----------------------"<<endl;

	//test basique :
	GestionTrafic g;
	string s = "ADD 1422 2014 5 21 13 58 0 1 V";
	g.Start(s);
	s = "ADD 2216 2014 5 21 13 58 0 1 V";
	g.Start(s);
	s = "ADD 1422 2014 5 21 13 59 0 1 V";
	g.Start(s);
	s = "ADD 2216 2014 5 21 13 59 0 1 V";
	g.Start(s);
	s = "ADD 1422 2014 5 21 14 0 0 1 V";
	g.Start(s);
	s = "ADD 2216 2014 5 21 14 0 0 1 V";
	g.Start(s);
	s = "ADD 1422 2014 5 21 14 1 0 1 V";
	g.Start(s);
	s = "ADD 2216 2014 5 21 14 1 0 1 V";
	g.Start(s);
	s = "ADD 1422 2014 5 21 14 2 0 1 V";
	g.Start(s);
	s = "ADD 2216 2014 5 21 14 2 0 1 N";
	g.Start(s);
	s = "ADD 1422 2014 5 21 14 3 0 1 V";
	g.Start(s);
	s = "ADD 2216 2014 5 21 14 3 0 1 R";
	g.Start(s);
	s = "ADD 1425 2014 5 21 14 3 0 1 N"; //ajout d'un 3è !
	g.Start(s);
	s = "ADD 1425 2014 5 21 14 4 0 1 V";
	g.Start(s);
	s = "ADD 1422 2014 5 21 14 4 0 1 V";
	g.Start(s);
	s = "ADD 2216 2014 5 21 14 4 0 1 V";
	g.Start(s);
	s = "ADD 1422 2014 5 21 14 5 0 1 V";
	g.Start(s);
	s = "ADD 2216 2014 5 21 14 5 0 1 V";
	g.Start(s);
	s = "ADD 1422 2014 5 21 14 6 0 1 V";
	g.Start(s);
	s = "ADD 2216 2014 5 21 14 6 0 1 V";
	g.Start(s);
	s = "ADD 1422 2014 5 21 14 7 0 1 V";
	g.Start(s);
	s = "ADD 2216 2014 5 21 14 7 0 1 V";
	g.Start(s);
	s = "ADD 1422 2014 5 21 14 8 0 1 V";
	g.Start(s);
	s = "ADD 2216 2014 5 21 14 8 0 1 V";
	g.Start(s);
	s = "ADD 1422 2014 5 21 14 9 0 1 V";
	g.Start(s);
	s = "ADD 2216 2014 5 21 14 9 0 1 V";
	g.Start(s);
	g.toutLeTrafic->gestionnaireMax.AfficheListes();
	g.toutLeTrafic->MaxBouchonsSimultanes();
	cout<<"attendu : 2014 5 21 14 3 0 66%"<<endl<<endl;

	//changement de max bouchon :
	s = "ADD 1422 2014 5 21 14 10 0 1 R";
	g.Start(s);
	s = "ADD 2216 2014 5 21 14 10 0 1 R";
	g.Start(s);
	s = "ADD 1422 2014 5 21 14 10 0 1 V";
	g.Start(s);
	s = "ADD 2216 2014 5 21 14 10 0 1 V";
	g.Start(s);
	g.toutLeTrafic->gestionnaireMax.AfficheListes();
	g.toutLeTrafic->MaxBouchonsSimultanes();
	cout << "attendu : 2014 5 21 14 10 0 100%" << endl<<endl;
	// le changement s'opere bien

	GestionTrafic g2;
	//changement de max bouchon apres 5min:
	s = "ADD 1 2014 5 21 14 10 0 1 N";
	g2.Start(s);
	s = "ADD 2 2014 5 21 14 10 0 1 V";
	g2.Start(s);
	s = "ADD 1 2014 5 21 14 11 0 1 N";
	g2.Start(s);
	s = "ADD 2 2014 5 21 14 11 0 1 N";
	g2.Start(s);
	g2.toutLeTrafic->MaxBouchonsSimultanes();
	cout << "attendu : 2014 5 21 14 10 0 50%" << endl <<endl;
	s = "ADD 2 2014 5 21 14 16 0 1 N";
	g2.Start(s);
	g2.toutLeTrafic->gestionnaireMax.AfficheListes();
	g2.toutLeTrafic->MaxBouchonsSimultanes();
	cout << "attendu : 2014 5 21 14 11 0 100%" << endl<<endl;
	// le changement s'opere bien

	//maxbouchon a une date != d'une date d'un 'add'
	// erreur
	GestionTrafic g3;
	s = "ADD 1 2014 5 21 14 10 0 1 V";
	g3.Start(s);
	s = "ADD 2 2014 5 21 14 10 0 1 V";
	g3.Start(s);
	s = "ADD 3 2014 5 21 14 13 0 1 R";
	g3.Start(s);
	s = "ADD 2 2014 5 21 14 16 0 1 N";
	g3.Start(s);
	g3.toutLeTrafic->gestionnaireMax.AfficheListes();
	g3.toutLeTrafic->MaxBouchonsSimultanes();
	cout << "attendu : 2014 5 21 14 15 0 100%" << endl<<endl;


	cout << "----------------------FIN MAX BOUCHONS----------------------"<<endl;
}
