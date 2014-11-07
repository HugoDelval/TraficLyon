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
	Evenement *evenementAAjouter= new Evenement(anneeEvent, moisEvent, nJourMoisEvent,minutesEvent, secondesEvent);
	evenements[idCapteur][heure][jourSemaine][trafic]->ajouterDansLaListe(evenementAAjouter);
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
		for(int j(0) ; j<23 ; j++)
			for(int k(0) ; k<7 ; k++)
				for(int l(0) ; l<5 ; l++)
					evenements[i][j][k][l]->afficherListe(i,j,k,l);
}

Evenements::Evenements()
{
	arbreId = new ArbreIdentifiants();
	evenements= new ListeEvenements****[1500];
	for(int i=0 ; i<1500 ; i++)
	{
		evenements[i] = new ListeEvenements***[23];
		for(int j=0 ; j<23 ; j++)
		{
			evenements[i][j] = new ListeEvenements**[7];
			for(int k=0 ; k<7 ; k++)
			{
				evenements[i][j][k] = new ListeEvenements*[5];
				for(int l=0 ; l<5 ; l++)
				{
					evenements[i][j][k][l] = new ListeEvenements();
				}
			}
		}
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
	float pourcentageVert = dureeVert / dureeTotale ;
}

Evenements::~Evenements()
{
#ifdef MAP
	cout<< "Evenements::~Evenements()" <<endl;
#endif
	delete [] evenements;
// a modifier : boucles comme dans le constructeur
}

