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
    
  free(listejoueur);
  return 0;
}
