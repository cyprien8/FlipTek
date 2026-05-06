 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include<time.h>


#define CARTE_X2      1
#define CARTE_PLUS_2  2
#define CARTE_PLUS_4  3
#define CARTE_PLUS_6  4
#define CARTE_PLUS_8  5
#define CARTE_PLUS_10 6
#define TAILLE_PIOCHE 86


 typedef struct{
     int valeur; // valeur de la carte 
     char label[5]; // ce qui va être affiché à l'ecran 
     int est_bonus; // 0 ou 1, pour savoir rapidement si la carte est bonus(1) ou normale(0)
 }Carte;
 
 typedef struct{
     char nom[100];
     int score_total;
     int score_manche;
     Carte main[7];
     int taille_main; // savoir rapidement combien de carte il a dans la main 
     int est_actif; // savoir si le joueur est encore dans la manche (1) ou si il est parti (0)
 }Joueur;

typedef struct {
    Carte cartes[TAILLE_PIOCHE];
    int   reste; // nombre de cartes restantes dans la pioche
} Pioche;

void vider_main(Joueur *j)
void affiche_carte( Carte c)
void ajouter_carte(Joueur *j, Carte c)
void   def_carte(Carte *carte, int valeur, char *id);
void   pioche_base(Deck *deck);
void   melange_deck(Deck *deck);
Carte *drawCard(Deck *deck);
