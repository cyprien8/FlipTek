int arret_manche(Joueur *listejoueur, int nbjoueurs) {
    for (int i = 0; i < nbjoueurs; i++) {
        if (listejoueur[i].taille_main == 7 && listejoueur[i].est_actif == 1) {
            return 0; // Quelqu'un gagne la manche avec 7 cartes
        }
    }
    
    // Condition 2 : Reste-t-il au moins un joueur actif ?
    for (int i = 0; i < nbjoueurs; i++) {
        if (listejoueur[i].est_actif == 1) {
            return 1; //la manche continue
        }
    }
    return 2; // tout le monde s'est arrété
}



void jouer_manche(Joueur *listejoueur, int nbjoueurs, Pioche *pioche) {
    int status_manche = 1;
    vider_mains(listejoueur, nbjoueurs);
    Carte carte_pioche;
    char choix;
    int doublon;
    
    printf("\n--- DEBUT D'UNE NOUVELLE MANCHE ---\n");

    while (status_manche == 1 && pioche->reste > 0) {
        for (int j = 0; j < nbjoueurs; j++) {
            // On revérifie l'état de la manche après chaque tour individuel
            status_manche = arret_manche(listejoueur, nbjoueurs);
            if (status_manche != 1 || pioche->reste <= 0){ 
                break;// permet de sortir de la boucle sans sortir du programme tout entier
        }
            if (listejoueur[j].est_actif == 1) {
                
                printf("\nAu tour de [%s] (%d cartes en main). Reste %d cartes dans la pioche.\n", 
                       listejoueur[j].nom, listejoueur[j].taille_main, pioche->reste);
                
                // on affiche la main du joueur
                if(listejoueur[j].taille_main > 0) {
                    printf("Votre main actuelle : ");
                    for(int m = 0; m < listejoueur[j].taille_main; m++) {
                        printf("[%s] ", listejoueur[j].main[m].label);
                    }
                    printf("\n");
                }
                do{ 
                printf("Ecrire 'A' pour s'arreter volontairement ou 'P' pour piocher : ");
                scanf(" %c", &choix);
                }while(choix != 'A' || choix!= 'a'|| choix != 'P'|| choix != 'p');
                
                if (choix == 'A' || choix == 'a') {
                    listejoueur[j].est_actif = 0;
                    printf("[%s] s'arrete avec ses cartes actuelles.\n", listejoueur[j].nom);
                } 
                else if (choix == 'P' || choix == 'p') {
                    carte_pioche = carte_dessus(pioche);
                    printf("Vous avez pioche la carte :\n");
                    affiche_carte(carte_pioche);

                    // Recherche de doublon pour les cartes normales
                     doublon = recherche_dichotomique_main(listejoueur[j].main, 0, listejoueur[j].taille_main - 1, carte_pioche);
                    
                    if (doublon == 1) {
                        printf("\033[31mDommage ! La carte %s est deja dans votre main. Vous perdez TOUT pour cette manche !\033[0m\n", carte_pioche.label);
                        listejoueur[j].est_actif = 0;
                        listejoueur[j].score_manche = -1; // Marqueur d'élimination pour le calcul des scores
                    } else {
                        ajouter_carte(&listejoueur[j], carte_pioche);
                        tri_main(listejoueur[j].main, listejoueur[j].taille_main);
                    }
                }
            }
        }
        if (status_manche == 1) {
            status_manche = arret_manche(listejoueur, nbjoueurs);
        }
    }

    // Fin de la manche 
    printf("\n--- FIN DE LA MANCHE ---\n");
    
    // Si la manche s'est arrêtée car un joueur a réussi à obtenir 7 cartes différentes
    for (int i = 0; i < nbjoueurs; i++) {
        if (listejoueur[i].taille_main == 7 && listejoueur[i].score_manche != -1) {
            printf("\033[32mFelicitations a %s qui a collecte 7 cartes ! Bonus de +15 points !\033[0m\n", listejoueur[i].nom);
            listejoueur[i].score_total += 15; // bonus de 15 si le joueur a reussi à avoir 7 carte différente
        }
    }

    // Calcul et mise à jour des scores totaux de chaque joueur
    for (int g = 0; g < nbjoueurs; g++) {
        int pts = calculer_score_manche(&listejoueur[g]);
        listejoueur[g].score_total += pts;
        printf("Joueur %s : +%d points (Total actuel : %d points)\n", listejoueur[g].nom, pts, listejoueur[g].score_total);
    }
}

