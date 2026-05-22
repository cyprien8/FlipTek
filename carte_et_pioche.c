#include "final.h"


void def_carte(Carte *carte, int valeur, char *label, int est_bonus, int type_bonus) {
    carte->valeur = valeur;
    strcpy(carte->label, label);
    carte->est_bonus = est_bonus;
    carte->type_bonus = type_bonus;
}

void pioche_base(Pioche *pioche) {
    int index = 0;
    char label[8];
    int nbExemplaire_carte;

    // Génération des 79 cartes numéros (0 à 12)
    for (int numero_carte = 0; numero_carte <= 12; numero_carte++) {
        if (numero_carte < 2) {
            nbExemplaire_carte = 1; 
        } else {
            nbExemplaire_carte = numero_carte; 
        }

        sprintf(label, "%d", numero_carte);

        for (int c = 0; c < nbExemplaire_carte; c++) {
            def_carte(&pioche->cartes[index], numero_carte, label, 0, BONUS_AUCUN);
            index++;
        }
    }

    // Ajout des 6 cartes bonus
    def_carte(&(pioche->cartes[index++]), 0, "x2", 1, BONUS_X2);
    def_carte(&(pioche->cartes[index++]), 2, "+2", 1, BONUS_PLUS_2);
    def_carte(&(pioche->cartes[index++]), 4, "+4", 1, BONUS_PLUS_4);
    def_carte(&(pioche->cartes[index++]), 6, "+6", 1, BONUS_PLUS_6);
    def_carte(&(pioche->cartes[index++]), 8, "+8", 1, BONUS_PLUS_8);
    def_carte(&(pioche->cartes[index++]), 10, "+10", 1, BONUS_PLUS_10);

    if (index != TAILLE_PIOCHE) {
        printf("erreur : %d cartes initialisees au lieu de %d\n", index, TAILLE_PIOCHE);
        exit(2);
    }
    pioche->reste = TAILLE_PIOCHE;
}

void melange_pioche(Pioche *pioche) {
    for (int i = TAILLE_PIOCHE- 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Carte temporaire = pioche->cartes[i];
        pioche->cartes[i] = pioche->cartes[j];
        pioche->cartes[j] = temporaire; // CORRECTION : Échange de cartes complété
    }
}


Carte carte_dessus(Pioche *pioche) {
    if (pioche->reste <= 0) {
        // Retourne une carte fictive vide si la pioche s'épuise en cours de route
        Carte vide = {0, "VIDE", 0, BONUS_AUCUN};
        return vide;
    }
    pioche->reste--;
    return pioche->cartes[pioche->reste];
}

void affiche_carte(Carte c) {
    if (c.est_bonus == 1) {
        printf("\033[33m"); // Jaune pour les bonus
        printf("-------\n");
        printf("|     |\n");
        printf("|  %3s  |\n", c.label); // %3s pour caler  le texte bien
        printf("|     |\n");
        printf("-------\n");
        printf("\033[0m"); 
    } else {
        printf("\033[37m"); // Blanc pour les normales
        printf("------- \n");
        printf("|     |\n");
        printf("|  %3s  |\n", c.label);
        printf("|     |\n");
        printf("-------\n");
        printf("\033[0m"); 
    }
}
