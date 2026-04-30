 void vider_main(Joueur *j){
     j->taille_main=0;
 }
 
 void ajouter_carte(Joueur *j, Carte c){
     if (j->taille_main<7){
         j->main[j->taille_main]=c;
         j->taille_main++;
     }
 }
 
 void affiche_carte( Carte c){
     
     if(c.est_bonus==1){
        printf("\033[33m");
        printf("-------\n");
        printf("|     |\n");
        printf("|  %s  |\n", c.label);
        printf("|     |\n");
        printf("-------\n");
        printf("\033[0m");
     }
     else{
        printf("\033[37m");
        printf("-------\n");
        printf("|     |\n");
        printf("|  %s  |\n", c.label);
        printf("|     |\n");
        printf("-------\n");
        printf("\033[0m");
     }
 }
