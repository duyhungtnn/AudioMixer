


#include "wav.h"
using namespace std;
/** *************************************************************************
    \file wav.cpp

    \brief Bibliotheque pour manipuler des fichiers de musique en format wav

    \author   Gabriel Girard
    \author   Benoit Fraikin
    \date     31 octobre 2013
    \version  1.0

    Cette bibliotheque contient plusieurs fonctions permettant de manipuler des
    fichiers de musique en format wav.  Elle permet de lire et ecrire des
    fichiers wav.  Elle permet aussi de jouer un fichier wav.

    Date de la premiere version: 31 octobre 2013

************************************************************************* */

/*=========================================================================
    j o u e r M u s i q u e
==========================================================================*/

/** ----------------------------------------------------------------------
  \brief Fonction permettant de jouer la musique a partir d'un fichier wav

  \param[in] nomFichier : nom du fichier contenant la musique
  \param[in] duree : duree desiree pour l'ecoute
-------------------------------------------------------------------------- **/
void jouerMusique(string nomFichier, int duree)
{
// La bibliothèque vlc n'existe pas sur le sun Solaris (non installée)
#ifdef __sun
   cout << "Debut de la musique..........." << endl;
   cout << "........................................" << endl;
   cout << "Fin de la musique..........." << endl;
//-----------------------------------------------------------
// Elle est disponible sur sur Linux
#elif __linux

    libvlc_instance_t *inst;
    libvlc_media_player_t *mp;
    libvlc_media_t *m;

    // Chargement de l'outil pour jouer la musique
    inst = libvlc_new(0, NULL);
    cout << "Debut de la musique..........." << endl;
    // creation d'un element pour jouer la musique
    m = libvlc_media_new_path(inst, nomFichier.c_str());
    // creation d'un environnement pour jouer la musique
    mp = libvlc_media_player_new_from_media(m);
    libvlc_media_release(m);
    // On joue la musique pour "duree" secondes
    libvlc_media_player_play(mp);
    sleep(duree);
    // On arrête la musique
    libvlc_media_player_stop(mp);
    cout << "Fin de la musique..........." << endl;

// Elle est disponible sur sur Windows
// la fonction Sleep change.....
#elif _WIN32

    libvlc_instance_t *inst;
    libvlc_media_player_t *mp;
    libvlc_media_t *m;

    // Chargement de l'outil pour jouer la musique
    inst = libvlc_new(0, NULL);
    cout << "Debut de la musique..........." << endl;
    // creation d'un element pour jouer la musique
    m = libvlc_media_new_path(inst, nomFichier.c_str());
    // creation d'un environnement pour jouer la musique
    mp = libvlc_media_player_new_from_media(m);
    libvlc_media_release(m);
    // On joue la musique pour "duree" secondes
    libvlc_media_player_play(mp);
    Sleep(duree*1000);
    // On arrête la musique
    libvlc_media_player_stop(mp);
    cout << "Fin de la musique..........." << endl;
#endif
}
/*=========================================================================
    l i r e C h a i n e
==========================================================================*/
/** ----------------------------------------------------------------------
  \brief Fonction pour lire une chaine de caracteres dans un fichier wav

  \param[out]    ch : chaine lue dans le fichier
  \param[in,out] in : fichier d'entree

  \return rien
-------------------------------------------------------------------------- **/
void lireChaine(char ch[], ifstream &in)
{
    for (int i=0; i < 4 ; i++)
        in.get(ch[i]);
    ch[4]=0;
}
/*=========================================================================
    l i r e M o t
==========================================================================*/
/** ----------------------------------------------------------------------
  \brief Fonction pour lire un entier (4 octets) dans un fichier wav

  \param[in,out] in : fichier d'entree
  \return entier lu
-------------------------------------------------------------------------- **/
unsigned int lireMot(ifstream &in)
{
  unsigned long int val=0;
  if (IS_BIG_ENDIAN)
  {
    for(int i=3;i>=0;i--)
            in.get(*((char*)&val+i));

  }
  else
  {
   in.read((char *)&val, 4);
  }
   return int(val) ;
}

/*=========================================================================
    l i r e D e m i M o t
==========================================================================*/
/** ----------------------------------------------------------------------
  \brief Fonction pour lire un entier court (2 octets) dans un fichier wav

  \param[in,out] in : fichier d'entree
  \return entier lu
-------------------------------------------------------------------------- **/
unsigned short int lireDemiMot(ifstream &in)
{
    unsigned short int val=0;
 if (IS_BIG_ENDIAN)
 {
     for(int i=1;i>=0;i--)
            in.get(*((char*)&val+i));
 }
 else
 {
        in.read((char *)&val, 2);
 }
    return val ;

}

