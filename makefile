CC=gcc
OBJECT_FRE=main.o
.PHONY: clean all
FLAGS= -Wall -g 
frequency:$(OBJECT_FRE)
	$(CC) $(FLAGS) -o frequency $(OBJECT_FRE)
main.o:main.c
	$(CC) $(FLAGS) -c main.c
all:frequency
clean:
	rm -f frequency *o
