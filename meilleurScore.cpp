#include "meilleurScore.h"

#include <fstream>
#include <sstream>
#include <algorithm>

MeilleurScore::MeilleurScore()
{
}

MeilleurScore::~MeilleurScore()
{
}

string MeilleurScore::getFichierDifficulte()
{
    return nomFichier;
}

void MeilleurScore::choisirFichierDifficulte(int difficulte)
{
    switch(difficulte)
    {
        case 100:
            {
                this->nomFichier = "./scoreFacile.txt";
            }
            break;
         case 500:
            {
                this->nomFichier = "./scoreMoyen.txt";
            }
            break;
        case 1000:
            {
                this->nomFichier = "./scoreDifficile.txt";
            }
            break;

    }
}

int MeilleurScore::calculerPositionClassement(int score)
{
    string ligneFichierScore;
    ifstream fichierScore(this->getFichierDifficulte().c_str());
    int scoreFichier = 0;
    int classement = 0; 

    while(getline(fichierScore, ligneFichierScore)) 
    {
        stringstream convert(ligneFichierScore); 
        convert >> scoreFichier; 

        if(scoreFichier <= score)
        {
            ++classement;
        } 
    }
    return classement;
}

void MeilleurScore::recupererScore()  
{
    string ligneFichierScore;
    ifstream fichierScore(this->getFichierDifficulte().c_str());
    int score = 0;

    while(getline(fichierScore, ligneFichierScore)) 
    {
        string recuperationScore = ligneFichierScore;
        stringstream convert(recuperationScore); 
        convert >> score;

        this->donneeFichier.push_back(make_pair(score, ligneFichierScore));
    }
}

void MeilleurScore::sauvegarderScore(int nbCoups, string nom)
{
    string ligneFichierScore;
    ofstream fichierScore(this->getFichierDifficulte().c_str());
    
    stringstream stringNbCoups;
    stringNbCoups << nbCoups;

    string creationScore = stringNbCoups.str() + " " + nom;
    this->donneeFichier.push_back(make_pair(nbCoups, creationScore));
    sort(donneeFichier.begin(), donneeFichier.end());

    for(unsigned int i=0;i < donneeFichier.size(); i++)
    {
        fichierScore << donneeFichier[i].second << endl;
    }
}

void MeilleurScore::remettreAZeroScore()
{
    donneeFichier.clear();
}
