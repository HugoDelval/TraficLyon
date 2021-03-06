/*************************************************************************
       PreStockageMax  -  implementation de PreStockageMax decrit dans GestionMax.h
                             -------------------
    d�but                : 07/11/2014
    copyright            : (C) 2014 par PAPIN/DELVAL
*************************************************************************/
//-----R�alisation de la classe <GestionMax> (fichier GestionMax.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

//------------------------------------------------------ Include personnel
#include "GestionMax.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
void GestionMax::Ajouter(int idTableau, int traficEvenement, Date dateEvenement)
{
	/* insertion dans les listes de date et evenements en faisant attention aux capteurs n'ayant pas agit les 5min precedentes */
	if(root == NULL)
	{
		root=new ElementDate();
		root->dateAretenir=dateEvenement;
		root->suivant=NULL;
		root->precedent=NULL;
	}
	else
	{
		if(tabListeDate[idTableau]!=NULL && (dateEvenement - tabListeDate[idTableau]->dateEvenement->dateAretenir) > NOMBRE_SECONDES_MINUTE*5)
		{
			Date dateIntermediaire = tabListeDate[idTableau]->dateEvenement->dateAretenir + NOMBRE_SECONDES_MINUTE*5 +1;
			ElementDate *e= tabListeDate[idTableau]->dateEvenement;
			while (e->suivant != NULL && e->suivant->dateAretenir > dateIntermediaire)
			{
				e=e->suivant;
			}
			if(e->suivant!=NULL)
			{
				if(e->suivant->dateAretenir != dateIntermediaire)
				{
					ElementDate *suivant = e->suivant;
					ElementDate *precedent = e;
					ElementDate *elementAInserer=new ElementDate();
					elementAInserer->dateAretenir=dateIntermediaire;
					elementAInserer->suivant = suivant;
					elementAInserer->precedent=precedent;
					elementAInserer->suivant->precedent = elementAInserer;
					if(elementAInserer->precedent != NULL)
					{
						elementAInserer->precedent->suivant = elementAInserer;
					}
				}
			}
			else
			{
				ElementDate *precedent = e->precedent;
				ElementDate *elementAInserer=new ElementDate();
				elementAInserer->dateAretenir=dateIntermediaire;
				elementAInserer->suivant = NULL;
				elementAInserer->precedent=precedent;
				if(elementAInserer->precedent != NULL)
				{
					elementAInserer->precedent->suivant = elementAInserer;
				}
			}
		}
		if(root->dateAretenir != dateEvenement)
		{
			ElementDate *eleAInserer = new ElementDate();
			eleAInserer->dateAretenir=dateEvenement;
			eleAInserer->suivant = root;
			eleAInserer->precedent=NULL;
			if(root != NULL)
			{
				root->precedent = eleAInserer;;
			}
			root = eleAInserer;
		}
	}
	if(tabListeDate[idTableau] == NULL)
	{
		tabListeDate[idTableau] = new ElementEvenement();
		tabListeDate[idTableau]->dateEvenement=root;
		tabListeDate[idTableau]->trafic=traficEvenement;
		tabListeDate[idTableau]->suivant=NULL;
		tabListeDate[idTableau]->precedent=NULL;
	}
	else
	{
		ElementEvenement *elementAInserer = new ElementEvenement();
		elementAInserer->dateEvenement=root;
		elementAInserer->trafic=traficEvenement;
		elementAInserer->suivant = tabListeDate[idTableau];
		elementAInserer->precedent=NULL;
		if(tabListeDate[idTableau] != NULL)
		{
			tabListeDate[idTableau]->precedent = elementAInserer;
		}
		tabListeDate[idTableau] = elementAInserer;
	}
}


