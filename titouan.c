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
