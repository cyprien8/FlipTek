

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define CARD_X2      -1
#define CARD_PLUS_2  -2
#define CARD_PLUS_4  -3
#define CARD_PLUS_6  -4
#define CARD_PLUS_8  -5
#define CARD_PLUS_10 -6

#define TAILLE_DECK 86
#define TAILLE_ID   8

typedef struct {
    int  valeur;
    char id[TAILLE_ID];
} Carte;

typedef struct {
    Carte cartes[TAILLE_DECK];
    int   reste;
} Deck;

void   def_carte(Carte *carte, int valeur, char *id);
void   deck_base(Deck *deck);
void   melange_deck(Deck *deck);
Carte *drawCard(Deck *deck);
