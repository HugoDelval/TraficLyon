/*************************************************************************
       Evenements  -  implementation des Evenements decrits dans Evenements.h
                             -------------------
    début                : 24/10/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/

//---------- Réalisation de la classe <Evenements> (fichier Evenements.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Evenements.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Evenements::AjouterEvenement(int idCapteur, int heure, int jourSemaine,
									int trafic, int anneeEvent , int moisEvent,
									int nJourMoisEvent, int minutesEvent, int secondesEvent)
{
	/*
#ifdef MAP
	cout<<"insert in Evenements with : "<<idCapteur<<" "<<heure<<" "<<jourSemaine<<" "<<trafic<<endl;
#endif
*/
	Date dateEvenement(jourSemaine, anneeEvent, moisEvent, nJourMoisEvent, heure, minutesEvent, secondesEvent);
	capteurs[idCapteur]->Ajouter(trafic,dateEvenement);
	dateDernierEvenementTrafic = dateEvenement;
	float traficAcuel=gestionnaireMax.AjouteCapteurEtRetourneTraficActuel(idCapteur,trafic,dateEvenement);
	if(traficAcuel > bouchonMax)
	{
		bouchonMax = traficAcuel;
		dateBouchonMax = dateEvenement;
	}
}

void Evenements::MaxBouchonsSimultanes()
{
	dateBouchonMax.AfficheDateRelle();
	cout << bouchonMax << "%"
		 << endl;
}

int Evenements::AjouterIdAArbre(int idCapeurReel)
{
	return arbreId->Insert(idCapeurReel);
}

void Evenements::AfficherTousLesEvenements()
{
	cout<< endl;
	cout<< "-------Evenements : -------" << endl;
	cout<< "-----(par idTableau)-------" << endl;
	cout<< "---------------------------" << endl;
	for(int i(0); i<NOMBRE_MAX_CAPTEURS; i++)
	{
		cout << "id = " << i << endl;
		capteurs[i]->Afficher();
	}

}


void Evenements::StatistiquesCapteur(int idCapteurReel)
{
	int idCapteurTableau( arbreId->TrouverIdTableauCorrespondant(idCapteurReel));
	capteurs[idCapteurTableau]->StatistiquesParCapteur();
}

void Evenements::StatistiquesJourSemaine(int nJour)
{
	double tempsTotal(0.0);
	double *secondesPasseesJournee = new double[NOMBRE_ETATS_CAPTEUR];
	for(int j(0) ; j<NOMBRE_ETATS_CAPTEUR ; j++)
	{
		secondesPasseesJournee[j] = 0.0;
	}
	//vert, jaune, rouge, et noir
	double *secondesPasseesJourneeCapteurX = new double[NOMBRE_ETATS_CAPTEUR];
	for(int i(0) ; i<NOMBRE_MAX_CAPTEURS ; i++)
	{
		secondesPasseesJourneeCapteurX = capteurs[i]->SecondesPasseesDansChaqueEtat(nJour, dateDernierEvenementTrafic);
		for(int j(0) ; j<NOMBRE_ETATS_CAPTEUR ; j++)
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


void Evenements::StatistiquesJourHeureSemaine(int nJour, int heure)
{
	double tempsTotal(0.0);
	double *secondesPasseesHeureJournee = new double[NOMBRE_ETATS_CAPTEUR];
	for(int j(0) ; j<NOMBRE_ETATS_CAPTEUR ; j++)
	{
		secondesPasseesHeureJournee[j] = 0.0;
	}
	//vert, jaune, rouge, et noir
	double *secondesPasseesHeureJourneeCapteurX = new double[NOMBRE_ETATS_CAPTEUR];
	for(int i(0) ; i<NOMBRE_MAX_CAPTEURS ; i++)
	{
		secondesPasseesHeureJourneeCapteurX = capteurs[i]->SecondesPasseesDansChaqueEtat(nJour, heure, dateDernierEvenementTrafic);
		for(int j(0) ; j<NOMBRE_ETATS_CAPTEUR ; j++)
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

//-------------------------------------------- Constructeurs - destructeur

Evenements::Evenements()
{
	arbreId = new ArbreIdentifiants();
	capteurs = new EvenementsCapteur*[NOMBRE_MAX_CAPTEURS];
	for(int i(0) ; i<NOMBRE_MAX_CAPTEURS ; i++)
	{
		capteurs[i] = new EvenementsCapteur();
	}
	bouchonMax=0.0;
}

Evenements::~Evenements()
{
#ifdef MAP
	cout<< "Evenements::~Evenements()" <<endl;
#endif
	delete [] capteurs;
// a modifier : boucles comme dans le constructeur
}

//------------------------------------------------------------------ PRIVE

//------------------------------------------------------- Méthodes privées

