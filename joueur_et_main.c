#include "final.h"

void vider_mains(Joueur *listejoueur, int nbjoueurs) {
    for (int i = 0; i < nbjoueurs; i++) {
        listejoueur[i].taille_main = 0; 
        listejoueur[i].score_manche = 0;
        listejoueur[i].est_actif = 1;
    }
}

void ajouter_carte(Joueur *j, Carte c) {
    if (j->taille_main < 7) {
        j->main[j->taille_main] = c;
        j->taille_main++;
    }
}


void tri_main(Carte *main, int taille_main) {// tri par insertion
    int i, j;
    Carte cle;
    for (i = 1; i < taille_main; i++) {
        cle = main[i];   
        j = i - 1;    
        while (j >= 0 && main[j].valeur > cle.valeur) {
            main[j + 1] = main[j]; 
            j = j - 1;     
        }
        main[j + 1] = cle; 
    }
}



int recherche_dichotomique_main(Carte *tab, int debut, int fin, Carte carte) {
    if (carte.est_bonus) {
        return 0; // carte bonus ne peuvent pas etre en doublon
    }
    if (debut > fin) {
        return 0;
    }
    int milieu = (debut + fin) / 2;
    
    if (tab[milieu].valeur == carte.valeur && !tab[milieu].est_bonus) {
        return 1; 
    }
    if (tab[milieu].valeur > carte.valeur) {
        return recherche_dichotomique_main(tab, debut, milieu - 1, carte);
    } else {
        return recherche_dichotomique_main(tab, milieu + 1, fin, carte);
    }
}



int calculer_score_manche(Joueur *j) {
    int points = 0;
    int multiplicateur_x2 = 0;

    // Si le joueur a été éliminé par un doublon, il marque 0 point
    if (j->score_manche == -1) {
        return 0;
    }

    // Premier passage : On additionne cartes numériques et bonus d'addition
    for (int i = 0; i < j->taille_main; i++) {
        if (!j->main[i].est_bonus) {
            points += j->main[i].valeur;
        } else {
            if (j->main[i].type_bonus == BONUS_X2) {
                multiplicateur_x2++;
            } else {
                points += j->main[i].valeur; 
            }
        }
    }

    // Deuxième passage : On applique le ou les multiplicateurs x2 accumulés
    for (int i = 0; i < multiplicateur_x2; i++) {
        points *= 2;
    }

    return points;
}

