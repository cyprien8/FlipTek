#include "code_cyprien.h"
//Com test
void vider_main(Joueur *j){ // fonction pour enlever toutes les cartes d'un joueur en fin de manche 
     j->taille_main=0;
 }
 
void ajouter_carte(Joueur *j, Carte c){ // fonction pour ajouter une carte a la main d'un joueur 
     if (j->taille_main<7){
         j->main[j->taille_main] =  c;
         j->taille_main++;
     }
 }
 
 
 void affiche_carte( Carte c){ // effet visuel pour distinguer les cartes bonus des autres 
     
     if(c.est_bonus==1){
        printf("\033[33m"); // mise en couleur jaune 
        printf("-------\n");
        printf("|     |\n");
        printf("|  %s  |\n", c.label);
        printf("|     |\n");
        printf("-------\n");
        printf("\033[0m"); // on revient à la couleur par défaut 
     }
     else{
        printf("\033[37m"); // mise en couleur blanc 
        printf("-------\n");
        printf("|     |\n");
        printf("|  %s  |\n", c.label);
        printf("|     |\n");int score(Joueur *j){ // fonction pour ajouter le score de la manche au score total d'un joueur 
        printf("-------\n");
        printf("\033[0m"); // on revient à la couleur par défaut 
     }
 }


int score(Joueur *j){ // fonction pour ajouter le score de la manche au score total d'un joueur 
    j.score_total=j.score_total+j.score_manche
     return(j.score_total);
}
