#include <iostream>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <vector>
#include <cassert>
#include <cstdlib>

#define IS_BIG_ENDIAN (*(uint16_t *)"\0\xff" < 0x100)

// Definitions pour Windows
#ifdef _WIN32
#include <vlc/vlc.h>
#define os "windows"
#include <windows.h>
#define ENDIANESS "LITTLE"

// Definitions pour Linux
#elif __linux__
#include <vlc/vlc.h>
#include <unistd.h>
#define os "linux"
#define ENDIANESS "LITTLE"

// Definitions pour sun Solaris
#elif __sun
#define os "solaris"
#include <unistd.h>
#define ENDIANESS "BIG"
#endif

using namespace std;

struct EchantillonStereo
{
    short int gauche;
    short int droite;
};

struct MusiqueWAV
{
    char idFichier[5];
    unsigned long int tailleFichier;
    char formatFichier[5];
    char formatEntete[5];
    unsigned long int tailleEntete;
    unsigned short int audioFormat;
    unsigned short int nbCanaux;
    unsigned long int tauxEchantillon;
    unsigned long int tauxOctets;
    unsigned short int octetsParBloc;
    unsigned short int bitParEchantillon;
    char idData[5];
    unsigned long int tailleData;
    vector<EchantillonStereo> echantillon;
};

void jouerMusique(string nomFichier, int duree);
void imprimerEntete(MusiqueWAV uneChanson);
MusiqueWAV lireChanson(string nomFichier);
void ecrireChanson(MusiqueWAV titre, string nomFichier);


