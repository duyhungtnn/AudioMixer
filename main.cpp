/** **************************************************************
 \file tp5.cpp
 \author Martin Rancourt - 140 59 412
 \author Frederic Poitras - 140 61 677
 *****************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ***** Declaration de structures tmp ***** //
struct chanson_t
{
    string titre;
    string interprete;
    string attribut;
};

void init(chanson_t Chanson)
{
    Chanson.titre = "UnTitre";
    Chanson.interprete = "UnInterprete";
    Chanson.attribut = "UnAttribut";
}

string toString(chanson_t Chanson)
{
    
    string toString = "Titre : " + Chanson.titre + "\n" +
    "Interprete : " + Chanson.interprete + "\n" +
    "Attribut : " + Chanson.attribut;
    
    return toString;
}

// ***** Declaration des commandes ***** //
const string CMD_JOUER = "jouer";
const string CMD_AJOUTER = "jouer";
const string CMD_AFFICHER = "jouer";
const string CMD_RETIRER = "jouer";
const string CMD_MIXER = "jouer";
const string CMD_KARAOKE = "jouer";
const string CMD_ECHO = "jouer";
const string CMD_ACCELERER = "jouer";
const string CMD_RALENTIR = "jouer";
const string CMD_FIN = "jouer";
const string OUI = "oui";
const string NON = "non";

/** ----------------------------------------------------------------------
 \brief Ce programme est le module principal. Il sert a modifier des
 pistes audio
 ----------------------------------------------------------------------- **/
int main()
{
    
    // Declaration des fonctions prototype
    void init(vector<chanson_t> &); // FONCTION TEMPORAIRE
    void afficher(vector<chanson_t> &);
    void retirer(vector<chanson_t> &);
    
    // Declarations des constantes
    
    // Declaration des variables
    vector<chanson_t> chansons;
    
    // Initialisation temporaire de la liste des chansons
    init(chansons);
    
    retirer(chansons);
    
    afficher(chansons);
    
    return 0;
}

// FONCTION TEMPORAIRE INUTILE POUR LE TP!
void init(vector<chanson_t> &chansons)
{
    const string alphanum = "abcdefghijklmnopqrstuvwxyz";
    chanson_t uneChanson;
    
    // Genere i chansons random
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 12; ++j)
        {
            uneChanson.titre = &alphanum[rand() % (26 - 1)];
            uneChanson.interprete = &alphanum[rand() % (26 - 1)];
            uneChanson.attribut = &alphanum[rand() % (26 - 1)];
        }
        
        chansons.push_back(uneChanson);
    }
}

/** ----------------------------------------------------------------------
 \brief Ce module permet d'afficher la liste des chansons triees dans un
 ordrespecifie.
 ----------------------------------------------------------------------- **/
void afficher(vector<chanson_t> &chansons)
{
    
    cout << "--------------------------------------- " << endl;
    cout << "-- L i s t e  d e s  c h a n s o n s --" << endl;
    cout << "--------------------------------------- " << endl;
    
    // Pour chaque chanson
    for (int i = 0; i < chansons.size(); i++)
    {
        cout << "-------------------- " << endl;
        cout << "-- Chanson " << i << endl;
        cout << "-------------------- " << endl;
        
        // Affichage des informations
        cout << toString(chansons.at(i)) << endl;
        
    }
}

/** ----------------------------------------------------------------------
 FONCTION SEMI FOURNISE
 \brief Recupere et retourne une chanson parmi la liste des chansons
 ----------------------------------------------------------------------- **/
int obtenirChanson(vector<chanson_t> &chansons, bool veuxAfficher)
{
    // Declaration des fonctions prototypes
    void afficher(vector<chanson_t> &chansons);
    
    string reponse;
    int indice;
    
    if (veuxAfficher)
    {
        cout << "Souhaitez-vous voir la liste des chansons ? [" + OUI + "/" + NON + "] ";
        cin >> reponse;
        
        if (reponse == OUI)
        {
            // Affichage de la liste des chansons
            afficher(chansons);
        }
    }
    
    cout << "Entrez le numero de la chanson choisie : ";
    cin >> indice ;
    return indice;
    
}

/** ----------------------------------------------------------------------
 \brief Cette operation permet de retirer une chanson de la liste.
 ----------------------------------------------------------------------- **/
