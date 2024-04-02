#RAN MIZRAHI 314809625
#makefile

CC=gcc
OBJECTS_MAIN= StrList.o Main.o

FLAGS= -Wall -g

all: StrList

StrList: $(OBJECTS_MAIN) 
	$(CC) $(FLAGS) -o StrList $(OBJECTS_MAIN) 
StrList.o: StrList.c StrList.h
	$(CC) $(FLAGS) -c StrList.c  
Main.o: Main.c StrList.h
	$(CC) $(FLAGS) -c Main.c 

.PHONY: clean all

make clean:
	rm -f *.o StrList
