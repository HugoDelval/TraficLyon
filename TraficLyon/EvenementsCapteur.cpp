/*************************************************************************
       EvenementsCapteur  -  implementation des EvenementsCapteurs decrite dans EvenementsCapteur.h
                             -------------------
    début                : 07/11/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/

//---------- Réalisation de la classe <> (fichier EvenementsCapteur.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "EvenementsCapteur.h"

//------------------------------------------------------------- Constantes


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void EvenementsCapteur::Ajouter(int trafic, Date date)
{
	if(!isEmpty)
	{
		int secondesPasseesMajore = max5minutes(date-dateDernierEvenement); /*on s'interesse seulement
		                                                                     a la periode de validite de l'ancien evenement
		                                                                     */
		Date datePlus5min = dateDernierEvenement+secondesPasseesMajore;
		if(datePlus5min.heure == dateDernierEvenement.heure) // on est dans la mm heure, mm jour ..
		{
			secondesPassees[dateDernierEvenement.heure][dateDernierEvenement.jourDeLaSemaine][traficDernierEvenement]
	                          += secondesPasseesMajore;
		}
		else // 2 cases a modifier
		{
			int tempsAAjouterDateDernierEvenement = max5minutes( (NOMBRE_MINUSTES_HEURE-1-dateDernierEvenement.minute)*NOMBRE_MINUSTES_HEURE + NOMBRE_SECONDES_MINUTE -dateDernierEvenement.seconde ) ;
			int autreTemps = secondesPasseesMajore - tempsAAjouterDateDernierEvenement;
			/*cout<<tempsAAjouterDateDernierEvenement<<endl;
			cout<<autreTemps<<endl;
			cout<<secondesPasseesMajore<<endl;*/
			secondesPassees[datePlus5min.heure][datePlus5min.jourDeLaSemaine][traficDernierEvenement]
			               += autreTemps;
			secondesPassees[dateDernierEvenement.heure][dateDernierEvenement.jourDeLaSemaine][traficDernierEvenement]
						   += tempsAAjouterDateDernierEvenement;
		}
		traficDernierEvenement = trafic;
		dateDernierEvenement = date;
	}
	else
	{
		traficDernierEvenement = trafic;
		dateDernierEvenement = date;
		isEmpty=false;
	}
	//cout<<"fin ajouter dans EvenementsCapteur"<<endl;

}

void EvenementsCapteur::StatistiquesParCapteur()
{
	double secondesPasseesActif=0.0;
	double secondesPasseesV1=0.0;
	double secondesPasseesJ2=0.0;
	double secondesPasseesR3=0.0;
	double secondesPasseesN4=0.0;
	for(int i(0) ; i<NOMBRE_HEURES_JOURNEE ; i++)
	{
		for(int j(0) ; j<NOMBRE_JOURS_SEMAINE ; j++)
		{
			for(int k(0) ; k<NOMBRE_ETATS_CAPTEUR_TOT ; k++)
			{
				secondesPasseesActif += secondesPassees[i][j][k];
				switch(k)
				{
					case VERT:
						secondesPasseesV1 += secondesPassees[i][j][k];
						break;
					case JAUNE:
						secondesPasseesJ2 += secondesPassees[i][j][k];
						break;
					case ROUGE:
						secondesPasseesR3 += secondesPassees[i][j][k];
						break;
					case NOIR:
						secondesPasseesN4 += secondesPassees[i][j][k];
				}
			}
		}
	}
	cout<<"V "<<(secondesPasseesV1/secondesPasseesActif)*100.0<<"%"<<endl;
	cout<<"J "<<(secondesPasseesJ2/secondesPasseesActif)*100.0<<"%"<<endl;
	cout<<"R "<<(secondesPasseesR3/secondesPasseesActif)*100.0<<"%"<<endl;
	cout<<"N "<<(secondesPasseesN4/secondesPasseesActif)*100.0<<"%"<<endl;
}

double* EvenementsCapteur::SecondesPasseesDansChaqueEtat(int jour, Date dateDernierEvenementTrafic)
{
	double *secondesPasseesJournee = new double[NOMBRE_ETATS_CAPTEUR_UTILES];
	for(int j(0) ; j<NOMBRE_ETATS_CAPTEUR_UTILES ; j++)
	{
		secondesPasseesJournee[j] = 0.0;
	}
	for(int i(0) ; i<NOMBRE_HEURES_JOURNEE ; i++)
	{
		for(int j(1) ; j<NOMBRE_ETATS_CAPTEUR_TOT ; j++)
		{
			secondesPasseesJournee[j-1] += secondesPassees[i][jour][j];
		}
	}

	int secondesPasseesMajore = max5minutes(dateDernierEvenementTrafic-dateDernierEvenement);
	if(secondesPasseesMajore>0) // on doit peut etre ajouter qqchose au resultat final
	{
		Date datePlus5min = dateDernierEvenement+secondesPasseesMajore;
		//il faut ajouter qqchose si :
		if( datePlus5min.jourDeLaSemaine==jour && dateDernierEvenement.jourDeLaSemaine==jour )
		{
			secondesPasseesJournee[traficDernierEvenement-1] += secondesPasseesMajore;
		}
		else
		{
			if(dateDernierEvenement.jourDeLaSemaine == jour)
			{
				secondesPasseesJournee[traficDernierEvenement-1] += max5minutes(
						(NOMBRE_MINUSTES_HEURE-1-dateDernierEvenement.minute)*NOMBRE_SECONDES_MINUTE
						+ NOMBRE_SECONDES_MINUTE-dateDernierEvenement.seconde );
			}
			else if(datePlus5min.jourDeLaSemaine == jour)
			{
				secondesPasseesJournee[traficDernierEvenement-1] += max5minutes( (datePlus5min.minute)*NOMBRE_SECONDES_MINUTE + datePlus5min.seconde );
			}
		}
	}

	return secondesPasseesJournee;
}

