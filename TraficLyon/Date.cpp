
/*
 * Date.cpp
 *
 *  Created on: 7 nov. 2014
 *      Author: Hugo
 */

#include "Date.h"


bool operator==(Date& date1, Date& date2)
{
	return date1.estEgal(date2);
}

bool operator!=(Date& date1, Date& date2)
{
	return !(date1==date2);
}

bool operator<(Date &date2, Date& date1)
{
	return date1.estInf(date2);
}

bool operator<=(Date& date1, Date& date2)
{
	return (date1<date2 || date1==date2);
}

bool operator>(Date& date1, Date& date2)
{
	return !(date1<date2 || date1==date2);
}

bool operator>=(Date& date1, Date& date2)
{
	return !(date1<date2);
}

Date operator+(const Date &date, int secondes)   // 0 <= secondes <= 60
{
	Date dateAddition(date);
	return dateAddition.additionner(secondes);
}

Date operator-(const Date &date, int secondes)   // 0 <= secondes <= 60
{
	Date dateSoustraction(date);
	return dateSoustraction.additionner(-secondes);
}

bool Date::estEgal(Date const& dateAComparer)
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

bool Date::estInf(Date const& dateAComparer)
{
	if(dateAComparer.annee >annee )
			return true;
		else if(dateAComparer.mois >mois)
			return true;
		else if(dateAComparer.jourDuMois > jourDuMois)
			return true;
		else if(dateAComparer.heure > heure)
			return true;
		else if(dateAComparer.minute >minute)
			return true;
		else if(dateAComparer.seconde >seconde)
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
		minute-=((seconde/60)+1);
		seconde %= 60;
		seconde = 60 - seconde;
	}

	if(minute >= 60)
	{
		heure+=minute/60;
		minute%=60;
	}
	else if (minute<0)
	{
		minute = -minute;
		heure-=((minute/60)+1);
		minute %= 60;
		minute = 60 - minute;
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
		jourDuMois-=((heure/24)+1);
		jourDeLaSemaine-=((heure/24)+1);
		jourDeLaSemaine%=7;
		jourDeLaSemaine = 7 - jourDeLaSemaine;
		heure %=24;
		heure = 24 - heure;
	}

	if((jourDuMois > 27 && mois == 1))
	{
		mois+=jourDuMois/28;
		jourDuMois%=31;
	}
	else if(jourDuMois<0 && mois==2)
	{
		jourDuMois=-jourDuMois;
		mois-=((jourDuMois/28)+1);
		jourDuMois%=28;
		jourDuMois = 28-jourDuMois;
	}


	if((jourDuMois > 29 && (mois == 3 || mois == 5 || mois == 8 || mois == 10)))
	{
		mois+=jourDuMois/30;
		jourDuMois%=31;
	}
	else if(jourDuMois<0 && (mois==4 || mois==6 || mois==9 || mois==11))
	{
		jourDuMois=-jourDuMois;
		mois-=((jourDuMois/30)+1);
		jourDuMois%=30;
		jourDuMois=30-jourDuMois;
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
		mois-=((jourDuMois/31)+1);
		jourDuMois%=31;
		jourDuMois=31-jourDuMois;
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
		mois=12-mois;
	}

	return *this;
}

void Date::afficheDate()
{
	cout << annee <<" "<<mois << " " << jourDuMois << " " << heure << " " << minute << " " << seconde;

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

	// TODO secondeannee
}

Date::Date(const Date &dateACopier)
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
