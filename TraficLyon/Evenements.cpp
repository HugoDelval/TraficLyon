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
	Date dateEvenement(jourSemaine, anneeEvent, moisEvent, nJourMoisEvent, heure, minutesEvent, secondesEvent);
	capteurs[idCapteur]->Ajouter(trafic,dateEvenement);
	dateDernierEvenementTrafic = dateEvenement;
	gestionnaireMax.Ajouter(idCapteur,trafic,dateEvenement);
}

void Evenements::MaxBouchonsSimultanes()
{
	gestionnaireMax.AfficherMax();
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
	tempsTotal= tempsTotal==0 ? 1 : tempsTotal ; //on evite la division par 0
	cout<<"V "<<(int)((secondesPasseesJournee[0]/tempsTotal)*100.0)<<"%"<<"\r\n";
	cout<<"J "<<(int)((secondesPasseesJournee[1]/tempsTotal)*100.0)<<"%"<<"\r\n";
	cout<<"R "<<(int)((secondesPasseesJournee[2]/tempsTotal)*100.0)<<"%"<<"\r\n";
	cout<<"N "<<(int)((secondesPasseesJournee[3]/tempsTotal)*100.0)<<"%"<<"\r\n";
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
	tempsTotal= tempsTotal==0 ? 1 : tempsTotal ; //on evite la division par 0
	cout<<"V "<<(int)((secondesPasseesHeureJournee[0]/tempsTotal)*100.0)<<"%"<<"\r\n";
	cout<<"J "<<(int)((secondesPasseesHeureJournee[1]/tempsTotal)*100.0)<<"%"<<"\r\n";
	cout<<"R "<<(int)((secondesPasseesHeureJournee[2]/tempsTotal)*100.0)<<"%"<<"\r\n";
	cout<<"N "<<(int)((secondesPasseesHeureJournee[3]/tempsTotal)*100.0)<<"%"<<"\r\n";
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
}

Evenements::~Evenements()
{
	delete arbreId;
	for(int i=0 ; i<NOMBRE_MAX_CAPTEURS ; i++)
	{
		delete capteurs[i];
	}
	delete [] capteurs;
}

//------------------------------------------------------------------ PRIVE

//------------------------------------------------------- Méthodes privées

