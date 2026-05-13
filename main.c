#include "final.h"


int main(){
  Pioche p;
  Pioche *ppioche=&p;
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
  
  pioche_base(ppioche); //appel de la fonction pour initialise la pioche
  
  melange_pioche(ppioche); //appel de la fonction pour mélanger la pioche

  // lancement de la partie/1ere manche

  jouer_manche(listejoueur, nbjoueurs, ppioche);
    
  free(listejoueur);
  return 0;
}