void sauvegarder_scores(Joueur *listejoueur, int nbjoueurs) {
    char nom_fichier[150];
    printf("\nEntrez le nom du fichier pour sauvegarder les scores (ex: scores.txt) : ");
    scanf("%s", nom_fichier);

    FILE *fichier = fopen(nom_fichier, "w");
    if (fichier == NULL) {
        printf("Erreur lors du telechargement ou de la creation du fichier.\n");
        return;
    }

    fprintf(fichier, "=== TABLEAU DES SCORES FLIPTECH ===\n");
    for (int i = 0; i < nbjoueurs; i++) {
        fprintf(fichier, "Pseudo : %s | Score final : %d points\n", listejoueur[i].nom, listejoueur[i].score_total);
    }

    fclose(fichier);
    printf("Scores sauvegardes avec succes dans le fichier '%s' !\n", nom_fichier);
    
    
}


void vider_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}



void rappeler_regles() {
    printf("\n\033[36m==================================================================\033[0m\n");
    printf("\033[1;36m                     REGLES DU JEU : FLIPTECH                     \033[0m\n");
    printf("\033[36m==================================================================\033[0m\n");
    printf("\n\033[1m1. BUT DU JEU :\033[0m\n");
    printf("   Avoir le plus de points possible en accumulant des cartes[cite: 14, 74].\n");
    printf("   Les cartes numeros rapportent leur valeur (ex: un 8 vaut 8 points)[cite: 75].\n");
    printf("   Les cartes bonus modifient votre score (x2, +2, +4, +6, +8, +10)[cite: 76].\n");
    
    printf("\n\033[1m2. LA PIOCHE (85 cartes) :\033[0m\n");
    printf("   79 cartes numérotées de 0 à 12 (ex: 1 carte '0', 1 carte '1', 2 '2', ..., 12 '12')[cite: 58, 59, 60, 61, 62, 64].\n");
    printf("   6 cartes bonus uniques[cite: 65].\n");

    printf("\n\033[1m3. DEROULEMENT D'UN TOUR :\033[0m\n");
    printf("   A votre tour, vous avez deux choix[cite: 78]:\n");
    printf("   \033[32m[P] Piocher\033[0m : Vous tirez une carte de la pioche[cite: 78].\n");
    printf("     - Si c'est un numéro que vous n'avez pas, il s'ajoute à votre main[cite: 80].\n");
    printf("     - Si c'est un bonus, il boostera vos points en fin de manche[cite: 81].\n");
    printf("     - \033[31mSi c'est un numéro que vous possédez DEJA, vous perdez TOUT (0 pt) !\033[0m [cite: 82]\n");
    printf("   \033[33m[A] S'arreter\033[0m : Vous validez vos points actuels et quittez la manche[cite: 78].\n");

    printf("\n\033[1m4. FIN D'UNE MANCHE :\033[0m\n");
    printf("   La manche s'arrete si tout le monde s'est arrete ou a perdu[cite: 85].\n");
    printf("   \033[32mBONUS SPECIAL :\033[0m Si vous atteignez 7 cartes différentes en main, la manche\n");
    printf("   s'arrete immédiatement et vous gagnez \033[1;32m+15 points de bonus\033[0m[cite: 83, 84]!\n");
    
    printf("\n\033[1m5. FIN DE LA PARTIE :\033[0m\n");
    printf("   Dès qu'un joueur atteint ou dépasse \033[1;31m200 points\033[0m, la partie s'arrete[cite: 90].\n");
    printf("\033[36m==================================================================\033[0m\n\n");
    
    printf("Appuyez sur Entree pour lancer la partie...");
    getchar(); // Attend que l'utilisateur lise et appuie sur Entrée
    getchar(); 
}
