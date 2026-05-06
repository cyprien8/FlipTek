#include<stdio.h>
#include<stdlib.h>

int main(){
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
    scanf("%s",listejoueur[i].pseudo); // remplissage des pseudos dans le tableau
    listejoueur[i].score_total=0;
  }
  


  free(listejoueur);
  return 0;
}



int tour(Joueur* tab, nbjoueurs){
if(nbjoueurs==0){
  return 0;
}
ajouter_carte(tab[0], Carte c)
//Appel de la fonction piocher du premier joueur(tab[0])

  return tour(tab+1,nbjoueurs-1);

