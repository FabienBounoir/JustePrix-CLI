#ifndef JUSTEPRIX_H
#define JUSTEPRIX_H

#include <iostream>

#include "ihm.h"
#include "joueur.h"
#include "historique.h"
#include "meilleurScore.h"

class Ihm;
class Joueur;
class Historique;
class MeilleurScore;

class JustePrix
{
    private:
        int prixMystere;
        const int prixMin;
        int prixMax;
        int nbCoups;

        void creerPrixMystere();

        Ihm *ihm;
        Joueur *joueur;
        Historique *historique;
        MeilleurScore *meilleurScore;

    public:
        JustePrix();
        ~JustePrix();
        
        void recupererNom();
        bool verifierPrix(int prix, int prixMystere);
        void demarrer();
        void jouer();
        void jouerNouvellePartie();
        void ChoisirDifficulte();
        void ChoisirMenu();
        void calculerTemps(int chronometre);
        void compterNbCoups(int prix);
        
        int getPrixMystere() const;
        int getNbCoups() const;
        int getPrixMin() const;
        int getPrixMax() const;
        void setPrixMystere(int prixMystere);
        void setNbCoups(int nbCoups);
        void setPrixMax(int prixMax);
};

#endif //JUSTEPRIX_H
