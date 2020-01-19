# hw6: Eyosias Kibe 
# date: 07/26/2019

cc = gcc
CFLAGS = -Wall
    
graham: main.o graham.o
	$(cc) $(CFLAGS) -o graham main.o graham.o -lm
    
main.o: main.c point.h
	$(cc) $(CFLAGS) -c main.c -lm

graham.o: graham.c 
	$(cc) $(CFLAGS) -c -o graham.o graham.c  -lm
    
    
clean:
	rm *.o

    
