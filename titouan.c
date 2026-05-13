#include "final.h"

void tri_main(Carte* main, int taille_main) {
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

int somme_main(Joueur* j){
	int score_manche=0;
  	for(int i=0; i< j->taille_main; i++){
    	score_manche=score_manche + j->main[i].valeur;
  	}
}


int recherche_dichotomique_main(Carte* tab, int debut, int fin, Carte carte){ //recherche si la carte est deja dans la main a condition que la main soit trié
  if(debut>fin){
    return 0;
  }
  int millieu=(fin+debut)/2;
  if(tab[millieu].valeur==carte.valeur){
    return 1;
  }
  if(tab[millieu].valeur>carte.valeur){
    return recherche_dichotomique_main(tab+1,millieu+1,fin,carte);
  }
  if(tab[millieu].valeur<carte.valeur){
    return recherche_dichotomique_main(tab+1,debut,millieu-1,carte);
  }
}



void jouer_manche(Joueur* listejoueur, int nbjoueurs, Pioche ppioche){
int manche_en_cours=1;
while(manche_en_cours==1){
  //for(int i=0;i<nbjoueurs;i++){ initialisation des parametre, on parcourt les joueurs
    vider_main(listejoueur);
    listejoueur[0].est_actif=1;
    listejoueur[0].score_manche=0;

    //debut de la manche 
    char jeu;
    int n;
    Carte carte_pioche;
    if(listejoueur[0].est_actif==1){ //est ce que le joueur est toujours dans le jeu
      printf("Ecrire 'A' si tu souhaites t'arreter et 'P' si tu souhaites piocher");
      scanf("%c",&jeu);
      if(jeu=='A'){
        listejoueur[0].est_actif=0; //si il s'arrete il devient inactif
      }
      else if(jeu=='P'){
        carte_pioche=carte_dessus(ppioche);//sinon on retourne une carte de la pioche
        affiche_carte(carte_pioche); //affichage de la carte
        n=recherche_dichotomique_main(listejoueur[0].main,0,nbjoueurs,carte_pioche); 
        if(n==1){
          printf("La carte pioché est deja dans la main");
          listejoueur[0].est_actif=0; //devient inactif
          listejoueur[0].score_manche=0; //il gagne aucun point durant cette manche
        }
        else{
          ajouter_carte(listejoueur, carte_pioche);
          tri_main(listejoueur[0].main,listejoueur[0].taille_main);
        }
      }
    }
    manche_en_cours=arret_manche(listejoueur,nbjoueurs);
      if(manche_en_cours==0){ 
        printf("Arret de la manche car un joueur a atteint le maximum de carte");
      }
      if(manche_en_cours==2){
        printf("Plus aucun joueur n'est actif");
      }
      if(manche_en_cours==1){
        printf("Continuation de la manche");
      }
  }
  listejoueur[0].score_manche=somme_main(listejoueur);
}
