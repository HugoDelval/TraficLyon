/*
 * EvenementsCapteur.cpp
 *
 *  Created on: 7 nov. 2014
 *      Author: Hugo
 */

#include "EvenementsCapteur.h"


void EvenementsCapteur::ajouter(int trafic, Date date)
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
			int tempsAAjouterDateDernierEvenement = max5minutes( (59-dateDernierEvenement.minute)*60 + 60-dateDernierEvenement.seconde ) ;
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

void EvenementsCapteur::statistiquesParCapteur()
{
	double secondesPasseesActif=0.0;
	double secondesPasseesV1=0.0;
	double secondesPasseesJ2=0.0;
	double secondesPasseesR3=0.0;
	double secondesPasseesN4=0.0;
	for(int i=0 ; i<24 ; i++)
	{
		for(int j=0 ; j<7 ; j++)
		{
			for(int k=0 ; k<5 ; k++)
			{
				secondesPasseesActif += secondesPassees[i][j][k];
				switch(k)
				{
					case 1:
						secondesPasseesV1 += secondesPassees[i][j][k];
						break;
					case 2:
						secondesPasseesJ2 += secondesPassees[i][j][k];
						break;
					case 3:
						secondesPasseesR3 += secondesPassees[i][j][k];
						break;
					case 4:
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

double* EvenementsCapteur::secondesPasseesDansChaqueEtat(int jour, Date dateDernierEvenementTrafic)
{
	double *secondesPasseesJournee = new double[4];
	for(int j=0 ; j<4 ; j++)
	{
		secondesPasseesJournee[j] = 0.0;
	}
	for(int i=0 ; i<24 ; i++)
	{
		for(int j=1 ; j<5 ; j++)
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
				secondesPasseesJournee[traficDernierEvenement-1] += max5minutes( (59-dateDernierEvenement.minute)*60 + 60-dateDernierEvenement.seconde );
			}
			else if(datePlus5min.jourDeLaSemaine == jour)
			{
				secondesPasseesJournee[traficDernierEvenement-1] += max5minutes( (datePlus5min.minute)*60 + datePlus5min.seconde );
			}
		}
	}

	return secondesPasseesJournee;
}

double* EvenementsCapteur::secondesPasseesDansChaqueEtat(int jour, int heure, Date dateDernierEvenementTrafic)
{
	double *secondesPasseesHeure = new double[4];
	for(int j=0 ; j<4 ; j++)
	{
		secondesPasseesHeure[j] = 0.0;
	}
	for(int i=1 ; i<5 ; i++)
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
				secondesPasseesHeure[traficDernierEvenement-1] += max5minutes(60-dateDernierEvenement.seconde );
			}
			else if(datePlus5min.heure == heure)
			{
				secondesPasseesHeure[traficDernierEvenement-1] += max5minutes( datePlus5min.seconde );
			}
		}
	}

	return secondesPasseesHeure;
}

void EvenementsCapteur::afficher()
{
	for(int i=0 ; i<24 ; i++)  // heures
	{
		for(int j=0 ; j<7 ; j++) // jour semaine
		{
			for(int k=0 ; k<5 ; k++) // trafic
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

int EvenementsCapteur::max5minutes(int nombreSecondes)
{
	if(nombreSecondes <= 5*60)
	{
		return nombreSecondes;
	}
	return 5*60;
}

EvenementsCapteur::EvenementsCapteur(int trafic, Date date)
{
	traficDernierEvenement = trafic;
	dateDernierEvenement = date;
	secondesPassees = new int**[24];
	for(int i=0 ; i<24 ; i++)  // heures
	{
		secondesPassees[i] = new int*[7];
		for(int j=0 ; j<7 ; j++) // jour semaine
		{
			secondesPassees[i][j] = new int[5];
			for(int k=0 ; k<5 ; k++) // trafic
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
	secondesPassees = new int**[24];
	for(int i=0 ; i<24 ; i++)  // heures
	{
		secondesPassees[i] = new int*[7];
		for(int j=0 ; j<7 ; j++) // jour semaine
		{
			secondesPassees[i][j] = new int[5];
			for(int k=0 ; k<5 ; k++) // trafic
			{
				secondesPassees[i][j][k] = 0;
			}
		}
	}
	isEmpty=true;
}

EvenementsCapteur::~EvenementsCapteur()
{
	for(int i=0 ; i<24 ; i++)  // heures
	{
		for(int j=0 ; j<7 ; j++) // jour semaine
		{
			delete[] secondesPassees[i][j];
		}
	}
	for(int i=0 ; i<24 ; i++)  // heures
	{
		delete[] secondesPassees[i];
	}
	delete[] secondesPassees;
}

