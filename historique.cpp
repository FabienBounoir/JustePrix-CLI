#include "historique.h"

Historique::Historique()
{
}

Historique::~Historique()
{
}

void Historique::ajouter(int nbCoups, string nom)
{
    this->scoreHistorique.push_back(make_pair(nbCoups, nom));
}

vector<pair<int,string> > Historique::getHistorique()
{
    return scoreHistorique;
}

bool Historique::enregistrerAncienCoups(int prix)
{
    if(find(this->ancienCoups.begin(), this->ancienCoups.end(), prix ) != this->ancienCoups.end())
    {
        return false;
    }
    else
    {
        this->ancienCoups.push_back(prix);
        return true;
    }
}

void Historique::initialiserAncienCoups()
{
    ancienCoups.clear();
}