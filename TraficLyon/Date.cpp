
/*
 * Date.cpp
 *
 *  Created on: 7 nov. 2014
 *      Author: Hugo
 */

#include "Date.h"


bool operator==(Date const &date1, Date const &date2)
{
	return date1.estEgal(date2);
}

bool operator!=(Date const& date1, Date const& date2)
{
	return !(date1==date2);
}

bool operator<(Date const& date2, Date const &date1)
{
	return date1.estInf(date2);
}

bool operator<=(Date const& date1, Date const& date2)
{
	return (date1<date2 || date1==date2);
}

bool operator>(Date const& date1, Date const& date2)
{
	return !(date1<date2 || date1==date2);
}

bool operator>=(Date const& date1, Date const& date2)
{
	return !(date1<date2);
}

Date operator+(Date const &date, int secondes)   // 0 <= secondes <= 60
{
	Date dateAddition(date);
	return dateAddition.additionner(secondes);
}

int operator-(Date const& date1, Date const& dateAEnlever)
{
	return date1.difference(dateAEnlever);
}

Date operator-(Date const &date, int secondes)   // 0 <= secondes <= 60
{
	Date dateSoustraction(date);
	return dateSoustraction.additionner(-secondes);
}

bool Date::estEgal(Date const &dateAComparer) const
{
	if (dateAComparer.annee == annee  && dateAComparer.jourDeLaSemaine==jourDeLaSemaine
				&& dateAComparer.jourDuMois==jourDuMois && dateAComparer.mois==mois
				&& dateAComparer.heure==heure && dateAComparer.minute==minute
				&& dateAComparer.seconde==seconde)
	{
		return true;
	} else {
		 return false;
	}
}

// todo verifier
bool Date::estInf(Date const& dateAComparer) const
{
	if(dateAComparer.annee <annee )
			return true;
		else if(dateAComparer.mois <mois)
			return true;
		else if(dateAComparer.jourDuMois < jourDuMois)
			return true;
		else if(dateAComparer.heure < heure)
			return true;
		else if(dateAComparer.minute <minute)
			return true;
		else if(dateAComparer.seconde <seconde)
			return true;
		else
			return false;
}

Date Date::additionner(int secondes)
{
	seconde += secondes;

	if(seconde >= 60)
	{
		minute+=seconde/60;
		seconde %= 60;
	}
	else if(seconde < 0)
	{
		seconde = -seconde;
		minute-=(((seconde-1)/60)+1);
		seconde %= 60;
		seconde = (60 - seconde)%60;
	}

	if(minute >= 60)
	{
		heure+=minute/60;
		minute%=60;
	}
	else if (minute<0)
	{
		minute = -minute;
		heure-=(((minute-1)/60)+1);
		minute %= 60;
		minute = (60 - minute)%60;
	}

	if(heure >= 24)
	{
		jourDuMois+=heure/24;
		jourDeLaSemaine+=heure/24;
		jourDeLaSemaine%=7;
		heure %=24;
	}
	else if (heure <0)
	{
		heure = -heure;
		jourDuMois-=(((heure-1)/24)+1);
		jourDeLaSemaine-=(((heure-1)/24)+1);
		jourDeLaSemaine%=7;
		jourDeLaSemaine = (7 - jourDeLaSemaine)%7;
		heure %=24;
		heure = (24 - heure)%24;
	}

	if((jourDuMois > 27 && mois == 1))
	{
		mois+=jourDuMois/28;
		jourDuMois%=31;
	}
	else if(jourDuMois<0 && mois==2)
	{
		jourDuMois=-jourDuMois;
		mois-=(((jourDuMois-1)/28)+1);
		jourDuMois%=28;
		jourDuMois = (28-jourDuMois)%28;
	}


	if((jourDuMois > 29 && (mois == 3 || mois == 5 || mois == 8 || mois == 10)))
	{
		mois+=jourDuMois/30;
		jourDuMois%=31;
	}
	else if(jourDuMois<0 && (mois==4 || mois==6 || mois==9 || mois==11))
	{
		jourDuMois=-jourDuMois;
		mois-=(((jourDuMois-1)/30)+1);
		jourDuMois%=30;
		jourDuMois=(30-jourDuMois)%30;
	}

	if(jourDuMois > 30 && (mois == 0 || mois == 2 || mois == 4 || mois == 6
										|| mois == 7 || mois == 9|| mois==11))
	{
		if(mois!=6 && mois != 11 && mois!=0)
		{
			mois+=jourDuMois/31;
			jourDuMois%=30;
		}
		else if(mois!=0)
		{
			mois+=jourDuMois/31;
			jourDuMois%=31;
		}
		else
		{
			mois+=jourDuMois/31;
			jourDuMois%=28;
		}
	}
	else if(jourDuMois<0 && (mois==1 || mois==3 || mois==5 || mois==7 || mois==8 || mois==10 || mois==0))
	{
		jourDuMois=-jourDuMois;
		mois-=(((jourDuMois-1)/31)+1);
		jourDuMois%=31;
		jourDuMois=(31-jourDuMois)%31;
	}

	secondesDepuisDebutAnnee += secondes;
	if(mois>11)
	{
		annee++;
		mois%=12;
	}
	else if(mois<0)
	{
		annee--;
		mois=-mois;
		mois%=12;
		mois=(12-mois)%12;
	}

	return *this;
}