void GestionMax::AfficherMax()
{
	for(int i=0 ; i<NOMBRE_MAX_CAPTEURS ; i++)
	{
		if(tabListeDate[i] != NULL && tabListeDate[i]->dateEvenement->dateAretenir != root->dateAretenir)
		{
			ElementEvenement *elementAInserer = new ElementEvenement();
			elementAInserer->dateEvenement=root;
			elementAInserer->trafic=0;
			elementAInserer->suivant = tabListeDate[i];
			elementAInserer->precedent=NULL;
			if(tabListeDate[i] != NULL)
			{
				tabListeDate[i]->precedent = elementAInserer;
			}
			tabListeDate[i] = elementAInserer;
		}
	}
	ElementDate *e=root;
	ElementDate *dateAPartirDeLaquelleOnPeutSupprimer = root;
	ElementEvenement *eAConsiderer;
	if(root != NULL)
	{
		dateMax = root->dateAretenir;
		float secondesTot=0.0;
		float secondesBouchon=0.0;
		while (e != NULL)
		{
			for(int i=0 ; i<NOMBRE_MAX_CAPTEURS ; i++)
			{
				eAConsiderer = trouverEInteressant(e->dateAretenir,i);
				if(eAConsiderer!=NULL && eAConsiderer->suivant!=NULL)
				{
					if(eAConsiderer->suivant->trafic != AUCUNE_DONNEE)
					{
						int secondesAAjouter = max5minutes(eAConsiderer->dateEvenement->dateAretenir-e->dateAretenir);
						secondesTot+=secondesAAjouter;
						if(eAConsiderer->suivant->trafic == NOIR || eAConsiderer->suivant->trafic == ROUGE)
						{
							secondesBouchon+=secondesAAjouter;
						}
					}
				}
			}
			if(secondesBouchon/secondesTot>=maxBouchon)
			{
				maxBouchon = secondesBouchon/secondesTot;
				dateMax = e->dateAretenir;
			}
			secondesTot=0.0;
			secondesBouchon=0.0;

			e=e->suivant;
			while(dateAPartirDeLaquelleOnPeutSupprimer != NULL && dateAPartirDeLaquelleOnPeutSupprimer->suivant != NULL && dateAPartirDeLaquelleOnPeutSupprimer->suivant->dateAretenir + (5*NOMBRE_SECONDES_MINUTE+1) >= dateMax)
			{
				dateAPartirDeLaquelleOnPeutSupprimer = dateAPartirDeLaquelleOnPeutSupprimer->suivant;
			}
		}
		//supprimerToutApres(dateMax-(5*NOMBRE_SECONDES_MINUTE +1));


		dateMax.AfficheDateRelle();
		cout << (int)(maxBouchon*100) << "%"
			 << "\r\n";
		for(int i=0 ; i<NOMBRE_MAX_CAPTEURS ; i++)
		{
			if(tabListeDate[i] != NULL && tabListeDate[i]->trafic==0)
			{
				ElementEvenement *elementASupprimer = tabListeDate[i];
				tabListeDate[i]=tabListeDate[i]->suivant;
				delete elementASupprimer;
			}
		}
	}
	else
	{
		dateMax.AfficheDateRelle();
		cout << (int)(maxBouchon*100) << "%"
			 << "\r\n";
	}


}

void GestionMax::AfficheListes()
{
	cout<<"Listes Tableau :"<<endl;
	for(int i=0;i<1500;i++)
	{
		if(tabListeDate[i]!=NULL)
		{
			cout<<"id:"<<i<<endl;
			ElementEvenement *e=tabListeDate[i];
			while (e != NULL)
			{
				e->dateEvenement->dateAretenir.AfficheDateRelle();
				cout<<" trafic:"<<e->trafic<<endl;
				e=e->suivant;
			}
		}
	}
	cout<<"Liste Date :"<<endl;
	ElementDate *e=root;
	while (e != NULL)
	{
		e->dateAretenir.AfficheDateRelle();
		cout<<endl;
		e=e->suivant;
	}
}


//----------------------------------------------------- Constructeurs - destructeur
GestionMax::GestionMax()
{
	tabListeDate = new ElementEvenement*[NOMBRE_MAX_CAPTEURS];
	for(int i(0) ; i<NOMBRE_MAX_CAPTEURS ; i++)
	{
		tabListeDate[i]=NULL;
	}
	root = NULL;
	maxBouchon=0.0;
}

GestionMax::~GestionMax()
{
	supprimerToutApres(root->dateAretenir);
	delete[] tabListeDate;

}

//------------------------------------------------------------------ PRIVE

//------------------------------------------------------- M�thodes priv�es

ElementEvenement* GestionMax::trouverEInteressant(Date dateACalculer, int idTableau)
{
	ElementEvenement *res = tabListeDate[idTableau];
	while(res != NULL && res->suivant != NULL && res->suivant->dateEvenement->dateAretenir > dateACalculer)
	{
		res=res->suivant;
	}
	return res;
}

int GestionMax::max5minutes(int nombreSecondes)
{
	if(nombreSecondes <= 5*NOMBRE_SECONDES_MINUTE)
	{
		return nombreSecondes;
	}
	return 5*NOMBRE_SECONDES_MINUTE;
}

void GestionMax::supprimerToutApres(Date dateDebutSuppression)
{
	ElementDate *e1= root;
	bool estRoot=true;
	while (e1 != NULL && e1->dateAretenir>dateDebutSuppression)
	{
		estRoot=false;
		e1=e1->suivant;
	}
	if(e1 != NULL && e1->precedent != NULL)
	{
		e1->precedent->suivant=NULL;
	}
	if(estRoot)
	{
		root=NULL;
	}
	ElementDate *aSup1;
	while (e1 != NULL)
	{
		aSup1 = e1;
		e1=e1->suivant;
		delete aSup1;
	}
	ElementEvenement *e;
	ElementEvenement *aSup;
	for(int i=0 ; i<NOMBRE_MAX_CAPTEURS ; i++)
	{
		e= tabListeDate[i];
		estRoot=true;
		while (e != NULL && e->dateEvenement->dateAretenir>dateDebutSuppression)
		{
			estRoot=false;
			e=e->suivant;
		}
		if(e != NULL && e->precedent != NULL)
		{
			e->precedent->suivant=NULL;
		}
		if(estRoot)
		{
			tabListeDate[i]=NULL;
		}
		while (e != NULL)
		{
			aSup = e;
			e=e->suivant;
			delete aSup;
		}
	}
}

