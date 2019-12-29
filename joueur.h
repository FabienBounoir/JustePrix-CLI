#ifndef JOUEUR_H
#define JOUEUR_H

#include <cstring>
#include <iostream>

using namespace std;

class Joueur
{
    private:
        string nom;

    public:
        Joueur(string nom="");
        ~Joueur();

        void setNom(string nom);
        string getNom() const;
};

#endif //JOUEUR_H
