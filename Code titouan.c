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


int recherche_dichotomique_main(int* tab, int debut, int fin, int carte){ //recherche si la carte est deja dans la main a condition que la main soit trié
  if(debut>fin){
    return NULL;
  }
  int millieu=(fin+debut)/2;
  if(tab[millieu]==carte){
    return 1;
  }
  if(tab[millieu]>carte){
    return recherche_dichotomique_main(tab+1,millieu+1,fin,carte);
  }
  if(tab[millieu]<carte){
    return recherche_dichotomique_main(tab+1,debut,millieu-1,carte);
  }
}



char jeu;
int n;
for(int i=0;i<nbjoueurs;i++){
  if(listejoueur[i].est_actif==1){    //condition pour savoir si le joueur est toujours dans le jeu
    printf("Ecrire 'A' si tu souhaites t'arreter et 'P' si tu souhaites piocher");    //demander si il est toujours dans le jeu si il veut piocher ou s'arreter
    scanf("%c",&jeu);
    if(jeu=='A'){
      listejoueur[i].est_actif==0;    //si il s'arrete alors il est inactif durant la manche
    }
    else if(jeu=='P'){   //sinon il pioche 
      //fonction piocher
      n=recherche_dichotomique_main(listejoueur,0,nbjoueurs,carte);//carte resultant de la fonction piocher
      if(n==1){    //la carte pioché est deja dans la main
        listejoueur[i].score_manche=0;
        listejoueur[i].est_actif=0; //devient inactif
      }
      else{
        //fonction ajouter main
      }
    }
    if(listejoueur[i].taille_main==7){    //un joueur a cumulé 7 cartes dans sa main donc arret de la manche
      //arret de la manche 
      listejoueur[i].score_manche+=15;  //bonus de +15
    }
  }
} //enfin fini je peux aller me branler!





