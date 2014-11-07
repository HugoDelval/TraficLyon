/*
 * Evenement.cpp
 *
 *  Created on: 24 oct. 2014
 *      Author: Hugo
 */

#include "Evenement.h"

Evenement::Evenement()
{

#ifdef MAP
	cout<< "Evenement::Evenement()" <<endl;
#endif
	annee=0;
	mois=0;
	nJourMois=0;
	minutes=0;
	secondes=0;
	evenementSuivant=NULL;
	evenementPrecedent=NULL;
}

Evenement::Evenement(int anneeEvent , int moisEvent, int nJourMoisEvent, int minutesEvent, int secondesEvent)
{
	/*
#ifdef MAP
	cout<< "Evenement::Evenement(int anneeEvent , int moisEvent, int nJourMoisEvent, int minutesEvent, int secondesEvent)" <<endl;
#endif
*/
	annee=anneeEvent;
	mois=moisEvent;
	nJourMois=nJourMoisEvent;
	minutes=minutesEvent;
	secondes=secondesEvent;
	evenementSuivant=NULL;
	evenementPrecedent=NULL;
}


Evenement::~Evenement()
{
#ifdef MAP
	cout<< "Evenement::~Evenement()" <<endl;
#endif

}

/*
 * anneeEvent %= 1970;
	jourSemaine--;
	nJourMoisEvent--;
	moisEvent--;

	int heureF=heure,
		jourSemaineF=jourSemaine,
		anneeEventF=anneeEvent,
		moisEventF=moisEvent,
		nJourMoisEventF=nJourMoisEvent,
		minutesEventF=minutesEvent;

	if( minutesEvent+5 < 60 )
	{
		minutesEventF = minutesEvent+5;
	}
	else
	{
		minutesEventF = (minutesEvent+5)%60;
		if( heure+1 < 24 )
		{
			heureF = heure+1;
		}
		else
		{
			heureF = 0;
			jourSemaineF = (jourSemaine+1)%7;
			if( nJourMoisEvent+1 <= 27 ||
					(nJourMoisEvent+1 <= 29 && (moisEvent==3 || moisEvent==5 || moisEvent==8 || moisEvent==10) )
					||
					(nJourMoisEvent+1 <= 30 && (moisEvent==0 || moisEvent==2 || moisEvent==4 || moisEvent==6 || moisEvent==7 || moisEvent==9 || moisEvent==11))
					)
			{
				nJourMoisEventF = nJourMoisEvent+1;
			}
			else
			{
				nJourMoisEventF = 0;
				moisEventF = (moisEvent+1)%12;
				anneeEventF = moisEventF==0 ? (anneeEvent+1) : anneeEvent;
			}
		}
	}
 *
 */
