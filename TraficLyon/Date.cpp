/*************************************************************************
       Date  -  implementation de la Date decrite dans Date.h
                             -------------------
    début                : 07/11/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/

//---------- Réalisation de la classe <Date> (fichier Date.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Date.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool Date::EstEgal(Date const &dateAComparer) const
{
	if (dateAComparer.annee == annee  && dateAComparer.jourDeLaSemaine==jourDeLaSemaine
				&& dateAComparer.jourDuMois==jourDuMois && dateAComparer.mois==mois
				&& dateAComparer.heure==heure && dateAComparer.minute==minute
				&& dateAComparer.seconde==seconde)
	{
		return true;
	}
	else
	{
		 return false;
	}
}

bool Date::EstInf(Date const& dateAComparer) const
{
	if(dateAComparer.annee <annee )
	{
		return true;
	}
	else
	{
		if(dateAComparer.mois <mois)
		{
			return true;
		}
		else
		{
			if(dateAComparer.jourDuMois < jourDuMois)
			{
				return true;
			}
			else
			{
				if(dateAComparer.heure < heure)
				{
					return true;
				}
				else
				{
					if(dateAComparer.minute <minute)
					{
						return true;
					}
					else
					{
						if(dateAComparer.seconde <seconde)
						{
							return true;
						}
						else
						{
							return false;
						}
					}
				}
			}
		}
	}
}

Date Date::Additionner(int secondes)
{
	seconde += secondes;

	if(seconde >= NOMBRE_SECONDES_MINUTE)
	{
		minute+=seconde/NOMBRE_SECONDES_MINUTE;
		seconde %= NOMBRE_SECONDES_MINUTE;
	}
	else
	{
		if(seconde < 0)
		{
			seconde = -seconde;
			minute-=(((seconde-1)/NOMBRE_SECONDES_MINUTE)+1);
			seconde %= NOMBRE_SECONDES_MINUTE;
			seconde = (NOMBRE_SECONDES_MINUTE - seconde)%NOMBRE_SECONDES_MINUTE;
		}
	}

	if(minute >= NOMBRE_MINUSTES_HEURE)
	{
		heure+=minute/NOMBRE_MINUSTES_HEURE;
		minute%=NOMBRE_MINUSTES_HEURE;
	}
	else
	{
		if (minute<0)
		{
			minute = -minute;
			heure-=(((minute-1)/NOMBRE_MINUSTES_HEURE)+1);
			minute %= NOMBRE_MINUSTES_HEURE;
			minute = (NOMBRE_MINUSTES_HEURE - minute)%NOMBRE_MINUSTES_HEURE;
		}
	}

	if(heure >= NOMBRE_HEURES_JOURNEE)
	{
		jourDuMois+=heure/NOMBRE_HEURES_JOURNEE;
		jourDeLaSemaine+=heure/NOMBRE_HEURES_JOURNEE;
		jourDeLaSemaine%=NOMBRE_JOURS_SEMAINE;
		heure %=NOMBRE_HEURES_JOURNEE;
	}
	else
	{
		if (heure <0)
		{
			heure = -heure;
			jourDuMois-=(((heure-1)/NOMBRE_HEURES_JOURNEE)+1);
			jourDeLaSemaine-=(((heure-1)/NOMBRE_HEURES_JOURNEE)+1);
			jourDeLaSemaine%=NOMBRE_JOURS_SEMAINE;
			jourDeLaSemaine = (NOMBRE_JOURS_SEMAINE - jourDeLaSemaine)%NOMBRE_JOURS_SEMAINE;
			heure %=NOMBRE_HEURES_JOURNEE;
			heure = (NOMBRE_HEURES_JOURNEE - heure)%NOMBRE_HEURES_JOURNEE;
		}
	}

	if((jourDuMois > (NOMBRE_JOURS_MOIS_28-1) && mois == FEVRIER))
	{
		mois+=jourDuMois/NOMBRE_JOURS_MOIS_28;
		jourDuMois%=NOMBRE_JOURS_MOIS_31;
	}
	else
	{
		if(jourDuMois<JANVIER && mois==MARS)
		{
			jourDuMois=-jourDuMois;
			mois-=(((jourDuMois-1)/NOMBRE_JOURS_MOIS_28)+1);
			jourDuMois%=NOMBRE_JOURS_MOIS_28;
			jourDuMois = (NOMBRE_JOURS_MOIS_28-jourDuMois)%NOMBRE_JOURS_MOIS_28;
		}
	}


	if((jourDuMois > (NOMBRE_JOURS_MOIS_30-1) && (mois == AVRIL || mois ==JUIN
												|| mois == SEPTEMBRE || mois == 10)))
	{
		mois+=jourDuMois/NOMBRE_JOURS_MOIS_30;
		jourDuMois%=NOMBRE_JOURS_MOIS_31;
	}
	else
	{
		if(jourDuMois<0 && (mois==MAI || mois==JUILLET || mois==OCTOBRE || mois==DECEMBRE))
		{
			jourDuMois=-jourDuMois;
			mois-=(((jourDuMois-1)/NOMBRE_JOURS_MOIS_30)+1);
			jourDuMois%=NOMBRE_JOURS_MOIS_30;
			jourDuMois=(NOMBRE_JOURS_MOIS_30-jourDuMois)%NOMBRE_JOURS_MOIS_30;
		}
	}

	if(jourDuMois > (NOMBRE_JOURS_MOIS_31-1) && (mois == JANVIER || mois ==MARS || mois == MAI
									|| mois == JUILLET || mois == AOUT || mois == OCTOBRE
											|| mois==DECEMBRE))
	{
		if(mois!=JUILLET && mois != DECEMBRE && mois!=JANVIER)
		{
			mois+=jourDuMois/NOMBRE_JOURS_MOIS_31;
			jourDuMois%=NOMBRE_JOURS_MOIS_30;
		}
		else
		{
			if(mois!=JANVIER)
			{
				mois+=jourDuMois/NOMBRE_JOURS_MOIS_31;
				jourDuMois%=NOMBRE_JOURS_MOIS_31;
			}
			else
			{
				mois+=jourDuMois/NOMBRE_JOURS_MOIS_31;
				jourDuMois%=NOMBRE_JOURS_MOIS_28;
			}
		}
	}
	else
	{
		if(jourDuMois<0 && (mois==FEVRIER || mois==AVRIL || mois==JUIN || mois==AOUT
									|| mois==SEPTEMBRE || mois==NOVEMBRE || mois==JANVIER))
		{
			jourDuMois=-jourDuMois;
			mois-=(((jourDuMois-1)/NOMBRE_JOURS_MOIS_31)+1);
			jourDuMois%=NOMBRE_JOURS_MOIS_31;
			jourDuMois=(NOMBRE_JOURS_MOIS_31-jourDuMois)%NOMBRE_JOURS_MOIS_31;
		}
	}

	secondesDepuisDebutAnnee += secondes;
	if(mois>DECEMBRE)
	{
		annee++;
		mois%=NOMBRE_MOIS_ANNEE;
	}
	else
	{
		if(mois<0)
		{
			annee--;
			mois=-mois;
			mois%=NOMBRE_MOIS_ANNEE;
			mois=(NOMBRE_MOIS_ANNEE-mois)%NOMBRE_MOIS_ANNEE;
		}
	}

	return *this;
}

int Date::Difference(Date const &dateAEnlever) const
{
	return (secondesDepuisDebutAnnee - dateAEnlever.secondesDepuisDebutAnnee)+(annee - dateAEnlever.annee)
								*NOMBRE_JOURS_ANNEE*NOMBRE_HEURES_JOURNEE*NOMBRE_MINUSTES_HEURE*NOMBRE_SECONDES_MINUTE;
}

void Date::AfficheDateRelle()
{
	cout << annee <<" "
		 << mois+1 << " "
		 << jourDuMois+1 << " "
		 << heure << " "
		 << minute << " "
		 << seconde << " ";
}

void Date::DebugAffichage()
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

//-------------------------------------------- Redéfinition d'opérateurs

bool operator==(Date const &date1, Date const &date2)
{
	return date1.EstEgal(date2);
}

bool operator!=(Date const& date1, Date const& date2)
{
	return !(date1==date2);
}

bool operator<(Date const& date2, Date const &date1)
{
	return date1.EstInf(date2);
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

Date operator+(Date const &date, int secondes)
{
	Date dateAddition(date);
	return dateAddition.Additionner(secondes);
}

int operator-(Date const& date1, Date const& dateAEnlever)
{
	return date1.Difference(dateAEnlever);
}

Date operator-(Date const &date, int secondes)
{
	Date dateSoustraction(date);
	return dateSoustraction.Additionner(-secondes);
}

//-------------------------------------------- Constructeurs - destructeur

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
	int secondesMois30 (NOMBRE_JOURS_MOIS_30*NOMBRE_SECONDES_MINUTE*NOMBRE_MINUSTES_HEURE*NOMBRE_HEURES_JOURNEE);
	int secondesMois31 (NOMBRE_JOURS_MOIS_31*NOMBRE_SECONDES_MINUTE*NOMBRE_MINUSTES_HEURE*NOMBRE_HEURES_JOURNEE);
	int secondesMois28 (NOMBRE_JOURS_MOIS_28*NOMBRE_SECONDES_MINUTE*NOMBRE_MINUSTES_HEURE*NOMBRE_HEURES_JOURNEE);
	switch (mois)
	{
		case FEVRIER:
			secondesMois=secondesMois31;
			break;
		case MARS:
			secondesMois=secondesMois31 + secondesMois28;
			break;
		case AVRIL:
			secondesMois=secondesMois31 *2 + secondesMois28;
			break;
		case MAI:
			secondesMois=secondesMois31 *2 + secondesMois28 + secondesMois30;
			break;
		case JUIN:
			secondesMois=secondesMois31 *3 + secondesMois28 + secondesMois30;
			break;
		case JUILLET:
			secondesMois=secondesMois31 *3 + secondesMois28 + secondesMois30*2;
			break;
		case AOUT:
			secondesMois=secondesMois31 *4 + secondesMois28 + secondesMois30 *2;
			break;
		case SEPTEMBRE:
			secondesMois=secondesMois31 *5 + secondesMois28 + secondesMois30 *2;
			break;
		case OCTOBRE:
			secondesMois=secondesMois31 *5 + secondesMois28 + secondesMois30 *3;
			break;
		case NOVEMBRE:
			secondesMois=secondesMois31 *6 + secondesMois28 + secondesMois30 *3;
			break;
		case DECEMBRE:
			secondesMois=secondesMois31 *6 + secondesMois28 + secondesMois30 *4;
			break;
	}

	secondesDepuisDebutAnnee = seconde + minute*NOMBRE_SECONDES_MINUTE
								+ heure*NOMBRE_SECONDES_MINUTE*NOMBRE_MINUSTES_HEURE
								+ jourDuMois*NOMBRE_SECONDES_MINUTE*NOMBRE_MINUSTES_HEURE*NOMBRE_HEURES_JOURNEE
								+ secondesMois;
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


//------------------------------------------------------------------ PRIVE

//------------------------------------------------------- Méthodes privées
