/*
 * EvenementsCapteur.cpp
 *
 *  Created on: 7 nov. 2014
 *      Author: Hugo
 */

#include "EvenementsCapteur.h"


void EvenementsCapteur::ajouter(int trafic, Date date)
{
	int secondesPasseesMajore = 0;/*max5minutes(date-dateDernierEvenement); /*on s'interesse seulement
	                                                                     a la periode de validite de l'ancien evenement
	                                                                     */
	if((dateDernierEvenement+secondesPasseesMajore).heure != dateDernierEvenement.heure) // on est dans la mm heure, mm jour ..
	{
		secondesPassees[dateDernierEvenement.heure][dateDernierEvenement.jourDeLaSemaine][traficDernierEvenement]
                          += secondesPasseesMajore;
	}
	else // 2 cases a modifier
	{
		Date datePlus5min = dateDernierEvenement+secondesPasseesMajore;
		int tempsAAjouterDateDernierEvenement = ( (59-dateDernierEvenement.minute)*60 + 59-dateDernierEvenement.seconde ) ;
		int autreTemps = secondesPasseesMajore - tempsAAjouterDateDernierEvenement;
		secondesPassees[datePlus5min.heure][datePlus5min.jourDeLaSemaine][traficDernierEvenement]
		               += autreTemps;
		secondesPassees[dateDernierEvenement.heure][dateDernierEvenement.jourDeLaSemaine][traficDernierEvenement]
					   += tempsAAjouterDateDernierEvenement;
	}
	traficDernierEvenement = trafic;
	dateDernierEvenement = date;
}

void EvenementsCapteur::afficher()
{
	for(int i=0 ; i<24 ; i++)  // heures
	{
		for(int j=0 ; j<7 ; j++) // jour semaine
		{
			for(int k=0 ; k<5 ; k++) // trafic
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

