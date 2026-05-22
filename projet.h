
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAILLE_PIOCHE 85
#define MAX_SCORE_FIN 200

// Constantes pour distinguer les bonus
#define BONUS_AUCUN   0
#define BONUS_X2      1
#define BONUS_PLUS_2  2
#define BONUS_PLUS_4  3
#define BONUS_PLUS_6  4
#define BONUS_PLUS_8  5
#define BONUS_PLUS_10 6

typedef struct {
    int valeur;      // Valeur numérique pour le score (0 à 12, ou valeur du bonus)
    char label[8];   // Texte affiché sur la carte (ex: "12", "+8", "x2")
    int est_bonus;   // 0 si carte normale, 1 si carte bonus
    int type_bonus;  // Type précis du bonus (BONUS_X2, etc.)
} Carte;

typedef struct {
    char nom[100];
    int score_total;
    int score_manche;
    Carte main[7];
    int taille_main;
    int est_actif;   // 1 si actif, 0 si arrêté volontairement ou éliminé (doublon)
} Joueur;

typedef struct {
    Carte cartes[TAILLE_PIOCHE];
    int reste;
} Pioche;

// Fonctions de gestion des cartes et de la pioche
void def_carte(Carte *carte, int valeur, char *label, int est_bonus, int type_bonus);// different
void pioche_base(Pioche *pioche);
void melange_pioche(Pioche *pioche);
Carte carte_dessus(Pioche *pioche);
void affiche_carte(Carte c);

// Fonctions liées aux joueurs et à la main
void vider_mains(Joueur *listejoueur, int nbjoueurs);
void ajouter_carte(Joueur *j, Carte c);
void tri_main(Carte *main, int taille_main);
int recherche_dichotomique_main(Carte *tab, int debut, int fin, Carte carte);
int calculer_score_manche(Joueur *j);// equivalent a somme_main

// Gestion du déroulement du jeu
int arret_manche(Joueur *listejoueur, int nbjoueurs);
void jouer_manche(Joueur *listejoueur, int nbjoueurs, Pioche *pioche);
void sauvegarder_scores(Joueur *listejoueur, int nbjoueurs);
void vider_buffer();

void rappeler_regles();// rajout bonus
