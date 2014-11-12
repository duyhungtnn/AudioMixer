/** **************************************************************
 \file tp5.cpp
 \author Martin Rancourt - 140 59 412
 \author Frederic Poitras - 140 61 677
 *****************************************************************/

#include <iostream>
#include <string>
#include <vector>

#include "chanson.h"
#include "vlc/vlc.h"
#include "wav.h"

using namespace std;

// Declaration des fonctions prototypes globales
int obtenirChanson(vector<chanson_t> &chansons, bool veuxAfficher);

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
const string SEPARATEUR_VERSION = "-V";

/** ----------------------------------------------------------------------
 \brief Ce programme est le module principal. Il sert a modifier des
 pistes audio
 ----------------------------------------------------------------------- **/
int main()
{
    // Declaration des fonctions prototype
    void init(vector<chanson_t> &); // init temporaire pour les tests
    void afficher(vector<chanson_t> &);
    void retirer(vector<chanson_t> &);
    void mixer(vector<chanson_t> &);
    void accelerer(vector<chanson_t> &, float);
    void ralentir(vector<chanson_t> &, float);
    // Declarations des constantes
    
    // Declaration des variables
    vector<chanson_t> chansons;
    
    // Initialisation temporaire de la liste des chansons
    init(chansons);
    
    // Mixage de deux chansons
    //mixer(chansons);
    
    // Acceleration d'une chanson
    //accelerer(chansons, 3);
    
    // Deceleration d'une chanson
    ralentir(chansons, 3);
    
    // Suppression d'une chanson
    //retirer(chansons);
    
    // Affichage de la liste
    afficher(chansons);
    
    return 0;
}

/** ----------------------------------------------------------------------
 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
 Fonction d'initialisation pour les tests. non pertinent pour la remise
 finale!!
 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
 
 \brief Ce programme est le module principal. Il sert a modifier des
 pistes audio
 ----------------------------------------------------------------------- **/
void init(vector<chanson_t> &chansons)
{
    const int NB_CHANSONS = 2;
    
    string chansonsFichiers[NB_CHANSONS] = {
        "mamakin.wav",
        "trainkept.wav"
    };
    string chansonsTitres[NB_CHANSONS] = {
        "Mama kin",
        "Train Kept a Rollin'"
    };
    string chansonsInterpretes[NB_CHANSONS] = {
        "Aerosmith",
        "Aerosmith"
    };
    string chansonsAttributs[NB_CHANSONS] = {
        "original",
        "original"
    };
    
    chanson_t uneChanson;
    
    // Ajoute NB_CHANSONS a la liste de chansons
    for (int i = 0; i < NB_CHANSONS; i++)
    {
        // Creation de la chanson
        uneChanson.fichier = chansonsFichiers[i];
        uneChanson.titre = chansonsTitres[i];
        uneChanson.interprete = chansonsInterpretes[i];
        uneChanson.attribut = chansonsAttributs[i];
        
        // Ajout de la chansons
        chansons.push_back(uneChanson);
    }
}

/** ----------------------------------------------------------------------
 \brief Ce module permet d'afficher la liste des chansons triees dans un
 ordre specifie.
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
void mixer(vector<chanson_t> &chansons)
{
    // Declaration des variables
    int indice1;
    int indice2;
    
    MusiqueWAV titre1;
    MusiqueWAV titre2;
    MusiqueWAV titre;
    
    unsigned int nbTraite = 0;
    EchantillonStereo nouvelEchatillon;
    
    //Obtenir les chansons et le contenu musical
    indice1 = obtenirChanson(chansons, true);
    indice2 = obtenirChanson(chansons, false);
    titre2 = lireChanson(chansons.at(indice2).fichier);
    titre1 = lireChanson(chansons.at(indice1).fichier);
    
    
    // Creation de la nouvelle chanson
    chansons.push_back(chansons.at(indice1));
    // Modification du nom de fichier de la chanson
    chansons.back().fichier += SEPARATEUR_VERSION + recupererProchaineVersion(chansons.at(indice1).nbCopies);
    // Mise a jout de l'attribut de la chanson
    chansons.back().attribut = CMD_MIXER;
    
    
    titre = titre1;
    titre.echantillon.clear();
    
    if (titre1.tailleData > titre2.tailleData)
    {
        titre.tailleData = titre2.tailleData;
    }
    
    // Generation des echantillons
    while(nbTraite < titre.tailleData/4)
    {
        nouvelEchatillon.gauche = titre1.echantillon[nbTraite].gauche/2
        + titre2.echantillon[nbTraite].gauche/2;
        
        nouvelEchatillon.droite = titre1.echantillon[nbTraite].droite/2
        + titre2.echantillon[nbTraite].droite/2;
        
        titre.echantillon.push_back(nouvelEchatillon);
        
        nbTraite++;
    }
    
    // Enregistrement de la chanson dans un fichier WAV avec son nouveau nom
    ecrireChanson(titre, chansons.back().fichier);
    
    // increment du nombre de version de la chanson originale
    chansons.at(indice1).nbCopies++;
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
void accelerer(vector<chanson_t> &chansons, float facteur)
{
    int indice;
    MusiqueWAV titre1, titre;
    
    // Obtenir la chanson et le contenu musical
    indice = obtenirChanson(chansons, true);
    titre1 = lireChanson(chansons.at(indice).fichier);
    
    
    // Creation de la nouvelle chanson
    chansons.push_back(chansons.at(indice));
    // Modification du nom de fichier de la chanson
    chansons.back().fichier += SEPARATEUR_VERSION + recupererProchaineVersion(chansons.back().nbCopies);
    // Mise a jout de l'attribut de la chanson
    chansons.back().attribut = CMD_ACCELERER;
    
    
    titre = titre1;
    titre.tauxEchantillon=int(titre.tauxEchantillon * facteur);
    ecrireChanson(titre, chansons.back().fichier);
    
    // increment du nombre de version de la chanson originale
    chansons.at(indice).nbCopies++;
}

/** ----------------------------------------------------------------------
 \brief Ce module permet de creer une nouvelle chanson a partir d'une
 chanson deja presente dans la liste en ralentissant le rythme de la chanson
 ----------------------------------------------------------------------- **/
void ralentir(vector<chanson_t> &chansons, float facteur)
{
    int indice;
    MusiqueWAV titre1, titre;
    
    // Obtenir la chanson et le contenu musical
    indice = obtenirChanson(chansons, true);
    titre1 = lireChanson(chansons.at(indice).fichier);
    
    
    // Creation de la nouvelle chanson
    chansons.push_back(chansons.at(indice));
    // Modification du nom de fichier de la chanson
    chansons.back().fichier += SEPARATEUR_VERSION + recupererProchaineVersion(chansons.back().nbCopies);
    // Mise a jout de l'attribut de la chanson
    chansons.back().attribut = CMD_RALENTIR;
    
    
    titre = titre1;
    titre.tauxEchantillon=int(titre.tauxEchantillon / facteur);
    ecrireChanson(titre, chansons.back().fichier);
    
    // increment du nombre de version de la chanson originale
    chansons.at(indice).nbCopies++;
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

