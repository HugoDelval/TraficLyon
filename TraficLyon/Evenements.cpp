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
	Date dateEvenement(jourSemaine, anneeEvent, moisEvent, nJourMoisEvent, heure, minutesEvent, secondesEvent);
	capteurs[idCapteur]->ajouter(trafic,dateEvenement);
	float traficAcuel=gestionnaireMax.ajouteCapteurEtRetourneTraficActuel(idCapteur,trafic,dateEvenement);
	if(traficAcuel > bouchonMax)
	{
		bouchonMax = traficAcuel;
		dateBouchonMax = dateEvenement;
	}
}

void Evenements::maxBouchonsSimultanes()
{
	dateBouchonMax.afficheDate();
	cout << " "
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
	{
		cout << "id = " << i << endl;
		capteurs[i]->afficher();
	}

}

Evenements::Evenements()
{
	arbreId = new ArbreIdentifiants();
	capteurs = new EvenementsCapteur*[1500];
	for(int i=0 ; i<1500 ; i++)
	{
		capteurs[i] = new EvenementsCapteur();
	}
	bouchonMax=0.0;
}

void Evenements::statistiquesCapteur(int idCapteurReel)
{
	int idCapteurTableau = arbreId->trouverIdTableauCorrespondant(idCapteurReel);
	capteurs[idCapteurTableau]->statistiquesParCapteur();
}

void Evenements::statistiquesJourSemaine(int nJour)
{
	for(int i=0 ; i<1500 ; i++)
	{

	}
}

Evenements::~Evenements()
{
#ifdef MAP
	cout<< "Evenements::~Evenements()" <<endl;
#endif
	delete [] capteurs;
// a modifier : boucles comme dans le constructeur
}

