/*************************************************************************
    GestionTrafic  -  implementation de GestionTrafic decrit dans GestionTrafic.h
                             -------------------
    début                : 24/10/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/

//---------- Réalisation de la classe <GestionTrafic> (fichier GestionTrafic.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "GestionTrafic.h"

//------------------------------------------------------------- Constantes


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

int main()
{
	GestionTrafic g;
	g.Start();

	return 0;
}


void GestionTrafic::Start()
{
	string commande="";
	int typeCommande=-1;
	bool sortir = false;
	while(!sortir)
	{
		typeCommande=-1;
		getline(cin,commande);
		typeCommande = determineTypeCommande(commande);
		switch(typeCommande)
		{
			case COMMANDE_ADD:
			{
				size_t mot0 = commande.find(' ')+1;
				size_t mot1 = commande.find(' ', mot0+1)+1;
				size_t mot2 = commande.find(' ',mot1+1)+1;
				size_t mot3 = commande.find(' ',mot2+1)+1;
				size_t mot4 = commande.find(' ',mot3+1)+1;
				size_t mot5 = commande.find(' ',mot4+1)+1;
				size_t mot6 = commande.find(' ',mot5+1)+1;
				size_t mot7 = commande.find(' ',mot6+1)+1;
				size_t mot8 = commande.find(' ',mot7+1)+1;
				appelerAjouter(
						commande.substr(mot0,mot1-mot0-1),
						commande.substr(mot1,mot2-mot1-1),
						commande.substr(mot2,mot3-mot2-1),
						commande.substr(mot3,mot4-mot3-1),
						commande.substr(mot4,mot5-mot4-1),
						commande.substr(mot5,mot6-mot5-1),
						commande.substr(mot6,mot7-mot6-1),
						commande.substr(mot7,mot8-mot7-1),
						commande.substr(mot8,1)/*juste un caractere (V,R,N...)*/
						);
				break;
			}
			case COMMANDE_STATS_C:
			{
				size_t mot0 = commande.find(' ')+1;
				appelerStatistiquesCapteur(commande.substr(mot0,commande.length()-mot0-1));
				break;
			}
			case COMMANDE_STATS_D7:
			{
				size_t mot0 = commande.find(' ')+1;
				appelerStatistiquesJourSemaine(commande.substr(mot0,commande.length()-mot0-1));
				break;
			}
			case COMMANDE_STATS_D7_H24:
			{
				size_t mot0 = commande.find(' ')+1;
				size_t mot1 = commande.find(' ',mot0+1)+1;
				appelerStatistiquesJourHeureSemaine(
						commande.substr(mot0,mot1-mot0-1),
						commande.substr(mot1,commande.length()-mot1-1)
				);
				break;
			}
			case COMMANDE_MAX_TS:
			{
				appelerMaxBouchonsSimultanes();
				break;
			}
			case COMMANDE_EXIT:
			{
				sortir = true;
				break;
			}
			default:
			{
				//erreur de commande, on recommence
				break;
			}
		}
	}
}


//-------------------------------------------- Constructeurs - destructeur

GestionTrafic::GestionTrafic()
{
	toutLeTrafic = new Evenements();
}

GestionTrafic::~GestionTrafic()
{

}

//------------------------------------------------------------------ PRIVE

//------------------------------------------------------- Méthodes privées

void GestionTrafic::appelerAjouter(string idCapteurReel,string annee, string mois, string jourDuMois,
				string heure, string minute, string seconde, string jourDeLaSemaine, string trafic)
{
	int idCapteurR = atoi(idCapteurReel.c_str());
	int idCapteurTableau = toutLeTrafic->AjouterIdAArbre(idCapteurR);
	if(idCapteurTableau != -1)
	{
		int anneeFinale = atoi(annee.c_str());
		int moisFinal = atoi(mois.c_str());
		int jourDuMoisFinal = atoi(jourDuMois.c_str());
		int heureFinale = atoi(heure.c_str());
		int minuteFinale = atoi(minute.c_str());
		int secondeFinale = atoi(seconde.c_str());
		int jourDeLaSemaineFinale = atoi(jourDeLaSemaine.c_str());
		int traficFinal = 0; // <=> capteur inactif
		if(trafic.compare("V")==0)
		{
			traficFinal=1;
		}
		else
		{
			if(trafic.compare("J")==0)
			{
				traficFinal=2;
			}
			else
			{
				if(trafic.compare("R")==0)
				{
					traficFinal=3;
				}
				else
				{
					if(trafic.compare("N")==0)
					{
						traficFinal=4;
					}
				}
			}
		}
		toutLeTrafic->AjouterEvenement(idCapteurTableau,heureFinale,jourDeLaSemaineFinale-1,traficFinal,
											   anneeFinale,moisFinal-1,jourDuMoisFinal-1,minuteFinale,secondeFinale);
		//toutLeTrafic->afficherTousLesEvenements();  // Pour les tests
	}
	else //il y a une erreur dans l'insertion
	{
		cout<<"erreur arbreIdentifiants"<<endl;
	}
}

void GestionTrafic::appelerStatistiquesCapteur(string idCapteurReel)
{
	int idCapteurR = atoi(idCapteurReel.c_str());
	toutLeTrafic->StatistiquesCapteur(idCapteurR);
}

void GestionTrafic::appelerStatistiquesJourSemaine(string nJour)
{
	int jourDeLaSemaineFinale = atoi(nJour.c_str());
	toutLeTrafic->StatistiquesJourSemaine(jourDeLaSemaineFinale-1);
}

void GestionTrafic::appelerStatistiquesJourHeureSemaine(string nJour, string heure)
{
	int jourDeLaSemaineFinale = atoi(nJour.c_str());
	int heureFinale = atoi(heure.c_str());
	toutLeTrafic->StatistiquesJourHeureSemaine(jourDeLaSemaineFinale-1, heureFinale);
}

void GestionTrafic::appelerMaxBouchonsSimultanes()
{
	toutLeTrafic->MaxBouchonsSimultanes();
}


int GestionTrafic::determineTypeCommande(const string &commande)
{
	int res =-1;
	if(commande.find("ADD")==0)
	{
		res=COMMANDE_ADD;
	}
	else
	{
		if(commande.find("STATS_C")==0)
		{
		res=COMMANDE_STATS_C;
		}
		else
		{
			if(commande.find("STATS_D7_H24")==0)
			{
				res=COMMANDE_STATS_D7_H24;
			}
			else
			{
				if(commande.find("STATS_D7")==0)
				{
					res=COMMANDE_STATS_D7;
				}
				else
				{
					if(commande.find("MAX_TS")==0)
					{
						res=COMMANDE_MAX_TS;
					}
					else
					{
						if(commande.find("EXIT")==0)
						{
							res=COMMANDE_EXIT;
						}
					}
				}
			}
		}
	}
	return res;
}
