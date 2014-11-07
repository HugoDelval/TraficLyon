/*
 * Evenements.cpp
 *
 *  Created on: 24 oct. 2014
 *      Author: Hugo
 */

#include "Evenements.h"

void Evenements::ajouterEvenement(int idCapteur, int heure, int jourSemaine,
									int trafic, int anneeEvent , int moisEvent,
									int nJourMoisEvent, int minutesEvent, int secondesEvent)
{
	/*
#ifdef MAP
	cout<<"insert in Evenements with : "<<idCapteur<<" "<<heure<<" "<<jourSemaine<<" "<<trafic<<endl;
#endif
*/
	capteurs[idCapteur]->ajouter(heure, jourSemaine, trafic,
								 anneeEvent, moisEvent, nJourMoisEvent,
								 minutesEvent, secondesEvent);
	float traficAcuel=gestionnaireMax.ajouteCapteurEtRetourneTraficActuel(idCapteur,trafic,anneeEvent,moisEvent,nJourMoisEvent,heure,minutesEvent,secondesEvent);
	if(traficAcuel > bouchonMax)
	{
		bouchonMax = traficAcuel;
		anneeBouchonMax=anneeEvent;
		moisBouchonMax = moisEvent;
		jourBouchonMax = nJourMoisEvent;
		heureBouchonMax = heure;
		minuteBouchonMax = minutesEvent;
		secondeBouchonMax = secondesEvent;
	}
}

void Evenements::maxBouchonsSimultanes()
{
	cout << anneeBouchonMax << " "
		 << moisBouchonMax << " "
		 << jourBouchonMax << " "
		 << heureBouchonMax << " "
		 << minuteBouchonMax << " "
		 << secondeBouchonMax << " "
		 << bouchonMax << "%"
		 << endl;
}

int Evenements::ajouterIdAArbre(int idCapeurReel)
{
	return arbreId->insert(idCapeurReel);
}

void Evenements::afficherTousLesEvenements()
{
	cout<< endl;
	cout<< "-------Evenements : -------" << endl;
	cout<< "-----(par idTableau)-------" << endl;
	cout<< "---------------------------" << endl;
	for(int i(0); i<1500; i++)
		capteurs[i]->afficher();
}

Evenements::Evenements()
{
	arbreId = new ArbreIdentifiants();
	capteurs = new EvenementsCapteur*[1500];
	for(int i=0 ; i<1500 ; i++)
	{
		capteurs[i] = new EvenementsCapteur();
	}
	anneeBouchonMax=0;
	moisBouchonMax=0;
	jourBouchonMax=0;
	heureBouchonMax=0;
	minuteBouchonMax=0;
	secondeBouchonMax=0;
	bouchonMax=0.0;
}

void Evenements::statistiquesCapteur(int idCapteurReel)
{
	int idCapteurTableau = arbreId->trouverIdTableauCorrespondant(idCapteurReel);
	// float pourcentageVert = dureeVert / dureeTotale ;
}

Evenements::~Evenements()
{
#ifdef MAP
	cout<< "Evenements::~Evenements()" <<endl;
#endif
	delete [] capteurs;
// a modifier : boucles comme dans le constructeur
}

