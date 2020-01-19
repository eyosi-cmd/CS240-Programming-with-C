CC =  gcc
CFLAGS = -Wall

adder: main.o myAdd.o adder.o
    $(CC) $(CFLAGS) -o adder adder.o myAdd.o main.o

adder.o: adder.c adder.h
    $(CC) $(CFLAGS) -c adder.c

adder.o: adder.c adder.h
    $(CC) $(CFLAGS) -c adder.c

myAdd.o: myAdd.c adder.h
    $(CC) $(CFLAGS) -c myAdd.c

main.o: main.c adder.h
    $(CC) $(CFLAGS) -c main.c

rm *.o



