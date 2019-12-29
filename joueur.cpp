
#include "joueur.h"

Joueur::Joueur(string nom):nom(nom)
{
}

Joueur::~Joueur()
{
}

string Joueur::getNom() const
{
    return nom;
}

void Joueur::setNom(string nom)
{
	this->nom = nom;
}
