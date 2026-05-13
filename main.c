#include "final.h"

//*int tour(Joueur* jeu_joueur, int nbjoueurs, ){
  if(nbjoueurs==0){
    return 0;
  }
  ajouter_carte(jeu_joueur[0],)
  //Appel de la fonction piocher du premier joueur(tab[0])

  return tour(jeu_joueur+1,nbjoueurs-1);*//
    
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
  melange_pioche(p); //appel de la fonction pour mélanger la pioche

  // lancement de la partie/1ere manche

int manche_en_cours=1;
while(manche_en_cours=1){
  //for(int i=0;i<nbjoueurs;i++){ initialisation des parametre, on parcourt les joueurs
    vider_main(listejoueur[0]);
    listejoueur[0].est_actif=1;
    listejoueur[0].score_manche=0;

    //debut de la manche 
    char jeu;
    int n;
    Carte carte_pioché;
    if(listejoueur[0].est_actif==1){ //est ce que le joueur est toujours dans le jeu
      printf("Ecrire 'A' si tu souhaites t'arreter et 'P' si tu souhaites piocher");
      scanf("%c",&jeu);
      if(jeu=='A'){
        listejoueur[0].est_actif=0; //si il s'arrete il devient inactif
      }
      else if(jeu=='P'){
        carte_pioché=carte_dessus(p);//sinon on retourne une carte de la pioche
        affiche_carte(carte_pioché); //affichage de la carte
        n=recherche_dichotomique_main(listejoueur,0,nbjoueurs,carte_pioché); 
        if(n==1){
          printf("La carte pioché est deja dans la main");
          listejoueur[0].est_actif=0; //devient inactif
          listejoueur[0].score_manche=0; //il gagne aucun point durant cette manche
        }
        else{
          ajouter_carte(liste_joueur[0], carte_pioché);
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
  listejoueur[0].score_manche=somme_main(listejoueur[0]);
    
  free(listejoueur);
  return 0;
}

