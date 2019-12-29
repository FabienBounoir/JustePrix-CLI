#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

#include "justePrix.h"

//#define CHEAT

JustePrix::JustePrix():prixMystere(0), prixMin(1), prixMax(100), nbCoups(0)
{
    joueur = new Joueur();
    historique = new Historique();
    meilleurScore = new MeilleurScore();
    srand(time(NULL));
}

JustePrix::~JustePrix()
{
    delete joueur;
    delete historique;
    delete meilleurScore;
}
        
int JustePrix::getPrixMystere() const
{
    return prixMystere;
}

int JustePrix::getNbCoups() const
{
    return nbCoups;
}

int JustePrix::getPrixMin() const
{
    return prixMin;
}

int JustePrix::getPrixMax() const
{
    return prixMax;
}
        
void JustePrix::setPrixMystere(int prixMystere)
{
    this->prixMystere = prixMystere;
}

void JustePrix::setNbCoups(int nbCoups)
{
    this->nbCoups = nbCoups;
}

void JustePrix::setPrixMax(int prixMax)
{
    this->prixMax = prixMax;
}

void JustePrix::creerPrixMystere()
{
    setPrixMystere(rand() % getPrixMax() + getPrixMin());
}

void JustePrix::compterNbCoups(int prix)
{
    if(historique->enregistrerAncienCoups(prix))
    {
        if(prix > getPrixMax())
        {
            ihm->AfficherPrixSupBorne(prix, this->getPrixMax());
        }
        else if(prix < getPrixMin())
        {
            ihm->AfficherPrixInfBorne(prix, this->getPrixMin());
        }
        else
        {
            ++nbCoups;
        }       
    }
}

bool JustePrix::verifierPrix(int prix, int prixMystere)
{
    #ifdef CHEAT
        cout << endl;
        cout << "\033[1;34mCHEAT [prix = " <<  getPrixMystere( ) << "]\033[0m" << endl;
    #endif
    
    this->compterNbCoups(prix);

    if(prix < prixMystere)
    {
        ihm->afficherPrixMystereSuperieur();
        return true;
    }
    else if(prix > prixMystere)
    {
        ihm->afficherPrixMystereInferieur();
        return true;
    }
    else
    {
        ihm->afficherVictoire(nbCoups, joueur->getNom());
        return false;
    }
}

void JustePrix::recupererNom()
{
    joueur->setNom(ihm->demanderNom());  
}

void JustePrix::ChoisirDifficulte()
{
    char choix;
    do{
        choix = ihm->demanderDifficulte(joueur->getNom());
        if(choix == 'd' || choix == 'D')
        {
            this->setPrixMax(1000);
            meilleurScore->choisirFichierDifficulte(this->getPrixMax());
            this->creerPrixMystere();
        }
        else if(choix == 'm' || choix == 'M')
        {
            this->setPrixMax(500);
            meilleurScore->choisirFichierDifficulte(this->getPrixMax());
            this->creerPrixMystere();
        }
        else if(choix == 'f' || choix == 'F')
        {
            this->setPrixMax(100);
            meilleurScore->choisirFichierDifficulte(this->getPrixMax());
            this->creerPrixMystere();
        }
        else
        {
            cerr << "Désolé, cette difficulté n'existe pas" <<endl;
        }
    }
    while(choix != 'd' && choix != 'D' && choix != 'm' && choix != 'M' && choix != 'f' && choix != 'F');
}

void JustePrix::ChoisirMenu()
{
    char choixMenu = 0;
    do{
        choixMenu = ihm->afficherMenu();
        if(choixMenu == 'R' || choixMenu == 'r')
        {
            meilleurScore->remettreAZeroScore();
            this->jouerNouvellePartie();
        }
        else if(choixMenu == 'M' || choixMenu == 'm')
        {
            ihm->afficherMeilleursScores(meilleurScore->getFichierDifficulte());
            ihm->afficherPositionScore(meilleurScore->calculerPositionClassement(this->getNbCoups()));
        }
        else if(choixMenu == 'H' || choixMenu == 'h')
        {
            ihm->afficherHistorique(historique->getHistorique());
        }
        else if(choixMenu == 'Q' || choixMenu == 'q')
        {
            ihm->arreterJeu(joueur->getNom());
        }
        else
        {
            cerr << "Désoler ce choix n'est Disponible" <<endl;
        }
    }
    while(choixMenu != 'R' && choixMenu != 'r' && choixMenu != 'Q' && choixMenu != 'q');
}

void JustePrix::calculerTemps(int chronometre)
{
    int heure = chronometre / 3600;
    int minute = chronometre / 60;
    int seconde = chronometre % 60;
    ihm->afficherChronometre(heure, minute, seconde);
}

void JustePrix::demarrer()
{
    this->setNbCoups(0);
    ihm->afficherIntroduction(this->getPrixMin());
    this->recupererNom();
    this->ChoisirDifficulte();
    ihm->afficherBornes(this->getPrixMin(), this->getPrixMax());
    meilleurScore->recupererScore();
    this->jouer();
}

void JustePrix::jouerNouvellePartie()
{
    this->setNbCoups(0);
    historique->initialiserAncienCoups();
    ihm->afficherIntroduction(this->getPrixMin());
    this->ChoisirDifficulte();
    ihm->afficherBornes(this->getPrixMin(), this->getPrixMax());
    meilleurScore->recupererScore();
    this->jouer(); 
}

void JustePrix::jouer()
{
    int prix = 0;
    time_t debutChrono = time(NULL);
    do
    {
        prix = ihm->demanderPrix(joueur->getNom());
    }
    while(this->verifierPrix(prix, prixMystere));
    int chronometre = (int)time(NULL) - debutChrono;
    this->calculerTemps(chronometre);
    historique->ajouter(this->getNbCoups(), joueur->getNom());
    meilleurScore->sauvegarderScore(this->getNbCoups(), joueur->getNom());
    this->ChoisirMenu();
}