int Date::difference(Date const &dateAEnlever) const
{
	return (secondesDepuisDebutAnnee - dateAEnlever.secondesDepuisDebutAnnee)+(annee - dateAEnlever.annee)*365*24*3600;
}

void Date::afficheDateRelle()
{
	cout << annee <<" "
		 << mois+1 << " "
		 << jourDuMois+1 << " "
		 << heure << " "
		 << minute << " "
		 << seconde << " ";
}

void Date::debugAffichage()
{
	cout << "année: "<< annee
		 <<" mois: "<<mois
		 << " jour: " << jourDuMois
		 << " heure: " << heure
		 << " minute: " << minute
		 << " seconde: " << seconde
		 << " jourSemaine: " << jourDeLaSemaine
		 <<endl;
}

Date::Date()
{
	this->jourDeLaSemaine = 0;
	this->annee = 0;
	this->mois = 0;
	this->jourDuMois = 0;
	this->heure = 0;
	this->minute = 0;
	this->seconde = 0;
	secondesDepuisDebutAnnee = 0;

}

Date::Date(int jourDeLaSemaine, int annee, int mois, int jourDuMois, int heure, int minute, int seconde)
{
	this->jourDeLaSemaine = jourDeLaSemaine;
	this->annee = annee;
	this->mois = mois;
	this->jourDuMois = jourDuMois;
	this->heure = heure;
	this->minute = minute;
	this->seconde = seconde;

	int secondesMois(0);
	int secondesMois30 (30*3600*24);
	int secondesMois31 (31*3600*24);
	int secondesMois28 (28*3600*24);
	switch (mois)
	{
		case 1: // fevrier
			secondesMois=secondesMois31;
			break;
		case 2: //mars
			secondesMois=secondesMois31 + secondesMois28;
			break;
		case 3: //avril
			secondesMois=secondesMois31 *2 + secondesMois28;
			break;
		case 4: //mai
			secondesMois=secondesMois31 *2 + secondesMois28 + secondesMois30;
			break;
		case 5: //juin
			secondesMois=secondesMois31 *3 + secondesMois28 + secondesMois30;
			break;
		case 6: //juillet
			secondesMois=secondesMois31 *3 + secondesMois28 + secondesMois30*2;
			break;
		case 7: //aout
			secondesMois=secondesMois31 *4 + secondesMois28 + secondesMois30 *2;
			break;
		case 8: //septembre
			secondesMois=secondesMois31 *5 + secondesMois28 + secondesMois30 *2;
			break;
		case 9: //octobre
			secondesMois=secondesMois31 *5 + secondesMois28 + secondesMois30 *3;
			break;
		case 10: //novembre
			secondesMois=secondesMois31 *6 + secondesMois28 + secondesMois30 *3;
			break;
		case 11: //decembre
			secondesMois=secondesMois31 *6 + secondesMois28 + secondesMois30 *4;
			break;
	}

	secondesDepuisDebutAnnee = seconde + minute*60 + heure*3600 + jourDuMois*3600*24 + secondesMois;
}

Date::Date(Date const &dateACopier)
{
	jourDeLaSemaine = dateACopier.jourDeLaSemaine;
	annee = dateACopier.annee;
	mois = dateACopier.mois;
	jourDuMois = dateACopier.jourDuMois;
	heure = dateACopier.heure;
	minute = dateACopier.minute;
	seconde = dateACopier.seconde;
	secondesDepuisDebutAnnee = dateACopier.secondesDepuisDebutAnnee;
	//
}

Date::~Date() {
	// TODO Auto-generated destructor stub
}
