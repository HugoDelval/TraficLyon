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
	dateDernierEvenementTrafic = dateEvenement;
	float traficAcuel=gestionnaireMax.ajouteCapteurEtRetourneTraficActuel(idCapteur,trafic,dateEvenement);
	if(traficAcuel > bouchonMax)
	{
		bouchonMax = traficAcuel;
		dateBouchonMax = dateEvenement;
	}
}

void Evenements::maxBouchonsSimultanes()
{
	dateBouchonMax.afficheDateRelle();
	cout << bouchonMax << "%"
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
	double tempsTotal(0.0);
	double *secondesPasseesJournee = new double[4];
	for(int j=0 ; j<4 ; j++)
	{
		secondesPasseesJournee[j] = 0.0;
	}
	//vert, jaune, rouge, et noir
	double *secondesPasseesJourneeCapteurX = new double[4];
	for(int i=0 ; i<1500 ; i++)
	{
		secondesPasseesJourneeCapteurX = capteurs[i]->secondesPasseesDansChaqueEtat(nJour, dateDernierEvenementTrafic);
		for(int j=0 ; j<4 ; j++)
		{
			tempsTotal += secondesPasseesJourneeCapteurX[j];
			secondesPasseesJournee[j] += secondesPasseesJourneeCapteurX[j];
		}
	}
	cout<<tempsTotal<<endl;
	cout<<secondesPasseesJournee[0]<<endl;
	tempsTotal= tempsTotal==0 ? 1 : tempsTotal ; //on evite la division par 0
	cout<<"V "<<(secondesPasseesJournee[0]/tempsTotal)*100.0<<"%"<<endl;
	cout<<"J "<<(secondesPasseesJournee[1]/tempsTotal)*100.0<<"%"<<endl;
	cout<<"R "<<(secondesPasseesJournee[2]/tempsTotal)*100.0<<"%"<<endl;
	cout<<"N "<<(secondesPasseesJournee[3]/tempsTotal)*100.0<<"%"<<endl;
}


void Evenements::statistiquesJourHeureSemaine(int nJour, int heure)
{
	double tempsTotal(0.0);
	double *secondesPasseesHeureJournee = new double[4];
	for(int j=0 ; j<4 ; j++)
	{
		secondesPasseesHeureJournee[j] = 0.0;
	}
	//vert, jaune, rouge, et noir
	double *secondesPasseesHeureJourneeCapteurX = new double[4];
	for(int i=0 ; i<1500 ; i++)
	{
		secondesPasseesHeureJourneeCapteurX = capteurs[i]->secondesPasseesDansChaqueEtat(nJour, heure, dateDernierEvenementTrafic);
		for(int j=0 ; j<4 ; j++)
		{
			tempsTotal += secondesPasseesHeureJourneeCapteurX[j];
			secondesPasseesHeureJournee[j] += secondesPasseesHeureJourneeCapteurX[j];
		}
	}
	cout<<tempsTotal<<endl;
	cout<<secondesPasseesHeureJournee[0]<<endl;
	tempsTotal= tempsTotal==0 ? 1 : tempsTotal ; //on evite la division par 0
	cout<<"V "<<(secondesPasseesHeureJournee[0]/tempsTotal)*100.0<<"%"<<endl;
	cout<<"J "<<(secondesPasseesHeureJournee[1]/tempsTotal)*100.0<<"%"<<endl;
	cout<<"R "<<(secondesPasseesHeureJournee[2]/tempsTotal)*100.0<<"%"<<endl;
	cout<<"N "<<(secondesPasseesHeureJournee[3]/tempsTotal)*100.0<<"%"<<endl;
}


Evenements::~Evenements()
{
#ifdef MAP
	cout<< "Evenements::~Evenements()" <<endl;
#endif
	delete [] capteurs;
// a modifier : boucles comme dans le constructeur
}

