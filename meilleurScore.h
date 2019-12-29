#ifndef MEILLEURSCORE_H
#define MEILLEURSCORE_H

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class MeilleurScore
{
    private:
        vector<pair<int,string> > donneeFichier;
        string nomFichier;

    public:
        MeilleurScore();
        ~MeilleurScore();

        int calculerPositionClassement(int score);
        void recupererScore();
        void sauvegarderScore(int nbCoups, string nom);
        void remettreAZeroScore();

        string getFichierDifficulte();
        void choisirFichierDifficulte(int difficulte);
};

#endif //MEILLEURSCORE_H
