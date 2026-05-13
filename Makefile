all : exec

main.o: main.c final.h
	gcc -c main.c -o main.o
	
# ecrire les autres fonction de la même manière que le main.o  §
	
#mettre les autres fonction §
exec: main.o
	gcc main.o -o exec	
	

clean: 
	rm *.o
	rm exec
