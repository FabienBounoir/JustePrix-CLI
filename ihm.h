#ifndef IHM_H
#define IHM_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

class Ihm
{
    public:
        Ihm();
        ~Ihm();

        void afficherIntroduction(int min);
        string demanderNom();
        int demanderPrix(string nom);
        void afficherPrixMystereInferieur();
        void afficherPrixMystereSuperieur();
        void afficherVictoire(int nbCoups, string nom);
        void afficherBornes(int min, int max);
        void AfficherPrixSupBorne(int prix, int max);
        void AfficherPrixInfBorne(int prix, int min);
        char demanderDifficulte(string nom);
        char afficherMenu();
        void arreterJeu(string nom);
        void afficherHistorique(vector<pair<int,string> > scoreHistorique);
        void afficherMeilleursScores(string nomFichier);
        void afficherPositionScore(int classement);
        void afficherChronometre(int heure, int minute, int seconde);
};

#endif //IHM_H
