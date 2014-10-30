/*
 * GestionTrafic.cpp
 *
 *  Created on: 24 oct. 2014
 *      Author: Hugo
 */

#include "GestionTrafic.h"

GestionTrafic::GestionTrafic()
{
	toutLeTrafic = new Evenements();
}

GestionTrafic::~GestionTrafic()
{

}


void GestionTrafic::appelerAjouter(string idCapteurReel,string annee, string mois, string jourDuMois,
				string heure, string minute, string seconde, string jourDeLaSemaine, string trafic)
{
/*
	cout<<"appel de ajouter avec :"<<endl;
	cout<<"idCapteurReel= '"<<idCapteurReel<<"'"<<endl;
	cout<<"annee= '"<<annee<<"'"<<endl;
	cout<<"mois= '"<<mois<<"'"<<endl;
	cout<<"jourDuMois= '"<<jourDuMois<<"'"<<endl;
	cout<<"heure= '"<<heure<<"'"<<endl;
	cout<<"minute= '"<<minute<<"'"<<endl;
	cout<<"seconde= '"<<seconde<<"'"<<endl;
	cout<<"jourDeLaSemaine= '"<<jourDeLaSemaine<<"'"<<endl;
	cout<<"trafic= '"<<trafic<<"'"<<endl;
	cout<<endl;*/
	int idCapteurR = atoi(idCapteurReel.c_str());

	int idCapteurTableau = toutLeTrafic->ajouterIdAArbre(idCapteurR);
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
		else if(trafic.compare("J")==0)
		{
			traficFinal=2;
		}
		else if(trafic.compare("R")==0)
		{
			traficFinal=3;
		}
		else if(trafic.compare("N")==0)
		{
			traficFinal=4;
		}
		toutLeTrafic->ajouterEvenement(idCapteurTableau,heureFinale,jourDeLaSemaineFinale,traficFinal,
								anneeFinale,moisFinal,jourDuMoisFinal,minuteFinale,secondeFinale);

		toutLeTrafic->afficherTousLesEvenements();  // Pour les tests
	}
	else //il y a une erreur dans l'insertion
	{
		cout<<"erreur arbreIdentifiants"<<endl;
	}
}
void GestionTrafic::appelerStatistiquesCapteur(string idCapteurReel)
{
	/*cout<<"appel stat capteur :"<<endl;
	cout<<"idCapteurReel= '"<<idCapteurReel<<"'"<<endl;
	cout<<endl;*/
	int idCapteurR = atoi(idCapteurReel.c_str());
}
void GestionTrafic::appelerStatistiquesJourSemaine(string nJour)
{
	/*cout<<"appel stat jour Semaine :"<<endl;
	cout<<"nJour= '"<<nJour<<"'"<<endl;
	cout<<endl;*/
	int jourDeLaSemaineFinale = atoi(nJour.c_str());
}
void GestionTrafic::appelerStatistiquesJourHeureSemaine(string nJour, string heure)
{
	/*cout<<"appel stat JourSemaine + heure :"<<endl;
	cout<<"nJour= '"<<nJour<<"'"<<endl;
	cout<<"heure= '"<<heure<<"'"<<endl;
	cout<<endl;*/
	int jourDeLaSemaineFinale = atoi(nJour.c_str());
	int heureFinale = atoi(heure.c_str());
}
void GestionTrafic::appelerMaxBouchonsSimultanes()
{
/*	cout<<"Appel max bouchons"<<endl;
	cout<<endl;*/
}

void GestionTrafic::start()
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

int GestionTrafic::determineTypeCommande(const string &commande)
{
	int res =-1;
	if(commande.find("ADD")==0)
	{
		res=COMMANDE_ADD;
	}
	else if(commande.find("STATS_C")==0)
	{
		res=COMMANDE_STATS_C;
	}
	else if(commande.find("STATS_D7_H24")==0)
	{
		res=COMMANDE_STATS_D7_H24;
	}
	else if(commande.find("STATS_D7")==0)
	{
		res=COMMANDE_STATS_D7;
	}
	else if(commande.find("MAX_TS")==0)
	{
		res=COMMANDE_MAX_TS;
	}
	else if(commande.find("EXIT")==0)
	{
		res=COMMANDE_EXIT;
	}
	return res;
}

int main()
{
	GestionTrafic g;
	g.start();

	return 0;
}
