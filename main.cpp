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

// ***** Declaration des commandes et constantes globales ***** //
const string CMD_JOUER = "jouer";
const string CMD_AJOUTER = "ajouter";
const string CMD_AFFICHER = "afficher";
const string CMD_RETIRER = "retirer";
const string CMD_MIXER = "mixer";
const string CMD_KARAOKE = "karaoke";
const string CMD_ECHO = "echo";
const string CMD_ACCELERER = "accelerer";
const string CMD_RALENTIR = "ralentir";
const string CMD_FIN = "fin";
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
    void echo(vector<chanson_t> &);
    void karaoke(vector<chanson_t> &);
    void trier(vector<chanson_t>, string);
    
    // Declaration des variables
    vector<chanson_t> chansons;
    string commande;
    
    // Initialisation temporaire de la liste des chansons
    init(chansons);
    
    // Lecture de la commande de l'utilisateur
    cout << "Veuilez entrer une commande a executer : ";
    cin >> commande;
    
    while (commande != CMD_FIN) {
        // Lecteur d'une chanson
        if (commande == CMD_JOUER)
        {
            // Declaration des variables
            string nomFicher;
            int duree;
            
            // Lecture des informations
            cout << "Veuillez entrer le nom du fichier : ";
            cin >> nomFicher;
            
            cout << "Veuillez entrer la duree de lecture : ";
            cin >> duree;
            
            // Lecture de la chanson
            jouerMusique(nomFicher, duree);
        }
        // Affichage de la liste
        else if (commande == CMD_AFFICHER)
        {
            afficher(chansons);
        }
        // Ajout d'une chanson a la liste
        else if (commande == CMD_AJOUTER)
        {
        }
        // Suppression d'une chanson
        else if (commande == CMD_RETIRER)
        {
            retirer(chansons);
        }
        // Mixage de deux chansons
        else if (commande == CMD_MIXER)
        {
            mixer(chansons);
        }
        // Acceleration d'une chanson
        else if (commande == CMD_ACCELERER)
        {
            // Declaration des variables
            int facteur;
            
            // Lecture des informations
            cout << "Veuillez entrer le facteur d'acceleration : ";
            cin >> facteur;
            
            // Acceleration de la vitesse de la chanson selon le facteur
            accelerer(chansons, facteur);
        }
        // Deceleration d'une chanson
        else if (commande == CMD_RALENTIR)
        {
            // Declaration des variables
            int facteur;
            
            // Lecture des informations
            cout << "Veuillez entrer le facteur de decelaration : ";
            cin >> facteur;
            
            // Deceleration de la vitesse de la chanson selon le facteur
            ralentir(chansons, facteur);
        }
        // Ajout d'Echo sur une chanson
        else if (commande == CMD_ECHO)
        {
            echo(chansons);
        }
        // Conversion d'une chanson en mode Karaoke
        else if (commande == CMD_KARAOKE)
        {
            karaoke(chansons);
        }
        // Commande invalide
        else
        {
            cout << "La commande entree est invalide." << endl;
        }
        
        // Lecture de la commande de l'utilisateur
        cout << "Veuilez entrer une commande a executer : ";
        cin >> commande;
        
    }
    
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
        "1",
        "2"
    };
    string chansonsDates[NB_CHANSONS] = {
        "03102014",
        "14102014"
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
        uneChanson.originale = true;
        
        // Generation de la date
        date_t date;
        init(date);
        
        setDate(date, stoi(chansonsDates[i].substr(0,2)),
                stoi(chansonsDates[i].substr(2,2)),
                stoi(chansonsDates[i].substr(4,4)));
        
        uneChanson.dateEnregistrement = date;
        uneChanson.nbCopies = 0;
        
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
    
    const string TRI_TITRE = "titre";
    const string TRI_INTERPRETE = "interprete";
    
    cout << "--------------------------------------- " << endl;
    cout << "-- L i s t e  d e s  c h a n s o n s --" << endl;
    cout << "--------------------------------------- " << endl;
    
    // Est-ce que l'utilisateur veut trier la liste
    // Critere de tri
    
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
 
    const string OUI = "oui";
    const string NON = "non";
    
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
    cin >> indice;
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
    unsigned int nbTraite = 0;
    
    MusiqueWAV titre1;
    MusiqueWAV titre2;
    MusiqueWAV titre;
    
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
    while(nbTraite < titre.tailleData / 4)
    {
        nouvelEchatillon.gauche = titre1.echantillon[nbTraite].gauche / 2
        + titre2.echantillon[nbTraite].gauche / 2;
        
        nouvelEchatillon.droite = titre1.echantillon[nbTraite].droite / 2
        + titre2.echantillon[nbTraite].droite / 2;
        
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
void karaoke(vector<chanson_t> &chansons)
{
    // Declaration des fonctions prototypes
    void afficher(vector<chanson_t> &);
    
    int indice;
    unsigned int nbTraite = 0;
    
    MusiqueWAV titre1;
    MusiqueWAV titre;
    
    // Obtention la chanson et le contenu musical
    indice = obtenirChanson(chansons, true);
    titre1 = lireChanson(chansons.at(indice).fichier);
    
    
    // Creation de la nouvelle chanson
    chansons.push_back(chansons.at(indice));
    // Modification du nom de fichier de la chanson
    chansons.back().fichier += SEPARATEUR_VERSION + recupererProchaineVersion(chansons.back().nbCopies);
    // Mise a jout de l'attribut de la chanson
    chansons.back().attribut = CMD_ACCELERER;
    
    
    titre = titre1;
    
    // Suppression de la voix sur la nouvelle chanson
    // Generation des echantillons
    while(nbTraite < titre.tailleData / 4)
    {
        
        titre.echantillon[nbTraite].gauche = (titre1.echantillon[nbTraite].gauche - titre1.echantillon[nbTraite].droite) / 2;
        titre.echantillon[nbTraite].droite = (titre1.echantillon[nbTraite].gauche - titre1.echantillon[nbTraite].droite) / 2;
        
        nbTraite++;
    }
    
    ecrireChanson(titre, chansons.back().fichier);
    
    // increment du nombre de version de la chanson originale
    chansons.at(indice).nbCopies++;
    
}

/** ----------------------------------------------------------------------
 FONCTION SEMI FOURNISE
 \brief Cette fonction permet de creer une nouvelle chanson a partir
 d'une chanson deja presente dans la liste en ajoutant un effet d'echo
 ----------------------------------------------------------------------- **/
void echo(vector<chanson_t> &chansons)
{
    const int borneDacalage = 10050;
    const int decalage = 10000;
    
    int indice;
    MusiqueWAV titre1;
    MusiqueWAV titre;
    unsigned int nbTraite = 0;
    
    // Obtention la chanson et le contenu musical
    indice = obtenirChanson(chansons, true);
    titre1 = lireChanson(chansons.at(indice).fichier);
    
    
    // Creation de la nouvelle chanson
    chansons.push_back(chansons.at(indice));
    // Modification du nom de fichier de la chanson
    chansons.back().fichier += SEPARATEUR_VERSION + recupererProchaineVersion(chansons.back().nbCopies);
    // Mise a jout de l'attribut de la chanson
    chansons.back().attribut = CMD_ECHO;
    
    
    titre = titre1;
    while(nbTraite < titre.tailleData / 4)
    {
        if (nbTraite > borneDacalage)
        {
            titre.echantillon[nbTraite].gauche = titre1.echantillon[nbTraite].gauche
            + titre1.echantillon[nbTraite-decalage].gauche;
            
            titre.echantillon[nbTraite].droite = titre1.echantillon[nbTraite].droite
            + titre1.echantillon[nbTraite-decalage].droite;
        }
        else
        {
            titre.echantillon[nbTraite].gauche = titre1.echantillon[nbTraite].gauche;
            titre.echantillon[nbTraite].droite = titre1.echantillon[nbTraite].droite;
        }
        nbTraite += 2;
    }
    ecrireChanson(titre, chansons.back().fichier);
    
    // increment du nombre de version de la chanson originale
    chansons.at(indice).nbCopies++;
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
    
    // Obtention la chanson et le contenu musical
    indice = obtenirChanson(chansons, true);
    titre1 = lireChanson(chansons.at(indice).fichier);
    
    
    // Creation de la nouvelle chanson
    chansons.push_back(chansons.at(indice));
    // Modification du nom de fichier de la chanson
    chansons.back().fichier += SEPARATEUR_VERSION + recupererProchaineVersion(chansons.back().nbCopies);
    // Mise a jout de l'attribut de la chanson
    chansons.back().attribut = CMD_ACCELERER;
    
    
    titre = titre1;
    titre.tauxEchantillon = int(titre.tauxEchantillon * facteur);
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
    
    // Obtention la chanson et le contenu musical
    indice = obtenirChanson(chansons, true);
    titre1 = lireChanson(chansons.at(indice).fichier);
    
    
    // Creation de la nouvelle chanson
    chansons.push_back(chansons.at(indice));
    // Modification du nom de fichier de la chanson
    chansons.back().fichier += SEPARATEUR_VERSION + recupererProchaineVersion(chansons.back().nbCopies);
    // Mise a jout de l'attribut de la chanson
    chansons.back().attribut = CMD_RALENTIR;
    
    
    titre = titre1;
    titre.tauxEchantillon = int(titre.tauxEchantillon / facteur);
    ecrireChanson(titre, chansons.back().fichier);
    
    // increment du nombre de version de la chanson originale
    chansons.at(indice).nbCopies++;
}

/** ----------------------------------------------------------------------
 \brief Ce module permet de trier la liste des chansons dans un ordre
 specifie.
 ----------------------------------------------------------------------- **/
void trier(vector<chanson_t> chansons, string critereTri)
{
    // Declaration des fonctions prototypes
    void regrouper(vector<chanson_t>, vector<chanson_t>, vector<chanson_t> &);
    
    // Declaration des constantes
    const int LONGEUR_MINIMALE = 1;
    
    // Declaration des variables
    size_t pivot;
    vector<chanson_t> listeSortie;
    
    // si longueur > 1
    if (chansons.size() > LONGEUR_MINIMALE)
    {
        // trouve le milieu de la liste pour creer deux listes, liste1 et liste2, de longueur lg1 et lg2
        pivot = chansons.size() / 2;
        
        vector<chanson_t> liste1(chansons.begin(), chansons.begin() + pivot);
        vector<chanson_t> liste2(chansons.begin() + pivot, chansons.end());
        
        // tri fusion recursif sut la premiere liste
        trier(liste1, critereTri);
        // tri fusion recursif sur la deuxieme liste
        trier(liste2, critereTri);
        
        // regroupement des deux listes
        regrouper(liste1, liste2, listeSortie);
    }
    
    chansons = listeSortie;
}

/** ----------------------------------------------------------------------
 \brief Ce module permet de regrouper deux listes
 ----------------------------------------------------------------------- **/
void regrouper(vector<chanson_t> liste1, vector<chanson_t> liste2, vector<chanson_t> &listeRegroupee) {
    
    void afficher(vector<chanson_t> &);
    
    // → tant qu'une des listes n'est pas vide
    while ( liste1.size() > 0 && liste2.size() > 0 )
    {
        // → on compare les elements courants des deux listes
        // → on choisit le plus petit element
        // → on le copie dans la liste de sortie
        if ( liste1.front().attribut > liste2.front().attribut )
        {
            listeRegroupee.push_back(liste1.front());
            liste1.erase(liste1.begin()); // → on avance dans la liste contenant le plus petit element
        }
        else
        {
            listeRegroupee.push_back(liste2.front());
            liste2.erase(liste2.begin()); // → on avance dans la liste contenant le plus petit element
        }
    }
    
    // → on copie les elements restant de la liste non vide dans la liste de sortie pour obtenir une liste triee
    if (liste1.size() > 0)
    {
        for (int i = 0; i < liste1.size(); i++)
        {
            listeRegroupee.push_back(liste1.front());
            liste1.erase(liste1.begin());
        }
    }
    else if (liste2.size() > 0)
    {
        for (int i = 0; i < liste2.size(); i++)
        {
            listeRegroupee.push_back(liste2.front());
            liste2.erase(liste2.begin());
        }
    }
}