double* EvenementsCapteur::SecondesPasseesDansChaqueEtat(int jour, int heure, Date dateDernierEvenementTrafic)
{
	double *secondesPasseesHeure = new double[NOMBRE_ETATS_CAPTEUR_UTILES];
	for(int j(0) ; j<NOMBRE_ETATS_CAPTEUR_UTILES ; j++)
	{
		secondesPasseesHeure[j] = 0.0;
	}
	for(int i(1) ; i<(NOMBRE_ETATS_CAPTEUR_UTILES+1) ; i++)
	{
		secondesPasseesHeure[i-1] += secondesPassees[heure][jour][i];
	}

	int secondesPasseesMajore = max5minutes(dateDernierEvenementTrafic-dateDernierEvenement);
	if(secondesPasseesMajore>0) // on doit peut etre ajouter qqchose au resultat final
	{
		Date datePlus5min = dateDernierEvenement+secondesPasseesMajore;
		//il faut ajouter qqchose si :
		if( datePlus5min.heure==heure && dateDernierEvenement.heure==heure )
		{
			secondesPasseesHeure[traficDernierEvenement-1] += secondesPasseesMajore;
		}
		else
		{
			if(dateDernierEvenement.heure == heure)
			{
				secondesPasseesHeure[traficDernierEvenement-1] += max5minutes(NOMBRE_SECONDES_MINUTE-dateDernierEvenement.seconde );
			}
			else if(datePlus5min.heure == heure)
			{
				secondesPasseesHeure[traficDernierEvenement-1] += max5minutes( datePlus5min.seconde );
			}
		}
	}

	return secondesPasseesHeure;
}

void EvenementsCapteur::Afficher()
{
	for(int i(0) ; i<NOMBRE_HEURES_JOURNEE ; i++)  // heures
	{
		for(int j(0) ; j<NOMBRE_JOURS_SEMAINE ; j++) // jour semaine
		{
			for(int k(0) ; k<NOMBRE_ETATS_CAPTEUR_TOT ; k++) // trafic
			{
				if(secondesPassees[i][j][k]!=0)
				{
					cout << "heure:" << i
						 << "    jour de la semaine:" << j
						 << "    trafic:" << k
						 << "    nombres secondes dans cet état:" << secondesPassees[i][j][k]
						 << endl;
				}

			}
		}
	}
}

//-------------------------------------------- Constructeurs - destructeur

EvenementsCapteur::EvenementsCapteur(int trafic, Date date)
{
	traficDernierEvenement = trafic;
	dateDernierEvenement = date;
	secondesPassees = new int**[NOMBRE_HEURES_JOURNEE];
	for(int i(0) ; i<NOMBRE_HEURES_JOURNEE ; i++)  // heures
	{
		secondesPassees[i] = new int*[NOMBRE_JOURS_SEMAINE];
		for(int j(0) ; j<NOMBRE_JOURS_SEMAINE ; j++) // jour semaine
		{
			secondesPassees[i][j] = new int[5];
			for(int k(0) ; k<NOMBRE_ETATS_CAPTEUR_TOT ; k++) // trafic
			{
				secondesPassees[i][j][k] = 0;
			}
		}
	}
	isEmpty=false;
}

EvenementsCapteur::EvenementsCapteur()
{
	traficDernierEvenement = 0;
//	dateDernierEvenement();
	secondesPassees = new int**[NOMBRE_HEURES_JOURNEE];
	for(int i(0) ; i<NOMBRE_HEURES_JOURNEE ; i++)
	{
		secondesPassees[i] = new int*[NOMBRE_JOURS_SEMAINE];
		for(int j(0) ; j<NOMBRE_JOURS_SEMAINE ; j++)
		{
			secondesPassees[i][j] = new int[NOMBRE_ETATS_CAPTEUR_TOT];
			for(int k(0) ; k<NOMBRE_ETATS_CAPTEUR_TOT ; k++) // trafic
			{
				secondesPassees[i][j][k] = 0;
			}
		}
	}
	isEmpty=true;
}

EvenementsCapteur::~EvenementsCapteur()
{
	for(int i(0) ; i<NOMBRE_HEURES_JOURNEE ; i++)  // heures
	{
		for(int j(0) ; j<NOMBRE_JOURS_SEMAINE ; j++) // jour semaine
		{
			delete[] secondesPassees[i][j];
		}
	}
	for(int i(0) ; i<NOMBRE_HEURES_JOURNEE ; i++)  // heures
	{
		delete[] secondesPassees[i];
	}
	delete[] secondesPassees;
}

//------------------------------------------------------------------ PRIVE

//------------------------------------------------------- Méthodes privées

int EvenementsCapteur::max5minutes(int nombreSecondes)
{
	if(nombreSecondes <= 5*NOMBRE_SECONDES_MINUTE)
	{
		return nombreSecondes;
	}
	return 5*NOMBRE_SECONDES_MINUTE;
}
