#include "projet.h"
int main() {
    srand(time(NULL)); 
    int nbjoueurs;
    char reponse_regles;
    int saisie_valide = 0;

    printf("=== BIENVENUE DANS LE JEU FLIPTECH ===\n");

    do {
        printf("Voulez-vous un rappel des regles ? (Veuillez repondre par O pour oui ou N pour non. ) : ");
        scanf(" %c", &reponse_regles);
        vider_buffer(); // evite les erreurs

        if (reponse_regles == 'O' || reponse_regles == 'o') {
            rappeler_regles();
            saisie_valide = 1; // La réponse est correcte, on sort de la boucle
        } 
        else if (reponse_regles == 'N' || reponse_regles == 'n') {
            printf("Parfait, passons directement au jeu !\n\n");
            saisie_valide = 1; // La réponse est correcte aussi
        } 
        else {
            printf("\033[31mReponse invalide.\033[0m "); //message erreur rouge
            saisie_valide = 0; // On répète de la boucle
        }
    } while (saisie_valide == 0);


do{
  printf("Quel est le nombre de joueurs ?");
  scanf("%d",&nbjoueurs);
  if (nbjoueurs <= 0 && nbjoueurs>=86) {
        printf("Nombre de joueurs invalide.Veuillez mettre un nombre superieur à 0.\n");
    }
  }while(nbjoueurs<=0 && nbjoueurs>=86); 
    
    
    Joueur *listejoueur = malloc(nbjoueurs * sizeof(Joueur)); // crée le tableau de joueur en fonction du nombre donné
    if (listejoueur == NULL) {
        printf("Erreur d'allocation memoire.\n");
        exit(1);
    }

    for (int i = 0; i < nbjoueurs; i++) {
        printf("Entrez le nom/pseudo du joueur %d : ", i + 1);
        scanf("%s", listejoueur[i].nom);
        listejoueur[i].score_total = 0;
        listejoueur[i].taille_main = 0;
        listejoueur[i].est_actif = 1;
    }

    Pioche pioche;
    pioche_base(&pioche);
    melange_pioche(&pioche);

    int partie_en_cours = 1;
    while (partie_en_cours==1) {
        jouer_manche(listejoueur, nbjoueurs, &pioche);

        if (pioche.reste <= 0) {
            printf("\nLa pioche est epuisee ! Fin de la partie.\n");
            partie_en_cours = 0;
        }

        for (int i = 0; i < nbjoueurs; i++) {
            if (listejoueur[i].score_total >= MAX_SCORE_FIN) {
                printf("\n%s a atteint ou depasse les %d points !\n", listejoueur[i].nom, MAX_SCORE_FIN);
                partie_en_cours = 0;
            }
        }
    }

    int index_gagnant = 0;
    for (int i = 1; i < nbjoueurs; i++) {
        if (listejoueur[i].score_total > listejoueur[index_gagnant].score_total) {
            index_gagnant = i;// compare le score des joueurs pour savoir qui a gagné
        }
    }

    printf("\n====================================\n");
    printf(" LE GAGNANT EST : %s avec %d points ! \n", listejoueur[index_gagnant].nom, listejoueur[index_gagnant].score_total);
    printf("====================================\n");

    char sauver;
    printf("Voulez-vous enregistrer les scores dans un fichier ? (O/N) : ");
    scanf(" %c", &sauver);
    if (sauver == 'O' || sauver == 'o') {
        sauvegarder_scores(listejoueur, nbjoueurs);
    }

    free(listejoueur);
    printf("Merci d'avoir joue a FlipTech ! A bientot.\n");
    return 0;
}
