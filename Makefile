all : exec

main.o: main.c projet.h
	gcc -c main.c -o main.o
	
carte_et_pioche.o: carte_et_pioche.c projet.h
	gcc -c carte_et_pioche.c -o carte_et_pioche.o
	
deroulement_jeu.o: deroulement_jeu.c projet.h
	gcc -c deroulement_jeu.c -o deroulement_jeu.o
	
joueur_et_main.o: joueur_et_main.c projet.h
	gcc -c joueur_et_main.c -o joueur_et_main.o

exec: main.o carte_et_pioche.o deroulement_jeu.o joueur_et_main.o
	gcc main.o carte_et_pioche.o deroulement_jeu.o joueur_et_main.o -o exec	
	

clean: 
	rm *.o
	rm exec
