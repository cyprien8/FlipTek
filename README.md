# FlipTek
projet PreIng1

fliptek
#include wstdio.h>


ecrire comment utiliser le programme et les regles du jeu 
ecrire qui sont les auteurs 
comment executer et comment compiler 

BIENVENUE SUR LE PROJET FLIP 7 - CY TECH

Tu viens d'arriver sur notre dépôt ? Ne bouge pas, on t'explique tout pour pouvoir jouer en moins de 30 secondes !
LANCEMENT RAPIDE

Ouvre ton terminal Linux dans le dossier du projet et tape :
1. Pour compiler tous les fichiers d'un coup : make
2. Pour lancer le jeu et commencer à piocher : ./exec
(Bonus) Si tu veux nettoyer les fichiers temporaires après avoir joué : make clean
C'EST QUOI LE FLIP 7 ?

C'est un jeu de cartes de "Stop ou Encore" ultra addictif. À ton tour, tu as deux choix : [P]IOCHER : Tu tires une carte. Attention ! Si tu pioches une carte que tu as DÉJÀ dans ta main, tu perds tout et tu marques 0 point pour cette manche ! [S]'ARRÊTER : Tu sécurises tes cartes actuelles et tu valides tes points pour la manche. Comment gagner ?
* Fais un "Flip 7" : Accumule 7 cartes différentes sans exploser pour obtenir un bonus géant de +15 points et arrêter la manche.
* Sois le premier à atteindre 200 points au total des manches !
COULISSES TECHNIQUES

Derrière l'affichage de la console se cachent de vrais algorithmes :
* Un mélange de deck ultra-performant (Fisher-Yates) pour un hasard parfait.
* Un tri par insertion automatique qui range ta main à chaque nouvelle carte reçue.
* Une recherche dichotomique récursive super rapide pour vérifier si tu as fait un doublon à chaque fois que tu pioches.
AUTEURS DU PROJET

Ce projet a été réalisé par trois étudiants de CYTECH :
* Bayard Cyprien
* Gaston-Breton Mathis
* Le Mirronet Titouan
Bonne partie et attention aux doublons !