/*=========================================================================
    e c r i r e C h a i n e
==========================================================================*/
/** ----------------------------------------------------------------------
  \brief Fonction pour ecrire une chaine de caracteres dans un fichier wav

  \param[in]     ch : chaine a ecrire dans le fichier
  \param[in,out] in : fichier de sortie
-------------------------------------------------------------------------- **/
void ecrireChaine(char ch[], ofstream &out)
{
    for (int i=0; i < 4 ; i++)
        out.put(ch[i]);
    ch[4]=0;
}
/*=========================================================================
    e c r i r e M o t
==========================================================================*/
/** ----------------------------------------------------------------------
  \brief Fonction pour ecrire un entier long (4 octets) dans un fichier wav

  \param[in]     mot : entire a ecrire dans le fichier
  \param[in,out] in : fichier de sortie
 -------------------------------------------------------------------------- **/
void ecrireMot(unsigned long int mot, ofstream &out)
{
 if (IS_BIG_ENDIAN)
 {
      for(int i=3;i>=0;i--)
        out.put(*((char*)&mot+i));

 }
 else
 {
     out.write((char *)&mot, 4);
 }
}
/*=========================================================================
    e c r i r e D e m i M o t
==========================================================================*/
/** ----------------------------------------------------------------------
  \brief Fonction pour ecrire un entier court (2 octets) dans un fichier wav

  \param[in]     demiMot : entire a ecrire dans le fichier
  \param[in,out] in      : fichier de sortie
 -------------------------------------------------------------------------- **/
void ecrireDemiMot(unsigned short int demiMot, ofstream &out)
{
 if (IS_BIG_ENDIAN)
 {
      for(int i=1;i>=0;i--)
            out.put(*((char*)&demiMot+i));

 }
 else
 {
     out.write((char *)&demiMot, 2);
 }

}

/*=========================================================================
    i m p r i m e r E n t e t e
==========================================================================*/
/** ----------------------------------------------------------------------
  \brief Fonction permettant d'imprimer l'entete d'un fichier WAV

  \param[in]   : laChanson : structure contenant la chanson
-------------------------------------------------------------------------- **/
void imprimerEntete(MusiqueWAV laChanson)
{
    cout << "Identifiant  = " << laChanson.idFichier << endl;
    cout << "Taille du fichier = " << hex << laChanson.tailleFichier << " : "<< dec << laChanson.tailleFichier << endl;
    cout << "Format = " << laChanson.formatFichier << endl;
    cout << "Sous identifiant = " << laChanson.formatEntete << endl;
    cout << "Nombre d'octets du bloc (- 8) = " << hex << laChanson.tailleEntete << " : " << dec <<laChanson.tailleEntete << endl;
    cout << "Audio format (1 = PCM) = " << hex << laChanson.audioFormat << " : "<< dec << laChanson.audioFormat << endl;
    cout << "Nombre de canaux = " << hex << laChanson.nbCanaux << " : "<< dec << laChanson.nbCanaux << endl;
    cout << "Taux d'echatillonnage = " << hex << laChanson.tauxEchantillon << " : "<< dec << laChanson.tauxEchantillon<< endl;
    cout << "Nombre d'octets a lire par seconde = " << hex << laChanson.tauxOctets << " : "<< dec << laChanson.tauxOctets << endl;
    cout << "Nombre octets par echatillon = " << hex << laChanson.octetsParBloc  << " : "<< dec <<laChanson.octetsParBloc << endl;
    cout << "Bits par echatillon (8, 16 ou 24 ) = " << hex <<  laChanson.bitParEchantillon  << " : " << dec << laChanson.bitParEchantillon << endl;
    cout << "Identificateur champs = " << laChanson.idData << endl;
    cout << "Taille du champs data = " << hex << laChanson.tailleData<< " : " << dec <<laChanson.tailleData << endl;

}
/*=========================================================================
    l i r e C h a n s o n
==========================================================================*/
/** ----------------------------------------------------------------------
  \brief Fonction permettant de lire le contenu du fichier wav

  \param[in]  nomFichier : nom du fichier contenant la chanson
  \return     la structure contenant la chanson

-------------------------------------------------------------------------- **/
MusiqueWAV lireChanson(string nomFichier)
{
    ifstream in;
    MusiqueWAV laChanson;

    in.open(nomFichier,ios::binary);
    if (!in)
    {
        cout << "erreur a l'ouverture de entree" << endl;
        assert(false);
    }
    else cout << "Ouverture ok" << endl;
    // lecture chunkID
    lireChaine(laChanson.idFichier,in);
    // Lecture taille du fichier - 8 octets (little indian )
    laChanson.tailleFichier = lireMot(in);
    // Lecture du format (WAV)
    lireChaine(laChanson.formatFichier,in);
    // Lecture identifiant («fmt »)
    lireChaine(laChanson.formatEntete,in);
    // Lecture nb octets dans bloc
    laChanson.tailleEntete = lireMot(in);
    // Lecture audio format (1 : OCM )
    laChanson.audioFormat = lireDemiMot(in);
    // Lecture nombre de canaux
    laChanson.nbCanaux = lireDemiMot(in);
    // Lecture taux echantillonnage (11025 ou 22050 ou 44100, ...
    laChanson.tauxEchantillon = lireMot(in);
    // Lecture nb octets par seconds
    laChanson.tauxOctets = lireMot(in);
    // Lecture Nombre d'octets par bloc d'echatillonnage
    laChanson.octetsParBloc = lireDemiMot(in);
    // Lecture bit par echatillon (8, 16 ou 24)
    laChanson.bitParEchantillon = lireDemiMot(in);
    // Lectureidentificateur «data»
    lireChaine(laChanson.idData,in);
    // Lecture taille du champs data
    laChanson.tailleData = lireMot(in);

    imprimerEntete(laChanson);

    EchantillonStereo sample;
    int nbEchantillons = int(laChanson.tailleData)/laChanson.octetsParBloc;
    cout << endl << "nb echatillons = " << nbEchantillons << endl;
    //on prend pour acquis qu'on a du stereo 16 bits
//    assert(laChanson.nbCanaux==2);
//    assert(laChanson.bitParEchatillon==16);
    laChanson.echantillon.clear();
    int nbTraite = 0;
    while(nbTraite < nbEchantillons)
    {
        sample.gauche = lireDemiMot(in);
        sample.droite = lireDemiMot(in);
        laChanson.echantillon.push_back(sample);
        nbTraite++;
    }
    cout << "Fin lecture " << endl;
    in.close();
    return laChanson;
}

