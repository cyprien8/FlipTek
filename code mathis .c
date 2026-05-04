#include "mon_prog.h"

void def_carte(Carte *carte, int valeur, char *id) { //creer une carte
    carte->valeur= valeur;
    strcpy(carte->id,id);
}

void deck_base(Deck *deck) {

    int index = 0;   //position dans le tableau de carte 
    char id[8];   
    int nbExemplaire_carte;

for(int numero_carte=0;numero_carte<=12;numero_carte++){
    
if (numero_carte < 2) {
    nbExemplaire_carte = 1; // pr cartes 0 et 1
}
else{
    nbExemplaire_carte =numero_carte; // Pour les cartes 2, 3, 4... jusqu'à 12
    }


sprintf(id,"%d",numero_carte);// permet d'afficher sous forme de texte la variable qui est un int a la base

for(int c=0;c<nbExemplaire_carte;c++){
  def_carte(&deck->cartes[index],numero_carte,id);
  index++;  
}
}
def_carte(&deck->cartes[index++], CARTE_X2,    "x2");
def_carte(&deck->cartes[index++], CARTE_PLUS_2, "+2");
def_carte(&deck->cartes[index++], CARTE_PLUS_4, "+4");
def_carte(&deck->cartes[index++], CARTE_PLUS_6, "+6");
def_carte(&deck->cartes[index++], CARTE_PLUS_8, "+8");
def_carte(&deck->cartes[index++], CARTE_PLUS_10,"+10");


if (index !=TAILLE_DECK) {
        printf("[initDeck] ERREUR : %d cartes initialisées au lieu de %d\n",index, TAILLE_DECK);
        exit(1);
    }
    deck->reste = TAILLE_DECK;
}


void melange_deck(Deck *deck) {
    srand(time(NULL));
    for (int i =TAILLE_DECK- 1; i > 0; i--) {
        int j = rand() % (i+1);

        
        Carte temporaire  = deck->cartes[i];
        deck->cartes[i] = deck->cartes[j];
        deck->cartes[j] = temporaire;     // echange les cartes 
    }
}


Carte *drawCard(Deck *deck) {

    if (deck->reste <= 0) {
        printf("La pioche est vide !\n");
        return NULL;
    }

    deck->reste--;
    return &deck->cartes[deck->reste];
}