void retirer(vector<chanson_t> &chansons)
{
    
    // Declaration des fonctions prototypes
    int obtenirChanson(vector<chanson_t> &chansons, bool veuxAfficher);
    
    
    // indice de la chanson a retirer
    int indice;
    
    // Affichage de la liste selon la demande de l'utilisateur
    indice = obtenirChanson(chansons, true);
    
    // Suppression de la chanson de la liste
    chansons.erase(chansons.begin() + indice);
    
}

/** ----------------------------------------------------------------------
 FONCTION SEMI FOURNISE
 \brief Cette operation permet de creer (ajouter) une nouvelle chanson
 par le mixage de deux chansons deja presentes dans la liste
 ----------------------------------------------------------------------- **/
void mixer()
{
    // ...
}

/** ----------------------------------------------------------------------
 \brief Cette operation permet de creer une nouvelle chanson a partir
 d'une chanson deja presente dans la liste en enlevant la voix.
 ----------------------------------------------------------------------- **/
void karaoke(vector<chanson_t> &chansons, int indice)
{
    
    // Declaration des fonctions prototypes
    void afficher(vector<chanson_t> &);
    
    // Lecture du desir de l'utilisateur de voir la liste des chansons
    // Si l'utilisateur desir voir la liste des chansons
    // Affichage de la liste des chansons (Module Affichage)
    // Lecture du du numero de chanson a retirer
    // Ajout de la nouvelle chanson avec un numero de version (Module Ajouter)
    // Suppression de la voix sur la nouvelle chanson (Fonction 1)
    
}

/** ----------------------------------------------------------------------
 FONCTION SEMI FOURNISE
 \brief Cette fonction permet de creer une nouvelle chanson a partir
 d'une chanson deja presente dans la liste en ajoutant un effet d'echo
 ----------------------------------------------------------------------- **/
void echo()
{
    // ...
}

/** ----------------------------------------------------------------------
 FONCTION SEMI FOURNISE
 \brief Cette operation permet de creer une nouvelle chanson a partir
 d'une chanson deja presente dans la liste en accelerant le rythme de
 la chanson.
 ----------------------------------------------------------------------- **/
void accelerer()
{
    // ...
}

/** ----------------------------------------------------------------------
 \brief Ce module permet de creer une nouvelle chanson a partir d'une
 chanson deja presente dans la liste en ralentissant le rythme de la chanson
 ----------------------------------------------------------------------- **/
void ralentir(vector<chanson_t> &chansons, int indice)
{
    // Obtenir la premiere chanson a manipuler (module obtenir chanson)
    // Lire le contenu musical de la chanson (Module lireChanson)
    // Creation de la nouvelle chanson dans la liste
    // Copier les entrees de la chanson a ralentir
    // Creer un nom de fichier (ajouter no de version a la fin)
    // Modifier l'attribut (mettre "ralentir")
    // Modifier le fichier de musique
    // Modifier le taux d'echantillonnage (formule 1)
    // ecrire le contenu musical dans le fichier (Module ecrireChanson)
    // Adapter la taille de la liste
    // Incrementer le nombre de version de la chanson originale
}

/** ----------------------------------------------------------------------
 \brief Ce module permet de trier la liste des chansons dans un ordre
 specifie.
 ----------------------------------------------------------------------- **/
void trier(vector<chanson_t> &chansons)
{
    // Declaration des fonctions prototypes
    void regrouper(vector<chanson_t> &liste1, vector<chanson_t> &liste2, vector<chanson_t> &listeRegroupee);
    
    // Declaration des constantes
    const int LONGEUR_MINIMALE = 1;
    
    
    // si longueur > 1
    if (chansons.size() > LONGEUR_MINIMALE)
    {
        // trouve le milieu de la liste pour creer deux listes, liste1 et liste2, de longueur lg1 et lg2
        // tri_fusion(liste1, lg1)
        // tri_fusion(liste2, lg2)
        // regroupe(liste1, liste2, lg1, lg2, liste_sortie)
    }
}

/** ----------------------------------------------------------------------
 \brief Ce module permet de regrouper deux listes
 ----------------------------------------------------------------------- **/
void regrouper(vector<chanson_t> &liste1, vector<chanson_t> &liste2, vector<chanson_t> &listeRegroupee) {
    
    // → tant qu'une des listes n'est pas vide
    // → on compare les elements courants des deux listes
    // → on choisit le plus petit element
    // → on le copie dans la liste de sortie
    // → on avance dans la liste contenant le plus petit element
    // → on copie les elements restant de la liste non vide dans la liste de sortie pour obtenir une liste triee
    
}