/*=========================================================================
    e c r i r e C h a n s o n
==========================================================================*/
/** ----------------------------------------------------------------------
  \brief Fonction permettant d'ecrire une chanson dans un fichier wav

  \param[in]  laChanson : structure contant la chanson
  \param[in]  nomFichier : nom du fichier contenant la musique
-------------------------------------------------------------------------- **/
void ecrireChanson(MusiqueWAV laChanson, string nomFichier)
{
    ofstream out;
    out.open(nomFichier,ios::out | ios::binary);
    if (!out)
    {
        cout << "erreur a l'ouverture de " << nomFichier << endl;
        assert(false);
    }
    else cout << "Ouverture ok" << endl;

    // Ecriture chunkID
    ecrireChaine(laChanson.idFichier, out);
    // Ecriture taille du fichier - 8 octets (little indian )
    ecrireMot(laChanson.tailleFichier, out);
    // Ecriture du format (WAV)
    ecrireChaine(laChanson.formatFichier,out);
    // Ecriture identifiant («fmt »)
    ecrireChaine(laChanson.formatEntete,out);
    // Ecriture nb octets dans bloc
    ecrireMot(laChanson.tailleEntete, out);
    // Ecriture audio format (1 : OCM )
    ecrireDemiMot(laChanson.audioFormat, out);
    // Ecriture nombre de canaux
    ecrireDemiMot(laChanson.nbCanaux, out);
    // Ecriture taux echantillonnage (11025 ou 22050 ou 44100, ...
    ecrireMot(laChanson.tauxEchantillon, out);
    // Ecriture nb octets par seconds
    ecrireMot(laChanson.tauxOctets, out);
    // Ecriture Nombre d'octets par bloc d'echatillonnage
    ecrireDemiMot(laChanson.octetsParBloc, out);
    // Ecriture bit par echatillon (8, 16 ou 24)
    ecrireDemiMot(laChanson.bitParEchantillon, out);
    // Ecritureidentificateur «data»
    ecrireChaine(laChanson.idData,out);
    // Ecriture taille du champs data
    ecrireMot(laChanson.tailleData, out);
    int nbTraite = 0;
    int nbEchantillons = int(laChanson.tailleData)/laChanson.octetsParBloc;
    cout << endl << "nb echatillons = " << nbEchantillons << endl;
    while(nbTraite < nbEchantillons)
    {

        ecrireDemiMot(laChanson.echantillon[nbTraite].gauche, out);
        ecrireDemiMot(laChanson.echantillon[nbTraite].droite, out);
        nbTraite++;
    }
    out.flush();
    out.close();

}
