#RAN MIZRAHI 314809625
#makefile

CC=gcc
OBJECTS_MAIN= StrList.o Main.o

FLAGS= -Wall -g

all: StrList

StrList: $(OBJECTS_MAIN) StrList.a
	$(CC) $(FLAGS) -o StrList $(OBJECTS_MAIN) 
StrList.o: StrList.c StrList.h
	$(CC) $(FLAGS) -c -fPIC -o StrList.o StrList.c  
Main.o: test.c StrList.h
	$(CC) $(FLAGS) -c -fPIC -o Main.o Main.c 

.PHONY: clean all

make clean:
	rm -f *.o StrList
