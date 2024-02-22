#RAN MIZRAHI 314809625
#makefile

CC=gcc
AR=ar 
OBJECTS_MAIN=Main.o
OBJECTS=StrList.o

FLAGS= -Wall -g

all: StrList.a Main 
run: StrList.a
StrList.a: $(OBJECTS)
	$(AR) -rcs StrList.a $(OBJECTS)
	$(CC) -shared -o libclassloops.so $(OBJECTS)
Main: $(OBJECTS_MAIN) StrList.a
	$(CC) $(FLAGS) -o Main $(OBJECTS_MAIN) StrList.a
StrList.o: StrList.c StrList.h
	$(CC) $(FLAGS) -c -fPIC -o StrList.o StrList.c  
Main.o: Main.c StrList.h
	$(CC) $(FLAGS) -c -fPIC -o Main.o Main.c 

.PHONY: clean all

make clean:
	rm -f *.o *.a Main
