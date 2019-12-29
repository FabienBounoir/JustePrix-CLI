#ifndef HISTORIQUE_H
#define HISTORIQUE_H

#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

class Historique
{
    private:
        vector<pair<int,string> > scoreHistorique;
        vector<int> ancienCoups;

    public:
        Historique();
        ~Historique();

        void ajouter(int nbCoups, string nom);
        vector<pair<int,string> > getHistorique();
        bool enregistrerAncienCoups(int prix);
        void initialiserAncienCoups();
};

#endif //HISTORIQUE_H
