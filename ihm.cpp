#include "ihm.h"

#include <unistd.h>

Ihm::Ihm()
{
}

Ihm::~Ihm()
{
}

void Ihm::afficherIntroduction(int min)
{
    system("clear");
    cout <<"\033[1;31m     ___  __   __  _______  _______  _______  _______  ______    ___   __   __  "<<endl;
    cout <<"    |   ||  | |  ||       ||       ||       ||       ||    _ |  |   | |  |_|  | "<<endl;
    cout <<"    |   ||  | |  ||  _____||_     _||    ___||    _  ||   | ||  |   | |       | "<<endl;
    cout <<"    |   ||  |_|  || |_____   |   |  |   |___ |   |_| ||   |_||_ |   | |       | "<<endl;
    cout <<" ___|   ||       ||_____  |  |   |  |    ___||    ___||    __  ||   |  |     |  "<<endl;
    cout <<"|       ||       | _____| |  |   |  |   |___ |   |    |   |  | ||   | |   _   | "<<endl;
    cout <<"|_______||_______||_______|  |___|  |_______||___|    |___|  |_||___| |__| |__| \033[0m\n"<<endl;
    cout << endl;
    cout << "[version du logiciel : \033[1;36m3.2\033[0m]" << endl;
    cout << endl;    
    cout << "Le jeu du juste prix est un jeu où un nombre est choisi aléatoirement entre deux "<<endl;
    cout << "bornes et le joueur doit le deviner en un minimum d’essais. A chaque essai, si  "<<endl;
    cout << "le nombre n’est pas le bon, on indique au joueur si celui recherché est supérieur "<<endl;
    cout << "ou inférieur à celui énoncé." << endl;
    cout << endl;
    cout << "Les bornes seront comprises entre \033[1;36m" << min <<"\033[0m et\033[1;36m 100/500/1000\033[0m (Suivant la difficulté)" << endl;
    cout << endl;
}

string Ihm::demanderNom()
{
    string nom;
    cout << "Entrez votre nom : \033[1;31m"<< endl;
    cin >> nom;
    cout << "\033[0m";
    return nom;
}
        
int Ihm::demanderPrix(string nom)
{
    int prix = 0;
    cout <<endl;
    cout << nom << ", Entrez un prix : "<< endl;
    cin >> prix;
    while(cin.fail())
    {
        cout << "Entrez un prix : "<< endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> prix;
    }
    return prix;
}

void Ihm::afficherPrixMystereInferieur()
{
    cout << "C'est \033[1;33mmoins !\033[0m"<< endl;
}

void Ihm::afficherPrixMystereSuperieur()
{
    cout << "C'est \033[1;32mplus !\033[0m"<< endl;
}

void Ihm::afficherVictoire(int nbCoups, string nom)
{
    cout << endl;
    cout << "\033[1;31mBravo "<< nom <<" !\033[0m Vous avez gagné en \033[1;36m" << nbCoups << " coups \033[0m" << endl;
}

void Ihm::afficherBornes(int min, int max)
{
    cout << endl;
    cout <<"Les bornes sont donc comprises entre \033[1;31m" << min << "\033[0m et \033[1;31m" << max << "\033[0m";
    cout << endl;
}

void Ihm::AfficherPrixSupBorne(int prix, int max)
{
    cout << endl;
    cout << "le prix \033[1;33m" << prix << "\033[0m et supérieur à la borne max = \033[1;33m" << max << "\033[0m" <<endl;
}

void Ihm::AfficherPrixInfBorne(int prix, int min)
{
    cout << endl;
    cout << "le prix \033[1;32m" << prix << "\033[0m et inférieur à la borne min = \033[1;32m" << min << "\033[0m" <<endl;
}

char Ihm::demanderDifficulte(string nom)
{
    char Difficulte = ' ';
    cout << endl;
    cout << nom <<", Choisissez votre difficulté :"<< endl;
    cout << "\033[1;31m[F]\033[0macile (1 à 100)"<< endl;
    cout << "\033[1;31m[M]\033[0moyen (1 à 500)"<< endl;
    cout << "\033[1;31m[D]\033[0mifficile (1 à 1000)"<< endl;
    cout << endl;
    cout << "Entrez une difficulté : \033[1;31m";
    cin >> Difficulte;
    cout << "\033[0m";
    return Difficulte;
}

char Ihm::afficherMenu()
{
    char ChoixMenu = ' ';
    sleep(1);
    cout << endl;
    cout << "\033[1;31m[R]\033[0mejouer"<< endl;
    cout << "\033[1;31m[M]\033[0meilleurs Scores"<< endl;
    cout << "\033[1;31m[H]\033[0mistorique Partie"<< endl;
    cout << "\033[1;31m[Q]\033[0muitter"<< endl;
    cout << "Entrer votre choix : \033[1;31m";
    cin >> ChoixMenu;
    cout << "\033[0m";
    return ChoixMenu;
}

void Ihm::arreterJeu(string nom)
{
    cout << endl;
    cout << "\033[1;36mMerci d'avoir joué " << nom << "!\033[0m" << endl;
}

void Ihm::afficherHistorique(vector<pair<int,string> > scoreHistorique)
{
    system("clear");
    cout << "Historique de vos partie :" << endl;
    cout << "\033[1;36mJoueur : \033[0m"<< scoreHistorique[0].second << endl;
    for(unsigned int i=0;i < scoreHistorique.size(); i++)
    {
        cout << "\033[1;36m   score : \033[0m"<<scoreHistorique[i].first << endl;
    }
}

void Ihm::afficherMeilleursScores(string nomFichier)
{
    system("clear");

    string ligneFichierScore;
    ifstream fichierScore(nomFichier.c_str());
    int i = 0;

    cout << "\033[1;36m" << endl;
    cout << setfill('-') << setw(26) << "\n";
    cout << setfill(' ') << setw(3) << " classement \033[1;0m"; 
    cout << "|" << setfill(' ') << setw(5) << "\033[1;36m scores\033[1;0m"; 
    cout << "\n";

    while(getline(fichierScore, ligneFichierScore)) 
    {
        if(i < 20)
        {
            cout << setfill(' ') << setw(7) << ++i  << setfill(' ') << setw(6) << "|" <<  ligneFichierScore  <<endl;
        }
    }
    cout << "\033[1;36m";
    cout << setfill('-') << setw(26) << "\n";
    cout << "\033[1;0m";
}

void Ihm::afficherPositionScore(int classement)
{
    cout << endl;

    if(classement <= 1)
    {
        cout << "Vous êtes classé \033[1;31m" << classement << "er\033[0m dans les meilleurs scores" << endl;   
    }
    else
    {
        cout << "Vous êtes classé \033[1;31m" << classement << "ème\033[0m dans les meilleurs scores" << endl;    
    }
    
    cout << endl;
}

void Ihm::afficherChronometre(int heure, int minute, int seconde)
{
    cout << endl;
    cout << "Vous avez mis : \033[1;31m" << heure << "h "<< minute << "min " << seconde << "s\033[0m pour trouver le juste prix" << endl;
    cout << endl;
}
