#include "final.h"

int tour(Joueur* jeu_joueur, int nbjoueurs, ){
  if(nbjoueurs==0){
    return 0;
  }
  ajouter_carte(jeu_joueur[0],)
  //Appel de la fonction piocher du premier joueur(tab[0])

  return tour(jeu_joueur+1,nbjoueurs-1);
    
}


int main(){
  Pioche p;
  int nbjoueurs;
  do{
  printf("Quel est le nombre de joueurs ?");
  scanf("%d",&nbjoueurs);
  }while(nbjoueurs<=0); // Demande du nombre de joueurs

  Joueur *listejoueur=malloc(sizeof(Joueur)*nbjoueurs);
  
  if(listejoueur==NULL){
    printf("erreur d'allocation");
    exit(1); // création du tableau joueur 
  }
  
  for(int i=0; i<nbjoueurs; i++){
    printf("Quel est le pseudo du joueur %d",i+1);
    scanf("%s",listejoueur[i].nom); // remplissage des pseudos dans le tableau
    listejoueur[i].score_total=0;
  }
  
  pioche_base(p); //appel de la fonction pour initialise la pioche
  melange_pioche(pioche); //appel de la fonction pour mélanger la pioche


  
  tour(listejoueur,nbjoueurs,pioche);








  
  free(listejoueur);
  return 0;
}

