all : exec

main.o: main.c final.h
	gcc -c main.c -o main.o
	
mathis.o: mathis.c final.h
	gcc -c mathis.c -o mathis.o
	
titouan.o: titouan.c final.h
	gcc -c titouan.c -o titouan.o
	
cyprien.o: cyprien.c final.h
	gcc -c cyprien.c -o cyprien.o

exec: main.o mathis.o titouan.o cyprien.o
	gcc main.o mathis.o titouan.o cyprien.o -o exec	
	

clean: 
	rm *.o
	rm exec
